#include <QDesktopWidget>
#include <QTimer>

#include "organizerui.h"
#include "ui_organizerui.h"
#include "steptime.h"
#include "post.h"
#include "diary.h"

// Global fields.
Calendar calendar = Calendar(30, 6);
QPushButton * PressedButton = NULL;

OrganizerUI::OrganizerUI(Organizer * organizer, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OrganizerUI)
{
    ui->setupUi(this);

    // Create objects for new windows.
    this->newPostUI_obj = new NewPostUI(this);
    this->newGoalUI_obj = new NewGoalUI(this);

    // Some default fields initialization.
    this->startButtonIsPressed = false;
    this->organizer = organizer;

    // Fill chart information.
    double hours[] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f};
    this->chart = new ProductivityChart(hours);
    chart->Show(ui->chart_frame);

    // Disable resizing a BattleField window.
    // Disable 'maximize' and 'hide' button in a BattleField window.
    // Move BattleField window to the center of screen.
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    this->setWindowFlags(Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
    this->move((QApplication::desktop()->width() - this->size().width()) / 2,
               (QApplication::desktop()->height() - this->size().height()) / 2 - 50);

    // Generate button slots.
    for(int i = 1; i <= 7*6; i++)
    {
        QString curButtonName = QString("cal_button_%1").arg(i);
        QPushButton * curButton = ui->Calendar_frame->findChild<QPushButton*>(curButtonName);
        connect(curButton, SIGNAL (released()),this, SLOT (onCalendarButtonClicked()));
    }

    // Fill calendar.
	for (int i = 0; i < calendar.getMounth()->getWeeks(); i++) 
		for (int j = 0; j < 7; j++) 
		{ 
			QString tmpstring = QString("cal_button_%1").arg(QString::number(i * 7 + j + 1)); 
			QPushButton * label = ui->Calendar_frame->findChild<QPushButton *>(tmpstring); 
            label->setText(QString("%1").arg(QString::number(calendar.getMounth()->date(i, j))));
            if (i == 0 && calendar.getMounth()->date(i, j) > 10 || i == calendar.getMounth()->getWeeks() - 1 && calendar.getMounth()->date(i, j) < 10)
                label->setEnabled(false);
        }

    // A timer for tracker.
    this->workTimer = new QTimer(this);

    connect(ui->mainOrganizerArea_tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabSelected()));

    // Updating on first launch.
    tabSelected();
    updateDiary();

}

void OrganizerUI::onCalendarButtonClicked()
{
    // Function for tracking previous button position in Calendar tab.
    QPushButton *senderObj = (QPushButton *)sender();
    int date = senderObj->text().toInt();
    Day * curDay = calendar.getMounth()->getDay(date);
    if(PressedButton != NULL){
        PressedButton->setStyleSheet("background-color : rgb(198, 198, 198)");
    }
    PressedButton = senderObj;
    senderObj->setStyleSheet("background-color : rgb(255, 20, 50)");
    ui->CalendarActions_Label->setText("Start:" + curDay->getStart().toString() + "\nEnd:" + curDay->getEnd().toString() + "\nTime left:" + curDay->getLeft().toString());
}

Organizer *OrganizerUI::getOrganizer()
{
    return organizer;
}

OrganizerUI::~OrganizerUI()
{
    delete ui;
}

void OrganizerUI::tabSelected()
{
    // Do certain action depending on opened tab.
    switch(ui->mainOrganizerArea_tabWidget->currentIndex())
    {
        case TAB_GOALS:
        {
            updateTabGoals();
        }
        case TAB_DIARY:
        {
            updateDiary();
        }
    }
}
void OrganizerUI::on_newPost_button_clicked()
{
    // Open "New Post" window.
    this->newPostUI_obj->setModal(true);
    this->newPostUI_obj->show();
}

void OrganizerUI::on_newGoal_button_clicked()
{
    // Open "New Goal" window.
    this->newGoalUI_obj->setModal(true);
    this->newGoalUI_obj->show();
}
void OrganizerUI::updateTabGoals()
{
    // Function to update ComboBox with list of all goals in Goals tab.
    for(int i = 0; i < organizer->getGoalCount(); i++)
    {
        bool skip = false;
        for(int j = 0; j < ui->goalTitle_ComboBox->count(); j++)
        {
            if(QString::compare(ui->goalTitle_ComboBox->itemText(j), organizer->getGoal(i)->getTitle()) == 0)
            {
                skip = true;
            }
        }
        if(skip)
            continue;
        ui->goalTitle_ComboBox->addItem(organizer->getGoal(i)->getTitle());
    }
    // Update all data in GoalWindow about certain Goal.
    on_goalTitle_ComboBox_currentIndexChanged(ui->goalTitle_ComboBox->currentText());
}

QString OrganizerUI::setNewDiaryPost(QString title, QString description)
{
    // Function for handling new Post Creation.
    // User can add only one summary post per day.
    QDateTime curTime = QDateTime::currentDateTime();
    Post post = Post(curTime, description, title);
    Diary * diary = organizer->getGoal(ui->goalTitle_ComboBox_2->currentText())->getDiary();
    bool isPosted = false;
    for(Post p : diary->getPosts())
        if(p.getPushTime().date() == curTime.date())
            isPosted = true;
    if(!isPosted)
        diary->addPost(post);
    return (ui->goalTitle_ComboBox_2->currentText());
}

void OrganizerUI::updateDiary()
{
    // Function to update Diary Window.
    for(int i = 0; i < organizer->getGoalCount(); i++)
    {
        bool skip = false;
        for(int j = 0; j < ui->goalTitle_ComboBox_2->count(); j++)
        {
            if(QString::compare(ui->goalTitle_ComboBox_2->itemText(j), organizer->getGoal(i)->getTitle()) == 0)
            {
                skip = true;
            }
        }
        if(skip)
            continue;
        ui->goalTitle_ComboBox_2->addItem(organizer->getGoal(i)->getTitle());
    }
}

void OrganizerUI::on_goalTitle_ComboBox_currentIndexChanged(const QString &arg1)
{
    const int maxSteps = 5;
    Goal * goal = organizer->getGoal(arg1);
    ui->goalCategory_label->setText(goal->getCategory());
    ui->goalDescription_label->setText(goal->getDescription());
    int i;
    bool isActive = true;

    for(i = 0; i < goal->getStepCount(); i++)
    {
        // Fill step title.
        QString curTitleName = QString("step%1title_label").arg( QString::number(i + 1));
        QLabel * label = ui->goalSteps_ScrollArea->findChild<QLabel *>(curTitleName);
        label->setText(goal->getStepTitle(i));
        label->setVisible(true);
        // Fill hoursPerStepLeft labels.
        QString curPerStepLeftValue = QString("step%1hoursPerStepLeft_label").arg(QString::number(i + 1));
        QLabel *labelTimeLeft = ui->goalSteps_ScrollArea->findChild<QLabel *>(curPerStepLeftValue);
        QString labelText = QString("Time left: %1         DeadLine: %2").arg(goal->getStepTimeLeft(i).toString()).arg(goal->getStepDeadline(i).toString("MMM-dd"));
        labelTimeLeft->setText(labelText);
        labelTimeLeft->setVisible(true);
        // Fill checkBoxes.
        QString checkBoxName = QString("step%1_checkBox").arg(QString::number(i + 1));
        QCheckBox *checkBox = ui->goalSteps_ScrollArea->findChild<QCheckBox *>(checkBoxName);
        checkBox->setChecked(goal->isStepCompleted(i));
        checkBox->setEnabled(isActive);
        checkBox->setVisible(true);
        if(!goal->isStepCompleted(i))
            isActive = false;
    }
    if(i < maxSteps)
    {
        for(int j = i; j < maxSteps; j++)
        {
            // Hide empty steps titles.
            QString curTitleName = QString("step%1title_label").arg( QString::number(j + 1));
            QLabel * label = ui->goalSteps_ScrollArea->findChild<QLabel *>(curTitleName);
            label->setVisible(false);
            // Hide epmty hoursPerStepLeft titles.
            QString curPerStepLeftValue = QString("step%1hoursPerStepLeft_label").arg(QString::number(j + 1));
            QLabel *labelTimeLeft = ui->goalSteps_ScrollArea->findChild<QLabel *>(curPerStepLeftValue);
            labelTimeLeft->setVisible(false);
            // Hide empty checkboxes.
            QString checkBoxName = QString("step%1_checkBox").arg(QString::number(j + 1));
            QCheckBox *checkBox = ui->goalSteps_ScrollArea->findChild<QCheckBox *>(checkBoxName);
            checkBox->setVisible(false);
        }
    }
}

void OrganizerUI::on_step1_checkBox_clicked()
{
    ui->step2_checkBox->setEnabled(ui->step1_checkBox->isChecked());
    QString currentGoal = this->ui->goalTitle_ComboBox->currentText();
    this->organizer->getGoal(currentGoal)->setStepCompleted(0, ui->step1_checkBox->isChecked());
}

void OrganizerUI::on_step2_checkBox_clicked()
{
    ui->step1_checkBox->setEnabled(!ui->step2_checkBox->isChecked());
    ui->step3_checkBox->setEnabled(ui->step2_checkBox->isChecked());
    QString currentGoal = this->ui->goalTitle_ComboBox->currentText();
    this->organizer->getGoal(currentGoal)->setStepCompleted(1, ui->step1_checkBox->isChecked());
}

void OrganizerUI::on_step3_checkBox_clicked()
{
    ui->step2_checkBox->setEnabled(!ui->step3_checkBox->isChecked());
    ui->step4_checkBox->setEnabled(ui->step3_checkBox->isChecked());
    QString currentGoal = this->ui->goalTitle_ComboBox->currentText();
    this->organizer->getGoal(currentGoal)->setStepCompleted(2, ui->step1_checkBox->isChecked());
}

void OrganizerUI::on_step4_checkBox_clicked()
{
    ui->step3_checkBox->setEnabled(!ui->step4_checkBox->isChecked());
    ui->step5_checkBox->setEnabled(ui->step4_checkBox->isChecked());
    QString currentGoal = this->ui->goalTitle_ComboBox->currentText();
    this->organizer->getGoal(currentGoal)->setStepCompleted(3, ui->step1_checkBox->isChecked());
}

void OrganizerUI::on_step5_checkBox_clicked()
{
    ui->step4_checkBox->setEnabled(!ui->step5_checkBox->isChecked());
    QString currentGoal = this->ui->goalTitle_ComboBox->currentText();
    this->organizer->getGoal(currentGoal)->setStepCompleted(4, ui->step1_checkBox->isChecked());
}

void OrganizerUI::on_startTimer_button_clicked()
{
    // Function to handle startButton behavior.
    if(startButtonIsPressed == true)
    {
        startButtonIsPressed = false;
        ui->startTimer_button->setText("Start!");
        disconnect(workTimer, SIGNAL(timeout()), this, SLOT(decreaseSecond()));
    }
    else {
        startButtonIsPressed = true;
        ui->startTimer_button->setText("Stop!");
        connect(workTimer, SIGNAL(timeout()), this, SLOT(decreaseSecond()));
        this->workTimer->start(1000);
    }
}

void OrganizerUI::decreaseSecond()
{
    // Function, that calls every second.
    QString currentGoal = this->ui->goalTitle_ComboBox->currentText();
    // Update strings in GoalWindow.
    int index = -1;
    for (int i = 0; i < organizer->getGoalCount(); i++)
    {
        if (!ui->goalSteps_ScrollArea->findChild<QCheckBox *>(QString("step%1_checkBox").arg(QString::number(i + 1)))->isChecked())
        {
            index = i;
            break;
        }

    }
    if (-1 != index)
    {
        this->organizer->getGoal(currentGoal)->reduceStepTime(index, StepTime(0,0,1));
        QString labelText = QString("Time left: %1         DeadLine: %2")
                .arg(this->organizer->getGoal(currentGoal)->getStepTimeLeft(index).toString())
                .arg(this->organizer->getGoal(currentGoal)->getStepDeadline(index).toString("MMM-dd"));
        this->ui->goalSteps_ScrollArea->findChild<QLabel *>(QString("step%1hoursPerStepLeft_label").arg(QString::number(index + 1)))->setText(labelText);
        calendar.getMounth()->getDay(QDateTime::currentDateTime().date().day())->setLeft(calendar.getMounth()->getDay(QDateTime::currentDateTime().date().day())->getLeft().addSecs(-1));
    // Update string in calendar.
    if (PressedButton != NULL)
        if (!QString::compare(PressedButton->text(), QString::number(QDateTime::currentDateTime().date().day())))
        {
            Day *day = calendar.getMounth()->getDay(QDateTime::currentDateTime().date().day());
            QString calendarActionText = QString("Start: %1\nEnd: %2\nTime left: %3")
                    .arg(day->getStart().toString())
                    .arg(day->getEnd().toString())
                    .arg(day->getLeft().toString());
            ui->CalendarActions_Label->setText(calendarActionText);
        }
    updateWorkTime();
    }

}

void OrganizerUI::on_timeManagSave_button_clicked()
{
    // Button in "Time Management", that saves inputed time.
    for (int i = 0; i < 7; i++)
    {
        QTimeEdit * timeEdit = ui->frameTM->findChild<QTimeEdit *>(QString("timeFrom_%1").arg( QString::number(i + 1)));
        for (int curWeek = 0; curWeek < calendar.getMounth()->getWeeks(); curWeek++)
        {
            calendar.getMounth()->getDay(curWeek, i)->setStart(timeEdit->time());
        }
        timeEdit = ui->frameTM->findChild<QTimeEdit *>(QString("timeTo_%1").arg( QString::number(i + 1)));
        for (int curWeek = 0; curWeek < calendar.getMounth()->getWeeks(); curWeek++)
            calendar.getMounth()->getDay(curWeek, i)->setEnd(timeEdit->time());
        for (int curWeek = 0; curWeek < calendar.getMounth()->getWeeks(); curWeek++)
        {
            int difference = calendar.getMounth()->getDay(curWeek, i)->getStart().secsTo(calendar.getMounth()->getDay(curWeek, i)->getEnd());
            if(difference <= 0) {
                QTime emptyTime = QTime(0,0,0);
                calendar.getMounth()->getDay(curWeek, i)->setLeft(emptyTime);
                calendar.getMounth()->getDay(curWeek, i)->setStart(emptyTime);
                calendar.getMounth()->getDay(curWeek, i)->setEnd(emptyTime);
                continue;
            }
            if (QDateTime::currentDateTime().date().day() != calendar.getMounth()->getDay(curWeek, i)->getDate())
            {
                QTime tempTime = QTime(0, 0, 0);
                calendar.getMounth()->getDay(curWeek, i)->setLeft(tempTime.addSecs(difference));
            }
        }
    }
    updateWorkTime();
}

void OrganizerUI::on_goalTitle_ComboBox_2_currentIndexChanged(const QString &arg1)
{
    Goal * goal = organizer->getGoal(arg1);
    if(goal == nullptr)
        return;
    int i = 0;
    for(Post post : goal->getDiary()->getPosts())
    {
        if(ui->scrollArea->findChild<QFrame *>(QString("post_frame_%1").arg(i + 1)) != nullptr)
        {
            ui->scrollArea->findChild<QFrame *>(QString("post_frame_%1").arg(i + 1))->setVisible(true);
            QString curPostTitleLabelName = QString("post%1Title_label").arg(i + 1);
            QLabel * label = ui->scrollArea->findChild<QLabel *>(curPostTitleLabelName);
            label->setText(post.getTitle());
            QString curPostDescriptionLabelName = QString("post%1Description_label").arg(i + 1);
             QLabel * label1 = ui->scrollArea->findChild<QLabel *>(curPostDescriptionLabelName);
             label1->setText(post.getDescription());
            QString curPostPushTimLabelNamee = QString("post%1TimeDate_label").arg(i + 1);
             QLabel * label2 = ui->scrollArea->findChild<QLabel *>(curPostPushTimLabelNamee);
             label2->setText(post.getPushTime().toString());
        }
        i++;
    }
    for(int j = i; j < 3; j++)
    {
        ui->scrollArea->findChild<QFrame *>(QString("post_frame_%1").arg(j + 1))->setVisible(false);
    }
}

void OrganizerUI::updateWorkTime(){
    int daysToDeadline = QDateTime::currentDateTime().daysTo(this->organizer->getGoal(0/*!!*/)->getStepDeadline(0/*!!*/));
    int curDate = QDateTime::currentDateTime().date().day();
    int freeTime = 0;
    qDebug() << "done";
    for (int i = curDate; i < curDate + daysToDeadline; i++)
        freeTime += calendar.getMounth()->getDay(i)->getStart().secsTo(calendar.getMounth()->getDay(i)->getEnd());

    qDebug() << "done1";
    float timeCoeficient = float(this->organizer->getGoal(0/*!!*/)->getStepTimeLeft(0/*!!*/).getSeconds()) / float(freeTime);

    qDebug() << "done2";
    for (int i = curDate + 1; i < curDate + daysToDeadline; i++)
        calendar.getMounth()->getDay(i)->setLeft(QTime(0, 0, 0).addSecs(round(float(calendar.getMounth()->getDay(i)->getStart().secsTo(calendar.getMounth()->getDay(i)->getEnd())) * timeCoeficient)));

    qDebug() << "done3";
}

void OrganizerUI::on_goalSave_button_clicked()
{

}

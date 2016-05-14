#include "organizerui.h"
#include "ui_organizerui.h"
#include <QDesktopWidget>
#include <QDebug>
QPushButton * PressedButton = NULL;
OrganizerUI::OrganizerUI(Organizer * organizer, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OrganizerUI)
{
    this->organizer = organizer;
    ui->setupUi(this);
    this->newPostUI_obj = new NewPostUI(this);
    this->newGoalUI_obj = new NewGoalUI(this);

    // Disable resizing a BattleField window.
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    // Disable 'maximize' and 'hide' button in a BattleField window.
    this->setWindowFlags(Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
    // Move BattleField window to the center of screen.
    this->move((QApplication::desktop()->width() - this->size().width()) / 2,
               (QApplication::desktop()->height() - this->size().height()) / 2 - 50);

    // coonnects
    connect(ui->mainOrganizerArea_tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabSelected()));
    // Updating on first launch
    tabSelected();
    // Generate button slots
    for(int i = 1; i <= 7*6; i++)
    {
        QString curButtonName = QString("cal_button_%1").arg(i);
        QPushButton * curButton = ui->Calendar_frame->findChild<QPushButton*>(curButtonName);
        connect(curButton, SIGNAL (released()),this, SLOT (onCalendarButtonClicked()));
    }

}
void OrganizerUI::onCalendarButtonClicked()
{
    QPushButton *senderObj = (QPushButton *)sender();
    qDebug() << senderObj->objectName();
    if(PressedButton != NULL){
        PressedButton->setStyleSheet("background-color : rgb(198, 198, 198)");
    }
    PressedButton = senderObj;
    senderObj->setStyleSheet("background-color : rgb(255, 20, 50)");
    ui->CalendarActions_Label->setText("Plan " + senderObj->objectName());
    //ui->CalendarActions_Label->setText(button->objectName());
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
    switch(ui->mainOrganizerArea_tabWidget->currentIndex())
    {
        case TAB_GOALS:
        {
            updateTabGoals();
        }
    }
}
void OrganizerUI::on_newPost_button_clicked()
{
    this->newPostUI_obj->setModal(true);
    this->newPostUI_obj->show();
}

void OrganizerUI::on_newGoal_button_clicked()
{
    this->newGoalUI_obj->setModal(true);
    this->newGoalUI_obj->show();
}
void OrganizerUI::updateTabGoals()
{
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

    on_goalTitle_ComboBox_currentIndexChanged(ui->goalTitle_ComboBox->currentText());
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
        labelTimeLeft->setText(goal->getStepTimeLeft(i).toString("hh:mm:ss"));
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
    ui->step1_checkBox->setEnabled(false);
    ui->step2_checkBox->setEnabled(true);
}

void OrganizerUI::on_step2_checkBox_clicked()
{
    ui->step2_checkBox->setEnabled(false);
    ui->step3_checkBox->setEnabled(true);
}

void OrganizerUI::on_step3_checkBox_clicked()
{
    ui->step3_checkBox->setEnabled(false);
    ui->step4_checkBox->setEnabled(true);
}

void OrganizerUI::on_step4_checkBox_clicked()
{
    ui->step4_checkBox->setEnabled(false);
    ui->step5_checkBox->setEnabled(true);
}

void OrganizerUI::on_step5_checkBox_clicked()
{
    ui->step5_checkBox->setEnabled(false);
}

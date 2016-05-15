#include "newgoalui.h"
#include "ui_newgoalui.h"
#include "organizerui.h"
#include "goal.h"

#define MAX_GOALS_COUNT 5

NewGoalUI::NewGoalUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGoalUI)
{
    ui->setupUi(this);
    // Get Organizer object from NewGoalUI parent - OrganizeUI window.
    OrganizerUI * parent_org = (OrganizerUI *)parent;
    this->organizer = parent_org->getOrganizer();
}

NewGoalUI::~NewGoalUI()
{
    delete ui;
}

void NewGoalUI::on_Save_pusButton_clicked()
{
    // Get strings for creating a new Goal.
    QString title = ui->Title_Line->text();
    QString description = ui->Description_TextEdit->toPlainText();
    QString category = ui->Category_ComboBox->currentText();
    // Create a new goal.
    Goal *newGoal = organizer->addGoal(title, description, category);
    // Insert steps into this goal.
    for (int i = 0; i < MAX_GOALS_COUNT; i++)
    {
        // Get StepTitle from lineEdit.
        QString lineEditName = QString("StepTitle_LineEdit_%1").arg(QString::number(i + 1));
        QLineEdit *lineEdit = ui->AddStep_ScrollingArea->findChild<QLineEdit *>(lineEditName);
        if(!QString::compare(lineEdit->text(), "")) {
            continue;
        }
        // Get HoursPerStep from spinBox.
        QString timeEditName = QString("AddStep_TimEdit_%1").arg(QString::number(i + 1));
        QSpinBox *spinBox = ui->AddStep_ScrollingArea->findChild<QSpinBox *>(timeEditName);
        int hours = spinBox->value();
        // Get DeadlineTime from dateEdit.
        QString dateEditName = QString("dateEdit_%1").arg(QString::number(i + 1));
        QDateEdit *dateEdit = ui->AddStep_ScrollingArea->findChild<QDateEdit *>(dateEditName);
        QDateTime dateTime = dateEdit->dateTime();
        // Create a new goal.
        newGoal->addNewStep(lineEdit->text(), StepTime(hours, 0, 0), dateTime);
    }
    // Update ComboBox in OrganiseUI window.
    OrganizerUI * parent_org = (OrganizerUI *)this->parent();
    parent_org->updateTabGoals();
    // Close this window.
    emit close();
}

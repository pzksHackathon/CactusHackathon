#include "newgoalui.h"
#include "ui_newgoalui.h"
#include "organizerui.h"
#include "goal.h"

#define MAX_STEPS_COUNT 5

NewGoalUI::NewGoalUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGoalUI)
{
    ui->setupUi(this);
    // Get Organizer object from NewGoalUI parent - OrganizeUI window.
    OrganizerUI *orgUiParent = (OrganizerUI *)this->parent();
    this->organizer = orgUiParent->getOrganizer();
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
    // Arrays for holding certain values.
    QString stepsNames[5];
    int hours[5];
    QDateTime dates[5];
    // Insert steps into this goal.
    for (int i = 0; i < MAX_STEPS_COUNT; i++)
    {
        // Get StepTitle from lineEdit.
        QString lineEditName = QString("StepTitle_LineEdit_%1").arg(QString::number(i + 1));
        QLineEdit *lineEdit = ui->AddStep_ScrollingArea->findChild<QLineEdit *>(lineEditName);
        stepsNames[i] = lineEdit->text();
        // Get HoursPerStep from spinBox.
        QString timeEditName = QString("AddStep_TimEdit_%1").arg(QString::number(i + 1));
        QSpinBox *spinBox = ui->AddStep_ScrollingArea->findChild<QSpinBox *>(timeEditName);
        hours[i] = spinBox->value();
        // Get DeadlineTime from dateEdit.
        QString dateEditName = QString("dateEdit_%1").arg(QString::number(i + 1));
        QDateEdit *dateEdit = ui->AddStep_ScrollingArea->findChild<QDateEdit *>(dateEditName);
        dates[i] = dateEdit->dateTime();
    }
    // Create a new goal.
    OrganizerUI * parent_org = (OrganizerUI *)this->parent();
    parent_org->setNewGoal(title, description, category, stepsNames, hours, dates);
    // Update ComboBox in OrganiseUI window.
    parent_org->updateTabGoals();
    // Close this window.
    emit close();
}

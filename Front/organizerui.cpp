#include <QDesktopWidget>
#include <qdatetime.h>

#include "organizerui.h"
#include "ui_organizerui.h"

#include "newpostui.h"
#include <QDebug>
QPushButton * PressedButton = NULL;

OrganizerUI::OrganizerUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OrganizerUI)
{
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

OrganizerUI::~OrganizerUI()
{
    delete ui;
}

void OrganizerUI::on_newPost_button_clicked()
{
    this->newPostUI_obj->setModal(false);
    this->newPostUI_obj->show();
}

void OrganizerUI::on_newGoal_button_clicked()
{
    this->newGoalUI_obj->setModal(false);
    this->newGoalUI_obj->show();
}


/*void OrganizerUI::on_Monday1_button_clicked()
{
    if(PressedButton != NULL){
        PressedButton->setStyleSheet("background-color : rgb(198, 198, 198)");
    }
    PressedButton = ui->Monday1_button;
    ui->Monday1_button->setStyleSheet("background-color: rgb(255, 20, 50);");
}

void OrganizerUI::on_Tuesday1_button_clicked()
{
    if(PressedButton != NULL){
        PressedButton->setStyleSheet("background-color : rgb(198, 198, 198)");
    }
    PressedButton = ui->Tuesday1_button;
    ui->Tuesday1_button->setStyleSheet("background-color: rgb(255, 20, 50);");
}

void OrganizerUI::on_Wednesday1_button_clicked()
{
    if(PressedButton != NULL){
        PressedButton->setStyleSheet("background-color : rgb(198, 198, 198)");
    }
    PressedButton = ui->Wednesday1_button;
    ui->Wednesday1_button->setStyleSheet("background-color: rgb(255, 20, 50);");
}

void OrganizerUI::on_Thursday1_button_clicked()
{
    if(PressedButton != NULL){
        PressedButton->setStyleSheet("background-color : rgb(198, 198, 198)");
    }
    PressedButton = ui->Thursday1_button;
    ui->Thursday1_button->setStyleSheet("background-color: rgb(255, 20, 50);");
}*/

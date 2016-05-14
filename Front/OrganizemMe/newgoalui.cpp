#include "newgoalui.h"
#include "ui_newgoalui.h"

NewGoalUI::NewGoalUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGoalUI)
{
    ui->setupUi(this);
}

NewGoalUI::~NewGoalUI()
{
    delete ui;
}

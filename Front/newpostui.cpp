#include "newpostui.h"
#include "ui_newpostui.h"

NewPostUI::NewPostUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewPostUI)
{
    ui->setupUi(this);
}

NewPostUI::~NewPostUI()
{
    delete ui;
}

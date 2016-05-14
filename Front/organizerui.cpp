#include "organizerui.h"
#include "ui_organizerui.h"

OrganizerUI::OrganizerUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OrganizerUI)
{
    ui->setupUi(this);
}

OrganizerUI::~OrganizerUI()
{
    delete ui;
}

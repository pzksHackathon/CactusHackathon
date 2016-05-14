#include <QDesktopWidget>

#include "organizerui.h"
#include "ui_organizerui.h"

#include "newpostui.h"

OrganizerUI::OrganizerUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OrganizerUI)
{
    ui->setupUi(this);
    this->newPostUI_obj = new NewPostUI(this);

    // Disable resizing a BattleField window.
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    // Disable 'maximize' and 'hide' button in a BattleField window.
    this->setWindowFlags(Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
    // Move BattleField window to the center of screen.
    this->move((QApplication::desktop()->width() - this->size().width()) / 2,
               (QApplication::desktop()->height() - this->size().height()) / 2 - 50);
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

#include "newpostui.h"
#include "ui_newpostui.h"
#include "organizer.h"
#include "organizerui.h"

NewPostUI::NewPostUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewPostUI)
{
    ui->setupUi(this);
}

NewPostUI::~NewPostUI()
{
    delete ui;
}

void NewPostUI::on_NewPostSave_pusButton_clicked()
{
    // Get title and description for creating a new post.
    QString postTitle = ui->NewPostTitle_lineEdit->text();
    QString postDescription = ui->NewPost_Description_TextEdit->toPlainText();
    // Create a new post. While creation, get current Goal title.
    OrganizerUI *orgUiParent = (OrganizerUI *)this->parent();
    QString currentGoalTitle = orgUiParent->setNewDiaryPost(postTitle, postDescription);
    // Update posts in Diary tab in OrganizeUI window.
    orgUiParent->on_goalTitle_ComboBox_2_currentIndexChanged(currentGoalTitle);
    // Close a "New Post" window.
    emit close();
}

#include "newpostui.h"
#include "ui_newpostui.h"
#include "organizer.h"
#include "organizerui.h"
#include "goal.h"

#include <QDebug>

NewPostUI::NewPostUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewPostUI)
{
    ui->setupUi(this);
    OrganizerUI *orgUiParent = (OrganizerUI *)this->parent();
    this->organizer = orgUiParent->getOrganizer();
}

NewPostUI::~NewPostUI()
{
    delete ui;
}

void NewPostUI::on_NewPostSave_pusButton_clicked()
{
    // Get string for creating a new post.
    QString postTitle = ui->NewPostTitle_lineEdit->text();
    QString postDescription = ui->NewPost_Description_TextEdit->toPlainText();
    // Create a new post.
    OrganizerUI *orgUiParent = (OrganizerUI *)this->parent();
    // Update posts in Diary window.
    QString currentGoalTitle = orgUiParent->setNewDiaryPost(postTitle, postDescription);
    orgUiParent->on_goalTitle_ComboBox_2_currentIndexChanged(currentGoalTitle);

    Goal *tempGoal = organizer->getGoal(currentGoalTitle);
    qDebug() << QString::number(tempGoal->getDiary()->getPosts().size());
    // Close a "New Post" window.
    emit close();
}

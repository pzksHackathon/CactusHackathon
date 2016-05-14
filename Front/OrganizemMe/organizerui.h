#ifndef ORGANIZERUI_H
#define ORGANIZERUI_H

#include <QMainWindow>

// Includes for new windows.
#include "newpostui.h"
#include "newgoalui.h"

namespace Ui {
class OrganizerUI;
}

class OrganizerUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrganizerUI(QWidget *parent = 0);
    ~OrganizerUI();

private slots:
    void on_newPost_button_clicked();

    void on_newGoal_button_clicked();

private:
    NewPostUI *newPostUI_obj;
    NewGoalUI *newGoalUI_obj;
    Ui::OrganizerUI *ui;
};

#endif // ORGANIZERUI_H

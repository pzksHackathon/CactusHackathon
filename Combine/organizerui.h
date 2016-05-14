#ifndef ORGANIZERUI_H
#define ORGANIZERUI_H

#include <QMainWindow>
#include "organizer.h"
#include "newpostui.h"
#include "newgoalui.h"
enum TABS {TAB_GOALS, TAB_DIARY, TAB_CALENDAR, TAB_STATS, TAB_PERKS, TAB_TM};
namespace Ui {
class OrganizerUI;
}

class OrganizerUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrganizerUI(Organizer * organizer, QWidget *parent = 0);
    Organizer * getOrganizer();
    ~OrganizerUI();
    void updateTabGoals();

private:
    // pointer to object
    Ui::OrganizerUI *ui;
    Organizer * organizer;
    bool startButtonIsPressed;
    QTimer *workTimer;

private slots:
    void tabSelected();
    void on_newPost_button_clicked();

    void on_newGoal_button_clicked();

    void on_goalTitle_ComboBox_currentIndexChanged(const QString &arg1);

    void on_step1_checkBox_clicked();

    void on_step2_checkBox_clicked();

    void on_step3_checkBox_clicked();
    void on_step4_checkBox_clicked();
    void on_step5_checkBox_clicked();
    void onCalendarButtonClicked();
    void on_startTimer_button_clicked(bool checked);
    void decreaseSecond();
    void on_goalSave_button_clicked();

private:
    NewPostUI *newPostUI_obj;
    NewGoalUI *newGoalUI_obj;
};

#endif // ORGANIZERUI_H

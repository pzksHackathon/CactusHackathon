#ifndef ORGANIZERUI_H
#define ORGANIZERUI_H

#include <QMainWindow>
#include "organizer.h"
#include "newpostui.h"
#include "newgoalui.h"
#include "productivitychart.h"

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
    // This functions returns current Goal title.
    QString setNewDiaryPost(QString title, QString description);
    void setNewGoal(QString title, QString description, QString category, QString stepsNames[5], int hours[5], QDateTime dates[5]);
    void updateDiary();
private:
    // pointer to object
    Ui::OrganizerUI *ui;
    Organizer * organizer;
    bool startButtonIsPressed;
    QTimer *workTimer;
    void updateWorkTime();

public slots:
     void on_goalTitle_ComboBox_2_currentIndexChanged(const QString &arg1);

private slots:
    void tabSelected();
    void decreaseSecond();
    void on_goalTitle_ComboBox_currentIndexChanged(const QString &arg1);
    void onCalendarButtonClicked();
    void on_startTimer_button_clicked();
    void on_goalSave_button_clicked();
    void on_timeManagSave_button_clicked();
    void on_newPost_button_clicked();
    void on_newGoal_button_clicked();
    void on_step1_checkBox_clicked();
    void on_step2_checkBox_clicked();
    void on_step3_checkBox_clicked();
    void on_step4_checkBox_clicked();
    void on_step5_checkBox_clicked();

private:
    NewPostUI *newPostUI_obj;
    NewGoalUI *newGoalUI_obj;
    ProductivityChart * chart;
};

#endif // ORGANIZERUI_H

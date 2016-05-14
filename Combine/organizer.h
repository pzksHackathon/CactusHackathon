#ifndef ORGANIZER
#define ORGANIZER
#include <algorithm>
#include <vector>
#include "Goal.h"
#include "Timer.h"
#include "calendar.h"
#include "notificationmanager.h"
class Organizer{
private:
    vector<Goal *> goals;
    Timer * timer;
    Calendar * calendar;
    NotificationManager * notManager;
public:
    Goal * addGoal(QString name, QString description, QString category);
    int getGoalCount();
    Goal * getGoal(QString title);
    Goal *getGoal(int index);
};

#endif // ORGANIZER


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
};

#endif // ORGANIZER


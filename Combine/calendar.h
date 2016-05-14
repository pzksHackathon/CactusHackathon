#ifndef CALENDAR_H
#define CALENDAR_H
#include "month.h"
class Calendar{
private:
    Month * month;
public:
    Calendar(int countDaysInMonth, int countDaysBef){
        Day befDays[7];
        for (int i = 0; i < 7; i++)
            befDays[i] = Day ((25 + i) % 31 + 1); // prototype for this mounth
        month = new Month(countDaysInMonth, countDaysBef, befDays);

    }
    Month * getMounth()
    {
        return month;
    }
};


#endif // CALENDAR_H


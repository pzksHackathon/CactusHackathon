#ifndef MONTH
#define MONTH
#include "day.h"
class Month{
private:
    Day days[6][7];
    int weeks;
    int countDaysBef;
public:
    Month (int countDays, int countDaysBef, Day daysBef[7])
    {
        this->countDaysBef = countDaysBef;
        for (int i = 0; i < 7; i++)
            days[0][i] = daysBef[i];
        weeks = (countDays + countDaysBef) / 7 + 1;
        for (int i = 1; i < weeks; i++)
            for (int j = 0; j < 7; j++)
                days[i][j] = Day((7 - countDaysBef + (i - 1) * 7 + j) % countDays + 1); // magic
    }

    int getWeeks(){
        return weeks;
    }

    int date(int week, int day){
        return days[week][day].getDate();
    }

    Day getDay(int week, int day)
    {
        return days[week][day];
    }

    Day getDay(int date)
    {
        return days[(date + countDaysBef - 1) / 7][(date + countDaysBef - 1) % 7];
    }
};

#endif // MONTH


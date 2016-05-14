#ifndef DAY
#define DAY
#include <QTime>
class Day{
private:
    int date;
public:
    QTime start, end, left;
    Day (){
    }

    Day (int date)
    {
        this->date = date;
        start = QTime(0, 0, 0);
        end = QTime(0, 0, 0);
        left = QTime(0, 0, 0);
    }
    Day (int date, QTime start, QTime end, QTime left)
    {
        this->date = date;
        this->start = start;
        this->end = end;
        this->left = left;
    }

    int getDate(){
        return date;
    }

};

#endif // DAY


#ifndef DAY
#define DAY
#include <QTime>
class Day{
private:
    int date;
    QTime start, end, left;
public:
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

    void setEnd (QTime time)
    {
        end = time;
    }
    void setStart (QTime time)
    {
        //start.setHMS(time.hour(), time.minute(), time.second());
        start = time;
    }
    QTime getLeft ()
    {
        return left;
    }
    QTime getEnd ()
    {
        return end;
    }
    QTime getStart ()
    {

        return start;
    }
    void setLeft (QTime time)
    {
        left = time;
    }
};

#endif // DAY


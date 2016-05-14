#ifndef TIMER_H
#define TIMER_H
#include <QTime>
class Timer{
private:

    QTime startTime;
    QTime allTime;
    QTime curTime;
    QTime timeLeft;
    bool isEnd;
    bool isStopped;


public:
    Timer (QTime time){
        timeLeft = time;
        isEnd = false;
        isStopped = true;
    }

    QTime getTimeLeft() // returns time left
    {
        if (!isStopped)
        {
            QTime tmptime;
            curTime.start();
            tmptime = timeLeft.addSecs(curTime.secsTo(startTime));
            return tmptime;
        }
        else return timeLeft;
    }

    QTime getTimeElapsed() // returns the elapsed time from the start
    {
        curTime.start();
        QTime tmptime(0, 0, 0);
        return tmptime.addSecs(startTime.secsTo(curTime));
    }

    QTime getStartTime() // returns time when timer start
    {
        return startTime;
    }

    bool isTimerEnd() // returns is timer ends
    {
        isEnd = this->getTimeElapsed() >= timeLeft;
        return isEnd;
    }

    void start() // start timer
    {
        if (isStopped){
            startTime.start();
            isStopped = false;
        }
    }

    QTime stop() // stop timer and returns time elapsed from the start
    {
        if (!isStopped)
        {
            timeLeft = this->getTimeLeft();
            isStopped = true;
        }
        return this->getTimeElapsed();
    }


};

#endif // TIMER_H


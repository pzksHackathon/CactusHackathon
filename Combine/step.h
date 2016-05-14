#ifndef STEP
#define STEP
#include <QTime>
#include <QString>
#include "steptime.h"
using namespace std;
class Step{
private:
    QString title;
    StepTime initialTimeToFinish;
    StepTime timeToFinish;
    QDateTime deadline;
    bool completed;
public:
    Step(QString title, StepTime hoursToFinish, QDateTime deadline);
    bool isCompleted();
    QString getTitle();
    StepTime getTimeLeft();
    StepTime getInitialTime();
    void reduceStepTime(StepTime time);
    QDateTime getDeadline();
};

#endif // STEP

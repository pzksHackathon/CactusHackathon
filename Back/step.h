#ifndef STEP
#define STEP
#include <QTime>
#include <QString>
using namespace std;
class Step{
private:
    QString title;
    QTime initialTimeToFinish;
    QTime timeToFinish;
    bool completed;
public:
    Step(QString title, QTime timeToFinish);
    bool isCompleted();
    QString getTitle();
    QTime getTimeLeft();
    QTime getInitialTime();
    void reduceStepTime(QTime time);
};

#endif // STEP

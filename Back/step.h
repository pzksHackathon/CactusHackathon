#ifndef STEP
#define STEP
#include <QTime>
#include <string>
using namespace std;
class Step{
private:
    string title;
    QTime initialTimeToFinish;
    QTime timeToFinish;
    bool completed;
public:
    Step(string title, QTime timeToFinish);
    bool isCompleted();
    string getTitle();
    QTime getTimeLeft();
    QTime getInitialTime();
    void reduceStepTime(QTime time);
};

#endif // STEP

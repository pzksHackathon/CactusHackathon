#ifndef STEPTIME_H
#define STEPTIME_H
#include <QString>
class StepTime{
private:
    unsigned int seconds;
public:
    StepTime() {}
    StepTime(unsigned int hours, unsigned int minutes, unsigned int seconds);
    void reduceSeconds(unsigned int seconds);
    unsigned int getSeconds();
    QString toString();
};

#endif // STEPTIME_H

#include "steptime.h"

StepTime::StepTime(unsigned int hours, unsigned int minutes, unsigned int seconds)
{
    this->seconds = seconds + 60 * minutes + hours * 3600;
}

void StepTime::reduceSeconds(unsigned int seconds)
{
    this->seconds -= seconds;
}

unsigned int StepTime::getSeconds()
{
    return seconds;
}

QString StepTime::toString()
{
    int hours = this->seconds / 3600;
    int minutes = (this->seconds - hours * 3600)/60;
    int seconds = this->seconds - hours * 3600 - minutes * 60;
    return QString("%1:%2:%3").arg(QString::number(hours)).arg(QString::number(minutes)).arg(QString::number(seconds));
}

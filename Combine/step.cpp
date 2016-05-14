#include "step.h"

Step::Step(QString title, StepTime hoursToFinish, QDateTime deadline)
{
    this->timeToFinish = hoursToFinish;
    this->title = title;
    this->deadline = deadline;
    this->completed = false;
}

bool Step::isCompleted()
{
    return completed;
}

QString Step::getTitle()
{
    return title;
}

StepTime Step::getTimeLeft()
{
    return timeToFinish;
}

StepTime Step::getInitialTime()
{
    return initialTimeToFinish;
}

void Step::reduceStepTime(StepTime time)
{
    this->timeToFinish.reduceSeconds(time.getSeconds());
}

QDateTime Step::getDeadline()
{
    return this->deadline;
}

void Step::setCompleted(bool state)
{
    this->completed = state;
}

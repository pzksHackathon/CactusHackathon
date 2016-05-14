#include "step.h"

Step::Step(std::string title, QTime timeToFinish)
{
    this->title = title;
    this->timeToFinish = timeToFinish;
    this->completed = false;
}

bool Step::isCompleted()
{
    return completed;
}

string Step::getTitle()
{
    return title;
}

QTime Step::getTimeLeft()
{
    return timeToFinish;
}

QTime Step::getInitialTime()
{
    return initialTimeToFinish;
}

void Step::reduceStepTime(QTime time)
{
    this->timeToFinish.addMSecs(QTime().msecsTo(time));
}

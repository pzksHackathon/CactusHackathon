#include "goal.h"


Goal::Goal(QString name, QString description, QString category)
{
    this->title = name;
    this->description = description;
    this->category = category;
}

QString Goal::getTitle()
{
    return title;
}

QString Goal::getDescription()
{
    return description;
}

QString Goal::getCategory()
{
    return category;
}

void Goal::addNewStep(QString title, QTime timeToFinish)
{
    Step * step = new Step(title, timeToFinish);
    this->steps.push_back(step);
}

int Goal::getStepCount()
{
    return steps.size();
}


bool Goal::reduceStepTime(int index, QTime time)
{
    if(index >= this->getStepCount())
        return false;
    steps.at(index)->reduceStepTime(time);
    return true;
}

bool Goal::isStepCompleted(int index)
{
    return steps.at(index)->isCompleted();
}

QString Goal::getStepTitle(int index)
{
    return steps.at(index)->getTitle();
}

QTime Goal::getStepTimeLeft(int index)
{
    return steps.at(index)->getTimeLeft();
}

QTime Goal::getStepInitialTime(int index)
{
    return steps.at(index)->getInitialTime();
}

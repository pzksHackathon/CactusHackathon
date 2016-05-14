#include "goal.h"


Goal::Goal(string name, string description, string category)
{
    this->title = name;
    this->description = description;
    this->category = category;
}

string Goal::getTitle()
{
    return title;
}

string Goal::getDescription()
{
    return description;
}

string Goal::getCategory()
{
    return category;
}

void Goal::addNewStep(string title, QTime timeToFinish)
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

string Goal::getStepTitle(int index)
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

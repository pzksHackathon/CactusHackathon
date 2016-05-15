#include "goal.h"

Goal::Goal(QString name, QString description, QString category)
{
    this->title = name;
    this->description = description;
    this->category = category;
    vector<Post> posts;
    this->diary = new Diary(posts);
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

Diary *Goal::getDiary()
{
    return diary;
}

void Goal::addNewStep(QString title, StepTime hoursToFinish, QDateTime deadline)
{
    Step * step = new Step(title, hoursToFinish, deadline);
    this->steps.push_back(step);
}

int Goal::getStepCount()
{
    return (int)steps.size();
}

bool Goal::reduceStepTime(int index, StepTime time)
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

void Goal::setStepCompleted(int index, bool state)
{
    steps.at(index)->setCompleted(state);
}

QString Goal::getStepTitle(int index)
{
    return steps.at(index)->getTitle();
}

StepTime Goal::getStepTimeLeft(int index)
{
    return steps.at(index)->getTimeLeft();
}

StepTime Goal::getStepInitialTime(int index)
{
    return steps.at(index)->getInitialTime();
}

QDateTime Goal::getStepDeadline(int index)
{
    return steps.at(index)->getDeadline();
}

Goal::~Goal()
{
    for(Step * step : steps)
        delete step;
}

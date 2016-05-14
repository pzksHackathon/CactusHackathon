#include "organizer.h"

Goal *Organizer::addGoal(QString name, QString description, QString category)
{
    Goal * goal = new Goal(name, description, category);
    this->goals.push_back(goal);
    return goal;
}

int Organizer::getGoalCount()
{
    return goals.size();
}

Goal *Organizer::getGoal(QString title)
{
   for(Goal * goal : goals)
       if(goal->getTitle() == title)
           return goal;
   return nullptr;
}

Goal *Organizer::getGoal(int index)
{
    return goals.at(index);
}

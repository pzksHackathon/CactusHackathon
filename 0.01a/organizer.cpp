#include "organizer.h"
#include <fstream>
#include <iostream>
#include <qDebug>
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

void Organizer::save()
{
    std::fstream file;
    file.open("file.txt", std::ios::out | std::ios::trunc );
    file << this->getGoalCount() << std::endl;
    for (int i = 0; i < this->getGoalCount(); i++)
    {
        file << this->getGoal(i)->getTitle().toStdString().length() << std::endl;
        file << this->getGoal(i)->getTitle().toStdString() << std::endl;
         file << this->getGoal(i)->getDescription().toStdString().length() << std::endl;
        file << this->getGoal(i)->getDescription().toStdString() << std::endl;
        file << this->getGoal(i)->getCategory().toStdString().length() << std::endl;
        file << this->getGoal(i)->getCategory().toStdString() << std::endl;
        file << this->getGoal(i)->getStepCount() << std::endl;
        for (int j = 0; j < this->getGoal(i)->getStepCount(); j++)
        {
            file << this->getGoal(i)->getStepTitle(j).toStdString() << std::endl;
            file << this->getGoal(i)->isStepCompleted(j) << std::endl;
            file << this->getGoal(i)->getStepTimeLeft(j).getSeconds() << std::endl;
            file << this->getGoal(i)->getStepDeadline(j).toMSecsSinceEpoch() <<std::endl;
        }
    }
    file.close();
}

void Organizer::load()
{
    std::fstream file;
    file.open("file.txt", std::ios::in);
    int count ;
    file >> count;
    if (count == 0)
        return;
    for (int i = 0; i < count; i++)
    {
        int len;
        char title[100], desc[100], categ[100];
        file >> len;
        file.getline(title, len);
        file >> len;
        file.getline(desc, len);
        file >> len;
        file.getline(categ, len);
        this->addGoal(QString::fromLocal8Bit(title), QString::fromLocal8Bit(desc), QString::fromLocal8Bit(categ));

        int countSteps;
        file >> countSteps;

        for (int j = 0; j < countSteps; j++)
        {
            char stepTitle[100];
            bool isStepComp;
            int sec;
            long msec;
            file.getline(stepTitle, 100);
            file >> isStepComp;
            file >> sec;
            file >> msec;
            QDateTime tmp;
            tmp.setMSecsSinceEpoch((qint64)msec);
            this->getGoal(i)->addNewStep(QString::fromLocal8Bit(stepTitle), StepTime(0 ,0, sec), tmp);
        }
    }
    file.close();

}

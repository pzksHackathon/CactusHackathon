#ifndef GOAL
#define GOAL
#include <algorithm>
#include <vector>
#include <QString>
#include "step.h"
using namespace std;
class Goal{
private:
    QString title;
    QString description;
    QString category;
    vector<Step *> steps;
public:
    Goal(QString name, QString description, QString category);
    QString getTitle();
    QString getDescription();
    QString getCategory();
    void addNewStep(QString title, QTime timeToFinish);
    int getStepCount();
    /**
     * @brief If successfull returns true. If not - false.
     */
    bool reduceStepTime(int index, QTime time);
    bool isStepCompleted(int index);
    QString getStepTitle(int index);
    QTime getStepTimeLeft(int index);
    QTime getStepInitialTime(int index);
    ~Goal();
};

#endif // GOAL


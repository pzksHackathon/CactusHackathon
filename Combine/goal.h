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
    void addNewStep(QString title, StepTime hoursToFinish, QDateTime deadline);
    int getStepCount();
    /**
     * @brief If successfull returns true. If not - false.
     */
    bool reduceStepTime(int index, StepTime time);
    bool isStepCompleted(int index);
    QString getStepTitle(int index);
    StepTime getStepTimeLeft(int index);
    StepTime getStepInitialTime(int index);
    QDateTime getStepDeadline(int index);
    ~Goal();
};

#endif // GOAL


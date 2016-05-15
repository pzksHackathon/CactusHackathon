#ifndef GOAL
#define GOAL
#include <algorithm>
#include <vector>
#include <QString>
#include "step.h"
#include "diary.h"
using namespace std;
class Goal{
private:
    Diary * diary;
    QString title;
    QString description;
    QString category;
    vector<Step *> steps;
public:
    Goal(QString name, QString description, QString category);
    QString getTitle();
    QString getDescription();
    QString getCategory();
    Diary *getDiary();
    void addNewStep(QString title, StepTime hoursToFinish, QDateTime deadline);
    int getStepCount();
    /**
     * @brief If successfull returns true. If not - false.
     */
    bool reduceStepTime(int index, StepTime time);
    bool isStepCompleted(int index);
    void setStepCompleted(int index, bool state);
    QString getStepTitle(int index);
    StepTime getStepTimeLeft(int index);
    StepTime getStepInitialTime(int index);
    QDateTime getStepDeadline(int index);
    ~Goal();
};

#endif // GOAL


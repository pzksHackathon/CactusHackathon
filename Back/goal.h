#ifndef GOAL
#define GOAL
#include <algorithm>
#include <vector>
#include <string>
#include "step.h"
using namespace std;
class Goal{
private:
    string title;
    string description;
    string category;
    vector<Step *> steps;
public:
    Goal(string name, string description, string category);
    string getTitle();
    string getDescription();
    string getCategory();
    void addNewStep(string title, QTime timeToFinish);
    int getStepCount();
    /**
     * @brief If successfull returns true. If not - false.
     */
    bool reduceStepTime(int index, QTime time);
    bool isStepCompleted(int index);
    string getStepTitle(int index);
    QTime getStepTimeLeft(int index);
    QTime getStepInitialTime(int index);
};

#endif // GOAL


#include "organizerui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Organizer object for OrganizerUI constructor.
    Organizer * organizer = new Organizer();
    // Default empty goal.
    Goal * goal = organizer->addGoal("TestGoalTitle", "TestGoalDescription", "TestGoalCategory");
    StepTime stepTime = StepTime(10,10,10);
    QDateTime dateTime = QDateTime(QDate(2016, 5, 30), QTime(2,0,0));
    goal->addNewStep("Default first step.", stepTime, dateTime);
    goal->addNewStep("Default second step.", stepTime, dateTime);
    goal->addNewStep("Default third step.", stepTime, dateTime);
    // Initiailze and show OrganizerUI window.
    OrganizerUI * w = new OrganizerUI(organizer);
    w->show();

    return a.exec();
}

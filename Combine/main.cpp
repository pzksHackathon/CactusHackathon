#include "organizerui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Organizer * organizer = new Organizer();
    Goal * goal = organizer->addGoal("FUCKU", "I am fucking you", "FUCKS");
    Goal * goal2 = organizer->addGoal("Goal 2", "Descr2", "category2");

    goal->addNewStep("Dress up", QTime(10, 10, 0));
    goal->addNewStep("Dress1 up", QTime(10, 10, 0));
    goal->addNewStep("Dress2 up", QTime(10, 10, 0));
    goal2->addNewStep("DressFor2 up", QTime(10, 10, 0));
    goal2->addNewStep("DressFor2 up", QTime(10, 10, 0));
    goal2->addNewStep("DressFor2 up", QTime(10, 10, 0));
    goal2->addNewStep("DressFor2 up", QTime(10, 10, 0));

    OrganizerUI * w = new OrganizerUI(organizer);
    w->show();

    return a.exec();
}

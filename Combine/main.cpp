#include "organizerui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Organizer * organizer = new Organizer();
    Goal * goal = organizer->addGoal("FUCKU", "I am fucking you", "FUCKS");
    Goal * goal2 = organizer->addGoal("Goal 2", "Descr2", "category2");
    StepTime stTime = StepTime(10, 10, 10);
    QDateTime time = QDateTime(QDate(2016, 12, 12), QTime());
    goal->addNewStep("Dress up", stTime, time);
    goal->addNewStep("Dress1 up", stTime, time);
    goal->addNewStep("Dress2 up", stTime, time);
    goal2->addNewStep("DressFor2 up", stTime, time);
    goal2->addNewStep("DressFor2 up", stTime, time);
    goal2->addNewStep("DressFor2 up", stTime, time);
    goal2->addNewStep("DressFor2 up", stTime, time);

    OrganizerUI * w = new OrganizerUI(organizer);
    w->show();

    return a.exec();
}

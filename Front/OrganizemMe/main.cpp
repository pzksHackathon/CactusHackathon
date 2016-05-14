#include "organizerui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OrganizerUI w;
    w.show();

    return a.exec();
}

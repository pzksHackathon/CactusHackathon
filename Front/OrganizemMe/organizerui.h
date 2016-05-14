#ifndef ORGANIZERUI_H
#define ORGANIZERUI_H

#include <QMainWindow>

namespace Ui {
class OrganizerUI;
}

class OrganizerUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrganizerUI(QWidget *parent = 0);
    ~OrganizerUI();

private:
    // pointer to object
    Ui::OrganizerUI *ui;
};

#endif // ORGANIZERUI_H

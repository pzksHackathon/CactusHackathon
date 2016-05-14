#ifndef ORGANIZERUI_H
#define ORGANIZERUI_H

#include <QMainWindow>
#include "newpostui.h"

namespace Ui {
class OrganizerUI;
}

class OrganizerUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrganizerUI(QWidget *parent = 0);
    ~OrganizerUI();

private slots:
    void on_newPost_button_clicked();

private:
    NewPostUI *newPostUI_obj;
    Ui::OrganizerUI *ui;
};

#endif // ORGANIZERUI_H

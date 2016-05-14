#ifndef NEWPOSTUI_H
#define NEWPOSTUI_H

#include <QMainWindow>

namespace Ui {
class NewPostUI;
}

class NewPostUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewPostUI(QWidget *parent = 0);
    ~NewPostUI();

private:
    Ui::NewPostUI *ui;
};

#endif // NEWPOSTUI_H

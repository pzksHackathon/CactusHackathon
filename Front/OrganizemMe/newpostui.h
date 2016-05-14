#ifndef NEWPOSTUI_H
#define NEWPOSTUI_H

#include <QDialog>

namespace Ui {
class NewPostUI;
}

class NewPostUI : public QDialog
{
    Q_OBJECT

public:
    explicit NewPostUI(QWidget *parent = 0);
    ~NewPostUI();

private:
    Ui::NewPostUI *ui;
};

#endif // NEWPOSTUI_H

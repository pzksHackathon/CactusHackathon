#ifndef NEWGOALUI_H
#define NEWGOALUI_H
#include "organizer.h"
#include <QDialog>

namespace Ui {
class NewGoalUI;
}

class NewGoalUI : public QDialog
{
    Q_OBJECT

public:
    explicit NewGoalUI(QWidget *parent = 0);
    ~NewGoalUI();

private slots:
    void on_Save_pusButton_clicked();

private:
    Ui::NewGoalUI *ui;
    Organizer * organizer;
};

#endif // NEWGOALUI_H

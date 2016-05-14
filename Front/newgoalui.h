#ifndef NEWGOALUI_H
#define NEWGOALUI_H

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

private:
    Ui::NewGoalUI *ui;
};

#endif // NEWGOALUI_H

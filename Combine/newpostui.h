#ifndef NEWPOSTUI_H
#define NEWPOSTUI_H

#include <QDialog>
#include "organizer.h"

namespace Ui {
class NewPostUI;
}

class NewPostUI : public QDialog
{
    Q_OBJECT

public:
    explicit NewPostUI(QWidget *parent = 0);
    ~NewPostUI();

private slots:
    void on_NewPostSave_pusButton_clicked();

private:
    Ui::NewPostUI *ui;
    Organizer *organizer;
};

#endif // NEWPOSTUI_H

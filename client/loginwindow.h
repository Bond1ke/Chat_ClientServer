#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "qabstractbutton.h"
#include <QDialog>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    QString getter_UserName();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::LoginWindow *ui;
    QString UserName;
};

#endif // LOGINWINDOW_H

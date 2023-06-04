#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_buttonBox_accepted()
{
    if(ui->lineEdit->text().isEmpty() == true)
    {
        UserName = QString("NoName");
    }
    else
    {
        UserName = ui->lineEdit->text();
    }
}

QString LoginWindow::getter_UserName()
{
    return UserName;
}


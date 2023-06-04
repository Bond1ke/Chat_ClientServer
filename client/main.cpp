
#include "loginwindow.h"
#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow l;
    l.setWindowTitle("Login");
    if(l.exec() == QDialog::Accepted)
    {
        MainWindow w;
        w.setter_UserName(l.getter_UserName());
        w.setWindowTitle(l.getter_UserName());
        w.setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
        w.setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
        w.show();
        return a.exec();
    }
    else return 0;
}

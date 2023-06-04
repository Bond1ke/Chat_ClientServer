
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTime>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setter_UserName(QString str);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QByteArray Data;
    QString UserName; //имя клиента
    void SendToServer(QString str);
    quint16 nextBlockSize;
    bool SocketIsConnected = false;
    bool SetSocketName = false;
    bool SocketWasConnected = false;

public slots:
    void slotReadyRead();
    void socketConnected();
    void socketDisconnected();
};

#endif // MAINWINDOW_H

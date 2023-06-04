
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket, &QTcpSocket::connected, this, &MainWindow::socketConnected);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    nextBlockSize = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (SocketWasConnected == false && SocketIsConnected == false)
    {
        socket->connectToHost("192.168.141.46", 54321);
        this->SendToServer(UserName);
        qDebug() << socket->state();
    }
    if (SocketWasConnected == true && SocketIsConnected == false)
    {
        socket = new QTcpSocket(this);
        connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
        connect(socket, &QTcpSocket::connected, this, &MainWindow::socketConnected);
        connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
        nextBlockSize = 0;
        socket->connectToHost("192.168.141.46", 54321);
        this->SendToServer(UserName);
    }
    if (socket->state() == 3)
    {
        ui->textBrowser->append("\n\nYou already connected to this server\n\n");
    }
}

void MainWindow::SendToServer(QString str)
{
    Data.clear(); //обязательно чистим массив данных для отправки
    QDataStream output(&Data, QIODevice::WriteOnly);//создаём объект для записи и указываем адрес массива байтов
    output.setVersion(QDataStream::Qt_6_5);
    if (SetSocketName == true)
    {
        output << UserName;
        SetSocketName = false;
        qDebug()<< "SendToServer - SetSocketName bool value: " << SetSocketName;
        qDebug()<< "SendToServer - UserName (when SetSocketName was true) value: " << UserName;
        socket->write(Data); //записываем массив в сокет
        ui->lineEdit->clear(); //очищаем строку после отправки сообщения
    }
    else if (SetSocketName == false)
    {
        output << QTime::currentTime() << str;
        qDebug() << "SendToServer - (when SetSocketName is false) str value: " << str;
        socket->write(Data); //записываем массив в сокет
        ui->lineEdit->clear(); //очищаем строку после отправки сообщения
    }
}

void MainWindow::slotReadyRead()
{
    QDataStream input(socket);
    input.setVersion(QDataStream::Qt_6_5);
    if(input.status() == QDataStream::Ok)
    {
        QString str;
        QTime time;

        input >> time >> str;
        ui->textBrowser->append(time.toString() + " " +str);
    }
    else
    {
        ui->textBrowser->append("read error");
    }
}

void MainWindow::socketDisconnected()
{
    if(SocketIsConnected == true)
    {
        ui->textBrowser->append("Disconnecting...\n\n");
        SocketWasConnected = true;
        socket->disconnectFromHost();
        SocketIsConnected = false;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(socket->state() == 3)
    {
        SendToServer(ui->lineEdit->text());
    }
    else
    {
        ui->textBrowser->append("\n\nServer isn`t working or u already disconnected from the server\n\n");
        SocketIsConnected = false;
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(socket->state() == 3)
    {
        socketDisconnected();
    }
    else
    {
        ui->textBrowser->append("\n\nServer isn`t working or u already disconnected from the server\n\n");
        SocketIsConnected = false;
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->textBrowser->append("\n\nList of available opportunity:\n\n!list       - will give information about who is on the server\n@name smth      - there will be an appeal to the user <name> with the text <smth>\n\n\n");
}

void MainWindow::on_lineEdit_returnPressed()
{
    SendToServer(ui->lineEdit->text());
}

void MainWindow::socketConnected()
{
    SocketIsConnected = true;
    qDebug() << "Client connected successfully";
}

void MainWindow::setter_UserName(QString str)
{
    UserName = str;
}


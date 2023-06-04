#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector> //все сокеты будем записывать в вектор, для этого подключаем библиотеку
#include <QTime>
#include <QFile>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server();
    QTcpSocket *socket;

private:
    QByteArray Data; //данные для передачи
    void SendToClient(QString str, QString from, QString where);

    QMap <QTcpSocket*, QString> map_Sockets;//хеш-таблица сокетов
    int client_count = 0;

public:
    void incomingConnection(qintptr socketDescriptor); //обработчик новых подключений
    void slotReadyRead(); //обработчик полученных от клиента сообщений
    void clientDisconnected();
};

#endif // SERVER_H

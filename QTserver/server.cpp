#include "server.h"

Server::Server()
{
    if(this->listen(QHostAddress::Any, 54321)) //QHostAddress::Any означает что сервер будет принимать сигналы с любого адреса
    {
        qDebug() << QTime::currentTime().toString() << ": Starting the server - success.\n";
    }
    else
    {
        qDebug() << QTime::currentTime().toString() << ": Starting the server - error.";
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << QTime::currentTime().toString() << ": Connection request received.";
    socket = new QTcpSocket(this); // создаём новый сокет
    socket -> setSocketDescriptor(socketDescriptor); //устанавливаем в сокет дескриптор (неотрицательное число, которое индентифицирует поток ввода/вывода)
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);//объединяем сигнал readyRead с соответствующим слотом
    connect(socket, &QTcpSocket::disconnected, this, &Server::clientDisconnected); //теперь при отключении клиента, сервер удалит сокет, как только это будет возможно
    map_Sockets.insert(socket, "UNDEFINED");
    client_count++;
    qDebug() << "A new client has been added to the structure.\n";
}

void Server::slotReadyRead() //описание слота для чтения сообщений
{
    QFile file("buffer.txt"); // файл для записи буфера сервера

    if(file.open(QIODevice::Append | QIODevice::Text))
    { // Если файл успешно открыт для записи в текстовом режиме
        QTextStream writeStream(&file); // Создаем объект класса QTextStream
        // и передаем ему адрес объекта fileOut

        qDebug() << "Message request received:";
        writeStream << "Message request received:" << "\n";

        socket = (QTcpSocket*)sender(); //записываем в socket тот сокет, с которого пришло сообщение
        QDataStream input(socket); //используем класс для потокого ввода и вывода информации; работаем с данными, которые находятся в сокете
        input.setVersion(QDataStream::Qt_6_5);
        if(input.status() == QDataStream::Ok)
        {
            QString str, from, where = "all", mention = "@";
            QTime time;

            input >> time >> str;
            from  = map_Sockets[socket];

            if (map_Sockets[socket] == "UNDEFINED") // Присоединение пользователя
            {
                map_Sockets[socket] = str;

                from = "Server";
                str = "Client " + map_Sockets[socket] + " connected to the server";

                qDebug() << "Sender - " << "Server";
                qDebug() << "Time - " << time.toString();
                qDebug() << "Message - " << str;
                qDebug() << "Recipient - " << where;

                writeStream << "Sender - " << "Server" << "\n";
                writeStream << "Time - " << time.toString() << "\n";
                writeStream << "Message - " << str << "\n";
                writeStream << "Recipient - " << where << "\n";

                SendToClient(str, from, where);
                qDebug() << "Message was successfully sent.\n";
                writeStream << "Message was successfully sent.\n";
                writeStream << "***********************************************\n\n\n";
                return;
            }
            else if(str == "!list") // !list - список подключённых клиентов
            {
                QMap<QTcpSocket*, QString>::iterator i;
                int count = 1;

                qDebug() << "Sender - " << map_Sockets[socket];
                qDebug() << "Time - " << time.toString();
                qDebug() << "Message - " << str;
                qDebug() << "Recipient - " << where;

                writeStream << "Sender - " << map_Sockets[socket] << "\n";
                writeStream << "Time - " << time.toString() << "\n";
                writeStream << "Message - " << str << "\n";
                writeStream << "Recipient - " << where << "\n";


                str = "";
                qDebug() << "\nResult of the command !list: ";
                writeStream << "\nResult of the command !list: " << "\n";
                for(auto e : map_Sockets.keys())
                {
                    QString num = QString::number(count++);
                    str += num + ". " + map_Sockets.value(e) + "\n";
                    qDebug() << num + "." << e << "-" << map_Sockets.value(e) << '\n';
                    writeStream << num + "." << e << "-" << map_Sockets.value(e) << '\n';
                }
                str = "\n\nConnected clients:\n" + str;
                str = "!list" + str;
                SendToClient(str, from, where);
                qDebug() << "Message was successfully sent.\n";
                writeStream << "Message was successfully sent.\n";
                writeStream << "***********************************************\n\n\n";
                return;
            }
            else if (str.contains(mention, Qt::CaseInsensitive)) // упоминание @
            {
                where = str;
                where.remove("@");
                QString firstWord = where.split(" ").at(0);

                qDebug() << "Sender - " << map_Sockets[socket];
                qDebug() << "Time - " << time.toString();
                qDebug() << "Message - " << str;
                qDebug() << "Recipient - " << firstWord;

                writeStream << "Sender - " << map_Sockets[socket] << "\n";
                writeStream << "Time - " << time.toString() << "\n";
                writeStream << "Message - " << str << "\n";
                writeStream << "Recipient - " << firstWord << "\n";

                SendToClient(str, from, firstWord);
                qDebug() << "Message was successfully sent.\n";
                writeStream << "Message was successfully sent.\n";
                writeStream << "***********************************************\n\n\n";
                return;
            }
            qDebug() << "Sender - " << map_Sockets[socket];
            qDebug() << "Time - " << time.toString();
            qDebug() << "Message - " << str;
            qDebug() << "Recipient - " << where;

            writeStream << "Sender - " << map_Sockets[socket] << "\n";
            writeStream << "Time - " << time.toString() << "\n";
            writeStream << "Message - " << str << "\n";
            writeStream << "Recipient - " << where << "\n";

            SendToClient(str, from, where);
            qDebug() << "Message was successfully sent.\n";
            writeStream << "Message was successfully sent.\n";

            // запись в файл истории сообщений
        }
        else
        {
            qDebug() << "DataStream error\n";
            writeStream << "DataStream error" << "\n\n\n";
        }
        writeStream << "***********************************************\n\n\n";
        file.close(); // Закрываем файл
    }
    else
    {
        qDebug() << "File isn`t open for write only";
    }
}

void Server::SendToClient(QString str, QString from, QString where)
{
    if (where == "all")
    {
        Data.clear(); //обязательно чистим массив данных для отправки
        QDataStream output(&Data, QIODevice::WriteOnly); //создаём объект для записи и указываем адрес массива байтов
        output.setVersion(QDataStream::Qt_6_5);
        str = from + QString("\n") + str + QString("\n");

        output << QTime::currentTime() << str;

        for(auto e : map_Sockets.keys())
        {
            e->write(Data);
        }
        return;
    }
    else
    {
        Data.clear(); //обязательно чистим массив данных для отправки
        QDataStream output(&Data, QIODevice::WriteOnly); //создаём объект для записи и указываем адрес массива байтов
        output.setVersion(QDataStream::Qt_6_5);
        str = from + QString("\n") + str + QString("\n");

        output << QTime::currentTime() << str;

        for(auto e : map_Sockets.keys())
        {
            if (map_Sockets.value(e) == where || map_Sockets.value(e) == from)
            {

                e->write(Data);
            }
        }
        return;
    }
}

void Server::clientDisconnected()//слот для удаления сокета
{
    QFile file("buffer.txt"); // файл для записи буфера сервера

    if(file.open(QIODevice::Append | QIODevice::Text))
    { // Если файл успешно открыт для записи в текстовом режиме
        QTextStream writeStream(&file); // Создаем объект класса QTextStream
        // и передаем ему адрес объекта fileOut

        socket = (QTcpSocket*)sender();

        QString ClientName = map_Sockets[socket];
        QString where = "all";
        QString from = "Server";
        QString str = "Client " + ClientName + " disconnected from the server";

        int result = map_Sockets.remove(socket);

        if (result)
        {
            socket->deleteLater();
            SendToClient(str, from, where);
            client_count--;
            qDebug() << "Client" << ClientName << "disconnected from the server";
            writeStream << "Client " << ClientName << " disconnected from the server\n";
        }
        else
        {
            qDebug() << "error, could't disconnect client";
            writeStream << "error, could't disconnect client\n";
        }
        writeStream << "***********************************************\n\n\n";
        file.close(); // Закрываем файл
    }
    else
    {
        qDebug() << "File isn`t open for write only";
    }
}

#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) :
    QObject(parent)
{
}

void SocketTest::Connect()
{
    socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 1234);

    if(socket->waitForConnected(3000))
    {
        qDebug() << "Connected to server";

        // sending
        socket->write("hello server 1234.....");
        socket->waitForBytesWritten(2000);
        socket->waitForReadyRead(4000);
        qDebug() << "Reading ... " << socket->bytesAvailable();

        qDebug() << socket->readAll();

        socket->close();
    }
    else
    {
        qDebug() << "Not connected ....";
    }
}
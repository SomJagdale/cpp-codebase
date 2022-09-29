#include "myserver.h"

int MyServer::noOfClients = 0;
MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
}

void MyServer::StartServer()
{
    if(!this->listen("127.0.0.1",1234))
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "Listening...";
    }
}

void MyServer::incomingConnection(int socketDescriptor)
{
    qDebug() << socketDescriptor << " Connecting...";
    if (MyServer::noOfClients < 10)
	{
		MyThread *thread = new MyThread(socketDescriptor, this);
		connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
		thread->start();
		MyServer::noOfClients++;
	}
	else 
	    qDebug() << "No more connections...  max count is 10 only";
	
}
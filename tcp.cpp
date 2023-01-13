#include "tcp.h"

Tcp::Tcp()
{
//    mp_thread.reset(new QThread);
//    tcpServer = new QTcpServer(nullptr);
//    connect(mp_thread.get(), &QThread::started, this, &Tcp::started);
//    connect(mp_thread.get(), &QThread::finished, tcpServer, &QTcpServer::deleteLater);
//    connect(mp_thread.get(), &QThread::finished, mp_thread.get(), &QThread::deleteLater);
//    connect(this, &Tcp::listen, tcpServer, &QTcpServer::listen);
//    connect(this, &Tcp::unlisten, tcpServer, &QTcpServer::close);
//    connect(tcpServer, &QTcpServer::)


//    tcpServer->moveToThread(mp_thread);
//    mp_thread->start();
}

Tcp::~Tcp()
{
    mp_thread->quit();
    mp_thread->wait();
}

void Tcp::started(){
    qDebug()<<"Thread TCP Server started";
}

void Tcp::listenTCP(const QString &ipAddress, const QString port){
    QHostAddress ipAddressHost(ipAddress);
    int portInt = port.toInt();
    Q_EMIT listen(ipAddressHost, portInt);
}

void Tcp::unlistenTCP(){
    Q_EMIT unlisten();
}

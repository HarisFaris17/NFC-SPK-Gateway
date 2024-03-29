#include "tcpserver2.h"

TcpServer2::TcpServer2()
{
    qDebug()<<"init thread tcpserver : "<<QThread::currentThread();
}

TcpServer2::~TcpServer2()
{
    close();
}

void TcpServer2::run(){
    qDebug()<<"current thread tcpserver : "<<QThread::currentThread();
    if(!isListening()){
        if (ipAddress == "*" || ipAddress.isEmpty()) listen(QHostAddress::Any, port);
        else listen(QHostAddress(ipAddress),port);

        if(isListening()){
            qDebug()<<tr("Listening on : %1:%2").arg(ipAddress).arg(port);
            qDebug()<<"listening thread this : "<<this->thread();
            qDebug()<<"listening thread tcpserver : "<<QThread::currentThread();
            Q_EMIT listenResult(true);
            connect(this,&QTcpServer::newConnection,this,&TcpServer2::onNewConnection);
        }else{
            qDebug()<<tr("Can't listen");
            // this will move the thread to main thread
            this->moveToThread(QApplication::instance()->thread());
            Q_EMIT listenResult(false);
            Q_EMIT unlistened();
        }
    }
    else{
        qDebug()<<"this TCPServer object already listening";
    }
}

void TcpServer2::onNewConnection(){
    qDebug()<<"new connection thread tcpserver : "<<QThread::currentThread();
    QTcpSocket *client = this->nextPendingConnection();
    connect(client,&QTcpSocket::readyRead,this,&TcpServer2::onReadyRead);
}

void TcpServer2::onReadyRead(){
    QTcpSocket *client = qobject_cast<QTcpSocket *>(sender());
    QByteArray message = client->readAll();
    while(client->waitForReadyRead(50)){
        message += client->readAll();
    }
    qDebug()<<"New Message : \n"<<message<<"\n";
    Q_EMIT sendData(message);
}

void TcpServer2::config(const QString &ipAddress, const QString &port){
    qDebug()<<"config thread tcpserver : "<<QThread::currentThread();
    this->ipAddress = ipAddress;
    this->port = port.toInt();
    qDebug()<<"IP Address config : "<<ipAddress;
    qDebug()<<"port config : "<<port;
}

void TcpServer2::unlisten(){
    qDebug()<<"unlisten called";
    close();
    qDebug()<<"unlisten called";
    // this will move the thread to main thread
//    this->moveToThread(QApplication::instance()->thread());
//    qDebug()<<"current tcpserver thread : "<<QThread::currentThread();
    Q_EMIT unlistened();
}

//bool TcpServer2::event(QEvent *e){
//    qDebug()<<"This called";
////    qDebug()<<*e->;
//    // this is not useful since the ThreadChanged will be passed to this object just before the thread of this object changed, therefore the currentThread will return the same thread as the main thread
//    if(e->type()==QEvent::ThreadChange){
//        qDebug()<<"just before TCPSERVER thread CHANGED : "<<QThread::currentThread();
//    }

////    else if (e->type()==QEvent::)

//}

void TcpServer2::test(){
    qDebug()<<"testtttttttt";
}

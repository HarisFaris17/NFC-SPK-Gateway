#include "tcpserver.h"

TCPServer::TCPServer()
{

    qDebug()<<"init thread tcpserver : "<<QThread::currentThread();
    mp_thread.reset(new QThread);
    connect(mp_thread.get(), &QThread::started, this, &TCPServer::run);
//    connect(obj, &MainWindow::listen, this, &TCPServer::listenTcp);
    qDebug()<<"This called";
    moveToThread(mp_thread.get());
    mp_thread->start();
//    connect(mp_thread.get(), &QThread::finished, this, &TCPServer::run);

//    connect(mainWindow, &MainWindow::listen, this, &TCPServer::listenTcp, Qt::QueuedConnection);

}

void TCPServer::run(){
    qDebug()<<"current thread tcpserver : "<<QThread::currentThread();
//    QString ipAddress = tr("192.168.3.233");
//    QString port = tr("2121");
//    listenTcp(ipAddress, port);
//    if(!isListening()){
//        listen(QHostAddress(ipAddress),port);
//        if(isListening()){
//            qDebug()<<tr("Listening on : %1:%2").arg(ipAddress).arg(port);
//            qDebug()<<"listening thread this : "<<this->thread();
//            qDebug()<<"listening thread tcpserver : "<<QThread::currentThread();
//            connect(this,&QTcpServer::newConnection,this,&TCPServer::onNewConnection);
//        }else{
//            qDebug()<<tr("Can't listen");
//            // this will move the thread to main thread
//            this->moveToThread(QApplication::instance()->thread());
//            Q_EMIT unlistened();
//        }
//    }
//    else{
//        qDebug()<<"this TCPServer object already listening";
//    }
}

void TCPServer::cleanup(){
    mp_thread->quit();
}

TCPServer::~TCPServer(){
    QMetaObject::invokeMethod(this, "cleanup");
    mp_thread->wait();
}

void TCPServer::listenTcp(const QString &ipAddress, const QString &port){
//    if ()

    qDebug()<<"This called";
    if(!isListening()){
        this->ipAddress = ipAddress;
        this->port = port.toInt();
        listen(QHostAddress(this->ipAddress),this->port);
        if(isListening()){
            qDebug()<<tr("Listening on : %1:%2").arg(ipAddress).arg(port);
            qDebug()<<"listening thread this : "<<this->thread();
            qDebug()<<"listening thread tcpserver : "<<QThread::currentThread();
            connect(this,&QTcpServer::newConnection,this,&TCPServer::onNewConnection);
            Q_EMIT listenResult(true);
        }else{
            qDebug()<<tr("Failed to listen on ")<<ipAddress<<":"<<port;
            // this will move the thread to main thread
//            this->moveToThread(QApplication::instance()->thread());
            Q_EMIT listenResult(false);
        }
    }
    else{
        qDebug()<<"this TCPServer object already listening";
    }
}

void TCPServer::onNewConnection(){
    qDebug()<<"new connection thread tcpserver : "<<QThread::currentThread();
    QTcpSocket *client = this->nextPendingConnection();
    connect(client,&QTcpSocket::readyRead,this,&TCPServer::onReadyRead);
}

void TCPServer::onReadyRead(){
    qDebug()<<"on ready read thread this : "<<this->thread();
    qDebug()<<"on ready read thread tcpserver : "<<QThread::currentThread();
    QTcpSocket *client = qobject_cast<QTcpSocket *>(sender());
    QString message = client->readAll();
    while(client->waitForReadyRead(50)){
        message += client->readAll();
    }
    qDebug()<<"New Message : \n"<<message<<"\n";
    QJsonDocument messageDocument = QJsonDocument::fromJson(message.toUtf8());
    qDebug()<<messageDocument;
    QJsonArray arrayDocument = messageDocument.array();
    qDebug()<<arrayDocument;
    QJsonObject objectIndex0 = arrayDocument[0].toObject();
    qDebug()<<objectIndex0;
}

//void TCPServer::config(const QString &ipAddress, const QString &port){
//    qDebug()<<"config thread tcpserver : "<<QThread::currentThread();
//    this->ipAddress = ipAddress;
//    this->port = port.toInt();
//    qDebug()<<"IP Address config : "<<ipAddress;
//    qDebug()<<"port config : "<<port;
//}

void TCPServer::unlisten(){
    close();
    qDebug()<<"unlisten called";
    // this will move the thread to main thread
    this->moveToThread(QApplication::instance()->thread());
    qDebug()<<"current tcpserver thread : "<<QThread::currentThread();
//    Q_EMIT unlistened();
}

bool TCPServer::event(QEvent *e){
//    qDebug()<<*e->;
    // this is not useful since the ThreadChanged will be passed to this object just before the thread of this object changed, therefore the currentThread will return the same thread as the main thread
    if(e->type()==QEvent::ThreadChange){
        qDebug()<<"just before TCPSERVER thread CHANGED : "<<QThread::currentThread();
    }

}

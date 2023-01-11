#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectPushButton = ui->connectPushButton;
    unlistenPushButton = ui->unlistenPushButton;
    ipAddressLineEdit = ui ->ipAddressLineEdit;
    portLineEdit = ui->portLineEdit;

    qDebug()<<"mainwindow thread : "<<QThread::currentThread();
    connect(connectPushButton,&QPushButton::clicked,this,&MainWindow::connectDisconnectTCP);
    connect(unlistenPushButton,&QPushButton::clicked,this,&MainWindow::unlisten);


}

void MainWindow::connectDisconnectTCP(){
    // it is important to notice when the object was moved to another thread. if there is connection between the object and a calling (signalling) object and the object moved before any Q_EMIT from the calling object , then the slot of the moved object will not be triggered unless the another thread has started
    thread1 = new QThread;
    TCPServer *tcpServer =  new TCPServer();
    connect(this,&MainWindow::config,tcpServer,&TCPServer::config);
    QString ipAddress = ipAddressLineEdit->text();
    QString port = portLineEdit->text();
    int portNumber = port.toInt();
    Q_EMIT config(ipAddress,port);

    qDebug()<<"before moved ptr"<<tcpServer;

    connect(thread1,&QThread::started,tcpServer,&TCPServer::run);
    connect(tcpServer,&TCPServer::unlistened,thread1,&QThread::quit);
    connect(this,&MainWindow::unlistenTCP,tcpServer,&TCPServer::unlisten);
    connect(thread1,&QThread::finished,thread1,&QThread::deleteLater);

    //from now on we can't use the method of tcpServer directly from this object, since the tcpServer is in another thread (thread1). we can communicate with tcpServer using signal/slot liek that of unlistenTCP from this and unlisten from tcpServer
    tcpServer->moveToThread(thread1);

    thread1->start();

}

void MainWindow::unlisten(){
    qDebug()<<"main window unlisten";
    Q_EMIT unlistenTCP();
}

MainWindow::~MainWindow()
{
    delete ui;
}

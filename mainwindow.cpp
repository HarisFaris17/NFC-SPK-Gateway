#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectPushButton = ui->connectPushButton;
//    unlistenPushButton = ui->unlistenPushButton;
    ipAddressLineEdit = ui ->ipAddressLineEdit;
    portLineEdit = ui->portLineEdit;
    console = ui->console;
    tableWidget = ui->tableWidget;

    timer = new QTimer();
    timer->setSingleShot(true);

    processor = new Processor;
    QThread *processorThread = new QThread;
    connect(processor, &Processor::sendData, this, &MainWindow::receiveDataConsole);
    connect(processor, &Processor::sendDataTable, this, &MainWindow::receiveDataTable);
    connect(this, &MainWindow::destroyed, processorThread, &QThread::quit);
    connect(processorThread, &QThread::started, processor, &Processor::started);
    connect(processorThread, &QThread::finished, processor, &Processor::deleteLater);
    connect(processorThread, &QThread::finished, processorThread, &Processor::deleteLater);

    processor->moveToThread(processorThread);
    processorThread->start(QThread::HighPriority);

    qDebug()<<"mainwindow thread : "<<QThread::currentThread();
    connect(connectPushButton,&QPushButton::clicked,this,&MainWindow::connectDisconnectTCP);
//    connect(unlistenPushButton,&QPushButton::clicked,this,&MainWindow::unlisten);

    connect(timer, &QTimer::timeout, this, &MainWindow::timerTimeout);

    protoTableWidgetItem = new QTableWidgetItem();
    protoTableWidgetItem->setFlags(protoTableWidgetItem->flags() & ~Qt::ItemIsEditable);
    protoTableWidgetItem->setTextAlignment(Qt::AlignCenter);
}

void MainWindow::connectDisconnectTCP(){
    // it is important to notice when the object was moved to another thread. if there is connection between the object and a calling (signalling) object and the object moved before any Q_EMIT from the calling object , then the slot of the moved object will not be triggered unless the another thread has started
//    thread1 = new QThread;
//    if (tcpServer != NULL) {
//        qDebug()<<"TCP Server is running";
//        return;
//    }
//    TCPServer *tcpServer =  new TCPServer();
//    connect(this,&MainWindow::config,tcpServer,&TCPServer::config);

//    Q_EMIT config(ipAddress,port);

//    connect(this, &MainWindow::listen, tcpServer, &TCPServer::listenTcp);
//    connect(tcpServer, &TCPServer::listenResult, this, &MainWindow::listenResult);
//    tcpServer.listenTcp(ipAddress, port);

//    Q_EMIT listen(ipAddress, port);
//    tcpServer.listenTcp(ipAddress, port);
//    qDebug()<<"Should be listening";
//    qDebug()<<"before moved ptr"<<tcpServer;

//    connect(thread1,&QThread::started,tcpServer,&TCPServer::run);
//    connect(tcpServer,&TCPServer::unlistened,thread1,&QThread::quit);
//    connect(this,&MainWindow::unlistenTCP,tcpServer,&TCPServer::unlisten);
//    connect(thread1,&QThread::finished,thread1,&QThread::deleteLater);

    //from now on we can't use the method of tcpServer directly from this object, since the tcpServer is in another thread (thread1). we can communicate with tcpServer using signal/slot liek that of unlistenTCP from this and unlisten from tcpServer
//    tcpServer->moveToThread(thread1);

//    thread1->start();
    if (stateTcp == WAITING) {
        qDebug()<<"The TCP is currently waiting to wake up";
        return;
    }

    else if (stateTcp == LISTENING) {
        qDebug()<<"Disconnecting TCP";
        Q_EMIT unlistenTCP();
        stateTcp = STOP;
        changeDisplayStateTCP();
    }

    else if (stateTcp == STOP) {
        qDebug()<<"Trying to listen";

        QString ipAddress = ipAddressLineEdit->text();
        QString port = portLineEdit->text();
        int portNumber = port.toInt();

        TcpServer2 *tcpServer =  new TcpServer2();
        QThread *tcpServerThread = new QThread;

        tcpServer->config(ipAddress, port);

        connect(this, &MainWindow::unlistenTCP, tcpServer, &TcpServer2::unlisten);
        connect(this, &MainWindow::destroyed, tcpServerThread, &QThread::quit);

        connect(tcpServerThread, &QThread::started, tcpServer, &TcpServer2::run);
        connect(tcpServerThread, &QThread::finished, tcpServer, &TcpServer2::deleteLater);
        connect(tcpServerThread, &QThread::finished, tcpServerThread, &QThread::deleteLater);
        connect(tcpServer, &TcpServer2::unlistened, tcpServerThread, &QThread::quit);
        connect(tcpServer, &TcpServer2::unlistened, this, &MainWindow::unlistenedTcp);
        connect(tcpServer, &TcpServer2::listenResult, this, &MainWindow::listenResult);
        connect(tcpServer, &TcpServer2::sendData, processor, &Processor::receiveTcpData);
        connect(this, &MainWindow::test, tcpServer, &TcpServer2::test);

        tcpServer->moveToThread(tcpServerThread);
        tcpServerThread->start();

    //    connect(timer, &QTimer::timeout, )

        timer->start(10000);
        stateTcp = WAITING;
        changeDisplayStateTCP();
        Q_EMIT test();
//        tcpServer->unlisten();
    }
}

void MainWindow::listenResult(bool isSuccess){
    qDebug()<< "Listening result " << isSuccess;
    if (isSuccess) stateTcp = LISTENING;
    else stateTcp = STOP;
    changeDisplayStateTCP();
    timer->stop();
//    if (!isSuccess) delete tcpServer;
}

void MainWindow::unlistenedTcp(){
    // this conditional is not required, but just to prevent if there are some code that will break the flows of display TCP
    qDebug()<<"this is called";
    if (stateTcp == LISTENING){
        stateTcp = STOP;
        changeDisplayStateTCP();
    }
}

//void MainWindow::receiveData(QJsonObject data){
////    console->append(data);
//    qDebug()<<data;
//    QString rawData = "rawData";
//    console->append(data.value(rawData).toString());
//}

//void MainWindow::unlisten(){
//    qDebug()<<"main window unlisten";
//    Q_EMIT unlistenTCP();
//}

void MainWindow::timerTimeout(){
    if (stateTcp == WAITING) {
        qDebug()<<"TCP Server failed to start";
        stateTcp = STOP;
        changeDisplayStateTCP();
    }
}

void MainWindow::receiveDataConsole(QByteArray data){
    qDebug()<<data;

    QByteArray slicedData;
    for (int i = 7; i < data.length(); i++){
        slicedData += data[i];
    }
    qDebug()<<QString::fromUtf8(slicedData);
    console->append(QString::fromUtf8(slicedData));
}

void MainWindow::receiveDataTable(QString deviceId, QString tagId, QString spk, QString counter, QString dateTime){
    qDebug()<<__func__;
    qDebug()<<deviceId<<tagId<<spk<<counter,dateTime;
    QTableWidgetItem *deviceIdItem = protoTableWidgetItem->clone();
    QTableWidgetItem *tagIdItem = protoTableWidgetItem->clone();
    QTableWidgetItem *spkItem = protoTableWidgetItem->clone();
    QTableWidgetItem *counterItem = protoTableWidgetItem->clone();
    QTableWidgetItem *dateTimeItem = protoTableWidgetItem->clone();

    deviceIdItem->setText(deviceId);
    tagIdItem->setText(tagId);
    spkItem->setText(spk);
    counterItem->setText(counter);
    dateTimeItem->setText(dateTime);

    tableWidget->setItem(0, DEVICE_ID, deviceIdItem);
    tableWidget->setItem(0, TAG_ID, tagIdItem);
    tableWidget->setItem(0, SPK, spkItem);
    tableWidget->setItem(0, COUNTER, counterItem);
    tableWidget->setItem(0, LAST_UPDATE, dateTimeItem);
}

void MainWindow::changeDisplayStateTCP(){
    if (stateTcp == WAITING){
        connectPushButton->setEnabled(false);
        ipAddressLineEdit->setEnabled(false);
        portLineEdit->setEnabled(false);
    }
    else if (stateTcp == LISTENING){
        connectPushButton->setEnabled(true);
        connectPushButton->setText("Stop");
        ipAddressLineEdit->setEnabled(false);
        portLineEdit->setEnabled(false);
    }
    else if (stateTcp == STOP){
        connectPushButton->setEnabled(true);
        connectPushButton->setText("Connect");
        ipAddressLineEdit->setEnabled(true);
        portLineEdit->setEnabled(true);
    }
}

MainWindow::~MainWindow()
{
//    delete tcpServer;
    timer->stop();
    delete timer;
    delete processor;
    delete ui;
}

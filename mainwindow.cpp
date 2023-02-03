#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    settingLocatorUi(new SettingLocator)
{
    ui->setupUi(this);

    connectTCPPushButton = ui->connectTCPPushButton;
    connectDatabasePushButton = ui->connectDatabasePushButton;
//    unlistenPushButton = ui->unlistenPushButton;
    ipAddressTCPLineEdit = ui ->ipAddressTCPLineEdit;
    portTCPLineEdit = ui->portTCPLineEdit;
    hostDatabaseLineEdit = ui->hostDatabaseLineEdit;
    portDatabaseLineEdit = ui->portDatabaseLineEdit;
    databaseNameDatabaseLineEdit = ui->databaseNameDatabaseLineEdit;
    usernameDatabaseLineEdit = ui->usernameDatabaseLineEdit;
    passwordDatabaseLineEdit = ui->passwordDatabaseLineEdit;
    console = ui->console;
    tableWidgetCounting = ui->tableWidgetCounting;
//    tableWidgetLocation = ui->tableWidgetLocation;

    QList<QString> deviceIds;
    deviceIds << tr("DCC7CD766E3A") << tr("E985AED59234");
    Common::replaceDeviceIds(deviceIds);

    processor = new Processor;
    QThread *processorThread = new QThread;
    connect(processor, &Processor::sendData, this, &MainWindow::receiveDataConsole);
    connect(processor, &Processor::sendDataTable, this, &MainWindow::receiveDataTable);
    connect(processor, &Processor::sendLocation, this, &MainWindow::receiveLocation);
    connect(this, &MainWindow::destroyed, processorThread, &QThread::quit);
    connect(processorThread, &QThread::started, processor, &Processor::started);
    connect(processorThread, &QThread::finished, processor, &Processor::deleteLater);
    connect(processorThread, &QThread::finished, processorThread, &Processor::deleteLater);

    processor->moveToThread(processorThread);
    processorThread->start(QThread::HighPriority);

    qDebug()<<"mainwindow thread : "<<QThread::currentThread();
    connect(connectTCPPushButton,&QPushButton::clicked,this,&MainWindow::connectDisconnectTCP);

    connect(connectDatabasePushButton, &QPushButton::clicked, this, &MainWindow::connectDisconnectDatabase);
//    connect(unlistenPushButton,&QPushButton::clicked,this,&MainWindow::unlisten);

    protoTableWidgetItem = new QTableWidgetItem();
    protoTableWidgetItem->setFlags(protoTableWidgetItem->flags() & ~Qt::ItemIsEditable);
    protoTableWidgetItem->setTextAlignment(Qt::AlignCenter);

    QString ipAddress;
    QString TCPPort;
    QString host;
    QString databasePort;
    QString databaseName;
    QString username;
    QString password;

    File file;
    file.parseFile(ipAddress, TCPPort, host, databasePort, databaseName, username, password);
    qDebug()<<ipAddress<< TCPPort<< host<< databasePort<< databaseName<< username<< password;

    ipAddressTCPLineEdit->setText(ipAddress);
    portTCPLineEdit->setText(TCPPort);
    hostDatabaseLineEdit->setText(host);
    portDatabaseLineEdit->setText(databasePort);
    databaseNameDatabaseLineEdit->setText(databaseName);
    usernameDatabaseLineEdit->setText(username);
    passwordDatabaseLineEdit->setText(password);

    settingLocatorUi->show();

    connectDisconnectTCP();
    connectDisconnectDatabase();
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
    if (stateTcp == WaitingTCP) {
        qDebug()<<"The TCP is currently waiting to wake up";
        return;
    }

    else if (stateTcp == TCPListening) {
        qDebug()<<"Disconnecting TCP";
        Q_EMIT unlistenTCP();
        stateTcp = TCPStop;
        changeDisplayStateTCP();
    }

    else if (stateTcp == TCPStop) {
        qDebug()<<"Trying to listen";

        QString ipAddress = ipAddressTCPLineEdit->text();
        QString port = portTCPLineEdit->text();
        int portNumber = port.toInt();

        File file;
        file.saveTCPServerConfig(ipAddress, port);

        TcpServer2 *tcpServer =  new TcpServer2();
        QThread *tcpServerThread = new QThread;

        tcpServer->config(ipAddress, port);

        connect(this, &MainWindow::unlistenTCP, tcpServer, &TcpServer2::unlisten);
        connect(this, &MainWindow::destroyed, tcpServerThread, &QThread::quit);

        connect(tcpServerThread, &QThread::started, tcpServer, &TcpServer2::run);
        connect(tcpServerThread, &QThread::finished, tcpServer, &TcpServer2::deleteLater);
        connect(tcpServerThread, &QThread::finished, tcpServer, &TcpServer2::close);
        connect(tcpServerThread, &QThread::finished, tcpServerThread, &QThread::deleteLater);
        connect(tcpServer, &TcpServer2::unlistened, tcpServerThread, &QThread::quit);
        connect(tcpServer, &TcpServer2::unlistened, this, &MainWindow::unlistenedTcp);
        connect(tcpServer, &TcpServer2::listenResult, this, &MainWindow::listenResult);
        connect(tcpServer, &TcpServer2::sendData, processor, &Processor::receiveTcpData);
        connect(this, &MainWindow::test, tcpServer, &TcpServer2::test);

        QTimer *timerTcp = new QTimer(this);

        connect(timerTcp, &QTimer::timeout, this, &MainWindow::timerTcpTimeout);
        connect(this, &MainWindow::deleteTimerTCP, timerTcp, &QTimer::deleteLater);

        timerTcp->setSingleShot(true);
        timerTcp->start(10000);

        tcpServer->moveToThread(tcpServerThread);
        tcpServerThread->start();

        stateTcp = WaitingTCP;
        changeDisplayStateTCP();
        Q_EMIT test();
//        tcpServer->unlisten();
    }
}

void MainWindow::listenResult(bool isSuccess){
    qDebug()<< "Listening result " << isSuccess;
    if (isSuccess) stateTcp = TCPListening;
    else stateTcp = TCPStop;
    changeDisplayStateTCP();

    Q_EMIT deleteTimerTCP();
}

void MainWindow::unlistenedTcp(){
    // this conditional is not required, but just to prevent if there are some code that will break the flows of display TCP
    qDebug()<<"this is called";
    if (stateTcp == TCPListening){
        stateTcp = TCPStop;
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

void MainWindow::timerTcpTimeout(){
    if (stateTcp == WaitingTCP) {
        qDebug()<<"TCP Server failed to start";
        stateTcp = TCPStop;
        changeDisplayStateTCP();
    }

    Q_EMIT deleteTimerTCP();
}

void MainWindow::timerDatabaseTimeout(){
    if (stateDatabase == WaitingDatabase){
        qDebug()<<"Failed to get connection to database";
        stateDatabase = DatabaseDisconnected;
        changeDisplayDatabase();
    }

    Q_EMIT deleteTimerDatabase();
}

void MainWindow::receiveDataConsole(QString data){
    qDebug()<<data;

//    qDebug()<<QString::fromUtf8(data);
//    console->append(QString::fromUtf8(data));
    console->append(data);
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

    if (tagId != "") tagIdItem->setText(tagId);
    else tagIdItem->setText("---");

    spkItem->setText(spk);
    counterItem->setText(counter);
    dateTimeItem->setText(dateTime);

    if (deviceId == "DCC7CD766E3A"){
        tableWidgetCounting->setItem(0, DEVICE_ID, deviceIdItem);
        tableWidgetCounting->setItem(0, TAG_ID, tagIdItem);
        tableWidgetCounting->setItem(0, SPK, spkItem);
        tableWidgetCounting->setItem(0, COUNTER, counterItem);
        tableWidgetCounting->setItem(0, LAST_UPDATE, dateTimeItem);
    }
    else if (deviceId == "E985AED59234"){
        tableWidgetCounting->setItem(1, DEVICE_ID, deviceIdItem);
        tableWidgetCounting->setItem(1, TAG_ID, tagIdItem);
        tableWidgetCounting->setItem(1, SPK, spkItem);
        tableWidgetCounting->setItem(1, COUNTER, counterItem);
        tableWidgetCounting->setItem(1, LAST_UPDATE, dateTimeItem);
    }
}

void MainWindow::receiveLocation(QString deviceId, int locator, double x, double y, double z){
//    qDebug()<<"\n\n\nLocation received\n\n\n"<<locator<<deviceId<<x<<y<<z;
    int rowNumberDeviceId = Common::indexDeviceId(deviceId);
    qDebug()<<"\n\n\nLocation received\n\n\n"<<locator<<deviceId<<rowNumberDeviceId<<x<<y<<z;
    if (rowNumberDeviceId == -1 ) return;

    QTableWidgetItem *ar_x = protoTableWidgetItem->clone();
    QTableWidgetItem *ar_y = protoTableWidgetItem->clone();
    QTableWidgetItem *ar_z = protoTableWidgetItem->clone();

    ar_x->setText(QString::number(x, 'f', 8));
    ar_y->setText(QString::number(y, 'f', 8));
    ar_z->setText(QString::number(z, 'f', 8));

    tableWidgetCounting->setItem(rowNumberDeviceId, AR_HEADER_OFFSET(locator) + 0, ar_x);
    tableWidgetCounting->setItem(rowNumberDeviceId, AR_HEADER_OFFSET(locator) + 1, ar_y);
    tableWidgetCounting->setItem(rowNumberDeviceId, AR_HEADER_OFFSET(locator) + 2, ar_z);
}

void MainWindow::connectDisconnectDatabase(){

    qDebug()<<"connect disconnect database";

    if (stateDatabase == DatabaseDisconnected){
        qDebug()<<"Connecting database...";

        QString hostDatabase = hostDatabaseLineEdit->text();
        QString port = portDatabaseLineEdit->text();
        QString databaseName = databaseNameDatabaseLineEdit->text();
        QString username = usernameDatabaseLineEdit->text();
        QString password = passwordDatabaseLineEdit->text();

        File file;
        file.saveDatabaseConfig(hostDatabase, port, databaseName, username, password);

        database = new Database;
        QThread *databaseThread = new QThread;

        database->config(hostDatabase, port, databaseName, username, password);

        connect(this, &MainWindow::destroyed, databaseThread, &QThread::quit);
        connect(this, &MainWindow::disconnectDatabase, database, &Database::disconnectDatabase);
        connect(database, &Database::databaseDisconnected, this, &MainWindow::databaseDisconnected);
        connect(database, &Database::databaseDisconnected, databaseThread, &QThread::quit);
        connect(database, &Database::databaseConnectionResult, this, &MainWindow::databaseConnectionResult);
        connect(database, &Database::tableCreateResult, this, &MainWindow::tableCreateResult);
        connect(databaseThread, &QThread::started, database, &Database::run);
        connect(databaseThread, &QThread::finished, database, &Database::deleteLater);
        connect(databaseThread, &QThread::finished, databaseThread, &QThread::deleteLater);

        QTimer *timerDatabase = new QTimer(this);
        connect(timerDatabase, &QTimer::timeout, this, &MainWindow::timerDatabaseTimeout);
        connect(this, &MainWindow::deleteTimerDatabase, timerDatabase, &QTimer::deleteLater);

        timerDatabase->setSingleShot(true);
        timerDatabase->start(10000);

        database->moveToThread(databaseThread);
        databaseThread->start(QThread::HighPriority);

        stateDatabase = WaitingDatabase;

    }
    else if (stateDatabase == WaitingDatabase){
        qDebug()<<"Waiting connection ";
    }
    else if (stateDatabase == DatabaseConnected)
    {
        qDebug()<<"Disconnecting database...";
        Q_EMIT disconnectDatabase();
        stateDatabase = DatabaseDisconnected;
        changeDisplayDatabase();
    }
}

void MainWindow::databaseConnectionResult(bool isSuccess){
    qDebug()<<"Database connection result";
    if (isSuccess) stateDatabase = DatabaseConnected;
    else stateDatabase = DatabaseDisconnected;
    changeDisplayDatabase();

    Q_EMIT deleteTimerDatabase();
}

void MainWindow::databaseDisconnected(){
    if (stateDatabase == DatabaseConnected) {
        stateDatabase = DatabaseDisconnected;
        qDebug()<<"Database disconnected";
    }
}

void MainWindow::tableCreateResult(bool isDeviceTableCreated,
                                   bool isDataTableCreated,
                                   bool isDevicelocationTableCreated,
                                   bool isDataLocationTableCreated){
    qDebug()<<"Device table created : " << isDeviceTableCreated;
    qDebug()<<"Data table created : " << isDataTableCreated;
    qDebug()<<"Device location table created : " << isDevicelocationTableCreated;
    qDebug()<<"Data location table created : " << isDataLocationTableCreated;
}

void MainWindow::changeDisplayStateTCP(){
    if (stateTcp == WaitingTCP){
        connectTCPPushButton->setEnabled(false);
        ipAddressTCPLineEdit->setEnabled(false);
        portTCPLineEdit->setEnabled(false);
    }
    else if (stateTcp == TCPListening){
        connectTCPPushButton->setEnabled(true);
        connectTCPPushButton->setText("Stop");
        ipAddressTCPLineEdit->setEnabled(false);
        portTCPLineEdit->setEnabled(false);
    }
    else if (stateTcp == TCPStop){
        connectTCPPushButton->setEnabled(true);
        connectTCPPushButton->setText("Connect");
        ipAddressTCPLineEdit->setEnabled(true);
        portTCPLineEdit->setEnabled(true);
    }
}

void MainWindow::changeDisplayDatabase(){
    if (stateDatabase == DatabaseConnected){
        connectDatabasePushButton->setText("Disconnect");
        connectDatabasePushButton->setEnabled(true);
        hostDatabaseLineEdit->setEnabled(false);
        portDatabaseLineEdit->setEnabled(false);
        databaseNameDatabaseLineEdit->setEnabled(false);
        usernameDatabaseLineEdit->setEnabled(false);
        passwordDatabaseLineEdit->setEnabled(false);
    }
    else if (stateDatabase == WaitingDatabase){
        connectDatabasePushButton->setEnabled(false);
        hostDatabaseLineEdit->setEnabled(false);
        portDatabaseLineEdit->setEnabled(false);
        databaseNameDatabaseLineEdit->setEnabled(false);
        usernameDatabaseLineEdit->setEnabled(false);
        passwordDatabaseLineEdit->setEnabled(false);
    }
    else if (stateDatabase == DatabaseDisconnected){
        connectDatabasePushButton->setText("Connect");
        connectDatabasePushButton->setEnabled(true);
        hostDatabaseLineEdit->setEnabled(true);
        portDatabaseLineEdit->setEnabled(true);
        databaseNameDatabaseLineEdit->setEnabled(true);
        usernameDatabaseLineEdit->setEnabled(true);
        passwordDatabaseLineEdit->setEnabled(true);
    }
}

void MainWindow::closeEvent(QCloseEvent *closeEvent){
    settingLocatorUi->close();
    closeEvent->accept();
}

MainWindow::~MainWindow()
{
//    delete tcpServer;
//    timer->stop();
//    delete timer;
    delete processor;
    delete database;
    delete ui;
}

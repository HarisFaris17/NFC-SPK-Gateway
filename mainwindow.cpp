#include "mainwindow.h"
#include "ui_mainwindow.h"

#define IGNORE                                      "IGNORE"
#define MAX_HISTORY_TALBE_ROWS                      20

#define DASH_IF_TAG_EMPTY(tagId)                    (tagId.isEmpty() ? "---" : tagId)

#define CUMULATIVE_IDX                              //(empty)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug()<<"adsfasdfasdf";
    ui->setupUi(this);

    connectTCPPushButton = ui->connectTCPPushButton;
    connectDatabasePushButton = ui->connectDatabasePushButton;
    addDevicePushButton = ui->addDevicePushButton;
    settingPushButton = ui->settingPushButton;
    coordinatesPushButton = ui->coordinatesPushButton;

    ipAddressTCPLineEdit = ui ->ipAddressTCPLineEdit;
    portTCPLineEdit = ui->portTCPLineEdit;
    hostDatabaseLineEdit = ui->hostDatabaseLineEdit;
    portDatabaseLineEdit = ui->portDatabaseLineEdit;
    databaseNameDatabaseLineEdit = ui->databaseNameDatabaseLineEdit;
    usernameDatabaseLineEdit = ui->usernameDatabaseLineEdit;
    passwordDatabaseLineEdit = ui->passwordDatabaseLineEdit;

    console = ui->console;
    tableWidgetCounting = ui->tableWidgetCounting;
    tableWidgetHistoryCounting = ui->tableWidgetHistoryCounting;
//    tableWidgetLocation = ui->tableWidgetLocation;

    connect(addDevicePushButton, &QPushButton::clicked, this, &MainWindow::showAddDevice);
    connect(settingPushButton, &QPushButton::clicked, this, &MainWindow::showSettingLocator);
    connect(coordinatesPushButton, &QPushButton::clicked, this, &MainWindow::showCoordinates);

    processor = new Processor;
    QThread *processorThread = new QThread;
    connect(processor, &Processor::sendData, this, &MainWindow::receiveDataConsole);
    connect(processor, &Processor::sendDataTable, this, &MainWindow::receiveDataTableCounting);
    connect(processor, &Processor::sendLocation, this, &MainWindow::receiveLocation);
    connect(processor, &Processor::sendCumulativeLocation, this, &MainWindow::receiveCumulativeLocation);
    connect(processor, &Processor::sendHistory, this, &MainWindow::receiveHistory);
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

        QTimer *timerTcp = new QTimer(this);

        connect(timerTcp, &QTimer::timeout, this, &MainWindow::timerTcpTimeout);
        connect(this, &MainWindow::deleteTimerTCP, timerTcp, &QTimer::deleteLater);

        timerTcp->setSingleShot(true);
        timerTcp->start(10000);

        tcpServer->moveToThread(tcpServerThread);
        tcpServerThread->start();

        stateTcp = WaitingTCP;
        changeDisplayStateTCP();
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

void MainWindow::receiveDataTableCounting(QString deviceId, QString tagId, QString spk, QString counter, QString dateTime){
    qDebug()<<__func__;
    qDebug() << deviceId << tagId << spk << counter << dateTime;
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

    int row = deviceIds.indexOf(deviceId);
//    if (deviceId == "DCC7CD766E3A"){
    tableWidgetCounting->setItem(row, DEVICE_ID, deviceIdItem);
    tableWidgetCounting->setItem(row, TAG_ID, tagIdItem);
    tableWidgetCounting->setItem(row, SPK, spkItem);
    tableWidgetCounting->setItem(row, COUNTER, counterItem);
    tableWidgetCounting->setItem(row, LAST_UPDATE, dateTimeItem);
    qDebug() << row << deviceId << tagId << spk << counter << deviceIds <<__func__;
//    }
//    else if (deviceId == "E985AED59234"){
//        tableWidgetCounting->setItem(1, DEVICE_ID, deviceIdItem);
//        tableWidgetCounting->setItem(1, TAG_ID, tagIdItem);
//        tableWidgetCounting->setItem(1, SPK, spkItem);
//        tableWidgetCounting->setItem(1, COUNTER, counterItem);
//        tableWidgetCounting->setItem(1, LAST_UPDATE, dateTimeItem);
//    }
}

void MainWindow::receiveLocation(QString deviceId, int locator, double x, double y, double z){
//    qDebug()<<"\n\n\nLocation received\n\n\n"<<locator<<deviceId<<x<<y<<z;
    int rowNumberDeviceId = deviceIds.indexOf(deviceId);
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

void MainWindow::receiveCumulativeLocation(QString deviceId,
                                           double x, double y, double z
                                      /*     double x0, double y0, double z0,
                                           double x1, double y1, double z1,
                                           double x2, double y2, double z2,
                                           double x3, double y3, double z3*/){
    int rowNumberDeviceId = Common::indexDeviceId(deviceId);
    qDebug()<<"\n\n\nLocation Cumulative received\n\n\n" << deviceId << rowNumberDeviceId << x << y << z;
    if (rowNumberDeviceId == -1 ) return;

    QTableWidgetItem *x_item = protoTableWidgetItem->clone();
    QTableWidgetItem *y_item = protoTableWidgetItem->clone();
    QTableWidgetItem *z_item = protoTableWidgetItem->clone();

    x_item->setText(QString::number(x, 'f', 8));
    y_item->setText(QString::number(y, 'f', 8));
    z_item->setText(QString::number(z, 'f', 8));

    tableWidgetCounting->setItem(rowNumberDeviceId, X + 0, x_item);
    tableWidgetCounting->setItem(rowNumberDeviceId, Y + 1, y_item);
    tableWidgetCounting->setItem(rowNumberDeviceId, Z + 2, z_item);

}

void MainWindow::receiveLastStateDevice(QStringList deviceIds,
                                        QStringList tagId,
                                        QStringList spk,
                                        QStringList counter,
                                        QStringList x, QStringList y, QStringList z,
                                        QStringList locator1X, QStringList locator1Y, QStringList locator1Z,
                                        QStringList locator2X, QStringList locator2Y, QStringList locator2Z,
                                        QStringList locator3X, QStringList locator3Y, QStringList locator3Z,
                                        QStringList locator4X, QStringList locator4Y, QStringList locator4Z,
                                        QStringList lastUpdate){
//    qDebug() << __func__ << deviceIds << tagId << spk << counter << x << y << z;
//    QStringList deviceId =
//    qDebug() << Common::getDeviceIds();
    this->deviceIds.clear();
    this->deviceIds.append(deviceIds);

    int itemCount = deviceIds.size();
    for (int row = 0; row < itemCount; row++){
        this->deviceIds[row] = deviceIds[row];
        if (row >= tableWidgetCounting->rowCount()){
            tableWidgetCounting->insertRow(row);
        }

        // if all the coordinates has string 0, it is indicating that the coordinates hasn't saved yet before, hence the coordinates should be undefined
        if (x[row] == "0" && y[row] == "0" && z[row] == "0"){
            x[row] = "";
            y[row] = "";
            z[row] = "";
        }

        changeRowItem(row,
                      deviceIds[row],
                      tagId[row],
                      spk[row],
                      counter[row],
                      x[row], y[row], z[row],
                      locator1X[row], locator1Y[row], locator1Z[row],
                      locator2X[row], locator2Y[row], locator2Z[row],
                      locator3X[row], locator3Y[row], locator3Z[row],
                      locator4X[row], locator4Y[row], locator4Z[row],
                      lastUpdate[row]);
    }
}

void MainWindow::receiveHistory(const QString &deviceId,
                    const QString &tagId,
                    const QString &spk,
                    const QString &counter,
                    const QString &x, const QString &y, const QString &z,
                    const QString &x0, const QString &y0, const QString &z0,
                    const QString &x1, const QString &y1, const QString &z1,
                    const QString &x2, const QString &y2, const QString &z2,
                    const QString &x3, const QString &y3, const QString &z3,
                    const QString &dateTime){
    tableWidgetHistoryCounting->insertRow(0);
    QTableWidgetItem *deviceIdItem = protoTableWidgetItem->clone();
    QTableWidgetItem *tagIdItem = protoTableWidgetItem->clone();
    QTableWidgetItem *spkItem = protoTableWidgetItem->clone();
    QTableWidgetItem *counterItem = protoTableWidgetItem->clone();
    QTableWidgetItem *xItem = protoTableWidgetItem->clone();
    QTableWidgetItem *yItem = protoTableWidgetItem->clone();
    QTableWidgetItem *zItem = protoTableWidgetItem->clone();
    QTableWidgetItem *timestampItem = protoTableWidgetItem->clone();

#define DEFINE_TABLE_WIDGET_ITEM_COORD(idx)     QTableWidgetItem *x##idx##Item = protoTableWidgetItem->clone(); \
                                                QTableWidgetItem *y##idx##Item = protoTableWidgetItem->clone();   \
                                                QTableWidgetItem *z##idx##Item = protoTableWidgetItem->clone();

//    DEFINE_TABLE_WIDGET_ITEM_COORD(CUMULATIVE_IDX)
    DEFINE_TABLE_WIDGET_ITEM_COORD(0)
    DEFINE_TABLE_WIDGET_ITEM_COORD(1)
    DEFINE_TABLE_WIDGET_ITEM_COORD(2)
    DEFINE_TABLE_WIDGET_ITEM_COORD(3)

#define DEFINE_TABLE_WIDGET_ITEM_SET_TEXT(idx)  x##idx##Item->setText(x##idx); \
                                                y##idx##Item->setText(y##idx); \
                                                z##idx##Item->setText(z##idx);

//    DEFINE_TABLE_WIDGET_ITEM_SET_TEXT(CUMULATIVE_IDX)
    DEFINE_TABLE_WIDGET_ITEM_SET_TEXT(0)
    DEFINE_TABLE_WIDGET_ITEM_SET_TEXT(1)
    DEFINE_TABLE_WIDGET_ITEM_SET_TEXT(2)
    DEFINE_TABLE_WIDGET_ITEM_SET_TEXT(3)

#define  DEFINE_TABLE_WIDGET_ITEM_SET_ITEM(idx)     tableWidgetHistoryCounting->setItem(0, X## idx ##_HISTORY, x## idx ##Item); \
                                                    tableWidgetHistoryCounting->setItem(0, Y## idx ##_HISTORY, y## idx ##Item); \
                                                    tableWidgetHistoryCounting->setItem(0, Z## idx ##_HISTORY, z## idx ##Item);


    deviceIdItem->setText(deviceId);
    tagIdItem->setText(DASH_IF_TAG_EMPTY(tagId));
    spkItem->setText(spk);
    counterItem->setText(counter);
    xItem->setText(x);
    yItem->setText(y);
    zItem->setText(z);
    timestampItem->setText(dateTime);

    tableWidgetHistoryCounting->setItem(0, DEVICE_ID_HISTORY, deviceIdItem);
    tableWidgetHistoryCounting->setItem(0, TAG_ID_HISTORY, tagIdItem);
    tableWidgetHistoryCounting->setItem(0, SPK_HISTORY, spkItem);
    tableWidgetHistoryCounting->setItem(0, COUNTER_HISTORY, counterItem);
    tableWidgetHistoryCounting->setItem(0, X_HISTORY, xItem);
    tableWidgetHistoryCounting->setItem(0, Y_HISTORY, yItem);
    tableWidgetHistoryCounting->setItem(0, Z_HISTORY, zItem);
    tableWidgetHistoryCounting->setItem(0, TIMESTAMP__HISTORY, timestampItem);

    DEFINE_TABLE_WIDGET_ITEM_SET_ITEM(0)
    DEFINE_TABLE_WIDGET_ITEM_SET_ITEM(1)
    DEFINE_TABLE_WIDGET_ITEM_SET_ITEM(2)
    DEFINE_TABLE_WIDGET_ITEM_SET_ITEM(3)

    if (tableWidgetHistoryCounting->rowCount() > MAX_HISTORY_TALBE_ROWS) tableWidgetHistoryCounting->removeRow(tableWidgetHistoryCounting->rowCount() - 1);

}

void MainWindow::addDeviceId(const QString &mac){
    tableWidgetCounting->insertRow(tableWidgetCounting->rowCount());
    QTableWidgetItem *macItem = protoTableWidgetItem->clone();

    macItem->setText(mac);
    tableWidgetCounting->setItem(tableWidgetCounting->rowCount() - 1, DEVICE_ID, macItem);
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
        connect(database, &Database::sendLastStateDevice, this, &MainWindow::receiveLastStateDevice);
//        connect(database, &Database::sendDeviceIds, &Common::replaceDeviceIds);
        connect(database, &Database::sendLastStateDevice2, processor, &Processor::receiveLastStateDevice);
//        connect(database, &Database::newDeviceAdded, &Common::addDeviceId);
        connect(database, &Database::newDeviceAdded, this, &MainWindow::addDeviceId);
        connect(database, &Database::newDeviceAdded, processor, &Processor::addDeviceId);
        connect(databaseThread, &QThread::started, database, &Database::run);
        connect(databaseThread, &QThread::finished, database, &Database::deleteLater);
        connect(databaseThread, &QThread::finished, databaseThread, &QThread::deleteLater);

        if (addDeviceUi) connect(addDeviceUi, &AddDevice::sendDeviceID, database, &Database::addDevice);

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
    if (isSuccess) {
        stateDatabase = DatabaseConnected;
        
    }
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

void MainWindow::showSettingLocator(){
    if (settingLocatorUi){
        qDebug() << "The Setting Locator UI is currently present";
        return;
    }

    settingLocatorUi = new SettingLocator;

    connect(settingLocatorUi, &SettingLocator::sendRSSI, processor, &Processor::receiveRSSIConfig);
    connect(settingLocatorUi, &SettingLocator::sendLocatorParams, processor, &Processor::receiveLocatorParams);
    connect(settingLocatorUi, &SettingLocator::destroyed, this, &MainWindow::resetSettingLocator);

    settingLocatorUi->show();
}

void MainWindow::showAddDevice(){
    if (addDeviceUi){
        qDebug() << "The Add Device UI is currently present";
        return;
    }

    addDeviceUi = new AddDevice();

    connect(addDeviceUi, &AddDevice::destroyed, this, &MainWindow::resetAddDevice);

    if (database) {
        connect(addDeviceUi, &AddDevice::sendDeviceID, database, &Database::addDevice);
    }

    addDeviceUi->show();
}

void MainWindow::showCoordinates()
{
    if (coordinateSystem){
        qDebug() << "Coordinate system already exist";
        return;
    }

    qDebug() << "Displaying coordinates";
    coordinateSystem = new CoordinateSystem();

    connect(coordinateSystem, &CoordinateSystem::destroyed, this, &MainWindow::resetCoordinate);
    connect(processor, &Processor::updateCoord, coordinateSystem, &CoordinateSystem::updateCoord);

    coordinateSystem->receiveCoordinate(processor->getDeviceDataBuffer());
    coordinateSystem->show();
}

void MainWindow::resetSettingLocator(){
    settingLocatorUi = NULL;
}

void MainWindow::resetAddDevice(){
    addDeviceUi = NULL;
}

void MainWindow::resetCoordinate(){
    qDebug() << "Reset Coordinates";
    coordinateSystem = NULL;
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

void MainWindow::changeRowItem(int row,
                               QString deviceId,
                               QString tagId,
                               QString spk,
                               QString counter,
                               QString x, QString y, QString z,
                               QString locator1X, QString locator1Y, QString locator1Z,
                               QString locator2X, QString locator2Y, QString locator2Z,
                               QString locator3X, QString locator3Y, QString locator3Z,
                               QString locator4X, QString locator4Y, QString locator4Z,
                               QString lastUpdate){
    QTableWidgetItem *deviceIdItem = protoTableWidgetItem->clone();
    QTableWidgetItem *tagIdItem = protoTableWidgetItem->clone();
    QTableWidgetItem *spkItem = protoTableWidgetItem->clone();
    QTableWidgetItem *counterItem = protoTableWidgetItem->clone();
    QTableWidgetItem *xItem = protoTableWidgetItem->clone();
    QTableWidgetItem *yItem = protoTableWidgetItem->clone();
    QTableWidgetItem *zItem = protoTableWidgetItem->clone();
    QTableWidgetItem *locator1XItem = protoTableWidgetItem->clone();
    QTableWidgetItem *locator1YItem = protoTableWidgetItem->clone();
    QTableWidgetItem *locator1ZItem = protoTableWidgetItem->clone();
    QTableWidgetItem *locator2XItem = protoTableWidgetItem->clone();
    QTableWidgetItem *locator2YItem = protoTableWidgetItem->clone();
    QTableWidgetItem *locator2ZItem = protoTableWidgetItem->clone();
    QTableWidgetItem *locator3XItem = protoTableWidgetItem->clone();
    QTableWidgetItem *locator3YItem = protoTableWidgetItem->clone();
    QTableWidgetItem *locator3ZItem = protoTableWidgetItem->clone();
    QTableWidgetItem *locator4XItem = protoTableWidgetItem->clone();
    QTableWidgetItem *locator4YItem = protoTableWidgetItem->clone();
    QTableWidgetItem *locator4ZItem = protoTableWidgetItem->clone();
    QTableWidgetItem *lastUpdateItem = protoTableWidgetItem->clone();


    if (deviceId != IGNORE){
        deviceIdItem->setText(deviceId);
        tableWidgetCounting->setItem(row, DEVICE_ID, deviceIdItem);
    }

    if (tagId != IGNORE){
        tagIdItem->setText(DASH_IF_TAG_EMPTY(tagId));
        tableWidgetCounting->setItem(row, TAG_ID, tagIdItem);
    }

    if (spk != IGNORE){
        tagIdItem->setText(tagId);
        tableWidgetCounting->setItem(row, TAG_ID, tagIdItem);
    }

    if (counter != IGNORE){
        counterItem->setText(counter);
        tableWidgetCounting->setItem(row, COUNTER, counterItem);
    }

    if (x != IGNORE){
        xItem->setText(x);
        tableWidgetCounting->setItem(row, X, xItem);
    }

    if (y != IGNORE){
        yItem->setText(y);
        tableWidgetCounting->setItem(row, Y, yItem);
    }

    if (z != IGNORE){
        zItem->setText(x);
        tableWidgetCounting->setItem(row, Z, zItem);
    }

    if (locator1X != IGNORE){
        locator1XItem->setText(locator1X);
        tableWidgetCounting->setItem(row, X0, locator1XItem);
    }

    if (locator1Y != IGNORE){
        locator1YItem->setText(locator1Y);
        tableWidgetCounting->setItem(row, Y0, locator1YItem);
    }

    if (locator1Z != IGNORE){
        locator1ZItem->setText(locator1Z);
        tableWidgetCounting->setItem(row, Z0, locator1ZItem);
    }

    if (locator2X != IGNORE){
        locator2XItem->setText(locator2X);
        tableWidgetCounting->setItem(row, X1, locator2XItem);
    }

    if (locator2Y != IGNORE){
        locator2YItem->setText(locator2Y);
        tableWidgetCounting->setItem(row, Y1, locator2YItem);
    }

    if (locator2Z != IGNORE){
        locator2ZItem->setText(locator2Z);
        tableWidgetCounting->setItem(row, Z1, locator2ZItem);
    }
    if (locator3X != IGNORE){
        locator3XItem->setText(locator3X);
        tableWidgetCounting->setItem(row, X2, locator3XItem);
    }

    if (locator3Y != IGNORE){
        locator3YItem->setText(locator3Y);
        tableWidgetCounting->setItem(row, Y2, locator3YItem);
    }

    if (locator3Z != IGNORE){
        locator3ZItem->setText(locator3Z);
        tableWidgetCounting->setItem(row, Z2, locator3ZItem);
    }

    if (locator4X != IGNORE){
        locator4XItem->setText(locator4X);
        tableWidgetCounting->setItem(row, X3, locator4XItem);
    }

    if (locator4Y != IGNORE){
        locator4YItem->setText(locator4Y);
        tableWidgetCounting->setItem(row, Y3, locator4YItem);
    }

    if (locator4Z != IGNORE){
        locator4ZItem->setText(locator4Z);
        tableWidgetCounting->setItem(row, Z3, locator4ZItem);
    }
}

void MainWindow::closeEvent(QCloseEvent *closeEvent){
    if (settingLocatorUi) settingLocatorUi->close();
    delete settingLocatorUi;

    closeEvent->accept();
}

MainWindow::~MainWindow()
{
//    delete tcpServer;
//    timer->stop();
//    delete timer;
    delete settingLocatorUi;
    delete processor;
    delete database;
    delete ui;
}

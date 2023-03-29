#include "database.h"
#include "constants.h"

QString dbConnectionName("default");

Database::Database()
{

}

Database::~Database(){
    sql.clear();
    if (db.isOpen())db.close();
    QSqlDatabase::removeDatabase(dbConnectionName);
}

void Database::run(){
    qDebug()<<"Database starting connections...";

    sql = QSqlQuery(db);

    if (db.isOpen()) {\
        qDebug()<<"Database already listening";
        return;
    }

    db.open();
    if (!db.isOpen()){
        qDebug()<<"Failed to connect to database";
        Q_EMIT databaseConnectionResult(false);
        Q_EMIT databaseDisconnected();
        return;
    }

    qDebug()<<"Database connected";
    Q_EMIT databaseConnectionResult(true);


    createTable();
    retreiveDataDevice();

}

void Database::config(const QString ipAddress,
                       const QString port,
                       const QString databaseName,
                       const QString userName,
                       const QString password){
    db = QSqlDatabase::addDatabase("QMYSQL", dbConnectionName);
    db.setHostName(ipAddress);
    db.setPort(port.toInt());
    db.setDatabaseName(databaseName);
    db.setUserName(userName);
    db.setPassword(password);
}

void Database::disconnectDatabase(){
    qDebug()<<"Disconnecting database...";
    if(db.isOpen()) db.close();
    Q_EMIT databaseDisconnected();
}

void Database::addDevice(const QString &mac){
    bool isSuccess;
    QString queryAddDevice = tr("INSERT INTO %1 (device_id) VALUES (\"%2\")").arg(TABLE_NAME_DEVICES).arg(mac);

    isSuccess = sql.exec(queryAddDevice);
    qDebug()<<tr("Add device %1 succedd on table %2").arg(mac).arg(TABLE_NAME_DEVICES);

    Q_EMIT newDeviceAdded(mac);
}

void Database::createTable(){
    bool isSucceddQueryTableDevices;
    bool isSucceddQueryTableData = true;
    bool isSucceddQueryTableDevicesLocation;
    bool isSucceddQueryTableDataLocation = true;

    QString queryTableDevices;

#ifdef ACTIVE_DROP_TABLE
    queryTableDevices += tr("DROP TABLE IF EXISTS %1;").arg(TABLE_NAME_DEVICES);
#endif
    queryTableDevices += tr("CREATE TABLE IF NOT EXISTS %1 ("
                                    "device_id VARCHAR(16) PRIMARY KEY, "
                                    "tag VARCHAR(20), "
                                    "spk INT, "
                                    "counter INT, "
                                   "x DOUBLE, "
                                   "y DOUBLE, "
                                   "z DOUBLE, "
                                   "locator1_x DOUBLE, "
                                   "locator1_y DOUBLE, "
                                   "locator1_z DOUBLE, "
                                   "locator2_x DOUBLE, "
                                   "locator2_y DOUBLE, "
                                   "locator2_z DOUBLE, "
                                   "locator3_x DOUBLE, "
                                   "locator3_y DOUBLE, "
                                   "locator3_z DOUBLE, "
                                   "locator4_x DOUBLE, "
                                   "locator4_y DOUBLE, "
                                   "locator4_z DOUBLE, "
                                    "last_update DATETIME)").arg(TABLE_NAME_DEVICES);
    isSucceddQueryTableDevices = sql.exec(queryTableDevices);
    qDebug()<<sql.lastError();

//    QString queryTableData = tr("DROP TABLE %1; CREATE TABLE IF NOT EXISTS %1 (id INT AUTO_INCREMENT PRIMARY KEY, "
//                                  "device_id VARCHAR(16), "
//                                  "tag VARCHAR(20), "
//                                  "spk INT, "
//                                  "counter INT, "
//                                  "date_time DATETIME)").arg(TABLE_NAME_DATA);

//    isSucceddQueryTableData = sql.exec(queryTableData);
//    qDebug()<<sql.lastError();
    QString queryTableDevicesLocation;
#ifdef ACTIVE_DROP_TABLE
    queryTableDevicesLocation += tr("DROP TABLE IF EXISTS %1;").arg(TABLE_NAME_DEVICES_LOCATION);
#endif

    queryTableDevicesLocation += tr("CREATE TABLE IF NOT EXISTS %1 (id INT AUTO_INCREMENT PRIMARY KEY, "
                                  "device_id VARCHAR(16), "
                                  "tag VARCHAR(20), "
                                  "spk INT, "
                                  "counter INT, "
                                   "x DOUBLE, "
                                   "y DOUBLE, "
                                   "z DOUBLE, "
                                   "locator1_x DOUBLE, "
                                   "locator1_y DOUBLE, "
                                   "locator1_z DOUBLE, "
                                   "locator2_x DOUBLE, "
                                   "locator2_y DOUBLE, "
                                   "locator2_z DOUBLE, "
                                   "locator3_x DOUBLE, "
                                   "locator3_y DOUBLE, "
                                   "locator3_z DOUBLE, "
                                   "locator4_x DOUBLE, "
                                   "locator4_y DOUBLE, "
                                   "locator4_z DOUBLE, "
                                    "timestamp DATETIME)").arg(TABLE_NAME_DEVICES_LOCATION);
    isSucceddQueryTableDevicesLocation = sql.exec(queryTableDevicesLocation);
    qDebug()<<sql.lastError();

//    QString queryTableDataLocation = tr("DROP TABLE %1; CREATE TABLE IF NOT EXISTS %1 ( id INT AUTO_INCREMENT PRIMARY KEY, "
//                                              "device_id VARCHAR(16),"
//                                              "ar1_x DOUBLE, "
//                                              "ar1_y DOUBLE, "
//                                              "ar1_z DOUBLE, "
//                                              "ar2_x DOUBLE, "
//                                              "ar2_y DOUBLE, "
//                                              "ar2_z DOUBLE, "
//                                              "ar3_x DOUBLE, "
//                                              "ar3_y DOUBLE, "
//                                              "ar3_z DOUBLE, "
//                                              "ar4_x DOUBLE, "
//                                              "ar4_y DOUBLE, "
//                                              "ar4_z DOUBLE, "
//                                              "date_time DATETIME)").arg(TABLE_NAME_DATA_LOCATION);
//    isSucceddQueryTableDataLocation = sql.exec(queryTableDataLocation);
//    qDebug()<<sql.lastError();

    Q_EMIT tableCreateResult(isSucceddQueryTableDevices,
                             isSucceddQueryTableData, \
                             isSucceddQueryTableDevicesLocation,
                             isSucceddQueryTableDataLocation);
}

void Database::retreiveDataDevice(){
    QString query = tr("SELECT device_id,"
                       "tag, "
                       "spk, "
                       "counter, "
                       "x, "
                       "y, "
                       "z, "
                       "locator1_x, "
                       "locator1_y, "
                       "locator1_z, "
                       "locator2_x, "
                       "locator2_y, "
                       "locator2_z, "
                       "locator3_x, "
                       "locator3_y, "
                       "locator3_z, "
                       "locator4_x, "
                       "locator4_y, "
                       "locator4_z, "
                       "last_update "
                       "FROM %1").arg(TABLE_NAME_DEVICES);

    if (!sql.exec(query)){
        qDebug() << tr("Failed to execute %1").arg(query);
        return;
    }
    QStringList deviceIds;
    QStringList tagIds;
    QStringList spks;
    QStringList counters;
    QStringList Xs;
    QStringList Ys;
    QStringList Zs;
    QStringList locator1Xs;
    QStringList locator1Ys;
    QStringList locator1Zs;
    QStringList locator2Xs;
    QStringList locator2Ys;
    QStringList locator2Zs;
    QStringList locator3Xs;
    QStringList locator3Ys;
    QStringList locator3Zs;
    QStringList locator4Xs;
    QStringList locator4Ys;
    QStringList locator4Zs;
    QStringList lastUpdates;
    while (sql.next()){
        deviceIds << sql.value("device_id").toString();
        tagIds << sql.value("tag").toString();
        spks << sql.value("spk").toString();
        counters << sql.value("counter").toString();
        Xs << sql.value("x").toString();
        Ys << sql.value("y").toString();
        Zs << sql.value("z").toString();
        locator1Xs << sql.value("locator1_x").toString();
        locator1Ys << sql.value("locator1_y").toString();
        locator1Zs << sql.value("locator1_z").toString();
        locator2Xs << sql.value("locator2_x").toString();
        locator2Ys << sql.value("locator2_y").toString();
        locator2Zs << sql.value("locator2_z").toString();
        locator3Xs << sql.value("locator3_x").toString();
        locator3Ys << sql.value("locator3_y").toString();
        locator3Zs << sql.value("locator3_z").toString();
        locator4Xs << sql.value("locator4_x").toString();
        locator4Ys << sql.value("locator4_y").toString();
        locator4Zs << sql.value("locator4_z").toString();
        lastUpdates << sql.value("last_update").toString();
    }

    qDebug() << deviceIds;

    Q_EMIT sendLastStateDevice(deviceIds, tagIds, spks, counters,
                               Xs, Ys, Zs,
                               locator1Xs, locator1Ys, locator1Zs,
                               locator2Xs, locator2Ys, locator2Zs,
                               locator3Xs, locator3Ys, locator3Zs,
                               locator4Xs, locator4Ys, locator4Zs,
                               lastUpdates);
    Q_EMIT sendLastStateDevice2(deviceIds, tagIds, spks, counters, Xs, Ys, Zs);
    Q_EMIT sendDeviceIds(deviceIds);
}

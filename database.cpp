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

void Database::createTable(){
    bool isSucceddQueryTableDevices;
    bool isSucceddQueryTableData;
    bool isSucceddQueryTableDevicesLocation;
    bool isSucceddQueryTableDataLocation;
    QString queryTableDevices = tr("CREATE TABLE IF NOT EXISTS %1 (device_id VARCHAR(16) PRIMARY KEY, "
                                                                    "tag VARCHAR(20), "
                                                                    "spk INT, "
                                                                    "counter INT, "
                                                                    "last_update DATETIME)").arg(TABLE_NAME_DEVICES);
    isSucceddQueryTableDevices = sql.exec(queryTableDevices);
    qDebug()<<sql.lastError();

    QString queryTableData = tr("CREATE TABLE IF NOT EXISTS %1 (id INT AUTO_INCREMENT PRIMARY KEY, "
                                  "device_id VARCHAR(16), "
                                  "tag VARCHAR(20), "
                                  "spk INT, "
                                  "counter INT, "
                                  "date_time DATETIME)").arg(TABLE_NAME_DATA);

    isSucceddQueryTableData = sql.exec(queryTableData);
    qDebug()<<sql.lastError();

    QString queryTableDevicesLocation = tr("CREATE TABLE IF NOT EXISTS %1 (device_id VARCHAR(16) PRIMARY KEY, "
                                              "ar1_x DOUBLE, "
                                              "ar1_y DOUBLE, "
                                              "ar1_z DOUBLE, "
                                              "ar2_x DOUBLE, "
                                              "ar2_y DOUBLE, "
                                              "ar2_z DOUBLE, "
                                              "ar3_x DOUBLE, "
                                              "ar3_y DOUBLE, "
                                              "ar3_z DOUBLE, "
                                              "ar4_x DOUBLE, "
                                              "ar4_y DOUBLE, "
                                              "ar4_z DOUBLE, "
                                              "last_update DATETIME)").arg(TABLE_NAME_DEVICES_LOCATION);
    isSucceddQueryTableDevicesLocation = sql.exec(queryTableDevicesLocation);
    qDebug()<<sql.lastError();

    QString queryTableDataLocation = tr("CREATE TABLE IF NOT EXISTS %1 ( id INT AUTO_INCREMENT PRIMARY KEY, "
                                              "device_id VARCHAR(16),"
                                              "ar1_x DOUBLE, "
                                              "ar1_y DOUBLE, "
                                              "ar1_z DOUBLE, "
                                              "ar2_x DOUBLE, "
                                              "ar2_y DOUBLE, "
                                              "ar2_z DOUBLE, "
                                              "ar3_x DOUBLE, "
                                              "ar3_y DOUBLE, "
                                              "ar3_z DOUBLE, "
                                              "ar4_x DOUBLE, "
                                              "ar4_y DOUBLE, "
                                              "ar4_z DOUBLE, "
                                              "date_time DATETIME)").arg(TABLE_NAME_DATA_LOCATION);
    isSucceddQueryTableDataLocation = sql.exec(queryTableDataLocation);
    qDebug()<<sql.lastError();

    Q_EMIT tableCreateResult(isSucceddQueryTableDevices,
                             isSucceddQueryTableData, \
                             isSucceddQueryTableDevicesLocation,
                             isSucceddQueryTableDataLocation);
}

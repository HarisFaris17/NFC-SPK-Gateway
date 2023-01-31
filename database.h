#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <memory>
#include <QThread>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QHostAddress>
#include <QLatin1String>
#include <QSqlError>

class Database : public QObject
{
    Q_OBJECT
Q_SIGNALS:
    void databaseConnectionResult(bool isSuccess);
    void databaseDisconnected();

    void tableCreateResult(bool isDeviceTableCreated, bool isDataTableCreated, bool isDeviceLocationTableCreated, bool isDataLocationTableCreated);

public Q_SLOTS:
    void run();
    void config(const QString ipAddress, const QString port, const QString databaseName, const QString userName, const QString password);
    void disconnectDatabase();
    void createTable();

public:
    Database();
    ~Database();

private:
    QSqlQuery sql;
    QSqlDatabase db;
};

#endif // DATABASE_H

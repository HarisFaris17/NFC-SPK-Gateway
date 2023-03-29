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
#include <QStringList>

class Database : public QObject
{
    Q_OBJECT
Q_SIGNALS:
    void databaseConnectionResult(bool isSuccess);
    void databaseDisconnected();

    void tableCreateResult(bool isDeviceTableCreated, bool isDataTableCreated, bool isDeviceLocationTableCreated, bool isDataLocationTableCreated);
    void sendDeviceIds(QStringList deviceIds);
    void sendLastStateDevice(QStringList deviceIds,
                              QStringList tagId,
                              QStringList spk,
                              QStringList counter,
                              QStringList x, QStringList y, QStringList z,
                              QStringList locator1X, QStringList locator1Y, QStringList locator1Z,
                              QStringList locator2X, QStringList locator2Y, QStringList locator2Z,
                              QStringList locator3X, QStringList locator3Y, QStringList locator3Z,
                              QStringList locator4X, QStringList locator4Y, QStringList locator4Z,
                              QStringList lastUpdate);
    void sendLastStateDevice2(QStringList deviceIds,
                              QStringList tagId,
                              QStringList spk,
                              QStringList counter,
                              QStringList x, QStringList y, QStringList z);

    void newDeviceAdded(const QString &mac);

public Q_SLOTS:
    void run();
    void config(const QString ipAddress, const QString port, const QString databaseName, const QString userName, const QString password);
    void disconnectDatabase();
    void addDevice(const QString &mac);


public:
    Database();
    ~Database();

private:
    QSqlQuery sql;
    QSqlDatabase db;

private:
    void createTable();
    void retreiveDataDevice();
};

#endif // DATABASE_H

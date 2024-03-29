#ifndef FILE_H
#define FILE_H

#include "constants.h"
#include <QFile>
#include <QIODevice>
#include <QByteArray>
#include <QDebug>
#include <QDir>
#include <QList>

class File : public QFile
{
public:
    File(QObject *parent = nullptr);
    ~File();
    void parseFile(QString &ipAddress,
                   QString &TCPPort,
                   QString &host,
                   QString &databasePort,
                   QString &databaseName,
                   QString &userName,
                   QString &password);

    void parseLocatorParams(QString &x0, QString &y0, QString &z0,
                            QString &x1, QString &y1, QString &z1,
                            QString &x2, QString &y2, QString &z2,
                            QString &x3, QString &y3, QString &z3,
                            QString &x4, QString &y4, QString &z4,
                            QString &x5, QString &y5, QString &z5,
                            QString &x6, QString &y6, QString &z6,
                            QString &x7, QString &y7, QString &z7);

    void parseRSSI(QString &RSSI1m, QString &RSSI2m);

    void parseGatewayMac(QString &gateway1MAC, QString &gateway2MAC);

//    bool parseTCPServerInfo(QString &ipAddress, QString &port);
//    void saveIQ();
    void saveDatabaseConfig(QString host,
                            QString databasePort,
                            QString databaseName,
                            QString userName,
                            QString password);

    void saveTCPServerConfig(QString ipAddress, QString TCPPort);

    bool saveFile(QString ipAddress,
                  QString TCPPort,
                  QString host,
                  QString databasePort,
                  QString databaseName,
                  QString userName,
                  QString password);

    bool saveIQ(const QString macAddress, const int &locator, const QByteArray dataIQ);
    bool saveInstantaneousRSSI(QString RSSI, QString mac, const int &locator);

    bool saveConvenientCoordinatesPerLocator(const QString &macAddress, const int &locator, const QByteArray &xyz, const QString &dataType);
    bool saveConvenientCoordinatesCumulative(const QString &macAddress, const QByteArray &xyz);

    bool saveAoAAnglesPerLocator(const QString &macAddress, const int &locator, const QByteArray &angles);
    bool saveAoACoordinatesPerTwoLocators(const QString &macAddress, const int &locator1, const int &locator2, const QByteArray &xyz);
    bool saveAoACoordinatesPerLocator(const QString &macAddress, const int &locator1, const QByteArray &xyz);
    bool saveAoACoordinatesCumulative(const QString &macAddress, const QByteArray &xyz);

    bool saveLocatorParams(QString x0, QString y0, QString z0,
                           QString x1, QString y1, QString z1,
                           QString x2, QString y2, QString z2,
                           QString x3, QString y3, QString z3,
                           QString x4, QString y4, QString z4,
                           QString x5, QString y5, QString z5,
                           QString x6, QString y6, QString z6,
                           QString x7, QString y7, QString z7);
    bool saveRSSI(QString &RSSI1m, QString &RSSI2m);

    bool saveCalculatorData(const QByteArray &data);

    bool saveGatewayMAC(const QString gateway1MAC, const QString gateway2MAC);

private:
    QByteArray parseData(QByteArray &data,int &index, bool &isSuccess);

};

#endif // FILE_H

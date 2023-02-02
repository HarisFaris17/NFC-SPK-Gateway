#ifndef FILE_H
#define FILE_H

#include "constants.h"
#include <QFile>
#include <QIODevice>
#include <QByteArray>
#include <QDebug>
#include <QDir>

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

    bool saveIQ(const QString macAddress, const QByteArray dataIQ);

private:
    QByteArray parseData(QByteArray &data,int &index, bool &isSuccess);

};

#endif // FILE_H

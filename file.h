#ifndef FILE_H
#define FILE_H

#include <QFile>
#include <QIODevice>
#include <QByteArray>
#include <QDebug>

class File : public QFile
{
public:
    File();
    ~File();
    void parseFile(QString &ipAddress, QString &TCPPort, QString &host, QString &databasePort, QString &databaseName, QString &userName, QString &password);
//    bool parseTCPServerInfo(QString &ipAddress, QString &port);
private:
    QByteArray parseData(QByteArray &data,int &index, bool &isSuccess);
};

#endif // FILE_H

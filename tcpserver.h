#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>
#include <QByteArray>
#include <QDebug>
#include <QString>
#include <QApplication>
#include <QThread>
#include <QEvent>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonValueRef>
#include <memory>
#include <QMetaObject>
//#include "mainwindow.h"


class TCPServer : public QTcpServer
{
    Q_OBJECT
public Q_SLOTS:
    void listenTcp(const QString &ipAddress, const QString &port);
    void onNewConnection();
    void onReadyRead();
//    void config();
    void unlisten();
    // here handle the event of thread changed. remember that event is not signal, therefore we should handle it
    bool event(QEvent *e) override;


private Q_SLOTS:
    void cleanup();
    void run();

Q_SIGNALS:
    void unlistened();
    void listenResult(bool isSuccess);

public:
    TCPServer();

    ~TCPServer();

private:
    QString ipAddress;
    int port;
    std::unique_ptr<QThread> mp_thread;
};

#endif // TCPSERVER_H

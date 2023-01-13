#ifndef TCP_H
#define TCP_H

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

class Tcp : QObject
{
    Q_OBJECT
Q_SIGNALS:
    void listen(const QHostAddress &ipAddress, const int port);
    void unlisten();
public Q_SLOTS:
    void started();
    void listenTCP(const QString &ipAddress, const QString port);
    void unlistenTCP();

public:
    Tcp();
    ~Tcp();

private:
    std::unique_ptr<QThread> mp_thread;
    QTcpServer *tcpServer = NULL;
};

#endif // TCP_H

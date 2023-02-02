#ifndef TCPSERVER2_H
#define TCPSERVER2_H

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
#include <QVariantMap>
#


class TcpServer2 : public QTcpServer
{
    Q_OBJECT
public Q_SLOTS:
    void onNewConnection();
    void onReadyRead();
    void config(const QString &ipAddress,const QString &port);
    void unlisten();
    // here handle the event of thread changed. remember that event is not signal, therefore we should handle it
//    bool event(QEvent *e) override;
    void test();

Q_SIGNALS:
    void unlistened();
    void listenResult(bool isSuccess);
    void sendData(QByteArray data);
    \
public:
    TcpServer2();
    ~TcpServer2();
    void run();

private:
    QString ipAddress;
    int port;
};

#endif // TCPSERVER2_H

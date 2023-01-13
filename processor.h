#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <QObject>
#include <QString>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDebug>
#include <QDateTime>

class Processor : public QObject
{
    Q_OBJECT
public Q_SLOTS:
    void receiveTcpData(QByteArray data);
    void started();

Q_SIGNALS:
    void sendData(QByteArray data);
public:
    Processor();
    ~Processor();

private:
    bool convertToBytes(QString stringedBytes, QByteArray *p_result);
};

#endif // PROCESSOR_H

#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "constants.h"
#include "common.h"
#include "file.h"
#include "devicedatacontainer.h"
#include <QObject>
#include <QString>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDebug>
#include <QDateTime>
#include <QFile>
#include <QList>
#include <QVariant>
#include <QProcess>
#include <QStringList>
#include <QDir>
#include <QVector>
#include <cmath>



class Processor : public QObject
{
    Q_OBJECT
public Q_SLOTS:
    void receiveTcpData(QByteArray rawData);
//    void receiveTcpLocation(QByteArray tcpData);
    void started();

    void locationCalculatorStarted();
    void errorOccured(QProcess::ProcessError error);
    void locationCalculatorFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void stateChanged(QProcess::ProcessState state);

    void receiveLastStateDevice(QStringList deviceIds,
                                QStringList tagId,
                                QStringList spk,
                                QStringList counter,
                                QStringList x, QStringList y, QStringList z);
    void addDeviceId(const QString &deviceId);

    void receiveRSSIConfig(QString rssi1m, QString rssi2m);
    void receiveLocatorParams(QString x0, QString y0, QString z0,
                              QString x1, QString y1, QString z1,
                              QString x2, QString y2, QString z2,
                              QString x3, QString y3, QString z3,
                              QString x4, QString y4, QString z4,
                              QString x5, QString y5, QString z5,
                              QString x6, QString y6, QString z6,
                              QString x7, QString y7, QString z7);

private Q_SLOTS:
    void readyRead();

Q_SIGNALS:
    void sendData(QString data);
    void sendDataTable(QString deviceId, QString tagId, QString spk, QString counter, QString dateTime);
    void sendLocation(QString deviceId, int locator, double x, double y, double z);
    void sendCumulativeLocation(QString deviceId, double x, double y, double z);

    void sendHistory(const QString &deviceId,
                     const QString &tagId,
                     const QString &spk,
                     const QString &counter,
                     const QString &x, const QString &y, const QString &z,
                     const QString &x0, const QString &y0, const QString &z0,
                     const QString &x1, const QString &y1, const QString &z1,
                     const QString &x2, const QString &y2, const QString &z2,
                     const QString &x3, const QString &y3, const QString &z3,
                     const QString &dateTime);

    void updateCoord();

//    void sendDataIQLocation(const QByteArray &data);
public:
    Processor();
    ~Processor();

    QMap<QString, DeviceDataContainer> * getDeviceDataBuffer();
    int indexOfDeviceId(QString deviceId);

private:
    bool convertToBytes(QString stringedBytes, QByteArray *p_result);
    bool parseData(QByteArray data, int index, QString *p_result);
    bool extractData(QByteArray rawData, QByteArray *p_result);

    bool saveIQ(const QString macAddress, const QByteArray dataIQ);
private:
    QProcess *locationCalculatorProcessor;


//    QList<Coordinate> coordinates;
    QMap<QString, DeviceDataContainer> deviceDataBuffer;

//    QVector<QList<Coordinate>> coordinatesBuffer = QVector<QList<Coordinate>>(4);
};


#endif // PROCESSOR_H

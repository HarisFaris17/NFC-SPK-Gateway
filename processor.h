#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "constants.h"
#include "file.h"
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

class Processor : public QObject
{
    Q_OBJECT
public Q_SLOTS:
    void receiveTcpData(QByteArray rawData);
    void receiveTcpLocation(QByteArray tcpData);
    void started();

    void locationCalculatorStarted();
    void errorOccured(QProcess::ProcessError error);
    void locationCalculatorFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void stateChanged(QProcess::ProcessState state);

private Q_SLOTS:
    void readyRead();

Q_SIGNALS:
    void sendData(QString data);
    void sendDataTable(QString deviceId, QString tagId, QString spk, QString counter, QString dateTime);
    void sendLocation(QString deviceId, int locator, double x, double y, double z);

//    void sendDataIQLocation(const QByteArray &data);
public:
    Processor();
    ~Processor();

private:
    bool convertToBytes(QString stringedBytes, QByteArray *p_result);
    bool parseData(QByteArray data, int index, QString *p_result);
    bool extractData(QByteArray rawData, QByteArray *p_result);

    bool saveIQ(const QString macAddress, const QByteArray dataIQ);
private:
    QProcess *locationCalculatorProcessor;

    class Coordinate{
        Coordinate(double x, double y, double z){
            this->x = x;
            this->y = y;
            this->z = z;
        }

        double x;
        double y;
        double z;
    };

//    QList<Coordinate> coordinates;
    QVector<QList<Coordinate>> coordinatesBuffer = QVector<QList<Coordinate>>(4);
};

#endif // PROCESSOR_H

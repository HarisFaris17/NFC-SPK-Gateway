#ifndef COMMON_H
#define COMMON_H

#include <QList>
#include <QObject>
#include <QString>
#include <QMutex>
#include <QStringList>


class Common : public QObject
{
    Q_OBJECT
public:
    Common();
    static QStringList getDeviceIds();
public Q_SLOTS:
    static void addDeviceId(const QString &deviceId);
    static void replaceDeviceIds(const QList<QString> &deviceIds);
    static int indexDeviceId(const QString &deviceId);
    static bool isExistDeviceId(const QString &deviceId);

private:
    static QStringList deviceIds;
};

#endif // COMMON_H

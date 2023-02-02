#ifndef COMMON_H
#define COMMON_H

#include <QList>
#include <QString>
#include <QMutex>


class Common
{
public:
    Common();
public:
    static void addDeviceId(const QString &deviceId);
    static void replaceDeviceIds(const QList<QString> &deviceIds);
    static int indexDeviceId(const QString &deviceId);
    static bool isExistDeviceId(const QString &deviceId);

private:
    static QList<QString> deviceIds;
};

#endif // COMMON_H

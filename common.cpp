#include "common.h"

QStringList Common::deviceIds;

Common::Common()
{

}

QStringList Common::getDeviceIds(){
    return deviceIds;
}

void Common::addDeviceId(const QString &deviceId){
    QMutex mutex;
    if (!mutex.tryLock(1000)) return;
    deviceIds << deviceId;
    mutex.unlock();
}

// if the parameter is not a reference, instead it is a copy
void Common::replaceDeviceIds(const QList<QString> &deviceIds){
    QMutex mutex;
    if (!mutex.tryLock(1000)) return;
//     this will automatically create deep copy of every items of deviceIds parameter and assign them to the deviceId member class
    Common::deviceIds = deviceIds;
    mutex.unlock();
}

int Common::indexDeviceId(const QString &deviceId){
    return Common::deviceIds.indexOf(deviceId);
}

bool Common::isExistDeviceId(const QString &deviceId){
    if (indexDeviceId(deviceId) == -1) return false;
    return true;
}

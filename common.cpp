#include "common.h"

QList<QString> Common::deviceIds;

Common::Common()
{

}

void Common::addDeviceId(const QString &deviceId){
    deviceIds << deviceId;
}

// if the parameter is not a reference, instead it is a copy
void Common::replaceDeviceIds(const QList<QString> &deviceIds){
//     this will automatically create deep copy of every items of deviceIds parameter and assign them to the deviceId member class
    Common::deviceIds = deviceIds;
}

int Common::indexDeviceId(const QString &deviceId){
    return Common::deviceIds.indexOf(deviceId);
}

bool Common::isExistDeviceId(const QString &deviceId){
    if (indexDeviceId(deviceId) == -1) return false;
    return true;
}

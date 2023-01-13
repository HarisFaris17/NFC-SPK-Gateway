#include "processor.h"

Processor::Processor()
{

}

void Processor::receiveTcpData(QByteArray data){
    qDebug()<<"Received TCP Data in file processor";
    QJsonDocument dataJson = QJsonDocument::fromJson(data);
    if (dataJson.isEmpty()){
        qDebug()<<"Error while parsing JSON or JSON data is empty";
        qDebug()<<dataJson;
        return;
    }
    QJsonArray dataJsonArray = dataJson.array();
    qDebug()<<dataJsonArray;
    QString wantedMac = tr("DCC7CD766E3A");
    for (auto dataIterator = dataJsonArray.begin(); dataIterator != dataJsonArray.end(); ++dataIterator){
        QJsonValue dataElement = *dataIterator;

        if (!dataElement.isObject()){
            qDebug()<<tr("Data element %1 in index %2 is not object").arg(dataElement.toString()).arg(dataIterator.i);
            continue;
        }

        QJsonObject dataElementObject = dataElement.toObject();
        QString mac = dataElementObject.value("mac").toString();
        if (mac != wantedMac) {
            qDebug()<<"Not wanted MAC";
            continue;
        }
        qDebug()<<"MACCCCCCCCC wanted";

        QString stringedBytesData = dataElementObject.value("rawData").toString();
        qDebug()<<"rawData"<<stringedBytesData;
        QByteArray data;

        if (!convertToBytes(stringedBytesData, &data)){
            qDebug()<<"Failed to convert";
            // here we continue the loops since maybe there are some other MAC address we want to inspect the data
            continue;
        }

        data += tr("#") + wantedMac;

        data += tr("#") + QDateTime::currentDateTime().toString("ddMMyyyyHHmmss");
        Q_EMIT sendData(data);
    }
}

void Processor::started(){
    qDebug()<<"Processor started";
}

bool Processor::convertToBytes(QString stringedBytes, QByteArray *p_result){
    if (p_result == NULL) {
        qDebug()<<"The p_result pointer shouldn't be NULL";
        return false;
    }

    int stringedBytesLength = stringedBytes.length();
    if (stringedBytesLength %2 != 0) {
        qDebug()<<"Every stringed bytes should contains 2 character in the stringed bytes, hence the length of stringed bytes should be even";
        return false;
    }

    QByteArray byteArrayedBytes = stringedBytes.toUtf8();
    QByteArray bytes;
    uint8_t slashCounter = 0;

    for (int i = 0; i < stringedBytesLength; i+=2){
        QByteArray array;

        array += byteArrayedBytes[i];
        array += byteArrayedBytes[i+1];
        bool converted = false;

        uint8_t byte = (uint8_t)array.toInt(&converted, 16);

        if (!converted) return false;

        qDebug()<<"Char"<<byte;
        if (byte == '#') {
            slashCounter++;
        }

        // the stringed NFC ID is exist after the 3rd '#', hence we don't need to converted to bytes after that 3rd '#'
        bytes += byte;
        *p_result += byte;
        if (slashCounter == 3) {
            // the +2 here to jump to the index where the stringed NFC ID started, since every bytes in stringedbytes occupy 2 character.
            for (int j = i+2; j<stringedBytesLength; j++){
                bytes += byteArrayedBytes[j];
                *p_result += byteArrayedBytes[j];
            }
            break;
        }
    }

    if (slashCounter < 3) return false;
    qDebug()<<bytes;
    return true;
}

Processor::~Processor(){

}

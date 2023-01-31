#include "processor.h"

Processor::Processor()
{

}

void Processor::receiveTcpData(QByteArray rawData){
    qDebug()<<"Received TCP Data in file processor";
    QJsonDocument dataJson = QJsonDocument::fromJson(rawData);
    if (dataJson.isEmpty()){
        qDebug()<<"Error while parsing JSON or JSON data is empty";
        qDebug()<<dataJson;
        return;
    }
    QJsonArray dataJsonArray = dataJson.array();
    qDebug()<<dataJsonArray;
    QString wantedMac = tr("DCC7CD766E3A");
    QString wantedMac2 = tr("E985AED59234");
    for (auto dataIterator = dataJsonArray.begin(); dataIterator != dataJsonArray.end(); ++dataIterator){
        QJsonValue dataElement = *dataIterator;

        if (!dataElement.isObject()){
            qDebug()<<tr("Data element %1 in index %2 is not object").arg(dataElement.toString()).arg(dataIterator.i);
            continue;
        }

        qDebug()<<"The object-----------";
        QJsonObject dataElementObject = dataElement.toObject();
        qDebug()<<dataElementObject;
        qDebug()<<"The object-----------";

        qDebug()<<"iq------------";
        QJsonObject aoaObject = dataElementObject.value("aoa").toObject();
        int frequency = aoaObject.value("frequency").toInt(2402);
        QList<QVariant> iqJsonArray = aoaObject.value("iq").toArray().toVariantList();
        QList<int> iq;
        QByteArray iqString;
        for(auto iqVariant = iqJsonArray.begin(); iqVariant != iqJsonArray.end(); ++iqVariant){
            iq.append(iqVariant->toInt());
            iqString += QByteArray::number(iqVariant->toInt()) + ",";
        }
        if (iqString.length() == 0) continue;
        iqString[iqString.length()-1] = '\n';

        int rssi = dataElementObject.value("rssi").toInt();
        // MAC should be in upper case in this project
        QString mac = dataElementObject.value("mac").toString().toUpper();

        saveIQ(mac, iqString);
        qDebug()<<frequency<<iq<<rssi<<mac<<iqString;
        if (mac != wantedMac && mac != wantedMac2) {
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
        QByteArray extractedData;

        if (!extractData(data, &extractedData)){
            qDebug()<<"Failed to extract data";
            return;
        }

        QString currentTimeString = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

        extractedData += tr("#") + wantedMac;
        extractedData += tr("#") + currentTimeString;


        Q_EMIT sendData(extractedData);

        QString cmd;
        QString spk;
        QString counter;
        QString tagId;


        qDebug()<<"Parsing...";
        if (!parseData(extractedData, 0, &cmd)) {
            qDebug()<<"parsing first data failed";
            return;
        }

        if (!parseData(extractedData, 1, &spk)) {
            qDebug()<<"parsing first data failed";
            return;
        }

        if (!parseData(extractedData, 2, &counter)){
            qDebug()<<"parsing first data failed";
            return;
        }\
        if (!parseData(extractedData, 3, &tagId)) {
            qDebug()<<"parsing first data failed";
            return;
        }

        qDebug()<<"The cmd \n\n\n"<<cmd;
        qDebug()<<spk;
        qDebug()<<counter;
        if (cmd == "DAT") Q_EMIT sendDataTable(mac, tagId, spk, counter, currentTimeString);
        else if (cmd == "DON") Q_EMIT sendDataTable(mac, "", spk, counter, currentTimeString);
    }
}

void Processor::receiveTcpLocation(QByteArray tcpData){
    qDebug()<<"Received TCP Data in file processor";
    QJsonDocument dataJson = QJsonDocument::fromJson(tcpData);
    if (dataJson.isEmpty()){
        qDebug()<<"Error while parsing JSON or JSON data is empty";
        qDebug()<<dataJson;
        return;
    }
    QJsonArray dataJsonArray = dataJson.array();
    qDebug()<<dataJsonArray;
    QString wantedMac = tr("DCC7CD766E3A");
    QString wantedMac2 = tr("E985AED59234");
    for (auto dataIterator = dataJsonArray.begin(); dataIterator != dataJsonArray.end(); ++dataIterator){
        QJsonValue dataElement = *dataIterator;

        if (!dataElement.isObject()){
            qDebug()<<tr("Data element %1 in index %2 is not object").arg(dataElement.toString()).arg(dataIterator.i);
            continue;
        }

        QJsonObject dataElementObject = dataElement.toObject();
        QString mac = dataElementObject.value("mac").toString();
        if (dataElementObject.value("iq").isArray()) qDebug()<<"Not arrayyyyyyy";
        qDebug()<<"The array-----------";
        qDebug()<<dataElementObject.value("iq").toArray();
        qDebug()<<"--------------------";
        if (mac != wantedMac && mac != wantedMac2) {
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
        QByteArray extractedData;

        if (!extractData(data, &extractedData)){
            qDebug()<<"Failed to extract data";
            return;
        }

        QString currentTimeString = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

        extractedData += tr("#") + wantedMac;
        extractedData += tr("#") + currentTimeString;


        Q_EMIT sendData(extractedData);

        QString cmd;
        QString spk;
        QString counter;
        QString tagId;


        qDebug()<<"Parsing...";
        if (!parseData(extractedData, 0, &cmd)) {
            qDebug()<<"parsing first data failed";
            return;
        }

        if (!parseData(extractedData, 1, &spk)) {
            qDebug()<<"parsing first data failed";
            return;
        }

        if (!parseData(extractedData, 2, &counter)){
            qDebug()<<"parsing first data failed";
            return;
        }\
        if (!parseData(extractedData, 3, &tagId)) {
            qDebug()<<"parsing first data failed";
            return;
        }

        qDebug()<<"The cmd \n\n\n"<<cmd;
        qDebug()<<spk;
        qDebug()<<counter;
        if (cmd == "DAT") Q_EMIT sendDataTable(mac, tagId, spk, counter, currentTimeString);
        else if (cmd == "DON") Q_EMIT sendDataTable(mac, "", spk, counter, currentTimeString);
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

bool Processor::parseData(QByteArray data, int dataRegionNumber, QString *p_result){
    qDebug()<<__func__<<data;
    uint8_t slashCounter = 0;
    int i = 0;

//    if (dataRegionNumber != 0){
//        for ( ; i < data.length(); i++){
//            qDebug()<<i;
//            if (data[i] == '#'){
//                slashCounter++;
//                qDebug()<<"slash : "<<slashCounter;
//                if (slashCounter == dataRegionNumber) break;
//            }
//        }
//        qDebug()<<slashCounter<<";";

//    }

//    //  the last value of i must be at last index of data or at first index of string of dataRegionNumber
//    int j = 0;
//    for (i++; i < data.length(); i++){
//        if (data[i] == '#') break;
//        (*p_result)[j] = data[i];
//        j++;
//    }
    int j = 0;
    for (; i < data.length(); i++){
        if (dataRegionNumber == slashCounter){
            if (data[i] == '#') break;
            (*p_result)[j] = data[i];
            j++;
        }
        if (data[i] == '#') slashCounter++;
    }
    if (slashCounter != dataRegionNumber) return false;

    return true;

}

bool Processor::extractData(QByteArray rawData, QByteArray *p_result){
    // first data cukup is just for flags
//    int index_value;
//    uint8_t flags_length = rawData[0];
//    index_value = 0 + flags_length;

//    uint8_t manuf_data_length = rawData[index_value+1];
//    index_value += 3;
//    \
//    // +2 since there is manufactur id before actual manufacture data
//    int j = 0;
//    for (int i = index_value+2; i < rawData.length(); i++){
//        p_result[j] = rawData[i];
//        j++;
//    }
    int j = 0;
    for (int i = 7; i < rawData.length(); i++){
        (*p_result)[j] = rawData[i];
        j++;
    }
    return true;
}

bool Processor::saveIQ(const QString macAddress, const QByteArray dataIQ){
    QFile file;

    QString fileName = tr("C:/Test AoA/IQ_%1.csv").arg(macAddress);
    file.setFileName(fileName);

    if (!file.open(QFile::ReadOnly | QFile::Append)){
        qDebug()<<"The file failed to be opened or created";
        return false;
    }

//    QByteArray dataIQBytes = dataIQ + "\n";
    qDebug()<<"Saving IQ Data....";
    file.write(dataIQ);
    qDebug()<<dataIQ;
    file.close();
}

Processor::~Processor(){

}

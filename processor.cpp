#include "processor.h"

#define COMMAND_SET                         "SET"
#define SET_RSSI_TYPE                       "RSSI"
#define SET_LOCATOR_PARAMS_TYPE             "LOCATOR"

#define COMMAND_DATA                        "DATA"

#define COMMAND_RECV_OK                     "OK"
#define COMMAND_RECV_INFO                   "INFO"
#define COMMAND_RECV_ERROR                  "ERROR"

#define CONVENIENT_METHOD                   "CONVENIENT"
#define AOA_METHOD                          "AOA"

#define DATA_COLLECT_LOCATOR                "LOCATOR"
#define DATA_COLLECT_TWO_LOCATOR            "TWO_LOCATOR"
#define DATA_COLLECT_CUMULATIVE             "CUMULATIVE"

#define DATA_DISTANCE                       "DISTANCE"

#define COORD_MEAN_TYPE                     "COORD_MEAN_TYPE"
#define COORD_ELEMENT_TYPE                  "COORD_ELEMENT_TYPE"
#define COORD_TWO_LOCATORS_ELEMENT_TYPE     "COORD_TWO_LOCATORS_TYPE"

#define ANGLES_AOA                          "ANGLES"
#define COORD_AOA                           "COORD"

#define FLOATING_POINT_PRECISION            3
#define NUMBER_STRING(num)               (QString::number(num, 'f', FLOATING_POINT_PRECISION))

#define RETURN_COORD_STRING(coord)              (coord == INVALID_COORDINATES ? INVALID_STRING : NUMBER_STRING(coord))

#define DATA_FORMAT_TO_SENT(cmd, spk, counter, tagId, mac, x, y)                 (tr("%1#%2#%3#%4#%5#%6#%7")    \
                                                                                    .arg(cmd)       \
                                                                                    .arg(spk)       \
                                                                                    .arg(counter)   \
                                                                                    .arg(tagId)     \
                                                                                    .arg(mac)       \
                                                                                    .arg(NUMBER_STRING(x)) \
                                                                                    .arg(NUMBER_STRING(y)))
#define DATA_FORMAT_TO_SENT_INVALID_XY(cmd, spk, counter, tagId, mac)           (tr("%1#%2#%3#%4#%5#%6#%7")    \
                                                                                .arg(cmd)       \
                                                                                .arg(spk)       \
                                                                                .arg(counter)   \
                                                                                .arg(tagId)     \
                                                                                .arg(mac)       \
                                                                                .arg("nan")     \
                                                                                .arg("nan"))

#define API_CMD_DAT                         "DAT"
#define API_CMD_CHG                         "CHG"
#define API_CMD_DON                         "DON"

//#define COORD_AOA_TWO_LOCATORS_ELEMENT_TYPE "COORD_TWO_LOCATORS_TYPE"
//#define COORD_AOA_MEAN                      "COORD_MEAN"

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
//    QString wantedMac = tr("DCC7CD766E3A");
//    QString wantedMac2 = tr("E985AED59234");
    QString dataToLocationProcessor = QString();//tr("%1 ").arg(COMMAND_DATA);
    File file;
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

        QString mac = dataElementObject.value("mac").toString().toUpper();

        if (!deviceDataBuffer.contains(mac))
        {
            qDebug()<< tr("The mac %1 isn't registered yet").arg(mac);
            continue;
        }

        qDebug()<<"iq------------";
        int locator_idx = dataElementObject.value("no").toInt();
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


        file.saveIQ(mac, locator_idx, iqString);
        file.saveInstantaneousRSSI(QString::number(rssi), mac, locator_idx);

        iqString[iqString.length()-1] = ' ';
        QByteArray elementData;
        elementData += tr("%1 %2 %3 %4 ").arg(frequency).arg(rssi).arg(mac).arg(locator_idx).toUtf8();
        elementData += iqString;

        qDebug()<<"element data to location processor" << elementData;

        dataToLocationProcessor += elementData;

        qDebug() << frequency << iq << rssi << mac << iqString;
//        if (!Common::getDeviceIds().contains(mac, Qt::CaseInsensitive)) {

//        qDebug()<<"MACCCCCCCCC wanted";

        QString stringedBytesData = dataElementObject.value("raw").toString();
        qDebug()<<"raw data"<<stringedBytesData;
        QByteArray data;

        if (!convertToBytes(stringedBytesData, &data)){
            qDebug()<<"Failed to convert";
            // here we continue the loops since maybe there are some other MAC address we want to inspect the data
            continue;
        }

        if (data.isEmpty()){
            qDebug()<<"The data is empty";
            continue;
        }

        QByteArray extractedData;
        if (!extractData(data, &extractedData)){
            qDebug()<<"Failed to extract data";
            return;
        }

        QString currentTimeString = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

//        extractedData += tr("#") + wantedMac;
//        extractedData += tr("#") + currentTimeString;


//        Q_EMIT sendData(extractedData);

        QString cmd;
        QString spk;
        QString counter;
        QString tagId;


//        qDebug()<<"Parsing...";
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
        tagId = tagId.toUpper();

        qDebug()<<"The cmd \n\n\n"<<cmd;
        qDebug()<<spk;
        qDebug()<<counter;
        qDebug()<<tagId;

        int spkInt = spk.toInt();
        int counterInt = counter.toInt();


        DeviceDataContainer deviceData = deviceDataBuffer.value(mac);

        QString changedTagId = tagId;
        int changedSPK = spkInt;
        int changedCounter = counterInt;
        QString changedCMD = cmd;

        if (cmd == API_CMD_DAT) {
            if (tagId != deviceDataBuffer[mac].tagId && (deviceDataBuffer[mac].tagId != INVALID_STRING)){
                  changedCMD = API_CMD_CHG;

            }
            else if (spkInt == deviceData.spk){
                if (counterInt == deviceData.counter) continue;

            }

        }

        else if (cmd == API_CMD_CHG){
            if (spkInt <= deviceData.spk || tagId == deviceData.tagId) continue;

        }
        else if (cmd == API_CMD_DON) {
            if (spkInt < deviceData.spk) continue;
            if (tagId != deviceData.tagId) continue;
            changedTagId = INVALID_STRING;
            changedCounter = 0;
            changedSPK = spkInt + 1;
        }

        if (deviceData.x == INVALID_COORDINATES || deviceData.y == INVALID_COORDINATES) {
            Q_EMIT sendData(DATA_FORMAT_TO_SENT_INVALID_XY(changedCMD, spk, counter, tagId, mac));
//            Q_EMIT sendHistory(mac, changedTagId, spk, counter, INVALID_STRING, INVALID_STRING, INVALID_STRING,
//                                                                INVALID_STRING, INVALID_STRING, INVALID_STRING,
//                                                                INVALID_STRING, INVALID_STRING, INVALID_STRING,
//                                                                INVALID_STRING, INVALID_STRING, INVALID_STRING,
//                                                                INVALID_STRING, INVALID_STRING, INVALID_STRING,
//                                                                currentTimeString);
        }
        else{
            Q_EMIT sendData(DATA_FORMAT_TO_SENT(changedCMD, spk, counter, tagId, mac, deviceData.x, deviceData.y));
//            Q_EMIT sendHistory(mac, changedTagId, spk, counter, NUMBER_STRING(deviceData.x), NUMBER_STRING(deviceData.y), NUMBER_STRING(deviceData.z),
//                                                                NUMBER_STRING(deviceData.x0), NUMBER_STRING(deviceData.y0), NUMBER_STRING(deviceData.z0),
//                                                                NUMBER_STRING(deviceData.x1), NUMBER_STRING(deviceData.y1), NUMBER_STRING(deviceData.z1),
//                                                                NUMBER_STRING(deviceData.x2), NUMBER_STRING(deviceData.y2), NUMBER_STRING(deviceData.z2),
//                                                                NUMBER_STRING(deviceData.x3), NUMBER_STRING(deviceData.y3), NUMBER_STRING(deviceData.z3),
//                                                                  currentTimeString);
        }

        Q_EMIT sendHistory(mac, changedTagId, spk, counter, RETURN_COORD_STRING(deviceData.x), RETURN_COORD_STRING(deviceData.y), RETURN_COORD_STRING(deviceData.z),
                                                            RETURN_COORD_STRING(deviceData.x0), RETURN_COORD_STRING(deviceData.y0), RETURN_COORD_STRING(deviceData.z0),
                                                            RETURN_COORD_STRING(deviceData.x1), RETURN_COORD_STRING(deviceData.y1), RETURN_COORD_STRING(deviceData.z1),
                                                            RETURN_COORD_STRING(deviceData.x2), RETURN_COORD_STRING(deviceData.y2), RETURN_COORD_STRING(deviceData.z2),
                                                            RETURN_COORD_STRING(deviceData.x3), RETURN_COORD_STRING(deviceData.y3), RETURN_COORD_STRING(deviceData.z3),
                                                              currentTimeString);

        deviceDataBuffer[mac].setDeviceParameter(changedSPK, changedCounter, changedTagId);

        qDebug() << "Sending data table";
        Q_EMIT sendDataTable(mac, changedTagId, spk, counter, currentTimeString);


    }
    if (dataToLocationProcessor.isEmpty()) return;
    dataToLocationProcessor.prepend(tr("%1 ").arg(COMMAND_DATA));

    QByteArray dataToLocationProcessorBytes = dataToLocationProcessor.toUtf8();
    dataToLocationProcessorBytes[dataToLocationProcessorBytes.length() - 1] = '\n';

    qDebug() << "saving calculator data";
    file.saveCalculatorData(dataToLocationProcessorBytes);

    qDebug() << "dataToLocationProcessorBytes" << dataToLocationProcessorBytes;
    locationCalculatorProcessor->write(dataToLocationProcessorBytes);
}

//void Processor::receiveTcpLocation(QByteArray tcpData){
//    qDebug()<<"Received TCP Data in file processor";
//    QJsonDocument dataJson = QJsonDocument::fromJson(tcpData);
//    if (dataJson.isEmpty()){
//        qDebug()<<"Error while parsing JSON or JSON data is empty";
//        qDebug()<<dataJson;
//        return;
//    }
//    QJsonArray dataJsonArray = dataJson.array();
//    qDebug()<<dataJsonArray;
//    QString wantedMac = tr("DCC7CD766E3A");
//    QString wantedMac2 = tr("E985AED59234");
//    for (auto dataIterator = dataJsonArray.begin(); dataIterator != dataJsonArray.end(); ++dataIterator){
//        QJsonValue dataElement = *dataIterator;

//        if (!dataElement.isObject()){
//            qDebug()<<tr("Data element %1 in index %2 is not object").arg(dataElement.toString()).arg(dataIterator.i);
//            continue;
//        }

//        QJsonObject dataElementObject = dataElement.toObject();
//        QString mac = dataElementObject.value("mac").toString();
//        if (dataElementObject.value("iq").isArray()) qDebug()<<"Not arrayyyyyyy";
//        qDebug()<<"The array-----------";
//        qDebug()<<dataElementObject.value("iq").toArray();
//        qDebug()<<"--------------------";
//        if (mac != wantedMac && mac != wantedMac2) {
//            qDebug()<<"Not wanted MAC";
//            continue;
//        }
//        qDebug()<<"MACCCCCCCCC wanted";

//        QString stringedBytesData = dataElementObject.value("raw").toString();
//        qDebug()<<"raw data"<<stringedBytesData;
//        QByteArray data;

//        if (data.isEmpty()){
//            qDebug()<<"The data is empty";
//            continue;
//        }

//        if (!convertToBytes(stringedBytesData, &data)){
//            qDebug()<<"Failed to convert";
//            // here we continue the loops since maybe there are some other MAC address we want to inspect the data
//            continue;
//        }
//        QByteArray extractedData;

//        if (!extractData(data, &extractedData)){
//            qDebug()<<"Failed to extract data";
//            return;
//        }

//        QString currentTimeString = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

////        extractedData += tr("#") + wantedMac;
////        extractedData += tr("#") + currentTimeString;


////        Q_EMIT sendData(extractedData);

//        QString cmd;
//        QString spk;
//        QString counter;
//        QString tagId;


//        qDebug()<<"Parsing...";
//        if (!parseData(extractedData, 0, &cmd)) {
//            qDebug()<<"parsing cmd data failed";
//            return;
//        }

//        if (!parseData(extractedData, 1, &spk)) {
//            qDebug()<<"parsing spk data failed";
//            return;
//        }

//        if (!parseData(extractedData, 2, &counter)){
//            qDebug()<<"parsing counter data failed";
//            return;
//        }\
//        if (!parseData(extractedData, 3, &tagId)) {
//            qDebug()<<"parsing tag data failed";
//            return;
//        }
//        // the tag id sent by G2 gateway is in lowercase characters, but we want to be uppercase characters
//        tagId = tagId.toUpper();

//        qDebug()<<"The cmd \n\n\n"<<cmd;
//        qDebug()<<spk;
//        qDebug()<<counter;
//        qDebug()<<tagId;

//        QString dataToAPI = cmd + "#" + spk + "#" + counter + "#" + tagId;
//        if (cmd == "DAT") {
//            Q_EMIT sendData(dataToAPI);
//            Q_EMIT sendDataTable(mac, tagId, spk, counter, currentTimeString);
//        }
//        else if (cmd == "DON") Q_EMIT sendDataTable(mac, "", spk, counter, currentTimeString);
//    }
//}

void Processor::started(){
    qDebug()<<"Processor started";
    locationCalculatorProcessor = new QProcess(this);

    connect(locationCalculatorProcessor, &QProcess::started, this, &Processor::locationCalculatorStarted);
    connect(locationCalculatorProcessor, &QProcess::errorOccurred, this, &Processor::locationCalculatorStarted);
    connect(locationCalculatorProcessor, &QProcess::readyRead, this, &Processor::readyRead);
    connect(locationCalculatorProcessor, static_cast<void (QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, &Processor::locationCalculatorFinished);
    connect(locationCalculatorProcessor, &QProcess::stateChanged, this, &Processor::stateChanged);

    connect(this, &Processor::destroyed, locationCalculatorProcessor, &QProcess::kill);
//    connect(this, &Processor::sendDataIQLocation, locationCalculatorProcessor, static_cast<void (QProcess::*)(const QByteArray &data)>(&QProcess::write));

//    arguments.append("haha");
//    arguments.append("222");
    QStringList arguments;

#ifdef DEBUG_MODE
    arguments += AOA_CALCULATOR_SCRIPT;
//    locationCalculatorProcessor->setArguments(arguments);
    locationCalculatorProcessor->start(PYTHON, arguments, QProcess::ReadWrite);
    qDebug()<<"Debug Mode "<<arguments;
#else
    QString filePath;
    filePath = QDir::currentPath() + AOA_CALCULATOR_PROCESS;
    locationCalculatorProcessor->start(filePath, arguments, QProcess::ReadWrite);
    qDebug()<<"Production Mode" << filePath;
#endif
}

void Processor::locationCalculatorStarted(){
//    QProcess *locationCalculatorProcessor = qobject_cast<QProcess *>(sender());
    qDebug()<<"Location calculator program started"<<locationCalculatorProcessor->state();
//    if (locationCalculatorProcessor->state() == QProcess::N)
}

void Processor::readyRead(){
    qDebug()<<__func__<<"called";
//    QProcess *locationCalculatorProcessor = qobject_cast<QProcess *>(sender());
    QByteArray protocolDataAoACalculator = locationCalculatorProcessor->readAll();
//    while (locationCalculatorProcessor->waitForReadyRead(10)) {
    protocolDataAoACalculator += locationCalculatorProcessor->readAll();
//    }
//    qDebug()<<protocolDataAoACalculator.remove(protocolDataAoACalculator.length() - 5, 4);

    QString protocolDataString = QString(protocolDataAoACalculator);

    QStringList protocolDatas = protocolDataString.split("\t\r\n");

    qDebug()<<protocolDatas;

    for (int i = 0; i < protocolDatas.length(); i++){
//        qDebug() << i << protocolDatas[i];
        QString protocolData = protocolDatas[i];

        QStringList elementsData = protocolData.split("\r\n");

        QString command = elementsData[0];

        qDebug()<<elementsData;

        if (command == "ERROR"){
             qDebug()<<"Error command ";
             qDebug()<<elementsData[1];
             return;
        }
        else if (command == "INFO"){
            qDebug()<<"Info command ";
            qDebug()<<elementsData[1];
        }
        else if (command == "OK"){
            qDebug()<<"OK command";
            QString dataMethod = elementsData[1];

            if (dataMethod == AOA_METHOD){
                qDebug() << "AoA";
                QString dataHeader = elementsData[2];

                if (dataHeader == COORD_AOA){
                    qDebug() << "Coord";
                    QString dataCollection = elementsData[3];
                    if (dataCollection == DATA_COLLECT_LOCATOR){
                        qDebug() << "Single locator Element Type";
                        QStringList data = elementsData[4].split(" ");

                        if (data.length() != 3) return;
                        QString mac = data[0];
                        int locator = data[1].toInt();
                        QStringList coordinate = data[2].split(",");
                        double x = coordinate[0].toDouble();
                        double y = coordinate[1].toDouble();
                        double z = coordinate[2].toDouble();
                        QByteArray coord;

                        coord = tr("%1,%2,%3\n").arg(NUMBER_STRING(x)).arg(NUMBER_STRING(y)).arg(NUMBER_STRING(z)).toUtf8();
                        File file;

                        file.saveAoACoordinatesPerLocator(mac, locator, coord);

#ifdef AOA_PRIORITY_OVER_CONVENIENT
#ifdef SINGLE_OVER_TWO_LOCATORS
                        sendLocation(mac, locator, x, y, z);
                        deviceDataBuffer[mac].setCoordinatesLocator(locator, x, y, z);
#endif
#endif

                    }
                    else if (dataCollection == DATA_COLLECT_TWO_LOCATOR){
                        qDebug() << "Two Locators Element Type";
                        QStringList data = elementsData[4].split(" ");

                        if (data.length() != 4) return;

                        QString mac = data[0];
                        QStringList locators = data[1].split(",");
                        int locator1 = locators[0].toInt();
                        int locator2 = locators[1].toInt();

                        QStringList coordinates1 = data[2].split(",");
                        double x1 = coordinates1[0].toDouble();
                        double y1 = coordinates1[1].toDouble();
                        double z1 = coordinates1[2].toDouble();

                        QStringList coordinates2 = data[3].split(",");
                        double x2 = coordinates2[0].toDouble();
                        double y2 = coordinates2[1].toDouble();
                        double z2 = coordinates2[2].toDouble();

                        QByteArray coordTwoLocators;
                        File file;

                        if (locator1 < locator2){
                            coordTwoLocators = tr("%1,%2,%3\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%4,%5,%6\n").arg(x1).arg(y1).arg(z1).arg(x2).arg(y2).arg(z2).toUtf8();
                            file.saveAoACoordinatesPerTwoLocators(mac, locator1, locator2, coordTwoLocators);
                        }
                        else{
                            coordTwoLocators = tr("%1,%2,%3\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%4,%5,%6\n").arg(x2).arg(y2).arg(z2).arg(x1).arg(y1).arg(z1).toUtf8();
                            file.saveAoACoordinatesPerTwoLocators(mac, locator2, locator1, coordTwoLocators);
                        }
#ifdef AOA_PRIORITY_OVER_CONVENIENT
#ifndef SINGLE_OVER_TWO_LOCATORS
                        sendLocation(mac, locator1, x1, y1, z1);
                        sendLocation(mac, locator2, x2, y2, z2);
                        deviceDataBuffer[mac].setCoordinatesLocator(locator1, x1, y1, z1);
                        deviceDataBuffer[mac].setCoordinatesLocator(locator2, x2, y2, z2);
#endif
#endif
                        qDebug() << "Current deviceDataBuffer" << deviceDataBuffer;
                    }
                    else if (dataCollection == DATA_COLLECT_CUMULATIVE){
                        qDebug() << "Cumulative";
                        QStringList data = elementsData[4].split(" ");
                        QString mac = data[0];
                        double x = data[1].toDouble();
                        double y = data[2].toDouble();
                        double z = data[3].toDouble();

                        QByteArray coordinates = tr("%1,%2,%3\n").arg(x).arg(y).arg(z).toUtf8();
                        File file;
                        file.saveAoACoordinatesCumulative(mac, coordinates);

                        deviceDataBuffer[mac].setCoordinates(x, y, z);

                        sendLocation(mac, LOCATOR_IDX_OF_CUMULATIVE_DATA, x, y, z);
                        qDebug() << "Current deviceDataBuffer" << deviceDataBuffer;

                        Q_EMIT updateCoord();
                    }
                    else {
                        qDebug() << "data type failed to recognized";
                    }
                }
                else if (dataHeader == ANGLES_AOA){
                    qDebug() << "Angles";
                    QStringList data = elementsData[3].split(" ");

                    QString mac = data[0];
                    int locator = data[1].toInt();
                    double angle_x = data[2].toDouble();
                    double angle_y = data[3].toDouble();

                    QByteArray angles = tr("%1,%2\n").arg(angle_x).arg(angle_y).toUtf8();
                    File file;
                    file.saveAoAAnglesPerLocator(mac, locator, angles);
                }
                else{
                    qDebug() << "AoA data header unrecognized";
                }
            }
            else if (dataMethod == CONVENIENT_METHOD){
                QString dataCollection = elementsData[2];

                if (dataCollection == DATA_COLLECT_LOCATOR){
                    qDebug() << "Locator";
                    if (elementsData.size() != 5) return;

                    QString dataType = elementsData[3];

                    QStringList locationData = elementsData[4].split(" ");
                    QString mac = locationData[0];
                    int locator = locationData[1].toInt();
                    double x = locationData[2].toDouble();
                    double y = locationData[3].toDouble();
                    double z = locationData[4].toDouble();

                    if (dataType == COORD_ELEMENT_TYPE){
                        qDebug()<<"Element coordinates";
                    }
                    else if (dataType == COORD_MEAN_TYPE){
                        qDebug()<<"Mean coordinates";
                    }
                    else {
                        qDebug()<<"Unrecognized data type";
                    }

                    qDebug()<<"Data From Calculator" << mac << locator << x << y << z;
#ifndef AOA_PRIORITY_OVER_CONVENIENT
                    sendLocation(mac, locator, x, y, z);
#endif

                    QByteArray coordinates = tr("%1,%2,%3\n").arg(x).arg(y).arg(z).toUtf8();
                    File file;
                    file.saveConvenientCoordinatesPerLocator(mac, locator, coordinates, dataType);
                }
                else if (dataCollection == DATA_COLLECT_CUMULATIVE){
                    qDebug()<< "Cumulative";

                    QStringList locationData = elementsData[3].split(" ");
                    QString mac = locationData[0];
                    double x = locationData[1].toDouble();
                    double y = locationData[2].toDouble();
                    double z = locationData[3].toDouble();

                    QByteArray coordinates = tr("%1,%2,%3\n").arg(x).arg(y).arg(z).toUtf8();
                    File file;
                    file.saveConvenientCoordinatesCumulative(mac, coordinates);
                }
                else{
                    qDebug()<<"Unrecognized data collection";
                }
            }
            else{
                qDebug() << "The method failed to be recognized";
            }

        }
        else if (command == "Traceback"){
            qDebug() << "Traceback";
            qDebug() << elementsData;
        }
        else {
            qDebug()<<"Command doesn't recognized";
            qDebug () << elementsData;
        }
    }

}

void Processor::receiveLastStateDevice(QStringList deviceIds,
                                        QStringList tagId,
                                        QStringList spk,
                                        QStringList counter,
                                        QStringList x, QStringList y, QStringList z){
    int numOfDevices = deviceIds.length();
    for(int i = 0; i < numOfDevices; i++){
        QString deviceId = deviceIds[i];
        // the buffer already contains the device id and last coordinates;
        if (deviceDataBuffer.contains(deviceId)) return;

        if (x[i] == "0" && y[i] == "0" && z[i] == "0"){
            x[i] = QString::number(INVALID_COORDINATES);
            y[i] = QString::number(INVALID_COORDINATES);
            z[i] = QString::number(INVALID_COORDINATES);
        }
        else{
            DeviceDataContainer container(spk[i].toInt(), counter[i].toInt(), tagId[i], x[i].toDouble(), y[i].toDouble(), z[i].toDouble());
        }
        DeviceDataContainer container(spk[i].toInt(), counter[i].toInt(), tagId[i], x[i].toDouble(), y[i].toDouble(), z[i].toDouble());
        deviceDataBuffer.insert(deviceId, container);
    }
}

void Processor::addDeviceId(const QString &deviceId){
    if (deviceDataBuffer.contains(deviceId)) return;
    DeviceDataContainer emptyContainer;
    deviceDataBuffer.insert(deviceId, emptyContainer);

    qDebug() << "current device data buffer" << deviceDataBuffer;
}

void Processor::receiveRSSIConfig(QString rssi1m, QString rssi2m){
    QByteArray setRssiString;
    setRssiString += tr("%1 %2 %3 %4").arg(COMMAND_SET).arg(SET_RSSI_TYPE).arg(rssi1m).arg(rssi2m).toUtf8() + '\n';

    qDebug()<<"RSSI config" << setRssiString;

    locationCalculatorProcessor->write(setRssiString);

    File file;
    file.saveRSSI(rssi1m, rssi2m);
}

void Processor::receiveLocatorParams(int ref,
                                     QString x1, QString y1, QString z1,
                                     QString x2, QString y2, QString z2,
                                     QString x3, QString y3, QString z3,
                                     QString x4, QString y4, QString z4){
    QByteArray setLocatorParams;
    setLocatorParams += tr("%1 %2 %3 %4,%5,%6 %7,%8,%9 %10,%11,%12 %13,%14,%15").arg(COMMAND_SET).arg(SET_LOCATOR_PARAMS_TYPE)
                                                                                .arg(ref)
                                                                                .arg(x1).arg(y1).arg(z1)
                                                                                .arg(x2).arg(y2).arg(z2)
                                                                                .arg(x3).arg(y3).arg(z3)
                                                                                .arg(x4).arg(y4).arg(z4).toUtf8() + '\n';

    qDebug() << "Locator parameters config" << setLocatorParams;

    locationCalculatorProcessor->write(setLocatorParams);

    File file;
    file.saveLocatorParams(ref, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4);
}

void Processor::errorOccured(QProcess::ProcessError error){
    qDebug()<<"Error opening calculator"<<error;
}

void Processor::locationCalculatorFinished(int exitCode, QProcess::ExitStatus exitStatus){
    qDebug()<<"Location calculator finished"<<exitCode<<exitStatus;
    qDebug()<<locationCalculatorProcessor->readAll();
}

void Processor::stateChanged(QProcess::ProcessState state){
    qDebug()<<"state Changed"<<state;
    if (state == QProcess::Running){
//        qDebug()<<"Sending iq data....";
//        QProcess *locationCalculatorProcessor = qobject_cast<QProcess *>(sender());
//        QByteArray data;
//        data = "2402 155,-34,22,155,-166,6,3,-166,161,-4,-22,151,-157,-43,36,-159,-78,142,-28,10,-104,131,130,-152,-140,88,-32,-2,-163,27,183,-67,-164,-4,-24,-27,-163,-56,188,69,-138,-99,0,-30,-100,-135,128,154,-54,-153,13,-30,-22,-162,43,199,44,-161,27,-18,98,-124,-90,178,118,-101,32,2,157,-64,-181,96,161,-20,21,18,166,32,-206,-26,151,58,7,26,118,110,-145,-127,78,145,-13,30,35,161,-63,-188,-9,158,-27,20,-66,159,49,-191,-100,123,-28,2,-139,86,151,-124,-153,54,-28,-15,-168,10,204,-27,-157,-42,-15,-31,-136,-91,176,89,-108,-124,-5,-30,-56,-148,92,183,-23,-167,19,-23,42,-161,-23,198,72,-151,29,-11,122,-117,-128,148,140,-73,26,11,160,-40,-190,61,160,17,22,21";
//        Q_EMIT sendDataIQLocation(data);
//        locationCalculatorProcessor->write(data);
    }
}

//void Processor::locationCalculatorFinished(int exitCode){
//    qDebug()<<"Location calculator finished"<<exitCode;
//}

QMap<QString, DeviceDataContainer> * Processor::getDeviceDataBuffer(){
    return &deviceDataBuffer;
}

int Processor::indexOfDeviceId(QString deviceId){
    QList<QString> deviceIdList = deviceDataBuffer.keys();

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

//        qDebug()<<"Char"<<byte;
        if (byte == '#') {
            slashCounter++;
        }

        // the stringed NFC ID is exist after the 3rd '#', hence we don't need to converted to bytes after that 3rd '#'
        bytes += byte;
        *p_result += byte;
        if (slashCounter == 3) {
            // the +2 here to jump to the index where the stringed NFC ID started, since every bytes in stringedbytes occupy 2 character.
            for (int j = i+2; ; j++){
                if (j >= stringedBytesLength) break;

                char character = byteArrayedBytes[j];
                // in the scenario sending data with CTE to G2 minew gateway, the bluetooth device should emit fixed amount 31 bytes data, and the device only wanted to sending data less than 31 bytes, therefore after the NFC ID bytes, the bluetooth device append the character '#' and series of 0's
                if (character == '#') break;
                bytes += character;
                *p_result += character;
            }
            break;
        }
    }

    if (slashCounter < 3) return false;
    qDebug()<<bytes;
    return true;
}

bool Processor::parseData(QByteArray data, int dataRegionNumber, QString *p_result){
//    qDebug()<<__func__<<data;
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
//    int slashCounter = 0;
    int end = rawData.length()-1;
    for (int i = rawData.length()-1; i >= 0; i -= 2){
        QByteArray twoBytes;
        twoBytes += rawData[i-1];
        twoBytes += rawData[i];
//        qDebug()<<"Two bytes"<<twoBytes;
        // the stringedBytes "23" representing '#'
        if (twoBytes == "23")
        {
            i -= 2;
            end = i;
            break;
        }
    }

    for (int i = 11; i <= end; i++){
        (*p_result)[j] = rawData[i];

//        QByteArray nextTwoBytes;
//        nextTwoBytes += rawData.at(i + 1);
//        nextTwoBytes += rawData.at(i + 2);

//        if (nextTwoBytes == "23") slashCounter++;
//        if (slashCounter == 4) break;
        j++;
    }
    return true;
}



Processor::~Processor(){
    locationCalculatorProcessor->kill();
}

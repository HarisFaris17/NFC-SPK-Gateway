#include "file.h"

File::File(QObject *parent)
    :QFile(parent)
{

}

File::~File(){

}

void File::parseFile(QString &ipAddress,
                     QString &TCPPort,
                     QString &host,
                     QString &databasePort,
                     QString &databaseName,
                     QString &userName,
                     QString &password
){
    setFileName(SETTING_FILE);
    open(ReadOnly);

    if (!isOpen()) {
        qDebug("The file failed to be opened");
        return;
    }

    QByteArray data = readAll();
    int index = 0; // starts from index 0
    bool isSuccess = true;

    ipAddress = parseData(data, index, isSuccess);
    if (!isSuccess) qDebug()<<"Host failed to be parsed";
    TCPPort = parseData(data, index, isSuccess);
    if (!isSuccess) qDebug()<<"Host failed to be parsed";
    host = parseData(data, index, isSuccess);
    if (!isSuccess) qDebug()<<"Host failed to be parsed";
    databasePort = parseData(data, index, isSuccess);
    if (!isSuccess) qDebug()<<"Host failed to be parsed";
    databaseName = parseData(data, index, isSuccess);
    if (!isSuccess) qDebug()<<"Host failed to be parsed";
    userName = parseData(data, index, isSuccess);
    if (!isSuccess) qDebug()<<"Host failed to be parsed";
    password = parseData(data, index, isSuccess);
    if (!isSuccess) qDebug()<<"Host failed to be parsed";

    close();
}

void File::parseLocatorParams(QString &x0, QString &y0, QString &z0,
                              QString &x1, QString &y1, QString &z1,
                              QString &x2, QString &y2, QString &z2,
                              QString &x3, QString &y3, QString &z3,
                              QString &x4, QString &y4, QString &z4,
                              QString &x5, QString &y5, QString &z5,
                              QString &x6, QString &y6, QString &z6,
                              QString &x7, QString &y7, QString &z7){

    setFileName(LOCATOR_PARAMS_FILE);
    open(ReadOnly);

    if(!isOpen()){
        qDebug() << "The locator parameters file failed to be opened";
        return;
    }

    QByteArray savedBytes = readAll();
    qDebug()<<"Setting locator init"<<savedBytes;

    QList<QByteArray> locatorsParams = savedBytes.split('\n');
    qDebug()<<locatorsParams;

//    ref = QString(locatorsParams[0]);
#define ASSIGN_LOCATOR_PARAMS(locator_idx)          QList<QByteArray> locator## locator_idx ##Params = locatorsParams[locator_idx].split(','); \
                                                    x##locator_idx = locator## locator_idx ##Params[0]; \
                                                    y##locator_idx = locator## locator_idx ##Params[1]; \
                                                    z##locator_idx = locator## locator_idx ##Params[2]; \
//                                                    qDebug() << tr("%1").arg(x##locator_idx);

    ASSIGN_LOCATOR_PARAMS(0)
    ASSIGN_LOCATOR_PARAMS(1)
    ASSIGN_LOCATOR_PARAMS(2)
    ASSIGN_LOCATOR_PARAMS(3)
    ASSIGN_LOCATOR_PARAMS(4)
    ASSIGN_LOCATOR_PARAMS(5)
    ASSIGN_LOCATOR_PARAMS(6)
    ASSIGN_LOCATOR_PARAMS(7)

//    qDebug() << x0 << x1 << x2 << x3 << x4 << x5 << x6;
//    QList<QByteArray> locator1Params = locatorsParams[1].split(',');
//    x1 = locator1Params[0];
//    y1 = locator1Params[1];
//    z1 = locator1Params[2];

//    QList<QByteArray> locator2Params = locatorsParams[2].split(',');
//    x2 = locator2Params[0];
//    y2 = locator2Params[1];
//    z2 = locator2Params[2];

//    QList<QByteArray> locator3Params = locatorsParams[3].split(',');
//    x3 = locator3Params[0];
//    y3 = locator3Params[1];
//    z3 = locator3Params[2];

//    QList<QByteArray> locator4Params = locatorsParams[4].split(',');
//    x4 = locator4Params[0];
//    y4 = locator4Params[1];
//    z4 = locator4Params[2];

//    savedBytes += ref.toUtf8() + '\n';
//    savedBytes += x1.toUtf8() + ',' + y1.toUtf8() + ',' + z1.toUtf8() + '\n';
//    savedBytes += x2.toUtf8() + ',' + y2.toUtf8() + ',' + z2.toUtf8() + '\n';
//    savedBytes += x3.toUtf8() + ',' + y3.toUtf8() + ',' + z3.toUtf8() + '\n';
//    savedBytes += x4.toUtf8() + ',' + y4.toUtf8() + ',' + z4.toUtf8() + '\n';

//    write(savedBytes);
    close();
}

void File::parseRSSI(QString &RSSI1m, QString &RSSI2m){
    setFileName(RSSI_FILE);
    open(ReadOnly);

    if (!isOpen()){
        qDebug() << "The RSSI file failed to be opened";
        return;
    }

    QByteArray savedBytes = readAll();
    qDebug() << "RSSI file " << savedBytes;

    QList<QByteArray> RSSIs = savedBytes.split('\n');
    RSSI1m = RSSIs[0];
    RSSI2m = RSSIs[1];
}

void File::saveDatabaseConfig(QString host, QString databasePort, QString databaseName, QString userName, QString password){
    QString ipAddressTCPServer;
    QString portTCPServer;
    QString dummyContainer;

    parseFile(ipAddressTCPServer, portTCPServer, dummyContainer, dummyContainer, dummyContainer, dummyContainer, dummyContainer);

    saveFile(ipAddressTCPServer, portTCPServer, host, databasePort, databaseName, userName, password);
}

void File::saveTCPServerConfig(QString ipAddress, QString TCPPort){
    QString host;
    QString databasePort;
    QString databaseName;
    QString userName;
    QString password;
    QString dummyContainer;

    parseFile(dummyContainer, dummyContainer, host, databasePort, databaseName, userName, password);
    qDebug()<<"IP Address"<<ipAddress<<"Port"<<TCPPort;

    saveFile(ipAddress, TCPPort, host, databasePort, databaseName, userName, password);
}

bool File::saveFile(QString ipAddress,
                      QString TCPPort,
                      QString host,
                      QString databasePort,
                      QString databaseName,
                      QString userName,
                      QString password){

    QByteArray savedString;
    savedString += ipAddress.toUtf8() + "#";
    savedString += TCPPort.toUtf8() + "#";
    savedString += host.toUtf8() + "#";
    savedString += databasePort.toUtf8() + "#";
    savedString += databaseName.toUtf8() + "#";
    savedString += userName.toUtf8() + "#";
    savedString += password.toUtf8();

    setFileName(SETTING_FILE);
    open(WriteOnly);
    if (!isOpen()) return false;

    write(savedString);
    return true;
}

bool File::saveIQ(const QString macAddress, const int &locator, const QByteArray dataIQ){

    QString fileName = QDir::currentPath() + tr(AOA_IQ_FILE).arg(macAddress).arg(locator);
    setFileName(fileName);

    if (!open(QFile::ReadOnly | QFile::Append)){
        qDebug()<<"The file failed to be opened or created" << fileName;
        return false;
    }

//    QByteArray dataIQBytes = dataIQ + "\n";
    qDebug()<<"Saving IQ Data....";
    write(dataIQ);
    qDebug()<<dataIQ;
    close();

    return true;
}

bool File::saveInstantaneousRSSI(QString RSSI, QString mac, const int &locator){
    QString fileName = QDir::currentPath() + tr(INSTANTANEOUS_RSSI_FILE).arg(mac).arg(locator);
    setFileName(fileName);

    if (!open(QFile::ReadOnly | QFile::Append)){
        qDebug()<<"The file failed to be opened or created" << INSTANTANEOUS_RSSI_FILE;
        return false;
    }

    qDebug()<<"Saving Instantaneous RSSI....";
    write(RSSI.toUtf8() + ',');
    qDebug()<<RSSI;
    close();

    return true;
}

//bool File::parseTCPServerInfo(){
//    if (isOpen()) return false;

//    bool result = true;


//    return retult;
//}

bool File::saveConvenientCoordinatesPerLocator(const QString &macAddress, const int &locator, const QByteArray &xyz, const QString &dataType){
    QString fileName = QDir::currentPath() + tr(CONVENIENT_COORDINATES_PER_LOCATOR_FILE).arg(locator).arg(macAddress).arg(dataType);
    setFileName(fileName);

    if (!open(QFile::ReadOnly | QFile::Append)){
        qDebug()<<"The file failed to be opened or created" << fileName;
        return false;
    }

    qDebug()<<"Saving Coordinates per locator Data....";
    write(xyz);
    qDebug()<<xyz;
    close();

    return true;
}

bool File::saveConvenientCoordinatesCumulative(const QString &macAddress, const QByteArray &xyz){
    QString fileName = QDir::currentPath() + tr(CONVENIENT_COORDINATES_CUMULATIVE_FILE).arg(macAddress);
    setFileName(fileName);

    if (!open(QFile::ReadOnly | QFile::Append)){
        qDebug()<<"The file failed to be opened or created" << fileName;
        return false;
    }

    qDebug()<<"Saving Coordinates from cumulative data and convenient method....";
    write(xyz);
    qDebug()<<xyz;
    close();

    return true;
}

bool File::saveAoAAnglesPerLocator(const QString &macAddress, const int &locator, const QByteArray &angles){
    QString fileName = QDir::currentPath() + tr(AOA_ANGLES_FILE).arg(locator).arg(macAddress);
    setFileName(fileName);

    if (!open(QFile::ReadOnly | QFile::Append)){
        qDebug()<<"The file failed to be opened or created" << fileName;
        return false;
    }

    qDebug()<<"Saving Angle Data....";
    write(angles);
    qDebug()<<angles;
    close();

    return true;
}

bool File::saveAoACoordinatesPerTwoLocators(const QString &macAddress, const int &locator1, const int &locator2, const QByteArray &xyz){
    QString fileName = QDir::currentPath() + tr(AOA_COORD_TWO_lOCATORS_ELEMENTS_FILE).arg(locator1).arg(locator2).arg(macAddress);
    setFileName(fileName);

    if (!open(QFile::ReadOnly | QFile::Append)){
        qDebug()<<"The file failed to be opened or created" << fileName;
        return false;
    }

    qDebug()<<"Saving coordinates two locators Data....";
    write(xyz);
    qDebug()<<xyz;
    close();

    return true;
}

bool File::saveAoACoordinatesPerLocator(const QString &macAddress, const int &locator, const QByteArray &xyz)
{
    QString fileName = QDir::currentPath() + tr(AOA_COORD_LOCATOR_ELEMENTS_FILE).arg(locator).arg(macAddress);
    setFileName(fileName);

    if (!open(QFile::ReadOnly | QFile::Append)){
        qDebug()<<"The file failed to be opened or created" << fileName;
        return false;
    }

    qDebug()<<"Saving Coordinates single locator Data....";
    write(xyz);
    qDebug()<<xyz;
    close();

    return true;
}

bool File::saveAoACoordinatesCumulative(const QString &macAddress, const QByteArray &xyz){
    QString fileName = QDir::currentPath() + tr(AOA_COORD_CUMULATIVE_FILE).arg(macAddress);
    setFileName(fileName);

    if (!open(QFile::ReadOnly | QFile::Append)){
        qDebug()<<"The file failed to be opened or created" << fileName;
        return false;
    }

    qDebug()<<"Saving AoA Cumulative Data....";
    write(xyz);
    qDebug()<<xyz;
    close();

    return true;
}

bool File::saveLocatorParams(QString x0, QString y0, QString z0,
                             QString x1, QString y1, QString z1,
                             QString x2, QString y2, QString z2,
                             QString x3, QString y3, QString z3,
                             QString x4, QString y4, QString z4,
                             QString x5, QString y5, QString z5,
                             QString x6, QString y6, QString z6,
                             QString x7, QString y7, QString z7){
//    QString fileName = tr();
    setFileName(LOCATOR_PARAMS_FILE);

    open(QFile::WriteOnly);
    if(!isOpen()){
        qDebug()<<"The locator parameters file failed to be opened";
        return false;
    }

    qDebug()<<"Saving locator parameters configuration";

    QByteArray savedString;
#define ADD_LOCATOR_COORDINATE(locator_idx)    savedString += x ## locator_idx + ',' + y ## locator_idx + ',' + z1
#define ADD_NEW_LINE  + '\n';
//    savedString += x1 + ',' + y1 + ',' + z1 + '\n';
//    savedString += x2 + ',' + y2 + ',' + z2 + '\n';
//    savedString += x3 + ',' + y3 + ',' + z3 + '\n';
    ADD_LOCATOR_COORDINATE(0) ADD_NEW_LINE
    ADD_LOCATOR_COORDINATE(1) ADD_NEW_LINE
    ADD_LOCATOR_COORDINATE(2) ADD_NEW_LINE
    ADD_LOCATOR_COORDINATE(3) ADD_NEW_LINE
    ADD_LOCATOR_COORDINATE(4) ADD_NEW_LINE
    ADD_LOCATOR_COORDINATE(5) ADD_NEW_LINE
    ADD_LOCATOR_COORDINATE(6) ADD_NEW_LINE
    ADD_LOCATOR_COORDINATE(7);
//    savedString += x4 + ',' + y4 + ',' + z4;

    write(savedString);
    qDebug()<<savedString;
    close();

    return true;
}

bool File::saveRSSI(QString &RSSI1m, QString &RSSI2m){
    QByteArray savedString;
    savedString = RSSI1m.toUtf8() + '\n' + RSSI2m.toUtf8();

    setFileName(RSSI_FILE);
    open(WriteOnly);

    if (!isOpen()){
        qDebug() << "RSSI configuration failed to be saved";
        return false;
    }

    write(savedString);
    return true;
}

bool File::saveCalculatorData(const QByteArray &data){
    QString fileName = QDir::currentPath() + tr(CALCULATOR_DATA);
    setFileName(fileName);

    open(QFile::ReadOnly | QFile::Append);
    if (!isOpen()) {
        qDebug() << "The file failed to be opened " << fileName;
        return false;
    }

    qDebug () << "Saving calculator data";
    write(data);
    qDebug() << data;
    close();

}

QByteArray File::parseData(QByteArray &data, int &index, bool &isSuccess){
    isSuccess = true;

    int length = data.length();

    // representing the empty password
    if (index == length) {
        return "";
    }
    else if (index > length){
        isSuccess = false;
        return "";
    }

    QByteArray parsedData;
    int initIndex = index;

    for (; index < length; index++){
        if (data.at(index) == '#') break;
        parsedData.append(data.at(index));
    }

    if (initIndex == index){
        return "";
    }
    else if (parsedData.isEmpty()){
        isSuccess = false;
    }


    // index becomes the next data that wanted to be parsed and not the '#'
    index++;
    return parsedData;
}

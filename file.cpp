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

bool File::saveIQ(const QString macAddress, const QByteArray dataIQ){
    QFile file;

    QString fileName = QDir::currentPath() + tr(AOA_IQ_FILE).arg(macAddress);
    file.setFileName(fileName);

    if (!file.open(QFile::ReadOnly | QFile::Append)){
        qDebug()<<"The file failed to be opened or created" << fileName;
        return false;
    }

//    QByteArray dataIQBytes = dataIQ + "\n";
    qDebug()<<"Saving IQ Data....";
    file.write(dataIQ);
    qDebug()<<dataIQ;
    file.close();
}

//bool File::parseTCPServerInfo(){
//    if (isOpen()) return false;

//    bool result = true;


//    return retult;
//}

bool File::saveCoordinates(const QString &macAddress, const int &locator, const QByteArray &xyz){
    QFile file;

    QString fileName = QDir::currentPath() + tr(AOA_COORDINATES_FILE).arg(locator).arg(macAddress);
    file.setFileName(fileName);

    if (!file.open(QFile::ReadOnly | QFile::Append)){
        qDebug()<<"The file failed to be opened or created" << fileName;
        return false;
    }

    qDebug()<<"Saving Coordinates Data....";
    file.write(xyz);
    qDebug()<<xyz;
    file.close();
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

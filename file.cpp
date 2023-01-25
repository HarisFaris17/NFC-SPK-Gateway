#include "file.h"

File::File()
{
    setFileName("setting.ini");
    open(ReadWrite);
}

File::~File(){
    if (isOpen()) close();
}

void File::parseFile(QString &ipAddress,
                     QString &TCPPort,
                     QString &host,
                     QString &databasePort,
                     QString &databaseName,
                     QString &userName,
                     QString &password
){
    if (!isOpen()) {
        qDebug("The file failed to be opened");
        return;
    }
//    bool result = true;

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


//    return result;
}

//bool File::parseTCPServerInfo(){
//    if (isOpen()) return false;

//    bool result = true;


//    return retult;
//}

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

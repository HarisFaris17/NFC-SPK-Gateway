#include "database.h"

QString dbConnectionName("default");

Database::Database()
{

}

Database::~Database(){
    sql.clear();
    if (db.isOpen())db.close();
    QSqlDatabase::removeDatabase(dbConnectionName);
}

void Database::run(){
    qDebug()<<"Database starting connections...";

    sql = QSqlQuery(db);

    if (db.isOpen()) {\
        qDebug()<<"Database already listening";
        return;
    }

    db.open();
    if (!db.isOpen()){
        qDebug()<<"Failed to connect to database";
        Q_EMIT databaseConnectionResult(false);
        Q_EMIT databaseDisconnected();
        return;
    }

    qDebug()<<"Database connected";
    Q_EMIT databaseConnectionResult(true);
}

void Database::config(const QString ipAddress,
                       const QString port,
                       const QString databaseName,
                       const QString userName,
                       const QString password){
    db = QSqlDatabase::addDatabase("QMYSQL", dbConnectionName);
    db.setHostName(ipAddress);
    db.setPort(port.toInt());
    db.setDatabaseName(databaseName);
    db.setUserName(userName);
    db.setPassword(password);
}

void Database::disconnectDatabase(){
    qDebug()<<"Disconnecting database...";
    if(db.isOpen()) db.close();
    Q_EMIT databaseDisconnected();
}

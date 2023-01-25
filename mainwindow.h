#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tcpserver2.h"
#include "processor.h"
#include "database.h"
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QThread>
#include <QTextBrowser>
#include <QTimer>
#include <QVariantMap>
#include <QJsonObject>
#include <QByteArray>
#include <QTableWidget>
#include <QTableWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public Q_SLOTS:
    void connectDisconnectTCP();
    void listenResult(bool isSuccess);
    void unlistenedTcp();
//    void receiveData(QJsonObject data);

    void timerTcpTimeout();
    void timerDatabaseTimeout();

    void receiveDataConsole(QByteArray data);
    void receiveDataTable(QString deviceId, QString tagId, QString spk, QString counter, QString dateTime);

    void connectDisconnectDatabase();
    void databaseConnectionResult(bool isSuccess);
    void databaseDisconnected();




Q_SIGNALS:
    void listen(const QString &ipAddress,const QString &port);
    void test();
    void unlistenTCP();
    void deleteTimerTCP();

    void disconnectDatabase();
    void deleteTimerDatabase();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLineEdit *ipAddressTCPLineEdit;
    QLineEdit *portTCPLineEdit;
    QLineEdit *hostDatabaseLineEdit;
    QLineEdit *portDatabaseLineEdit;
    QLineEdit *databaseNameDatabaseLineEdit;
    QLineEdit *usernameDatabaseLineEdit;
    QLineEdit *passwordDatabaseLineEdit;
    QPushButton *connectTCPPushButton;
    QPushButton *connectDatabasePushButton;
    QTextBrowser *console;
    QTableWidget *tableWidget;
    QTableWidgetItem *protoTableWidgetItem;

//    QPushButton *unlistenPushButton;
//    QTextBrowser *serialConsole;

//    QTimer *timerTcp = NULL;
    Processor *processor = NULL;
    Database *database = NULL;

    typedef enum{
        WaitingTCP,
        TCPStop,
        TCPListening
    }StateTcp;

    typedef enum{
        WaitingDatabase,
        DatabaseDisconnected,
        DatabaseConnected
    }StateDatabase;

    typedef enum{
        DEVICE_ID = 0,
        TAG_ID,
        SPK,
        COUNTER,
        LAST_UPDATE
    }ColumnNumber;

    StateTcp stateTcp = TCPStop;
    StateDatabase stateDatabase = DatabaseDisconnected;

//    TCPServer tcpServer;
//    TCPServer *tcpServer = NULL;
//    QThread *thread1;
private:
    void changeDisplayStateTCP();
    void changeDisplayDatabase();
};

#endif // MAINWINDOW_H

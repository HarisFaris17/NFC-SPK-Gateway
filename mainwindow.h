#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tcpserver2.h"
#include "processor.h"
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

    void timerTimeout();

    void receiveDataConsole(QByteArray data);
    void receiveDataTable(QString deviceId, QString tagId, QString spk, QString counter, QString dateTime);



Q_SIGNALS:
    void listen(const QString &ipAddress,const QString &port);
    void test();
    void unlistenTCP();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLineEdit *ipAddressLineEdit;
    QLineEdit *portLineEdit;
    QPushButton *connectPushButton;
    QTextBrowser *console;
    QTableWidget *tableWidget;
    QTableWidgetItem *protoTableWidgetItem;
//    QPushButton *unlistenPushButton;
//    QTextBrowser *serialConsole;

    QTimer *timer = NULL;
    Processor *processor = NULL;

    typedef enum{
        WAITING,
        STOP,
        LISTENING
    }StateTcp;

    typedef enum{
        DEVICE_ID = 0,
        TAG_ID,
        SPK,
        COUNTER,
        LAST_UPDATE
    }ColumnNumber;

    StateTcp stateTcp = STOP;
//    TCPServer tcpServer;
//    TCPServer *tcpServer = NULL;
//    QThread *thread1;
private:
    void changeDisplayStateTCP();
};

#endif // MAINWINDOW_H

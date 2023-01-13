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

    void receiveData(QByteArray data);



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
//    QPushButton *unlistenPushButton;
//    QTextBrowser *serialConsole;

    QTimer *timer = NULL;
    Processor *processor = NULL;

    typedef enum{
        WAITING,
        STOP,
        LISTENING
    }StateTcp;

    StateTcp stateTcp = STOP;
//    TCPServer tcpServer;
//    TCPServer *tcpServer = NULL;
//    QThread *thread1;
private:
    void changeDisplayStateTCP();
};

#endif // MAINWINDOW_H

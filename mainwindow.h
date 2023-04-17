#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tcpserver2.h"
#include "processor.h"
#include "common.h"
#include "file.h"
#include "settinglocator.h"
#include "database.h"
#include "adddevice.h"
#include "andonprocessor.h"
#include "coordinatesystem.h"
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
#include <QList>
#include <QCloseEvent>

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

    void timerTcpTimeout();
    void timerDatabaseTimeout();

    void receiveDataConsole(QString data);
    void receiveDataTableCounting(QString deviceId, QString tagId, QString spk, QString counter, QString dateTime);
    void receiveLocation(QString deviceId, int locator, double x, double y, double z);
    void receiveCumulativeLocation(QString deviceId,
                                   double x, double y, double z
                                   /*double x0, double y0, double z0,
                                   double x1, double y1, double z1,
                                   double x2, double y2, double z2,
                                   double x3, double y3, double z3*/);
    void receiveLastStateDevice(QStringList deviceIds,
                                QStringList tagId,
                                QStringList spk,
                                QStringList counter,
                                QStringList x, QStringList y, QStringList z,
                                QStringList locator1X, QStringList locator1Y, QStringList locator1Z,
                                QStringList locator2X, QStringList locator2Y, QStringList locator2Z,
                                QStringList locator3X, QStringList locator3Y, QStringList locator3Z,
                                QStringList locator4X, QStringList locator4Y, QStringList locator4Z,
                                QStringList lastUpdate);
    void receiveHistory(const QString &deviceId,
                        const QString &tagId,
                        const QString &spk,
                        const QString &counter,
                        const QString &x, const QString &y, const QString &z,
                        const QString &x0, const QString &y0, const QString &z0,
                        const QString &x1, const QString &y1, const QString &z1,
                        const QString &x2, const QString &y2, const QString &z2,
                        const QString &x3, const QString &y3, const QString &z3,
                        const QString &dateTime);

    void addDeviceId(const QString &mac);

    void connectDisconnectDatabase();
    void databaseConnectionResult(bool isSuccess);
    void databaseDisconnected();
    void tableCreateResult(bool isDeviceTableCreated, bool isDataTableCreated, bool isDeviceLocationTableCreated, bool isDataLocationTableCreated);


    void saveGatewayMACs();

Q_SIGNALS:
    void listen(const QString &ipAddress,const QString &port);
    void test();
    void unlistenTCP();
    void deleteTimerTCP();

    void disconnectDatabase();
    void deleteTimerDatabase();

    void sendGatewayMAC(const QString &gateway1MAC, const QString &gateway2MAC);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SettingLocator *settingLocatorUi = NULL;
    AddDevice *addDeviceUi = NULL;
    CoordinateSystem *coordinateSystem = NULL;

    QLineEdit *ipAddressTCPLineEdit;
    QLineEdit *portTCPLineEdit;
    QLineEdit *hostDatabaseLineEdit;
    QLineEdit *portDatabaseLineEdit;
    QLineEdit *databaseNameDatabaseLineEdit;
    QLineEdit *usernameDatabaseLineEdit;
    QLineEdit *passwordDatabaseLineEdit;
    QLineEdit *gateway1MACLineEdit;
    QLineEdit *gateway2MACLineEdit;
    QPushButton *connectTCPPushButton;
    QPushButton *connectDatabasePushButton;
    QPushButton *addDevicePushButton;
    QPushButton *settingPushButton;
    QPushButton *coordinatesPushButton;
    QPushButton *saveGatewayMACPushButton;
    QTextBrowser *console;

    QTableWidget *tableWidgetCounting;
    QTableWidget *tableWidgetHistoryCounting;
//    QTableWidget *tableWidgetLocation;
    QTableWidgetItem *protoTableWidgetItem;

    Processor *processor = NULL;
    Database *database = NULL;
    AndonProcessor *andonProcessor = NULL;

    QList<QString> deviceIds;

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
        X,
        Y,
        Z,
        X0,
        Y0,
        Z0,
        X1,
        Y1,
        Z1,
        X2,
        Y2,
        Z2,
        X3,
        Y3,
        Z3,
        LAST_UPDATE
    }ColumnNumber;

    typedef enum{
        DEVICE_ID_HISTORY = 0,
        TAG_ID_HISTORY,
        SPK_HISTORY,
        COUNTER_HISTORY,
        X_HISTORY,
        Y_HISTORY,
        Z_HISTORY,
        X0_HISTORY,
        Y0_HISTORY,
        Z0_HISTORY,
        X1_HISTORY,
        Y1_HISTORY,
        Z1_HISTORY,
        X2_HISTORY,
        Y2_HISTORY,
        Z2_HISTORY,
        X3_HISTORY,
        Y3_HISTORY,
        Z3_HISTORY,
        TIMESTAMP__HISTORY
    }ColumnNumberHistory;

#define AR_HEADER_OFFSET(locator) (X0 + 3 * locator)
#define AR_HEADER_OFFSET_HISTORY(locator) (X0_HISTORY + 3 * locator)

    StateTcp stateTcp = TCPStop;
    StateDatabase stateDatabase = DatabaseDisconnected;

//    bool isPresentAddDeviceUi = false;
//    bool isPresentSettingLocator = false;

private Q_SLOTS:
    void showSettingLocator();
    void showAddDevice();
    void showCoordinates();

    void resetSettingLocator();
    void resetAddDevice();
    void resetCoordinate();



private:
    void changeDisplayStateTCP();
    void changeDisplayDatabase();
    void changeRowItem(int row,
                       QString deviceId,
                       QString tagId,
                       QString spk,
                       QString counter,
                       QString x, QString y, QString z,
                       QString locator1X, QString locator1Y, QString locator1Z,
                       QString locator2X, QString locator2Y, QString locator2Z,
                       QString locator3X, QString locator3Y, QString locator3Z,
                       QString locator4X, QString locator4Y, QString locator4Z,
                       QString lastUpdate);

    void closeEvent(QCloseEvent *closeEvent);
};

#endif // MAINWINDOW_H

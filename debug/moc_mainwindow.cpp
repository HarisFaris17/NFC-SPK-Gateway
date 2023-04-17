/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[78];
    char stringdata0[913];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 6), // "listen"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 9), // "ipAddress"
QT_MOC_LITERAL(4, 29, 4), // "port"
QT_MOC_LITERAL(5, 34, 4), // "test"
QT_MOC_LITERAL(6, 39, 11), // "unlistenTCP"
QT_MOC_LITERAL(7, 51, 14), // "deleteTimerTCP"
QT_MOC_LITERAL(8, 66, 18), // "disconnectDatabase"
QT_MOC_LITERAL(9, 85, 19), // "deleteTimerDatabase"
QT_MOC_LITERAL(10, 105, 14), // "sendGatewayMAC"
QT_MOC_LITERAL(11, 120, 11), // "gateway1MAC"
QT_MOC_LITERAL(12, 132, 11), // "gateway2MAC"
QT_MOC_LITERAL(13, 144, 20), // "connectDisconnectTCP"
QT_MOC_LITERAL(14, 165, 12), // "listenResult"
QT_MOC_LITERAL(15, 178, 9), // "isSuccess"
QT_MOC_LITERAL(16, 188, 13), // "unlistenedTcp"
QT_MOC_LITERAL(17, 202, 15), // "timerTcpTimeout"
QT_MOC_LITERAL(18, 218, 20), // "timerDatabaseTimeout"
QT_MOC_LITERAL(19, 239, 18), // "receiveDataConsole"
QT_MOC_LITERAL(20, 258, 4), // "data"
QT_MOC_LITERAL(21, 263, 24), // "receiveDataTableCounting"
QT_MOC_LITERAL(22, 288, 8), // "deviceId"
QT_MOC_LITERAL(23, 297, 5), // "tagId"
QT_MOC_LITERAL(24, 303, 3), // "spk"
QT_MOC_LITERAL(25, 307, 7), // "counter"
QT_MOC_LITERAL(26, 315, 8), // "dateTime"
QT_MOC_LITERAL(27, 324, 15), // "receiveLocation"
QT_MOC_LITERAL(28, 340, 7), // "locator"
QT_MOC_LITERAL(29, 348, 1), // "x"
QT_MOC_LITERAL(30, 350, 1), // "y"
QT_MOC_LITERAL(31, 352, 1), // "z"
QT_MOC_LITERAL(32, 354, 25), // "receiveCumulativeLocation"
QT_MOC_LITERAL(33, 380, 22), // "receiveLastStateDevice"
QT_MOC_LITERAL(34, 403, 9), // "deviceIds"
QT_MOC_LITERAL(35, 413, 9), // "locator1X"
QT_MOC_LITERAL(36, 423, 9), // "locator1Y"
QT_MOC_LITERAL(37, 433, 9), // "locator1Z"
QT_MOC_LITERAL(38, 443, 9), // "locator2X"
QT_MOC_LITERAL(39, 453, 9), // "locator2Y"
QT_MOC_LITERAL(40, 463, 9), // "locator2Z"
QT_MOC_LITERAL(41, 473, 9), // "locator3X"
QT_MOC_LITERAL(42, 483, 9), // "locator3Y"
QT_MOC_LITERAL(43, 493, 9), // "locator3Z"
QT_MOC_LITERAL(44, 503, 9), // "locator4X"
QT_MOC_LITERAL(45, 513, 9), // "locator4Y"
QT_MOC_LITERAL(46, 523, 9), // "locator4Z"
QT_MOC_LITERAL(47, 533, 10), // "lastUpdate"
QT_MOC_LITERAL(48, 544, 14), // "receiveHistory"
QT_MOC_LITERAL(49, 559, 2), // "x0"
QT_MOC_LITERAL(50, 562, 2), // "y0"
QT_MOC_LITERAL(51, 565, 2), // "z0"
QT_MOC_LITERAL(52, 568, 2), // "x1"
QT_MOC_LITERAL(53, 571, 2), // "y1"
QT_MOC_LITERAL(54, 574, 2), // "z1"
QT_MOC_LITERAL(55, 577, 2), // "x2"
QT_MOC_LITERAL(56, 580, 2), // "y2"
QT_MOC_LITERAL(57, 583, 2), // "z2"
QT_MOC_LITERAL(58, 586, 2), // "x3"
QT_MOC_LITERAL(59, 589, 2), // "y3"
QT_MOC_LITERAL(60, 592, 2), // "z3"
QT_MOC_LITERAL(61, 595, 11), // "addDeviceId"
QT_MOC_LITERAL(62, 607, 3), // "mac"
QT_MOC_LITERAL(63, 611, 25), // "connectDisconnectDatabase"
QT_MOC_LITERAL(64, 637, 24), // "databaseConnectionResult"
QT_MOC_LITERAL(65, 662, 20), // "databaseDisconnected"
QT_MOC_LITERAL(66, 683, 17), // "tableCreateResult"
QT_MOC_LITERAL(67, 701, 20), // "isDeviceTableCreated"
QT_MOC_LITERAL(68, 722, 18), // "isDataTableCreated"
QT_MOC_LITERAL(69, 741, 28), // "isDeviceLocationTableCreated"
QT_MOC_LITERAL(70, 770, 26), // "isDataLocationTableCreated"
QT_MOC_LITERAL(71, 797, 15), // "saveGatewayMACs"
QT_MOC_LITERAL(72, 813, 18), // "showSettingLocator"
QT_MOC_LITERAL(73, 832, 13), // "showAddDevice"
QT_MOC_LITERAL(74, 846, 15), // "showCoordinates"
QT_MOC_LITERAL(75, 862, 19), // "resetSettingLocator"
QT_MOC_LITERAL(76, 882, 14), // "resetAddDevice"
QT_MOC_LITERAL(77, 897, 15) // "resetCoordinate"

    },
    "MainWindow\0listen\0\0ipAddress\0port\0"
    "test\0unlistenTCP\0deleteTimerTCP\0"
    "disconnectDatabase\0deleteTimerDatabase\0"
    "sendGatewayMAC\0gateway1MAC\0gateway2MAC\0"
    "connectDisconnectTCP\0listenResult\0"
    "isSuccess\0unlistenedTcp\0timerTcpTimeout\0"
    "timerDatabaseTimeout\0receiveDataConsole\0"
    "data\0receiveDataTableCounting\0deviceId\0"
    "tagId\0spk\0counter\0dateTime\0receiveLocation\0"
    "locator\0x\0y\0z\0receiveCumulativeLocation\0"
    "receiveLastStateDevice\0deviceIds\0"
    "locator1X\0locator1Y\0locator1Z\0locator2X\0"
    "locator2Y\0locator2Z\0locator3X\0locator3Y\0"
    "locator3Z\0locator4X\0locator4Y\0locator4Z\0"
    "lastUpdate\0receiveHistory\0x0\0y0\0z0\0"
    "x1\0y1\0z1\0x2\0y2\0z2\0x3\0y3\0z3\0addDeviceId\0"
    "mac\0connectDisconnectDatabase\0"
    "databaseConnectionResult\0databaseDisconnected\0"
    "tableCreateResult\0isDeviceTableCreated\0"
    "isDataTableCreated\0isDeviceLocationTableCreated\0"
    "isDataLocationTableCreated\0saveGatewayMACs\0"
    "showSettingLocator\0showAddDevice\0"
    "showCoordinates\0resetSettingLocator\0"
    "resetAddDevice\0resetCoordinate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  164,    2, 0x06 /* Public */,
       5,    0,  169,    2, 0x06 /* Public */,
       6,    0,  170,    2, 0x06 /* Public */,
       7,    0,  171,    2, 0x06 /* Public */,
       8,    0,  172,    2, 0x06 /* Public */,
       9,    0,  173,    2, 0x06 /* Public */,
      10,    2,  174,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,  179,    2, 0x0a /* Public */,
      14,    1,  180,    2, 0x0a /* Public */,
      16,    0,  183,    2, 0x0a /* Public */,
      17,    0,  184,    2, 0x0a /* Public */,
      18,    0,  185,    2, 0x0a /* Public */,
      19,    1,  186,    2, 0x0a /* Public */,
      21,    5,  189,    2, 0x0a /* Public */,
      27,    5,  200,    2, 0x0a /* Public */,
      32,    4,  211,    2, 0x0a /* Public */,
      33,   20,  220,    2, 0x0a /* Public */,
      48,   20,  261,    2, 0x0a /* Public */,
      61,    1,  302,    2, 0x0a /* Public */,
      63,    0,  305,    2, 0x0a /* Public */,
      64,    1,  306,    2, 0x0a /* Public */,
      65,    0,  309,    2, 0x0a /* Public */,
      66,    4,  310,    2, 0x0a /* Public */,
      71,    0,  319,    2, 0x0a /* Public */,
      72,    0,  320,    2, 0x08 /* Private */,
      73,    0,  321,    2, 0x08 /* Private */,
      74,    0,  322,    2, 0x08 /* Private */,
      75,    0,  323,    2, 0x08 /* Private */,
      76,    0,  324,    2, 0x08 /* Private */,
      77,    0,  325,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   22,   23,   24,   25,   26,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double,   22,   28,   29,   30,   31,
    QMetaType::Void, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Double,   22,   29,   30,   31,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList,   34,   23,   24,   25,   29,   30,   31,   35,   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,   47,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   22,   23,   24,   25,   29,   30,   31,   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,   26,
    QMetaType::Void, QMetaType::QString,   62,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   67,   68,   69,   70,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->listen((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->test(); break;
        case 2: _t->unlistenTCP(); break;
        case 3: _t->deleteTimerTCP(); break;
        case 4: _t->disconnectDatabase(); break;
        case 5: _t->deleteTimerDatabase(); break;
        case 6: _t->sendGatewayMAC((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->connectDisconnectTCP(); break;
        case 8: _t->listenResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->unlistenedTcp(); break;
        case 10: _t->timerTcpTimeout(); break;
        case 11: _t->timerDatabaseTimeout(); break;
        case 12: _t->receiveDataConsole((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->receiveDataTableCounting((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 14: _t->receiveLocation((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5]))); break;
        case 15: _t->receiveCumulativeLocation((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 16: _t->receiveLastStateDevice((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4])),(*reinterpret_cast< QStringList(*)>(_a[5])),(*reinterpret_cast< QStringList(*)>(_a[6])),(*reinterpret_cast< QStringList(*)>(_a[7])),(*reinterpret_cast< QStringList(*)>(_a[8])),(*reinterpret_cast< QStringList(*)>(_a[9])),(*reinterpret_cast< QStringList(*)>(_a[10])),(*reinterpret_cast< QStringList(*)>(_a[11])),(*reinterpret_cast< QStringList(*)>(_a[12])),(*reinterpret_cast< QStringList(*)>(_a[13])),(*reinterpret_cast< QStringList(*)>(_a[14])),(*reinterpret_cast< QStringList(*)>(_a[15])),(*reinterpret_cast< QStringList(*)>(_a[16])),(*reinterpret_cast< QStringList(*)>(_a[17])),(*reinterpret_cast< QStringList(*)>(_a[18])),(*reinterpret_cast< QStringList(*)>(_a[19])),(*reinterpret_cast< QStringList(*)>(_a[20]))); break;
        case 17: _t->receiveHistory((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< const QString(*)>(_a[9])),(*reinterpret_cast< const QString(*)>(_a[10])),(*reinterpret_cast< const QString(*)>(_a[11])),(*reinterpret_cast< const QString(*)>(_a[12])),(*reinterpret_cast< const QString(*)>(_a[13])),(*reinterpret_cast< const QString(*)>(_a[14])),(*reinterpret_cast< const QString(*)>(_a[15])),(*reinterpret_cast< const QString(*)>(_a[16])),(*reinterpret_cast< const QString(*)>(_a[17])),(*reinterpret_cast< const QString(*)>(_a[18])),(*reinterpret_cast< const QString(*)>(_a[19])),(*reinterpret_cast< const QString(*)>(_a[20]))); break;
        case 18: _t->addDeviceId((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->connectDisconnectDatabase(); break;
        case 20: _t->databaseConnectionResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->databaseDisconnected(); break;
        case 22: _t->tableCreateResult((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 23: _t->saveGatewayMACs(); break;
        case 24: _t->showSettingLocator(); break;
        case 25: _t->showAddDevice(); break;
        case 26: _t->showCoordinates(); break;
        case 27: _t->resetSettingLocator(); break;
        case 28: _t->resetAddDevice(); break;
        case 29: _t->resetCoordinate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::listen)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::test)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::unlistenTCP)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::deleteTimerTCP)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::disconnectDatabase)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::deleteTimerDatabase)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendGatewayMAC)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 30;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::listen(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::test()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MainWindow::unlistenTCP()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MainWindow::deleteTimerTCP()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MainWindow::disconnectDatabase()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void MainWindow::deleteTimerDatabase()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void MainWindow::sendGatewayMAC(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE

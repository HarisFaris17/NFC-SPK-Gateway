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
    QByteArrayData data[27];
    char stringdata0[349];
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
QT_MOC_LITERAL(10, 105, 20), // "connectDisconnectTCP"
QT_MOC_LITERAL(11, 126, 12), // "listenResult"
QT_MOC_LITERAL(12, 139, 9), // "isSuccess"
QT_MOC_LITERAL(13, 149, 13), // "unlistenedTcp"
QT_MOC_LITERAL(14, 163, 15), // "timerTcpTimeout"
QT_MOC_LITERAL(15, 179, 20), // "timerDatabaseTimeout"
QT_MOC_LITERAL(16, 200, 18), // "receiveDataConsole"
QT_MOC_LITERAL(17, 219, 4), // "data"
QT_MOC_LITERAL(18, 224, 16), // "receiveDataTable"
QT_MOC_LITERAL(19, 241, 8), // "deviceId"
QT_MOC_LITERAL(20, 250, 5), // "tagId"
QT_MOC_LITERAL(21, 256, 3), // "spk"
QT_MOC_LITERAL(22, 260, 7), // "counter"
QT_MOC_LITERAL(23, 268, 8), // "dateTime"
QT_MOC_LITERAL(24, 277, 25), // "connectDisconnectDatabase"
QT_MOC_LITERAL(25, 303, 24), // "databaseConnectionResult"
QT_MOC_LITERAL(26, 328, 20) // "databaseDisconnected"

    },
    "MainWindow\0listen\0\0ipAddress\0port\0"
    "test\0unlistenTCP\0deleteTimerTCP\0"
    "disconnectDatabase\0deleteTimerDatabase\0"
    "connectDisconnectTCP\0listenResult\0"
    "isSuccess\0unlistenedTcp\0timerTcpTimeout\0"
    "timerDatabaseTimeout\0receiveDataConsole\0"
    "data\0receiveDataTable\0deviceId\0tagId\0"
    "spk\0counter\0dateTime\0connectDisconnectDatabase\0"
    "databaseConnectionResult\0databaseDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   94,    2, 0x06 /* Public */,
       5,    0,   99,    2, 0x06 /* Public */,
       6,    0,  100,    2, 0x06 /* Public */,
       7,    0,  101,    2, 0x06 /* Public */,
       8,    0,  102,    2, 0x06 /* Public */,
       9,    0,  103,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  104,    2, 0x0a /* Public */,
      11,    1,  105,    2, 0x0a /* Public */,
      13,    0,  108,    2, 0x0a /* Public */,
      14,    0,  109,    2, 0x0a /* Public */,
      15,    0,  110,    2, 0x0a /* Public */,
      16,    1,  111,    2, 0x0a /* Public */,
      18,    5,  114,    2, 0x0a /* Public */,
      24,    0,  125,    2, 0x0a /* Public */,
      25,    1,  126,    2, 0x0a /* Public */,
      26,    0,  129,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   19,   20,   21,   22,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
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
        case 6: _t->connectDisconnectTCP(); break;
        case 7: _t->listenResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->unlistenedTcp(); break;
        case 9: _t->timerTcpTimeout(); break;
        case 10: _t->timerDatabaseTimeout(); break;
        case 11: _t->receiveDataConsole((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 12: _t->receiveDataTable((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 13: _t->connectDisconnectDatabase(); break;
        case 14: _t->databaseConnectionResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->databaseDisconnected(); break;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
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
QT_END_MOC_NAMESPACE

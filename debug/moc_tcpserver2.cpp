/****************************************************************************
** Meta object code from reading C++ file 'tcpserver2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tcpserver2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpserver2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TcpServer2_t {
    QByteArrayData data[14];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpServer2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpServer2_t qt_meta_stringdata_TcpServer2 = {
    {
QT_MOC_LITERAL(0, 0, 10), // "TcpServer2"
QT_MOC_LITERAL(1, 11, 10), // "unlistened"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "listenResult"
QT_MOC_LITERAL(4, 36, 9), // "isSuccess"
QT_MOC_LITERAL(5, 46, 8), // "sendData"
QT_MOC_LITERAL(6, 55, 4), // "data"
QT_MOC_LITERAL(7, 60, 15), // "onNewConnection"
QT_MOC_LITERAL(8, 76, 11), // "onReadyRead"
QT_MOC_LITERAL(9, 88, 6), // "config"
QT_MOC_LITERAL(10, 95, 9), // "ipAddress"
QT_MOC_LITERAL(11, 105, 4), // "port"
QT_MOC_LITERAL(12, 110, 8), // "unlisten"
QT_MOC_LITERAL(13, 119, 4) // "test"

    },
    "TcpServer2\0unlistened\0\0listenResult\0"
    "isSuccess\0sendData\0data\0onNewConnection\0"
    "onReadyRead\0config\0ipAddress\0port\0"
    "unlisten\0test"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpServer2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,
       5,    1,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   61,    2, 0x0a /* Public */,
       8,    0,   62,    2, 0x0a /* Public */,
       9,    2,   63,    2, 0x0a /* Public */,
      12,    0,   68,    2, 0x0a /* Public */,
      13,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::QByteArray,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   10,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TcpServer2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpServer2 *_t = static_cast<TcpServer2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->unlistened(); break;
        case 1: _t->listenResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->sendData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->onNewConnection(); break;
        case 4: _t->onReadyRead(); break;
        case 5: _t->config((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->unlisten(); break;
        case 7: _t->test(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TcpServer2::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpServer2::unlistened)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TcpServer2::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpServer2::listenResult)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TcpServer2::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpServer2::sendData)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject TcpServer2::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_TcpServer2.data,
      qt_meta_data_TcpServer2,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TcpServer2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpServer2::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TcpServer2.stringdata0))
        return static_cast<void*>(const_cast< TcpServer2*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int TcpServer2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void TcpServer2::unlistened()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void TcpServer2::listenResult(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TcpServer2::sendData(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

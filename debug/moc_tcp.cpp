/****************************************************************************
** Meta object code from reading C++ file 'tcp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tcp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Tcp_t {
    QByteArrayData data[10];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tcp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tcp_t qt_meta_stringdata_Tcp = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Tcp"
QT_MOC_LITERAL(1, 4, 6), // "listen"
QT_MOC_LITERAL(2, 11, 0), // ""
QT_MOC_LITERAL(3, 12, 12), // "QHostAddress"
QT_MOC_LITERAL(4, 25, 9), // "ipAddress"
QT_MOC_LITERAL(5, 35, 4), // "port"
QT_MOC_LITERAL(6, 40, 8), // "unlisten"
QT_MOC_LITERAL(7, 49, 7), // "started"
QT_MOC_LITERAL(8, 57, 9), // "listenTCP"
QT_MOC_LITERAL(9, 67, 11) // "unlistenTCP"

    },
    "Tcp\0listen\0\0QHostAddress\0ipAddress\0"
    "port\0unlisten\0started\0listenTCP\0"
    "unlistenTCP"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tcp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       6,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   45,    2, 0x0a /* Public */,
       8,    2,   46,    2, 0x0a /* Public */,
       9,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    5,
    QMetaType::Void,

       0        // eod
};

void Tcp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Tcp *_t = static_cast<Tcp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->listen((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 1: _t->unlisten(); break;
        case 2: _t->started(); break;
        case 3: _t->listenTCP((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->unlistenTCP(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Tcp::*_t)(const QHostAddress & , const int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tcp::listen)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Tcp::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tcp::unlisten)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Tcp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Tcp.data,
      qt_meta_data_Tcp,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Tcp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tcp::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Tcp.stringdata0))
        return static_cast<void*>(const_cast< Tcp*>(this));
    return QObject::qt_metacast(_clname);
}

int Tcp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Tcp::listen(const QHostAddress & _t1, const int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Tcp::unlisten()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

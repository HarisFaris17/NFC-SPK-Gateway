/****************************************************************************
** Meta object code from reading C++ file 'database.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../database.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'database.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Database_t {
    QByteArrayData data[19];
    char stringdata0[268];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Database_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Database_t qt_meta_stringdata_Database = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Database"
QT_MOC_LITERAL(1, 9, 24), // "databaseConnectionResult"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 9), // "isSuccess"
QT_MOC_LITERAL(4, 45, 20), // "databaseDisconnected"
QT_MOC_LITERAL(5, 66, 17), // "tableCreateResult"
QT_MOC_LITERAL(6, 84, 20), // "isDeviceTableCreated"
QT_MOC_LITERAL(7, 105, 18), // "isDataTableCreated"
QT_MOC_LITERAL(8, 124, 28), // "isDeviceLocationTableCreated"
QT_MOC_LITERAL(9, 153, 26), // "isDataLocationTableCreated"
QT_MOC_LITERAL(10, 180, 3), // "run"
QT_MOC_LITERAL(11, 184, 6), // "config"
QT_MOC_LITERAL(12, 191, 9), // "ipAddress"
QT_MOC_LITERAL(13, 201, 4), // "port"
QT_MOC_LITERAL(14, 206, 12), // "databaseName"
QT_MOC_LITERAL(15, 219, 8), // "userName"
QT_MOC_LITERAL(16, 228, 8), // "password"
QT_MOC_LITERAL(17, 237, 18), // "disconnectDatabase"
QT_MOC_LITERAL(18, 256, 11) // "createTable"

    },
    "Database\0databaseConnectionResult\0\0"
    "isSuccess\0databaseDisconnected\0"
    "tableCreateResult\0isDeviceTableCreated\0"
    "isDataTableCreated\0isDeviceLocationTableCreated\0"
    "isDataLocationTableCreated\0run\0config\0"
    "ipAddress\0port\0databaseName\0userName\0"
    "password\0disconnectDatabase\0createTable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Database[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    0,   52,    2, 0x06 /* Public */,
       5,    4,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   62,    2, 0x0a /* Public */,
      11,    5,   63,    2, 0x0a /* Public */,
      17,    0,   74,    2, 0x0a /* Public */,
      18,    0,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,    6,    7,    8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   12,   13,   14,   15,   16,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Database::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Database *_t = static_cast<Database *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->databaseConnectionResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->databaseDisconnected(); break;
        case 2: _t->tableCreateResult((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 3: _t->run(); break;
        case 4: _t->config((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 5: _t->disconnectDatabase(); break;
        case 6: _t->createTable(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Database::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Database::databaseConnectionResult)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Database::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Database::databaseDisconnected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Database::*_t)(bool , bool , bool , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Database::tableCreateResult)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Database::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Database.data,
      qt_meta_data_Database,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Database::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Database::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Database.stringdata0))
        return static_cast<void*>(const_cast< Database*>(this));
    return QObject::qt_metacast(_clname);
}

int Database::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Database::databaseConnectionResult(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Database::databaseDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Database::tableCreateResult(bool _t1, bool _t2, bool _t3, bool _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

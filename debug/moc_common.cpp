/****************************************************************************
** Meta object code from reading C++ file 'common.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../common.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'common.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Common_t {
    QByteArrayData data[9];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Common_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Common_t qt_meta_stringdata_Common = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Common"
QT_MOC_LITERAL(1, 7, 11), // "addDeviceId"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 8), // "deviceId"
QT_MOC_LITERAL(4, 29, 16), // "replaceDeviceIds"
QT_MOC_LITERAL(5, 46, 14), // "QList<QString>"
QT_MOC_LITERAL(6, 61, 9), // "deviceIds"
QT_MOC_LITERAL(7, 71, 13), // "indexDeviceId"
QT_MOC_LITERAL(8, 85, 15) // "isExistDeviceId"

    },
    "Common\0addDeviceId\0\0deviceId\0"
    "replaceDeviceIds\0QList<QString>\0"
    "deviceIds\0indexDeviceId\0isExistDeviceId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Common[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       7,    1,   40,    2, 0x0a /* Public */,
       8,    1,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Int, QMetaType::QString,    3,
    QMetaType::Bool, QMetaType::QString,    3,

       0        // eod
};

void Common::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Common *_t = static_cast<Common *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addDeviceId((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->replaceDeviceIds((*reinterpret_cast< const QList<QString>(*)>(_a[1]))); break;
        case 2: { int _r = _t->indexDeviceId((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->isExistDeviceId((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        }
    }
}

const QMetaObject Common::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Common.data,
      qt_meta_data_Common,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Common::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Common::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Common.stringdata0))
        return static_cast<void*>(const_cast< Common*>(this));
    return QObject::qt_metacast(_clname);
}

int Common::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

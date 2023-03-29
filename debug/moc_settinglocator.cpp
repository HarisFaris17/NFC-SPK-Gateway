/****************************************************************************
** Meta object code from reading C++ file 'settinglocator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../settinglocator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settinglocator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SettingLocator_t {
    QByteArrayData data[24];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingLocator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingLocator_t qt_meta_stringdata_SettingLocator = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SettingLocator"
QT_MOC_LITERAL(1, 15, 17), // "sendLocatorParams"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 3), // "ref"
QT_MOC_LITERAL(4, 38, 2), // "x1"
QT_MOC_LITERAL(5, 41, 2), // "y1"
QT_MOC_LITERAL(6, 44, 2), // "z1"
QT_MOC_LITERAL(7, 47, 2), // "x2"
QT_MOC_LITERAL(8, 50, 2), // "y2"
QT_MOC_LITERAL(9, 53, 2), // "z2"
QT_MOC_LITERAL(10, 56, 2), // "x3"
QT_MOC_LITERAL(11, 59, 2), // "y3"
QT_MOC_LITERAL(12, 62, 2), // "z3"
QT_MOC_LITERAL(13, 65, 2), // "x4"
QT_MOC_LITERAL(14, 68, 2), // "y4"
QT_MOC_LITERAL(15, 71, 2), // "z4"
QT_MOC_LITERAL(16, 74, 8), // "sendRSSI"
QT_MOC_LITERAL(17, 83, 6), // "rssi1m"
QT_MOC_LITERAL(18, 90, 6), // "rssi2m"
QT_MOC_LITERAL(19, 97, 18), // "refComboBoxChanged"
QT_MOC_LITERAL(20, 116, 23), // "applyCalibrationClicked"
QT_MOC_LITERAL(21, 140, 20), // "applyDistanceClicked"
QT_MOC_LITERAL(22, 161, 13), // "zLinesChanged"
QT_MOC_LITERAL(23, 175, 7) // "newText"

    },
    "SettingLocator\0sendLocatorParams\0\0ref\0"
    "x1\0y1\0z1\0x2\0y2\0z2\0x3\0y3\0z3\0x4\0y4\0z4\0"
    "sendRSSI\0rssi1m\0rssi2m\0refComboBoxChanged\0"
    "applyCalibrationClicked\0applyDistanceClicked\0"
    "zLinesChanged\0newText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingLocator[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,   13,   44,    2, 0x06 /* Public */,
      16,    2,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    1,   76,    2, 0x0a /* Public */,
      20,    0,   79,    2, 0x0a /* Public */,
      21,    0,   80,    2, 0x0a /* Public */,
      22,    1,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   17,   18,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,

       0        // eod
};

void SettingLocator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SettingLocator *_t = static_cast<SettingLocator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendLocatorParams((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11])),(*reinterpret_cast< QString(*)>(_a[12])),(*reinterpret_cast< QString(*)>(_a[13]))); break;
        case 1: _t->sendRSSI((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->refComboBoxChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->applyCalibrationClicked(); break;
        case 4: _t->applyDistanceClicked(); break;
        case 5: _t->zLinesChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SettingLocator::*_t)(int , QString , QString , QString , QString , QString , QString , QString , QString , QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SettingLocator::sendLocatorParams)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SettingLocator::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SettingLocator::sendRSSI)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SettingLocator::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SettingLocator.data,
      qt_meta_data_SettingLocator,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SettingLocator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingLocator::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SettingLocator.stringdata0))
        return static_cast<void*>(const_cast< SettingLocator*>(this));
    return QDialog::qt_metacast(_clname);
}

int SettingLocator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SettingLocator::sendLocatorParams(int _t1, QString _t2, QString _t3, QString _t4, QString _t5, QString _t6, QString _t7, QString _t8, QString _t9, QString _t10, QString _t11, QString _t12, QString _t13)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)), const_cast<void*>(reinterpret_cast<const void*>(&_t10)), const_cast<void*>(reinterpret_cast<const void*>(&_t11)), const_cast<void*>(reinterpret_cast<const void*>(&_t12)), const_cast<void*>(reinterpret_cast<const void*>(&_t13)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SettingLocator::sendRSSI(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

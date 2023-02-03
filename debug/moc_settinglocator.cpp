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
    QByteArrayData data[6];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingLocator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingLocator_t qt_meta_stringdata_SettingLocator = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SettingLocator"
QT_MOC_LITERAL(1, 15, 18), // "refComboBoxChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 3), // "ref"
QT_MOC_LITERAL(4, 39, 9), // "okClicked"
QT_MOC_LITERAL(5, 49, 13) // "cancelClicked"

    },
    "SettingLocator\0refComboBoxChanged\0\0"
    "ref\0okClicked\0cancelClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingLocator[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    0,   32,    2, 0x0a /* Public */,
       5,    0,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SettingLocator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SettingLocator *_t = static_cast<SettingLocator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refComboBoxChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->okClicked(); break;
        case 2: _t->cancelClicked(); break;
        default: ;
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
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

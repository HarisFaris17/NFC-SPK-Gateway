/****************************************************************************
** Meta object code from reading C++ file 'processor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../processor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'processor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Processor_t {
    QByteArrayData data[32];
    char stringdata0[348];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Processor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Processor_t qt_meta_stringdata_Processor = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Processor"
QT_MOC_LITERAL(1, 10, 8), // "sendData"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 4), // "data"
QT_MOC_LITERAL(4, 25, 13), // "sendDataTable"
QT_MOC_LITERAL(5, 39, 8), // "deviceId"
QT_MOC_LITERAL(6, 48, 5), // "tagId"
QT_MOC_LITERAL(7, 54, 3), // "spk"
QT_MOC_LITERAL(8, 58, 7), // "counter"
QT_MOC_LITERAL(9, 66, 8), // "dateTime"
QT_MOC_LITERAL(10, 75, 12), // "sendLocation"
QT_MOC_LITERAL(11, 88, 7), // "locator"
QT_MOC_LITERAL(12, 96, 1), // "x"
QT_MOC_LITERAL(13, 98, 1), // "y"
QT_MOC_LITERAL(14, 100, 1), // "z"
QT_MOC_LITERAL(15, 102, 14), // "receiveTcpData"
QT_MOC_LITERAL(16, 117, 7), // "rawData"
QT_MOC_LITERAL(17, 125, 18), // "receiveTcpLocation"
QT_MOC_LITERAL(18, 144, 7), // "tcpData"
QT_MOC_LITERAL(19, 152, 7), // "started"
QT_MOC_LITERAL(20, 160, 25), // "locationCalculatorStarted"
QT_MOC_LITERAL(21, 186, 12), // "errorOccured"
QT_MOC_LITERAL(22, 199, 22), // "QProcess::ProcessError"
QT_MOC_LITERAL(23, 222, 5), // "error"
QT_MOC_LITERAL(24, 228, 26), // "locationCalculatorFinished"
QT_MOC_LITERAL(25, 255, 8), // "exitCode"
QT_MOC_LITERAL(26, 264, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(27, 285, 10), // "exitStatus"
QT_MOC_LITERAL(28, 296, 12), // "stateChanged"
QT_MOC_LITERAL(29, 309, 22), // "QProcess::ProcessState"
QT_MOC_LITERAL(30, 332, 5), // "state"
QT_MOC_LITERAL(31, 338, 9) // "readyRead"

    },
    "Processor\0sendData\0\0data\0sendDataTable\0"
    "deviceId\0tagId\0spk\0counter\0dateTime\0"
    "sendLocation\0locator\0x\0y\0z\0receiveTcpData\0"
    "rawData\0receiveTcpLocation\0tcpData\0"
    "started\0locationCalculatorStarted\0"
    "errorOccured\0QProcess::ProcessError\0"
    "error\0locationCalculatorFinished\0"
    "exitCode\0QProcess::ExitStatus\0exitStatus\0"
    "stateChanged\0QProcess::ProcessState\0"
    "state\0readyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Processor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    5,   72,    2, 0x06 /* Public */,
      10,    5,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    1,   94,    2, 0x0a /* Public */,
      17,    1,   97,    2, 0x0a /* Public */,
      19,    0,  100,    2, 0x0a /* Public */,
      20,    0,  101,    2, 0x0a /* Public */,
      21,    1,  102,    2, 0x0a /* Public */,
      24,    2,  105,    2, 0x0a /* Public */,
      28,    1,  110,    2, 0x0a /* Public */,
      31,    0,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    5,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double,    5,   11,   12,   13,   14,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,   16,
    QMetaType::Void, QMetaType::QByteArray,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 26,   25,   27,
    QMetaType::Void, 0x80000000 | 29,   30,
    QMetaType::Void,

       0        // eod
};

void Processor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Processor *_t = static_cast<Processor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendDataTable((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 2: _t->sendLocation((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5]))); break;
        case 3: _t->receiveTcpData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->receiveTcpLocation((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->started(); break;
        case 6: _t->locationCalculatorStarted(); break;
        case 7: _t->errorOccured((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        case 8: _t->locationCalculatorFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 9: _t->stateChanged((*reinterpret_cast< QProcess::ProcessState(*)>(_a[1]))); break;
        case 10: _t->readyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Processor::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Processor::sendData)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Processor::*_t)(QString , QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Processor::sendDataTable)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Processor::*_t)(QString , int , double , double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Processor::sendLocation)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Processor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Processor.data,
      qt_meta_data_Processor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Processor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Processor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Processor.stringdata0))
        return static_cast<void*>(const_cast< Processor*>(this));
    return QObject::qt_metacast(_clname);
}

int Processor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Processor::sendData(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Processor::sendDataTable(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Processor::sendLocation(QString _t1, int _t2, double _t3, double _t4, double _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

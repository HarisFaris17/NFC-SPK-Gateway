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
    QByteArrayData data[64];
    char stringdata0[538];
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
QT_MOC_LITERAL(15, 102, 22), // "sendCumulativeLocation"
QT_MOC_LITERAL(16, 125, 11), // "sendHistory"
QT_MOC_LITERAL(17, 137, 2), // "x0"
QT_MOC_LITERAL(18, 140, 2), // "y0"
QT_MOC_LITERAL(19, 143, 2), // "z0"
QT_MOC_LITERAL(20, 146, 2), // "x1"
QT_MOC_LITERAL(21, 149, 2), // "y1"
QT_MOC_LITERAL(22, 152, 2), // "z1"
QT_MOC_LITERAL(23, 155, 2), // "x2"
QT_MOC_LITERAL(24, 158, 2), // "y2"
QT_MOC_LITERAL(25, 161, 2), // "z2"
QT_MOC_LITERAL(26, 164, 2), // "x3"
QT_MOC_LITERAL(27, 167, 2), // "y3"
QT_MOC_LITERAL(28, 170, 2), // "z3"
QT_MOC_LITERAL(29, 173, 11), // "updateCoord"
QT_MOC_LITERAL(30, 185, 14), // "receiveTcpData"
QT_MOC_LITERAL(31, 200, 7), // "rawData"
QT_MOC_LITERAL(32, 208, 7), // "started"
QT_MOC_LITERAL(33, 216, 25), // "locationCalculatorStarted"
QT_MOC_LITERAL(34, 242, 12), // "errorOccured"
QT_MOC_LITERAL(35, 255, 22), // "QProcess::ProcessError"
QT_MOC_LITERAL(36, 278, 5), // "error"
QT_MOC_LITERAL(37, 284, 26), // "locationCalculatorFinished"
QT_MOC_LITERAL(38, 311, 8), // "exitCode"
QT_MOC_LITERAL(39, 320, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(40, 341, 10), // "exitStatus"
QT_MOC_LITERAL(41, 352, 12), // "stateChanged"
QT_MOC_LITERAL(42, 365, 22), // "QProcess::ProcessState"
QT_MOC_LITERAL(43, 388, 5), // "state"
QT_MOC_LITERAL(44, 394, 22), // "receiveLastStateDevice"
QT_MOC_LITERAL(45, 417, 9), // "deviceIds"
QT_MOC_LITERAL(46, 427, 11), // "addDeviceId"
QT_MOC_LITERAL(47, 439, 17), // "receiveRSSIConfig"
QT_MOC_LITERAL(48, 457, 6), // "rssi1m"
QT_MOC_LITERAL(49, 464, 6), // "rssi2m"
QT_MOC_LITERAL(50, 471, 20), // "receiveLocatorParams"
QT_MOC_LITERAL(51, 492, 2), // "x4"
QT_MOC_LITERAL(52, 495, 2), // "y4"
QT_MOC_LITERAL(53, 498, 2), // "z4"
QT_MOC_LITERAL(54, 501, 2), // "x5"
QT_MOC_LITERAL(55, 504, 2), // "y5"
QT_MOC_LITERAL(56, 507, 2), // "z5"
QT_MOC_LITERAL(57, 510, 2), // "x6"
QT_MOC_LITERAL(58, 513, 2), // "y6"
QT_MOC_LITERAL(59, 516, 2), // "z6"
QT_MOC_LITERAL(60, 519, 2), // "x7"
QT_MOC_LITERAL(61, 522, 2), // "y7"
QT_MOC_LITERAL(62, 525, 2), // "z7"
QT_MOC_LITERAL(63, 528, 9) // "readyRead"

    },
    "Processor\0sendData\0\0data\0sendDataTable\0"
    "deviceId\0tagId\0spk\0counter\0dateTime\0"
    "sendLocation\0locator\0x\0y\0z\0"
    "sendCumulativeLocation\0sendHistory\0"
    "x0\0y0\0z0\0x1\0y1\0z1\0x2\0y2\0z2\0x3\0y3\0z3\0"
    "updateCoord\0receiveTcpData\0rawData\0"
    "started\0locationCalculatorStarted\0"
    "errorOccured\0QProcess::ProcessError\0"
    "error\0locationCalculatorFinished\0"
    "exitCode\0QProcess::ExitStatus\0exitStatus\0"
    "stateChanged\0QProcess::ProcessState\0"
    "state\0receiveLastStateDevice\0deviceIds\0"
    "addDeviceId\0receiveRSSIConfig\0rssi1m\0"
    "rssi2m\0receiveLocatorParams\0x4\0y4\0z4\0"
    "x5\0y5\0z5\0x6\0y6\0z6\0x7\0y7\0z7\0readyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Processor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    5,  102,    2, 0x06 /* Public */,
      10,    5,  113,    2, 0x06 /* Public */,
      15,    4,  124,    2, 0x06 /* Public */,
      16,   20,  133,    2, 0x06 /* Public */,
      29,    0,  174,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      30,    1,  175,    2, 0x0a /* Public */,
      32,    0,  178,    2, 0x0a /* Public */,
      33,    0,  179,    2, 0x0a /* Public */,
      34,    1,  180,    2, 0x0a /* Public */,
      37,    2,  183,    2, 0x0a /* Public */,
      41,    1,  188,    2, 0x0a /* Public */,
      44,    7,  191,    2, 0x0a /* Public */,
      46,    1,  206,    2, 0x0a /* Public */,
      47,    2,  209,    2, 0x0a /* Public */,
      50,   24,  214,    2, 0x0a /* Public */,
      63,    0,  263,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    5,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double,    5,   11,   12,   13,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Double,    5,   12,   13,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    5,    6,    7,    8,   12,   13,   14,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,   31,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 35,   36,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 39,   38,   40,
    QMetaType::Void, 0x80000000 | 42,   43,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList,   45,    6,    7,    8,   12,   13,   14,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   48,   49,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,   62,
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
        case 3: _t->sendCumulativeLocation((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 4: _t->sendHistory((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< const QString(*)>(_a[9])),(*reinterpret_cast< const QString(*)>(_a[10])),(*reinterpret_cast< const QString(*)>(_a[11])),(*reinterpret_cast< const QString(*)>(_a[12])),(*reinterpret_cast< const QString(*)>(_a[13])),(*reinterpret_cast< const QString(*)>(_a[14])),(*reinterpret_cast< const QString(*)>(_a[15])),(*reinterpret_cast< const QString(*)>(_a[16])),(*reinterpret_cast< const QString(*)>(_a[17])),(*reinterpret_cast< const QString(*)>(_a[18])),(*reinterpret_cast< const QString(*)>(_a[19])),(*reinterpret_cast< const QString(*)>(_a[20]))); break;
        case 5: _t->updateCoord(); break;
        case 6: _t->receiveTcpData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: _t->started(); break;
        case 8: _t->locationCalculatorStarted(); break;
        case 9: _t->errorOccured((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        case 10: _t->locationCalculatorFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 11: _t->stateChanged((*reinterpret_cast< QProcess::ProcessState(*)>(_a[1]))); break;
        case 12: _t->receiveLastStateDevice((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4])),(*reinterpret_cast< QStringList(*)>(_a[5])),(*reinterpret_cast< QStringList(*)>(_a[6])),(*reinterpret_cast< QStringList(*)>(_a[7]))); break;
        case 13: _t->addDeviceId((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->receiveRSSIConfig((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 15: _t->receiveLocatorParams((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11])),(*reinterpret_cast< QString(*)>(_a[12])),(*reinterpret_cast< QString(*)>(_a[13])),(*reinterpret_cast< QString(*)>(_a[14])),(*reinterpret_cast< QString(*)>(_a[15])),(*reinterpret_cast< QString(*)>(_a[16])),(*reinterpret_cast< QString(*)>(_a[17])),(*reinterpret_cast< QString(*)>(_a[18])),(*reinterpret_cast< QString(*)>(_a[19])),(*reinterpret_cast< QString(*)>(_a[20])),(*reinterpret_cast< QString(*)>(_a[21])),(*reinterpret_cast< QString(*)>(_a[22])),(*reinterpret_cast< QString(*)>(_a[23])),(*reinterpret_cast< QString(*)>(_a[24]))); break;
        case 16: _t->readyRead(); break;
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
        {
            typedef void (Processor::*_t)(QString , double , double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Processor::sendCumulativeLocation)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Processor::*_t)(const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Processor::sendHistory)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Processor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Processor::updateCoord)) {
                *result = 5;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
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

// SIGNAL 3
void Processor::sendCumulativeLocation(QString _t1, double _t2, double _t3, double _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Processor::sendHistory(const QString & _t1, const QString & _t2, const QString & _t3, const QString & _t4, const QString & _t5, const QString & _t6, const QString & _t7, const QString & _t8, const QString & _t9, const QString & _t10, const QString & _t11, const QString & _t12, const QString & _t13, const QString & _t14, const QString & _t15, const QString & _t16, const QString & _t17, const QString & _t18, const QString & _t19, const QString & _t20)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)), const_cast<void*>(reinterpret_cast<const void*>(&_t10)), const_cast<void*>(reinterpret_cast<const void*>(&_t11)), const_cast<void*>(reinterpret_cast<const void*>(&_t12)), const_cast<void*>(reinterpret_cast<const void*>(&_t13)), const_cast<void*>(reinterpret_cast<const void*>(&_t14)), const_cast<void*>(reinterpret_cast<const void*>(&_t15)), const_cast<void*>(reinterpret_cast<const void*>(&_t16)), const_cast<void*>(reinterpret_cast<const void*>(&_t17)), const_cast<void*>(reinterpret_cast<const void*>(&_t18)), const_cast<void*>(reinterpret_cast<const void*>(&_t19)), const_cast<void*>(reinterpret_cast<const void*>(&_t20)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Processor::updateCoord()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'interface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WP/interface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Interface_t {
    QByteArrayData data[29];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Interface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Interface_t qt_meta_stringdata_Interface = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Interface"
QT_MOC_LITERAL(1, 10, 17), // "on_INICIO_clicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "read"
QT_MOC_LITERAL(4, 34, 10), // "DataValues"
QT_MOC_LITERAL(5, 45, 8), // "QString&"
QT_MOC_LITERAL(6, 54, 4), // "Data"
QT_MOC_LITERAL(7, 59, 1), // "n"
QT_MOC_LITERAL(8, 61, 4), // "int&"
QT_MOC_LITERAL(9, 66, 1), // "i"
QT_MOC_LITERAL(10, 68, 1), // "j"
QT_MOC_LITERAL(11, 70, 4), // "dirx"
QT_MOC_LITERAL(12, 75, 1), // "x"
QT_MOC_LITERAL(13, 77, 6), // "qreal&"
QT_MOC_LITERAL(14, 84, 2), // "mx"
QT_MOC_LITERAL(15, 87, 4), // "diry"
QT_MOC_LITERAL(16, 92, 1), // "y"
QT_MOC_LITERAL(17, 94, 2), // "my"
QT_MOC_LITERAL(18, 97, 7), // "diryNEW"
QT_MOC_LITERAL(19, 105, 7), // "dirxNEW"
QT_MOC_LITERAL(20, 113, 4), // "dirz"
QT_MOC_LITERAL(21, 118, 1), // "z"
QT_MOC_LITERAL(22, 120, 2), // "mz"
QT_MOC_LITERAL(23, 123, 8), // "MoveBall"
QT_MOC_LITERAL(24, 132, 1), // "w"
QT_MOC_LITERAL(25, 134, 1), // "h"
QT_MOC_LITERAL(26, 136, 9), // "LimitBall"
QT_MOC_LITERAL(27, 146, 16), // "on_PAUSE_clicked"
QT_MOC_LITERAL(28, 163, 15) // "on_GAME_clicked"

    },
    "Interface\0on_INICIO_clicked\0\0read\0"
    "DataValues\0QString&\0Data\0n\0int&\0i\0j\0"
    "dirx\0x\0qreal&\0mx\0diry\0y\0my\0diryNEW\0"
    "dirxNEW\0dirz\0z\0mz\0MoveBall\0w\0h\0LimitBall\0"
    "on_PAUSE_clicked\0on_GAME_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Interface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    4,   76,    2, 0x08 /* Private */,
      11,    2,   85,    2, 0x08 /* Private */,
      15,    2,   90,    2, 0x08 /* Private */,
      18,    2,   95,    2, 0x08 /* Private */,
      19,    2,  100,    2, 0x08 /* Private */,
      20,    2,  105,    2, 0x08 /* Private */,
      23,    2,  110,    2, 0x08 /* Private */,
      26,    2,  115,    2, 0x08 /* Private */,
      27,    0,  120,    2, 0x08 /* Private */,
      28,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int, 0x80000000 | 8, QMetaType::Int,    6,    7,    9,   10,
    QMetaType::QString, QMetaType::QString, 0x80000000 | 13,   12,   14,
    QMetaType::QString, QMetaType::QString, 0x80000000 | 13,   16,   17,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 13,   16,   17,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 13,   12,   14,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 13,   21,   22,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,   24,   25,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 13,   25,   24,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Interface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Interface *_t = static_cast<Interface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_INICIO_clicked(); break;
        case 1: _t->read(); break;
        case 2: _t->DataValues((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: { QString _r = _t->dirx((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->diry((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->diryNEW((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 6: _t->dirxNEW((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 7: _t->dirz((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 8: _t->MoveBall((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 9: _t->LimitBall((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 10: _t->on_PAUSE_clicked(); break;
        case 11: _t->on_GAME_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Interface::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Interface.data,
      qt_meta_data_Interface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Interface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Interface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Interface.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Interface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

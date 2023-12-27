/****************************************************************************
** Meta object code from reading C++ file 'checkstand.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Shenzhen_metro_ticket_sale_system/checkstand.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'checkstand.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Checkstand_t {
    const uint offsetsAndSize[28];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Checkstand_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Checkstand_t qt_meta_stringdata_Checkstand = {
    {
QT_MOC_LITERAL(0, 10), // "Checkstand"
QT_MOC_LITERAL(11, 14), // "return_to_line"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 9), // "sendminus"
QT_MOC_LITERAL(37, 1), // "m"
QT_MOC_LITERAL(39, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(61, 12), // "receiveprice"
QT_MOC_LITERAL(74, 1), // "p"
QT_MOC_LITERAL(76, 23), // "on_spinBox_valueChanged"
QT_MOC_LITERAL(100, 4), // "arg1"
QT_MOC_LITERAL(105, 29), // "on_doubleSpinBox_valueChanged"
QT_MOC_LITERAL(135, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(159, 14), // "return_from_no"
QT_MOC_LITERAL(174, 15) // "return_from_yes"

    },
    "Checkstand\0return_to_line\0\0sendminus\0"
    "m\0on_pushButton_clicked\0receiveprice\0"
    "p\0on_spinBox_valueChanged\0arg1\0"
    "on_doubleSpinBox_valueChanged\0"
    "on_pushButton_2_clicked\0return_from_no\0"
    "return_from_yes"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Checkstand[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    1 /* Public */,
       3,    1,   69,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   72,    2, 0x08,    4 /* Private */,
       6,    1,   73,    2, 0x08,    5 /* Private */,
       8,    1,   76,    2, 0x08,    7 /* Private */,
      10,    1,   79,    2, 0x08,    9 /* Private */,
      11,    0,   82,    2, 0x08,   11 /* Private */,
      12,    0,   83,    2, 0x08,   12 /* Private */,
      13,    0,   84,    2, 0x08,   13 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Checkstand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Checkstand *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->return_to_line(); break;
        case 1: _t->sendminus((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->receiveprice((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_doubleSpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_2_clicked(); break;
        case 7: _t->return_from_no(); break;
        case 8: _t->return_from_yes(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Checkstand::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Checkstand::return_to_line)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Checkstand::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Checkstand::sendminus)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Checkstand::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Checkstand.offsetsAndSize,
    qt_meta_data_Checkstand,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Checkstand_t
, QtPrivate::TypeAndForceComplete<Checkstand, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Checkstand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Checkstand::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Checkstand.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Checkstand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Checkstand::return_to_line()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Checkstand::sendminus(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

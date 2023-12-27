/****************************************************************************
** Meta object code from reading C++ file 'map.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Shenzhen_metro_ticket_sale_system/map.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'map.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Map_t {
    const uint offsetsAndSize[40];
    char stringdata0[318];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Map_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Map_t qt_meta_stringdata_Map = {
    {
QT_MOC_LITERAL(0, 3), // "Map"
QT_MOC_LITERAL(4, 8), // "mysignal"
QT_MOC_LITERAL(13, 0), // ""
QT_MOC_LITERAL(14, 17), // "return_to_welcome"
QT_MOC_LITERAL(32, 11), // "sendstation"
QT_MOC_LITERAL(44, 8), // "QString&"
QT_MOC_LITERAL(53, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(75, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(99, 22), // "on_Slider_valueChanged"
QT_MOC_LITERAL(122, 5), // "value"
QT_MOC_LITERAL(128, 34), // "on_horizontalScrollBar_slider..."
QT_MOC_LITERAL(163, 8), // "position"
QT_MOC_LITERAL(172, 32), // "on_verticalScrollBar_sliderMoved"
QT_MOC_LITERAL(205, 11), // "eventFilter"
QT_MOC_LITERAL(217, 7), // "QEvent*"
QT_MOC_LITERAL(225, 22), // "station_button_clicked"
QT_MOC_LITERAL(248, 16), // "QAbstractButton*"
QT_MOC_LITERAL(265, 22), // "on_lineEdit_textEdited"
QT_MOC_LITERAL(288, 4), // "arg1"
QT_MOC_LITERAL(293, 24) // "on_lineEdit_2_textEdited"

    },
    "Map\0mysignal\0\0return_to_welcome\0"
    "sendstation\0QString&\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked\0on_Slider_valueChanged\0"
    "value\0on_horizontalScrollBar_sliderMoved\0"
    "position\0on_verticalScrollBar_sliderMoved\0"
    "eventFilter\0QEvent*\0station_button_clicked\0"
    "QAbstractButton*\0on_lineEdit_textEdited\0"
    "arg1\0on_lineEdit_2_textEdited"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Map[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x06,    1 /* Public */,
       3,    0,   87,    2, 0x06,    2 /* Public */,
       4,    2,   88,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   93,    2, 0x08,    6 /* Private */,
       7,    0,   94,    2, 0x08,    7 /* Private */,
       8,    1,   95,    2, 0x08,    8 /* Private */,
      10,    1,   98,    2, 0x08,   10 /* Private */,
      12,    1,  101,    2, 0x08,   12 /* Private */,
      13,    2,  104,    2, 0x08,   14 /* Private */,
      15,    1,  109,    2, 0x08,   17 /* Private */,
      17,    1,  112,    2, 0x08,   19 /* Private */,
      19,    1,  115,    2, 0x08,   21 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 14,    2,    2,
    QMetaType::Void, 0x80000000 | 16,    2,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QString,   18,

       0        // eod
};

void Map::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Map *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->mysignal(); break;
        case 1: _t->return_to_welcome(); break;
        case 2: _t->sendstation((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_pushButton_2_clicked(); break;
        case 5: _t->on_Slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_horizontalScrollBar_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_verticalScrollBar_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->station_button_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 10: _t->on_lineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_lineEdit_2_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Map::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Map::mysignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Map::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Map::return_to_welcome)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Map::*)(QString & , QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Map::sendstation)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Map::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Map.offsetsAndSize,
    qt_meta_data_Map,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Map_t
, QtPrivate::TypeAndForceComplete<Map, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString &, std::false_type>, QtPrivate::TypeAndForceComplete<QString &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<QObject *, std::false_type>, QtPrivate::TypeAndForceComplete<QEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAbstractButton *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


>,
    nullptr
} };


const QMetaObject *Map::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Map::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Map.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Map::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Map::mysignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Map::return_to_welcome()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Map::sendstation(QString & _t1, QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

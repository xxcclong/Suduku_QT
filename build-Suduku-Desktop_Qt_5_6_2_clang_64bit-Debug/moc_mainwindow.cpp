/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Suduku/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[25];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "paintEvent"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "QPaintEvent*"
QT_MOC_LITERAL(4, 36, 11), // "longsuccess"
QT_MOC_LITERAL(5, 48, 9), // "longpress"
QT_MOC_LITERAL(6, 58, 7), // "newgame"
QT_MOC_LITERAL(7, 66, 4), // "open"
QT_MOC_LITERAL(8, 71, 7), // "showdia"
QT_MOC_LITERAL(9, 79, 1), // "i"
QT_MOC_LITERAL(10, 81, 4), // "save"
QT_MOC_LITERAL(11, 86, 6), // "saveas"
QT_MOC_LITERAL(12, 93, 5), // "about"
QT_MOC_LITERAL(13, 99, 4), // "easy"
QT_MOC_LITERAL(14, 104, 6), // "middle"
QT_MOC_LITERAL(15, 111, 4), // "hard"
QT_MOC_LITERAL(16, 116, 4), // "fill"
QT_MOC_LITERAL(17, 121, 1), // "x"
QT_MOC_LITERAL(18, 123, 1), // "y"
QT_MOC_LITERAL(19, 125, 3), // "num"
QT_MOC_LITERAL(20, 129, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(21, 144, 12), // "QMouseEvent*"
QT_MOC_LITERAL(22, 157, 5), // "event"
QT_MOC_LITERAL(23, 163, 6), // "setico"
QT_MOC_LITERAL(24, 170, 5) // "input"

    },
    "MainWindow\0paintEvent\0\0QPaintEvent*\0"
    "longsuccess\0longpress\0newgame\0open\0"
    "showdia\0i\0save\0saveas\0about\0easy\0"
    "middle\0hard\0fill\0x\0y\0num\0mouseMoveEvent\0"
    "QMouseEvent*\0event\0setico\0input"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x08 /* Private */,
       4,    0,  102,    2, 0x08 /* Private */,
       5,    1,  103,    2, 0x08 /* Private */,
       6,    0,  106,    2, 0x08 /* Private */,
       7,    0,  107,    2, 0x08 /* Private */,
       8,    1,  108,    2, 0x08 /* Private */,
       8,    0,  111,    2, 0x28 /* Private | MethodCloned */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    3,  118,    2, 0x08 /* Private */,
      20,    1,  125,    2, 0x08 /* Private */,
      23,    3,  128,    2, 0x08 /* Private */,
      23,    2,  135,    2, 0x28 /* Private | MethodCloned */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   17,   18,   19,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,   24,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 1: _t->longsuccess(); break;
        case 2: _t->longpress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->newgame(); break;
        case 4: _t->open(); break;
        case 5: _t->showdia((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->showdia(); break;
        case 7: { bool _r = _t->save();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { bool _r = _t->saveas();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: _t->about(); break;
        case 10: _t->easy(); break;
        case 11: _t->middle(); break;
        case 12: _t->hard(); break;
        case 13: _t->fill((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 14: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 15: _t->setico((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 16: _t->setico((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE

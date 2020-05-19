/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QtServer/server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Server_t {
    QByteArrayData data[18];
    char stringdata0[258];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Server_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Server_t qt_meta_stringdata_Server = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Server"
QT_MOC_LITERAL(1, 7, 19), // "showCurrentDirFiles"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 16), // "showNextDirFiles"
QT_MOC_LITERAL(4, 45, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(5, 62, 4), // "item"
QT_MOC_LITERAL(6, 67, 15), // "playCurrentItem"
QT_MOC_LITERAL(7, 83, 19), // "lineEditTextChanged"
QT_MOC_LITERAL(8, 103, 11), // "sendMessage"
QT_MOC_LITERAL(9, 115, 16), // "acceptConnection"
QT_MOC_LITERAL(10, 132, 11), // "receiveData"
QT_MOC_LITERAL(11, 144, 20), // "acceptFileConnection"
QT_MOC_LITERAL(12, 165, 18), // "updateFileProgress"
QT_MOC_LITERAL(13, 184, 12), // "displayError"
QT_MOC_LITERAL(14, 197, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(15, 226, 11), // "socketError"
QT_MOC_LITERAL(16, 238, 10), // "selectFile"
QT_MOC_LITERAL(17, 249, 8) // "sendFile"

    },
    "Server\0showCurrentDirFiles\0\0"
    "showNextDirFiles\0QListWidgetItem*\0"
    "item\0playCurrentItem\0lineEditTextChanged\0"
    "sendMessage\0acceptConnection\0receiveData\0"
    "acceptFileConnection\0updateFileProgress\0"
    "displayError\0QAbstractSocket::SocketError\0"
    "socketError\0selectFile\0sendFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Server[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a /* Public */,
       3,    1,   80,    2, 0x0a /* Public */,
       6,    1,   83,    2, 0x0a /* Public */,
       7,    1,   86,    2, 0x0a /* Public */,
       8,    0,   89,    2, 0x08 /* Private */,
       9,    0,   90,    2, 0x08 /* Private */,
      10,    0,   91,    2, 0x08 /* Private */,
      11,    0,   92,    2, 0x08 /* Private */,
      12,    0,   93,    2, 0x08 /* Private */,
      13,    1,   94,    2, 0x08 /* Private */,
      16,    0,   97,    2, 0x08 /* Private */,
      17,    0,   98,    2, 0x08 /* Private */,
      12,    1,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    2,

       0        // eod
};

void Server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Server *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showCurrentDirFiles(); break;
        case 1: _t->showNextDirFiles((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->playCurrentItem((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->lineEditTextChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->sendMessage(); break;
        case 5: _t->acceptConnection(); break;
        case 6: _t->receiveData(); break;
        case 7: _t->acceptFileConnection(); break;
        case 8: _t->updateFileProgress(); break;
        case 9: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 10: _t->selectFile(); break;
        case 11: _t->sendFile(); break;
        case 12: _t->updateFileProgress((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Server::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Server.data,
    qt_meta_data_Server,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Server::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Server.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

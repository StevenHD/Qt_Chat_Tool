/****************************************************************************
** Meta object code from reading C++ file 'qtclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QtChatTool/qtclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtClient_t {
    QByteArrayData data[23];
    char stringdata0[294];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtClient_t qt_meta_stringdata_QtClient = {
    {
QT_MOC_LITERAL(0, 0, 8), // "QtClient"
QT_MOC_LITERAL(1, 9, 13), // "connectServer"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 16), // "disconnectServer"
QT_MOC_LITERAL(4, 41, 11), // "receiveData"
QT_MOC_LITERAL(5, 53, 8), // "sendData"
QT_MOC_LITERAL(6, 62, 10), // "selectFile"
QT_MOC_LITERAL(7, 73, 8), // "sendFile"
QT_MOC_LITERAL(8, 82, 11), // "sendPicture"
QT_MOC_LITERAL(9, 94, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(10, 111, 4), // "item"
QT_MOC_LITERAL(11, 116, 18), // "updateFileProgress"
QT_MOC_LITERAL(12, 135, 16), // "showFileInfoList"
QT_MOC_LITERAL(13, 152, 13), // "QFileInfoList"
QT_MOC_LITERAL(14, 166, 9), // "pInfoList"
QT_MOC_LITERAL(15, 176, 19), // "getItemPropertyIcon"
QT_MOC_LITERAL(16, 196, 6), // "QIcon*"
QT_MOC_LITERAL(17, 203, 5), // "iType"
QT_MOC_LITERAL(18, 209, 11), // "showPicture"
QT_MOC_LITERAL(19, 221, 19), // "showCurrentDirFiles"
QT_MOC_LITERAL(20, 241, 16), // "showNextDirFiles"
QT_MOC_LITERAL(21, 258, 15), // "playCurrentItem"
QT_MOC_LITERAL(22, 274, 19) // "lineEditTextChanged"

    },
    "QtClient\0connectServer\0\0disconnectServer\0"
    "receiveData\0sendData\0selectFile\0"
    "sendFile\0sendPicture\0QListWidgetItem*\0"
    "item\0updateFileProgress\0showFileInfoList\0"
    "QFileInfoList\0pInfoList\0getItemPropertyIcon\0"
    "QIcon*\0iType\0showPicture\0showCurrentDirFiles\0"
    "showNextDirFiles\0playCurrentItem\0"
    "lineEditTextChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    1,  100,    2, 0x08 /* Private */,
      11,    1,  103,    2, 0x08 /* Private */,
      11,    0,  106,    2, 0x08 /* Private */,
      12,    1,  107,    2, 0x08 /* Private */,
      15,    1,  110,    2, 0x08 /* Private */,
      18,    0,  113,    2, 0x08 /* Private */,
      19,    0,  114,    2, 0x0a /* Public */,
      20,    1,  115,    2, 0x0a /* Public */,
      21,    1,  118,    2, 0x0a /* Public */,
      22,    1,  121,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    0x80000000 | 16, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void QtClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectServer(); break;
        case 1: _t->disconnectServer(); break;
        case 2: _t->receiveData(); break;
        case 3: _t->sendData(); break;
        case 4: _t->selectFile(); break;
        case 5: _t->sendFile(); break;
        case 6: _t->sendPicture((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 7: _t->updateFileProgress((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 8: _t->updateFileProgress(); break;
        case 9: _t->showFileInfoList((*reinterpret_cast< QFileInfoList(*)>(_a[1]))); break;
        case 10: { QIcon* _r = _t->getItemPropertyIcon((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QIcon**>(_a[0]) = std::move(_r); }  break;
        case 11: _t->showPicture(); break;
        case 12: _t->showCurrentDirFiles(); break;
        case 13: _t->showNextDirFiles((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 14: _t->playCurrentItem((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 15: _t->lineEditTextChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QtClient::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_QtClient.data,
    qt_meta_data_QtClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QtClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtClient.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QtClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

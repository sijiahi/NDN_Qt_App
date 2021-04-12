/****************************************************************************
** Meta object code from reading C++ file 'chat_demo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../app_ndn-cpp/chat_demo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chat_demo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Chat_demo_t {
    QByteArrayData data[12];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Chat_demo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Chat_demo_t qt_meta_stringdata_Chat_demo = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Chat_demo"
QT_MOC_LITERAL(1, 10, 15), // "on_Send_clicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "onChatStart"
QT_MOC_LITERAL(4, 39, 4), // "name"
QT_MOC_LITERAL(5, 44, 6), // "prefix"
QT_MOC_LITERAL(6, 51, 8), // "chatroom"
QT_MOC_LITERAL(7, 60, 18), // "onChatDataReceived"
QT_MOC_LITERAL(8, 79, 7), // "content"
QT_MOC_LITERAL(9, 87, 9), // "onNewUser"
QT_MOC_LITERAL(10, 97, 11), // "onUserLeave"
QT_MOC_LITERAL(11, 109, 24) // "onControlMessageReceived"

    },
    "Chat_demo\0on_Send_clicked\0\0onChatStart\0"
    "name\0prefix\0chatroom\0onChatDataReceived\0"
    "content\0onNewUser\0onUserLeave\0"
    "onControlMessageReceived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Chat_demo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    3,   45,    2, 0x08 /* Private */,
       7,    2,   52,    2, 0x08 /* Private */,
       9,    1,   57,    2, 0x08 /* Private */,
      10,    1,   60,    2, 0x08 /* Private */,
      11,    2,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    8,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    8,

       0        // eod
};

void Chat_demo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Chat_demo *_t = static_cast<Chat_demo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Send_clicked(); break;
        case 1: _t->onChatStart((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 2: _t->onChatDataReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->onNewUser((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->onUserLeave((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->onControlMessageReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject Chat_demo::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Chat_demo.data,
      qt_meta_data_Chat_demo,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Chat_demo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Chat_demo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Chat_demo.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Chat_demo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

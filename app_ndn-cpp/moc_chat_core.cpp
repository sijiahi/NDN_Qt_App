/****************************************************************************
** Meta object code from reading C++ file 'chat_core.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "chat_core.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chat_core.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Chat_t {
<<<<<<< HEAD
    QByteArrayData data[9];
    char stringdata0[81];
=======
    QByteArrayData data[6];
    char stringdata0[53];
>>>>>>> 73f85cd88c469ec05166c7729fca0f5d72976c7b
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Chat_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Chat_t qt_meta_stringdata_Chat = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Chat"
QT_MOC_LITERAL(1, 5, 16), // "chatDataReceived"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 4), // "from"
QT_MOC_LITERAL(4, 28, 7), // "content"
<<<<<<< HEAD
QT_MOC_LITERAL(5, 36, 7), // "addUser"
QT_MOC_LITERAL(6, 44, 10), // "removeUser"
QT_MOC_LITERAL(7, 55, 16), // "leftDataReceived"
QT_MOC_LITERAL(8, 72, 8) // "leaveNow"

    },
    "Chat\0chatDataReceived\0\0from\0content\0"
    "addUser\0removeUser\0leftDataReceived\0"
    "leaveNow"
=======
QT_MOC_LITERAL(5, 36, 16) // "leftDataReceived"

    },
    "Chat\0chatDataReceived\0\0from\0content\0"
    "leftDataReceived"
>>>>>>> 73f85cd88c469ec05166c7729fca0f5d72976c7b
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Chat[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
<<<<<<< HEAD
       5,   14, // methods
=======
       2,   14, // methods
>>>>>>> 73f85cd88c469ec05166c7729fca0f5d72976c7b
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
<<<<<<< HEAD
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       5,    1,   44,    2, 0x06 /* Public */,
       6,    1,   47,    2, 0x06 /* Public */,
       7,    2,   50,    2, 0x06 /* Public */,
       8,    0,   55,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void,
=======
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       5,    2,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
>>>>>>> 73f85cd88c469ec05166c7729fca0f5d72976c7b

       0        // eod
};

void Chat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Chat *_t = static_cast<Chat *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->chatDataReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
<<<<<<< HEAD
        case 1: _t->addUser((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->removeUser((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->leftDataReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->leaveNow(); break;
=======
        case 1: _t->leftDataReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
>>>>>>> 73f85cd88c469ec05166c7729fca0f5d72976c7b
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Chat::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Chat::chatDataReceived)) {
                *result = 0;
                return;
            }
        }
        {
<<<<<<< HEAD
            typedef void (Chat::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Chat::addUser)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Chat::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Chat::removeUser)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Chat::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Chat::leftDataReceived)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Chat::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Chat::leaveNow)) {
                *result = 4;
=======
            typedef void (Chat::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Chat::leftDataReceived)) {
                *result = 1;
>>>>>>> 73f85cd88c469ec05166c7729fca0f5d72976c7b
                return;
            }
        }
    }
}

const QMetaObject Chat::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Chat.data,
      qt_meta_data_Chat,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Chat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Chat::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Chat.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int Chat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
<<<<<<< HEAD
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
=======
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
>>>>>>> 73f85cd88c469ec05166c7729fca0f5d72976c7b
    }
    return _id;
}

// SIGNAL 0
void Chat::chatDataReceived(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
<<<<<<< HEAD
void Chat::addUser(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Chat::removeUser(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Chat::leftDataReceived(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Chat::leaveNow()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
=======
void Chat::leftDataReceived(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
>>>>>>> 73f85cd88c469ec05166c7729fca0f5d72976c7b
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

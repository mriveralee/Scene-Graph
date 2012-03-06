/****************************************************************************
** Meta object code from reading C++ file 'myframewidget.h'
**
** Created: Tue Mar 6 17:58:11 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../myframewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myframewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyFrameWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      29,   14,   14,   14, 0x05,
      46,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      61,   59,   14,   14, 0x0a,
      82,   14,   14,   14, 0x0a,
     103,   14,   14,   14, 0x0a,
     117,   59,   14,   14, 0x0a,
     137,   59,   14,   14, 0x0a,
     161,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyFrameWidget[] = {
    "MyFrameWidget\0\0sendTime(int)\0"
    "changeFrame(int)\0eraseFrame()\0,\0"
    "getImage(QImage,int)\0receiveGraph(Graph*)\0"
    "removeFrame()\0setClicked(int,int)\0"
    "updateImage(QImage,int)\0resetFrames()\0"
};

void MyFrameWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyFrameWidget *_t = static_cast<MyFrameWidget *>(_o);
        switch (_id) {
        case 0: _t->sendTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->changeFrame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->eraseFrame(); break;
        case 3: _t->getImage((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->receiveGraph((*reinterpret_cast< Graph*(*)>(_a[1]))); break;
        case 5: _t->removeFrame(); break;
        case 6: _t->setClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->updateImage((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->resetFrames(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyFrameWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyFrameWidget::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_MyFrameWidget,
      qt_meta_data_MyFrameWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyFrameWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyFrameWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyFrameWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyFrameWidget))
        return static_cast<void*>(const_cast< MyFrameWidget*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int MyFrameWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MyFrameWidget::sendTime(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyFrameWidget::changeFrame(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyFrameWidget::eraseFrame()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE

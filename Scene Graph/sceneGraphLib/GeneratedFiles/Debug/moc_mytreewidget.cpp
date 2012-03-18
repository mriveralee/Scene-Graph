/****************************************************************************
** Meta object code from reading C++ file 'mytreewidget.h'
**
** Created: Sun Mar 18 00:27:25 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mytreewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mytreewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyTreeWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,   40,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyTreeWidget[] = {
    "MyTreeWidget\0\0sendGraphFromTree(Graph*)\0"
    ",\0getTreeForBuilding(Graph*,bool)\0"
};

void MyTreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyTreeWidget *_t = static_cast<MyTreeWidget *>(_o);
        switch (_id) {
        case 0: _t->sendGraphFromTree((*reinterpret_cast< Graph*(*)>(_a[1]))); break;
        case 1: _t->getTreeForBuilding((*reinterpret_cast< Graph*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyTreeWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyTreeWidget::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_MyTreeWidget,
      qt_meta_data_MyTreeWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyTreeWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyTreeWidget))
        return static_cast<void*>(const_cast< MyTreeWidget*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int MyTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void MyTreeWidget::sendGraphFromTree(Graph * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

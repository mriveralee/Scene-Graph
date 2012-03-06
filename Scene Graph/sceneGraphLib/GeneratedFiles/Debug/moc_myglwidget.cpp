/****************************************************************************
** Meta object code from reading C++ file 'myglwidget.h'
**
** Created: Tue Mar 6 17:58:07 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../myglwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myglwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyGLWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      38,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   12,   11,   11, 0x05,
      37,   11,   11,   11, 0x05,
      57,   11,   11,   11, 0x05,
      74,   11,   11,   11, 0x05,
      82,   12,   11,   11, 0x05,
     111,   12,   11,   11, 0x05,
     133,   11,   11,   11, 0x05,
     156,   11,   11,   11, 0x05,
     170,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     187,   11,   11,   11, 0x0a,
     197,   11,   11,   11, 0x0a,
     216,   11,   11,   11, 0x0a,
     235,   11,   11,   11, 0x0a,
     250,   11,   11,   11, 0x0a,
     265,   11,   11,   11, 0x0a,
     278,   11,   11,   11, 0x0a,
     292,   11,   11,   11, 0x0a,
     308,   11,   11,   11, 0x0a,
     323,   11,   11,   11, 0x0a,
     343,   11,   11,   11, 0x0a,
     359,   11,   11,   11, 0x0a,
     372,   11,   11,   11, 0x0a,
     390,   11,   11,   11, 0x0a,
     411,   11,   11,   11, 0x0a,
     430,   11,   11,   11, 0x0a,
     449,   11,   11,   11, 0x0a,
     468,   11,   11,   11, 0x0a,
     487,   11,   11,   11, 0x0a,
     505,   11,   11,   11, 0x0a,
     523,   11,   11,   11, 0x0a,
     536,   11,   11,   11, 0x0a,
     551,   11,   11,   11, 0x0a,
     565,   11,   11,   11, 0x0a,
     582,   11,   11,   11, 0x0a,
     593,   11,   11,   11, 0x0a,
     618,   11,   11,   11, 0x0a,
     632,   11,   11,   11, 0x0a,
     651,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyGLWidget[] = {
    "MyGLWidget\0\0,\0buildTree(Graph*,bool)\0"
    "resetValues(double)\0resetValues(int)\0"
    "cNode()\0sendUpdatedImage(QImage,int)\0"
    "sendImage(QImage,int)\0setSelectedColumn(int)\0"
    "clearFrames()\0clearSelection()\0spin(int)\0"
    "translateX(double)\0translateY(double)\0"
    "scaleX(double)\0scaleY(double)\0"
    "resetGraph()\0colorRed(int)\0colorGreen(int)\0"
    "colorBlue(int)\0updateName(QString)\0"
    "updateMode(int)\0createNode()\0"
    "saveGeometry(int)\0saveNewName(QString)\0"
    "saveTransX(double)\0saveTransY(double)\0"
    "saveScaleX(double)\0saveScaleY(double)\0"
    "saveRotation(int)\0saveSides(double)\0"
    "saveRed(int)\0saveGreen(int)\0saveBlue(int)\0"
    "deleteTreeNode()\0addFrame()\0"
    "updateSelectedFrame(int)\0deleteFrame()\0"
    "updateFrameImage()\0updateInterpolateMode(bool)\0"
};

void MyGLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyGLWidget *_t = static_cast<MyGLWidget *>(_o);
        switch (_id) {
        case 0: _t->buildTree((*reinterpret_cast< Graph*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->resetValues((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->resetValues((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->cNode(); break;
        case 4: _t->sendUpdatedImage((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->sendImage((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->setSelectedColumn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->clearFrames(); break;
        case 8: _t->clearSelection(); break;
        case 9: _t->spin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->translateX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->translateY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->scaleX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->scaleY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->resetGraph(); break;
        case 15: _t->colorRed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->colorGreen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->colorBlue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->updateName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->updateMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->createNode(); break;
        case 21: _t->saveGeometry((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->saveNewName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->saveTransX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 24: _t->saveTransY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 25: _t->saveScaleX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 26: _t->saveScaleY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 27: _t->saveRotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->saveSides((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 29: _t->saveRed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->saveGreen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->saveBlue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->deleteTreeNode(); break;
        case 33: _t->addFrame(); break;
        case 34: _t->updateSelectedFrame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->deleteFrame(); break;
        case 36: _t->updateFrameImage(); break;
        case 37: _t->updateInterpolateMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyGLWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyGLWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_MyGLWidget,
      qt_meta_data_MyGLWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyGLWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyGLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyGLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyGLWidget))
        return static_cast<void*>(const_cast< MyGLWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int MyGLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 38)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 38;
    }
    return _id;
}

// SIGNAL 0
void MyGLWidget::buildTree(Graph * _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyGLWidget::resetValues(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyGLWidget::resetValues(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyGLWidget::cNode()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MyGLWidget::sendUpdatedImage(QImage _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyGLWidget::sendImage(QImage _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MyGLWidget::setSelectedColumn(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MyGLWidget::clearFrames()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void MyGLWidget::clearSelection()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'zgraph.h'
**
** Created: Tue 14. Jul 17:47:46 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../zgraph.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zgraph.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ZGraph[] = {

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
      13,    8,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      44,   40,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ZGraph[] = {
    "ZGraph\0\0text\0signal_from_zGraph(double)\0"
    "pos\0click_on_canvas(QPoint)\0"
};

void ZGraph::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ZGraph *_t = static_cast<ZGraph *>(_o);
        switch (_id) {
        case 0: _t->signal_from_zGraph((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->click_on_canvas((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ZGraph::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ZGraph::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ZGraph,
      qt_meta_data_ZGraph, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ZGraph::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ZGraph::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ZGraph::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ZGraph))
        return static_cast<void*>(const_cast< ZGraph*>(this));
    return QWidget::qt_metacast(_clname);
}

int ZGraph::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void ZGraph::signal_from_zGraph(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

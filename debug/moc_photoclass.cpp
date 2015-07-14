/****************************************************************************
** Meta object code from reading C++ file 'photoclass.h'
**
** Created: Mon 13. Jul 17:57:10 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../photoclass.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'photoclass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PhotoClass[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      17,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   19,   12,   11, 0x05,
      54,   19,   12,   11, 0x05,
      87,   19,   12,   11, 0x05,
     124,   19,   12,   11, 0x05,
     161,   19,   11,   11, 0x05,
     190,   19,   11,   11, 0x05,
     219,   19,   11,   11, 0x05,
     248,   19,   11,   11, 0x05,
     277,   19,   11,   11, 0x05,
     301,   19,   11,   11, 0x05,
     324,   19,   11,   11, 0x05,
     354,   19,   11,   11, 0x05,
     398,   19,   11,   11, 0x05,
     446,  442,   11,   11, 0x05,
     497,  442,   11,   11, 0x05,
     554,  548,   11,   11, 0x05,
     599,  548,   11,   11, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_PhotoClass[] = {
    "PhotoClass\0\0double\0a\0"
    "photo_signal_transform_x(double)\0"
    "photo_signal_transform_y(double)\0"
    "photo_signal_inv_transform_x(double)\0"
    "photo_signal_inv_transform_y(double)\0"
    "photo_signla_x_shift(double)\0"
    "photo_signla_y_shift(double)\0"
    "photo_signla_x_scale(double)\0"
    "photo_signla_y_scale(double)\0"
    "photo_signla_fi(double)\0photo_signla_k(double)\0"
    "photo_signla_fi_shift(double)\0"
    "photo_signal_to_change_scale_scale1(double)\0"
    "photo_signal_to_change_scale_scale2(double)\0"
    "a,b\0photo_signal_to_change_scale_angle1(double,double)\0"
    "photo_signal_to_change_scale_angle2(double,double)\0"
    "point\0photo_signal_to_change_scale_point1(QPointF)\0"
    "photo_signal_to_change_scale_point22(QPointF)\0"
};

void PhotoClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PhotoClass *_t = static_cast<PhotoClass *>(_o);
        switch (_id) {
        case 0: { double _r = _t->photo_signal_transform_x((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 1: { double _r = _t->photo_signal_transform_y((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 2: { double _r = _t->photo_signal_inv_transform_x((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 3: { double _r = _t->photo_signal_inv_transform_y((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 4: _t->photo_signla_x_shift((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->photo_signla_y_shift((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->photo_signla_x_scale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->photo_signla_y_scale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->photo_signla_fi((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->photo_signla_k((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->photo_signla_fi_shift((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->photo_signal_to_change_scale_scale1((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->photo_signal_to_change_scale_scale2((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->photo_signal_to_change_scale_angle1((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 14: _t->photo_signal_to_change_scale_angle2((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 15: _t->photo_signal_to_change_scale_point1((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 16: _t->photo_signal_to_change_scale_point22((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PhotoClass::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PhotoClass::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PhotoClass,
      qt_meta_data_PhotoClass, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PhotoClass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PhotoClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PhotoClass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PhotoClass))
        return static_cast<void*>(const_cast< PhotoClass*>(this));
    return QWidget::qt_metacast(_clname);
}

int PhotoClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
double PhotoClass::photo_signal_transform_x(double _t1)
{
    double _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
double PhotoClass::photo_signal_transform_y(double _t1)
{
    double _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
double PhotoClass::photo_signal_inv_transform_x(double _t1)
{
    double _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
    return _t0;
}

// SIGNAL 3
double PhotoClass::photo_signal_inv_transform_y(double _t1)
{
    double _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
    return _t0;
}

// SIGNAL 4
void PhotoClass::photo_signla_x_shift(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PhotoClass::photo_signla_y_shift(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PhotoClass::photo_signla_x_scale(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PhotoClass::photo_signla_y_scale(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void PhotoClass::photo_signla_fi(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void PhotoClass::photo_signla_k(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void PhotoClass::photo_signla_fi_shift(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void PhotoClass::photo_signal_to_change_scale_scale1(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void PhotoClass::photo_signal_to_change_scale_scale2(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void PhotoClass::photo_signal_to_change_scale_angle1(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void PhotoClass::photo_signal_to_change_scale_angle2(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void PhotoClass::photo_signal_to_change_scale_point1(QPointF _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void PhotoClass::photo_signal_to_change_scale_point22(QPointF _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}
QT_END_MOC_NAMESPACE

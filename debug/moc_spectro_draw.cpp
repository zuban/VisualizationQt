/****************************************************************************
** Meta object code from reading C++ file 'spectro_draw.h'
**
** Created: Fri 10. Apr 15:40:15 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../spectro_draw.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spectro_draw.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Spectro_draw[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      23,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   14,   13,   13, 0x05,
      50,   46,   13,   13, 0x05,
      84,   78,   13,   13, 0x05,
     124,  122,  115,   13, 0x05,
     151,  122,  115,   13, 0x05,
     178,  122,  115,   13, 0x05,
     209,  122,  115,   13, 0x05,
     240,  122,   13,   13, 0x05,
     263,  122,   13,   13, 0x05,
     286,  122,   13,   13, 0x05,
     309,  122,   13,   13, 0x05,
     332,  122,   13,   13, 0x05,
     350,  122,   13,   13, 0x05,
     367,  122,   13,   13, 0x05,
     391,   46,   13,   13, 0x05,
     412,  122,   13,   13, 0x05,
     450,  122,   13,   13, 0x05,
     492,  488,   13,   13, 0x05,
     537,  488,   13,   13, 0x05,
     588,  582,   13,   13, 0x05,
     627,  582,   13,   13, 0x05,
     667,  122,   13,   13, 0x05,
     698,   13,   13,   13, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Spectro_draw[] = {
    "Spectro_draw\0\0pos\0signal_form_canvas(QPointF)\0"
    "str\0signal_change_text(QString)\0p1,p2\0"
    "signal_zoomer(QPointF,QPointF)\0double\0"
    "a\0signal_transform_x(double)\0"
    "signal_transform_y(double)\0"
    "signal_inv_transform_x(double)\0"
    "signal_inv_transform_y(double)\0"
    "signla_x_shift(double)\0signla_y_shift(double)\0"
    "signla_x_scale(double)\0signla_y_scale(double)\0"
    "signla_fi(double)\0signla_k(double)\0"
    "signla_fi_shift(double)\0signal_test(QString)\0"
    "signal_to_change_scale_scale1(double)\0"
    "signal_to_change_scale_scale2(double)\0"
    "a,b\0signal_to_change_scale_angle1(double,double)\0"
    "signal_to_change_scale_angle2(double,double)\0"
    "point\0signal_to_change_scale_point1(QPointF)\0"
    "signal_to_change_scale_point22(QPointF)\0"
    "signal_to_change_scale(double)\0"
    "signal_to_zoom_norm()\0"
};

void Spectro_draw::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Spectro_draw *_t = static_cast<Spectro_draw *>(_o);
        switch (_id) {
        case 0: _t->signal_form_canvas((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 1: _t->signal_change_text((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->signal_zoomer((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2]))); break;
        case 3: { double _r = _t->signal_transform_x((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 4: { double _r = _t->signal_transform_y((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 5: { double _r = _t->signal_inv_transform_x((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 6: { double _r = _t->signal_inv_transform_y((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 7: _t->signla_x_shift((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->signla_y_shift((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->signla_x_scale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->signla_y_scale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->signla_fi((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->signla_k((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->signla_fi_shift((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->signal_test((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->signal_to_change_scale_scale1((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->signal_to_change_scale_scale2((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->signal_to_change_scale_angle1((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 18: _t->signal_to_change_scale_angle2((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 19: _t->signal_to_change_scale_point1((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 20: _t->signal_to_change_scale_point22((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 21: _t->signal_to_change_scale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 22: _t->signal_to_zoom_norm(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Spectro_draw::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Spectro_draw::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Spectro_draw,
      qt_meta_data_Spectro_draw, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Spectro_draw::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Spectro_draw::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Spectro_draw::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Spectro_draw))
        return static_cast<void*>(const_cast< Spectro_draw*>(this));
    return QWidget::qt_metacast(_clname);
}

int Spectro_draw::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void Spectro_draw::signal_form_canvas(QPointF _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Spectro_draw::signal_change_text(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Spectro_draw::signal_zoomer(QPointF _t1, QPointF _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
double Spectro_draw::signal_transform_x(double _t1)
{
    double _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
    return _t0;
}

// SIGNAL 4
double Spectro_draw::signal_transform_y(double _t1)
{
    double _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
    return _t0;
}

// SIGNAL 5
double Spectro_draw::signal_inv_transform_x(double _t1)
{
    double _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
    return _t0;
}

// SIGNAL 6
double Spectro_draw::signal_inv_transform_y(double _t1)
{
    double _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
    return _t0;
}

// SIGNAL 7
void Spectro_draw::signla_x_shift(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Spectro_draw::signla_y_shift(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Spectro_draw::signla_x_scale(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Spectro_draw::signla_y_scale(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Spectro_draw::signla_fi(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Spectro_draw::signla_k(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Spectro_draw::signla_fi_shift(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Spectro_draw::signal_test(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void Spectro_draw::signal_to_change_scale_scale1(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void Spectro_draw::signal_to_change_scale_scale2(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void Spectro_draw::signal_to_change_scale_angle1(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void Spectro_draw::signal_to_change_scale_angle2(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void Spectro_draw::signal_to_change_scale_point1(QPointF _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void Spectro_draw::signal_to_change_scale_point22(QPointF _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void Spectro_draw::signal_to_change_scale(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void Spectro_draw::signal_to_zoom_norm()
{
    QMetaObject::activate(this, &staticMetaObject, 22, 0);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'spectro_plot.h'
**
** Created: Tue 14. Jul 17:47:50 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../spectro_plot.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spectro_plot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Spectro_Plot[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   44,   13,   13, 0x0a,
      79,   73,   13,   13, 0x0a,
     112,   13,   13,   13, 0x0a,
     144,  142,  135,   13, 0x0a,
     162,  160,  135,   13, 0x0a,
     178,  142,  135,   13, 0x0a,
     198,  160,  135,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Spectro_Plot[] = {
    "Spectro_Plot\0\0a\0signal_from_vector(QString)\0"
    "pos\0slot_for_spectr(QPointF)\0p1,p2\0"
    "slot_for_zoomer(QPointF,QPointF)\0"
    "slot_for_zoomer_norm()\0double\0x\0"
    "trans_x(double)\0y\0trans_y(double)\0"
    "inv_trans_x(double)\0inv_trans_y(double)\0"
};

void Spectro_Plot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Spectro_Plot *_t = static_cast<Spectro_Plot *>(_o);
        switch (_id) {
        case 0: _t->signal_from_vector((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slot_for_spectr((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 2: _t->slot_for_zoomer((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2]))); break;
        case 3: _t->slot_for_zoomer_norm(); break;
        case 4: { double _r = _t->trans_x((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 5: { double _r = _t->trans_y((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 6: { double _r = _t->inv_trans_x((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 7: { double _r = _t->inv_trans_y((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Spectro_Plot::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Spectro_Plot::staticMetaObject = {
    { &QwtPlot::staticMetaObject, qt_meta_stringdata_Spectro_Plot,
      qt_meta_data_Spectro_Plot, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Spectro_Plot::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Spectro_Plot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Spectro_Plot::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Spectro_Plot))
        return static_cast<void*>(const_cast< Spectro_Plot*>(this));
    return QwtPlot::qt_metacast(_clname);
}

int Spectro_Plot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Spectro_Plot::signal_from_vector(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

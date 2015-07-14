/****************************************************************************
** Meta object code from reading C++ file 'form.h'
**
** Created: Fri 10. Apr 15:40:14 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../form.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Form[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x05,
      42,    5,    5,    5, 0x05,
      77,    5,    5,    5, 0x05,
     115,    5,    5,    5, 0x05,
     160,  156,    5,    5, 0x05,
     224,  216,    5,    5, 0x05,
     269,  216,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
     314,    5,    5,    5, 0x08,
     343,    5,    5,    5, 0x08,
     371,    5,    5,    5, 0x08,
     402,    5,    5,    5, 0x08,
     441,  436,    5,    5, 0x08,
     490,  216,    5,    5, 0x08,
     528,  216,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Form[] = {
    "Form\0\0signal_on_read_pushButton_clicked()\0"
    "signal_on_add_pushButton_clicked()\0"
    "signal_on_export_pushButton_clicked()\0"
    "signal_on_test_cuda_pushButton_clicked()\0"
    "str\0signal_on_test_row_column_lineEdit_textChanged(QString)\0"
    "checked\0signal_on_test_col_radioButton_toggled(bool)\0"
    "signal_on_test_row_radioButton_toggled(bool)\0"
    "on_read_pushButton_clicked()\0"
    "on_add_pushButton_clicked()\0"
    "on_export_pushButton_clicked()\0"
    "on_test_cuda_pushButton_clicked()\0"
    "arg1\0on_test_row_column_lineEdit_textChanged(QString)\0"
    "on_test_col_radioButton_toggled(bool)\0"
    "on_test_row_radioButton_toggled(bool)\0"
};

void Form::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Form *_t = static_cast<Form *>(_o);
        switch (_id) {
        case 0: _t->signal_on_read_pushButton_clicked(); break;
        case 1: _t->signal_on_add_pushButton_clicked(); break;
        case 2: _t->signal_on_export_pushButton_clicked(); break;
        case 3: _t->signal_on_test_cuda_pushButton_clicked(); break;
        case 4: _t->signal_on_test_row_column_lineEdit_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->signal_on_test_col_radioButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->signal_on_test_row_radioButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_read_pushButton_clicked(); break;
        case 8: _t->on_add_pushButton_clicked(); break;
        case 9: _t->on_export_pushButton_clicked(); break;
        case 10: _t->on_test_cuda_pushButton_clicked(); break;
        case 11: _t->on_test_row_column_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_test_col_radioButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_test_row_radioButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Form::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Form::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Form,
      qt_meta_data_Form, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Form::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Form::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Form::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Form))
        return static_cast<void*>(const_cast< Form*>(this));
    return QWidget::qt_metacast(_clname);
}

int Form::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Form::signal_on_read_pushButton_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Form::signal_on_add_pushButton_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Form::signal_on_export_pushButton_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Form::signal_on_test_cuda_pushButton_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Form::signal_on_test_row_column_lineEdit_textChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Form::signal_on_test_col_radioButton_toggled(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Form::signal_on_test_row_radioButton_toggled(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE

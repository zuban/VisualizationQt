/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created: Fri 10. Apr 15:40:11 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      42,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,    8,    7,    7, 0x08,
      46,   41,    7,    7, 0x08,
      68,   66,    7,    7, 0x08,
      99,    7,    7,    7, 0x08,
     133,    7,    7,    7, 0x08,
     171,  166,    7,    7, 0x08,
     223,  166,    7,    7, 0x08,
     283,  166,    7,    7, 0x08,
     336,  166,    7,    7, 0x08,
     389,  166,    7,    7, 0x08,
     434,    7,    7,    7, 0x08,
     469,    7,    7,    7, 0x08,
     515,  507,    7,    7, 0x08,
     560,    7,    7,    7, 0x08,
     596,    7,    7,    7, 0x08,
     636,    7,    7,    7, 0x08,
     669,    7,    7,    7, 0x08,
     706,  166,    7,    7, 0x08,
     756,  166,    7,    7, 0x08,
     807,  166,    7,    7, 0x08,
     861,    7,    7,    7, 0x08,
     902,  166,    7,    7, 0x08,
     954,    7,    7,    7, 0x08,
     992,    7,    7,    7, 0x08,
    1026,  166,    7,    7, 0x08,
    1079,  166,    7,    7, 0x08,
    1130,    7,    7,    7, 0x08,
    1170,    7,    7,    7, 0x08,
    1207,    7,    7,    7, 0x08,
    1240,  166,    7,    7, 0x08,
    1293,  166,    7,    7, 0x08,
    1344,    7,    7,    7, 0x08,
    1384,    7,    7,    7, 0x08,
    1421,    7,    7,    7, 0x08,
    1454,  507,    7,    7, 0x08,
    1491,  507,    7,    7, 0x08,
    1527,  507,    7,    7, 0x08,
    1563,  507,    7,    7, 0x08,
    1601,  507,    7,    7, 0x08,
    1644,  507,    7,    7, 0x08,
    1687,  166,    7,    7, 0x08,
    1740, 1736,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0event\0resizeEvent(QResizeEvent*)\0"
    "text\0change_text(double)\0a\0"
    "enable_delete_pushbutton(bool)\0"
    "slot_on_read_pushButton_clicked()\0"
    "slot_on_add_pushButton_clicked()\0arg1\0"
    "on_graph_type_comboBox_currentIndexChanged(QString)\0"
    "on_graph_lin_log_type_comboBox_currentIndexChanged(QString)\0"
    "on_graph_color_comboBox_currentIndexChanged(QString)\0"
    "on_graph_style_comboBox_currentIndexChanged(QString)\0"
    "on_graph_wight_spinBox_valueChanged(QString)\0"
    "on_add_marker_pushButton_clicked()\0"
    "on_delete_marker_pushButton_clicked()\0"
    "checked\0on_reference_marker_pushButton_toggled(bool)\0"
    "slot_on_export_pushButton_clicked()\0"
    "on_ampl_autoscale_radioButton_clicked()\0"
    "on_ampl_up_radioButton_clicked()\0"
    "on_ampl_manual_radioButton_clicked()\0"
    "on_ampl_max_comboBox_currentIndexChanged(QString)\0"
    "on_ampl_span_comboBox_currentIndexChanged(QString)\0"
    "on_phase_center_comboBox_currentIndexChanged(QString)\0"
    "on_phase_autoscale_radioButton_clicked()\0"
    "on_phase_span_comboBox_currentIndexChanged(QString)\0"
    "on_phase_manual_radioButton_clicked()\0"
    "on_phase_up_radioButton_clicked()\0"
    "on_real_center_comboBox_currentIndexChanged(QString)\0"
    "on_real_span_comboBox_currentIndexChanged(QString)\0"
    "on_real_autoscale_radioButton_clicked()\0"
    "on_real_manual_radioButton_clicked()\0"
    "on_real_up_radioButton_clicked()\0"
    "on_imag_center_comboBox_currentIndexChanged(QString)\0"
    "on_imag_span_comboBox_currentIndexChanged(QString)\0"
    "on_imag_autoscale_radioButton_clicked()\0"
    "on_imag_manual_radioButton_clicked()\0"
    "on_imag_up_radioButton_clicked()\0"
    "on_XY_scale_pushButton_toggled(bool)\0"
    "on_X_scale_pushButton_toggled(bool)\0"
    "on_Y_scale_pushButton_toggled(bool)\0"
    "on_magnifier_pushButton_toggled(bool)\0"
    "slot_on_test_col_radioButton_toggled(bool)\0"
    "slot_on_test_row_radioButton_toggled(bool)\0"
    "on_test_row_column_lineEdit_textChanged(QString)\0"
    "str\0slot_on_test_cuda_pushButton_clicked(QString)\0"
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Widget *_t = static_cast<Widget *>(_o);
        switch (_id) {
        case 0: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 1: _t->change_text((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->enable_delete_pushbutton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->slot_on_read_pushButton_clicked(); break;
        case 4: _t->slot_on_add_pushButton_clicked(); break;
        case 5: _t->on_graph_type_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_graph_lin_log_type_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_graph_color_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_graph_style_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_graph_wight_spinBox_valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_add_marker_pushButton_clicked(); break;
        case 11: _t->on_delete_marker_pushButton_clicked(); break;
        case 12: _t->on_reference_marker_pushButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->slot_on_export_pushButton_clicked(); break;
        case 14: _t->on_ampl_autoscale_radioButton_clicked(); break;
        case 15: _t->on_ampl_up_radioButton_clicked(); break;
        case 16: _t->on_ampl_manual_radioButton_clicked(); break;
        case 17: _t->on_ampl_max_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: _t->on_ampl_span_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->on_phase_center_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->on_phase_autoscale_radioButton_clicked(); break;
        case 21: _t->on_phase_span_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->on_phase_manual_radioButton_clicked(); break;
        case 23: _t->on_phase_up_radioButton_clicked(); break;
        case 24: _t->on_real_center_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 25: _t->on_real_span_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 26: _t->on_real_autoscale_radioButton_clicked(); break;
        case 27: _t->on_real_manual_radioButton_clicked(); break;
        case 28: _t->on_real_up_radioButton_clicked(); break;
        case 29: _t->on_imag_center_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 30: _t->on_imag_span_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 31: _t->on_imag_autoscale_radioButton_clicked(); break;
        case 32: _t->on_imag_manual_radioButton_clicked(); break;
        case 33: _t->on_imag_up_radioButton_clicked(); break;
        case 34: _t->on_XY_scale_pushButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 35: _t->on_X_scale_pushButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 36: _t->on_Y_scale_pushButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 37: _t->on_magnifier_pushButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 38: _t->slot_on_test_col_radioButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 39: _t->slot_on_test_row_radioButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 40: _t->on_test_row_column_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 41: _t->slot_on_test_cuda_pushButton_clicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Widget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget,
      qt_meta_data_Widget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
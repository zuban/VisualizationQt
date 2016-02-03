#ifndef SPECTRWIDGET_H
#define SPECTRWIDGET_H

#include <QWidget>
#include "z2vector.h"
#include "spectro_plot.h"
#include <QObject>
#include "iodata.h"
//#include "form_spectr.h"
//#include "ui_form_spectr.h"
//struct double_complex {double x; double y;};


class Form_Spectr;

namespace Ui {
class SpectrWidget;

}

class SpectrWidget : public QWidget
{
    Q_OBJECT
public:

    Form_Spectr *control;
    IOData *data;

    double_complex MakeComplex(double x,double y);
    float_complex fMakeComplex(float x,float y);
    Spectro_Plot* sp_plot;
    Z2Vector *z2vector;

    bool zoomer_mod;

    explicit SpectrWidget(QWidget *parent = 0);
    ~SpectrWidget();


signals:
    void set_data_2D(QString str);
    void set_gate_marker(double l_angl, double r_angl);
public slots:
    void export_spectr_pushbutton();
    void signal_on_pushButton_clicked();
private slots:

    void change_FI0_cuda_test(int count);
    void get_control(Form_Spectr* control1);
    void resizeEvent ( QResizeEvent * event );
    void change_x_shift(double a);
    void change_y_shift(double a);
    void change_x_scale(double a);
    void change_y_scale(double a);
    void change_fi(double a);
    void change_k(double a);
    void slot_to_change_scale_scale1(double a);
    void slot_to_change_scale_scale2(double a);
    void slot_to_change_scale_angle1(double a,double b);
    void slot_to_change_scale_angle2(double a,double b);
    void slot_to_change_scale_point1(QPointF point);
    void slot_to_change_scale_point22(QPointF point);

    void on_read_pushbutton_clicked();

    void on_type_combobox_currentIndexChanged(const QString &arg1);

    void on_max_spinbox_valueChanged(int arg1);

    void on_min_spinbox_valueChanged(double arg1);

    void on_rect_pushButton_clicked();

    void on_polygon_pushButton_clicked();

    void on_spec_type_combobox_currentIndexChanged(const QString &arg1);

    void on_select_point_pushButton_clicked();

    void on_line_pushButton_clicked();

    void on_color_comboBox_currentIndexChanged(const QString &arg1);

    void on_rect_pushButton_toggled(bool checked);

    void on_polygon_pushButton_toggled(bool checked);

    void on_circle_pushButton_toggled(bool checked);

    void on_line_pushButton_toggled(bool checked);

    void on_delete_last_pushButton_clicked();

    void on_select_point_pushButton_toggled(bool checked);

    void on_cont_read_pushButton_clicked();

    void on_zoom_pushButton_toggled(bool checked);

    void on_x_scale_lineEdit_textChanged(const QString &arg1);

    void on_x_shift_lineEdit_textChanged(const QString &arg1);

    void on_y_shift_lineEdit_textChanged(const QString &arg1);

    void on_y_scale_lineEdit_textChanged(const QString &arg1);

    void on_delete_sketch_pushButton_clicked();

    void on_fi_shift_lineEdit_textChanged(const QString &arg1);

    void on_fi_lineEdit_textChanged(const QString &arg1);

    void on_flip_checkBox_toggled(bool checked);

    void on_sketch_checkBox_toggled(bool checked);

    void on_scale_checkBox_toggled(bool checked);

    void on_fi_shift_slider_sliderMoved(int position);

    void on_x_y_scale_pushButton_clicked();

    void on_angle_pushbutton_clicked();

    void on_x_y_shitft_pushButton_clicked();

    void on_ok_x_y_scale_pushButton_clicked();

    void on_ok_angle_pushbutton_clicked();

    void on_ok_x_y_shift_pushButton_clicked();

    void on_x_y_scale_pushButton_2_clicked();

    void on_angle_pushbutton_2_clicked();

    void on_x_y_shitft_pushButton_2_clicked();


private:
    Ui::SpectrWidget *ui;
};

#endif // SPECTRWIDGET_H

#ifndef FORM_SPECTR_H
#define FORM_SPECTR_H

#include <QWidget>
#include "ui_widget.h"

#include "spectrwidget.h"


namespace Ui {
class Form_Spectr;
}

class Form_Spectr : public QWidget
{
    Q_OBJECT
    class SpectrWidget;
public:

    SpectrWidget *spectr;
    Ui::Form_Spectr *ui;

    explicit Form_Spectr(QWidget *parent = 0);
    ~Form_Spectr();

signals:
    void signal_on_export_spectr_pushbutton_clicked();
    void  signal_on_read_pushbutton_clicked();
    void  signal_on_cont_read_pushButton_clicked();
    void signal_on_x_y_scale_pushButton_clicked();
    void signal_on_ok_x_y_scale_pushButton_clicked();
    void signal_on_x_y_scale_pushButton_2_clicked();
    void signal_on_scale_checkBox_toggled(bool checked);
    void signal_on_flip_checkBox_toggled(bool checked);
    void signal_on_angle_pushbutton_clicked();
    void signal_on_ok_angle_pushbutton_clicked();
    void signal_on_angle_pushbutton_2_clicked();
    void signal_on_x_y_shitft_pushButton_clicked();
    void signal_on_ok_x_y_shift_pushButton_clicked();
    void signal_on_x_y_shitft_pushButton_2_clicked();
    void signal_on_x_shift_lineEdit_textChanged(QString arg1);
    void signal_on_fi_lineEdit_textChanged(QString arg1);
    void signal_on_y_shift_lineEdit_textChanged(QString arg1);
    void signal_on_x_scale_lineEdit_textChanged(QString arg1);
    void signal_on_y_scale_lineEdit_textChanged(QString arg1);
    void signal_on_k_lineEdit_textChanged(QString arg1);
    void change_FI0_cuda_test(int count);
    void signal_on_pushButton_clicked();
private slots:
    void on_read_pushbutton_clicked();
    void on_cont_read_pushButton_clicked();
    void on_x_y_scale_pushButton_clicked();
    void on_ok_x_y_scale_pushButton_clicked();
    void on_x_y_scale_pushButton_2_clicked();
    void on_scale_checkBox_toggled(bool checked);
    void on_flip_checkBox_toggled(bool checked);
    void on_angle_pushbutton_clicked();
    void on_ok_angle_pushbutton_clicked();
    void on_angle_pushbutton_2_clicked();
    void on_x_y_shitft_pushButton_clicked();
    void on_ok_x_y_shift_pushButton_clicked();
    void on_x_y_shitft_pushButton_2_clicked();
    void on_x_shift_lineEdit_textChanged(const QString &arg1);
    void on_fi_lineEdit_textChanged(const QString &arg1);
    void on_y_shift_lineEdit_textChanged(const QString &arg1);
    void on_x_scale_lineEdit_textChanged(const QString &arg1);
    void on_y_scale_lineEdit_textChanged(const QString &arg1);
    void on_k_lineEdit_textChanged(const QString &arg1);
    void on_horizontalSlider_for_cuda_test_valueChanged(int value);
    void on_Azstart_lieedit_data_textChanged(const QString &arg1);
    void on_Azstop_lineedit_data_textChanged(const QString &arg1);
    void on_Az_span_lineEdit_textChanged(const QString &arg1);
    void on_export_spectr_pushbutton_clicked();
    void on_pushButton_clicked();

private:
};

#endif // FORM_SPECTR_H

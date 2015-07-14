#include "form_spectr.h"
#include "ui_form_spectr.h"

#include "spectrwidget.h"

Form_Spectr::Form_Spectr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Spectr)
{
    ui->setupUi(this);
}

Form_Spectr::~Form_Spectr()
{
    delete ui;
}

void Form_Spectr::on_read_pushbutton_clicked()
{
 emit signal_on_read_pushbutton_clicked();
}


void Form_Spectr::on_cont_read_pushButton_clicked()
{
    emit signal_on_cont_read_pushButton_clicked();
}

void Form_Spectr::on_x_y_scale_pushButton_clicked()
{
    emit signal_on_x_y_scale_pushButton_clicked();
}

void Form_Spectr::on_ok_x_y_scale_pushButton_clicked()
{
    emit signal_on_ok_x_y_scale_pushButton_clicked();
}
//QString Form_Spectr::get_x_y_scale_lineedit1()
//{
//    return ui->x_y_scale_lineedit1->text();
//}
//QString Form_Spectr::get_x_y_scale_lineedit2()
//{
//    return ui->x_y_scale_lineedit2->text();
//}
//QString Form_Spectr::get_x_scale_lineEdit()
//{
//    return ui->x_scale_lineEdit->text();
//}
//QString Form_Spectr::get_y_scale_lineEdit()
//{
//    return ui->y_scale_lineEdit->text();
//}
//QString Form_Spectr::get_angle_lineedit2()
//{
//    return ui->angle_lineedit2->text();
//}
//QString Form_Spectr::get_angle_lineedit1()
//{
//    return ui->angle_lineedit1->text();
//}
//QString Form_Spectr::get_fi_lineEdit()
//{
//    return ui->fi_lineEdit->text();
//}

//QString Form_Spectr::get_x_shift_lineedit1()
//{
//    return ui->x_shift_lineedit1->text();
//}
//QString Form_Spectr::get_x_shift_lineedit2()
//{
//    return ui->x_shift_lineedit2->text();
//}
//QString Form_Spectr::get_y_shift_lineedit2()
//{
//    return ui->y_shift_lineedit2->text();
//}
//QString Form_Spectr::get_y_shift_lineedit1()
//{
//    return ui->y_shift_lineedit1->text();
//}

void Form_Spectr::on_x_y_scale_pushButton_2_clicked()
{
    emit signal_on_x_y_scale_pushButton_2_clicked();
}

void Form_Spectr::on_scale_checkBox_toggled(bool checked)
{
    emit signal_on_scale_checkBox_toggled(checked);
}

void Form_Spectr::on_flip_checkBox_toggled(bool checked)
{
    emit signal_on_flip_checkBox_toggled(checked);
}

void Form_Spectr::on_angle_pushbutton_clicked()
{
    emit signal_on_angle_pushbutton_clicked();
}

void Form_Spectr::on_ok_angle_pushbutton_clicked()
{
    emit signal_on_ok_angle_pushbutton_clicked();
}

void Form_Spectr::on_angle_pushbutton_2_clicked()
{
    emit signal_on_angle_pushbutton_2_clicked();
}

void Form_Spectr::on_x_y_shitft_pushButton_clicked()
{
    emit signal_on_x_y_shitft_pushButton_clicked();
}

void Form_Spectr::on_ok_x_y_shift_pushButton_clicked()
{
    emit signal_on_ok_x_y_shift_pushButton_clicked();
}

void Form_Spectr::on_x_y_shitft_pushButton_2_clicked()
{
    emit signal_on_x_y_shitft_pushButton_2_clicked();
}



//void Form_Spectr::set_x_y_scale_lineedit1(QString str)
//{
//    ui->x_y_scale_lineedit1->setText(str);
//}
//void Form_Spectr::set_x_y_scale_lineedit2(QString str)
//{
//    ui->x_y_scale_lineedit2->setText(str);
//}
//void Form_Spectr::set_x_scale_lineEdit(QString str)
//{
//    ui->x_scale_lineEdit->setText(str);
//}
//void Form_Spectr::set_y_scale_lineEdit(QString str)
//{
//    ui->y_scale_lineEdit->setText(str);
//}
//void Form_Spectr::set_angle_lineedit2(QString str)
//{
//    ui->angle_lineedit2->setText(str);
//}
//void Form_Spectr::set_angle_lineedit1(QString str)
//{
//    ui->angle_lineedit1->setText(str);
//}
//void Form_Spectr::set_fi_lineEdit(QString str)
//{
//    ui->fi_lineEdit->setText(str);
//}
//void Form_Spectr::set_x_shift_lineedit1(QString str)
//{
//    ui->x_shift_lineedit1->setText(str);
//}

//void Form_Spectr::set_x_shift_lineedit2(QString str)
//{
//    ui->x_shift_lineedit2->setText(str);
//}
//void Form_Spectr::set_y_shift_lineedit2(QString str)
//{
//    ui->y_shift_lineedit2->setText(str);
//}
//void Form_Spectr::set_y_shift_lineedit1(QString str)
//{
//    ui->y_shift_lineedit1->setText(str);
//}

void Form_Spectr::on_x_shift_lineEdit_textChanged(const QString &arg1)
{
    emit signal_on_x_shift_lineEdit_textChanged(arg1);
}

void Form_Spectr::on_fi_lineEdit_textChanged(const QString &arg1)
{
    emit signal_on_fi_lineEdit_textChanged(arg1);
}

void Form_Spectr::on_y_shift_lineEdit_textChanged(const QString &arg1)
{
    emit signal_on_y_shift_lineEdit_textChanged(arg1);
}

void Form_Spectr::on_x_scale_lineEdit_textChanged(const QString &arg1)
{
    emit signal_on_x_scale_lineEdit_textChanged(arg1);
}

void Form_Spectr::on_y_scale_lineEdit_textChanged(const QString &arg1)
{
    emit signal_on_y_scale_lineEdit_textChanged(arg1);
}

void Form_Spectr::on_k_lineEdit_textChanged(const QString &arg1)
{
    emit signal_on_k_lineEdit_textChanged(arg1);
}

void Form_Spectr::on_horizontalSlider_for_cuda_test_valueChanged(int value)
{
    emit change_FI0_cuda_test(value);
}

void Form_Spectr::on_fi_shift_slider_valueChanged(int value)
{

}

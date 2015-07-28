#include "form_spectr.h"
#include "ui_form_spectr.h"
#include <QMessageBox>

#include "spectrwidget.h"

Form_Spectr::Form_Spectr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Spectr)
{
    ui->setupUi(this);

    ui->x_y_scale_lineedit1->setEnabled(false);
    ui->x_y_scale_lineedit2->setEnabled(false);
    ui->x_shift_lineedit1->setEnabled(false);
    ui->y_shift_lineedit2->setEnabled(false);
    ui->angle_lineedit1->setEnabled(false);
    ui->angle_lineedit2->setEnabled(false);

    ui->angle_pushbutton->setEnabled(false);
    ui->angle_pushbutton_2->setEnabled(false);
    ui->x_y_scale_pushButton->setEnabled(false);
    ui->x_y_scale_pushButton_2->setEnabled(false);
    ui->x_y_shitft_pushButton->setEnabled(false);
    ui->x_y_shitft_pushButton_2->setEnabled(false);

    ui->ok_angle_pushbutton->setEnabled(false);
    ui->ok_x_y_scale_pushButton->setEnabled(false);
    ui->ok_x_y_shift_pushButton->setEnabled(false);

    // ui->y_shift_lineEdit->setEnabled(false);
    ui->x_shift_lineedit2->setEnabled(false);

    ui->y_shift_lineedit1->setEnabled(false);
    ui->flip_checkBox->setEnabled(false);
    ui->pushButton->setEnabled(false);
}

Form_Spectr::~Form_Spectr()
{
    delete ui;
}

void Form_Spectr::on_read_pushbutton_clicked()
{
    emit signal_on_read_pushbutton_clicked();
    ui->horizontalSlider_for_cuda_test->setValue(0.0);
    ui->pushButton->setEnabled(true);
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
void Form_Spectr::on_x_y_scale_pushButton_2_clicked()
{
    emit signal_on_x_y_scale_pushButton_2_clicked();
}

void Form_Spectr::on_scale_checkBox_toggled(bool checked)
{
    if (checked)
    {
        emit signal_on_scale_checkBox_toggled(checked);
        ui->x_y_scale_lineedit1->setEnabled(true);
        ui->x_y_scale_lineedit2->setEnabled(true);
        ui->x_shift_lineedit1->setEnabled(true);
        ui->y_shift_lineedit2->setEnabled(true);
        ui->angle_lineedit1->setEnabled(true);
        ui->angle_lineedit2->setEnabled(true);

        ui->angle_pushbutton->setEnabled(true);
        ui->angle_pushbutton_2->setEnabled(true);
        ui->x_y_scale_pushButton->setEnabled(true);
        ui->x_y_scale_pushButton_2->setEnabled(true);
        ui->x_y_shitft_pushButton->setEnabled(true);
        ui->x_y_shitft_pushButton_2->setEnabled(true);

        ui->ok_angle_pushbutton->setEnabled(true);
        ui->ok_x_y_scale_pushButton->setEnabled(true);
        ui->ok_x_y_shift_pushButton->setEnabled(true);

        ui->x_shift_lineedit2->setEnabled(true);
        ui->y_shift_lineedit1->setEnabled(true);
        ui->flip_checkBox->setEnabled(true);
    }
    else
    {
        ui->x_y_scale_lineedit1->setEnabled(false);
        ui->x_y_scale_lineedit2->setEnabled(false);
        ui->x_shift_lineedit1->setEnabled(false);
        ui->y_shift_lineedit2->setEnabled(false);
        ui->angle_lineedit1->setEnabled(false);
        ui->angle_lineedit2->setEnabled(false);

        ui->angle_pushbutton->setEnabled(false);
        ui->angle_pushbutton_2->setEnabled(false);
        ui->x_y_scale_pushButton->setEnabled(false);
        ui->x_y_scale_pushButton_2->setEnabled(false);
        ui->x_y_shitft_pushButton->setEnabled(false);
        ui->x_y_shitft_pushButton_2->setEnabled(false);

        ui->ok_angle_pushbutton->setEnabled(false);
        ui->ok_x_y_scale_pushButton->setEnabled(false);
        ui->ok_x_y_shift_pushButton->setEnabled(false);

        ui->x_shift_lineedit2->setEnabled(false);
        ui->y_shift_lineedit1->setEnabled(false);
        ui->flip_checkBox->setEnabled(false);
    }
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

void Form_Spectr::on_x_shift_lineEdit_textChanged(const QString &arg1)
{
    bool ok;
    double a2= arg1.toDouble(&ok);
    if (ok)
    {
        emit signal_on_x_shift_lineEdit_textChanged(arg1);
        ui->horizontalSlider_for_cuda_test->setValue(0.0);
    }
    else QMessageBox::information(0,"error","Invalid input");
}

void Form_Spectr::on_fi_lineEdit_textChanged(const QString &arg1)
{
    bool ok;
    double a2= arg1.toDouble(&ok);
    if (ok)
    {
        emit signal_on_fi_lineEdit_textChanged(arg1);
        ui->horizontalSlider_for_cuda_test->setValue(0.0);
    }
    else QMessageBox::information(0,"error","Invalid input");
}

void Form_Spectr::on_y_shift_lineEdit_textChanged(const QString &arg1)
{
    bool ok;
    double a2= arg1.toDouble(&ok);
    if (ok)
    {
        emit signal_on_y_shift_lineEdit_textChanged(arg1);
        ui->horizontalSlider_for_cuda_test->setValue(0.0);
    }
    else QMessageBox::information(0,"error","Invalid input");
}

void Form_Spectr::on_x_scale_lineEdit_textChanged(const QString &arg1)
{
    bool ok;
    double a2= arg1.toDouble(&ok);
    if (ok)
    {
        emit signal_on_x_scale_lineEdit_textChanged(arg1);
        ui->horizontalSlider_for_cuda_test->setValue(0.0);
    }
    else QMessageBox::information(0,"error","Invalid input");
}

void Form_Spectr::on_y_scale_lineEdit_textChanged(const QString &arg1)
{
    bool ok;
    double a2= arg1.toDouble(&ok);
    if (ok)
    {
        emit signal_on_y_scale_lineEdit_textChanged(arg1);
        ui->horizontalSlider_for_cuda_test->setValue(0.0);
    }
    else QMessageBox::information(0,"error","Invalid input");
}

void Form_Spectr::on_k_lineEdit_textChanged(const QString &arg1)
{
    bool ok;
    double a2= arg1.toDouble(&ok);
    if (ok)
    {
        emit signal_on_k_lineEdit_textChanged(arg1);
        ui->horizontalSlider_for_cuda_test->setValue(0.0);
    }
    else QMessageBox::information(0,"error","Invalid input");
}

void Form_Spectr::on_horizontalSlider_for_cuda_test_valueChanged(int value)
{
    emit change_FI0_cuda_test(value);
    ui->horizontalSlider_for_cuda_test_label->setText(QString::number(value));
}


void Form_Spectr::on_Azstart_lieedit_data_textChanged(const QString &arg1)
{
    ui->horizontalSlider_for_cuda_test->setMinimum(static_cast<int>(ui->Azstart_lieedit_data->text().toDouble())+ui->Az_span_lineEdit->text().toInt()/2);
    ui->horizontalSlider_for_cuda_test->setMaximum(static_cast<int>(ui->Azstop_lineedit_data->text().toDouble())-ui->Az_span_lineEdit->text().toInt()/2);
}

void Form_Spectr::on_Azstop_lineedit_data_textChanged(const QString &arg1)
{
    ui->horizontalSlider_for_cuda_test->setMinimum(static_cast<int>(ui->Azstart_lieedit_data->text().toDouble())+ui->Az_span_lineEdit->text().toInt()/2);
    ui->horizontalSlider_for_cuda_test->setMaximum(static_cast<int>(ui->Azstop_lineedit_data->text().toDouble())-ui->Az_span_lineEdit->text().toInt()/2);
}

void Form_Spectr::on_Az_span_lineEdit_textChanged(const QString &arg1)
{
    ui->horizontalSlider_for_cuda_test->setMinimum(static_cast<int>(ui->Azstart_lieedit_data->text().toDouble())+ui->Az_span_lineEdit->text().toInt()/2);
    ui->horizontalSlider_for_cuda_test->setMaximum(static_cast<int>(ui->Azstop_lineedit_data->text().toDouble())-ui->Az_span_lineEdit->text().toInt()/2);
}

void Form_Spectr::on_export_spectr_pushbutton_clicked()
{
    emit signal_on_export_spectr_pushbutton_clicked();
}

void Form_Spectr::on_pushButton_clicked()
{
    emit signal_on_pushButton_clicked();
}

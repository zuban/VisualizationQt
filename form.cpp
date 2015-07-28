#include "form.h"
#include "ui_form.h"
#include <QMessageBox>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);


    ui->angle_ind_textbox->setEnabled(false);
    ui->angle_value_textbox->setEnabled(false);
    ui->freq_ind_textedit->setEnabled(false);
    ui->freq_value_textbox->setEnabled(false);
}

Form::~Form()
{
    delete ui;
}

void Form::on_export_pushButton_clicked()
{
    emit signal_on_export_pushButton_clicked();
}

void Form::on_average_freq_radioButton_toggled(bool checked)
{
    if (checked==true)
    {

        emit signal_on_test_cuda_pushButton_clicked(0,3);
        emit enable_gate_marker(true);

        ui->angle_ind_textbox->setEnabled(false);
        ui->angle_value_textbox->setEnabled(false);
        ui->freq_ind_textedit->setEnabled(false);
        ui->freq_value_textbox->setEnabled(false);
    }
    else
        ui->freq_ind_textedit->setEnabled(true);
}

void Form::on_average_angle_radioButton_toggled(bool checked)
{
    if (checked==true)
    {

        emit signal_on_test_cuda_pushButton_clicked(0,4);
        emit enable_gate_marker(false);

        ui->angle_ind_textbox->setEnabled(false);
        ui->angle_value_textbox->setEnabled(false);
        ui->freq_ind_textedit->setEnabled(false);
        ui->freq_value_textbox->setEnabled(false);
    }
    else
    {
    }
}

void Form::on_center_freq_radiobutton_toggled(bool checked)
{
    if (checked)
    {
        emit signal_on_test_cuda_pushButton_clicked(0,5);
        emit enable_gate_marker(true);
        ui->angle_ind_textbox->setEnabled(false);
        ui->angle_value_textbox->setEnabled(false);
        ui->freq_ind_textedit->setEnabled(false);
        ui->freq_value_textbox->setEnabled(false);
    }

}

void Form::on_test_col_radioButton_toggled(bool checked)
{
    if (checked)
    {
        emit signal_on_test_cuda_pushButton_clicked(ui->freq_ind_textedit->text().toInt(),2);
        emit enable_gate_marker(true);
        ui->angle_ind_textbox->setEnabled(false);
        ui->angle_value_textbox->setEnabled(false);
        ui->freq_ind_textedit->setEnabled(true);
        ui->freq_value_textbox->setEnabled(true);
    }

}

void Form::on_center_angle_radiobutton_toggled(bool checked)
{
    if (checked)
    {
        emit signal_on_test_cuda_pushButton_clicked(0,6);
        emit enable_gate_marker(false);
        ui->angle_ind_textbox->setEnabled(false);
        ui->angle_value_textbox->setEnabled(false);
        ui->freq_ind_textedit->setEnabled(false);
        ui->freq_value_textbox->setEnabled(false);
    }
}

void Form::on_test_row_radioButton_toggled(bool checked)
{
    if (checked)
    {
        emit signal_on_test_cuda_pushButton_clicked(ui->angle_ind_textbox->text().toInt(),1);
        emit enable_gate_marker(false);
        ui->angle_ind_textbox->setEnabled(true);
        ui->angle_value_textbox->setEnabled(true);
        ui->freq_ind_textedit->setEnabled(false);
        ui->freq_value_textbox->setEnabled(false);
    }

}

void Form::on_freq_ind_textedit_textChanged(const QString &arg1)
{
    emit signal_on_test_cuda_pushButton_clicked(ui->freq_ind_textedit->text().toInt(),2);
    emit enable_gate_marker(true);
}
void Form::on_angle_ind_textbox_textChanged(const QString &arg1)
{
    emit signal_on_test_cuda_pushButton_clicked(ui->angle_ind_textbox->text().toInt(),1);
    emit enable_gate_marker(false);
}

void Form::on_copy_pushButton_clicked()
{
    emit signal_on_copy_pushButton_clicked();
}

void Form::on_clear_pushButton_clicked()
{
    emit signal_on_clear_pushButton_clicked();
   // ui->average_freq_radioButton->toggle();
}
void Form::replot_2d()
{
    ui->average_freq_radioButton->toggle();
}
void  Form::change_value_freq(double val)
{
    ui->angle_value_textbox->setText(QString::number(val)+ " deg");
}
void  Form::change_value_angle(double val)
{

     ui->freq_value_textbox->setText(QString::number(val)+ " GHz");
}

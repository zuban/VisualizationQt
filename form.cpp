#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}


void Form::on_read_pushButton_clicked()
{
    emit signal_on_read_pushButton_clicked();
}

void Form::on_add_pushButton_clicked()
{
    emit signal_on_add_pushButton_clicked();
}

void Form::on_export_pushButton_clicked()
{
    emit signal_on_export_pushButton_clicked();
}

void Form::on_test_cuda_pushButton_clicked()
{
    emit signal_on_test_cuda_pushButton_clicked();
}

void Form::on_test_row_column_lineEdit_textChanged(const QString &arg1)
{
    emit signal_on_test_row_column_lineEdit_textChanged(arg1);
}

void Form::on_test_col_radioButton_toggled(bool checked)
{
    emit signal_on_test_col_radioButton_toggled(checked);
}

void Form::on_test_row_radioButton_toggled(bool checked)
{
    emit signal_on_test_row_radioButton_toggled(checked);
}

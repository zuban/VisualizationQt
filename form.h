#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT
    
public:
    explicit Form(QWidget *parent = 0);
    ~Form();

signals:
    void signal_on_read_pushButton_clicked();
    void signal_on_add_pushButton_clicked();
    void signal_on_export_pushButton_clicked();
    void signal_on_test_cuda_pushButton_clicked(int num,int type);
    void signal_on_test_row_column_lineEdit_textChanged(QString str);
    void signal_on_test_col_radioButton_toggled(bool checked);
    void signal_on_test_row_radioButton_toggled(bool checked);


     void enable_gate_marker(bool en);
private slots:

    void on_export_pushButton_clicked();
    void on_test_cuda_pushButton_clicked();

    //    void on_test_row_column_lineEdit_textChanged(const QString &arg1);

    //    void on_test_col_radioButton_toggled(bool checked);

    //    void on_test_row_radioButton_toggled(bool checked);

    void on_average_freq_radioButton_toggled(bool checked);

    void on_average_angle_radioButton_toggled(bool checked);

private:
    Ui::Form *ui;
};

#endif // FORM_H

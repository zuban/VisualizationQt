#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "zgraph.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    ZGraph *zGraph;

    
private slots:

    void resizeEvent ( QResizeEvent * event );




    void change_text(double text);

    void enable_delete_pushbutton(bool a);

    //void slot_on_read_pushButton_clicked();

    // void slot_on_add_pushButton_clicked();

    void on_graph_type_comboBox_currentIndexChanged(const QString &arg1);

    void on_graph_lin_log_type_comboBox_currentIndexChanged(const QString &arg1);

    void on_graph_color_comboBox_currentIndexChanged(const QString &arg1);

    void on_graph_style_comboBox_currentIndexChanged(const QString &arg1);

    void on_graph_wight_spinBox_valueChanged(const QString &arg1);

    void on_add_marker_pushButton_clicked();

    void on_delete_marker_pushButton_clicked();

    void on_reference_marker_pushButton_toggled(bool checked);

    void slot_on_export_pushButton_clicked();

    void on_ampl_autoscale_radioButton_clicked();

    void on_ampl_up_radioButton_clicked();

    void on_ampl_manual_radioButton_clicked();

    void on_ampl_max_comboBox_currentIndexChanged(const QString &arg1);

    void on_ampl_span_comboBox_currentIndexChanged(const QString &arg1);

    void on_phase_center_comboBox_currentIndexChanged(const QString &arg1);

    void on_phase_autoscale_radioButton_clicked();

    void on_phase_span_comboBox_currentIndexChanged(const QString &arg1);

    void on_phase_manual_radioButton_clicked();

    void on_phase_up_radioButton_clicked();

    void on_real_center_comboBox_currentIndexChanged(const QString &arg1);

    void on_real_span_comboBox_currentIndexChanged(const QString &arg1);

    void on_real_autoscale_radioButton_clicked();

    void on_real_manual_radioButton_clicked();

    void on_real_up_radioButton_clicked();

    void on_imag_center_comboBox_currentIndexChanged(const QString &arg1);

    void on_imag_span_comboBox_currentIndexChanged(const QString &arg1);

    void on_imag_autoscale_radioButton_clicked();

    void on_imag_manual_radioButton_clicked();

    void on_imag_up_radioButton_clicked();

    void on_XY_scale_pushButton_toggled(bool checked);

    void on_X_scale_pushButton_toggled(bool checked);

    void on_Y_scale_pushButton_toggled(bool checked);

    void on_magnifier_pushButton_toggled(bool checked);

    //    void slot_on_test_col_radioButton_toggled(bool checked);

    //    void slot_on_test_row_radioButton_toggled(bool checked);

    //  void on_test_row_column_lineEdit_textChanged(const QString &arg1);

    void slot_on_test_cuda_pushButton_clicked(int num, int type);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

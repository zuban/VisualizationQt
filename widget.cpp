#include "widget.h"
#include "ui_widget.h"
#include "QFileDialog"
#include "qwt_plot_renderer.h"
#include "QMessageBox"
#include "QImageWriter"
#include "QBuffer"
#include "QRect"
#include "QApplication"
#include "QDesktopWidget"
#include "cuda_dll_module.h"
#include "qwt_plot_grid.h"
//struct double2 {double x; double y;};
#include <QtDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    zGraph=new ZGraph(this);
    QRect  a=QApplication::desktop()->screenGeometry();
    zGraph->move(5,80);
    zGraph->resize(a.width()-40,a.height()-20);
    zGraph->resizeMyPlot(a.width()-45,a.height()-30);
    this->showMaximized();
    connect(zGraph,SIGNAL(signal_from_zGraph(double)),this,SLOT(change_text(double)));
    // connect(zGraph->myPlot->mylegend,SIGNAL(signal_from_legend(double)),this,SLOT(change_text(double)));
    connect(zGraph->myPlot->mymarker,SIGNAL(enable_delete_button(bool)),this,SLOT(enable_delete_pushbutton(bool)));

    ui->add_marker_pushButton->setEnabled(false);
    ui->delete_marker_pushButton->setEnabled(false);
    ui->reference_marker_pushButton->setEnabled(false);
    ui->show_marker_pushButton->setEnabled(false);
    //TODOui->add_pushButton->setEnabled(false);
    //TODOui->export_pushButton->setEnabled(false);
    ui->graph_color_comboBox->setEnabled(false);
    ui->graph_lin_log_type_comboBox->setEnabled(false);
    ui->graph_style_comboBox->setEnabled(false);
    ui->graph_type_comboBox->setEnabled(false);
    ui->graph_wight_spinBox->setEnabled(false);
    ui->stackedWidget->setEnabled(false);
    ui->ampl_max_comboBox->setEnabled(false);
    ui->ampl_span_comboBox->setEnabled(false);
    ui->X_scale_pushButton->setEnabled(false);
    ui->Y_scale_pushButton->setEnabled(false);
    ui->XY_scale_pushButton->setEnabled(false);
    ui->magnifier_pushButton->setEnabled(false);
    //TODOui->test_row_radioButton->setChecked(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::get_data_2D(double set_datax,double set_datay, int len)
{

}
//void Widget::slot_on_read_pushButton_clicked()
//{
//    QString way = QFileDialog::getOpenFileName(this, tr("Open File"), "",tr(".dat Files (*.dat)"));
//     if (way==0)
//     {
//         return;
//     }
//    zGraph->draw_default_graph(way);
//    ui->add_marker_pushButton->setEnabled(true);
//    ui->delete_marker_pushButton->setEnabled(true);
//    ui->reference_marker_pushButton->setEnabled(true);
//    ui->show_marker_pushButton->setEnabled(true);
//    //TODOui->add_pushButton->setEnabled(true);

//    //TODOui->export_pushButton->setEnabled(true);
//    ui->graph_color_comboBox->setEnabled(true);
//    ui->graph_lin_log_type_comboBox->setEnabled(true);
//    ui->graph_style_comboBox->setEnabled(true);
//    ui->graph_type_comboBox->setEnabled(true);
//    ui->graph_wight_spinBox->setEnabled(true);
//    ui->stackedWidget->setEnabled(true);

//    ui->X_scale_pushButton->setEnabled(true);
//    ui->Y_scale_pushButton->setEnabled(true);
//    ui->XY_scale_pushButton->setEnabled(true);
//    ui->magnifier_pushButton->setEnabled(true);
//}

//void Widget::slot_on_add_pushButton_clicked()
//{
//    QString way = QFileDialog::getOpenFileName(this, tr("Open File"), "",tr(".dat Files (*.dat)"));
//     if (way==0)
//     {
//         return;
//     }
//     zGraph->add_new_graph(way);
//}
void Widget::change_text(double text)
{
    //text//ui->textEdit->setText(QString::number(text));
    //  ui->textEdit->setText(QString::number(text));
    ui->lineEdit->setText(QString::number(text));
}

void Widget::on_graph_type_comboBox_currentIndexChanged(const QString &arg1)
{
    if (zGraph==NULL)
            return;
    if (arg1=="Amplitude")
    {
        zGraph->redefine_type(arg1);
        ui->graph_lin_log_type_comboBox->setEnabled(true);
        ui->stackedWidget->setCurrentIndex(0);
        ui->ampl_autoscale_radioButton->setChecked(true);
        ui->ampl_max_comboBox->setEnabled(false);
        ui->ampl_span_comboBox->setEnabled(false);
    }
    if (arg1=="Phase")
    {
        zGraph->redefine_type(arg1);
        ui->graph_lin_log_type_comboBox->setEnabled(false);
        ui->stackedWidget->setCurrentIndex(1);
        ui->phase_autoscale_radioButton->setChecked(true);
        ui->phase_center_comboBox->setEnabled(false);
        ui->phase_span_comboBox->setEnabled(false);
    }
    if (arg1=="Real")
    {
        zGraph->redefine_type(arg1);
        ui->graph_lin_log_type_comboBox->setEnabled(false);
        ui->stackedWidget->setCurrentIndex(2);
        ui->real_autoscale_radioButton->setChecked(true);
        ui->real_center_comboBox->setEnabled(false);
        ui->real_span_comboBox->setEnabled(false);
    }
    if (arg1=="Imag")
    {
        zGraph->redefine_type(arg1);
        ui->graph_lin_log_type_comboBox->setEnabled(false);
        ui->stackedWidget->setCurrentIndex(3);
        ui->imag_autoscale_radioButton->setChecked(true);
        ui->imag_center_comboBox->setEnabled(false);
        ui->imag_span_comboBox->setEnabled(false);
    }
}

void Widget::on_graph_lin_log_type_comboBox_currentIndexChanged(const QString &arg1)
{
    if (zGraph==NULL)
            return;
    if (arg1=="Lin")
    {
        zGraph->redefine_type(arg1);
        ui->ampl_span_comboBox->setEnabled(false);
        ui->ampl_autoscale_radioButton->setChecked(true);

        zGraph->reDrawScale(0,0);
        ui->ampl_max_comboBox->setEnabled(false);
        ui->ampl_span_comboBox->setEnabled(false);
    }
    if (arg1=="Log")
    {
        zGraph->redefine_type(arg1);
        ui->ampl_span_comboBox->setEnabled(true);
        ui->ampl_autoscale_radioButton->setChecked(true);

        zGraph->reDrawScale(0,0);
        ui->ampl_max_comboBox->setEnabled(false);
        ui->ampl_span_comboBox->setEnabled(false);
    }
}

void Widget::on_graph_color_comboBox_currentIndexChanged(const QString &arg1)
{
    if (arg1=="black")
    {
        zGraph->change_graph_color(Qt::black);
    }
    if (arg1=="cyan")
    {
        zGraph->change_graph_color(Qt::cyan);
    }
    if (arg1=="darkCyan")
    {
        zGraph->change_graph_color(Qt::darkCyan);
    }
    if (arg1=="red")
    {
        zGraph->change_graph_color(Qt::red);
    }
    if (arg1=="darkRed")
    {
        zGraph->change_graph_color(Qt::darkRed);
    }
    if (arg1=="magenta")
    {
        zGraph->change_graph_color(Qt::magenta);
    }
    if (arg1=="darkMagenta")
    {
        zGraph->change_graph_color(Qt::darkMagenta);
    }
    if (arg1=="green")
    {
        zGraph->change_graph_color(Qt::green);
    }
    if (arg1=="darkGreen")
    {
        zGraph->change_graph_color(Qt::darkGreen);
    }
    if (arg1=="yellow")
    {
        zGraph->change_graph_color(Qt::yellow);
    }
    if (arg1=="darkYellow")
    {
        zGraph->change_graph_color(Qt::darkYellow);
    }
    if (arg1=="blue")
    {
        zGraph->change_graph_color(Qt::blue);
    }
    if (arg1=="darkBlue")
    {
        zGraph->change_graph_color(Qt::darkBlue);
    }
    if (arg1=="gray")
    {
        zGraph->change_graph_color(Qt::gray);
    }
    if (arg1=="darkGray")
    {
        zGraph->change_graph_color(Qt::darkGray);
    }
    if (arg1=="lightGray")
    {
        zGraph->change_graph_color(Qt::lightGray);
    }

}

void Widget::on_graph_style_comboBox_currentIndexChanged(const QString &arg1)
{
    if (arg1=="SolidLine")
    {
        zGraph->change_graph_style(Qt::SolidLine);
    }
    if (arg1=="DashLine")
    {
        zGraph->change_graph_style(Qt::DashLine);
    }
    if (arg1=="DotLine")
    {
        zGraph->change_graph_style(Qt::DotLine);
    }
    if (arg1=="DashDotLine")
    {
        zGraph->change_graph_style(Qt::DashDotLine);
    }
    if (arg1=="DashDotDotLine")
    {
        zGraph->change_graph_style(Qt::DashDotDotLine);
    }

}

void Widget::on_graph_wight_spinBox_valueChanged(const QString &arg1)
{
    bool ok;
    int a= arg1.toInt(&ok);
    if (ok)
    zGraph->change_graph_width(arg1.toInt(&ok));
    else QMessageBox::information(0,"error","Invalid input");
}

void Widget::on_add_marker_pushButton_clicked()
{
    zGraph->add_marker();
}

void Widget::on_delete_marker_pushButton_clicked()
{
    zGraph->delete_marker();
}

void Widget::on_reference_marker_pushButton_toggled(bool checked)
{
    zGraph->reference_marker_toggled(checked);
}



void Widget::slot_on_export_pushButton_clicked()
{

    //    int w = zGraph->myPlot->width();
    //    int h = zGraph->myPlot->height();
    //    QPixmap pixmap(w, h);
    //    zGraph->myPlot->print(pixmap);

    //    static QByteArray bytes;
    //    QBuffer buffer(&bytes);
    //    buffer.open(QIODevice::WriteOnly);
    //    pixmap.save(&buffer, "png");
    //    // or save as a file
    //    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
    //                               "/home/jana/untitled.png",
    //                               tr("Images (*.png)"));

    //    QFile file(fileName);
    //      if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    //          return;

    //      QTextStream out(&file);
    //      out << bytes;
    {

#ifndef QT_NO_PRINTER
        QString fileName = "plot.pdf";
#else
        QString fileName = "plot.png";
#endif

#ifndef QT_NO_FILEDIALOG
        const QList<QByteArray> imageFormats =
                QImageWriter::supportedImageFormats();

        QStringList filter;
        filter += "PDF Documents (*.pdf)";
#ifndef QWT_NO_SVG
        filter += "SVG Documents (*.svg)";
#endif
        filter += "Postscript Documents (*.ps)";

        if ( imageFormats.size() > 0 )
        {
            QString imageFilter("Images (");
            for ( int i = 0; i < imageFormats.size(); i++ )
            {
                if ( i > 0 )
                    imageFilter += " ";
                imageFilter += "*.";
                imageFilter += imageFormats[i];
            }
            imageFilter += ")";

            filter += imageFilter;
        }

        fileName = QFileDialog::getSaveFileName(
                    this, "Export File Name", fileName,
                    filter.join(";;"), NULL, QFileDialog::DontConfirmOverwrite);
#endif
        if ( !fileName.isEmpty() )
        {
            QwtPlotRenderer renderer;
            // renderer.setDiscardFlag(QwtPlotRenderer::DiscardBackground, false);

            renderer.renderDocument(zGraph->myPlot, fileName, QSizeF(300, 200), 85);
            QMessageBox::information(0,"information","Operation Complete");
        }

    }
}

void Widget::enable_delete_pushbutton(bool a)
{
    if (a==true)
    {
        ui->delete_marker_pushButton->setEnabled(true);
    }
    if (a==false)
    {
        ui->delete_marker_pushButton->setEnabled(false);
    }
}

void Widget::on_ampl_autoscale_radioButton_clicked()
{
    zGraph->eAmplScale=ZGraph::AmplAutoscale;
    zGraph->reDrawScale(0,0);
    ui->ampl_max_comboBox->setEnabled(false);
    ui->ampl_span_comboBox->setEnabled(false);
}

void Widget::on_ampl_up_radioButton_clicked()
{
    if (ui->ampl_span_comboBox->currentText().toDouble()==0)
        return;
    zGraph->eAmplScale=ZGraph::AmplUp;
    zGraph->reDrawScale(ui->ampl_max_comboBox->currentText().toDouble(),ui->ampl_span_comboBox->currentText().toDouble());
    ui->ampl_max_comboBox->setEnabled(false);
    ui->ampl_span_comboBox->setEnabled(true);

}

void Widget::on_ampl_manual_radioButton_clicked()
{
    if (ui->ampl_span_comboBox->currentText().toDouble()==0)
        return;
    zGraph->eAmplScale=ZGraph::AmplManual;
    QString a;

    zGraph->reDrawScale(ui->ampl_max_comboBox->currentText().toDouble(),ui->ampl_span_comboBox->currentText().toDouble());
    ui->ampl_max_comboBox->setEnabled(true);
    ui->ampl_span_comboBox->setEnabled(true);
}

void Widget::on_ampl_max_comboBox_currentIndexChanged(const QString &arg1)
{
    bool ok1,ok2;
    double a1= arg1.toDouble(&ok1);
    double a2= ui->ampl_span_comboBox->currentText().toDouble(&ok2);
    if (ok1 && ok2)
    zGraph->reDrawScale(arg1.toDouble(),ui->ampl_span_comboBox->currentText().toDouble());
    else QMessageBox::information(0,"error","Invalid input");
}

void Widget::on_ampl_span_comboBox_currentIndexChanged(const QString &arg1)
{
    if (arg1.toDouble()==0)
        return;
    bool ok1,ok2;
    double a1= ui->ampl_max_comboBox->currentText().toDouble(&ok1);
    double a2= arg1.toDouble(&ok2);
    if (ok1 && ok2)
    zGraph->reDrawScale(ui->ampl_max_comboBox->currentText().toDouble(),arg1.toDouble());
        else QMessageBox::information(0,"error","Invalid input");
}

void Widget::on_phase_center_comboBox_currentIndexChanged(const QString &arg1)
{
    bool ok1,ok2;
    double a1= arg1.toDouble(&ok1);
    double a2= ui->phase_span_comboBox->currentText().toDouble(&ok2);
    if (ok1 && ok2)
    zGraph->reDrawScale(arg1.toDouble(),ui->phase_span_comboBox->currentText().toDouble());
     else QMessageBox::information(0,"error","Invalid input");
}

void Widget::on_phase_autoscale_radioButton_clicked()
{
    zGraph->ePhaseScale=ZGraph::PhaseAutoscale;
    zGraph->reDrawScale(0,0);
    ui->phase_center_comboBox->setEnabled(false);
    ui->phase_span_comboBox->setEnabled(false);
}

void Widget::on_phase_span_comboBox_currentIndexChanged(const QString &arg1)
{
    if (arg1.toDouble()==0)
        return;

    bool ok1,ok2;
    double a1=ui->phase_center_comboBox->currentText().toDouble(&ok1);
    double a2=arg1.toDouble(&ok2);
    if (ok1 && ok2)
    zGraph->reDrawScale(ui->phase_center_comboBox->currentText().toDouble(),arg1.toDouble());
    else QMessageBox::information(0,"error","Invalid input");
}

void Widget::on_phase_manual_radioButton_clicked()
{
    if (ui->phase_span_comboBox->currentText().toDouble()==0)
        zGraph->ePhaseScale=ZGraph::PhaseManual;
    ui->phase_center_comboBox->setEnabled(true);
    ui->phase_span_comboBox->setEnabled(true);


    bool ok1,ok2;
    double a1= ui->phase_center_comboBox->currentText().toDouble(&ok1);
    double a2= ui->phase_span_comboBox->currentText().toDouble(&ok2);
    if (ok1 && ok2)
    zGraph->reDrawScale(ui->phase_center_comboBox->currentText().toDouble(),ui->phase_span_comboBox->currentText().toDouble());
    else QMessageBox::information(0,"error","Invalid input");
}

void Widget::on_phase_up_radioButton_clicked()
{
    if (ui->phase_span_comboBox->currentText().toDouble()==0)
        return;
    zGraph->ePhaseScale=ZGraph::PhaseUp;
    ui->phase_center_comboBox->setEnabled(false);
    ui->phase_span_comboBox->setEnabled(true);

    bool ok1,ok2;
    double a1= ui->phase_center_comboBox->currentText().toDouble(&ok1);
    double a2= ui->phase_span_comboBox->currentText().toDouble(&ok2);
    if (ok1 && ok2)
    zGraph->reDrawScale(ui->phase_center_comboBox->currentText().toDouble(),ui->phase_span_comboBox->currentText().toDouble());
     else QMessageBox::information(0,"error","Invalid input");
}

void Widget::on_real_center_comboBox_currentIndexChanged(const QString &arg1)
{
    bool ok1,ok2;
    double a1= arg1.toDouble(&ok1);
    double a2= ui->real_span_comboBox->currentText().toDouble(&ok2);
    if (ok1 && ok2)
    zGraph->reDrawScale(arg1.toDouble(),ui->real_span_comboBox->currentText().toDouble());
     else QMessageBox::information(0,"error","Invalid input");
}

void Widget::on_real_span_comboBox_currentIndexChanged(const QString &arg1)
{
    if (arg1.toDouble()==0)
        return;

    bool ok1,ok2;
    double a1= ui->real_center_comboBox->currentText().toDouble(&ok1);
    double a2= arg1.toDouble(&ok2);
    if (ok1 && ok2)
    zGraph->reDrawScale(ui->real_center_comboBox->currentText().toDouble(),arg1.toDouble());
    else QMessageBox::information(0,"error","Invalid input");
}

void Widget::on_real_autoscale_radioButton_clicked()
{
    zGraph->eReImScale=ZGraph::ReAutoscale;
    zGraph->reDrawScale(0,0);
    ui->real_center_comboBox->setEnabled(false);
    ui->real_span_comboBox->setEnabled(false);
}

void Widget::on_real_manual_radioButton_clicked()
{
    if (ui->real_span_comboBox->currentText().toDouble()==0)
        return;
    zGraph->eReImScale=ZGraph::ReManual;

    bool ok1,ok2;
    double a1= ui->real_center_comboBox->currentText().toDouble(&ok1);
    double a2= ui->real_span_comboBox->currentText().toDouble(&ok2);
    if (ok1 && ok2)
    zGraph->reDrawScale(ui->real_center_comboBox->currentText().toDouble(),ui->real_span_comboBox->currentText().toDouble());
     else QMessageBox::information(0,"error","Invalid input");
    ui->real_center_comboBox->setEnabled(true);
    ui->real_span_comboBox->setEnabled(true);
}

void Widget::on_real_up_radioButton_clicked()
{
    if (ui->real_span_comboBox->currentText().toDouble()==0)
        return;
    zGraph->eReImScale=ZGraph::ReUp;
     bool ok1,ok2;
    double a1= ui->real_center_comboBox->currentText().toDouble(&ok1);
    double a2= ui->real_span_comboBox->currentText().toDouble(&ok2);
    if (ok1 && ok2)
    zGraph->reDrawScale(ui->real_center_comboBox->currentText().toDouble(),ui->real_span_comboBox->currentText().toDouble());
     else QMessageBox::information(0,"error","Invalid input");
    ui->real_center_comboBox->setEnabled(false);
    ui->real_span_comboBox->setEnabled(true);
}

void Widget::on_imag_center_comboBox_currentIndexChanged(const QString &arg1)
{
    bool ok1,ok2;
   double a1= arg1.toDouble(&ok1);
   double a2= ui->imag_span_comboBox->currentText().toDouble(&ok2);
   if (ok1 && ok2)
    zGraph->reDrawScale(arg1.toDouble(),ui->imag_span_comboBox->currentText().toDouble());
   else QMessageBox::information(0,"error","Invalid input");
}

void Widget::on_imag_span_comboBox_currentIndexChanged(const QString &arg1)
{
    if (arg1.toDouble()==0)
        return;

    bool ok1,ok2;
   double a1= ui->real_center_comboBox->currentText().toDouble(&ok1);
   double a2= arg1.toDouble(&ok2);
   if (ok1 && ok2)
    zGraph->reDrawScale(ui->real_center_comboBox->currentText().toDouble(),arg1.toDouble());
    else QMessageBox::information(0,"error","Invalid input");
}

void Widget::on_imag_autoscale_radioButton_clicked()
{
    zGraph->eReImScale=ZGraph::ReAutoscale;
    zGraph->reDrawScale(0,0);
    ui->imag_center_comboBox->setEnabled(false);
    ui->imag_span_comboBox->setEnabled(false);
}

void Widget::on_imag_manual_radioButton_clicked()
{
    if (ui->imag_span_comboBox->currentText().toDouble()==0)
        return;
     zGraph->eReImScale=ZGraph::ReManual;
    bool ok1,ok2;
   double a1= ui->imag_center_comboBox->currentText().toDouble(&ok1);
   double a2= ui->imag_span_comboBox->currentText().toDouble(&ok2);
   if (ok1 && ok2)
    zGraph->reDrawScale(ui->imag_center_comboBox->currentText().toDouble(),ui->imag_span_comboBox->currentText().toDouble());
    else QMessageBox::information(0,"error","Invalid input");
    ui->imag_center_comboBox->setEnabled(true);
    ui->imag_span_comboBox->setEnabled(true);
}
void Widget::on_imag_up_radioButton_clicked()
{
    if (ui->imag_span_comboBox->currentText().toDouble()==0)
        return;
    zGraph->eReImScale=ZGraph::ReUp;
    bool ok1,ok2;
   double a1= ui->imag_center_comboBox->currentText().toDouble(&ok1);
   double a2= ui->imag_span_comboBox->currentText().toDouble(&ok2);
   if (ok1 && ok2)
    zGraph->reDrawScale(ui->imag_center_comboBox->currentText().toDouble(),ui->imag_span_comboBox->currentText().toDouble());
    else QMessageBox::information(0,"error","Invalid input");
    ui->imag_center_comboBox->setEnabled(false);
    ui->imag_span_comboBox->setEnabled(true);
}

void Widget::on_XY_scale_pushButton_toggled(bool checked)
{
    if (checked==true)
    {
        ui->X_scale_pushButton->setEnabled(false);
        ui->Y_scale_pushButton->setEnabled(false);
        ui->magnifier_pushButton->setEnabled(false);
        zGraph->enable_xy_zoomer();
    }
    if (checked==false)
    {
        ui->X_scale_pushButton->setEnabled(true);
        ui->Y_scale_pushButton->setEnabled(true);
        ui->magnifier_pushButton->setEnabled(true);
        zGraph->delete_xy_zoomer();
    }
}

void Widget::on_X_scale_pushButton_toggled(bool checked)
{
    if (checked==true)
    {
        ui->XY_scale_pushButton->setEnabled(false);
        ui->Y_scale_pushButton->setEnabled(false);
        ui->magnifier_pushButton->setEnabled(false);
        zGraph->enable_x_zoomer();
    }
    if (checked==false)
    {
        ui->XY_scale_pushButton->setEnabled(true);
        ui->Y_scale_pushButton->setEnabled(true);
        ui->magnifier_pushButton->setEnabled(true);
        zGraph->delete_x_zoomer();
    }
}

void Widget::on_Y_scale_pushButton_toggled(bool checked)
{
    if (checked==true)
    {
        ui->X_scale_pushButton->setEnabled(false);
        ui->XY_scale_pushButton->setEnabled(false);
        ui->magnifier_pushButton->setEnabled(false);
        zGraph->enable_y_zoomer();
    }
    if (checked==false)
    {
        ui->X_scale_pushButton->setEnabled(true);
        ui->XY_scale_pushButton->setEnabled(true);
        ui->magnifier_pushButton->setEnabled(true);
        zGraph->delete_y_zoomer();
    }
}

void Widget::on_magnifier_pushButton_toggled(bool checked)
{
    if (checked==true)
    {
        ui->X_scale_pushButton->setEnabled(false);
        ui->XY_scale_pushButton->setEnabled(false);
        ui->Y_scale_pushButton->setEnabled(false);
        zGraph->enable_magnifier();
    }
    if (checked==false)
    {
        ui->X_scale_pushButton->setEnabled(true);
        ui->XY_scale_pushButton->setEnabled(true);
        ui->Y_scale_pushButton->setEnabled(true);
        zGraph->delete_magnifier();
    }
}

//void Widget::slot_on_test_col_radioButton_toggled(bool checked)
//{
//    if (checked==true)
//    {
//        zGraph->is_rows=false;
//        //TODOui->test_row_radioButton->setChecked(false);
//    }
//}

//void Widget::slot_on_test_row_radioButton_toggled(bool checked)
//{
//    if (checked==true)
//    {
//        zGraph->is_rows=true;
//        //TODOui->test_col_radioButton->setChecked(false);
//    }
//}

//void Widget::on_test_row_column_lineEdit_textChanged(const QString &arg1)
//{
//    zGraph->col_or_row_number=arg1.toInt();
//    zGraph->replot_test(arg1.toInt());
//}

void Widget::slot_on_test_cuda_pushButton_clicked(int num, bool row)
{
    qDebug() << QString::number(num);
    if (zGraph->eRun==ZGraph::first)
    {
        zGraph->Cuda_draw_default_graph("");
        ui->add_marker_pushButton->setEnabled(true);
        ui->delete_marker_pushButton->setEnabled(true);
        ui->reference_marker_pushButton->setEnabled(true);
        ui->show_marker_pushButton->setEnabled(true);
        //TODOui->add_pushButton->setEnabled(true);

        //TODOui->export_pushButton->setEnabled(true);
        ui->graph_color_comboBox->setEnabled(true);
        ui->graph_lin_log_type_comboBox->setEnabled(true);
        ui->graph_style_comboBox->setEnabled(true);
        ui->graph_type_comboBox->setEnabled(true);
        ui->graph_wight_spinBox->setEnabled(true);
        ui->stackedWidget->setEnabled(true);

        ui->X_scale_pushButton->setEnabled(true);
        ui->Y_scale_pushButton->setEnabled(true);
        ui->XY_scale_pushButton->setEnabled(true);
        ui->magnifier_pushButton->setEnabled(true);
    }
    else
    {
        zGraph->test_func_deprecated();
    }


}
void Widget::resizeEvent ( QResizeEvent * event )
{

    zGraph->resize((*this).width()-140,(*this).height()-90);
    zGraph->resizeMyPlot((*this).width()-145,(*this).height()-100);

    QWidget::resizeEvent(event);
}

#include "spectrwidget.h"
#include "ui_spectrwidget.h"
#include "QFileDialog"
#include "time.h"
#include "QLabel"
#include "QGraphicsScene"
#include "cuda_dll_module.h"
#include "ui_form_spectr.h"
#include "form_spectr.h"
#include <QMessageBox>


double GLOBAL_F_start;
double GLOBAL_F_stop;
//#include "H5Cpp.h"
//struct double2 {double x; double y;};

SpectrWidget::SpectrWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpectrWidget)
{
    ui->setupUi(this);
    zoomer_mod = false;
    z2vector = new Z2Vector();
    sp_plot=new Spectro_Plot(this);
    sp_plot->setWindowOpacity(0.5);
    sp_plot->move(5,60);
    sp_plot->resize(this->width()-5,this->height()-60);
    control=NULL;
    data=NULL;
    ui->progressBar->setValue(0);
    ui->polygon_pushButton->setChecked(true);

    //connect(sp_plot,SIGNAL(signal_from_vector(QString)),this,SLOT(time(QString)));
    //connect(sp_plot->draw_widget,SIGNAL(signal_change_text(QString)),this,SLOT(change_text(QString)));
    connect(sp_plot->draw_widget,SIGNAL(signla_x_shift(double)),this,SLOT(change_x_shift(double)));
    connect(sp_plot->draw_widget,SIGNAL(signla_y_shift(double)),this,SLOT(change_y_shift(double)));
    connect(sp_plot->draw_widget,SIGNAL(signla_x_scale(double)),this,SLOT(change_x_scale(double)));
    connect(sp_plot->draw_widget,SIGNAL(signla_y_scale(double)),this,SLOT(change_y_scale(double)));
    connect(sp_plot->draw_widget,SIGNAL(signla_fi(double)),this,SLOT(change_fi(double)));
    connect(sp_plot->draw_widget,SIGNAL(signla_k(double)),this,SLOT(change_k(double)));
    connect(sp_plot->draw_widget,SIGNAL(signla_fi_shift(double)),this,SLOT(change_fi_shift(double)));
    //connect(sp_plot->draw_widget,SIGNAL(signal_to_change_scale(double)),this,SLOT(slot_size(double)));
    connect(sp_plot->draw_widget,SIGNAL(signal_to_change_scale_scale1(double)),this,SLOT(slot_to_change_scale_scale1(double)));
    connect(sp_plot->draw_widget,SIGNAL(signal_to_change_scale_scale2(double)),this,SLOT(slot_to_change_scale_scale2(double)));
    connect(sp_plot->draw_widget,SIGNAL(signal_to_change_scale_angle1(double,double)),this,SLOT(slot_to_change_scale_angle1(double,double)));
    connect(sp_plot->draw_widget,SIGNAL(signal_to_change_scale_point1(QPointF)),this,SLOT(slot_to_change_scale_point1(QPointF)));
    connect(sp_plot->draw_widget,SIGNAL(signal_to_change_scale_point22(QPointF)),this,SLOT(slot_to_change_scale_point22(QPointF)));
    connect(sp_plot->draw_widget,SIGNAL(signal_to_change_scale_angle2(double,double)),this,SLOT(slot_to_change_scale_angle2(double,double)));
    connect(sp_plot->draw_widget,SIGNAL(signal_test(QString)),this,SLOT(slot_test(QString)));
//    connect(sp_plot->photo,SIGNAL(photo_signla_x_shift(double)),this,SLOT(photo_change_x_shift(double)));
//    connect(sp_plot->photo,SIGNAL(photo_signla_y_shift(double)),this,SLOT(photo_change_y_shift(double)));
//    connect(sp_plot->photo,SIGNAL(photo_signla_x_scale(double)),this,SLOT(photo_change_x_scale(double)));
//    connect(sp_plot->photo,SIGNAL(photo_signla_y_scale(double)),this,SLOT(photo_change_y_scale(double)));
//    connect(sp_plot->photo,SIGNAL(photo_signla_fi(double)),this,SLOT(photo_change_fi(double)));
//    connect(sp_plot->photo,SIGNAL(photo_signla_k(double)),this,SLOT(photo_change_k(double)));
//    connect(sp_plot->photo,SIGNAL(photo_signla_fi_shift(double)),this,SLOT(photo_change_fi_shift(double)));
//    //connect(sp_plot->photo,SIGNAL(photo_signal_to_change_scale(double)),this,SLOT(photo_slot_size(double)));
//    connect(sp_plot->photo,SIGNAL(photo_signal_to_change_scale_scale1(double)),this,SLOT(photo_slot_to_change_scale_scale1(double)));
//    connect(sp_plot->photo,SIGNAL(photo_signal_to_change_scale_scale2(double)),this,SLOT(photo_slot_to_change_scale_scale2(double)));
//    connect(sp_plot->photo,SIGNAL(photo_signal_to_change_scale_angle1(double,double)),this,SLOT(photo_slot_to_change_scale_angle1(double,double)));
//    connect(sp_plot->photo,SIGNAL(photo_signal_to_change_scale_point1(QPointF)),this,SLOT(photo_slot_to_change_scale_point1(QPointF)));
//    connect(sp_plot->photo,SIGNAL(photo_signal_to_change_scale_point22(QPointF)),this,SLOT(photo_slot_to_change_scale_point22(QPointF)));
//    connect(sp_plot->photo,SIGNAL(photo_signal_to_change_scale_angle2(double,double)),this,SLOT(photo_slot_to_change_scale_angle2(double,double)));
    this->showMaximized();

}

SpectrWidget::~SpectrWidget()
{
    delete sp_plot;
    delete z2vector;
    delete data;
    delete ui;
}

void SpectrWidget::on_read_pushbutton_clicked()
{
    if (data!=NULL)
    {
        QMessageBox::information(0,"error","Only one graph");
        return;
    }
    QString way = QFileDialog::getOpenFileName(this, tr("Open File"), "",tr(".bin Files (*.bin)"));
    if (way==0)
    {
        return;
    }

    ui->progressBar->setValue(10);
    data = new IOData(this);
    int N_k;
    int N_fi;
    double F_start,F_stop, AzStart,AzStop;
    ui->progressBar->setValue(15);
    data->d_readmasSize(way,N_k,N_fi);
    double_complex *masin=new double_complex[N_k*N_fi];



    ui->progressBar->setValue(20);
    data->d_readFile(way,N_k,N_fi,F_start,F_stop,AzStart,AzStop,masin);
    control->ui->Nk_lineedit_data->setText(QString::number(N_k));
    control->ui->Nfi_lineedit_data->setText(QString::number(N_fi));
    control->ui->Fstart_lineedit_data->setText(QString::number(F_start));
    control->ui->Fstop_lineedit_data->setText(QString::number(F_stop));
    control->ui->Azstart_lieedit_data->setText(QString::number(AzStart));
    control->ui->Azstop_lineedit_data->setText(QString::number(AzStop));
    ui->progressBar->setValue(50);
    emit set_data_2D(way);
    bool is_double = true;
    if (is_double)
    {
        double pi = 3.1415926;
        bool bWhole = true;
        int NEWCOL=2048;// int NEWCOL=2048;
        int NEWROW=1024;
        double fi_degspan = 20.0;
        if(bWhole){
            fi_degspan = 360.0;
            // N_fi = 15000;
        }
        double_complex *mas=new double_complex[NEWCOL*NEWROW];
        bool a = SetArrayZ2Z(N_k,N_fi,F_start,F_stop,AzStart,AzStop,(double*)masin,false);
        ui->progressBar->setValue(60);

        double dAzStart =  40;
        double dAzStop =  60;
        bool b = CalcZ2Z(NEWCOL,NEWROW,F_start,F_stop,dAzStart,dAzStop,(double*)mas);
        ui->progressBar->setValue(70);

        GLOBAL_F_start = F_start;
        GLOBAL_F_stop  = F_stop;
        z2vector->resize(NEWCOL*NEWROW);
        z2vector->set_zero_vector(NEWCOL,NEWROW,-100,100,-100,100);
        for (int i=0;i<z2vector->size()-1;i++)
        {
            (*z2vector)[i].x = mas[i].x;
            (*z2vector)[i].y = mas[i].y;
        }
        ui->progressBar->setValue(90);

        sp_plot->draw_spectr(*z2vector,get_zstart()+control->ui->spectr_shift_lineedit->text().toDouble(),get_zstop()+control->ui->spectr_shift_lineedit->text().toDouble(),get_xstart(),get_xstop(),ui->max_spinbox->text().toDouble(),ui->min_spinbox->text().toDouble());
        z2vector->startx = get_zstart()+control->ui->spectr_shift_lineedit->text().toDouble();
        z2vector->stopx = get_zstop()+control->ui->spectr_shift_lineedit->text().toDouble();
        z2vector->starty = get_xstart();
        z2vector->stopy = get_xstop();
        double scale = max(fabs(get_xstart()-get_xstop()),fabs(get_zstart()-get_zstop()));
        z2vector->scale = scale;
            sp_plot->setAxisScale(QwtPlot::yLeft,-scale/2,scale/2);
            sp_plot->setAxisScale(QwtPlot::xBottom,-scale/2,scale/2);


        sp_plot->replot();
        if (zoomer_mod)
            sp_plot->slot_for_zoomer(sp_plot->point_for_zoomer1,sp_plot->point_for_zoomer1);
        ui->progressBar->setValue(100);



        //        control->ui->Fstart_lineedit_data->setText(QString::number(get_xstart()));
        //        control->ui->Fstop_lineedit_data->setText(QString::number(get_xstop()));
        //        control->ui->Azstart_lieedit_data->setText(QString::number(get_zstart()));
        //        control->ui->Azstop_lineedit_data->setText(QString::number(get_zstop()));
        delete mas;
    }
    else {

        bool bWhole = true;
        int NEWCOL=2048;
        int NEWROW=1024;
        float fi_degspan = 20.0;
        if(bWhole){
            fi_degspan = 360.0;
            //N_fi = 15000;
        }
        float_complex *mas=new float_complex[NEWCOL*NEWROW];
        bool a = SetArrayC2C(N_k,N_fi,F_start,F_stop,AzStart,AzStop,(float*)masin,true);
        float dAzStart =  40;
        float dAzStop =  60;
        bool b = CalcC2C(NEWCOL,NEWROW,F_start,F_stop,dAzStart,dAzStop,(float*)mas);
        GLOBAL_F_start = F_start;
        GLOBAL_F_stop  = F_stop;
        z2vector->resize(NEWCOL*NEWROW);
        z2vector->set_zero_vector(NEWCOL,NEWROW,-100,100,-100,100);
        for (int i=0;i<z2vector->size()-1;i++)
        {
            (*z2vector)[i].x = mas[i].x;
            (*z2vector)[i].y = mas[i].y;
        }
        ui->progressBar->setValue(90);
        sp_plot->draw_spectr(*z2vector,f_get_zstart()+control->ui->spectr_shift_lineedit->text().toDouble(),f_get_zstop()+control->ui->spectr_shift_lineedit->text().toDouble(),f_get_xstart(),f_get_xstop(),ui->max_spinbox->text().toDouble(),ui->min_spinbox->text().toDouble());
        ui->progressBar->setValue(100);
        delete mas;
    }
    delete masin;
}







bool bInProgress = false;
void SpectrWidget::change_FI0_cuda_test(int count)
{
    bool is_double = true;
    if (is_double)
    {
        ui->progressBar->setValue(50);
        if(bInProgress) return;
        bInProgress = true;
        int NEWCOL=2048;
        int NEWROW=1024;
        double_complex *mas=new double_complex[NEWCOL*NEWROW];
        double dAzStart = (double)count - control->ui->dAzStart_lineEdit->text().toDouble();
        double dAzStop = (double)count + control->ui->dAzStop_lineEdit->text().toDouble();
        try{
            bool b = CalcZ2Z(NEWCOL,NEWROW,GLOBAL_F_start,GLOBAL_F_stop,dAzStart,dAzStop,(double*)mas);
        }
        catch(...) {
            printf ("CUDA ERROR\n");
            bInProgress = false;
            return;
        }

        try{
            //test end
            z2vector->resize(NEWROW*NEWCOL);

            z2vector->set_zero_vector(NEWCOL,NEWROW,-100,100,-100,100);

            for (int i=0;i<z2vector->size()-1;i++)
            {
                (*z2vector)[i].x = mas[i].x;
                (*z2vector)[i].y = mas[i].y;
            }
            delete mas;

           //sp_plot->draw_spectr(*z2vector,get_xstart(),get_xstop(),get_zstart(),get_zstop(),-10.0,-60);
            sp_plot->draw_spectr(*z2vector,get_zstart()+control->ui->spectr_shift_lineedit->text().toDouble(),get_zstop()+control->ui->spectr_shift_lineedit->text().toDouble(),get_xstart(),get_xstop(),ui->max_spinbox->text().toDouble(),ui->min_spinbox->text().toDouble());
            z2vector->startx = get_zstart()+control->ui->spectr_shift_lineedit->text().toDouble();
            z2vector->stopx = get_zstop()+control->ui->spectr_shift_lineedit->text().toDouble();
            z2vector->starty = get_xstart();
            z2vector->stopy = get_xstop();

           double scale = max(fabs(get_xstart()-get_xstop()),fabs(get_zstart()-get_zstop()));
           z2vector->scale = scale;

           sp_plot->setAxisScale(QwtPlot::yLeft,-scale/2,scale/2);
           sp_plot->setAxisScale(QwtPlot::xBottom,-scale/2,scale/2);
           if (zoomer_mod)
           {
               sp_plot->setAxisScale(QwtPlot::yLeft,sp_plot->trans_y(sp_plot->point_for_zoomer1.y()),sp_plot->trans_y(sp_plot->point_for_zoomer2.y()));
               sp_plot->setAxisScale(QwtPlot::xBottom,sp_plot->trans_x(sp_plot->point_for_zoomer1.x()),sp_plot->trans_x(sp_plot->point_for_zoomer2.x()));
           }
           sp_plot->replot();

            ui->progressBar->setValue(100);
            sp_plot->draw_widget->replot_sketch(control->ui->x_shift_lineEdit->text().toDouble(),control->ui->y_shift_lineEdit->text().toDouble(),control->ui->x_scale_lineEdit->text().toDouble(),control->ui->y_scale_lineEdit->text().toDouble(),
                                                control->ui->fi_lineEdit->text().toDouble(),control->ui->horizontalSlider_for_cuda_test->value(),control->ui->k_lineEdit->text().toDouble());

            //        control->ui->Fstart_lineedit_data->setText(QString::number(get_xstart()));
            //        control->ui->Fstop_lineedit_data->setText(QString::number(get_xstop()));
            //        control->ui->Azstart_lieedit_data->setText(QString::number(get_zstart()));
            //        control->ui->Azstop_lineedit_data->setText(QString::number(get_zstop()));
        }
        catch(...) {
            printf ("RENDER ERROR\n");
            bInProgress = false;
            return;
        }

        bInProgress = false;
    }
    else {
        ui->progressBar->setValue(50);

        if(bInProgress) return;
        bInProgress = true;
        printf ("count enter %d \n", count);
        int NEWCOL=2048;
        int NEWROW=1024;
        float_complex *mas=new float_complex[NEWCOL*NEWROW];
        float dAzStart = (float)count - control->ui->dAzStart_lineEdit->text().toFloat();
        float dAzStop = (float)count + control->ui->dAzStop_lineEdit->text().toFloat();
        try{
            bool b = CalcC2C(NEWCOL,NEWROW,GLOBAL_F_start,GLOBAL_F_stop,dAzStart,dAzStop,(float*)mas);
        }
        catch(...) {
            printf ("CUDA ERROR\n");
            bInProgress = false;
            return;
        }
        printf ("count proceed\n");
        try{
            //test end
            z2vector->resize(NEWROW*NEWCOL);
            printf ("count  %d \n", count);
            z2vector->set_zero_vector(NEWCOL,NEWROW,-100,100,-100,100);

            for (int i=0;i<z2vector->size()-1;i++)
            {
                (*z2vector)[i].x = mas[i].x;
                (*z2vector)[i].y = mas[i].y;
            }

            delete mas;

            sp_plot->draw_spectr(*z2vector,f_get_zstart()+control->ui->spectr_shift_lineedit->text().toDouble(),f_get_zstop()+control->ui->spectr_shift_lineedit->text().toDouble(),f_get_xstart(),f_get_xstop(),ui->max_spinbox->text().toDouble(),ui->min_spinbox->text().toDouble());
            ui->progressBar->setValue(100);
        }
        catch(...) {
            printf ("RENDER ERROR\n");
            bInProgress = false;
            return;
        }
        printf ("count exit\n");
        bInProgress = false;
    }
}
void SpectrWidget::on_type_combobox_currentIndexChanged(const QString &arg1)
{
//    clock_t t7 = clock();
    if (arg1=="Ampl")
    {
        sp_plot->etype=Spectro_Plot::Ampl;
        sp_plot->draw_spectr(*z2vector,z2vector->startx,z2vector->stopx,z2vector->starty,z2vector->stopy,ui->max_spinbox->text().toDouble(),ui->min_spinbox->text().toDouble());
        sp_plot->setAxisScale(QwtPlot::yLeft,-z2vector->scale/2,z2vector->scale/2);
        sp_plot->setAxisScale(QwtPlot::xBottom,-z2vector->scale/2,z2vector->scale/2);
        sp_plot->replot();
        if (zoomer_mod)
            sp_plot->slot_for_zoomer(sp_plot->point_for_zoomer1,sp_plot->point_for_zoomer1);
    }
    if (arg1=="Phase")
    {
        sp_plot->etype=Spectro_Plot::Phase;
        sp_plot->draw_spectr(*z2vector,z2vector->startx,z2vector->stopx,z2vector->starty,z2vector->stopy,ui->max_spinbox->text().toDouble(),ui->min_spinbox->text().toDouble());
        sp_plot->setAxisScale(QwtPlot::yLeft,-z2vector->scale/2,z2vector->scale/2);
        sp_plot->setAxisScale(QwtPlot::xBottom,-z2vector->scale/2,z2vector->scale/2);
        sp_plot->replot();
        if (zoomer_mod)
            sp_plot->slot_for_zoomer(sp_plot->point_for_zoomer1,sp_plot->point_for_zoomer1);
    }
    if (arg1=="Re")
    {
        sp_plot->etype=Spectro_Plot::Re;
        sp_plot->draw_spectr(*z2vector,z2vector->startx,z2vector->stopx,z2vector->starty,z2vector->stopy,ui->max_spinbox->text().toDouble(),ui->min_spinbox->text().toDouble());
        sp_plot->setAxisScale(QwtPlot::yLeft,-z2vector->scale/2,z2vector->scale/2);
        sp_plot->setAxisScale(QwtPlot::xBottom,-z2vector->scale/2,z2vector->scale/2);
        sp_plot->replot();
        if (zoomer_mod)
            sp_plot->slot_for_zoomer(sp_plot->point_for_zoomer1,sp_plot->point_for_zoomer1);
    }
    if (arg1=="Im")
    {
        sp_plot->etype=Spectro_Plot::Im;
        sp_plot->draw_spectr(*z2vector,z2vector->startx,z2vector->stopx,z2vector->starty,z2vector->stopy,ui->max_spinbox->text().toDouble(),ui->min_spinbox->text().toDouble());
        sp_plot->setAxisScale(QwtPlot::yLeft,-z2vector->scale/2,z2vector->scale/2);
        sp_plot->setAxisScale(QwtPlot::xBottom,-z2vector->scale/2,z2vector->scale/2);
        sp_plot->replot();
        if (zoomer_mod)
            sp_plot->slot_for_zoomer(sp_plot->point_for_zoomer1,sp_plot->point_for_zoomer1);
    }
//    clock_t t8 = clock();
//    time("Changetime:"+QString::number((t8-t7))+" ");

}

void SpectrWidget::on_max_spinbox_valueChanged(int arg1)
{
    sp_plot->draw_spectr(*z2vector,z2vector->startx,z2vector->stopx,z2vector->starty,z2vector->stopy,ui->max_spinbox->text().toDouble(),ui->min_spinbox->text().toDouble());
    sp_plot->setAxisScale(QwtPlot::yLeft,-z2vector->scale/2,z2vector->scale/2);
    sp_plot->setAxisScale(QwtPlot::xBottom,-z2vector->scale/2,z2vector->scale/2);
    sp_plot->replot();
    if (zoomer_mod)
        sp_plot->slot_for_zoomer(sp_plot->point_for_zoomer1,sp_plot->point_for_zoomer1);
}

void SpectrWidget::on_min_spinbox_valueChanged(double arg1)
{
    sp_plot->draw_spectr(*z2vector,z2vector->startx,z2vector->stopx,z2vector->starty,z2vector->stopy,ui->max_spinbox->text().toDouble(),ui->min_spinbox->text().toDouble());
    sp_plot->setAxisScale(QwtPlot::yLeft,-z2vector->scale/2,z2vector->scale/2);
    sp_plot->setAxisScale(QwtPlot::xBottom,-z2vector->scale/2,z2vector->scale/2);
    sp_plot->replot();
    if (zoomer_mod)
        sp_plot->slot_for_zoomer(sp_plot->point_for_zoomer1,sp_plot->point_for_zoomer1);
}

//void SpectrWidget::time(QString a)
//{
//    //ui->lineEdit->setText(ui->lineEdit->text()+" "+a);
//}

void SpectrWidget::on_rect_pushButton_clicked()
{
    sp_plot->draw_widget->eType=Spectro_draw::Rect;
    sp_plot->draw_widget->is_new_item=true;
}

void SpectrWidget::on_polygon_pushButton_clicked()
{
    sp_plot->draw_widget->eType=Spectro_draw::Polygon;
    sp_plot->draw_widget->is_new_item=true;
}

void SpectrWidget::on_spec_type_combobox_currentIndexChanged(const QString &arg1)
{
    if (arg1=="Transparent")
    {
        sp_plot->is_transparent=true;
        sp_plot->draw_spectr(*z2vector,z2vector->startx,z2vector->stopx,z2vector->starty,z2vector->stopy,ui->max_spinbox->text().toDouble(),ui->min_spinbox->text().toDouble());
        sp_plot->setAxisScale(QwtPlot::yLeft,-z2vector->scale/2,z2vector->scale/2);
        sp_plot->setAxisScale(QwtPlot::xBottom,-z2vector->scale/2,z2vector->scale/2);
        sp_plot->replot();
        if (zoomer_mod)
            sp_plot->slot_for_zoomer(sp_plot->point_for_zoomer1,sp_plot->point_for_zoomer1);
    }
    if (arg1=="Normal")
    {
        sp_plot->is_transparent=false;
        sp_plot->draw_spectr(*z2vector,z2vector->startx,z2vector->stopx,z2vector->starty,z2vector->stopy,ui->max_spinbox->text().toDouble(),ui->min_spinbox->text().toDouble());
        sp_plot->setAxisScale(QwtPlot::yLeft,-z2vector->scale/2,z2vector->scale/2);
        sp_plot->setAxisScale(QwtPlot::xBottom,-z2vector->scale/2,z2vector->scale/2);
        sp_plot->replot();
        if (zoomer_mod)
            sp_plot->slot_for_zoomer(sp_plot->point_for_zoomer1,sp_plot->point_for_zoomer1);
    }
}

void SpectrWidget::on_select_point_pushButton_clicked()
{

    // sp_plot->draw_widget->end();

}

void SpectrWidget::on_line_pushButton_clicked()
{
    sp_plot->draw_widget->eType=Spectro_draw::Line;
    sp_plot->draw_widget->is_new_item=true;
}

void SpectrWidget::on_color_comboBox_currentIndexChanged(const QString &arg1)
{
    if (arg1=="black")
    {
        // sp_plot->draw_widget->change_color(ui->pol_rec_line_comboBox->currentText(),Qt::black);
        sp_plot->draw_widget->change_color(sp_plot->draw_widget->getRGB(Spectro_draw::black));
    }
    if (arg1=="cyan")
    {
        sp_plot->draw_widget->change_color(sp_plot->draw_widget->getRGB(Spectro_draw::cyan));
    }
    if (arg1=="darkCyan")
    {
        sp_plot->draw_widget->change_color(sp_plot->draw_widget->getRGB(Spectro_draw::darkCyan));
    }
    if (arg1=="red")
    {
        sp_plot->draw_widget->change_color(sp_plot->draw_widget->getRGB(Spectro_draw::red));
    }
    if (arg1=="darkRed")
    {
        sp_plot->draw_widget->change_color(sp_plot->draw_widget->getRGB(Spectro_draw::darkRed));
    }
    if (arg1=="magenta")
    {
        sp_plot->draw_widget->change_color(sp_plot->draw_widget->getRGB(Spectro_draw::magenta));
    }
    if (arg1=="darkMagenta")
    {
        sp_plot->draw_widget->change_color(sp_plot->draw_widget->getRGB(Spectro_draw::darkMagenta));
    }
    if (arg1=="green")
    {
        sp_plot->draw_widget->change_color(sp_plot->draw_widget->getRGB(Spectro_draw::green));
    }
    if (arg1=="darkGreen")
    {
        sp_plot->draw_widget->change_color(sp_plot->draw_widget->getRGB(Spectro_draw::darkGreen));
    }
    if (arg1=="yellow")
    {
        sp_plot->draw_widget->change_color(sp_plot->draw_widget->getRGB(Spectro_draw::yellow));
    }
    if (arg1=="darkYellow")
    {
        sp_plot->draw_widget->change_color(sp_plot->draw_widget->getRGB(Spectro_draw::darkYellow));
    }
    if (arg1=="blue")
    {
        sp_plot->draw_widget->change_color(sp_plot->draw_widget->getRGB(Spectro_draw::blue));
    }
    if (arg1=="darkBlue")
    {
        sp_plot->draw_widget->change_color(sp_plot->draw_widget->getRGB(Spectro_draw::darkBlue));
    }
    if (arg1=="gray")
    {
        sp_plot->draw_widget->change_color(sp_plot->draw_widget->getRGB(Spectro_draw::gray));
    }
    if (arg1=="darkGray")
    {
        sp_plot->draw_widget->change_color(sp_plot->draw_widget->getRGB(Spectro_draw::darkGray));
    }
    if (arg1=="lightGray")
    {
        sp_plot->draw_widget->change_color(sp_plot->draw_widget->getRGB(Spectro_draw::lightGray));
    }
    if (arg1=="black")
    {
        sp_plot->draw_widget->eColor=Spectro_draw::black;
    }
    if (arg1=="cyan")
    {
        sp_plot->draw_widget->eColor=Spectro_draw::cyan;
    }
    if (arg1=="darkCyan")
    {
        sp_plot->draw_widget->eColor=Spectro_draw::darkCyan;
    }
    if (arg1=="red")
    {
        sp_plot->draw_widget->eColor=Spectro_draw::red;
    }
    if (arg1=="darkRed")
    {
        sp_plot->draw_widget->eColor=Spectro_draw::darkRed;
    }
    if (arg1=="magenta")
    {
        sp_plot->draw_widget->eColor=Spectro_draw::magenta;
    }
    if (arg1=="darkMagenta")
    {
        sp_plot->draw_widget->eColor=Spectro_draw::darkMagenta;
    }
    if (arg1=="green")
    {
        sp_plot->draw_widget->eColor=Spectro_draw::green;
    }
    if (arg1=="darkGreen")
    {
        sp_plot->draw_widget->eColor=Spectro_draw::darkGreen;
    }
    if (arg1=="yellow")
    {
        sp_plot->draw_widget->eColor=Spectro_draw::yellow;
    }
    if (arg1=="darkYellow")
    {
        sp_plot->draw_widget->eColor=Spectro_draw::darkYellow;
    }
    if (arg1=="blue")
    {
        sp_plot->draw_widget->eColor=Spectro_draw::blue;
    }
    if (arg1=="darkBlue")
    {
        sp_plot->draw_widget->eColor=Spectro_draw::darkBlue;
    }
    if (arg1=="gray")
    {
        sp_plot->draw_widget->eColor=Spectro_draw::gray;
    }
    if (arg1=="darkGray")
    {
        sp_plot->draw_widget->eColor=Spectro_draw::darkGray;
    }
    if (arg1=="lightGray")
    {
        sp_plot->draw_widget->eColor=Spectro_draw::lightGray;
    }
    sp_plot->draw_widget->repaint();
}

void SpectrWidget::on_rect_pushButton_toggled(bool checked)
{
    if (checked==true)
    {
        sp_plot->draw_widget->eType=Spectro_draw::Rect;

        ui->line_pushButton->setChecked(false);


        ui->polygon_pushButton->setChecked(false);
    }
}

void SpectrWidget::on_polygon_pushButton_toggled(bool checked)
{
    if (checked==true)
    {
        sp_plot->draw_widget->eType=Spectro_draw::Polygon;
        ui->line_pushButton->setChecked(false);
        ui->rect_pushButton->setChecked(false);
    }
}

void SpectrWidget::on_circle_pushButton_toggled(bool checked)
{
    if (checked==true)
    {
        sp_plot->draw_widget->eType=Spectro_draw::Circle;

        ui->line_pushButton->setChecked(false);
        ui->rect_pushButton->setChecked(false);
        ui->polygon_pushButton->setChecked(false);
    }
}

void SpectrWidget::on_line_pushButton_toggled(bool checked)
{
    if (checked==true)
    {
        sp_plot->draw_widget->eType=Spectro_draw::Line;

        ui->rect_pushButton->setChecked(false);

        ui->polygon_pushButton->setChecked(false);
    }
}



void SpectrWidget::on_delete_last_pushButton_clicked()
{
    sp_plot->draw_widget->delete_last();
}

void SpectrWidget::on_select_point_pushButton_toggled(bool checked)
{
    if (checked==true)
        sp_plot->draw_widget->is_select_mode_enable=true;
    else
        sp_plot->draw_widget->is_select_mode_enable=false;
}

void SpectrWidget::on_cont_read_pushButton_clicked()
{
    sp_plot->draw_widget->read_from_file();

}




void SpectrWidget::on_zoom_pushButton_toggled(bool checked)
{
    if (checked==true)
    {
        ui->select_point_pushButton->setChecked(false);
        ui->line_pushButton->setChecked(false);
        ui->rect_pushButton->setChecked(false);
        sp_plot->draw_widget->is_zoom_mode_enable=true;
        ui->polygon_pushButton->setChecked(false);
        //TODO все сделать enabled false

        ui->delete_sketch_pushButton->setEnabled(false);
        ui->delete_last_pushButton->setEnabled(false);
        ui->line_pushButton->setEnabled(false);
        ui->polygon_pushButton->setEnabled(false);
        ui->rect_pushButton->setEnabled(false);
        ui->select_point_pushButton->setEnabled(false);
       // ui->zoom_pushButton->setEnabled(false);
        zoomer_mod = true;

    }
    if (checked==false)
    {
        ui->delete_sketch_pushButton->setEnabled(true);
        ui->delete_last_pushButton->setEnabled(true);
        ui->line_pushButton->setEnabled(true);
        ui->polygon_pushButton->setEnabled(true);
        ui->rect_pushButton->setEnabled(true);
        ui->select_point_pushButton->setEnabled(true);
        ui->zoom_pushButton->setEnabled(true);

        sp_plot->draw_widget->is_zoom_mode_enable=false;
        zoomer_mod = false;
        sp_plot->setAxisScale(QwtPlot::yLeft,-z2vector->scale/2,z2vector->scale/2);
        sp_plot->setAxisScale(QwtPlot::xBottom,-z2vector->scale/2,z2vector->scale/2);
        sp_plot->replot();


    }
}

void SpectrWidget::change_x_shift(double a)
{
    control->ui->x_shift_lineEdit->setText(QString::number(a));
}
void SpectrWidget::change_y_shift(double a)
{
    control->ui->y_shift_lineEdit->setText(QString::number(a));
}
void SpectrWidget::change_x_scale(double a)
{
    control->ui->x_scale_lineEdit->setText(QString::number(a));
}
void SpectrWidget::change_y_scale(double a)
{
    control->ui->y_scale_lineEdit->setText(QString::number(a));
}
void SpectrWidget::change_fi(double a)
{
    control->ui->fi_lineEdit->setText(QString::number(a));
}
void SpectrWidget::change_k(double a)
{
    control->ui->k_lineEdit->setText(QString::number(a));
}

//void SpectrWidget::on_horizontalSlider_actionTriggered(int action)
//{

//}

void SpectrWidget::on_x_scale_lineEdit_textChanged(const QString &arg1)
{
    sp_plot->draw_widget->replot_sketch(control->ui->x_shift_lineEdit->text().toDouble(),control->ui->y_shift_lineEdit->text().toDouble(),control->ui->x_scale_lineEdit->text().toDouble(),control->ui->y_scale_lineEdit->text().toDouble(),
                                        control->ui->fi_lineEdit->text().toDouble(),0.0,control->ui->k_lineEdit->text().toDouble());


}

void SpectrWidget::on_x_shift_lineEdit_textChanged(const QString &arg1)
{
    sp_plot->draw_widget->replot_sketch(control->ui->x_shift_lineEdit->text().toDouble(),control->ui->y_shift_lineEdit->text().toDouble(),control->ui->x_scale_lineEdit->text().toDouble(),control->ui->y_scale_lineEdit->text().toDouble(),
                                        control->ui->fi_lineEdit->text().toDouble(),0.0,control->ui->k_lineEdit->text().toDouble());
}

void SpectrWidget::on_y_shift_lineEdit_textChanged(const QString &arg1)
{
    sp_plot->draw_widget->replot_sketch(control->ui->x_shift_lineEdit->text().toDouble(),control->ui->y_shift_lineEdit->text().toDouble(),control->ui->x_scale_lineEdit->text().toDouble(),control->ui->y_scale_lineEdit->text().toDouble(),
                                        control->ui->fi_lineEdit->text().toDouble(),0.0,control->ui->k_lineEdit->text().toDouble());
}

void SpectrWidget::on_y_scale_lineEdit_textChanged(const QString &arg1)
{
    sp_plot->draw_widget->replot_sketch(control->ui->x_shift_lineEdit->text().toDouble(),control->ui->y_shift_lineEdit->text().toDouble(),control->ui->x_scale_lineEdit->text().toDouble(),control->ui->y_scale_lineEdit->text().toDouble(),
                                        control->ui->fi_lineEdit->text().toDouble(),0.0,control->ui->k_lineEdit->text().toDouble());
}

void SpectrWidget::on_delete_sketch_pushButton_clicked()
{
    if (sp_plot->draw_widget->sketch_list.size()!=0)
    {
        sp_plot->draw_widget->sketch_list.clear();
        sp_plot->draw_widget->repaint();
    }
}

void SpectrWidget::on_fi_shift_lineEdit_textChanged(const QString &arg1)
{
    sp_plot->draw_widget->replot_sketch(control->ui->x_shift_lineEdit->text().toDouble(),control->ui->y_shift_lineEdit->text().toDouble(),control->ui->x_scale_lineEdit->text().toDouble(),control->ui->y_scale_lineEdit->text().toDouble(),
                                        control->ui->fi_lineEdit->text().toDouble(),0.0,control->ui->k_lineEdit->text().toDouble());
}
void SpectrWidget::change_fi_shift(double a)
{
    control->ui->fi_shift_slider->setValue(a);
}

void SpectrWidget::on_fi_lineEdit_textChanged(const QString &arg1)
{
    sp_plot->draw_widget->replot_sketch(control->ui->x_shift_lineEdit->text().toDouble(),control->ui->y_shift_lineEdit->text().toDouble(),control->ui->x_scale_lineEdit->text().toDouble(),control->ui->y_scale_lineEdit->text().toDouble(),
                                        control->ui->fi_lineEdit->text().toDouble(),0.0,control->ui->k_lineEdit->text().toDouble());
}



void SpectrWidget::on_flip_checkBox_toggled(bool checked)
{
    sp_plot->draw_widget->flip();
}

void SpectrWidget::on_sketch_checkBox_toggled(bool checked)
{
    if (checked==true)
    {
        sp_plot->draw_widget->is_sketch_mode_enable=true;
    }
    if (checked==false)
        sp_plot->draw_widget->is_sketch_mode_enable=false;
}
//void SpectrWidget::slot_size(double a)
//{
//    ui->view_scalelineEdit->setText(QString::number(a));
//}

void SpectrWidget::on_scale_checkBox_toggled(bool checked)
{
    if (checked==true)
    {
        sp_plot->draw_widget->is_scale_mode_enable=true;

    }
    if (checked==false)
        sp_plot->draw_widget->is_scale_mode_enable=false;
}

void SpectrWidget::on_fi_shift_slider_sliderMoved(int position)
{

    sp_plot->draw_widget->replot_sketch(control->ui->x_shift_lineEdit->text().toDouble(),control->ui->y_shift_lineEdit->text().toDouble(),control->ui->x_scale_lineEdit->text().toDouble(),control->ui->y_scale_lineEdit->text().toDouble(),
                                        control->ui->fi_lineEdit->text().toDouble(),0.0,control->ui->k_lineEdit->text().toDouble());
}

void SpectrWidget::slot_to_change_scale_scale1(double a)
{
    control->ui->x_y_scale_lineedit1->setText(QString::number(a));
}
void SpectrWidget::slot_to_change_scale_scale2(double a)
{
    control->ui->x_y_scale_lineedit2->setText(QString::number(a));
}
void SpectrWidget::slot_to_change_scale_angle1(double a,double b)
{
    double x=360*atan2(b,a)/(2*3.1415926);
    control->ui->angle_lineedit1->setText(QString::number(x));
}
void SpectrWidget::slot_to_change_scale_angle2(double a, double b)
{
    double x=360*atan2(b,a)/(2*3.1415926);
    control->ui->angle_lineedit2->setText(QString::number(x));
}
void SpectrWidget::slot_to_change_scale_point1(QPointF point)
{
    control->ui->x_shift_lineedit1->setText(QString::number(point.x()));
    control->ui->y_shift_lineedit1->setText(QString::number(point.y()));
}
void SpectrWidget::slot_to_change_scale_point22(QPointF point)
{
    control->ui->x_shift_lineedit2->setText(QString::number(point.x()));
    control->ui->y_shift_lineedit2->setText(QString::number(point.y()));
}


void SpectrWidget::on_x_y_scale_pushButton_clicked()
{
    sp_plot->draw_widget->is_scale_mode_scale1=true;
    sp_plot->draw_widget->is_scale_mode_angle1=false;
    sp_plot->draw_widget->is_scale_mode_point1=false;

    sp_plot->draw_widget->is_scale_mode_scale2=false;
    sp_plot->draw_widget->is_scale_mode_angle2=false;
    sp_plot->draw_widget->is_scale_mode_point2=false;

}

void SpectrWidget::on_angle_pushbutton_clicked()
{
    sp_plot->draw_widget->is_scale_mode_scale1=false;
    sp_plot->draw_widget->is_scale_mode_angle1=true;
    sp_plot->draw_widget->is_scale_mode_point1=false;

    sp_plot->draw_widget->is_scale_mode_scale2=false;
    sp_plot->draw_widget->is_scale_mode_angle2=false;
    sp_plot->draw_widget->is_scale_mode_point2=false;
}

void SpectrWidget::on_x_y_shitft_pushButton_clicked()
{
    sp_plot->draw_widget->is_scale_mode_scale1=false;
    sp_plot->draw_widget->is_scale_mode_angle1=false;
    sp_plot->draw_widget->is_scale_mode_point1=true;

    sp_plot->draw_widget->is_scale_mode_scale2=false;
    sp_plot->draw_widget->is_scale_mode_angle2=false;
    sp_plot->draw_widget->is_scale_mode_point2=false;
}

void SpectrWidget::on_ok_x_y_scale_pushButton_clicked()
{
    double a=control->ui->x_y_scale_lineedit1->text().toDouble()/control->ui->x_y_scale_lineedit2->text().toDouble();

    control->ui->x_scale_lineEdit->setText(QString::number(control->ui->x_scale_lineEdit->text().toDouble()*a));
    control->ui->y_scale_lineEdit->setText(QString::number(control->ui->y_scale_lineEdit->text().toDouble()*a));
    control->ui->x_y_scale_lineedit1->setText(control->ui->x_y_scale_lineedit2->text());
}

void SpectrWidget::on_ok_angle_pushbutton_clicked()
{
    if (control->ui->angle_lineedit2->text()=="")
    {
        //  double a=ui->angle_lineedit1->text().toDouble();//ui->angle_lineedit2->text().toDouble()-ui->angle_lineedit1->text().toDouble();
        //   ui->angle_lineedit1->setText(ui->angle_lineedit2->text());
        //   ui->fi_lineEdit->setText(QString::number(ui->fi_lineEdit->text().toDouble()+(ui->angle_lineedit2->text().toDouble()-ui->angle_lineedit1->text().toDouble())));
        control->ui->fi_lineEdit->setText(QString::number(control->ui->fi_lineEdit->text().toDouble()+control->ui->angle_lineedit1->text().toDouble()));
    }
    else
    {
        double a=control->ui->angle_lineedit2->text().toDouble()-control->ui->angle_lineedit1->text().toDouble();
        control->ui->angle_lineedit1->setText(control->ui->angle_lineedit2->text());
        control->ui->fi_lineEdit->setText(QString::number(control->ui->fi_lineEdit->text().toDouble()+a));
    }

}

void SpectrWidget::on_ok_x_y_shift_pushButton_clicked()
{
    double a=control->ui->x_shift_lineedit1->text().toDouble()-control->ui->x_shift_lineedit2->text().toDouble();

    double b=control->ui->y_shift_lineedit1->text().toDouble()-control->ui->y_shift_lineedit2->text().toDouble();
    control->ui->x_shift_lineedit1->setText(control->ui->x_shift_lineedit2->text());
    control->ui->y_shift_lineedit1->setText(control->ui->y_shift_lineedit2->text());
    control->ui->x_shift_lineEdit->setText(QString::number(a));
    control->ui->y_shift_lineEdit->setText(QString::number(b));
}

void SpectrWidget::on_x_y_scale_pushButton_2_clicked()
{
    sp_plot->draw_widget->is_scale_mode_scale1=false;
    sp_plot->draw_widget->is_scale_mode_angle1=false;
    sp_plot->draw_widget->is_scale_mode_point1=false;

    sp_plot->draw_widget->is_scale_mode_scale2=true;
    sp_plot->draw_widget->is_scale_mode_angle2=false;
    sp_plot->draw_widget->is_scale_mode_point2=false;
}

void SpectrWidget::on_angle_pushbutton_2_clicked()
{
    sp_plot->draw_widget->is_scale_mode_scale1=false;
    sp_plot->draw_widget->is_scale_mode_angle1=false;
    sp_plot->draw_widget->is_scale_mode_point1=false;

    sp_plot->draw_widget->is_scale_mode_scale2=false;
    sp_plot->draw_widget->is_scale_mode_angle2=true;
    sp_plot->draw_widget->is_scale_mode_point2=false;
}

void SpectrWidget::on_x_y_shitft_pushButton_2_clicked()
{
    sp_plot->draw_widget->is_scale_mode_scale1=false;
    sp_plot->draw_widget->is_scale_mode_angle1=false;
    sp_plot->draw_widget->is_scale_mode_point1=false;

    sp_plot->draw_widget->is_scale_mode_scale2=false;
    sp_plot->draw_widget->is_scale_mode_angle2=false;
    sp_plot->draw_widget->is_scale_mode_point2=true;
}


void SpectrWidget::on_photo_enable_checkBox_toggled(bool checked)
{
    if (checked==true)
    {
        sp_plot->draw_widget->hide();
    }
    //
}

//void SpectrWidget::on_tabWidget_currentChanged(int index)
//{
//    if (index==0)
//    {
//        sp_plot->draw_widget->show();
//        sp_plot->photo->hide();
//    }
//    else
//    {
//        sp_plot->draw_widget->hide();
//        sp_plot->photo->show();
//    }
//}


void SpectrWidget::photo_change_x_shift(double a)
{
    control->ui->photo_x_shift_lineEdit->setText(QString::number(a));
}

void SpectrWidget::photo_change_y_shift(double a)
{
    control->ui->photo_y_shift_lineEdit->setText(QString::number(a));
}
void SpectrWidget::photo_change_x_scale(double a)
{
    control->ui->photo_x_scale_lineEdit->setText(QString::number(a));
}
void SpectrWidget::photo_change_y_scale(double a)
{
    control->ui->photo_y_scale_lineEdit->setText(QString::number(a));
}
void SpectrWidget::photo_change_fi(double a)
{
    control->ui->photo_fi_lineEdit->setText(QString::number(a));
}
void SpectrWidget::photo_change_k(double a)
{
    control->ui->photo_k_lineEdit->setText(QString::number(a));
}
void SpectrWidget::photo_change_fi_shift(double a)
{
    control->ui->photo_fi_shift_slider->setValue(a);
}
void SpectrWidget::photo_slot_to_change_scale_scale1(double a)
{
    control->ui->photo_x_y_scale_lineedit1->setText(QString::number(a));
}
void SpectrWidget::photo_slot_to_change_scale_scale2(double a)
{
    control->ui->photo_x_y_scale_lineedit2->setText(QString::number(a));
}
void SpectrWidget::photo_slot_to_change_scale_angle1(double a,double b)
{
    double x=360*atan2(b,a)/(2*3.1415926);
    control->ui->photo_angle_lineedit1->setText(QString::number(x));
}
void SpectrWidget::photo_slot_to_change_scale_angle2(double a,double b)
{
    double x=360*atan2(b,a)/(2*3.1415926);
    control->ui->photo_angle_lineedit2->setText(QString::number(x));
}
void SpectrWidget::photo_slot_to_change_scale_point1(QPointF point)
{
    control->ui->photo_x_shift_lineedit1->setText(QString::number(point.x()));
    control->ui->photo_y_shift_lineedit1->setText(QString::number(point.y()));
}
void SpectrWidget::photo_slot_to_change_scale_point22(QPointF point)
{
    control->ui->photo_x_shift_lineedit2->setText(QString::number(point.x()));
    control->ui->photo_y_shift_lineedit2->setText(QString::number(point.y()));
}

void SpectrWidget::on_photo_x_y_scale_pushButton_clicked()
{
//    sp_plot->photo->is_scale_mode_scale1=true;
//    sp_plot->photo->is_scale_mode_angle1=false;
//    sp_plot->photo->is_scale_mode_point1=false;

//    sp_plot->photo->is_scale_mode_scale2=false;
//    sp_plot->photo->is_scale_mode_angle2=false;
//    sp_plot->photo->is_scale_mode_point2=false;
}

void SpectrWidget::on_photo_x_y_scale_pushButton_2_clicked()
{
//    sp_plot->photo->is_scale_mode_scale1=false;
//    sp_plot->photo->is_scale_mode_angle1=false;
//    sp_plot->photo->is_scale_mode_point1=false;

//    sp_plot->photo->is_scale_mode_scale2=true;
//    sp_plot->photo->is_scale_mode_angle2=false;
//    sp_plot->photo->is_scale_mode_point2=false;
}

void SpectrWidget::on_photo_ok_x_y_scale_pushButton_clicked()
{
    double a=control->ui->photo_x_y_scale_lineedit1->text().toDouble()/control->ui->photo_x_y_scale_lineedit2->text().toDouble();

    control->ui->photo_x_scale_lineEdit->setText(QString::number(control->ui->photo_x_scale_lineEdit->text().toDouble()*a));
    control->ui->photo_y_scale_lineEdit->setText(QString::number(control->ui->photo_y_scale_lineEdit->text().toDouble()*a));
    control->ui->photo_x_y_scale_lineedit1->setText(control->ui->photo_x_y_scale_lineedit2->text());
}

void SpectrWidget::on_photo_angle_pushbutton_clicked()
{
//    sp_plot->photo->is_scale_mode_scale1=false;
//    sp_plot->photo->is_scale_mode_angle1=true;
//    sp_plot->photo->is_scale_mode_point1=false;

//    sp_plot->photo->is_scale_mode_scale2=false;
//    sp_plot->photo->is_scale_mode_angle2=false;
//    sp_plot->photo->is_scale_mode_point2=false;
}

void SpectrWidget::on_photo_ok_angle_pushbutton_clicked()
{
    if (control->ui->photo_angle_lineedit2->text()=="")
    {
        //  double a=ui->angle_lineedit1->text().toDouble();//ui->angle_lineedit2->text().toDouble()-ui->angle_lineedit1->text().toDouble();
        //   ui->angle_lineedit1->setText(ui->angle_lineedit2->text());
        //   ui->fi_lineEdit->setText(QString::number(ui->fi_lineEdit->text().toDouble()+(ui->angle_lineedit2->text().toDouble()-ui->angle_lineedit1->text().toDouble())));
        control->ui->photo_fi_lineEdit->setText(QString::number(control->ui->photo_fi_lineEdit->text().toDouble()+control->ui->photo_angle_lineedit1->text().toDouble()));
    }
    else
    {
        double a=control->ui->photo_angle_lineedit2->text().toDouble()-control->ui->photo_angle_lineedit1->text().toDouble();
        control->ui->photo_angle_lineedit1->setText(control->ui->photo_angle_lineedit2->text());
        control->ui->photo_fi_lineEdit->setText(QString::number(control->ui->photo_fi_lineEdit->text().toDouble()+a));
    }
}

void SpectrWidget::on_photo_angle_pushbutton_2_clicked()
{
//    sp_plot->photo->is_scale_mode_scale1=false;
//    sp_plot->photo->is_scale_mode_angle1=false;
//    sp_plot->photo->is_scale_mode_point1=false;

//    sp_plot->photo->is_scale_mode_scale2=false;
//    sp_plot->photo->is_scale_mode_angle2=true;
//    sp_plot->photo->is_scale_mode_point2=false;
}

void SpectrWidget::on_photo_x_y_shitft_pushButton_clicked()
{
//    sp_plot->photo->is_scale_mode_scale1=false;
//    sp_plot->photo->is_scale_mode_angle1=false;
//    sp_plot->photo->is_scale_mode_point1=true;

//    sp_plot->photo->is_scale_mode_scale2=false;
//    sp_plot->photo->is_scale_mode_angle2=false;
//    sp_plot->photo->is_scale_mode_point2=false;
}

void SpectrWidget::on_photo_ok_x_y_shift_pushButton_clicked()
{
    double a=control->ui->photo_x_shift_lineedit1->text().toDouble()-control->ui->photo_x_shift_lineedit2->text().toDouble();

    double b=control->ui->photo_y_shift_lineedit1->text().toDouble()-control->ui->photo_y_shift_lineedit2->text().toDouble();
    control->ui->photo_x_shift_lineedit1->setText(control->ui->photo_x_shift_lineedit2->text());
    control->ui->photo_y_shift_lineedit1->setText(control->ui->photo_y_shift_lineedit2->text());
    control->ui->photo_x_shift_lineEdit->setText(QString::number(a));
    control->ui->photo_y_shift_lineEdit->setText(QString::number(b));
}

void SpectrWidget::on_photo_x_y_shitft_pushButton_2_clicked()
{
//    sp_plot->photo->is_scale_mode_scale1=false;
//    sp_plot->photo->is_scale_mode_angle1=false;
//    sp_plot->photo->is_scale_mode_point1=false;

//    sp_plot->photo->is_scale_mode_scale2=false;
//    sp_plot->photo->is_scale_mode_angle2=false;
//    sp_plot->photo->is_scale_mode_point2=true;
}

//void SpectrWidget::on_photo_x_shift_lineEdit_textChanged(const QString &arg1)
//{
//    sp_plot->photo->replot_sketch(control->ui->photo_x_shift_lineEdit->text().toDouble(),control->ui->photo_y_shift_lineEdit->text().toDouble(),control->ui->photo_x_scale_lineEdit->text().toDouble(),control->ui->photo_y_scale_lineEdit->text().toDouble(),
//                                  control->ui->photo_fi_lineEdit->text().toDouble(),control->ui->photo_fi_shift_slider->value(),control->ui->photo_k_lineEdit->text().toDouble());
//}

//void SpectrWidget::on_photo_y_shift_lineEdit_textChanged(const QString &arg1)
//{
//    sp_plot->photo->replot_sketch(control->ui->photo_x_shift_lineEdit->text().toDouble(),control->ui->photo_y_shift_lineEdit->text().toDouble(),control->ui->photo_x_scale_lineEdit->text().toDouble(),control->ui->photo_y_scale_lineEdit->text().toDouble(),
//                                  control->ui->photo_fi_lineEdit->text().toDouble(),control->ui->photo_fi_shift_slider->value(),control->ui->photo_k_lineEdit->text().toDouble());}

//void SpectrWidget::on_photo_x_scale_lineEdit_textChanged(const QString &arg1)
//{
//    sp_plot->photo->replot_sketch(control->ui->photo_x_shift_lineEdit->text().toDouble(),control->ui->photo_y_shift_lineEdit->text().toDouble(),control->ui->photo_x_scale_lineEdit->text().toDouble(),control->ui->photo_y_scale_lineEdit->text().toDouble(),
//                                  control->ui->photo_fi_lineEdit->text().toDouble(),control->ui->photo_fi_shift_slider->value(),control->ui->photo_k_lineEdit->text().toDouble());}

//void SpectrWidget::on_photo_y_scale_lineEdit_textChanged(const QString &arg1)
//{
//    sp_plot->photo->replot_sketch(control->ui->photo_x_shift_lineEdit->text().toDouble(),control->ui->photo_y_shift_lineEdit->text().toDouble(),control->ui->photo_x_scale_lineEdit->text().toDouble(),control->ui->photo_y_scale_lineEdit->text().toDouble(),
//                                  control->ui->photo_fi_lineEdit->text().toDouble(),control->ui->photo_fi_shift_slider->value(),control->ui->photo_k_lineEdit->text().toDouble());}

//void SpectrWidget::on_photo_fi_lineEdit_textChanged(const QString &arg1)
//{
//    sp_plot->photo->replot_sketch(control->ui->photo_x_shift_lineEdit->text().toDouble(),control->ui->photo_y_shift_lineEdit->text().toDouble(),control->ui->photo_x_scale_lineEdit->text().toDouble(),control->ui->photo_y_scale_lineEdit->text().toDouble(),
//                                  control->ui->photo_fi_lineEdit->text().toDouble(),control->ui->photo_fi_shift_slider->value(),control->ui->photo_k_lineEdit->text().toDouble());}

//void SpectrWidget::on_photo_fi_shift_slider_valueChanged(int value)
//{
//    sp_plot->photo->replot_sketch(control->ui->photo_x_shift_lineEdit->text().toDouble(),control->ui->photo_y_shift_lineEdit->text().toDouble(),control->ui->photo_x_scale_lineEdit->text().toDouble(),control->ui->photo_y_scale_lineEdit->text().toDouble(),
//                                  control->ui->photo_fi_lineEdit->text().toDouble(),control->ui->photo_fi_shift_slider->value(),control->ui->photo_k_lineEdit->text().toDouble());}
void SpectrWidget::resizeEvent ( QResizeEvent * event )
{
    sp_plot->resize(this->width()-5,this->height()-60);
    sp_plot->draw_widget->resize(this->width()-40,this->height()-80);
    QWidget::resizeEvent(event);
}

void SpectrWidget::get_control(Form_Spectr* control1)
{
    control = control1;
}
double_complex SpectrWidget::MakeComplex(double x,double y)
{
    double_complex c;
    c.x = x;
    c.y = y;
    return c;
}
float_complex SpectrWidget::fMakeComplex(float x,float y)
{
    float_complex c;
    c.x = x;
    c.y = y;
    return c;
}



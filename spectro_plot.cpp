#include "spectro_plot.h"
#include "qwt_color_map.h"
#include "qwt_scale_widget.h"
#include "qwt_plot_zoomer.h"
#include "qwt_plot_panner.h"
#include "qwt_matrix_raster_data.h"
#include "time.h"
#include "QFileDialog"
#include "QLabel"
#include "qwt_color_map.h"
#include "z2vector.h"

class MyZoomer: public QwtPlotZoomer
{
public:
    MyZoomer(QwtPlotCanvas *canvas):
        QwtPlotZoomer(canvas)
    {
        setTrackerMode(AlwaysOn);
    }
    virtual QwtText trackerTextF(const QPointF &pos) const
    {
        QColor bg(Qt::white);
        bg.setAlpha(200);
        QwtText text = QwtPlotZoomer::trackerTextF(pos);
        text.setBackgroundBrush( QBrush( bg ));
        return text;
    }
};

Spectro_Plot::Spectro_Plot(QWidget *parent):
    QwtPlot(parent)
{
    etype=Ampl;
    is_transparent=false;
    grid=new QwtPlotGrid();
    grid->setMajPen(QPen(Qt::gray, 0, Qt::DotLine));
    grid->setMinPen(QPen(Qt::gray, 0 , Qt::DotLine));
    grid->attach(this);

    color_map = NULL;
    alpha_color_map= NULL;
    raster= NULL;
    data= NULL;

    /////////////////////////////////////////////////////////////
    zoomer = new MyZoomer(canvas());
    zoomer->setMousePattern(QwtEventPattern::MouseSelect2,
                            Qt::RightButton, Qt::ControlModifier);
    zoomer->setMousePattern(QwtEventPattern::MouseSelect3,
                            Qt::RightButton);
    /////////////////////////////////////////////////////////////
    panner = new QwtPlotPanner(canvas());
    panner->setAxisEnabled(QwtPlot::yRight, false);
    panner->setMouseButton(Qt::MidButton);

    /////////////////////////////////////////////////////////////
    const QFontMetrics fm(axisWidget(QwtPlot::yLeft)->font());
    QwtScaleDraw *sd = axisScaleDraw(QwtPlot::yLeft);
    sd->setMinimumExtent( fm.width("1.00") );
    /////////////////////////////////////////////////////////////
    const QColor c(Qt::darkBlue);
    zoomer->setRubberBandPen(c);
    zoomer->setTrackerPen(c);
    /////////////////////////////////////////////////////////////

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!WORKKK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    d_spectrogram = new QwtPlotSpectrogram();
    //        QLabel *label=new QLabel(this);
    //        QPixmap *image = new QPixmap("433px-BCDto7SegDecoder.png");
    //               label->setWindowOpacity(qreal(40)/100);
    //                label->move(50,00);
    //                label->resize(1100,900);
    //                label->setWindowOpacity(0.1);
    //                label->setPixmap(*image);

//    photo=new PhotoClass(this);
//    photo->move(40,0);
//    photo->resize(this->width()-100,this->height()-25);
//    photo->hide();
    d_spectrogram->setRenderThreadCount(0); // use system specific thread count
    draw_widget=new Spectro_draw(this);

    draw_widget->move(40,0);
    // draw_widget->resize(this->width(),this->height());
    draw_widget->resize(100,100);

    connect(draw_widget,SIGNAL(signal_form_canvas(QPointF)),this,SLOT(slot_for_spectr(QPointF)));
    connect(draw_widget,SIGNAL(signal_zoomer(QPointF,QPointF)),this,SLOT(slot_for_zoomer(QPointF,QPointF)));
   // connect(draw_widget,SIGNAL(signal_to_zoom_norm()),this,SLOT(slot_for_zoomer_norm()));
    connect(draw_widget,SIGNAL(signal_transform_x(double)),this,SLOT(trans_x(double)));
    connect(draw_widget,SIGNAL(signal_transform_y(double)),this,SLOT(trans_y(double)));
    connect(draw_widget,SIGNAL(signal_inv_transform_x(double)),this,SLOT(inv_trans_x(double)));
    connect(draw_widget,SIGNAL(signal_inv_transform_y(double)),this,SLOT(inv_trans_y(double)));

//    connect(photo,SIGNAL(photo_signal_transform_x(double)),this,SLOT(trans_x(double)));
//    connect(photo,SIGNAL(photo_signal_transform_y(double)),this,SLOT(trans_y(double)));
//    connect(photo,SIGNAL(photo_signal_inv_transform_x(double)),this,SLOT(inv_trans_x(double)));
//    connect(photo,SIGNAL(photo_signal_inv_transform_y(double)),this,SLOT(inv_trans_y(double)));

}

void Spectro_Plot::draw_spectr(Z2Vector z2vector,double intx1,double intx2,double inty1,double inty2,int colormax,double colormin)
{
    QVector<double>  *vct= new QVector<double>(z2vector.size());

    if (etype==Ampl)
    {
        for ( int i = 0; i < vct->size(); i++ )
        {

             (*vct)[i] = 10.0*log10(real(z2vector.at(i))*real(z2vector.at(i))+imag(z2vector.at(i))*imag(z2vector.at(i))+1e-20);
        }
    }
    if (etype==Phase)
    {
        for ( int i = 0; i < vct->size(); i++ )
        {
             (*vct)[i]=atan2(imag(z2vector.at(i)),real(z2vector.at(i)))*180.0/3.1415926;
        }
    }
    if (etype==Re)
    {
        for ( int i = 0; i < vct->size(); i++ )
        {
             (*vct)[i]=real(z2vector.at(i));
        }
    }
    if (etype==Im)
    {
        for ( int i = 0; i < vct->size(); i++ )
        {
            (*vct)[i]=z2vector.at(i).imag();
        }
    }
    if (raster!=NULL)
        delete raster;
    raster=new RasterData(vct,intx1,intx2,inty1,inty2,z2vector.nx,colormax,colormin);
    d_spectrogram->setData(raster);
    setAxisScale(QwtPlot::xBottom, intx1,intx2);
    setAxisScale(QwtPlot::yLeft, inty1,inty2);
    d_spectrogram->attach(this);

//    RasterData *data = (RasterData *)d_spectrogram->data();
//    data->setResampleMode( (QwtMatrixRasterData::ResampleMode) QwtMatrixRasterData::BilinearInterpolation);
    const QwtInterval zInterval = d_spectrogram->data()->interval( Qt::ZAxis );
    // A color bar on the right axis
    QwtScaleWidget *rightAxis = axisWidget(QwtPlot::yRight);
    rightAxis->setTitle("Intensity");
    rightAxis->setColorBarEnabled(true);

    if (is_transparent==false)
    {
        if (color_map==NULL)
        {
            color_map=new ColorMap();
            d_spectrogram->setColorMap(color_map);
            rightAxis->setColorMap( zInterval, color_map);
            if (alpha_color_map!=NULL)
            {
                delete alpha_color_map;
                alpha_color_map=NULL;
            }
        }
    }
    if (is_transparent==true)
    {
        if (alpha_color_map==NULL)
        {
            alpha_color_map =new ColorAlphamap();
            d_spectrogram->setColorMap(alpha_color_map);
            rightAxis->setColorMap( zInterval, alpha_color_map);
            if (color_map!=NULL)
            {
                delete color_map;
                color_map=NULL;
            }
        }
    }
    rightAxis->setColorBarWidth(25);
    setAxisScale(QwtPlot::yRight, zInterval.minValue(), zInterval.maxValue() );
    enableAxis(QwtPlot::yRight);
    replot();
    delete vct;

}
void Spectro_Plot::slot_for_spectr(QPointF pos)
{
}

void Spectro_Plot::slot_for_zoomer(QPointF p1,QPointF p2)
{
    if (zoomer!=NULL)
        zoomer->zoom(QRectF(QPointF(invTransform(QwtPlot::xBottom,p1.x()),invTransform(QwtPlot::yLeft,p1.y())),
                            QPointF(invTransform(QwtPlot::xBottom,p2.x()),invTransform(QwtPlot::yLeft,p2.y())) ));
}

double Spectro_Plot::trans_x(double x)
{
    return transform(QwtPlot::xBottom,x);
}
double Spectro_Plot::trans_y(double y)
{
    return transform(QwtPlot::yLeft,y);
}
double Spectro_Plot::inv_trans_x(double x)
{
    return invTransform(QwtPlot::xBottom,x);
}
double Spectro_Plot::inv_trans_y(double y)
{
    return invTransform(QwtPlot::yLeft,y);
}

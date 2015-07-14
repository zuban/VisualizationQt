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

//////////////////////////////////////////////////////////////////////////
class RasterData: public QwtMatrixRasterData
{
public:


    RasterData(QVector<double> *vector,double intx1,double intx2,double inty1,double inty2,int column,int colormax,double colormin)
    {
        //        QVector<double> values;
        //        for ( uint i = 0; i < vector.size()-1; i++ )
        //            values += vector.at(i);

        const int numColumns = column;
        setValueMatrix(*vector, numColumns);

        setInterval( Qt::XAxis,
                     QwtInterval( intx1, intx2, QwtInterval::IncludeBorders) );
        setInterval( Qt::YAxis,
                     QwtInterval( inty1, inty2, QwtInterval::IncludeBorders ) );
        setInterval( Qt::ZAxis, QwtInterval(colormin, colormax) );
    }

};

//////////////////////////////////////////////////////////////////
class ColorMap: public QwtLinearColorMap
{
public:
    ColorMap():
        QwtLinearColorMap(Qt::black, Qt::red)
    {
        //addColorStop(0.2, Qt::blue);
        addColorStop(0.2, Qt::blue);
        addColorStop(0.4, Qt::cyan);
        addColorStop(0.6, Qt::yellow);
        addColorStop(0.8, Qt::red);
    }
};
class ColorAlphamap: public QwtAlphaColorMap
{
public:
    ColorAlphamap():
        QwtAlphaColorMap(Qt::red)
    {

    }
};


///////////////////////////////////////////////////////////////////
Spectro_Plot::Spectro_Plot(QWidget *parent):
    QwtPlot(parent)
{
    etype=Ampl;
    is_transparent=false;
    grid=new QwtPlotGrid();
    grid->setMajPen(QPen(Qt::gray, 0, Qt::DotLine));
    grid->setMinPen(QPen(Qt::gray, 0 , Qt::DotLine));
    grid->attach(this);



    /////////////////////////////////////////////////////////////
    zoomer = new MyZoomer(canvas());
    zoomer->setMousePattern(QwtEventPattern::MouseSelect2,
                            Qt::RightButton, Qt::ControlModifier);
    zoomer->setMousePattern(QwtEventPattern::MouseSelect3,
                            Qt::RightButton);
    /////////////////////////////////////////////////////////////
    QwtPlotPanner *panner = new QwtPlotPanner(canvas());
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

    photo=new PhotoClass(this);
    photo->move(40,0);
    photo->resize(this->width()-100,this->height()-25);
    photo->hide();
    d_spectrogram->setRenderThreadCount(0); // use system specific thread count
    draw_widget=new Spectro_draw(this);

    draw_widget->move(40,0);
    // draw_widget->resize(this->width(),this->height());
    draw_widget->resize(100,100);

    connect(draw_widget,SIGNAL(signal_form_canvas(QPointF)),this,SLOT(slot_for_spectr(QPointF)));
    connect(draw_widget,SIGNAL(signal_zoomer(QPointF,QPointF)),this,SLOT(slot_for_zoomer(QPointF,QPointF)));
    connect(draw_widget,SIGNAL(signal_to_zoom_norm()),this,SLOT(slot_for_zoomer_norm()));
    connect(draw_widget,SIGNAL(signal_transform_x(double)),this,SLOT(trans_x(double)));
    connect(draw_widget,SIGNAL(signal_transform_y(double)),this,SLOT(trans_y(double)));
    connect(draw_widget,SIGNAL(signal_inv_transform_x(double)),this,SLOT(inv_trans_x(double)));
    connect(draw_widget,SIGNAL(signal_inv_transform_y(double)),this,SLOT(inv_trans_y(double)));

    connect(photo,SIGNAL(photo_signal_transform_x(double)),this,SLOT(trans_x(double)));
    connect(photo,SIGNAL(photo_signal_transform_y(double)),this,SLOT(trans_y(double)));
    connect(photo,SIGNAL(photo_signal_inv_transform_x(double)),this,SLOT(inv_trans_x(double)));
    connect(photo,SIGNAL(photo_signal_inv_transform_y(double)),this,SLOT(inv_trans_y(double)));




}

void Spectro_Plot::draw_spectr(Z2Vector z2vector,double intx1,double intx2,double inty1,double inty2,int colormax,double colormin)
{



    clock_t t3 = clock();
    if (is_transparent==false)
    {
        ColorMap *color_map=new ColorMap();
        d_spectrogram->setColorMap(color_map);
    }
    if (is_transparent==true)
    {
        ColorAlphamap *color_map =new ColorAlphamap();
        d_spectrogram->setColorMap(color_map);
    }

    QVector<double> vector;
    vector.resize(z2vector.size());
    if (etype==Ampl)
    {
        for ( uint i = 0; i < vector.size()-1; i++ )
        {
            vector[i]=10.0*log10(real(z2vector.at(i))*real(z2vector.at(i))+imag(z2vector.at(i))*imag(z2vector.at(i))+1e-20);
        }
    }
    if (etype==Phase)
    {
        for ( uint i = 0; i < vector.size()-1; i++ )
        {
            vector[i]=atan2(imag(z2vector.at(i)),real(z2vector.at(i)))*180.0/3.1415926;
        }
    }
    if (etype==Re)
    {
        for ( uint i = 0; i < vector.size()-1; i++ )
        {
            vector[i]=real(z2vector.at(i));
        }
    }
    if (etype==Im)
    {
        for ( uint i = 0; i < vector.size()-1; i++ )
        {
            vector[i]=z2vector.at(i).imag();
        }
    }
    RasterData *raster=new RasterData(&vector,intx1,intx2,inty1,inty2,z2vector.nx,colormax,colormin);
    clock_t t4 = clock();
    emit signal_from_vector("Calculus:"+QString::number((t4-t3))+" ");
    clock_t t1 = clock();
    d_spectrogram->setData(raster);
    setAxisScale(QwtPlot::xBottom, intx1,intx2);
    setAxisScale(QwtPlot::yLeft, inty1,inty2);
    d_spectrogram->attach(this);
    RasterData *data = (RasterData *)d_spectrogram->data();
    data->setResampleMode( (QwtMatrixRasterData::ResampleMode) QwtMatrixRasterData::BilinearInterpolation);
    const QwtInterval zInterval = d_spectrogram->data()->interval( Qt::ZAxis );
    // A color bar on the right axis
    QwtScaleWidget *rightAxis = axisWidget(QwtPlot::yRight);
    rightAxis->setTitle("Intensity");
    rightAxis->setColorBarEnabled(true);
    if (is_transparent==false)
    {
        ColorMap *color_map=new ColorMap();
        rightAxis->setColorMap( zInterval, color_map);
    }
    if (is_transparent==true)
    {
        ColorAlphamap *color_map =new ColorAlphamap();
        rightAxis->setColorMap( zInterval, color_map);
    }
    rightAxis->setColorBarWidth(25);
    setAxisScale(QwtPlot::yRight, zInterval.minValue(), zInterval.maxValue() );
    enableAxis(QwtPlot::yRight);
    replot();

    clock_t t2 = clock();
    emit signal_from_vector("Graphics:"+QString::number((t2-t1))+" ");
}
void Spectro_Plot::slot_for_spectr(QPointF pos)
{
    //double x=invTransform(QwtPlot::xBottom,pos.x());
    //double y=invTransform(QwtPlot::yLeft,pos.y());


}
void Spectro_Plot::slot_for_zoomer(QPointF p1,QPointF p2)
{
    //  zoomer->zoom(QRect(QPoint(invTransform(QwtPlot::xBottom,p1.x()),invTransform(QwtPlot::yLeft,p1.y())),
    //                   QPoint(invTransform(QwtPlot::xBottom,p2.x()),invTransform(QwtPlot::yLeft,p2.y())) ));
    zoomer->zoom(QRectF(QPointF(invTransform(QwtPlot::xBottom,p1.x()),invTransform(QwtPlot::yLeft,p1.y())),
                        QPointF(invTransform(QwtPlot::xBottom,p2.x()),invTransform(QwtPlot::yLeft,p2.y())) ));
}
void Spectro_Plot::slot_for_zoomer_norm()
{
    this->setAxisAutoScale(QwtPlot::xBottom,true);
    this->setAxisAutoScale(QwtPlot::yLeft,true);
    this->replot();
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
//void Spectro_Plot::resizeEvent ( QResizeEvent * event )
//{


//}


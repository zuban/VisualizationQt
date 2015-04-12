#include "myqwtplot.h"

MyQwtPlot::MyQwtPlot(QWidget *parent) :
    QwtPlot(parent)
{
        mymarker=new MyMarker(this);
         mymarker->move(70,20);
         mymarker->resize(241,83);


        mylegend=new QtLegend(this);
        mylegend->move(1000,20);
        mylegend->resize(154,43);


}

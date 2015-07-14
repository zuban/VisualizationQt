#ifndef MYQWTPLOT_H
#define MYQWTPLOT_H
#include "qwt_plot.h"
#include "qtlegend.h"
#include "mymarker.h"
class MyQwtPlot : public QwtPlot
{
    Q_OBJECT


public:


    explicit MyQwtPlot(QWidget *parent = 0);

   QtLegend *mylegend;
    MyMarker *mymarker;
    
signals:
    
public slots:
    
};

#endif // MYQWTPLOT_H

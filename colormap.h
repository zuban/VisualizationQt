#ifndef COLORMAP_H
#define COLORMAP_H

#include "qwt_color_map.h"

class ColorMap : public QwtLinearColorMap
{
public:
    ColorMap() : QwtLinearColorMap(Qt::black, Qt::red)
    {
        //addColorStop(0.2, Qt::blue);
        addColorStop(0.2, Qt::blue);
        addColorStop(0.4, Qt::cyan);
        addColorStop(0.6, Qt::yellow);
        addColorStop(0.8, Qt::red);
    }
};

#endif // COLORMAP_H

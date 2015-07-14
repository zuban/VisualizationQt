#ifndef RASTERDATA_H
#define RASTERDATA_H

#include "qwt_matrix_raster_data.h"
#include "QVector"

class RasterData : public QwtMatrixRasterData
{
public:
    RasterData(QVector<double> *vector,double intx1,double intx2,double inty1,double inty2,int column,int colormax,double colormin)
    {
        const int numColumns = column;
        setValueMatrix(*vector, numColumns);

        setInterval( Qt::XAxis,
                     QwtInterval( intx1, intx2, QwtInterval::IncludeBorders) );
        setInterval( Qt::YAxis,
                     QwtInterval( inty1, inty2, QwtInterval::IncludeBorders ) );
        setInterval( Qt::ZAxis, QwtInterval(colormin, colormax) );
    }
};

#endif // RASTERDATA_H

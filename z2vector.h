#ifndef Z2VECTOR_H
#define Z2VECTOR_H

#include <complex>
#include "QVector"
#include "zcomplex.h"

class Z2Vector : public QVector<double_complex>
{

public:
    Z2Vector();
    void set_zero_vector(int nX,int nY,double startX,double stopX,double startY,double stopY);
    double startx,starty,stopx,stopy;
    int nx,ny;
    double scale;

};

#endif // Z2VECTOR_H

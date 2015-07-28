#include "z2vector.h"
#include "QStringList"
#include "QFile"
#include "QTextStream"

Z2Vector::Z2Vector() : QVector<double_complex>()
{
}
void Z2Vector::set_zero_vector(int nX,int nY,double startX,double stopX,double startY,double stopY)
{
    this->resize(nX*nY);
    startx=startX;
    starty=startY;
    stopx=stopX;
    stopy=stopY;
    nx=nX;
    ny=nY;
    for (int i=0;i<nx*ny-1;i++)
    {
        (*this)[i].x =0.0;
    (*this)[i].y =0.0;
    }
}

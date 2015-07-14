#include "z2vector.h"
#include "QStringList"
#include "QFile"
#include "QTextStream"

Z2Vector::Z2Vector() : QVector<Complex>()
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
        (*this)[i]=0;
}
//void Z2Vector::set_value(int a, int b,Complex c)
//{
//    int ind=a+b*nx;
//    if (ind<0 || ind>=this->size())
//        return;
//    (*this)[ind]=c;
//}
//void Z2Vector::test_debug()
//{
//    int n=10000;
//    int k=1000;
//    set_zero_vector(n,k,-5,5,-5,5);
//    for (int i=0;i<k*n-1;i++)
//    {
//        Complex complex;
//        complex.imag()=i+3;
//        complex.real()=sin(i)/cos(i);
//        (*this)[i]=complex;

//    }
//}
//void Z2Vector::ReadAscii(QString line) //in: way; out: flag only????
//{

//}



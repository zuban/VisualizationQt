#ifndef Z2VECTOR_H
#define Z2VECTOR_H

#include <complex>
#include "QVector"
#include "zcomplex.h"

//using namespace std;
//typedef complex<double> double_complex;

class Z2Vector : public QVector<double_complex>
{

public:
    Z2Vector();
//    void test_debug();
    void set_zero_vector(int nX,int nY,double startX,double stopX,double startY,double stopY);
//    void ReadAscii(QString line);
    double startx,starty,stopx,stopy;
    int nx,ny;
    double scale;
    // void set_value(int a,int b,Complex c);
    //void get_value(int a,int b);
};

#endif // Z2VECTOR_H

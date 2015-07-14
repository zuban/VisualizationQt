#ifndef Z2VECTOR_H
#define Z2VECTOR_H

#include <complex>
#include "QVector"


using namespace std;
typedef complex<double> Complex;

class Z2Vector : public QVector<Complex>
{

public:
    Z2Vector();
//    void test_debug();
    void set_zero_vector(int nX,int nY,double startX,double stopX,double startY,double stopY);
//    void ReadAscii(QString line);
    double startx,starty,stopx,stopy;
    int nx,ny;
    // void set_value(int a,int b,Complex c);
    //void get_value(int a,int b);
};

#endif // Z2VECTOR_H

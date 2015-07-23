#ifndef ZVECTOR_H
#define ZVECTOR_H

#include <QObject>
#include <QVector>
#include <complex>
#include <QDialog>
//using namespace std;
//typedef complex<double> double_complex;
#include "zcomplex.h"

class ZVector : public QVector<double_complex>
{

public:

    double start;//Начальное значение комплексных чисел
    double stop; //Конечное значение комплекс
    int zLenght;  //Длина
    double getMaxValue();//Максимальное значение массива
    double getMinValue();

    void ReadAscii(QString line); //заполняет массив комплексных чисел.
    ZVector();

private:

    
signals:

    void signal_from_vector(double a);
    
public slots:
    
};

#endif // ZVECTOR_H

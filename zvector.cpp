#include "zvector.h"
#include "QVector"
#include "widget.h"
#include "QFile"
#include "QString"
#include "QTextStream"
#include "QStringList"
#include "math.h"
#include "QMessageBox"


ZVector::ZVector() : QVector<Complex>()
{
//   is_test=false;
//   is_rows=true;

}
void ZVector::ReadAscii(QString line) //in: way; out: flag only????
{

    QFile file(line);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
    }
    int k=0;
    double pi=3.1415926;
    Complex Ci=Complex(0.0,1.0);
    QTextStream in(&file);
    QStringList StringList;
    int j=0;
    while (!in.atEnd())
    {

       QString line1=in.readLine();
       QStringList list2 = line1.split(",", QString::SkipEmptyParts);

       StringList <<  list2[0];
       StringList <<  list2[1];
       StringList <<  list2[2];
       k++;
    }
    resize(k);
    zLenght=k;
    j++;
    int q=0;
    for (int j=0;j<k;j++)
    {
        QString str1 = StringList.at(q);
        q++;
        QString str2 = StringList.at(q);
        q++;
        QString str3 = StringList.at(q);
        q++;
        double F= str1.toDouble();
        double A=str2.toDouble();
        double Fi=str3.toDouble();
        (*this)[j]=pow(10.0,A/20.0)*exp(Ci*Fi*pi/180.0);
        if (j==0)
        {
            start=F;
        }
        if (j==(k-1))
        {
            stop=F;
        }
    }
    file.close();


}

double ZVector::getMaxValue() //out: max value of Vector;uses zLenght
{
    double max=-1000000000;
    for (int i=0;i<zLenght;i++)
    {
        double d=abs((*this)[i]);
        if (d>max)
            max=d;
    }
    return max;
}
double ZVector::getMinValue() //out: min value of Vector;uses zLenght
{
    double min=1.0e200;
    for (int i=0;i<zLenght;i++)
    {
        double d=abs((*this)[i]);
        if (d<min)
            min=d;
    }
    return min;
}


#ifndef IODATA_H
#define IODATA_H

#include <QObject>
#include <w_wlib.h>
struct double_complex {double x; double y;};
struct float_complex {float x; float y;};
class IOData : public QObject
{

    Q_OBJECT
public:

    explicit IOData(QObject *parent = 0);
    void d_readFile(QString path,int &N_k,int &N_fi,double &Fstart,double &Fstop,double &AzStart, double &AzStop,double_complex *array);
    void d_writeFile(QString path,int N_k,int N_fi,double Fstart,double Fstop,double AzStart, double AzStop,double_complex *array);
    void d_readmasSize(QString path,int &N_k,int &N_fi);
signals:
    
public slots:
    
};

#endif // IODATA_H

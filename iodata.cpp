#include "iodata.h"

IOData::IOData(QObject *parent) :
    QObject(parent)
{
}
void IOData::d_readFile(QString path,int &N_k,int &N_fi,double &Fstart,double &Fstop,double &AzStart, double &AzStop,double_complex *array)
{
    char *cpath = path.toAscii().data();
    bifstream *istream = new bifstream(cpath);
    *istream >> N_k >> N_fi >> Fstart >> Fstop >> AzStart >> AzStop ;
    for (int j=0; j<=N_fi-1;j++)
    {
        for (int i=0;i<=N_k-1;i++)
        {
            int ind = N_k*j+i;
            double a, b;
            *istream >> a;
            *istream >> b;
            array[ind].x = a;
            array[ind].y = b;
        }
    }
    printf ("read success \n");
    istream->close();
    delete istream;
}
void IOData::d_writeFile(QString path,int N_k,int N_fi,double Fstart,double Fstop,double AzStart, double AzStop,double_complex *array)
{
    char *cpath = path.toAscii().data();
    bofstream *ostream = new bofstream(cpath);

    *ostream << N_k << N_fi << Fstart<< Fstop << AzStart << AzStop ;
    for (int j=0; j<=N_fi-1;j++)
    {
        for (int i=0;i<=N_k-1;i++)
        {
            int ind = N_k*j+i;
            double a=array[2*ind + 1].x;
            double b=array[2*ind + 1].y;
            *ostream << a;
            *ostream << b;
        }
    }
    printf ("write success \n");
    ostream->close();
    delete ostream;
}
void IOData::d_readmasSize(QString path,int &N_k,int &N_fi)
{
    char *cpath = path.toAscii().data();
    bifstream *istream = new bifstream(cpath);
    *istream >> N_k >> N_fi;
    printf ("read success %d %d \n",N_k,N_fi );
    istream->close();
    delete istream;
}

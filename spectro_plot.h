#ifndef SPECTRO_PLOT_H
#define SPECTRO_PLOT_H

#include "qwt_plot.h"
#include "qwt_plot_spectrogram.h"
#include "z2vector.h"
#include "qwt_plot_grid.h"
#include "qwt_plot.h"
#include "spectro_draw.h"
#include "photoclass.h"

class MyZoomer;
class Spectro_Plot : public QwtPlot
{
    Q_OBJECT
public:
    enum EType {Ampl,Phase,Re,Im};
    bool is_transparent;
    EType etype;
    Spectro_Plot(QWidget * = NULL);
    void draw_spectr(Z2Vector z2vector,double intx1,double intx2,double inty1,double inty2,int colormax,double colormin);
    QwtPlotGrid *grid;
    QwtPlot *plot;
    Spectro_draw *draw_widget;
    MyZoomer* zoomer;
    PhotoClass *photo;






signals:
    void signal_from_vector(QString a);

private:
    QwtPlotSpectrogram *d_spectrogram;
public slots:
  //  void resizeEvent ( QResizeEvent * event );
    void slot_for_spectr(QPointF pos);
    void slot_for_zoomer(QPointF p1,QPointF p2);
    void slot_for_zoomer_norm();
    double trans_x(double x);
    double trans_y(double y);
    double inv_trans_x(double x);
    double inv_trans_y(double y);




};

#endif // SPECTRO_PLOT_H





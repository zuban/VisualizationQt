#ifndef ZGRAPH_H
#define ZGRAPH_H

#include <QWidget>
#include "myqwtplot.h"
#include "zvector.h"
#include "qwt_plot_curve.h"
#include "qwt_plot_marker.h"
#include "qwt_symbol.h"
#include "qwt_plot_picker.h"
#include "qwt_plot_zoomer.h"
#include "qwt_plot_magnifier.h"
#include "scrollzoomer.h"
#include "qwt_plot_panner.h"
#include "iodata.h"


class ZGraph : public QWidget
{
    Q_OBJECT
public:
    explicit ZGraph(QWidget *parent = 0);

    IOData *cdata;
    double_complex *cuda_mas;

    const static int N_GRAPHS_MAX = 4;
    int graphs_count;
    int markers_count;
    int d_selectedPoint;
    double curve_width[N_GRAPHS_MAX];
    ZVector *zVector[N_GRAPHS_MAX];
    QwtPlotCurve *curve[N_GRAPHS_MAX];
    MyQwtPlot *myPlot;
    QwtPlotMarker *line_marker[N_GRAPHS_MAX];
    QwtPlotMarker *basic_marker[N_GRAPHS_MAX];
    QwtSymbol *line_symbol;
    QwtSymbol *basic_symbol[N_GRAPHS_MAX];
    QwtPlotMarker *reference_marker;
    QwtPlotMagnifier *magnifier;
    ScrollZoomer *scrollzoomer;
    QwtPlotPanner *panner;
    QList <QwtPlotCurve*>  ref_curve_list;
    QList <QwtPlotMarker*> marker_list;
    QList <QwtPlotCurve*>  curve_list;
    QwtPlotZoomer *zoomer;
    QwtPlotCurve *d_selectedCurve;
    QwtPlotPicker *d_picker;

    int N_k;
    int N_fi;
    double F_start,F_stop, AzStart,AzStop;

    enum ERun{first,nonfirst};
    ERun eRun;
    enum EType {Ampl,Phase,Real,Imag,NonType};
    EType eType;
    enum EAmplScale {AmplAutoscale,AmplUp,AmplManual,AmplNonScale};
    EAmplScale eAmplScale;
    enum EAmplType {AmplLog,AmplLin,NonAmplType};
    EAmplType eAmplType;
    enum EPhaseScale {PhaseAutoscale,PhaseUp,PhaseManual,PhaseNonScale};
    EPhaseScale ePhaseScale;
    enum EReImScale {ReAutoscale,ReUp,ReManual,ReNonScale};
    EReImScale eReImScale;
    enum EGraph {graph1,graph2,graph3,graph4,graph5,graph6,nograph};
    enum ECurveType {SolidLine,DashLine,DotLine,DashDotLine,DashDotDotLine,CustomDashLine};
    ECurveType eCurveType[N_GRAPHS_MAX];
    enum EColor {white,red,green,blue,cyan,magenta,yellow,gray,black,darkRed,darkGreen,darkBlue,darkCyan,darkMagenta,darkYellow,darkGray,lightGray};
    EColor eColor[N_GRAPHS_MAX];
    enum ESpecial_marker {active,nonactive};
    ESpecial_marker eSpecialMarker;



    void Cuda_draw_default_graph(int num, int type);
    void add_new_graph(QString way); //deprecated version 1.0
    void reDraw();
    void reDrawScale(double Max,double Span);
    double get_max_compare();
    double get_min_compare();
    void redefine_type(QString type);
    void draw_default_graph(QString way);
    void draw_test();
    void show_special_marker(double x);
    bool  eventFilter(QObject *target, QEvent *event);
    double getPointX(QwtPlotCurve *curveid, int Point);
    double getPointY(QwtPlotCurve *curveid, int Point);
    int z_getNumber(double x);
    void change_graph_color(QColor color);
    void change_graph_style(Qt::PenStyle style);
    void change_graph_width(double x);
    void add_marker();
    void delete_marker();
    void resizeMyPlot(int x,int y);
    QColor getRGB(EColor color);
    Qt::PenStyle getPen(ECurveType type);
    void append_marker1();
    void delete_marker1();
    void display_numbers();
    void enable_xy_zoomer();
    void delete_xy_zoomer();
    void enable_x_zoomer();
    void delete_x_zoomer();
    void enable_y_zoomer();
    void delete_y_zoomer();
    void enable_magnifier();
    void delete_magnifier();
    void select(const QPoint &pos);
    void showCursor(bool showIt);
    void reference_marker_toggled(bool checked);
    void change_markers();
    void Cuda_redraw_graph(int num,int type);
    QwtPlotMarker *gate_marker1;
    QwtPlotMarker *gate_marker2;
    bool gate_enable;
    double gate_pos1;
    double gate_pos2;
signals:
    void signal_from_zGraph(double text);
    void replot_2d();
    void change_value_freq(double val);
    void change_value_angle(double val);

public slots:
    void signal_on_copy_pushButton_clicked();
    void signal_on_clear_pushButton_clicked();
    void set_gate_marker(double l_angl, double r_angl);
    void enable_gate_marker(bool en);
    void get_data_2D(QString str);
public Q_SLOTS:
    void click_on_canvas(const QPoint &pos);
    
};

#endif // ZGRAPH_H

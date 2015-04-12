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
struct double2 {double x; double y;};

class ZGraph : public QWidget
{
    Q_OBJECT
public:
    explicit ZGraph(QWidget *parent = 0);
    const static int N_GRAPHS_MAX = 10;


    bool is_rows;
    int col_or_row_number;
    void replot_test(int num);
    double2 *mas;
    int nCol;
    int nRow;
    void Cuda_draw_default_graph(QString way);



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
    double curve_width[N_GRAPHS_MAX];

    enum ESpecial_marker {active,nonactive};
    ESpecial_marker eSpecialMarker;

    void add_new_graph(QString way);
    void reDraw();
    void reDrawScale(double Max,double Span);
    double get_max_compare();
    double get_min_compare();
    void redefine_type(QString type);
    QColor getRGB(EColor color);
    Qt::PenStyle getPen(ECurveType type);
    int graphs_count;

    QwtPlotCurve *curve[N_GRAPHS_MAX];
    ZVector *zVector[N_GRAPHS_MAX];
    void draw_default_graph(QString way);
    MyQwtPlot *myPlot;
    void draw_test();
    void show_special_marker(double x);
    bool  eventFilter(QObject *target, QEvent *event);
    double getPointX(QwtPlotCurve *curveid, int Point);
    double getPointY(QwtPlotCurve *curveid, int Point);
    int z_getNumber(double x);
    QwtPlotMarker *line_marker[N_GRAPHS_MAX];
    QwtPlotMarker *basic_marker[N_GRAPHS_MAX];
    QwtSymbol *line_symbol;
    QwtSymbol *basic_symbol[N_GRAPHS_MAX];
    void change_graph_color(QColor color);
    void change_graph_style(Qt::PenStyle style);
    void change_graph_width(double x);
    void add_marker();
    void delete_marker();
    void resizeMyPlot(int x,int y);
    QwtPlotMarker *reference_marker;



    void  change_gate_marker(QPoint pos);
    int gate_pos_1;
    int gate_pos_2;
    QwtPlotMarker *gate_marker1;
    QwtPlotMarker *gate_marker2;




    //test
     QwtPlotMagnifier *magnifier;
     ScrollZoomer *scrollzoomer;
     QwtPlotPanner *panner;
     QList <QwtPlotCurve*>  ref_curve_list;
     QList <QwtPlotMarker*> marker_list;
     QList <QwtPlotCurve*>  curve_list;
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
     QwtPlotZoomer *zoomer;

    void select(const QPoint &pos);
    int markers_count;
    int d_selectedPoint;
    QwtPlotCurve *d_selectedCurve;
    void showCursor(bool showIt);
    QwtPlotPicker *d_picker;
    void reference_marker_toggled(bool checked);
    void change_markers();


    
signals:
     void signal_from_zGraph(double text);

    
public Q_SLOTS:
     void click_on_canvas(const QPoint &pos);
    
};

#endif // ZGRAPH_H

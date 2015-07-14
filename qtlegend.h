#ifndef QTLEGEND_H
#define QTLEGEND_H

#include <QWidget>

class QtLegend : public QWidget
{
    Q_OBJECT
public:
    explicit QtLegend(QWidget *parent);

    const static int nGraphsMax=10;
    void change_color(int curve,QColor color_curve);
    void change_type(int curve,Qt::PenStyle style);
    void delete_legend();//set to the default items
    void add_graph();
    void change_title(int curve,QString curve_title);
    int graphs_legend_count;
    int active_graph;
    QPointF *point[nGraphsMax];

private:
    bool eventFilter(QObject *object, QEvent *event);
    void draw( QPainter  *painter);
    enum ECurveType {SolidLine,DashLine,DotLine,DashDotLine,DashDotDotLine,CustomDashLine};
    enum EColor {white,red,green,blue,cyan,magenta,yellow,gray,black,darkRed,darkGreen,darkBlue,darkCyan,darkMagenta,darkYellow,darkGray,lightGray};

    EColor color[nGraphsMax];
    QString title[nGraphsMax];
    ECurveType type[nGraphsMax];
    Qt::PenStyle getPen(ECurveType type);
    QColor getRGB(EColor color);
protected:
    void paintEvent(QPaintEvent *event);
signals:
    void signal_from_legend(double pos);
    
public slots:
    
};

#endif // QTLEGEND_H

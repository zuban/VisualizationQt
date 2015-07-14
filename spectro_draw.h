#ifndef SPECTRO_DRAW_H
#define SPECTRO_DRAW_H

#include <QWidget>
#include "QList"


class Spectro_draw : public QWidget
{
    Q_OBJECT
public:

    enum EColor {white,red,green,blue,cyan,magenta,yellow,gray,black,darkRed,darkGreen,darkBlue,darkCyan,darkMagenta,darkYellow,darkGray,lightGray};
    EColor eColor;
    QColor getRGB(EColor color);
    enum EType {Polygon,Rect,Circle,Line};
    EType eType;
    bool is_new_item;
    bool is_select_mode_enable;//for select item
    bool is_sketch_mode_enable;
    bool is_zoom_mode_enable;
    bool is_scale_mode_enable;
    bool is_scale_mode_enable_new_item;


    bool is_scale_mode_scale1;
    bool is_scale_mode_scale2;
    QList<QPointF> scale_mode_scale_list1;
    QList<QPointF> scale_mode_scale_list2;
    bool is_scale_mode_angle1;
    bool is_scale_mode_angle2;
    QList<QPointF> scale_mode_angle_list1;
    QList<QPointF> scale_mode_angle_list2;
    bool is_scale_mode_point1;
    bool is_scale_mode_point2;
    QList<QPointF> scale_mode_point_list1;
    QList<QPointF> scale_mode_point_list2;
    //   QPointF scale_point1;//for size mode
    //   QPointF scale_point2;


    int left_select;
    int right_select;
    double angle_rotate,x_shift,y_shift,fi,x_scale,y_scale,points_count,_k;
    double calculate_const_x(double x,double y);
    double calculate_const_y(double x, double y);
    void replot_sketch(double x_sh,double y_sh,double x_sc,double y_sc, double fi0, double fi_shift, double k);
    void flip();



    bool is_new_point;
    QPointF point1;
    QPointF point2;


    struct Point  {
    public:
        QPointF point;
        QColor color;
        bool updown;
        EType type;
        Point(QPointF _point,QColor _color,bool _updown,EType _type,int _aux=0)
        {
            point=_point;
            color=_color;
            updown=_updown;//true is for new
            type=_type;
        }

    };

    explicit Spectro_draw(QWidget *parent = 0);
    void draw( QPainter  *painter);
    void get_selected_area(int num);
    QList<Point> list;

    QList<Point> sketch_list;

    int find_point(int number);
    void change_color(QColor color);
    void delete_last();
    int find_closest_point(QPointF point);
    int get_equal_point(int num);
    void read_from_file();


private:
    bool eventFilter(QObject *object, QEvent *event);
protected:
    void paintEvent(QPaintEvent *event);
signals:
    void signal_form_canvas(QPointF pos);
    void signal_change_text(QString str);
    void signal_zoomer(QPointF p1,QPointF p2);


    double signal_transform_x(double a);
    double signal_transform_y(double a);
    double signal_inv_transform_x(double a);
    double signal_inv_transform_y(double a);
    void signla_x_shift(double a);
    void signla_y_shift(double a);
    void signla_x_scale(double a);
    void signla_y_scale(double a);
    void signla_fi(double a);
    void signla_k(double a);
    void signla_fi_shift(double a);

    void signal_test(QString str);


    void signal_to_change_scale_scale1(double a);
    void signal_to_change_scale_scale2(double a);
    void signal_to_change_scale_angle1(double a,double b);
    void signal_to_change_scale_angle2(double a,double b);
    void signal_to_change_scale_point1(QPointF point);
    void signal_to_change_scale_point22(QPointF point);

    void signal_to_change_scale(double a);

    void signal_to_zoom_norm();
public slots:

};

#endif // SPECTRO_DRAW_H

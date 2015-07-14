#ifndef PHOTOCLASS_H
#define PHOTOCLASS_H

#include <QWidget>
#include "QLabel"

class PhotoClass : public QWidget
{
    Q_OBJECT
public:
    explicit PhotoClass(QWidget *parent = 0);
    QLabel *label;
    QPixmap *image;
    //  QImage *MyImage;
    void resize_photo(double x,double y);
    double res_x;
    double res_y;
    void move_photo(QPointF point);
    void set_opacity(double a);
    void rotate(double x);
    void draw( QPainter  *painter);



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
    void replot_sketch(double x_sh,double y_sh,double x_sc,double y_sc, double fi0, double fi_shift, double k);



private:
    bool eventFilter(QObject *object, QEvent *event);
protected:
    void paintEvent(QPaintEvent *event);
signals:
    double photo_signal_transform_x(double a);
    double photo_signal_transform_y(double a);
    double photo_signal_inv_transform_x(double a);
    double photo_signal_inv_transform_y(double a);


    void photo_signla_x_shift(double a);
    void photo_signla_y_shift(double a);
    void photo_signla_x_scale(double a);
    void photo_signla_y_scale(double a);
    void photo_signla_fi(double a);
    void photo_signla_k(double a);
    void photo_signla_fi_shift(double a);

    void photo_signal_to_change_scale_scale1(double a);
    void photo_signal_to_change_scale_scale2(double a);
    void photo_signal_to_change_scale_angle1(double a,double b);
    void photo_signal_to_change_scale_angle2(double a,double b);
    void photo_signal_to_change_scale_point1(QPointF point);
    void photo_signal_to_change_scale_point22(QPointF point);
    
public slots:
    
};

#endif // PHOTOCLASS_H

#include "photoclass.h"
#include "QLabel"
#include "QPainter"
#include "QEvent"
#include "QMouseEvent"
#include "math.h"

PhotoClass::PhotoClass(QWidget *parent) :
    QWidget(parent)
{
    is_scale_mode_scale1=false;
    is_scale_mode_angle1=false;
    is_scale_mode_point1=false;
    is_scale_mode_scale2=false;
    is_scale_mode_angle2=false;
    is_scale_mode_point2=false;
    this->installEventFilter(this);
    label=new QLabel(this);
    image = new QPixmap("433px-BCDto7SegDecoder.png");
    label->setWindowOpacity(qreal(40)/100);
    label->move(0,0);
    label->resize(1600,975);
    label->setWindowOpacity(1);
    label->setPixmap(image->scaled(1600,1600,Qt::KeepAspectRatio));
}
void PhotoClass::resize_photo(double x, double y)
{
    label->setPixmap(image->scaled(x,y,Qt::KeepAspectRatio));
}
void PhotoClass::set_opacity(double a)
{
    label->setWindowOpacity(a);
}
void PhotoClass::move_photo(QPointF point)
{
    label->move(point.toPoint());
}
void PhotoClass::rotate(double x)
{
    QTransform myTransform;
    myTransform.rotate(x);
    myTransform.translate(-5, -5); // Now I want to read the rectangular area only, so I try to translate the upperleft point.
    QPixmap MyImage = image->transformed(myTransform);
    label->setPixmap(MyImage.scaled(1600,1600,Qt::KeepAspectRatio));
}
void  PhotoClass::paintEvent(QPaintEvent *  )
{
    QPainter  painter(this);
    draw(&painter);
}
void  PhotoClass::draw( QPainter  *painter)
{

}
bool PhotoClass::eventFilter(QObject *object, QEvent *event)
{
    if (is_scale_mode_scale1==true)
    {
        if (event->type() == QEvent::MouseButtonPress )
        {
            scale_mode_scale_list1.append(QPointF(((QMouseEvent*)event)->posF()));
            this->repaint();
            if (scale_mode_scale_list1.size()==2)
            {
                double x1=photo_signal_inv_transform_x(scale_mode_scale_list1.at(0).x());
                double x2=photo_signal_inv_transform_x(scale_mode_scale_list1.at(1).x());
                double y1=photo_signal_inv_transform_y(scale_mode_scale_list1.at(0).y());
                double y2=photo_signal_inv_transform_y(scale_mode_scale_list1.at(1).y());
                double a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
                emit photo_signal_to_change_scale_scale1(a);
                scale_mode_scale_list1.clear();
            }
        }
    }
    if (is_scale_mode_scale2==true)
    {
        if (event->type() == QEvent::MouseButtonPress )
        {
            scale_mode_scale_list2.append(QPointF(((QMouseEvent*)event)->posF()));
            this->repaint();
            if (scale_mode_scale_list2.size()==2)
            {
                double x1=photo_signal_inv_transform_x(scale_mode_scale_list2.at(0).x());
                double x2=photo_signal_inv_transform_x(scale_mode_scale_list2.at(1).x());
                double y1=photo_signal_inv_transform_y(scale_mode_scale_list2.at(0).y());
                double y2=photo_signal_inv_transform_y(scale_mode_scale_list2.at(1).y());
                double a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
                emit photo_signal_to_change_scale_scale2(a);
                scale_mode_scale_list2.clear();
            }
        }
    }
    if (is_scale_mode_angle1==true)
    {
        if (event->type() == QEvent::MouseButtonPress )
        {
            scale_mode_angle_list1.append(QPointF(((QMouseEvent*)event)->posF()));
            this->repaint();
            if (scale_mode_angle_list1.size()==2)
            {
                double x1=photo_signal_inv_transform_x(scale_mode_angle_list1.at(0).x());
                double x2=photo_signal_inv_transform_x(scale_mode_angle_list1.at(1).x());
                double y1=photo_signal_inv_transform_y(scale_mode_angle_list1.at(0).y());
                double y2=photo_signal_inv_transform_y(scale_mode_angle_list1.at(1).y());
                double a=x2-x1;
                double b=y2-y1;
                emit photo_signal_to_change_scale_angle1(a,b);
                scale_mode_angle_list1.clear();
            }
        }
    }
    if (is_scale_mode_angle2==true)
    {
        if (event->type() == QEvent::MouseButtonPress )
        {
            scale_mode_angle_list2.append(QPointF(((QMouseEvent*)event)->posF()));
            this->repaint();
            if (scale_mode_angle_list2.size()==2)
            {
                double x1=photo_signal_inv_transform_x(scale_mode_angle_list2.at(0).x());
                double x2=photo_signal_inv_transform_x(scale_mode_angle_list2.at(1).x());
                double y1=photo_signal_inv_transform_y(scale_mode_angle_list2.at(0).y());
                double y2=photo_signal_inv_transform_y(scale_mode_angle_list2.at(1).y());
                double a=x2-x1;
                double b=y2-y1;
                emit photo_signal_to_change_scale_angle2(a,b);
                scale_mode_angle_list2.clear();
            }
        }
    }
    if (is_scale_mode_point1==true)
    {
        if (event->type() == QEvent::MouseButtonPress )
        {
            scale_mode_point_list1.append(QPointF(((QMouseEvent*)event)->posF()));
            this->repaint();
            if (scale_mode_point_list1.size()==1)
            {
                emit photo_signal_to_change_scale_point1(QPointF(photo_signal_inv_transform_x(scale_mode_point_list1.at(0).x()),photo_signal_inv_transform_y(scale_mode_point_list1.at(0).y())));
                scale_mode_point_list1.clear();
            }
        }
    }
    if (is_scale_mode_point2==true)
    {
        if (event->type() == QEvent::MouseButtonPress )
        {
            scale_mode_point_list2.append(QPointF(((QMouseEvent*)event)->posF()));
            this->repaint();
            if (scale_mode_point_list2.size()==1)
            {
                emit photo_signal_to_change_scale_point22(QPointF(photo_signal_inv_transform_x(scale_mode_point_list2.at(0).x()),photo_signal_inv_transform_y(scale_mode_point_list2.at(0).y())));
                scale_mode_point_list2.clear();
            }
        }
    }
    return false;
}

void PhotoClass::replot_sketch(double x_sh,double y_sh,double x_sc,double y_sc,double fi0,double fi_shift,double k)
{
    resize_photo(x_sc,y_sc);
    move_photo(QPointF(x_sh,y_sh));
    rotate(fi_shift);
    this->repaint();
}

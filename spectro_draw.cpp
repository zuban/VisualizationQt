#include "spectro_draw.h"
#include "QPainter"
#include "QEvent"
#include "QMouseEvent"
#include "math.h"
#include "QFileDialog"
#include "QTextStream"
#include <QDebug>

Spectro_draw::Spectro_draw(QWidget *parent) :
    QWidget(parent)
{
    fi = 0.0;
    eType=Polygon;
    eColor=cyan;
    is_new_item=true;
    this->installEventFilter(this);
    is_select_mode_enable=false;
    left_select=0;
    right_select=0;
    is_zoom_mode_enable=false;
    is_new_point=true;
    is_sketch_mode_enable=false;
    is_scale_mode_enable=false;
    is_scale_mode_enable_new_item=true;
    is_scale_mode_scale1=false;
    is_scale_mode_angle1=false;
    is_scale_mode_point1=false;
    is_scale_mode_scale2=false;
    is_scale_mode_angle2=false;
    is_scale_mode_point2=false;
    qDebug() << "TEST";
    qDebug() << signal_inv_transform_x(0.0);
    qDebug() << signal_inv_transform_y(0.0);
    qDebug() << signal_transform_x(0.0);
    qDebug() << signal_transform_x(0.0);
    qDebug() << "TEST";

}
double Spectro_draw::calculate_const_x(double x,double y)
{
    if (x_scale==0) return -1;
    if (y_scale==0) return -1;
    return ((x_shift+x/x_scale)*cos(fi)+(y_shift+y/y_scale)*sin(fi));//+this->width()/2);
}
double Spectro_draw::calculate_const_y(double x,double y)
{
    if (x_scale==0) return -1;
    if (y_scale==0) return -1;
    return ((y_shift+y/y_scale)*cos(fi)-(x_shift+x/x_scale)*sin(fi));
}

void Spectro_draw::paintEvent(QPaintEvent *  )
{
    try {
        QPainter  painter;
            painter.begin(this);
            draw(&painter);
    } catch (const std::bad_alloc &) {
        printf("error in painter usage");
    }

}
void Spectro_draw::draw( QPainter  *painter)
{
    painter->setOpacity(0.6);
    painter->setRenderHint(QPainter::Antialiasing,true);

    if (man_list.size()!=0)
    {
        for (int i=0;i<man_list.size()-1;i++)
        {
            QBrush *brush=new QBrush( ((Point)(man_list.at(i))).color );
            painter->setBrush(*brush);
            //if (brush!=null)
            QPen *setpen = new QPen(*brush,2);
            painter->setPen(*setpen);
            if (man_list.size()>1)
            {

                if (((Point)(man_list.at(i))).updown==false)
                {
                    if (((Point)(man_list.at(i+1))).updown==false)
                    {
                        painter->drawLine(QPointF(signal_transform_x(((Point)(man_list.at(i))).point.x()),signal_transform_y(((Point)(man_list.at(i))).point.y())),
                                          QPointF(signal_transform_x(((Point)(man_list.at(i+1))).point.x()),signal_transform_y(((Point)(man_list.at(i+1))).point.y())));
                        // qDebug() << QPointF(signal_transform_x(((Point)(man_list.at(i))).point.x()),signal_transform_y(((Point)(man_list.at(i))).point.y()));
                    }
                }
                else
                {
                    painter->drawLine(QPointF(signal_transform_x(((Point)(man_list.at(i))).point.x()),signal_transform_y(((Point)(man_list.at(i))).point.y())),
                                      QPointF(signal_transform_x(((Point)(man_list.at(i+1))).point.x()),signal_transform_y(((Point)(man_list.at(i+1))).point.y())));
                }
            }
            delete brush;
            delete setpen;
        }
    }
    if (sketch_list.size()>0)
    {
        for (int i=0;i<sketch_list.size()-2;i++)
        {
            QBrush *brush=new QBrush( ((Point)(sketch_list.at(i))).color );
            painter->setBrush(*brush);
            QPen *setpen = new QPen(*brush,2);
            painter->setPen(*setpen);
            if (sketch_list.size()>1)
            {
                if (((Point)(sketch_list.at(i))).updown==false)
                {
                    if (((Point)(sketch_list.at(i+1))).updown==false)
                    {

                        painter->drawLine(QPointF(signal_transform_x(((Point)(sketch_list.at(i))).point.x()),signal_transform_y(((Point)(sketch_list.at(i))).point.y())),
                                          QPointF(signal_transform_x(((Point)(sketch_list.at(i+1))).point.x()),signal_transform_y(((Point)(sketch_list.at(i+1))).point.y())));
                    }
                    //                    if(i>0)
                    //                    {
                    //                    }
                }
                else
                {
                    painter->drawLine(QPointF(signal_transform_x(((Point)(sketch_list.at(i))).point.x()),signal_transform_y(((Point)(sketch_list.at(i))).point.y())),
                                      QPointF(signal_transform_x(((Point)(sketch_list.at(i+1))).point.x()),signal_transform_y(((Point)(sketch_list.at(i+1))).point.y())));
                }
            }
            delete brush;
            delete setpen;
        }
    }
    QBrush *brush=new QBrush( Qt::yellow );
    painter->setBrush(*brush);
    QPen pen;
    pen.setStyle(Qt::DotLine);
    pen.setWidth(2);
    pen.setBrush(*brush);
    painter->setPen(pen);
    int ll = man_list.length();
    if (left_select<right_select)
    {
        for (int i=left_select;i<right_select;i++)
        {
            if (ll>i+1)
                painter->drawLine(QPointF(signal_transform_x(((Point)(man_list.at(i))).point.x()),signal_transform_y(((Point)(man_list.at(i))).point.y())),
                                  QPointF(signal_transform_x(((Point)(man_list.at(i+1))).point.x()),signal_transform_y(((Point)(man_list.at(i+1))).point.y())));
        }
    }


    if (is_scale_mode_scale1==true)
    {
        if (scale_mode_scale_list1.size()==2)
            painter->drawLine(scale_mode_scale_list1.at(0),scale_mode_scale_list1.at(1));

    }
    if (is_scale_mode_scale2==true)
    {
        if (scale_mode_scale_list2.size()==2)
            painter->drawLine(scale_mode_scale_list2.at(0),scale_mode_scale_list2.at(1));

    }
    if (is_scale_mode_angle1==true)
    {
        if (scale_mode_angle_list1.size()==2)
            painter->drawLine(scale_mode_angle_list1.at(0),scale_mode_angle_list1.at(1));
    }
    if (is_scale_mode_angle2==true)
    {
        if (scale_mode_angle_list2.size()==2)
            painter->drawLine(scale_mode_angle_list2.at(0),scale_mode_angle_list2.at(1));
    }
    if (is_scale_mode_point1==true)
    {
        if (scale_mode_point_list1.size()==1)
            painter->drawPoint(scale_mode_point_list1.at(0));
    }
    if (is_scale_mode_point2==true)
    {
        if (scale_mode_point_list2.size()==1)
            painter->drawPoint(scale_mode_point_list2.at(0));
    }
delete brush;

}


bool Spectro_draw::eventFilter(QObject *object, QEvent *event)
{
    if (is_scale_mode_enable==false)
    {
        if (is_zoom_mode_enable==false)
        {
            if (is_select_mode_enable==false)
            {
                if (event->type() == QEvent::MouseMove )
                {
                    if (eType==Polygon)
                    {
                        if (man_list.size()==0)
                        {
                            man_list.append(* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,getRGB(eColor),true,Polygon));
                            is_new_item=false;
                        }
                        else
                        {
                            if (is_new_item==false)
                                man_list.append(* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,getRGB(eColor),false,Polygon));
                            else
                            {
                                man_list.append(* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,getRGB(eColor),true,Polygon));
                                is_new_item=false;
                            }
                        }
                    }
                    if (eType==Rect)
                    {
                        if (man_list.size()==0)
                        {
                            man_list.append(* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,getRGB(eColor),true,Rect));
                            is_new_item=false;
                        }
                        else
                        {
                            if (is_new_item!=false)
                            {
                                man_list.append(* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,getRGB(eColor),true,Rect));
                                is_new_item=false;
                            }
                        }
                    }

                }
                if (event->type() == QEvent::MouseButtonPress )
                {
                    if (eType==Line)
                    {
                        if (man_list.size()==0)
                        {
                            man_list.append(* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,getRGB(eColor),true,Line));
                            is_new_item=false;
                        }
                        else
                        {
                            if (is_new_item==false)
                                man_list.append(* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,getRGB(eColor),false,Line));
                            else
                            {
                                man_list.append(* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,getRGB(eColor),true,Line));
                                is_new_item=false;
                            }
                        }
                    }

                }
                if (event->type() == QEvent::MouseButtonRelease )
                {
                    if (eType==Polygon)
                    {
                        man_list.append(* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,getRGB(eColor),false,Polygon));
                        int num=find_point(man_list.size()-1);
                        QPointF po=((Point)(man_list.at(num))).point;
                        QColor co=((Point)(man_list.at(num))).color;
                        man_list.append( * new Point( po,co,false,Polygon));
                        is_new_item=true;
                    }
                    if (eType==Rect)
                    {
                        man_list.append(* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),
                                                            ((Point)(man_list.at(man_list.size()-1))).point.y()),getRGB(eColor),false,Rect));
                        man_list.append(* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())),getRGB(eColor),false,Rect));
                        man_list.append(* new Point(QPointF(((Point)(man_list.at(man_list.size()-3))).point.x(),
                                                            signal_inv_transform_y(((QMouseEvent*)event)->posF().y())),getRGB(eColor),false,Rect));
                        man_list.append(* new Point(((Point)(man_list.at(man_list.size()-4))).point,getRGB(eColor),false,Rect));
                        is_new_item=true;
                    }
                }
                if (event->type() == QEvent::MouseButtonDblClick )
                {
                    if (eType==Line)
                    {
                        int num1=find_point(man_list.size()-1);
                        QPointF po1=((Point)(man_list.at(num1))).point;
                        QColor co1=((Point)(man_list.at(num1))).color;
                        man_list.append( * new Point( po1,co1,false,Line));
                        is_new_item=true;
                    }
                }
                if (event->type() == QEvent::KeyPress) {
                    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
                    if (keyEvent->key() == Qt::Key_Space) {
                        focusNextPrevChild(true);
                        is_new_item=true;
                    }
                }
            }
            else
            {
                if (event->type() == QEvent::MouseButtonDblClick )
                {
                    int p=find_closest_point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())));
                    get_selected_area(p);
                }
                if (event->type() == QEvent::MouseMove )
                {
                    if (eType==Line)
                    {
                        if (man_list.size()==0)
                            return false;
                        int p=find_closest_point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())));
                        int k=get_equal_point(p);
                        if (k==-1)
                        {
                            bool a=((Point)(man_list.at(p))).updown;
                            QColor r=((Point)(man_list.at(p))).color;
                            man_list.replace(p,* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,r,a,Line));
                        }
                        else
                        {
                            bool a=((Point)(man_list.at(p))).updown;
                            QColor r=((Point)(man_list.at(p))).color;
                            man_list.replace(p,* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,r,a,Line));
                            bool a1=((Point)(man_list.at(k))).updown;
                            QColor r1=((Point)(man_list.at(k))).color;
                            man_list.replace(k,* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,r1,a1,Line));
                        }

                    }
                    if (eType==Rect)
                    {  if (man_list.size()==0)
                            return false;
                        int p=find_closest_point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())));
                        if (p+4>man_list.size()-1)
                        {
                            if (((Point)(man_list.at(p))).point==((Point)(man_list.at(p-4))).point)
                            {
                                int p1=find_closest_point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())));
                                bool a1=((Point)(man_list.at(p1))).updown;
                                QColor r1=((Point)(man_list.at(p1))).color;
                                man_list.replace(p1,* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,r1,a1,Rect));

                                int p2=find_closest_point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())));
                                p2=p2-4;
                                bool a2=((Point)(man_list.at(p2))).updown;
                                QColor r2=((Point)(man_list.at(p2))).color;
                                man_list.replace(p2,* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,r2,a2,Rect));
                            }
                            else
                            {
                                int p1=find_closest_point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())));
                                bool a1=((Point)(man_list.at(p1))).updown;
                                QColor r1=((Point)(man_list.at(p1))).color;
                                man_list.replace(p1,* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())),r1,a1,Rect));
                            }
                        }
                        if (p-4<0)
                        {
                            if (((Point)(man_list.at(p))).point==((Point)(man_list.at(p+4))).point)
                            {
                                int p1=find_closest_point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())));
                                bool a1=((Point)(man_list.at(p1))).updown;
                                QColor r1=((Point)(man_list.at(p1))).color;
                                man_list.replace(p1,* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,r1,a1,Rect));
                                int p2=find_closest_point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())));
                                p2=p2+4;
                                bool a2=((Point)(man_list.at(p2))).updown;
                                QColor r2=((Point)(man_list.at(p2))).color;
                                man_list.replace(p2,* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,r2,a2,Rect));
                            }
                            else
                            {
                                int p1=find_closest_point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())));
                                bool a1=((Point)(man_list.at(p1))).updown;
                                QColor r1=((Point)(man_list.at(p1))).color;
                                man_list.replace(p1,* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,r1,a1,Rect));
                            }
                        }
                        if (p-4>=0 && p+4<=man_list.size()-1)
                        {
                            if (((Point)(man_list.at(p))).point==((Point)(man_list.at(p+4))).point)
                            {
                                int p1=find_closest_point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())));
                                bool a1=((Point)(man_list.at(p1))).updown;
                                QColor r1=((Point)(man_list.at(p1))).color;
                                man_list.replace(p1,* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,r1,a1,Rect));
                                int p2=find_closest_point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())));
                                p2=p2+4;
                                bool a2=((Point)(man_list.at(p2))).updown;
                                QColor r2=((Point)(man_list.at(p2))).color;
                                man_list.replace(p2,* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,r2,a2,Rect));
                            }
                            if (((Point)(man_list.at(p))).point==((Point)(man_list.at(p-4))).point)
                            {
                                int p1=find_closest_point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())));
                                bool a1=((Point)(man_list.at(p1))).updown;
                                QColor r1=((Point)(man_list.at(p1))).color;
                                man_list.replace(p1,* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,r1,a1,Rect));
                                int p2=find_closest_point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())));
                                p2=p2-4;
                                bool a2=((Point)(man_list.at(p2))).updown;
                                QColor r2=((Point)(man_list.at(p2))).color;
                                man_list.replace(p2,* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())),r2,a2,Rect));
                            }
                            if (((Point)(man_list.at(p))).point!=((Point)(man_list.at(p-4))).point && (((Point)(man_list.at(p))).point!=((Point)(man_list.at(p+4))).point))
                            {
                                int p1=find_closest_point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())));
                                bool a1=((Point)(man_list.at(p1))).updown;
                                QColor r1=((Point)(man_list.at(p1))).color;
                                man_list.replace(p1,* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,r1,a1,Rect));
                            }
                        }
                    }

                    if (eType==Polygon)
                    {
                        if (man_list.size()==0)
                            return false;

                        int p=find_closest_point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())));
                        int k=get_equal_point(p);
                        if (k==-1)
                        {
                            bool a=((Point)(man_list.at(p))).updown;
                            QColor r=((Point)(man_list.at(p))).color;
                            man_list.replace(p,* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,r,a,Polygon));
                        }
                        else
                        {
                            bool a=((Point)(man_list.at(p))).updown;
                            QColor r=((Point)(man_list.at(p))).color;
                            man_list.replace(p,* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,r,a,Polygon));

                            bool a1=((Point)(man_list.at(k))).updown;
                            QColor r1=((Point)(man_list.at(k))).color;
                            man_list.replace(k,* new Point(QPointF(signal_inv_transform_x(((QMouseEvent*)event)->posF().x()),signal_inv_transform_y(((QMouseEvent*)event)->posF().y())) ,r1,a1,Polygon));
                        }
                    }
                }
            }
            this->update();
        }
        else
        {
            if (event->type() == QEvent::MouseMove )
            {
                if (is_new_point==true)
                {
                    point1=((QMouseEvent*)event)->posF();
                    is_new_point=false;
                }
            }
            if (event->type() == QEvent::MouseButtonRelease )
            {
                point2=((QMouseEvent*)event)->posF();
                is_new_point=true;
                emit signal_zoomer(point1,point2);
            }
        }
    }
    if (is_scale_mode_enable==true)
    {
        if (is_scale_mode_scale1==true)
        {
            if (event->type() == QEvent::MouseButtonPress )
            {
                scale_mode_scale_list1.append(QPointF(((QMouseEvent*)event)->posF()));
                this->repaint();
                if (scale_mode_scale_list1.size()==2)
                {
                    double x1=signal_inv_transform_x(scale_mode_scale_list1.at(0).x());
                    double x2=signal_inv_transform_x(scale_mode_scale_list1.at(1).x());
                    double y1=signal_inv_transform_y(scale_mode_scale_list1.at(0).y());
                    double y2=signal_inv_transform_y(scale_mode_scale_list1.at(1).y());
                    double a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
                    emit signal_to_change_scale_scale1(a);
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
                    double x1=signal_inv_transform_x(scale_mode_scale_list2.at(0).x());
                    double x2=signal_inv_transform_x(scale_mode_scale_list2.at(1).x());
                    double y1=signal_inv_transform_y(scale_mode_scale_list2.at(0).y());
                    double y2=signal_inv_transform_y(scale_mode_scale_list2.at(1).y());
                    double a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
                    emit signal_to_change_scale_scale2(a);
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
                    double x1=signal_inv_transform_x(scale_mode_angle_list1.at(0).x());
                    double x2=signal_inv_transform_x(scale_mode_angle_list1.at(1).x());
                    double y1=signal_inv_transform_y(scale_mode_angle_list1.at(0).y());
                    double y2=signal_inv_transform_y(scale_mode_angle_list1.at(1).y());
                    double a=x2-x1;
                    double b=y2-y1;
                    emit signal_to_change_scale_angle1(a,b);
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
                    double x1=signal_inv_transform_x(scale_mode_angle_list2.at(0).x());
                    double x2=signal_inv_transform_x(scale_mode_angle_list2.at(1).x());
                    double y1=signal_inv_transform_y(scale_mode_angle_list2.at(0).y());
                    double y2=signal_inv_transform_y(scale_mode_angle_list2.at(1).y());
                    double a=x2-x1;
                    double b=y2-y1;
                    emit signal_to_change_scale_angle2(a,b);
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
                    emit signal_to_change_scale_point1(QPointF(signal_inv_transform_x(scale_mode_point_list1.at(0).x()),signal_inv_transform_y(scale_mode_point_list1.at(0).y())));
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
                    emit signal_to_change_scale_point22(QPointF(signal_inv_transform_x(scale_mode_point_list2.at(0).x()),signal_inv_transform_y(scale_mode_point_list2.at(0).y())));
                    scale_mode_point_list2.clear();
                }
            }
        }
    }
    return false;
}

int  Spectro_draw::find_closest_point(QPointF point)
{
    int k=0;
    double a=10000;
    for (int i=0;i<man_list.size();i++)
    {

        double bx=((Point)(man_list.at(i))).point.x();
        double by=((Point)(man_list.at(i))).point.y();
        if   ((bx-point.x())*(bx-point.x())+(by-point.y())*(by-point.y())<a)
        {
            k=i;
            a=(bx-point.x())*(bx-point.x())+(by-point.y())*(by-point.y());
        }
    }
    return k;
}

QColor Spectro_draw::getRGB(EColor color)
{

    if  (color==white)
    {
        return Qt::white;
    }
    if  (color==red)
    {
        return Qt::red;
    }
    if  (color==green)
    {
        return Qt::green;
    }
    if  (color==cyan)
    {
        return Qt::cyan;
    }
    if  (color==magenta)
    {
        return Qt::magenta;
    }
    if  (color==yellow)
    {
        return Qt::yellow;
    }
    if  (color==gray)
    {
        return Qt::gray;
    }
    if  (color==black)
    {
        return Qt::black;
    }
    if  (color==blue)
    {
        return Qt::blue;
    }
    if  (color==darkGreen)
    {
        return Qt::darkGreen;
    }
    if  (color==darkRed)
    {
        return Qt::darkRed;
    }
    if  (color==darkBlue)
    {
        return Qt::darkBlue;
    }
    if  (color==darkCyan)
    {
        return Qt::darkCyan;
    }
    if  (color==darkMagenta)
    {
        return Qt::darkMagenta;
    }
    if  (color==darkYellow)
    {
        return Qt::darkYellow;
    }
    if  (color==darkGray)
    {
        return Qt::darkGray;
    }
    if  (color==lightGray)
    {
        return Qt::lightGray;
    }
    return Qt::black;
}


int Spectro_draw::find_point(int number)
{
    if (number<0)
        return 0;
    for (int i = number ;i>=0;i--)
    {
        if ( ((Point)(man_list.at(i))).updown==true )
        {
            return (i);
        }
    }
    return 0;
}


void Spectro_draw::change_color(QColor color)
{
    if (is_sketch_mode_enable==false)
    {
        if (left_select<right_select)
        {
            for (int i=left_select;i<right_select;i++)
            {
                QPointF p=(((Point)(man_list.at(i))).point);
                bool a=((Point)(man_list.at(i))).updown;
                EType type=((Point)(man_list.at(i))).type;
                man_list.replace(i,* new Point(p ,color,a,type));
            }
        }
    }
    if (is_sketch_mode_enable==true)
    {
        if (sketch_list.size()>0)
        {
            for (int i=0;i<sketch_list.size()-1;i++)
            {
                QPointF p=(((Point)(sketch_list.at(i))).point);
                bool a=((Point)(sketch_list.at(i))).updown;
                EType type=((Point)(sketch_list.at(i))).type;
                sketch_list.replace(i,* new Point(p ,color,a,type));
            }
        }
    }
    this->update();
}

void Spectro_draw::delete_last()
{
    if (left_select<right_select)
    {
        for (int i=left_select;i<right_select+1;i++)
        {
            man_list.removeAt(left_select);
        }
    }
    left_select=0;
    right_select=0;


}
int Spectro_draw::get_equal_point(int num)
{
    for (int i=0;i<man_list.size();i++)
    {
        if (i==num)
        {}
        else
        {
            if (((Point)(man_list.at(i))).point==((Point)(man_list.at(num))).point)
                return i;
        }
    }
    return -1;
}

void Spectro_draw::get_selected_area(int num)
{
    left_select=find_point(num);
    for (int i=num;i<man_list.size();i++)
    {
        if (((Point)(man_list.at(i+1))).updown==true)
        {
            right_select=i;
            return;
        }
    }
    right_select=man_list.size()-1;
}

void Spectro_draw::read_from_file()
{
    QPointF temp_point;
    is_new_item=true;
    QString way = QFileDialog::getOpenFileName(this, tr("Open File"), "",tr(".skt Files (*.skt)"));
    if (way==0)
    {
        return;
    }
    QFile file(way);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    int k=0;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (k==0)
        {
            for (int i=0;i<line.size()-1;i++)
            {
                if (i>0)
                {
                    if (line.at(i).isSpace()==true)
                    {
                        if (line.at(i-1).isNumber()==true)
                        {
                            line.replace(i,1,",");
                        }
                    }
                }
            }
            QStringList list1 = line.split(",", QString::SkipEmptyParts);
            QString a1= list1[0];
            QString a2=   list1[1];
            fi=a1.toDouble();
            x_shift=a2.toDouble();
            _k=1;
            emit signla_k(_k);
            emit signla_fi(fi);
            emit signla_x_shift(x_shift);
        }
        if (k==1)
        {
            for (int i=0;i<line.size()-1;i++)
            {
                if (i>0)
                {
                    if (line.at(i).isSpace()==true)
                    {
                        if (line.at(i-1).isNumber()==true)
                        {
                            line.replace(i,1,",");
                        }
                    }
                }
            }
            QStringList list1 = line.split(",", QString::SkipEmptyParts);
            QString a1= list1[0];
            QString a2=   list1[1];
            y_shift=a1.toDouble();
            emit signla_y_shift(y_shift);
        }
        if (k==2)
        {
            for (int i=0;i<line.size()-1;i++)
            {
                if (i>0)
                {
                    if (line.at(i).isSpace()==true)
                    {
                        if (line.at(i-1).isNumber()==true)
                        {
                            line.replace(i,1,",");
                        }
                    }
                }
            }
            QStringList list1 = line.split(",", QString::SkipEmptyParts);
            QString a1= list1[0];
            QString a2=   list1[1];
            x_scale=a1.toDouble();
            y_scale=a2.toDouble();
            emit signla_x_scale(x_scale);
            emit signla_y_scale(y_scale);
        }
        if (k==3)
        { for (int i=0;i<line.size()-1;i++)
            {
                if (i>0)
                {
                    if (line.at(i).isSpace()==true)
                    {
                        if (line.at(i-1).isNumber()==true)
                        {
                            line.replace(i,1,",");
                        }
                    }
                }
            }
            QStringList list1 = line.split(",", QString::SkipEmptyParts);
            QString a1= list1[0];
            points_count=a1.toDouble();
        }
        if (k>3)
        {
            for (int i=0;i<line.size()-1;i++)
            {
                if (i>0)
                {
                    if (line.at(i).isSpace()==true)
                    {
                        if (line.at(i-1).isNumber()==true)
                        {
                            line.replace(i,1,",");
                        }
                    }
                }
            }
            QStringList list1 = line.split(",", QString::SkipEmptyParts);
            QString a1= list1[0];
            QString a2=   list1[1];
            QString a3=   list1[2];
            if (k==4)
            {
                if (a3.toDouble()==-1)
                {

                    temp_point=QPointF(calculate_const_x(a1.toDouble(),a2.toDouble()),calculate_const_y(a1.toDouble(),a2.toDouble()));
                    is_new_item=true;
                }
                if (a3.toDouble()==2)
                {
                    temp_point=QPointF(calculate_const_x(a1.toDouble(),a2.toDouble()),calculate_const_y(a1.toDouble(),a2.toDouble()));
                    sketch_list.append(* new Point(QPointF(QPointF(calculate_const_x(a1.toDouble(),a2.toDouble()),calculate_const_y(a1.toDouble(),a2.toDouble()))) ,Qt::red,true,Line));

                    is_new_item=false;
                }
            }
            if (k>4)
            {
                if (a3.toDouble()==-1)
                {
                    if (is_new_item==true)
                    {
                        temp_point=QPointF(calculate_const_x(a1.toDouble(),a2.toDouble()),calculate_const_y(a1.toDouble(),a2.toDouble()));


                    }
                    if (is_new_item==false)
                    {
                        temp_point=QPointF(calculate_const_x(a1.toDouble(),a2.toDouble()),calculate_const_y(a1.toDouble(),a2.toDouble()));


                    }
                }
                if (a3.toDouble()==2)
                {
                    if (is_new_item==true)
                    {
                        sketch_list.append(* new Point(temp_point ,Qt::red,true,Line));
                        sketch_list.append(* new Point(QPointF(calculate_const_x(a1.toDouble(),a2.toDouble()),calculate_const_y(a1.toDouble(),a2.toDouble())) ,Qt::red,true,Line));
                        temp_point=QPointF(calculate_const_x(a1.toDouble(),a2.toDouble()),calculate_const_y(a1.toDouble(),a2.toDouble()));

                    }
                    else
                    {
                        sketch_list.append(* new Point(QPointF(calculate_const_x(a1.toDouble(),a2.toDouble()),calculate_const_y(a1.toDouble(),a2.toDouble())) ,Qt::red,false,Line));
                        temp_point=QPointF(calculate_const_x(a1.toDouble(),a2.toDouble()),calculate_const_y(a1.toDouble(),a2.toDouble()));


                    }
                }
            }
        }
        k++;
    }




    is_new_item=true;

}
void Spectro_draw::replot_sketch(double x_sh,double y_sh,double x_sc,double y_sc,double fi0,double fi_shift,double k)
{

    double fi_new=fi0+k*fi_shift;
    if (man_list.size()>0)
        for (int i=0;i<man_list.size();i++)
        {
            double x=((Point)(man_list.at(i))).point.x();
            double y=((Point)(man_list.at(i))).point.y();
            double a=(x*cos((fi_new-fi)*2*3.1415926/360)+y*sin((fi_new-fi)*2*3.1415926/360));
            double b=(y*cos((fi_new-fi)*2*3.1415926/360)-x*sin((fi_new-fi)*2*3.1415926/360));
            QColor color=((Point)(man_list.at(i))).color;
            bool uppd=((Point)(man_list.at(i))).updown;
            man_list.replace(i,(* new Point(QPointF( a,b) ,color,uppd,Line)));
        }
    if (/*x_sh!=0 && y_sh!=0 &&*/ x_sc!=0 && y_sc!=0)
    {
        if (sketch_list.size()>0)
        {
            for (int i=0;i<sketch_list.size();i++)
            {
                double x=((Point)(sketch_list.at(i))).point.x();
                double y=((Point)(sketch_list.at(i))).point.y();
                QColor color=((Point)(sketch_list.at(i))).color;
                bool uppd=((Point)(sketch_list.at(i))).updown;
                double x_old=(x*cos(fi*2*3.1415926/360.0)-y*sin(fi*2*3.1415926/360.0))*x_scale-x_shift*x_scale;
                double y_old=(x*sin(fi*2*3.1415926/360.0)+y*cos(fi*2*3.1415926/360.0))*y_scale-y_shift*y_scale;
                double a=(((x_sh)+x_old/x_sc)*cos(fi_new*2*3.1415926/360.0)+((y_sh)+y_old/y_sc)*sin(fi_new*2*3.1415926/360.0));
                double b=(((y_sh)+y_old/y_sc)*cos(fi_new*2*3.1415926/360.0)-((x_sh)+x_old/x_sc)*sin(fi_new*2*3.1415926/360.0));

                sketch_list.replace(i , (* new Point(QPointF( a , b ) ,color,uppd,Line)));
            }
        }

        x_scale=x_sc;
        y_scale=y_sc;
        x_shift=x_sh;
        y_shift=y_sh;
        fi=fi_new;
    }
    fi=fi_new;
    this->repaint();
}
void Spectro_draw::flip()
{
    if (sketch_list.size()>0)
    {
        for (int i=0;i<sketch_list.size();i++)
        {
            double x=((Point)(sketch_list.at(i))).point.x();
            double y=((Point)(sketch_list.at(i))).point.y();
            QColor color=((Point)(sketch_list.at(i))).color;
            bool type=((Point)(sketch_list.at(i))).type;
            sketch_list.replace(i,(* new Point(QPointF(x,-y) ,color,type,Line)));
        }
    }
    this->repaint();
}

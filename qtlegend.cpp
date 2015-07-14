#include "qtlegend.h"
#include "QPainter"
#include "QFileDialog"
#include "QCoreApplication"
#include"QLabel"
#include "QMouseEvent"

QtLegend::QtLegend(QWidget *parent) :
    QWidget(parent)
{
    this->installEventFilter(this);
    graphs_legend_count=0;
    active_graph=1;
    color[0]=black;
    color[1]=gray;
    color[2]=darkGreen;
    color[3]=darkGray;
    color[4]=darkCyan;
    color[5]=black;
    color[6]=darkYellow;
    if (point[0]!=NULL)
        point[0]=new QPointF(140,19);
    if (point[1]!=NULL)
        point[1]=new QPointF(140,37);
    if (point[2]!=NULL)
        point[2]=new QPointF(140,55);


    for (int i=0;i<nGraphsMax;i++)
    {
        if (i>7)
            color[i]=black;
        type[i]=SolidLine;
        title[i]="Curve "+QString::number(i+1);
    }

}
void QtLegend::add_graph()
{
    graphs_legend_count++;
}
void QtLegend::delete_legend()
{
    graphs_legend_count=0;
}

void QtLegend::paintEvent(QPaintEvent *  )
{
    QPainter  painter(this);
    draw(&painter);
}

void QtLegend::draw( QPainter  *painter)
{
    painter->setOpacity(0.7);
    if (graphs_legend_count==0)
    {
    }
    if (graphs_legend_count==1)
    {
        this->resize(154,43);
        painter->setRenderHint(QPainter::Antialiasing,true);
        painter->setBrush(QBrush(Qt::white));
        painter->setPen(QPen(Qt::black));
        painter->drawRoundedRect(QRect(0,0,154,34),6,6);
        painter->setFont(QFont("Helvetica [Cronyx]", 11, QFont::Helvetica));
        painter->drawText(QPoint(77,23),title[0]);
        QPen pen1(getRGB(color[0]), 5, getPen(type[0]), Qt::FlatCap, Qt::RoundJoin);
        pen1.setDashOffset(6);
        painter->setPen(pen1);
        //  painter->setPen(Qt::DotLine);
        painter->drawLine(10, 19, 70, 19);

        QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
        painter->setPen(pen10);
        painter->drawEllipse(QPoint(140,19),2.5,2.5);
    }
    if (graphs_legend_count==2)
    {
        this->resize(154,53);
        painter->setRenderHint(QPainter::Antialiasing,true);
        painter->setBrush(QBrush(Qt::white));
        painter->setPen(QPen(Qt::black));
        painter->drawRoundedRect(QRect(0,0,154,52),6,6);
        painter->setFont(QFont("Helvetica [Cronyx]", 11, QFont::Helvetica));
        painter->drawText(QPoint(77,23),title[0]);
        painter->drawText(QPoint(77,41),title[1]);
        QPen pen1(getRGB(color[0]), 5, getPen(type[0]), Qt::FlatCap, Qt::RoundJoin);
        pen1.setDashOffset(6);
        painter->setPen(pen1);
        //  painter->setPen(Qt::DotLine);
        painter->drawLine(10, 19, 70, 19);
        QPen pen2(getRGB(color[1]), 5,getPen(type[1]), Qt::FlatCap, Qt::RoundJoin);
        painter->setPen(pen2);
        painter->drawLine(10, 37, 70, 37);

        if (active_graph==1)
        {
            QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
            painter->setPen(pen10);
            painter->drawEllipse(QPoint(140,19),2.5,2.5);
        }
        if (active_graph==2)
        {
            QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
            painter->setPen(pen10);
            painter->drawEllipse(QPoint(140,37),2.5,2.5);
        }
    }
    if (graphs_legend_count==3)
    {
        this->resize(154,73);
        painter->setRenderHint(QPainter::Antialiasing,true);
        painter->setBrush(QBrush(Qt::white));
        painter->setPen(QPen(Qt::black));
        painter->drawRoundedRect(QRect(0,0,154,71),6,6);

        painter->setFont(QFont("Helvetica [Cronyx]", 11, QFont::Helvetica));
        painter->drawText(QPoint(77,23),title[0]);
        painter->drawText(QPoint(77,41),title[1]);
        painter->drawText(QPoint(77,59),title[2]);

        QPen pen1(getRGB(color[0]), 5, getPen(type[0]), Qt::FlatCap, Qt::RoundJoin);
        pen1.setDashOffset(6);
        painter->setPen(pen1);
        painter->drawLine(10, 19, 70, 19);

        QPen pen2(getRGB(color[1]), 5,getPen(type[1]), Qt::FlatCap, Qt::RoundJoin);
        painter->setPen(pen2);
        painter->drawLine(10, 37, 70, 37);
        QPen pen3(getRGB(color[2]), 5,getPen(type[2]), Qt::FlatCap, Qt::RoundJoin);
        pen2.setDashOffset(6);
        painter->setPen(pen3);
        painter->drawLine(10, 55, 70, 55);
        if (active_graph==1)
        {
            QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
            painter->setPen(pen10);
            painter->drawEllipse(QPoint(140,19),2.5,2.5);
        }
        if (active_graph==2)
        {
            QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
            painter->setPen(pen10);
            painter->drawEllipse(QPoint(140,37),2.5,2.5);
        }
        if (active_graph==3)
        {
            QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
            painter->setPen(pen10);
            painter->drawEllipse(QPoint(140,55),2.5,2.5);
        }

    }
    if (graphs_legend_count==4)
    {
        this->resize(154,73+19);
        painter->setRenderHint(QPainter::Antialiasing,true);
        painter->setBrush(QBrush(Qt::white));
        painter->setPen(QPen(Qt::black));
        painter->drawRoundedRect(QRect(0,0,154,71+19),6,6);

        painter->setFont(QFont("Helvetica [Cronyx]", 11, QFont::Helvetica));
        painter->drawText(QPoint(77,23),title[0]);
        painter->drawText(QPoint(77,41),title[1]);
        painter->drawText(QPoint(77,59),title[2]);
        painter->drawText(QPoint(77,77),title[4]);

        QPen pen1(getRGB(color[0]), 5, getPen(type[0]), Qt::FlatCap, Qt::RoundJoin);
        pen1.setDashOffset(6);
        painter->setPen(pen1);
        painter->drawLine(10, 19, 70, 19);

        QPen pen2(getRGB(color[1]), 5,getPen(type[1]), Qt::FlatCap, Qt::RoundJoin);
        painter->setPen(pen2);
        painter->drawLine(10, 37, 70, 37);

        QPen pen3(getRGB(color[2]), 5,getPen(type[2]), Qt::FlatCap, Qt::RoundJoin);
        pen2.setDashOffset(6);
        painter->setPen(pen3);
        painter->drawLine(10, 55, 70, 55);

        QPen pen4(getRGB(color[3]), 5,getPen(type[3]), Qt::FlatCap, Qt::RoundJoin);
        pen2.setDashOffset(6);
        painter->setPen(pen4);
        painter->drawLine(10, 73, 63, 73);

        if (active_graph==1)
        {
            QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
            painter->setPen(pen10);
            painter->drawEllipse(QPoint(140,19),2.5,2.5);
        }
        if (active_graph==2)
        {
            QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
            painter->setPen(pen10);
            painter->drawEllipse(QPoint(140,37),2.5,2.5);
        }
        if (active_graph==3)
        {
            QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
            painter->setPen(pen10);
            painter->drawEllipse(QPoint(140,55),2.5,2.5);
        }
        if (active_graph==4)
        {
            QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
            painter->setPen(pen10);
            painter->drawEllipse(QPoint(140,72),2.5,2.5);
        }

    }
    if (graphs_legend_count==5)
    {
        this->resize(154,73+19+19);
        painter->setRenderHint(QPainter::Antialiasing,true);
        painter->setBrush(QBrush(Qt::white));
        painter->setPen(QPen(Qt::black));
        painter->drawRoundedRect(QRect(0,0,154,71+19+19),6,6);

        painter->setFont(QFont("Helvetica [Cronyx]", 11, QFont::Helvetica));
        painter->drawText(QPoint(77,23),title[0]);
        painter->drawText(QPoint(77,41),title[1]);
        painter->drawText(QPoint(77,59),title[2]);

        QPen pen1(getRGB(color[0]), 5, getPen(type[0]), Qt::FlatCap, Qt::RoundJoin);
        pen1.setDashOffset(6);
        painter->setPen(pen1);
        painter->drawLine(10, 19, 70, 19);

        QPen pen2(getRGB(color[1]), 5,getPen(type[2]), Qt::FlatCap, Qt::RoundJoin);
        painter->setPen(pen2);
        painter->drawLine(10, 37, 70, 37);
        QPen pen3(getRGB(color[2]), 5,getPen(type[2]), Qt::FlatCap, Qt::RoundJoin);
        pen2.setDashOffset(6);
        painter->setPen(pen3);
        painter->drawLine(10, 55, 70, 55);

        if (active_graph==1)
        {
            QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
            painter->setPen(pen10);
            painter->drawEllipse(QPoint(140,19),2.5,2.5);
        }
        if (active_graph==2)
        {
            QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
            painter->setPen(pen10);
            painter->drawEllipse(QPoint(140,37),2.5,2.5);
        }
        if (active_graph==3)
        {
            QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
            painter->setPen(pen10);
            painter->drawEllipse(QPoint(140,55),2.5,2.5);
        }
        if (active_graph==4)
        {
            QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
            painter->setPen(pen10);
            painter->drawEllipse(QPoint(140,72),2.5,2.5);
        }
        if (active_graph==5)
        {
            QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
            painter->setPen(pen10);
            painter->drawEllipse(QPoint(140,89),2.5,2.5);
        }

    }
}
Qt::PenStyle QtLegend::getPen(ECurveType type)
{
    if  (type==SolidLine)
    {
        return Qt::SolidLine;
    }
    if  (type==DashLine)
    {
        return Qt::DashLine;
    }
    if  (type==DotLine)
    {
        return Qt::DotLine;
    }
    if  (type==DashDotLine)
    {
        return Qt::DashDotLine;
    }
    if  (type==DashDotDotLine)
    {
        return Qt::DashDotDotLine;
    }
    if  (type==CustomDashLine)
    {
        return Qt::CustomDashLine;
    }
}
QColor QtLegend::getRGB(EColor color)
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


}
void QtLegend::change_type(int curve, Qt::PenStyle style)
{
    if (curve==1)
    {


        if (style==getPen(SolidLine))
            type[0]=SolidLine;
        if (style==getPen(DashLine))
            type[0]=DashLine;
        if (style==getPen(DotLine))
            type[0]=DotLine;
        if (style==getPen(DashDotLine))
            type[0]=DashDotLine;
        if (style==getPen(DashDotDotLine))
            type[0]=DashDotDotLine;
    }
    if (curve==2)
    {

        if (style==getPen(SolidLine))
            type[1]=SolidLine;
        if (style==getPen(DashLine))
            type[1]=DashLine;
        if (style==getPen(DotLine))
            type[1]=DotLine;
        if (style==getPen(DashDotLine))
            type[1]=DashDotLine;
        if (style==getPen(DashDotDotLine))
            type[1]=DashDotDotLine;
    }
    if (curve==3)
    {

        if (style==getPen(SolidLine))
            type[2]=SolidLine;
        if (style==getPen(DashLine))
            type[2]=DashLine;
        if (style==getPen(DotLine))
            type[2]=DotLine;
        if (style==getPen(DashDotLine))
            type[2]=DashDotLine;
        if (style==getPen(DashDotDotLine))
            type[2]=DashDotDotLine;
    }
    if (curve==4)
    {


        if (style==getPen(SolidLine))
            type[3]=SolidLine;
        if (style==getPen(DashLine))
            type[3]=DashLine;
        if (style==getPen(DotLine))
            type[3]=DotLine;
        if (style==getPen(DashDotLine))
            type[3]=DashDotLine;
        if (style==getPen(DashDotDotLine))
            type[3]=DashDotDotLine;
    }
}
void QtLegend::change_color(int curve, QColor color_curve)
{
    if (color[curve-1]==NULL)
            return;
    if (color_curve==Qt::black)
        color[curve-1]=black;
    if (color_curve==Qt::white)
        color[curve-1]=white;
    if (color_curve==Qt::red)
        color[curve-1]=red;
    if (color_curve==Qt::green)
        color[curve-1]=green;
    if (color_curve==Qt::blue)
        color[curve-1]=blue;
    if (color_curve==Qt::cyan)
        color[curve-1]=cyan;
    if (color_curve==Qt::magenta)
        color[curve-1]=magenta;
    if (color_curve==Qt::yellow)
        color[curve-1]=yellow;
    if (color_curve==Qt::gray)
        color[curve-1]=gray;

    if (color_curve==Qt::darkRed)
        color[curve-1]=darkRed;
    if (color_curve==Qt::darkGreen)
        color[curve-1]=darkGreen;
    if (color_curve==Qt::darkBlue)
        color[curve-1]=darkBlue;
    if (color_curve==Qt::darkCyan)
        color[curve-1]=darkCyan;
    if (color_curve==Qt::darkMagenta)
        color[curve-1]=darkMagenta;
    if (color_curve==Qt::darkYellow)
        color[curve-1]=darkYellow;
    if (color_curve==Qt::darkGray)
        color[curve-1]=darkGray;
    if (color_curve==Qt::lightGray)
        color[curve-1]=lightGray;
}
void QtLegend::change_title(int curve, QString curve_title)
{
    if (title[curve-1]!=NULL)
    title[curve-1]=curve_title;
}
bool QtLegend::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        emit signal_from_legend((((QMouseEvent*)event)->pos().y()));


        if (((((QMouseEvent*)event)->pos().y()>0) &&  ((((QMouseEvent*)event)->pos().y()<28))))
        {
            active_graph=1;
        }
        if (((((QMouseEvent*)event)->pos().y())>28) &&  ((((QMouseEvent*)event)->pos().y())<45))
        {
            active_graph=2;
        }
        if (((((QMouseEvent*)event)->pos().y()>45) &&  ((((QMouseEvent*)event)->pos().y()<62))))
        {
            active_graph=3;
        }
        if (((((QMouseEvent*)event)->pos().y())>62) &&  ((((QMouseEvent*)event)->pos().y())<79))
        {
            active_graph=4;
        }
        if (((((QMouseEvent*)event)->pos().y()>79) &&  ((((QMouseEvent*)event)->pos().y()<96))))
        {
            active_graph=5;
        }
        if (((((QMouseEvent*)event)->pos().y())>96) &&  ((((QMouseEvent*)event)->pos().y())<113))
        {
            active_graph=6;
        }
        this->repaint();
    }
    return false;
}

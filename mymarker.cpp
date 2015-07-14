#include "mymarker.h"
#include "QPainter"
#include "QEvent"
#include "QMouseEvent"

MyMarker::MyMarker(QWidget *parent) :
    QWidget(parent)
{

    active_marker=0;
    markers_count=0;
    reference_marker_mode=nonactive;
    ref_x=0;
    ref_y=0;
    this->installEventFilter(this);
}
void MyMarker::paintEvent(QPaintEvent *)
{
    QPainter  painter(this);
    draw(&painter);

}
int MyMarker::get_string_lenght()
{
    int a=0;
    for (int i=0;i<marker_list.size();i++)
    {
        if (marker_list[i]->length() > a)
            a=marker_list[i]->length();
    }
    return a;
}

void MyMarker::draw(QPainter *painter)
{

    for (int i=0;i<nGraphsMax;i++)
    {
        if (marker_list.size()<=i)
        {
            xs[i]=0;
            ys[i]=0;
        }
    }
    int lenght=get_string_lenght();
    painter->setOpacity(0.7);

    if (marker_list.size()==0)
    {
    }
    else
    {
        if (marker_list.size()==1)
        {

            if (reference_marker_mode==nonactive)
            {
                this->resize(150+lenght*3,35);
                //add resize
                painter->setRenderHint(QPainter::Antialiasing,true);
                painter->setBrush(QBrush(Qt::white));
                painter->setPen(QPen(Qt::black));
                painter->drawRoundedRect(QRect(0,0,150+lenght*3,32),6,6);
                painter->setFont(QFont("Helvetica [Cronyx]", 11, QFont::Bold));
                painter->drawText(QPoint(7,23),"1"+*marker_list[0]);
                QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                painter->setPen(pen10);
                painter->drawEllipse(QPoint(140+lenght*3,18),2.5,2.5);
            }
            if (reference_marker_mode==active)
            {
                this->resize(150+lenght*3,60);
                //add resize
                painter->setRenderHint(QPainter::Antialiasing,true);
                painter->setBrush(QBrush(Qt::white));
                painter->setPen(QPen(Qt::black));
                painter->drawRoundedRect(QRect(0,0,150+lenght*3,58),6,6);
                painter->setFont(QFont("Helvetica [Cronyx]", 11, QFont::Bold));
                painter->drawText(QPoint(7,23),"1:  x = "+QString::number(ref_x-xs[0],'f',3)+"; y = "+QString::number(ref_y-ys[0],'f',3));

                painter->drawText(QPoint(7,47),"R: x = "+QString::number(ref_x,'f',3)+"; y = "+QString::number(ref_y,'f',3));
                painter->setPen(QPen(Qt::black));
                painter->drawLine(7,30,200,30);
                if (active_marker==-1)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,45),2.5,2.5);
                }
                if (active_marker==0)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,18),2.5,2.5);
                }

            }
        }
        if (marker_list.size()==2)
        {
            if (reference_marker_mode==nonactive)
            {
                this->resize(150+lenght*3,54);
                painter->setRenderHint(QPainter::Antialiasing,true);
                painter->setBrush(QBrush(Qt::white));
                painter->setPen(QPen(Qt::black));
                painter->drawRoundedRect(QRect(0,0,150+lenght*3,52),6,6);
                painter->setFont(QFont("Helvetica [Cronyx]", 11, QFont::Bold));
                painter->drawText(QPoint(7,23),"1"+*marker_list[0]);
                painter->drawText(QPoint(7,43),"2"+*marker_list[1]);
                if (active_marker==0)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,18),2.5,2.5);
                }
                if (active_marker==1)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,39),2.5,2.5);
                }


            }
            if (reference_marker_mode==active)
            {
                this->resize(150+lenght*3,74);
                painter->setRenderHint(QPainter::Antialiasing,true);
                painter->setBrush(QBrush(Qt::white));
                painter->setPen(QPen(Qt::black));
                painter->drawRoundedRect(QRect(0,0,150+lenght*3,72),6,6);
                painter->setFont(QFont("Helvetica [Cronyx]", 11, QFont::Bold));
                painter->drawText(QPoint(7,23),"1:  x = "+QString::number(ref_x-xs[0],'f',3)+"; y = "+QString::number(ref_y-ys[0],'f',3));
                painter->drawText(QPoint(7,43),"2:  x = "+QString::number(ref_x-xs[1],'f',3)+"; y = "+QString::number(ref_y-ys[1],'f',3));
                painter->drawText(QPoint(7,63),"R: x = "+QString::number(ref_x,'f',3)+"; y = "+QString::number(ref_y,'f',3));

                painter->setPen(QPen(Qt::black));
                painter->drawLine(7,48,200,48);

                if (active_marker==-1)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,58),2.5,2.5);
                }
                if (active_marker==0)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,18),2.5,2.5);
                }
                if (active_marker==1)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,39),2.5,2.5);
                }


            }

        }
        if (marker_list.size()==3)
        {
            if (reference_marker_mode==nonactive)
            {
                this->resize(150+lenght*3,73);
                painter->setRenderHint(QPainter::Antialiasing,true);
                painter->setBrush(QBrush(Qt::white));
                painter->setPen(QPen(Qt::black));
                painter->drawRoundedRect(QRect(0,0,150+lenght*3,71),6,6);
                painter->setFont(QFont("Helvetica [Cronyx]", 11, QFont::Bold));
                painter->drawText(QPoint(7,23),"1"+*marker_list[0]);
                painter->drawText(QPoint(7,43),"2"+*marker_list[1]);
                painter->drawText(QPoint(7,63),"3"+*marker_list[2]);
                if (active_marker==0)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,18),2.5,2.5);
                }
                if (active_marker==1)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,39),2.5,2.5);
                }
                if (active_marker==2)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,60),2.5,2.5);
                }


            }
            if (reference_marker_mode==active)
            {
                this->resize(150+lenght*3,96);
                painter->setRenderHint(QPainter::Antialiasing,true);
                painter->setBrush(QBrush(Qt::white));
                painter->setPen(QPen(Qt::black));
                painter->drawRoundedRect(QRect(0,0,150+lenght*3,94),6,6);
                painter->setFont(QFont("Helvetica [Cronyx]", 11, QFont::Bold));
                painter->drawText(QPoint(7,23),"1:  x = "+QString::number(ref_x-xs[0],'f',3)+"; y = "+QString::number(ref_y-ys[0],'f',3));
                painter->drawText(QPoint(7,43),"2:  x = "+QString::number(ref_x-xs[1],'f',3)+"; y = "+QString::number(ref_y-ys[1],'f',3));
                painter->drawText(QPoint(7,63),"3:  x = "+QString::number(ref_x-xs[2],'f',3)+"; y = "+QString::number(ref_y-ys[2],'f',3));
                painter->drawText(QPoint(7,83),"R: x = "+QString::number(ref_x,'f',3)+"; y = "+QString::number(ref_y,'f',3));

                painter->setPen(QPen(Qt::black));
                painter->drawLine(7,68,200,68);

                if (active_marker==-1)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,81),2.5,2.5);
                }
                if (active_marker==0)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,18),2.5,2.5);
                }
                if (active_marker==1)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,39),2.5,2.5);
                }
                if (active_marker==2)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,60),2.5,2.5);
                }


            }

        }
        if (marker_list.size()==4)
        {
            if (reference_marker_mode==nonactive)
            {
                this->resize(150+lenght*3,93);
                painter->setRenderHint(QPainter::Antialiasing,true);
                painter->setBrush(QBrush(Qt::white));
                painter->setPen(QPen(Qt::black));
                painter->drawRoundedRect(QRect(0,0,150+lenght*3,91),6,6);
                painter->setFont(QFont("Helvetica [Cronyx]", 11, QFont::Bold));
                painter->drawText(QPoint(7,23),"1"+*marker_list[0]);
                painter->drawText(QPoint(7,43),"2"+*marker_list[1]);
                painter->drawText(QPoint(7,63),"3"+*marker_list[2]);
                painter->drawText(QPoint(7,83),"4"+*marker_list[3]);
                if (active_marker==0)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,18),2.5,2.5);
                }
                if (active_marker==1)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,39),2.5,2.5);
                }
                if (active_marker==2)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,60),2.5,2.5);
                }
                if (active_marker==3)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,81),2.5,2.5);
                }


            }
            if (reference_marker_mode==active)
            {
                this->resize(150+lenght*3,112);
                painter->setRenderHint(QPainter::Antialiasing,true);
                painter->setBrush(QBrush(Qt::white));
                painter->setPen(QPen(Qt::black));
                painter->drawRoundedRect(QRect(0,0,150+lenght*3,110),6,6);
                painter->setFont(QFont("Helvetica [Cronyx]", 11, QFont::Bold));
                painter->drawText(QPoint(7,23),"1:  x = "+QString::number(ref_x-xs[0],'f',3)+"; y = "+QString::number(ref_y-ys[0],'f',3));
                painter->drawText(QPoint(7,43),"2:  x = "+QString::number(ref_x-xs[1],'f',3)+"; y = "+QString::number(ref_y-ys[1],'f',3));
                painter->drawText(QPoint(7,63),"3:  x = "+QString::number(ref_x-xs[2],'f',3)+"; y = "+QString::number(ref_y-ys[2],'f',3));
                painter->drawText(QPoint(7,83),"4:  x = "+QString::number(ref_x-xs[3],'f',3)+"; y = "+QString::number(ref_y-ys[3],'f',3));
                painter->drawText(QPoint(7,103),"R: x = "+QString::number(ref_x,'f',3)+"; y = "+QString::number(ref_y,'f',3));

                painter->setPen(QPen(Qt::black));
                painter->drawLine(7,87,200,87);

                if (active_marker==-1)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,102),2.5,2.5);
                }
                if (active_marker==0)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,18),2.5,2.5);
                }
                if (active_marker==1)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,39),2.5,2.5);
                }
                if (active_marker==2)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,60),2.5,2.5);
                }
                if (active_marker==3)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,81),2.5,2.5);
                }


            }
        }
        if (marker_list.size()==5)
        {
            if (reference_marker_mode==nonactive)
            {
                this->resize(150+lenght*3,112);
                painter->setRenderHint(QPainter::Antialiasing,true);
                painter->setBrush(QBrush(Qt::white));
                painter->setPen(QPen(Qt::black));
                painter->drawRoundedRect(QRect(0,0,150+lenght*3,110),6,6);
                painter->setFont(QFont("Helvetica [Cronyx]", 11, QFont::Bold));
                painter->drawText(QPoint(7,23),"1"+*marker_list[0]);
                painter->drawText(QPoint(7,43),"2"+*marker_list[1]);
                painter->drawText(QPoint(7,63),"3"+*marker_list[2]);
                painter->drawText(QPoint(7,83),"4"+*marker_list[3]);
                painter->drawText(QPoint(7,103),"5"+*marker_list[4]);
                if (active_marker==0)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,18),2.5,2.5);
                }
                if (active_marker==1)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,39),2.5,2.5);
                }
                if (active_marker==2)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,60),2.5,2.5);
                }
                if (active_marker==3)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,81),2.5,2.5);
                }
                if (active_marker==4)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,102),2.5,2.5);
                }


            }
            if (reference_marker_mode==active)
            {
                this->resize(150+lenght*3,132);
                painter->setRenderHint(QPainter::Antialiasing,true);
                painter->setBrush(QBrush(Qt::white));
                painter->setPen(QPen(Qt::black));
                painter->drawRoundedRect(QRect(0,0,150+lenght*3,130),6,6);
                painter->setFont(QFont("Helvetica [Cronyx]", 11, QFont::Bold));
                painter->drawText(QPoint(7,23),"1:  x = "+QString::number(ref_x-xs[0],'f',3)+"; y = "+QString::number(ref_y-ys[0],'f',3));
                painter->drawText(QPoint(7,43),"2:  x = "+QString::number(ref_x-xs[1],'f',3)+"; y = "+QString::number(ref_y-ys[1],'f',3));
                painter->drawText(QPoint(7,63),"3:  x = "+QString::number(ref_x-xs[2],'f',3)+"; y = "+QString::number(ref_y-ys[2],'f',3));
                painter->drawText(QPoint(7,83),"4:  x = "+QString::number(ref_x-xs[3],'f',3)+"; y = "+QString::number(ref_y-ys[3],'f',3));
                painter->drawText(QPoint(7,103),"5:  x = "+QString::number(ref_x-xs[4],'f',3)+"; y = "+QString::number(ref_y-ys[4],'f',3));
                painter->drawText(QPoint(7,123),"R: x = "+QString::number(ref_x,'f',3)+"; y = "+QString::number(ref_y,'f',3));

                painter->setPen(QPen(Qt::black));
                painter->drawLine(7,107,200,107);

                if (active_marker==-1)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,120),2.5,2.5);
                }
                if (active_marker==0)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,18),2.5,2.5);
                }
                if (active_marker==1)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,39),2.5,2.5);
                }
                if (active_marker==2)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,60),2.5,2.5);
                }
                if (active_marker==3)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,81),2.5,2.5);
                }
                if (active_marker==4)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,102),2.5,2.5);
                }


            }
        }
        if (marker_list.size()==6)
        {
            if (reference_marker_mode==nonactive)
            {
                this->resize(150+lenght*3,136);
                painter->setRenderHint(QPainter::Antialiasing,true);
                painter->setBrush(QBrush(Qt::white));
                painter->setPen(QPen(Qt::black));
                painter->drawRoundedRect(QRect(0,0,150+lenght*3,134),6,6);
                painter->setFont(QFont("Helvetica [Cronyx]", 11, QFont::Bold));
                painter->drawText(QPoint(7,23),"1"+*marker_list[0]);
                painter->drawText(QPoint(7,43),"2"+*marker_list[1]);
                painter->drawText(QPoint(7,63),"3"+*marker_list[2]);
                painter->drawText(QPoint(7,83),"4"+*marker_list[3]);
                painter->drawText(QPoint(7,103),"5"+*marker_list[4]);
                painter->drawText(QPoint(7,123),"6"+*marker_list[5]);
                if (active_marker==0)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,18),2.5,2.5);
                }
                if (active_marker==1)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,39),2.5,2.5);
                }
                if (active_marker==2)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,60),2.5,2.5);
                }
                if (active_marker==3)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,81),2.5,2.5);
                }
                if (active_marker==4)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,102),2.5,2.5);
                }
                if (active_marker==5)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,122),2.5,2.5);
                }

            }
            if (reference_marker_mode==active)
            {
                this->resize(150+lenght*3,151);
                painter->setRenderHint(QPainter::Antialiasing,true);
                painter->setBrush(QBrush(Qt::white));
                painter->setPen(QPen(Qt::black));
                painter->drawRoundedRect(QRect(0,0,150+lenght*3,149),6,6);
                painter->setFont(QFont("Helvetica [Cronyx]", 11, QFont::Bold));
                painter->drawText(QPoint(7,23),"1:  x = "+QString::number(ref_x-xs[0],'f',3)+"; y = "+QString::number(ref_y-ys[0],'f',3));
                painter->drawText(QPoint(7,43),"2:  x = "+QString::number(ref_x-xs[1],'f',3)+"; y = "+QString::number(ref_y-ys[1],'f',3));
                painter->drawText(QPoint(7,63),"3:  x = "+QString::number(ref_x-xs[2],'f',3)+"; y = "+QString::number(ref_y-ys[2],'f',3));
                painter->drawText(QPoint(7,83),"4:  x = "+QString::number(ref_x-xs[3],'f',3)+"; y = "+QString::number(ref_y-ys[3],'f',3));
                painter->drawText(QPoint(7,103),"5:  x = "+QString::number(ref_x-xs[4],'f',3)+"; y = "+QString::number(ref_y-ys[4],'f',3));
                painter->drawText(QPoint(7,123),"6:  x = "+QString::number(ref_x-xs[6],'f',3)+"; y = "+QString::number(ref_y-ys[6],'f',3));
                painter->drawText(QPoint(7,143),"R: x = "+QString::number(ref_x,'f',3)+"; y = "+QString::number(ref_y,'f',3));

                painter->setPen(QPen(Qt::black));
                painter->drawLine(7,127,200,127);

                if (active_marker==-1)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,140),2.5,2.5);
                }
                if (active_marker==0)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,18),2.5,2.5);
                }
                if (active_marker==1)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,39),2.5,2.5);
                }
                if (active_marker==2)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,60),2.5,2.5);
                }
                if (active_marker==3)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,81),2.5,2.5);
                }
                if (active_marker==4)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,102),2.5,2.5);
                }
                if (active_marker==5)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,120),2.5,2.5);
                }


            }
        }
        if (marker_list.size()==7)
        {
            if (reference_marker_mode==nonactive)
            {
                this->resize(150+lenght*3,154);
                painter->setRenderHint(QPainter::Antialiasing,true);
                painter->setBrush(QBrush(Qt::white));
                painter->setPen(QPen(Qt::black));
                painter->drawRoundedRect(QRect(0,0,150+lenght*3,152),6,6);
                painter->setFont(QFont("Helvetica [Cronyx]", 11, QFont::Bold));
                painter->drawText(QPoint(7,23),"1"+*marker_list[0]);
                painter->drawText(QPoint(7,43),"2"+*marker_list[1]);
                painter->drawText(QPoint(7,63),"3"+*marker_list[2]);
                painter->drawText(QPoint(7,83),"4"+*marker_list[3]);
                painter->drawText(QPoint(7,103),"5"+*marker_list[4]);
                painter->drawText(QPoint(7,123),"6"+*marker_list[5]);
                painter->drawText(QPoint(7,143),"7"+*marker_list[6]);
                if (active_marker==0)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,18),2.5,2.5);
                }
                if (active_marker==1)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,39),2.5,2.5);
                }
                if (active_marker==2)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,60),2.5,2.5);
                }
                if (active_marker==3)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,81),2.5,2.5);
                }
                if (active_marker==4)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,102),2.5,2.5);
                }
                if (active_marker==5)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,122),2.5,2.5);
                }
                if (active_marker==6)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,142),2.5,2.5);
                }

            }
            if (reference_marker_mode==active)
            {
                this->resize(150+lenght*3,181);
                painter->setRenderHint(QPainter::Antialiasing,true);
                painter->setBrush(QBrush(Qt::white));
                painter->setPen(QPen(Qt::black));
                painter->drawRoundedRect(QRect(0,0,150+lenght*3,179),6,6);
                painter->setFont(QFont("Helvetica [Cronyx]", 11, QFont::Bold));
                painter->drawText(QPoint(7,23),"1:  x = "+QString::number(ref_x-xs[0],'f',3)+"; y = "+QString::number(ref_y-ys[0],'f',3));
                painter->drawText(QPoint(7,43),"2:  x = "+QString::number(ref_x-xs[1],'f',3)+"; y = "+QString::number(ref_y-ys[1],'f',3));
                painter->drawText(QPoint(7,63),"3:  x = "+QString::number(ref_x-xs[2],'f',3)+"; y = "+QString::number(ref_y-ys[2],'f',3));
                painter->drawText(QPoint(7,83),"4:  x = "+QString::number(ref_x-xs[3],'f',3)+"; y = "+QString::number(ref_y-ys[3],'f',3));
                painter->drawText(QPoint(7,103),"5:  x = "+QString::number(ref_x-xs[4],'f',3)+"; y = "+QString::number(ref_y-ys[4],'f',3));
                painter->drawText(QPoint(7,123),"6:  x = "+QString::number(ref_x-xs[6],'f',3)+"; y = "+QString::number(ref_y-ys[6],'f',3));
                painter->drawText(QPoint(7,143),"6:  x = "+QString::number(ref_x-xs[7],'f',3)+"; y = "+QString::number(ref_y-ys[7],'f',3));
                painter->drawText(QPoint(7,163),"R: x = "+QString::number(ref_x,'f',3)+"; y = "+QString::number(ref_y,'f',3));

                painter->setPen(QPen(Qt::black));
                painter->drawLine(7,147,200,147);

                if (active_marker==-1)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,160),2.5,2.5);
                }
                if (active_marker==0)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,18),2.5,2.5);
                }
                if (active_marker==1)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,39),2.5,2.5);
                }
                if (active_marker==2)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,60),2.5,2.5);
                }
                if (active_marker==3)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,81),2.5,2.5);
                }
                if (active_marker==4)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,102),2.5,2.5);
                }
                if (active_marker==5)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,120),2.5,2.5);
                }
                if (active_marker==6)
                {
                    QPen pen10(Qt::green, 5,Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin);
                    painter->setPen(pen10);
                    painter->drawEllipse(QPoint(140+lenght*3,140),2.5,2.5);
                }


            }
        }


    }
}

bool MyMarker::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        if (reference_marker_mode==active)
        {
            if (((((QMouseEvent*)event)->pos().y()>0) &&  ((((QMouseEvent*)event)->pos().y()<33))))
            {
                active_marker=0;
            }
            if (((((QMouseEvent*)event)->pos().y()>33) &&  ((((QMouseEvent*)event)->pos().y()<53))))
            {
                active_marker=1;
            }
            if (((((QMouseEvent*)event)->pos().y()>53) &&  ((((QMouseEvent*)event)->pos().y()<81))))
            {
                active_marker=2;
            }
            if (((((QMouseEvent*)event)->pos().y()>81) &&  ((((QMouseEvent*)event)->pos().y()<101))))
            {
                active_marker=3;
            }
            if (((((QMouseEvent*)event)->pos().y()>101) &&  ((((QMouseEvent*)event)->pos().y()<121))))
            {
                active_marker=4;
            }
            if (((((QMouseEvent*)event)->pos().y()>121) &&  ((((QMouseEvent*)event)->pos().y()<141))))
            {
                active_marker=5;
            }
            if (((((QMouseEvent*)event)->pos().y()>141) &&  ((((QMouseEvent*)event)->pos().y()<161))))
            {
                active_marker=6;
            }
            emit enable_delete_button(true);
        }

        if (reference_marker_mode==nonactive)
        {
            if (((((QMouseEvent*)event)->pos().y()>0) &&  ((((QMouseEvent*)event)->pos().y()<33))))
            {
                active_marker=0;
            }
            if (((((QMouseEvent*)event)->pos().y()>33) &&  ((((QMouseEvent*)event)->pos().y()<53))))
            {
                active_marker=1;
            }
            if (((((QMouseEvent*)event)->pos().y()>53) &&  ((((QMouseEvent*)event)->pos().y()<76))))
            {
                active_marker=2;
            }
            if (((((QMouseEvent*)event)->pos().y()>76) &&  ((((QMouseEvent*)event)->pos().y()<92))))
            {
                active_marker=3;
            }
            if (((((QMouseEvent*)event)->pos().y()>92) &&  ((((QMouseEvent*)event)->pos().y()<114))))
            {
                active_marker=4;
            }
            if (((((QMouseEvent*)event)->pos().y()>114) &&  ((((QMouseEvent*)event)->pos().y()<131))))
            {
                active_marker=5;
            }
            if (((((QMouseEvent*)event)->pos().y()>131) &&  ((((QMouseEvent*)event)->pos().y()<161))))
            {
                active_marker=6;
            }
        }
        this->repaint();
    }
    return false;
}
void MyMarker::set_enable_delete_button(bool a)
{
    emit enable_delete_button(a);
}

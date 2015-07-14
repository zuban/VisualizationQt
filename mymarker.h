#ifndef MYMARKER_H
#define MYMARKER_H

#include <QWidget>
#include "QList"

class MyMarker : public QWidget
{
    Q_OBJECT
public:
    explicit MyMarker(QWidget *parent);
    enum Reference_Marker_Mode{active,nonactive};
    Reference_Marker_Mode reference_marker_mode;
    const static int nGraphsMax=7;
    double xs[nGraphsMax];
    double ys[nGraphsMax];
    double ref_x;
    double ref_y;
    int active_marker;//считаем с нуля //-1 is for reference marker
    int markers_count;
    QList <QString*> marker_list;
    int get_string_lenght();
    void set_enable_delete_button(bool a);
signals:
      void enable_delete_button(bool a);
private:
     bool eventFilter(QObject *object, QEvent *event);
    void draw( QPainter  *painter);
    QString mystring;
protected:
     void paintEvent(QPaintEvent *);

    
public slots:
    
};

#endif // MYMARKER_H

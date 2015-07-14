#ifndef COLORALPHAMAP_H
#define COLORALPHAMAP_H

class ColorAlphamap : public QwtAlphaColorMap
{
public:
    ColorAlphamap():
        QwtAlphaColorMap(Qt::red)
    {
    }
};

#endif // COLORALPHAMAP_H

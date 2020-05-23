#ifndef PRINTER_ICON_H
#define PRINTER_ICON_H
#include "QPixmap"
#include "QPoint"

class printer_icon
{
public:
    QPixmap img;
    QPoint pos;
    double scale;
    printer_icon();
    printer_icon(QPixmap _img, QPoint _pos, double _scale);
};

#endif // PRINTER_ICON_H

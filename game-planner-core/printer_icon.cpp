#include "printer_icon.h"

printer_icon::printer_icon()
{
    pos = QPointF(0,0);
    scale = 1;
}

printer_icon::printer_icon(QPixmap _img)
{
    img = _img;
    pos = QPointF(0,0);
    scale = 1;
}

printer_icon::printer_icon(QPixmap _img, QPoint _pos, double _scale)
{
    img = _img;
    pos = _pos;
    scale = _scale;
}

void printer_icon::setPos(QPointF _pos){
    pos=_pos;
}

void printer_icon::setScale(double _scale){
    scale = _scale;
}

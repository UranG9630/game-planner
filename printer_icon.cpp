#include "printer_icon.h"

printer_icon::printer_icon()
{
    pos = QPoint(0,0);
}

printer_icon::printer_icon(QPixmap _img, QPoint _pos, double _scale)
{
    img = _img;
    pos = _pos;
    scale = _scale;
}

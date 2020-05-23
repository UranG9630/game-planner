#ifndef PRINTER_CORE_H
#define PRINTER_CORE_H
#include <initializer_list>
#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <printer_icon.h>

class printer_core
{

public:
    printer_icon* lista_ikon;
    int count;
    printer_core();
    printer_core(printer_icon* _lista_ikon);
    void print_icons(QPixmap* cel);
    void set_icons(printer_icon* _lista_ikon);
};

#endif // PRINTER_CORE_H

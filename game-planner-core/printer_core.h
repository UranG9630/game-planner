#ifndef PRINTER_CORE_H
#define PRINTER_CORE_H
#include <initializer_list>
#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVector>
#include <QDebug>

#include <printer_icon.h>

class printer_core
{

public:
    printer_icon* lista_ikon;
    QVector<printer_icon> lista_ikonV;
    int count;
    printer_core();
    printer_core(printer_icon* _lista_ikon);
    void print_icons(QPixmap* cel);
    void print_icons(QPixmap* cel, printer_icon* _lista_ikon);
    void set_icons(printer_icon* _lista_ikon);

    void print_iconsV(QPixmap* cel);
    void print_iconsV(QPixmap* cel, QVector<printer_icon> _lista_ikonV);
    void set_iconsV(QVector<printer_icon> _lista_ikonV);

    //QPixmap setOpacity(QPixmap pix, double opacity);
};

#endif // PRINTER_CORE_H

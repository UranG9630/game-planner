#include "printer_core.h"

printer_core::printer_core()
{
    count = 0;
    lista_ikon = nullptr;
}

printer_core::printer_core(printer_icon* _lista_ikon){
    lista_ikon = _lista_ikon;
    count = sizeof(printer_icon) / sizeof(_lista_ikon);
}

void printer_core::print_icons(QPixmap* cel){
    QPainter *paint = new QPainter(cel);
    QPixmap pix;
    double scale;
    for(int i=0;i<count;i++){
        pix = lista_ikon[i].img;
        scale = lista_ikon[i].scale;
        paint->drawPixmap(lista_ikon[i].pos,pix.scaled(pix.width()*scale,pix.height()*scale));
    }
    delete paint;
}

void printer_core::print_icons(QPixmap* cel, printer_icon* _lista_ikon){
    int tcount = sizeof(printer_icon) / sizeof(_lista_ikon);
    QPainter *paint = new QPainter(cel);
    QPixmap pix;
    double scale;
    for(int i=0;i<tcount;i++){
        pix = _lista_ikon[i].img;
        scale = _lista_ikon[i].scale;
        paint->drawPixmap(_lista_ikon[i].pos,pix.scaled(pix.width()*scale,pix.height()*scale));
    }
    delete paint;
}

void printer_core::set_icons(printer_icon* _lista_ikon){
    lista_ikon = _lista_ikon;
}

void printer_core::print_iconsV(QPixmap* cel){
    QPainter *paint = new QPainter(cel);
    QPixmap pix;
    double scale;
    for(int i=0;i<count;i++){
        pix = lista_ikonV[i].img;
        scale = lista_ikonV[i].scale;
        paint->drawPixmap(lista_ikonV[i].pos,pix.scaled(pix.width()*scale,pix.height()*scale));
    }
    delete paint;
}
void printer_core::print_iconsV(QPixmap* cel, QVector<printer_icon> _lista_ikonV){
    int tcount = _lista_ikonV.size();
    QPainter *paint = new QPainter(cel);
    QPixmap pix;
    double scale;
    for(int i=0;i<tcount;i++){
        pix = _lista_ikonV[i].img;
        scale = _lista_ikonV[i].scale;
        //paint->drawPixmap(_lista_ikonV[i].pos,pix.scaled(pix.width()*scale,pix.height()*scale));
        paint->drawPixmap(_lista_ikonV[i].pos,pix);
    }
    qDebug() << "printed" << _lista_ikonV[0].pos;
    delete paint;
}
void printer_core::set_iconsV(QVector<printer_icon> _lista_ikonV){
    lista_ikonV = _lista_ikonV;
}



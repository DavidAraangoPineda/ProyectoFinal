#include <QTimer>
#include <QGraphicsScene>

#include <resort.h>
#include "bullet.h"
#include "Game.h"



resort::resort(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){

     setPixmap(QPixmap(":/imagenes/imagenes/resorte.png"));
     //dibujar la bala
     QBrush brush;
    brush.setStyle(Qt::SolidPattern);
     brush.setColor(Qt::red);
     resort_hitbox = new QGraphicsRectItem(0, 0, 50, 10, this);//(comienza desde,baja o sube tanto, Ancho, Altura, this)
     //resort_hitbox->setBrush(brush);
     resort_hitbox->setPen(Qt::NoPen);

}


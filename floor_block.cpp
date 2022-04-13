#include "floor_block.h"

Floor_Block::Floor_Block(qreal x, qreal y, bool terrain, QGraphicsItem * parent): QGraphicsPixmapItem(parent)
{
    setZValue(10);
    if(!terrain){
        setPixmap(QPixmap(":/imagenes/descarga.jpg"));
    }else {
        setPixmap(QPixmap(":/imagenes/descarga.jpg"));
    }

//    box = new QGraphicsRectItem

    setPos(x, y);
}

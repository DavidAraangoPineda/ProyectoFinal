#include "floor_block.h"

Floor_Block::Floor_Block(qreal x, qreal y, bool terrain, QGraphicsItem * parent): QGraphicsPixmapItem(parent)
{
    setZValue(10);
    if(!terrain){
        setPixmap(QPixmap(":/sprites/blocks/brick_normal.png"));
    }else {
        setPixmap(QPixmap(":/sprites/blocks/brick_normal.png"));
    }

//    box = new QGraphicsRectItem

    setPos(x, y);
}

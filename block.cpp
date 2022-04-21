#include "block.h"
#include <QBrush>
#include "Game.h"
//block::block(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
block::block(QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    setBrush(brush);

}


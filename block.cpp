#include "block.h"
#include <QBrush>
//block::block(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
block::block(QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    //block->setPos()
    QBrush brush;
    brush.setStyle(Qt::Dense2Pattern);
    brush.setColor(Qt::gray);
    setBrush(brush);
}

//void block::setNivel(int nivel)
//{
//    block_size = size;

//    switch (size) {
//    case 1:
//        setPos(x(), y());
//        break;
//    case 2:
//        //setPos(x(), y()-pixmap().height()+32);
//        break;
//    case 3:
//        //setPos(x(), y()-pixmap().height());
//        break;
//    }
//}



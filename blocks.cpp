#include "blocks.h"

blocks::blocks(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/imagenes/descarga.jpg"));
    setZValue(-1);
}

void blocks::setSize(int size)
{
    block_size = size;

    switch (size) {
    case 1:
        setPos(x(), y()-64);
        break;
    case 2:
        setPos(x(), y()-pixmap().height()+32);
        break;
    case 3:
        setPos(x(), y()-pixmap().height());
        break;
    }
}



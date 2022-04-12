#ifndef BLOCKS_H
#define BLOCKS_H
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QDebug>

class blocks: public QObject, public QGraphicsPixmapItem
{
public:
    blocks(QGraphicsItem * parent = 0);


    void setSize(int size);
private:
    int block_size = 3;

};

#endif // BLOCKS_H


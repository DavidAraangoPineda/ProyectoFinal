#ifndef BLOCK_H
#define BLOCK_H
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QDebug>
#include <QGraphicsRectItem>
class block: public QObject, public QGraphicsRectItem
// block: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    block(QGraphicsItem * parent = 0);


    //void setSize(int size);
private:
    //int block_size = 3;

};

#endif // BLOCK_H


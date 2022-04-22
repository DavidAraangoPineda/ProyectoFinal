#ifndef RESORT_H
#define RESORT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "bullet.h"

class resort: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT

public:
    resort(QGraphicsItem * parent = 0);
    //bullet *Bullet;

public slots:

private:

        QGraphicsRectItem * resort_hitbox;

};






#endif // RESORT_H

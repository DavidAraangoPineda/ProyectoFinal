#ifndef DOOR_H
#define DOOR_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QImage>
#include <QGraphicsRectItem>
#include <QBrush>

class door:public QObject, public QGraphicsPixmapItem{

public:
    door(QGraphicsItem *parent = 0);

public slots:

    void update();

private:

    QGraphicsRectItem * door_center;

    //QTimer *timer;
};

#endif // DOOR_H


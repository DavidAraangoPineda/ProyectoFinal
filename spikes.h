#ifndef SPIKES_H
#define SPIKES_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QImage>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QBrush>
class spikes:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    spikes(QGraphicsItem *parent = 0);
    //void colliding_player();
    //void move_fall_block();

public slots:

    //void update();


private:

    QGraphicsRectItem * spikes_bottom;
    QGraphicsRectItem * spikes_top;
    QGraphicsRectItem * spikes_right;
    QGraphicsRectItem * spikes_left;
    //QTimer *timer;
};

#endif // SPIKES_H


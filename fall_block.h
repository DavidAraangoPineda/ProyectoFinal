#ifndef FALL_BLOCK_H
#define FALL_BLOCK_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QImage>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QBrush>
//class fall_block:public QObject, public QGraphicsRectItem{
class fall_block:public QObject, public QGraphicsPixmapItem{
        Q_OBJECT
public:
    fall_block(QGraphicsItem *parent = 0);
    void colliding_player();
    void move_fall_block();

public slots:

    void update();


private:
    float velY = 0;

    bool isCollidingRight = false;
    bool isCollidingLeft = false;
    bool isCollidingBottom = false;
    bool isCollidingTop = false;

    bool isCollidingRightPlayer = false;
    bool isCollidingLeftPlayer = false;
    bool isCollidingBottomPlayer = false;
    bool isCollidingTopPlayer = false;

    bool stopGravity = false;

    QGraphicsRectItem * fall_block_bottom;
    QGraphicsRectItem * fall_block_top;
    QGraphicsRectItem * fall_block_right;
    QGraphicsRectItem * fall_block_left;

    QTimer *timer;
};

#endif // FALL_BLOCK_H

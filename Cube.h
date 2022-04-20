#ifndef CUBE_H
#define CUBE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QImage>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QBrush>
//class Cube: public QObject, public QGraphicsRectItem{
class Cube: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Cube(QGraphicsItem *parent = 0);
    void colliding_block();
    void moveCube();


public slots:

    void update();


private:


    float accl = 0.10;
    float maxSpeed = 1.8;
    float gravityMaxSpeed = 3;
    float velX = 0;
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

    QGraphicsRectItem * cube_bottom;
    QGraphicsRectItem * cube_top;
    QGraphicsRectItem * cube_right;
    QGraphicsRectItem * cube_left;

    QTimer *timer;
};

#endif // CUBE_H

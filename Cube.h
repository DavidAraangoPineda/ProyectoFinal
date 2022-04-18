#ifndef CUBE_H
#define CUBE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QImage>
#include <QGraphicsRectItem>
#include <QTimer>

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
    float jumpCounterMax = 20;
    float jumpCounter = 0;
    float gravityMaxSpeed = 3;
    float velX = 0;
    float velY = 0;
    bool isMovingRight=false;
    bool isMovingLeft=false;
    bool isJumping=false;
    bool isCollidingRight = false;
    bool isCollidingLeft = false;
    bool isCollidingBottom = false;
    bool isCollidingTop = false;
    bool isMidJump = false;
    bool stopControls = false;
    bool stopGravity = false;

    QGraphicsRectItem * cube_bottom;
    QGraphicsRectItem * cube_top;
    QGraphicsRectItem * cube_right;
    QGraphicsRectItem * cube_left;

    QTimer *timer;
};

#endif // CUBE_H

#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QImage>
#include <QGraphicsRectItem>

//class Player: public QObject, public QGraphicsPixmapItem,public QGraphicsRectItem{
class Player: public QObject, public QGraphicsRectItem{
    Q_OBJECT

public:
    Player(QGraphicsItem *parent = 0);

    void keyPressEvent(QKeyEvent * event) override;
    void keyReleaseEvent(QKeyEvent * event) override;
    void colliding_block();
    void update();
public slots:
    void movePlayer();
    void movePlayer2();

private:
    float accl = 2;
    float maxSpeed = 3;
    float jumpCounterMax = 40;
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
    QGraphicsRectItem * player_bottom;
    QGraphicsRectItem * player_top;
    QGraphicsRectItem * player_right;
    QGraphicsRectItem * player_left;

};

#endif // PLAYER_H

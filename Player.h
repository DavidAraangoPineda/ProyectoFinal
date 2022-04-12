#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>


class Player: public QObject, public QGraphicsRectItem{
    Q_OBJECT

public:
    Player(QGraphicsItem *parent = 0);
    void keyPressEvent(QKeyEvent * event) override;
    void keyReleaseEvent(QKeyEvent * event) override;
public slots:
    void movePlayer();
private:
    float accl = 1;
    float maxSpeed = 10;
    float jumpCounterMax = 40;
    float jumpCounter = 0;
    float gravityMaxSpeed = 3;
    float velX = 0;
    float velY = 0;

    bool isMovingRight=false;
    bool isMovingLeft=false;
    bool isJumping=false;
    bool isCollidingBottom=false;
};

#endif // PLAYER_H

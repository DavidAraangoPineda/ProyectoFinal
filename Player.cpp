#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <Game.h>
#include <iostream>


Player::Player(QGraphicsItem *parent)
{
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(movePlayer()));
     //start the timer
    timer->start(50);
}
void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
        isMovingLeft = true;

    if (event->key() == Qt::Key_Right)
        isMovingRight = true;

    if (event->key() == Qt::Key_Up)
        isJumping = true;
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
        isMovingLeft = false;

    if (event->key() == Qt::Key_Right )
        isMovingRight = false;

    if (event->key() == Qt::Key_Up)
        isJumping = false;
}

void Player::movePlayer()
{
    if (isMovingLeft){
        velX += ((-1 * maxSpeed) - velX) * accl;
    }

    if (isMovingRight)
    {
        velX += ((1 * maxSpeed) - velX) * accl;
    }

    if (!isMovingLeft && !isMovingRight)
    {
        velX *= 0.9;
    }

    if (!isMovingLeft && !isMovingRight && velX > -0.005 && velX < 0.005){
        velX = 0;
    }

    if (isJumping && jumpCounter < jumpCounterMax)
    {
        velY = -5;
        jumpCounter++;
    }
    else if (!isJumping && jumpCounter > 0)
    {
        jumpCounter = jumpCounterMax;
    }
    if (!isCollidingBottom && velY < gravityMaxSpeed)
    {
        velY += 0.15;
    }

//    if (pos().y()+rect().height()>scene()->height())
//    {
//        isCollidingBottom=true;
//    }

    setPos(x() + velX, y() + velY);
}







#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QDebug>
#include <QList>
#include <QProcess>
#include <iostream>
#include "Player.h"
#include <block.h>
#include <Game.h>

Player::Player(QGraphicsItem *parent)
{

    setPixmap(QPixmap(":/imagenes/player.png"));

    player_left = new QGraphicsRectItem(0, 1, 2, 30, this);
    player_right = new QGraphicsRectItem(30, 1, 2, 30, this);
    player_top = new QGraphicsRectItem(4, -1, 24, 1, this);
    player_bottom = new QGraphicsRectItem(4, 32, 24, 1, this);

//    player_left->setPen(Qt::NoPen);
//    player_right->setPen(Qt::NoPen);
//    player_top->setPen(Qt::NoPen);
//    player_bottom->setPen(Qt::NoPen);


//    player_left -> setRect(0, 1, 2, 30);
//    player_right -> setRect(30, 1, 2, 30);
//    player_top ->  setRect(4, -1, 24, 1);
//    player_bottom ->  setRect(4, 32, 24, 1);

    timer = new QTimer(this);
   // QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(20);
}

void Player::update(){

    colliding_block();
    movePlayer();

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
    if(stopGravity)
        return;


    if (isMovingLeft){
        velX += ((-1 * maxSpeed) - velX) * accl;
    }

    if (isMovingRight)
    {
        velX += ((1 * maxSpeed) - velX) * accl;
    }

    if (!isMovingLeft && !isMovingRight)
        velX *= 0.9;

    if (!isMovingLeft && !isMovingRight && velX > -0.005 && velX < 0.005)
        velX = 0;

    if (isJumping && jumpCounter < jumpCounterMax)
    {
        velY = -3;
        jumpCounter++;
        isMidJump = true;
    }
    else if (!isJumping && jumpCounter > 0)
    {
        jumpCounter = jumpCounterMax;
        isMidJump = false;
    }

    if (!isCollidingBottom && velY < gravityMaxSpeed)
    {
        velY += 0.15;
        if (!isMidJump)
            jumpCounter = jumpCounterMax;
    }

    if (isCollidingLeft && velX < 0)
        velX = 0;

    if (isCollidingRight && velX > 0)
        velX = 0;

    if (isCollidingBottom && velY > 0)
        velY = 0;

    if (isCollidingTop && velY < 0)
        velY = 0;


    setPos(x() + velX, y() + velY);
    //std::cout<<"Velocidad en X es: "<<velX<<"\n"<<"Velocidad en Y es: "<<velY;
}

void Player::colliding_block()
{
    if(stopGravity){return;}


    if (player_bottom->collidingItems().size() > 0)
    {
        for (QGraphicsItem *colliding_item : player_bottom->collidingItems())
        {
            if (typeid(*colliding_item) == typeid(block)||typeid(*colliding_item) == typeid(Cube))
            {
                isCollidingBottom = true;
                if (typeid(*colliding_item) == typeid(block)){
                    if (colliding_item->y() != y() + pixmap().height())
                        setPos(x(), colliding_item->y() - pixmap().height());}



                if (!isJumping)
                    jumpCounter = 0;
            }
            else
            {
                isCollidingBottom = false;
            }
        }
    }
    else
    {
        isCollidingBottom = false;
    }

    if (player_top->collidingItems().size() > 0)
    {
        for (QGraphicsItem *colliding_item : player_top->collidingItems())
        {
            if (typeid(*colliding_item) == typeid(block))
            {
                isCollidingTop = true;
                if (isMidJump)
                    jumpCounter = jumpCounterMax;
            }
            else
            {
                isCollidingTop = false;
            }
        }
    }
    else
    {
        isCollidingTop = false;
    }


    if (player_right->collidingItems().size() > 0)
    {
        for (QGraphicsItem *colliding_item : player_right->collidingItems())
        {
            if (typeid(*colliding_item) == typeid(block))
            {
                isCollidingRight = true;
            }
            else
            {
                isCollidingRight = false;
            }
        }
    }
    else
    {
        isCollidingRight = false;
    }

    if (player_left->collidingItems().size() > 0)
    {
        for (QGraphicsItem *colliding_item : player_left->collidingItems())
        {
            if (typeid(*colliding_item) == typeid(block))
            {
                isCollidingLeft = true;
            }
            else
            {
                isCollidingLeft = false;
            }
        }
    }
    else
    {
        isCollidingLeft = false;
    }

    }


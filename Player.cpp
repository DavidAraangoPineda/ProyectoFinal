#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QList>
#include <QProcess>
#include <iostream>
#include <stdlib.h> // rand() -> really large int
#include "Player.h"
#include <block.h>
#include <spikes.h>
#include <fall_block.h>
#include <bullet.h>
#include <resort.h>
#include <Game.h>

//extern fall_block *Fall_block;
extern Game *game; // llamar una variable externa para interactuar con ella

Player::Player(QGraphicsItem *parent)
{


    //setPixmap(QPixmap(":/imagenes/imagenes/player_quiet.png"));


    player_left = new QGraphicsRectItem(0, 1, 2, 30, this);
    player_right = new QGraphicsRectItem(30, 1, 2, 30, this);
    player_top = new QGraphicsRectItem(4, -1, 24, 1, this);
    player_bottom = new QGraphicsRectItem(4, 32, 24, 1, this);

    player_left->setPen(Qt::NoPen);
    player_right->setPen(Qt::NoPen);
    player_top->setPen(Qt::NoPen);
    player_bottom->setPen(Qt::NoPen);


//    player_left -> setRect(0, 1, 2, 30);
//    player_right -> setRect(30, 1, 2, 30);
//    player_top ->  setRect(4, -1, 24, 1);
//    player_bottom ->  setRect(4, 32, 24, 1);

    timer = new QTimer(this);
   // QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(15);
}

void Player::update(){

    colliding_block();
    movePlayer();
 //   dying();

}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        isMovingLeft = true;
        setPixmap(QPixmap(":/imagenes/imagenes/player_izq.png"));}

    if (event->key() == Qt::Key_Right){
        isMovingRight = true;
        setPixmap(QPixmap(":/imagenes/imagenes/player_der.png"));}

    if (event->key() == Qt::Key_Up){
        isJumping = true;
        setPixmap(QPixmap(":/imagenes/imagenes/player_up.png"));}
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

    if (velY>0){setPixmap(QPixmap(":/imagenes/imagenes/player_down.png"));}
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
        velY += 0.2;
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
            if (typeid(*colliding_item) == typeid(block)||
                typeid(*colliding_item) == typeid(Cube)||
                typeid(*colliding_item) == typeid(fall_block))
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
            if (typeid(*colliding_item) == typeid(block)||
                    typeid(*colliding_item) == typeid(fall_block))
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
            if (typeid(*colliding_item) == typeid(block)||
                    typeid(*colliding_item) == typeid(fall_block))
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
            if (typeid(*colliding_item) == typeid(block)||
                    typeid(*colliding_item) == typeid(fall_block))
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

    if (player_bottom->collidingItems().size() > 0||
            player_top->collidingItems().size() > 0||
            player_left->collidingItems().size() > 0||
            player_right->collidingItems().size() > 0)
    {
        for (QGraphicsItem *colliding_item : player_bottom->collidingItems())
        {
            if (typeid(*colliding_item) == typeid(spikes)||
                    typeid(*colliding_item) == typeid(bullet))
            {
                isDead = true;
            }
            if (typeid(*colliding_item) == typeid(door))
            {
                next_level = true;
            }

        }
        for (QGraphicsItem *colliding_item : player_top->collidingItems())
        {
            if (typeid(*colliding_item) == typeid(spikes)||
                    typeid(*colliding_item) == typeid(bullet))
            {
                isDead = true;
            }
            if (typeid(*colliding_item) == typeid(door))
            {
                next_level = true;
            }

        }
        for (QGraphicsItem *colliding_item : player_left->collidingItems())
        {
            if (typeid(*colliding_item) == typeid(spikes)||
                    typeid(*colliding_item) == typeid(bullet))
            {
                isDead = true;
            }
            if (typeid(*colliding_item) == typeid(door))
            {
                next_level = true;
            }

        }
        for (QGraphicsItem *colliding_item : player_right->collidingItems())
        {
            if (typeid(*colliding_item) == typeid(spikes)||
                    typeid(*colliding_item) == typeid(bullet))
            {
                isDead = true;
            }
            if (typeid(*colliding_item) == typeid(door))
            {
                next_level = true;
            }

        }
        for (QGraphicsItem *colliding_item : player_bottom->collidingItems())
        {
            if (typeid(*colliding_item) == typeid(resort))
            {
                velY=velY*-2;
            }

        }
    }


    if (pixmap().height()+pos().y() >scene()->height()){isDead=true;}

    if(isDead){
        isDead=false;
        game->load_level();
    }
    if(next_level){
        next_level=false;
        game->load_next_level();
       // game->string_a_txt();
        //deadMusic->play();

    }


}


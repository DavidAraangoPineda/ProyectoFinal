#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <iostream>
#include <QList>
#include "Player.h"
#include <block.h>
#include <Game.h>


Player::Player(QGraphicsItem *parent)
{
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(movePlayer2()));
     //start the timer
    timer->start(20);
}
void Player::update(){

    movePlayer();
    //colliding_block();
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
    if (isCollidingBottom==false && velY < gravityMaxSpeed)
    {
        velY += 0.15;
    }
    if (isCollidingBottom==true)
    {
        velY = 0;
    }

//    if (pos().y()+rect().height()>scene()->height())
//    {

//    }

    setPos(x() + velX, y() + velY);
    QList <QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n=colliding_items.size();i<n;++i){
        if(typeid(*(colliding_items[i]))==typeid (block)){
            isCollidingBottom=true;
            //std::cout<<"adadada";

        }
    }
}
void Player::movePlayer2()
{
        isCollidingBottom=false;

    QList <QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n=colliding_items.size();i<n;++i)
    {
        if(typeid(*(colliding_items[i]))==typeid (block)){
            isCollidingBottom=true;}
    }

    if (isMovingLeft){
        velX += ((-1 * maxSpeed) - velX) * accl;
    }

    if (isMovingRight)
    {
        velX += ((1 * maxSpeed) - velX) * accl;
    }

    if (isMovingLeft==false && isMovingRight==false)
    {
        velX *= 0.7;
    }

    if (!isMovingLeft && !isMovingRight && velX > -0.005 && velX < 0.005){
        velX = 0;
    }

    if (isJumping && jumpCounter < jumpCounterMax)
    {
        velY = -3;
        jumpCounter++;
    }
    if (isCollidingBottom==false)
    {
        velY += 0.5;
    }

    if (isCollidingBottom==true&&isJumping)
    {
        velY -= 10;
       // std::cout<<"saltandoooo";
    }
    if (isCollidingBottom==true&&velY>0)
    {
        velY = 0;
    }
setPos(x() + velX, y() + velY);


        //else{isCollidingBottom=false;std::cout<<"Cayendo"<<std::endl;}




}

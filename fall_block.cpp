#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QDebug>
#include <QList>
#include <QProcess>
#include <Cube.h>
#include <block.h>
#include <iostream>
#include <Game.h>
#include <Player.h>
#include <QBrush>
#include "fall_block.h"

fall_block::fall_block(QGraphicsItem *parent)
{
    //setPixmap(QPixmap(":/imagenes/bloque.jpg"));
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    fall_block_left = new QGraphicsRectItem(-2, 10, 5, 15, this);
    fall_block_right = new QGraphicsRectItem(32, 10, 2,15, this);
    fall_block_top = new QGraphicsRectItem(4, -1, 24, 1, this);
    fall_block_bottom = new QGraphicsRectItem(4, 32, 24, 1, this);//(Posicion inicial de x, 32, Ancho, Altura, this)

    //    fall_block_left->setBrush(brush);
    //    fall_block_right->setBrush(brush);
    //    fall_block_top->setBrush(brush);
    //    fall_block_bottom->setBrush(brush);
        fall_block_left->setPen(Qt::NoPen);
        fall_block_right->setPen(Qt::NoPen);
        fall_block_top->setPen(Qt::NoPen);
        fall_block_bottom->setPen(Qt::NoPen);

        timer = new QTimer(this);
       // QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(update()));
        timer->start(20);
}


void fall_block::update(){

    colliding_player();
    move_fall_block();

}

void fall_block::move_fall_block()
{

    if (!isCollidingBottom)
    {
        velY += 0.15;
    }



    if ((isCollidingLeft && velX < 0) || (!isCollidingLeftPlayer))
        velX = 0;

    if ((isCollidingRight )||(!isCollidingRightPlayer))
        velX = 0;

    if (isCollidingBottom && velY > 0)
        velY = 0;

    if (isCollidingTop && velY < 0)
        velY = 0;

    if (isCollidingLeftPlayer&&(isCollidingRight==false)){
        velX = 1*maxSpeed;}

    if (isCollidingRightPlayer&&(isCollidingLeft==false)){
        //std::cout<<"Aaaaa"<<std::endl;
        velX =-1*maxSpeed;}




    setPos(x() + velX, y() + velY);
    //std::cout<<"Izquierda"<<isCollidingLeft<<"\n";
}

void fall_block::colliding_player()
{
    if(stopGravity){return;}


    if (fall_block_bottom->collidingItems().size() > 0)
    {
        for (QGraphicsItem *colliding_item : fall_block_bottom->collidingItems())
        {
            if (typeid(*colliding_item) == typeid(Cube)||
                typeid(*colliding_item) == typeid(block))
            {
                isCollidingBottom = true;
            }
            else
            {
                isCollidingBottom = false;
            }
        }
    }
    if (fall_block_top->collidingItems().size() > 0)
    {
        for (QGraphicsItem *colliding_item : fall_block_top->collidingItems())
        {
            if (typeid(*colliding_item) == typeid(Cube)||
                typeid(*colliding_item) == typeid(block))
            {
                isCollidingTop = true;
            }
            else
            {
                isCollidingTop = false;
            }
        }
    }
    if (fall_block_right->collidingItems().size() > 0)
    {
        for (QGraphicsItem *colliding_item : fall_block_right->collidingItems())
        {
            if (
                typeid(*colliding_item) == typeid(block))
            {
                isCollidingRight = true;
                //std::cout<<"Izquierda"<<std::endl;
            }
            else
            {
                isCollidingRight = false;
            }
        }
    }
    if (fall_block_left->collidingItems().size() > 0)
    {
        for (QGraphicsItem *colliding_item : fall_block_left->collidingItems())
        {
            if (typeid(*colliding_item) == typeid(block))
            {
                isCollidingLeft = true;
                //std::cout<<"Izquierda"<<std::endl;
            }
            else
            {
                isCollidingLeft = false;
            }
        }
    }

    //COLISION JUGADOR CON BLOQUE POR IZQUIERDA DEL BLOQUE
    if (fall_block_left->collidingItems().size() > 0)
    {
        for (QGraphicsItem *colliding_item : fall_block_left->collidingItems())
        {
            if (typeid(*colliding_item) == typeid(Player))
            {
                std::cout<<"Izquierda";
                isCollidingLeftPlayer = true;
            }
            else
            {
                isCollidingLeftPlayer = false;
            }
        }
    }
    //COLISION JUGADOR CON BLOQUE POR DERECHA DEL BLOQUE
    if (fall_block_right->collidingItems().size() > 0)
    {
        for (QGraphicsItem *colliding_item : fall_block_right->collidingItems())
        {
            if (typeid(*colliding_item) == typeid(Player))
            {
                isCollidingRightPlayer = true;
            }
            else
            {
                isCollidingRightPlayer = false;
            }
        }
    }
}


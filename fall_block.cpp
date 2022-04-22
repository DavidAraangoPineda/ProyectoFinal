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
    setPixmap(QPixmap(":/imagenes/fall_block.png"));
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    fall_block_left = new QGraphicsRectItem(0, 8, 2, 15, this);
    fall_block_right = new QGraphicsRectItem(60, 8, 2,15, this);
    fall_block_top = new QGraphicsRectItem(4, -1, 54, 1, this);
    fall_block_bottom = new QGraphicsRectItem(4, 30, 54, 1, this);//(comienza desde,baja o sube tanto, Ancho, Altura, this)

//        fall_block_left->setBrush(brush);
//        fall_block_right->setBrush(brush);
//        fall_block_top->setBrush(brush);
//        fall_block_bottom->setBrush(brush);
//        fall_block_left->setPen(Qt::NoPen);
//        fall_block_right->setPen(Qt::NoPen);
//        fall_block_top->setPen(Qt::NoPen);
//        fall_block_bottom->setPen(Qt::NoPen);

        timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(update()));
        timer->start(20);

}


void fall_block::update(){

    colliding_player();
    move_fall_block();

}

void fall_block::move_fall_block()
{

    if (isCollidingTopPlayer)
    {
        velY += 0.05;
    }

    setPos(x(), y() + velY);

}

void fall_block::colliding_player()
{  

    if (fall_block_top->collidingItems().size() > 0)
    {
        for (QGraphicsItem *colliding_item : fall_block_top->collidingItems())
        {
            if (typeid(*colliding_item) == typeid(Cube)||
                typeid(*colliding_item) == typeid(Player))
            {
                isCollidingTopPlayer = true;
            }

        }
    }
    if ((pixmap().width()+pos().y() >570)){isCollidingTopPlayer=false;velY = 0;}

}


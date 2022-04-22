#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QProcess>
#include <Cube.h>
#include <block.h>
#include <iostream>
#include "spikes.h"
#include <Game.h>
#include <Player.h>
#include <QBrush>
#include "door.h"

door::door(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/imagenes/imagenes/door.png"));
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
//    spikes_left = new QGraphicsRectItem(0, 8, 2, 15, this);
//    spikes_right = new QGraphicsRectItem(60, 8, 2,15, this);
//    spikes_top = new QGraphicsRectItem(4, -1, 54, 1, this);
    door_center = new QGraphicsRectItem(15, 2, 4, 4, this);//(comienza desde,baja o sube tanto, Ancho, Altura, this)
    //fall_block_left->setBrush(brush);
    //fall_block_right->setBrush(brush);
    //fall_block_top->setBrush(brush);
    //fall_block_bottom->setBrush(brush);
    door_center->setPen(Qt::NoPen);
//    spikes_right->setPen(Qt::NoPen);
//    spikes_top->setPen(Qt::NoPen);
//    spikes_bottom->setPen(Qt::NoPen);
}



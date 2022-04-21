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

spikes::spikes(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/imagenes/spikes.png"));
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    spikes_left = new QGraphicsRectItem(0, 8, 2, 15, this);
    spikes_right = new QGraphicsRectItem(60, 8, 2,15, this);
    spikes_top = new QGraphicsRectItem(4, -1, 54, 1, this);
    spikes_bottom = new QGraphicsRectItem(4, 30, 54, 1, this);//(comienza desde,baja o sube tanto, Ancho, Altura, this)
    //fall_block_left->setBrush(brush);
    //fall_block_right->setBrush(brush);
    //fall_block_top->setBrush(brush);
    //fall_block_bottom->setBrush(brush);
    spikes_left->setPen(Qt::NoPen);
    spikes_right->setPen(Qt::NoPen);
    spikes_top->setPen(Qt::NoPen);
    spikes_bottom->setPen(Qt::NoPen);
}




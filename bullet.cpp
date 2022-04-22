#include "bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QtDebug>
#include <QList>
#include <resort.h>
#include <Game.h>

extern Game *game;
bullet::bullet(QGraphicsItem *parent)
{
    //dibujar la bala
   // QBrush brush;
  //  brush.setStyle(Qt::SolidPattern);
    //brush.setColor(Qt::red);
    bullet_hitbox = new QGraphicsRectItem(15, 0, 50, 60, this);//(comienza desde,baja o sube tanto, Ancho, Altura, this)
    //bullet_hitbox->setBrush(brush);
    bullet_hitbox->setPen(Qt::NoPen);
                music2 = new QMediaPlayer();

    timer = new QTimer(this);
   // QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveBullet()));
    timer->start(20);
}

void bullet::moveBullet()
{
//    //mover bala
    //if (velX==0){velX=-5;}
    if (pos().x() >600){velX=-3;setPixmap(QPixmap(":/imagenes/imagenes/duque.png"));}
    if (pos().x() <80){velX=3;setPixmap(QPixmap(":/imagenes/imagenes/fico.png"));}
    setPos(x() + velX, y());


    if (bullet_hitbox->collidingItems().size() > 0)
    {
        for (QGraphicsItem *colliding_item : bullet_hitbox->collidingItems())
        {
            if (typeid(*colliding_item) == typeid(Player))
            {

                //game->sonido()

            }
        }

    }
}


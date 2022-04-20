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

Cube::Cube(QGraphicsItem *parent)
{

    setPixmap(QPixmap(":/imagenes/bloque.jpg"));
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    cube_left = new QGraphicsRectItem(-2, 10, 5, 15, this);
    cube_right = new QGraphicsRectItem(32, 10, 2,15, this);
    cube_top = new QGraphicsRectItem(4, -1, 24, 1, this);
    cube_bottom = new QGraphicsRectItem(4, 32, 24, 1, this);//(Posicion inicial de x, 32, Ancho, Altura, this)

//    cube_left->setBrush(brush);
//    cube_right->setBrush(brush);
//    cube_top->setBrush(brush);
//    cube_bottom->setBrush(brush);
    cube_left->setPen(Qt::NoPen);
    cube_right->setPen(Qt::NoPen);
    cube_top->setPen(Qt::NoPen);
    cube_bottom->setPen(Qt::NoPen);



//    player_left -> setRect(0, 1, 2, 30);
//    player_right -> setRect(30, 1, 2, 30);
//    player_top ->  setRect(4, -1, 24, 1);
//    player_bottom ->  setRect(4, 32, 24, 1);

    timer = new QTimer(this);
   // QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(20);
}

void Cube::update(){

    colliding_block();
    moveCube();

}

void Cube::moveCube()
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

void Cube::colliding_block()
{
    if(stopGravity){return;}


    if (cube_bottom->collidingItems().size() > 0)
    {
        for (QGraphicsItem *colliding_item : cube_bottom->collidingItems())
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
    if (cube_top->collidingItems().size() > 0)
    {
        for (QGraphicsItem *colliding_item : cube_top->collidingItems())
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
    if (cube_right->collidingItems().size() > 0)
    {
        for (QGraphicsItem *colliding_item : cube_right->collidingItems())
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
    if (cube_left->collidingItems().size() > 0)
    {
        for (QGraphicsItem *colliding_item : cube_left->collidingItems())
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
    if (cube_left->collidingItems().size() > 0)
    {
        for (QGraphicsItem *colliding_item : cube_left->collidingItems())
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
    if (cube_right->collidingItems().size() > 0)
    {
        for (QGraphicsItem *colliding_item : cube_right->collidingItems())
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


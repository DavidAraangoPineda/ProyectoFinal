#include "Game.h"
#include <QTimer>
#include <QBrush>
#include <QImage>
#include <QGraphicsRectItem>
#define X_SIZE 600
#define Y_SIZE 500
Game::Game(QWidget *parent)
{
    // crear la scena

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,X_SIZE,Y_SIZE);
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(X_SIZE,Y_SIZE);
    scene->clear();
    //scene->setBackgroundBrush(QBrush(QImage(":imagenes/fondo.jpg")));
    //scene->setBackgroundBrush(QBrush("#FFFFFF"));


    // crear el jugador

    player = new Player();
    //player->setRect(0,0,20,40);
    //player->setPixmap(QPixmap(":/imagenes/nave.png").scaled(100,100));
    player->setPos(100,400);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);



    block = new class block();
    block->setRect(0,0,800,50);
    block->setPos(0,450);
    scene->addItem(block);

    block = new class block();
    block->setRect(0,0,50,50);
    block->setPos(0,370);
    scene->addItem(block);

    block = new class block();
    block->setRect(0,0,50,50);
    block->setPos(100,320);
    scene->addItem(block);

    block = new class block();
    block->setRect(0,0,50,50);
    block->setPos(100,320);
    scene->addItem(block);

    show();
}


void Game::assemble_blocks()
    {
        //QList <block*> brick_blocks;
        //{
    //block *bloque1 = new block();

   // bloque1->setPos(0,570);
    //bloque1->setSize(1);
   // bloque1->setScale(0.5);
    // brick_blocks.push_back(bloque1);
   // scene->addItem(bloque1);
    //show();

//}
}




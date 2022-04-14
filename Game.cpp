#include "Game.h"
#include <QTimer>
#include <QBrush>
#include <QImage>
#include <QGraphicsRectItem>

Game::Game(QWidget *parent)
{
    // crear la scena

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    scene->clear();
    //scene->setBackgroundBrush(QBrush(QImage(":imagenes/fondo.jpg")));
    scene->setBackgroundBrush(QBrush("#FFFFFF"));


    // crear el jugador

    player = new Player();
    player->setRect(0,0,20,40);
    //player->setPixmap(QPixmap(":/imagenes/nave.png").scaled(100,100));
    player->setPos(400,500);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();


    block = new class block();
    block->setRect(0,0,800,50);
    block->setPos(0,550);

    scene->addItem(block);
    scene->addItem(player);
    //assemble_blocks();
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




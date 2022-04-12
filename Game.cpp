#include "Game.h"
#include <QTimer>


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
    setBackgroundBrush(QBrush(QImage(":/sprites/fondos/fondo1.jpg")));


    // crear el jugador

    player = new Player();
    player->setRect(0,0,20,40);
    player->setPos(400,500);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);


    show();
}
void Game::assemble_blocks()
    {

        QList <Floor_Block*> floor_blocks;
        {
            int blocksWidth = 0;

            for(int i=0;i < 50;i++){

                if(i == 69){
                    blocksWidth += 64;
                }
                floor_blocks.push_back(new Floor_Block(blocksWidth, floor, false));

                floor_blocks.push_back(new Floor_Block(blocksWidth, floor + 32, false));
                blocksWidth += 32;
            }
        }

}


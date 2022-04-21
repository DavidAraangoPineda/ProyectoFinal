#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QMediaPlayer>
#include "Player.h"
#include "block.h"
#include "Button.h"
#include "Cube.h"
#include "fall_block.h"
#include "spikes.h"
#include "door.h"


class Game: public QGraphicsView{
    Q_OBJECT
private:



public:
    Game(QWidget * parent = 0);
    void menu();
    //int spawn_block(int posx,int posy, int width,int height);
    QGraphicsScene *scene;
    Player * player;
    block * Block;
    QMediaPlayer * music;
    Cube *cube;
    fall_block *Fall_block;
    spikes *Spikes;
    door *Door;

public slots:
    void Level1();
    void Level2();
    void Level3();
    void load_level();

};


#endif // GAME_H

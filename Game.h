#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QMediaPlayer>

#include <iostream>
#include <fstream>
#include <stdlib.h>


#include "Player.h"
#include "block.h"
#include "Button.h"
#include "Cube.h"
#include "fall_block.h"
#include "spikes.h"
#include "door.h"
#include "resort.h"
#include "bullet.h"
using namespace std;

class Game: public QGraphicsView{
    Q_OBJECT
private:



public:
    Game(QWidget * parent = 0);
    void menu();
    // Se le da un nombre de un archivo de texto y lo retorna

    //int spawn_block(int posx,int posy, int width,int height);
    QGraphicsScene *scene;
    Player * player;
    block * Block;
    QMediaPlayer * music;
        QMediaPlayer * musica;
    Cube *cube;
    fall_block *Fall_block;
    spikes *Spikes;
    door *Door;
    resort *Resort;
    bullet *Bullet;

public slots:
    void Level1();
    void Level2();
    void Level3();
    void load_level();
    void load_continua();
    void load_level1();
    void load_next_level();
    int leer_txt();
    void string_a_txt();
    void sonido();
};


#endif // GAME_H

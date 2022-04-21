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

public slots:
    void Level1();
    void Level2();
    void Level3();
    void start_game();

};


#endif // GAME_H

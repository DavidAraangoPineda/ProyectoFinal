#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QMediaPlayer>
#include "Player.h"
#include "floor_block.h"
#include "block.h"
#include "Button.h"

class Game: public QGraphicsView{
    Q_OBJECT
private:
    //void assemble_blocks();


public:
    Game(QWidget * parent = 0);
    void menu();
    QGraphicsScene *scene;
    Player * player;
    block * block;
    QMediaPlayer * music;

public slots:
    void Level1();
    void Level2();
    void Level3();
};


#endif // GAME_H

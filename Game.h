#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "Player.h"
#include "floor_block.h"
#include "blocks.h"



class Game: public QGraphicsView{
    Q_OBJECT
private:
    void assemble_blocks();

public:
    Game(QWidget * parent = 0);

    QGraphicsScene *scene;
    Player * player;
    void menu();
    int floor = 416;
public slots:
    //void start();

};


#endif // GAME_H

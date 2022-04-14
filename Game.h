#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "Player.h"
#include "floor_block.h"
#include "block.h"


class Game: public QGraphicsView{
    Q_OBJECT
private:
    void assemble_blocks();

public:
    Game(QWidget * parent = 0);

    QGraphicsScene *scene;
    Player * player;
    block * block;
    void menu();
public slots:
    //void start();

};


#endif // GAME_H

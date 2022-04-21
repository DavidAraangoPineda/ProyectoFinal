#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QImage>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QMediaPlayer>

//class Player: public QObject, public QGraphicsPixmapItem,public QGraphicsRectItem{
class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Player(QGraphicsItem *parent = 0);

    void keyPressEvent(QKeyEvent * event) override;
    void keyReleaseEvent(QKeyEvent * event) override;
    void colliding_block();
    void movePlayer();
    void dying();
    QMediaPlayer * deadMusic;

public slots:
    void update();


private:
    float accl = 0.10;
    float maxSpeed = 1.8;
    float jumpCounterMax = 20;
    float jumpCounter = 0;
    float gravityMaxSpeed = 3;
    float velX = 0;
    float velY = 0;
    bool isMovingRight=false;
    bool isMovingLeft=false;
    bool isJumping=false;
    bool isCollidingRight = false;
    bool isCollidingLeft = false;
    bool isCollidingBottom = false;
    bool isCollidingTop = false;
    bool isMidJump = false;   
    bool stopControls = false;
    bool stopGravity = false;
    bool isDead = false;
    bool next_level = false;

    QGraphicsRectItem * player_bottom;
    QGraphicsRectItem * player_top;
    QGraphicsRectItem * player_right;
    QGraphicsRectItem * player_left;

    QTimer *timer;

    //void restart_game();
};

#endif // PLAYER_H

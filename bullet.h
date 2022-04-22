#ifndef BULLET_H
#define BULLET_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QImage>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QBrush>
#include <QMediaPlayer>

using namespace std;

class bullet:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    bullet(QGraphicsItem *parent = 0);

public slots:
    void moveBullet();
    //void update();

private:

    float velX=-5;

    QTimer *timer;
    QGraphicsRectItem * bullet_hitbox;
    QMediaPlayer *music2;
};

#endif // BULLET_H

#include "Game.h"
#include <QTimer>
#include <QBrush>
#include <QImage>
#include <QGraphicsRectItem>
#include <QMediaPlayer>

#define X_SIZE 600
#define Y_SIZE 500
Game::Game(QWidget *parent)
{
    // crear la scena

    scene = new QGraphicsScene();
    music = new QMediaPlayer();
    scene->setSceneRect(0,0,X_SIZE,Y_SIZE);
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(X_SIZE,Y_SIZE);
    scene->clear();
    //scene->setBackgroundBrush(QBrush(QImage(":imagenes/fondo1.jpg")));
    //scene->setBackgroundBrush(QBrush("#FFFFFF"));

}
void Game::menu()
    {
    scene->clear();
    setBackgroundBrush(QBrush(QImage(":imagenes/pixel.jpg")));

    music->setMedia(QUrl("qrc:/sound/Intro.mp3"));
    music->setVolume(30);
    music->play();

    QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("Petroboy & Ficogirl"));
    QFont titleFont("Times",50);
    titleText->setFont(titleFont);

    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 100;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // crear boton play

    Button * playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 -playButton->boundingRect().width()/2;
    int byPos = 200;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(Level1()));
    scene->addItem(playButton);

//    // crear boton salir

    Button * quitButton = new Button(QString("Exit"));
    int qxPos = this->width()/2 -quitButton->boundingRect().width()/2;
    int qyPos = 270;
    quitButton->setPos(qxPos,qyPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

       // crear boton continuar

    Button * Continue = new Button(QString("Continuar"));
    int cxPos = this->width()/2 -Continue->boundingRect().width()/2;
    int cyPos = 340;
    Continue->setPos(cxPos,cyPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(Level2()));
    scene->addItem(Continue);


}

void Game::Level1()
{
    scene->clear();
    //setBackgroundBrush(QBrush(QImage(":imagenes/nivel1.jpg")));
        //setSceneRect()
    player = new Player();
    player->setPos(100,400);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);


//    cube=new Cube();
//    cube->setPos(150,400);

//    scene->addItem(cube);

    cube=new Cube();
    cube->setPos(170,350);
    scene->addItem(cube);


    music->setMedia(QUrl("qrc:/sound/nivel1.mp3"));
    music->setVolume(10);
    //music->play();

    Block = new class block();
    Block->setRect(0,0,800,50);
    Block->setPos(0,450);

    scene->addItem(Block);

    Block = new class block();
    Block->setRect(0,0,50,50);
    Block->setPos(250,400);
    scene->addItem(Block);

    Block = new class block();
    Block->setRect(0,0,50,50);
    Block->setPos(0,400);
    scene->addItem(Block);

    Block = new class block();
    Block->setRect(0,0,50,50);
    Block->setPos(100,320);
    scene->addItem(Block);

    Block = new class block();
    Block->setRect(0,0,50,50);
    Block->setPos(100,320);
    scene->addItem(Block);

    show();
}
void Game::Level2()
{
    int matriz[30][25],filas,columnas;
    for (int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
           // cout<<"Digite un nuer"
        }
    }

}

void Game::Level3()
{

}







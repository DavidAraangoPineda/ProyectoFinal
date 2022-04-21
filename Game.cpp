#include "Game.h"
#include <QTimer>
#include <QBrush>
#include <QImage>
#include <QGraphicsRectItem>
#include <QMediaPlayer>

#define X_SIZE 700
#define Y_SIZE 500

int nivel=2;

Game::Game(QWidget *parent)
{
    // crear la scena

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,X_SIZE,Y_SIZE);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(X_SIZE,Y_SIZE);
    scene->clear();


    //scene->setBackgroundBrush(QBrush(QImage(":imagenes/fondo1.jpg")));
    //scene->setBackgroundBrush(QBrush("#FFFFFF"));

//    if (nivel==0){
//        menu();
//    }
//    if (nivel==1){
//        level1;
//    }
//    if (nivel==0){
//        menu();
//    }

}

void Game::menu()
{
        scene->clear();
        //setBackgroundBrush(QBrush(QImage(":imagenes/pixel.jpg")));

        //music = new QMediaPlayer();

        //music->setMedia(QUrl("qrc:/sound/Intro.mp3"));
        //music->setVolume(30);
        //music->play();

        QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("Petroboy & Ficogirl"));
        QFont titleFont("Times",50);
        titleText->setFont(titleFont);

        int txPos = this->width()/2 - titleText->boundingRect().width()/2;
        int tyPos = 100;
        titleText->setPos(txPos,tyPos);
        scene->addItem(titleText);

        // crear boton play

        Button * playButton = new Button(QString("Nivel1"));
        int bxPos = this->width()/2 -playButton->boundingRect().width()/2;
        int byPos = 200;
        playButton->setPos(bxPos,byPos);
        connect(playButton,SIGNAL(clicked()),this,SLOT(Level1()));
        scene->addItem(playButton);

    //    // crear boton salir

        Button * quitButton = new Button(QString("Nivel2"));
        int qxPos = this->width()/2 -quitButton->boundingRect().width()/2;
        int qyPos = 270;
        quitButton->setPos(qxPos,qyPos);
        connect(quitButton,SIGNAL(clicked()),this,SLOT(Level2()));
        scene->addItem(quitButton);

           // crear boton continuar

        Button * Continue = new Button(QString("Nivel3"));
        int cxPos = this->width()/2 -Continue->boundingRect().width()/2;
        int cyPos = 340;
        Continue->setPos(cxPos,cyPos);
        connect(Continue,SIGNAL(clicked()),this,SLOT(Level3()));
        scene->addItem(Continue);

//        Button * playaButton = new Button(QString("Play"));
//        int bxaPos = this->width()/2 -playButton->boundingRect().width()/2;
//        int byaPos = 20;
//        playButton->setPos(bxaPos,byaPos);
//        connect(playButton,SIGNAL(clicked()),this,SLOT(Level2()));
//        scene->addItem(playaButton);

        //scene->clear();


}

void Game::Level1()
{
    scene->clear();
    //setBackgroundBrush(QBrush(QImage(":imagenes/nivel1.jpg")));
        //setSceneRect()
    player = new Player();
    player->setPos(200,180);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    //music->setMedia(QUrl("qrc:/sound/nivel1.mp3"));
    //music->setVolume(10);
    //music->setPosition(50);
    //music->play();

    cube=new Cube();
    cube->setPos(170,350);
    scene->addItem(cube);

    Fall_block=new fall_block();
    Fall_block->setPos(250,270);
    scene->addItem(Fall_block);

    Spikes=new spikes();
    Spikes ->setPos(314,332);
    Spikes->setRotation(180);
    scene->addItem(Spikes);

    Door=new door();
    Door ->setPos(0,0);
    scene->addItem(Door);


    Block = new block();
    Block->setRect(0,0,100,20);
    Block->setPos(100,480);
    scene->addItem(Block);

    Block = new block();
    Block->setRect(0,0,100,40);
    Block->setPos(0,200);
    scene->addItem(Block);

    Block = new block();
    Block->setRect(0,0,100,100);
    Block->setPos(150,250);
    scene->addItem(Block);

    Block = new block();
    Block->setRect(0,0,100,40);
    Block->setPos(0,460);
    scene->addItem(Block);

    Block = new block();
    Block->setRect(0,0,200,40);
    Block->setPos(270,400);
    scene->addItem(Block);

    Block = new block();
    Block->setRect(0,0,100,40);
    Block->setPos(350,360);
    scene->addItem(Block);

    Block = new block();
    Block->setRect(0,0,40,130);
    Block->setPos(350,170);
    scene->addItem(Block);

    Block = new block();
    Block->setRect(0,0,100,40);
    Block->setPos(500,290);
    scene->addItem(Block);
//--------------------------
    Block = new block();
    Block->setRect(0,0,100,20);
    Block->setPos(0,64);
    scene->addItem(Block);
//

    Fall_block=new fall_block();
    Fall_block->setPos(170,110);
    scene->addItem(Fall_block);

    Fall_block=new fall_block();
    Fall_block->setPos(250,180);
    scene->addItem(Fall_block);

    Block = new block();
    Block->setRect(0,0,100,40);
    Block->setPos(0,460);
    scene->addItem(Block);

    Block = new block();
    Block->setRect(0,0,100,40);
    Block->setPos(0,460);
    scene->addItem(Block);




//    Block = new class block();
//    Block->setRect(0,0,150,50);
//    Block->setPos(0,450);
//    scene->addItem(Block);

//    Block = new class block();
//    Block->setRect(0,0,50,50);
//    Block->setPos(250,400);
//    scene->addItem(Block);

//    Block = new class block();
//    Block->setRect(0,0,50,50);
//    Block->setPos(0,400);
//    scene->addItem(Block);

//    Block = new class block();
//    Block->setRect(0,0,50,50);
//    Block->setPos(100,320);
//    scene->addItem(Block);

//    Block = new block();
//    Block->setRect(0,0,50,50);
//    Block->setPos(100,320);
//    scene->addItem(Block);

    show();
}
void Game::Level2()
{
    //scene->clear();
    Button * playButton = new Button(QString("Nivel1"));
    playButton->deleteLater();
    cube=new Cube();
    cube->setPos(170,350);
    scene->addItem(cube);

    Fall_block=new fall_block();
    Fall_block->setPos(250,270);
    scene->addItem(Fall_block);

    show();


}
void Game::Level3()
{
    nivel=2;
}

void Game::load_level(){
    scene->clear();
    if (nivel==2){
        Level2();
//        Button * playButton = new Button(QString("Nivel1"));
//        int bxPos = this->width()/2 -playButton->boundingRect().width()/2;
//        int byPos = 200;
//        playButton->setPos(bxPos,byPos);
//        connect(playButton,SIGNAL(clicked()),this,SLOT(Level2()));
//        scene->addItem(playButton);

    }

//        Block->setRect(0,0,100,20);
//        Block->setPos(0,64);
//        scene->addItem(Block);

//        Fall_block=new fall_block();
//        Fall_block->setPos(170,110);
//        scene->addItem(Fall_block);

    //}
    //show();
    //menu();
//    player->setPos(200,180);
//    cube->setPos(170,350);
//    Fall_block->setPos(250,270);

        //music->play();


}







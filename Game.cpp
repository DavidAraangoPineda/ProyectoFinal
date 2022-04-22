#include "Game.h"
#include <QTimer>
#include <QBrush>
#include <QImage>
#include <QGraphicsRectItem>
#include <QMediaPlayer>

#define X_SIZE 700
#define Y_SIZE 500

int nivel=1;
int continua;

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

}

void Game::menu()
{

        continua=leer_txt();

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
        connect(playButton,SIGNAL(clicked()),this,SLOT(load_level1()));
        scene->addItem(playButton);

        // crear boton continuar

        Button * Continue = new Button(QString("Continue"));
        int cxPos = this->width()/2 -Continue->boundingRect().width()/2;
        int cyPos = 270;
        Continue->setPos(cxPos,cyPos);
        connect(Continue,SIGNAL(clicked()),this,SLOT(load_continua()));
        scene->addItem(Continue);


    //    // crear boton salir
        Button * quitButton = new Button(QString("Exit"));
        int qxPos = this->width()/2 -quitButton->boundingRect().width()/2;
        int qyPos = 340;
        quitButton->setPos(qxPos,qyPos);
        connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
        scene->addItem(quitButton);

}

void Game::Level1()
{

    //scene->clear();
    //setBackgroundBrush(QBrush(QImage(":imagenes/nivel1.jpg")));
        //setSceneRect()
    player = new Player();
    player->setPos(200,180);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    Fall_block=new fall_block();
    Fall_block->setPos(170,110);
    scene->addItem(Fall_block);

    Fall_block=new fall_block();
    Fall_block->setPos(250,180);
    scene->addItem(Fall_block);

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

    Block = new block();
    Block->setRect(0,0,100,40);
    Block->setPos(0,460);
    scene->addItem(Block);

    Block = new block();
    Block->setRect(0,0,100,40);
    Block->setPos(0,460);
    scene->addItem(Block);



    show();
}

void Game::Level2()
{


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

    if (nivel==1){
        scene->clear();
        Level1();
    }
    if (nivel==2){
        scene->clear();
        Level2();
    }
    if (nivel==3){
        scene->clear();
        Level3();
    }
}

void Game::load_continua(){
    nivel=continua;

    if (continua==1){
        scene->clear();
        Level1();
    }
    if (continua==2){
        scene->clear();
        Level2();
    }
    if (continua==3){
        scene->clear();
        Level3();
    }
}

void Game::load_level1(){
    scene->clear();
    nivel=1;
    Level1();
    nivel=0;
    string_a_txt();
}

void Game::load_next_level(){
    if (nivel==1){string_a_txt();nivel=2;}
    if (nivel==2){string_a_txt();nivel=3;}
    scene->clear();
    if (nivel==2){
        Level2();
    }
    if (nivel==3){
        Level3();
    }
}

int Game::leer_txt()
{
    long long int tam;
    char *texto;
    int numero;
   // fstream abierto;
    string nombre_natural="nivel.txt";
    fstream abierto(nombre_natural,fstream::ate|fstream::in|fstream::binary);
    if(abierto.is_open()){
        //cout<<"abierto correctamente"<<endl;
        tam=abierto.tellg();
        texto=new char[tam];
        abierto.seekg(0);
        for(long long int i=0;i<tam;i++){
            texto[i]=abierto.get();
        }
        texto[tam]='\0';

        //int(texto);
        numero =stoi(texto);
        abierto.close();
        //cout<<numero;
        return numero;
    }
    else {
        return 0;
         }
}

void Game::string_a_txt(){
    nivel=nivel+1;
    string texto=to_string(nivel);
    fstream k;
    string nombrebin="nivel.txt";
    k.open(nombrebin,fstream::out|fstream::binary);

    if(k.is_open()){
        k<<texto;
        }
    k.close();
    }



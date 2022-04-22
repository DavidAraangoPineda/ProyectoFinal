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
        music = new QMediaPlayer();



}

void Game::menu()
{
        continua=leer_txt();
        scene->clear();
        setBackgroundBrush(QBrush(QImage(":imagenes/imagenes/pixel.jpg")));

        music = new QMediaPlayer();

       music->setMedia(QUrl("qrc:/sound/Intro.mp3"));
        music->setVolume(30);
        music->play();

        QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("Petroboy"));
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
    setBackgroundBrush(QBrush(QImage(":/imagenes/imagenes/nivel1.jpg")));

    music->setMedia(QUrl("qrc:/sound/nivel1.mp3")); 
    music->play();
    music->setVolume(7);

    player = new Player();
    player->setPos(0,300);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);


    Resort=new resort();
    Resort->setPos(400,210);
    scene->addItem(Resort);

    cube=new Cube();
    cube->setPos(170,350);
    scene->addItem(cube);

    Fall_block=new fall_block();
    Fall_block->setPos(170,110);
    scene->addItem(Fall_block);

    Fall_block=new fall_block();
    Fall_block->setPos(250,180);
    scene->addItem(Fall_block);

//    Fall_block=new fall_block();
//    Fall_block->setPos(470,120);
//    scene->addItem(Fall_block);

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
    Block->setRect(0,0,20,20);
    Block->setPos(120,100);
    scene->addItem(Block);

    Block = new block();
    Block->setRect(0,0,20,20);
    Block->setPos(370,80);
    scene->addItem(Block);

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
    Block->setRect(0,0,30,40);
    Block->setPos(650,230);
    scene->addItem(Block);

    Block = new block();
    Block->setRect(0,0,30,40);
    Block->setPos(570,180);
    scene->addItem(Block);

    Block = new block();
    Block->setRect(0,0,30,40);
    Block->setPos(650,130);
    scene->addItem(Block);

    Block = new block();
    Block->setRect(0,0,30,40);
    Block->setPos(570,180);
    scene->addItem(Block);



    show();
}

void Game::Level2()
{
    setBackgroundBrush(QBrush(QImage(":/imagenes/imagenes/nivel2.jpg")));

        music->setMedia(QUrl("qrc:/sound/nivel2.mp3"));
        music->play();
        music->setVolume(7);
        player = new Player();
            player->setPos(100,400);
            player->setFlag(QGraphicsItem::ItemIsFocusable);
            player->setFocus();
            scene->addItem(player);

                Block = new block();
                Block->setRect(0,0,100,40);
                Block->setPos(600,470);
                scene->addItem(Block);

                Spikes=new spikes();
                Spikes ->setPos(600,440);
                scene->addItem(Spikes);

                Block = new block();
                Block->setRect(0,0,200,40);
                Block->setPos(0,470);
                scene->addItem(Block);

                Block = new block();
                Block->setRect(0,0,200,40);
                Block->setPos(600,60);
                scene->addItem(Block);


                //1 real
                Fall_block=new fall_block();
                Fall_block->setPos(200,440);
                scene->addItem(Fall_block);

                //2 real
                Fall_block=new fall_block();
                Fall_block->setPos(300,410);
                scene->addItem(Fall_block);

                //12
                Fall_block=new fall_block();
                Fall_block->setPos(470,360);
                scene->addItem(Fall_block);


                //13
                Fall_block=new fall_block();
                Fall_block->setPos(550,280);
                scene->addItem(Fall_block);

                //14
                Fall_block=new fall_block();
                Fall_block->setPos(390,440);
                scene->addItem(Fall_block);

                Spikes=new spikes();
                Spikes ->setPos(390,410);
                scene->addItem(Spikes);

                //4
                Fall_block=new fall_block();
                Fall_block->setPos(370,350);
                scene->addItem(Fall_block);

                //3 real
                Block = new block();
                Block->setRect(0,0,30,15);
                Block->setPos(210,340);
                scene->addItem(Block);


                //5 real
                Fall_block=new fall_block();
                Fall_block->setPos(300,270);
                scene->addItem(Fall_block);


                //6
                Fall_block=new fall_block();
                Fall_block->setPos(440,280);
                scene->addItem(Fall_block);

                Spikes=new spikes();
                Spikes ->setPos(405,260);
                Spikes->setRotation(180);
                scene->addItem(Spikes);


                //7
                Fall_block=new fall_block();
                Fall_block->setPos(500,210);
                scene->addItem(Fall_block);


                //8
                Block = new block();
                Block->setRect(0,0,30,15);
                Block->setPos(550,150);
                scene->addItem(Block);

                //9 real
                Fall_block=new fall_block();
                Fall_block->setPos(340,200);
                scene->addItem(Fall_block);

                //10
                Block = new block();
                Block->setRect(0,0,15,10);
                Block->setPos(270,140);
                scene->addItem(Block);


                //15
                Fall_block=new fall_block();
                Fall_block->setPos(390,140);
                scene->addItem(Fall_block);

                Spikes=new spikes();
                Spikes ->setPos(378,171);
                Spikes->setRotation(270);
                Spikes->setScale(0.5);
                scene->addItem(Spikes);



                //9 real
                Fall_block=new fall_block();
                Fall_block->setPos(340,70);
                scene->addItem(Fall_block);

                //11
                Fall_block=new fall_block();
                Fall_block->setPos(470,60);
                scene->addItem(Fall_block);

                Spikes=new spikes();
                Spikes ->setPos(530,120);
                Spikes->setRotation(180);
                scene->addItem(Spikes);


                Door=new door();
                Door ->setPos(630,0);
                scene->addItem(Door);

        show();


}

void Game::Level3()
{

    setBackgroundBrush(QBrush(QImage(":/imagenes/imagenes/nivel3.jpg")));

    music->setMedia(QUrl("qrc:/sound/nivel3.mp3"));
    music->play();
    music->setVolume(7);
    player = new Player();
    player->setPos(640,0);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    Block = new block();
    Block->setRect(0,0,40,20);
    Block->setPos(630,50);
    scene->addItem(Block);

    Fall_block=new fall_block();
    Fall_block->setPos(100,50);
    scene->addItem(Fall_block);

    Fall_block=new fall_block();
    Fall_block->setPos(170,70);
    scene->addItem(Fall_block);

    Fall_block=new fall_block();
    Fall_block->setPos(250,50);
    scene->addItem(Fall_block);

    Fall_block=new fall_block();
    Fall_block->setPos(300,90);
    scene->addItem(Fall_block);

    Fall_block=new fall_block();
    Fall_block->setPos(500,50);
    scene->addItem(Fall_block);

    Resort=new resort();
    Resort->setPos(400,170);
    scene->addItem(Resort);

    Block = new block();
    Block->setRect(0,0,15,10);
    Block->setPos(0,140);
    scene->addItem(Block);
    //paredes
    Block = new block();
    Block->setRect(0,0,1,500);
    Block->setPos(0,0);
    scene->addItem(Block);

    Block = new block();
    Block->setRect(0,0,1,500);
    Block->setPos(700,0);
    scene->addItem(Block);
    //---

    for (int i = 0; i < 400; i=i+64) {
        Spikes=new spikes();
        Spikes ->setPos(230+i,180);
        //Spikes->setRotation(270);
        //Spikes->setScale(0.5);
        scene->addItem(Spikes);

    }
    Block = new block();
    Block->setRect(0,0,430,10);
    Block->setPos(250,210);
    scene->addItem(Block);

    Block = new block();
    Block->setRect(0,0,15,10);
    Block->setPos(0,370);
    scene->addItem(Block);


    Bullet=new bullet();
    Bullet->setPos(650,390);
    scene->addItem(Bullet);

    Door=new door();
    Door ->setPos(630,430);
    scene->addItem(Door);

    Block = new block();
    Block->setRect(0,0,700,10);
    Block->setPos(0,490);
    scene->addItem(Block);

    Block = new block();
    Block->setRect(0,0,20,20);
    Block->setPos(70,430);
    scene->addItem(Block);

    Block = new block();
    Block->setRect(0,0,15,10);
    Block->setPos(120,370);
    scene->addItem(Block);



}

void Game::load_level(){



    if (nivel==1){
        scene->clear();
        //music->pause();
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
    //nivel=0;
    string_a_txt();
}

void Game::load_next_level(){
    bool fal=false;
    if (nivel==1&&fal==false){nivel=2;fal=true;}
    if (nivel==2&&fal==false){nivel=3;fal=true;}
    scene->clear();
    if (nivel==1){
        Level1();
    }
    if (nivel==2){
        Level2();
    }
    if (nivel==3){
        Level3();
    }
    string_a_txt();
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

    //nivel=nivel+1;
    string texto=to_string(nivel);
    fstream k;
    string nombrebin="nivel.txt";
    k.open(nombrebin,fstream::out|fstream::binary);

    if(k.is_open()){
        k<<texto;
        }
    k.close();
    }

void Game::sonido(){
    music->setMedia(QUrl("qrc:/sound/atrape.mp3"));
     music->setVolume(30);
     music->play();

}

//This is the game manager file, it links the different game objects to the scene directly or indirectly
//and it also manages the creation on the menu and other important game characters like the enemies and
//the player

#include "_GM.h"

#include <QMediaPlayer>

#include <QMediaPlaylist>

#include <QBrush.h>

#include <QImage.h>

#include <QTimer>

#include <QDebug>

#include <QCoreApplication>
#include <QTime>

#include "menubuttons.h"

//+++++++++++++++++++++++++++++++++++++++++ GM() Constructor [ Main Menu ] ++++++++++++++++++++++++++++++++++++++++++++++++

_GM::_GM()
{

    //Create a Scene.....................................................................................................

    scene = new QGraphicsScene();
    scene->setSceneRect(0,200,800,600);               // Set scene co-ordinates to (0,0) and set scene size to 800x600

    //Background set

     setBackgroundBrush(QBrush(QImage(":/Assets/Menu/HomeScreen.png").scaled(scene->width(),scene->height() + 200,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));

    // visualize scene and Disable scroll bars...........................................................................

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);        // Disable Horizontal Bar
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);          // Disable Vertial Bar
    setFixedSize(800,600);                                       // Set view size 800x600

    //create Buttons.....................................................................................................

    menuButtons *start = new menuButtons();
    scene->addItem(start);
    start->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    start->setFocus();

    //Set Background Music...............................................................................................

    QMediaPlaylist *playlist = new QMediaPlaylist();                          //Create Playlist
    playlist->addMedia(QUrl("qrc:/Assets/Menu/music/music1.mp3"));               //set media location
    playlist->addMedia(QUrl("qrc:/Assets/Menu/music/music2.mp3"));
    playlist->addMedia(QUrl("qrc:/Assets/Menu/music/music3.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);                          //Set play state to loop

    QMediaPlayer *bgMusic = new QMediaPlayer();                               //create media object
    bgMusic->setPlaylist(playlist);                                           //set playlist
    bgMusic->setVolume(50);
    bgMusic->play();                                                          //play the music

    show();
}

// +++++++++++++++++++++++++++++++++++++++++++++++ Game Start Function +++++++++++++++++++++++++++++++++++++++++++++++++

void _GM::start()
{
    scene->clear();

    //Background set....................................................................................................

     setBackgroundBrush(QBrush(QImage(":/Assets/Backgrounds/Background (2).png")));

    //Create ScoreBar and add it to Scene

    score = new Score();
    score->setPos(scene->sceneRect().x() + 60 , scene->sceneRect().y()+1);
    scene->addItem(score);

    //Create HealthBar and add it to scene..............................................................................

    health = new Health();                                                           //Outer Frame
    health->setPos(scene->sceneRect().x() + 50 ,scene->sceneRect().y() + 25);
    scene->addItem(health);

    header_body * healthbarBody = new header_body();                                 //Green bar
    scene->addItem(healthbarBody);
    healthbarBody->setPos(scene->sceneRect().x(),scene->sceneRect().y() + 20);

    //Create Player......................................................................................................

    player = new Player(width());

    player->setPos( (width()/2) - (player->pixmap().width()/2) , scene->sceneRect().height() + player->pixmap().height() + 20); // Adjusting the player Position

    // Add Player to the scene...........................................................................................

    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);   // Make item focusable
    player->setFocus();                                // Set Focus to player

    //Enemy Timer to create Enemies......................................................................................

    QTimer *eTimer = new QTimer(); // Enemy timer
    QObject::connect( eTimer,SIGNAL(timeout()),player,SLOT(enemy_Spawn()) );
    eTimer->start(500);

   //Meteorites Timer to create  Meteorites..............................................................................

    QTimer *mTimer = new QTimer();
    QObject::connect( mTimer ,SIGNAL(timeout()),player,SLOT(meteoritesSpawn()) );
    mTimer->start(1000);

    //Power Up Item creator..............................................................................................

    QTimer *powerUP_Timer = new QTimer();
    QObject::connect( powerUP_Timer,SIGNAL(timeout()),player,SLOT(powerUP_Spawn()) );
    powerUP_Timer->start(5000);
}

//+++++++++++++++++++++++++++++++++++++++++++++++Play Game Over Music+++++++++++++++++++++++++++++++++++++++++++++++++++

void _GM::ExplosionMusic()
{
    QMediaPlaylist *explodePlaylist = new QMediaPlaylist();                                              //Create Playlist
    explodePlaylist->addMedia(QUrl("qrc:/Assets/blue_shipv3/Explosion/explosion.mp3"));         //set media location
    explodePlaylist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);                                   //Set play state to onlyOnce

    QMediaPlayer *explodeMusic = new QMediaPlayer();                                                     //create media object
    explodeMusic->setPlaylist(explodePlaylist);                                                          //set playlist
    explodeMusic->play();
}

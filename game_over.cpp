#include "game_over.h"
#include "_GM.h"

#include "player.h"
#include <QDebug>
extern _GM* game;

//Game Over Constructor

Game_Over::Game_Over()
{
    //Initialize animation sprite Counter

    counter = 1;

    //Display game Oevr sprite

    setPixmap(QPixmap(":/Assets/misc/Game Over (1).png"));
    setPos(game->scene->sceneRect().width()/2 - this->pixmap().width()/2, game->scene->sceneRect().height()/2);
    qInfo()<<game->scene->sceneRect().height();
    //Timer for playing game over sprite animation

    QTimer *gameOverTimer = new QTimer();
    connect( gameOverTimer,SIGNAL(timeout()),this,SLOT(display()) );
    gameOverTimer->start(1);
}

// GameOver Sprites

void Game_Over::display()
{
    switch(counter)
    {
        case 1:setPixmap(QPixmap(":/Assets/misc/Game Over (1).png"));counter = 2;break;
        case 2:setPixmap(QPixmap(":/Assets/misc/Game Over (2).png"));counter = 3;break;
        case 3:setPixmap(QPixmap(":/Assets/misc/Game Over (3).png"));counter = 4;break;
        case 4:setPixmap(QPixmap(":/Assets/misc/Game Over (3).png"));counter = 5;break;
        case 5:setPixmap(QPixmap(":/Assets/misc/Game Over (2).png"));counter = 6;break;
        case 6:setPixmap(QPixmap(":/Assets/misc/Game Over (1).png"));counter = 1;break;
    }
}

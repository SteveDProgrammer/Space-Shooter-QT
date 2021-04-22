//This file is for the managing the properties and behavior of the enemies

#include "enemy.h"

#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> //for rand() function

#include "_GM.h"

#include <QList>
#include <typeinfo>
#include "floating_text.h"

extern _GM * game;

//Enemy Constructor

enemy::enemy()
{
    //Draw the Enemy

    setPixmap(QPixmap(":/Assets/Red_Dragon/Red_Dragon (1).png").scaled(128,128,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    //screen limit is the scene width substracted enemy pixmap width.....................................................

    int ScreenLimit = game->scene->sceneRect().width() - pixmap().width();

    int random_x = rand() % ScreenLimit; //initialze the random x position of the enemy

    setPos( random_x,y()); // Initialize the position of the enemy

    // allocating memory for the enemy move timer and Initializing it

    EnemyMoveTimer = new QTimer();
    connect(EnemyMoveTimer,SIGNAL(timeout()),this,SLOT(Move()));
    EnemyMoveTimer->start(10);          //start EnemyMoveTimer

    //initialize fly animation counter

    anim_number_fly = 1;

    //animation timer for controlling the wings animation of the enemy dragon

    flyAnimTimer = new QTimer();
    connect( flyAnimTimer,SIGNAL(timeout()),this,SLOT(playFlyAnimation()) );
    flyAnimTimer->start(90);        //Start Fly animationTimer

}

void enemy::Move()
{

    // delete off-scene enemies..........................................................................................

    if( pos().y() > scene()->height() + scene()->sceneRect().y())
        {
            delete EnemyMoveTimer;

            delete flyAnimTimer;

            //play score deduction animation..............................................................................

            Floating_Text *text = new Floating_Text(QPixmap(":/Assets/misc/score(-2).png").scaled(43,43,Qt::IgnoreAspectRatio,Qt::SmoothTransformation),x(),y() - 5);
            game->scene->addItem(text);
            game->health->Decrease(2); //deduct score by 2 if condition is satisfied......................................

            scene()->removeItem(this);  //remove enemies..................................................................
            delete this;
            return;
        }

    //move the enemies

    setPos(x(),y() + 5);

}

//++++++++++++++++++++++++++++++++++++++++++Enemy play animation Function++++++++++++++++++++++++++++++++++++++++++++++++

void enemy :: playFlyAnimation()
{
    switch(anim_number_fly)
    {
        case 1 :setPixmap(Dragon1); anim_number_fly = 2; break;
        case 2 :setPixmap(Dragon2); anim_number_fly = 3; break;
        case 3 :setPixmap(Dragon3); anim_number_fly = 4; break;
        case 4 :setPixmap(Dragon4); anim_number_fly = 5; break;
        case 5 :setPixmap(Dragon4); anim_number_fly = 6; break;
        case 6 :setPixmap(Dragon3); anim_number_fly = 7; break;
        case 7 :setPixmap(Dragon2); anim_number_fly = 8; break;
        case 8 :setPixmap(Dragon1); anim_number_fly = 1; break;
    }
}

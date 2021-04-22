//This file manages the Player health

#include "Health.h"
#include <QFont>
#include "_GM.h"
#include "game_over.h"

extern _GM *game;

Health::Health()
{

    //initialize Health to 200

     health = 80;

     //setPixmap

     setPixmap(QPixmap(":/Assets/misc/HealthBar (1).png").scaled(260,30,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}

//This function is responsible for maintaining the decrease in player Health

void Health::Decrease(int decrease_Factor)
{
    if(health < 0 )
    {
    health = 0;

    //set Health bar size

    setPixmap(QPixmap(":/Assets/misc/HealthBar (1).png").scaled(0,30,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    }
    else if (health >= 0)
    {
        //decrease health factor by decrease_Factor amounts

        health -= decrease_Factor;

        //reset Health bar size
        setPixmap(QPixmap(":/Assets/misc/HealthBar (1).png").scaled(3*health,30,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    }
}

//This function is responsible for maintaining the increase in player Health

void Health::Increase(int increase_Factor)
{
    if (health > 0 && health <= 80)
    {
        //increase player health by increase_factor amounts

        health += increase_Factor;

        //reset player healthbar size

        setPixmap(QPixmap(":/Assets/misc/HealthBar (1).png").scaled(3*health,30,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    }

    if(pixmap().width() > 240)
    setPixmap(QPixmap(":/Assets/misc/HealthBar (1).png").scaled(260,30,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}


int Health::getHealth()
{
    return health;
}

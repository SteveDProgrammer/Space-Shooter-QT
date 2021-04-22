//This file is defines the explosion animation when the player dies

#include "plane_explosion.h"
#include "_GM.h"

extern _GM *game;

//Plane_Explosion animation timer++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Plane_Explosion::Plane_Explosion(qreal x, qreal y)
{
    //set player explosion animation counter

    counter = 1;

    //Play player Explosion music

    game->ExplosionMusic();

    //set the first explosion sprite

    setPixmap(QPixmap(":/Assets/blue_shipv3/Explosion/Untitled-1.png"));

    // set position of the sprite

    setPos(x,y);

    //start player eplosion animation timer

    QTimer *ExplosionTimer = new QTimer();
    connect( ExplosionTimer,SIGNAL(timeout()),this,SLOT(Animate()) );
    ExplosionTimer->start(50);
}


//Animation sprites++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Plane_Explosion::Animate()
{ switch(counter)
    {
        case 1:setPixmap(QPixmap(":/Assets/blue_shipv3/Explosion/Explosion (1).png"));counter = 2;break;
        case 2:setPixmap(QPixmap(":/Assets/blue_shipv3/Explosion/Explosion (1).png"));counter = 3;break;
        case 3:setPixmap(QPixmap(":/Assets/blue_shipv3/Explosion/Explosion (2).png"));counter = 4;break;
        case 4:setPixmap(QPixmap(":/Assets/blue_shipv3/Explosion/Explosion (2).png"));counter = 5;break;
        case 5:setPixmap(QPixmap(":/Assets/blue_shipv3/Explosion/Explosion (3).png"));counter = 6;break;
        case 6:setPixmap(QPixmap(":/Assets/blue_shipv3/Explosion/Explosion (3).png"));counter = 7;break;
        case 7:setPixmap(QPixmap(":/Assets/blue_shipv3/Explosion/Explosion (4).png"));counter = 8;break;
        case 8:setPixmap(QPixmap(":/Assets/blue_shipv3/Explosion/Explosion (4).png"));counter = 9;break;
        case 9:setPixmap(QPixmap(":/Assets/blue_shipv3/Explosion/Explosion (5).png"));counter = 10;break;
        case 10:setPixmap(QPixmap(":/Assets/blue_shipv3/Explosion/Explosion (5).png"));counter = 11;break;
        case 11:setPixmap(QPixmap(":/Assets/blue_shipv3/Explosion/Explosion (6).png"));counter = 12;break;
        case 12:setPixmap(QPixmap(":/Assets/blue_shipv3/Explosion/Explosion (6).png"));counter = 13;break;
        case 13:setPixmap(QPixmap(":/Assets/blue_shipv3/Explosion/Explosion (7).png"));counter = 14;break;
        case 14:setPixmap(QPixmap(":/Assets/blue_shipv3/Explosion/Explosion (7).png"));counter = 15;break;
        case 15:setPixmap(QPixmap(":/Assets/blue_shipv3/Explosion/Explosion (8).png"));counter = 16;break;
        case 16:setPixmap(QPixmap(":/Assets/blue_shipv3/Explosion/Explosion (8).png"));counter = 17;break;
        case 17:setPixmap(QPixmap(":/Assets/blue_shipv3/Explosion/Explosion (9).png"));counter = 18;break;
        case 18:setPixmap(QPixmap(":/Assets/blue_shipv3/Explosion/Explosion (9).png"));counter = 1;break;
    }

}

//This Header file is for manipulating the bullet movement and controls

#include "bullet.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>

#include "_GM.h"
#include <QDebug>

extern _GM *game;

int Bullet::spriteCounter = 1; //defining the static data member in Bullet

//++++++++++++++++++++++++++++++++++++++++++++++ Bullet constructor +++++++++++++++++++++++++++++++++++++++++++++++++++++

Bullet::Bullet()
{
    anim_number_die = 1;

    explosionTimeLimit = 0;

    // Set Bullet Sprite According to Power up ....................................................................................

    if(spriteCounter == 1)
    {
        setPixmap(QPixmap(":/Assets/Bullets/bullet_v1.png").scaled(6,28,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    }
    else if(spriteCounter == 2)
    {
        setPixmap(QPixmap(":/Assets/Bullets/bullet_v2.png").scaled(6,28,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    }
    else if(spriteCounter == 3)
    {
        setPixmap(QPixmap(":/Assets/Bullets/bullet_v3_1.png").scaled(6,28,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    }

    //Initialize Bullet Position.....................................................................................................

    qreal bulletX = game->player->x()+(game->player->pixmap().width()/2 - pixmap().width()/2);
    qreal bulletY = game->player->y() - this->pixmap().height();
    setPos(bulletX , bulletY );

    // Creating the MoveTimer.........................................................................................................
    moveTimer = new QTimer();
    connect(moveTimer,SIGNAL(timeout()),this,SLOT(Move()));
    moveTimer->start(15);

}

void Bullet::Move()
{
//if bullet collides enemy, Destroy it............................................................................................

    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0 ; i < colliding_items.size() ; i++)
    {
        if( ( typeid(*(colliding_items[i])) == typeid(enemy) || typeid(*(colliding_items[i])) == typeid(Meteorites) )  && y() > game->scene->sceneRect().y() && game->health->getHealth() > 0) // y() > game->scene->sceneRect().y() , for ensuring that the bullet doesn't kill the out of bounds enemy
        {
            moveTimer->stop();

            //create score animation text image

            if(typeid(*(colliding_items[i])) == typeid(enemy))
            {
                hoveringscore = new Floating_Text(QPixmap(":/Assets/misc/score(+2).png").scaled(53,53,Qt::IgnoreAspectRatio,Qt::SmoothTransformation),x(),y());
                game->scene->addItem(hoveringscore);

                //Increase score

                game->score->setScore(2);

            }

            //Play Enemy Destruction Music

            QTimer::singleShot( 1,game->player,SLOT(playEnemyDestructionMusic()) );

            //remove enemy

            scene()->removeItem(colliding_items[i]);

            //delete enemy

            delete colliding_items[i];

//++++++++++++++++++++++++++++++++++++++++++ Enemy Explosion Timer +++++++++++++++++++++++++++++++++++++++++++++++++++++++

            EnemyExplosionTimer = new QTimer();
            connect( EnemyExplosionTimer,SIGNAL(timeout()),this,SLOT(dieExplosionAnimation()) );
            EnemyExplosionTimer->start(1);

            Destroy();//Call to Destroy Function

            return; // to ensure that the program doesn't execute after bullet is destroyed
        }

    }

    // Move the bullet

    this->setPos(x(),y() - 6);

    // Delete out of view bullet

    if( y() < game->scene->sceneRect().y())
    {
        //Bullet Fire Music

        scene()->removeItem(this);
        Destroy();
        delete this;
    }
}

void Bullet::Destroy()
{
    delete moveTimer;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++ Enemy Explosion sprites +++++++++++++++++++++++++++++++++++++++++++++++

void Bullet :: dieExplosionAnimation()
{
    explosionTimeLimit ++;
    if(explosionTimeLimit < 20)
    {
        if(spriteCounter == 1)
            switch(anim_number_die)
                { //Bullet type 1 explosion................................................................................

                    case 1 :setPixmap(QPixmap(":/Assets/Red_Dragon/Yellow Explosion/yellow_explosion (1).png").scaled(43,43,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); anim_number_die = 2; break;
                    case 2 :setPixmap(QPixmap(":/Assets/Red_Dragon/Yellow Explosion/yellow_explosion (2).png").scaled(86,86,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); anim_number_die = 3; break;
                    case 3 :setPixmap(QPixmap(":/Assets/Red_Dragon/Yellow Explosion/yellow_explosion (3).png").scaled(128,128,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); anim_number_die = 4; break;
                    case 4 :setPixmap(QPixmap(":/Assets/Red_Dragon/Yellow Explosion/yellow_explosion (4).png").scaled(128,128,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); anim_number_die = 5; break;
                    case 5 :setPixmap(QPixmap(":/Assets/Red_Dragon/Yellow Explosion/yellow_explosion (5).png").scaled(86,86,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); anim_number_die = 6; break;
                    case 6 :setPixmap(QPixmap(":/Assets/Red_Dragon/Yellow Explosion/yellow_explosion (6).png").scaled(43,43,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); anim_number_die = 1; break;
                }
        else if(spriteCounter == 2)
            switch(anim_number_die)
                { //bullet type 2 explosion...............................................................................

                    case 1 :setPixmap(QPixmap(":/Assets/Red_Dragon/Red Explosion/red_explosion (1).png").scaled(43,43,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); anim_number_die = 2; break;
                    case 2 :setPixmap(QPixmap(":/Assets/Red_Dragon/Red Explosion/red_explosion (2).png").scaled(86,86,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); anim_number_die = 3; break;
                    case 3 :setPixmap(QPixmap(":/Assets/Red_Dragon/Red Explosion/red_explosion (3).png").scaled(128,128,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); anim_number_die = 4; break;
                    case 4 :setPixmap(QPixmap(":/Assets/Red_Dragon/Red Explosion/red_explosion (4).png").scaled(128,128,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); anim_number_die = 5; break;
                    case 5 :setPixmap(QPixmap(":/Assets/Red_Dragon/Red Explosion/red_explosion (5).png").scaled(86,86,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); anim_number_die = 6; break;
                    case 6 :setPixmap(QPixmap(":/Assets/Red_Dragon/Red Explosion/red_explosion (6).png").scaled(43,43,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); anim_number_die = 1; break;
                }
        else if(spriteCounter == 3)
            switch(anim_number_die)
                { // Bullet type 2 explosion...............................................................................

                    case 1 :setPixmap(QPixmap(":/Assets/Red_Dragon/Green Explosion/green_explosion (1).png").scaled(43,43,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); anim_number_die = 2; break;
                    case 2 :setPixmap(QPixmap(":/Assets/Red_Dragon/Green Explosion/green_explosion (2).png").scaled(86,86,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); anim_number_die = 3; break;
                    case 3 :setPixmap(QPixmap(":/Assets/Red_Dragon/Green Explosion/green_explosion (3).png").scaled(128,128,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); anim_number_die = 4; break;
                    case 4 :setPixmap(QPixmap(":/Assets/Red_Dragon/Green Explosion/green_explosion (4).png").scaled(128,128,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); anim_number_die = 5; break;
                    case 5 :setPixmap(QPixmap(":/Assets/Red_Dragon/Green Explosion/green_explosion (5).png").scaled(86,86,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); anim_number_die = 6; break;
                    case 6 :setPixmap(QPixmap(":/Assets/Red_Dragon/Green Explosion/green_explosion (6).png").scaled(43,43,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); anim_number_die = 1; break;
                }
     }
     else if(explosionTimeLimit > 20)
     {  //Stop playing Animation...........................................................................................

        EnemyExplosionTimer->stop();
        scene()->removeItem(this);  //remove Bullet
        delete this;                //delete this
     }
}

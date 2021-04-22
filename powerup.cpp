//This file is resposible for maintaining the powerUps in the game

#include "powerup.h"
#include "bullet.h"

#include <stdlib.h>

#include "floating_text.h"

extern _GM *game;

//Power Up Constructor +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

PowerUP::PowerUP()
{

  //set a random Value for the powerUP item

    icon_counter =  1 + rand()%5;

  //set the sprite for powerUP item

  switch(icon_counter)
  {
    case 1: setPixmap(QPixmap(":/Assets/PowerUP/Bronze.png").scaled(28,45,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); break;
    case 2: setPixmap(QPixmap(":/Assets/PowerUP/Silver.png").scaled(28,45,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); break;
    case 3: setPixmap(QPixmap(":/Assets/PowerUP/Gold.png").scaled(28,45,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); break;
    case 4: setPixmap(QPixmap(":/Assets/PowerUP/Shield.png").scaled(45,45,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); break;
    case 5: setPixmap(QPixmap(":/Assets/PowerUP/Health.png").scaled(33,31,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); break;
  }

  // randomize the x-axis of the power up item

  int ScreenLimit = game->scene->sceneRect().width() - pixmap().width();
  x_axis = rand()%ScreenLimit;

  //set the position of this item

  setPos( x_axis , (game->scene->sceneRect().y() - pixmap().height()) );

  //Power Up Move Timer

  powerUP_MoveTimer = new QTimer();
  connect( powerUP_MoveTimer,SIGNAL(timeout()),this,SLOT(powerUpMOve()) );
  powerUP_MoveTimer->start(10);
}

//PowerUP definition +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void PowerUP::powerUpMOve()
{
    setPos(x(),y()+3);

    //Create List to store colliding items

    QList<QGraphicsItem *> collision_items = collidingItems();


    if(y() > (game->scene->sceneRect().height() + game->scene->sceneRect().y()) )
    {
        delete powerUP_MoveTimer;

        game->scene->removeItem(this);
        delete this;

        return;
    }


    for(int i = 0 ; i < collision_items.size() ; i++)
    {
        if(typeid(*collision_items[i]) == typeid(Player))
        {
            delete powerUP_MoveTimer;

            //set bullet sprite according to the power up the player recieves

            switch(icon_counter)
            {
              case 1: Bullet::spriteCounter = 1;game->score->setScore(10);game->player->setAndPlayItemRecieveMusic(PowerUpCollisionmedia,0); break;
              case 2: Bullet::spriteCounter = 2;game->score->setScore(20);game->player->setAndPlayItemRecieveMusic(PowerUpCollisionmedia,0); break;
              case 3: Bullet::spriteCounter = 3;game->score->setScore(30);game->player->setAndPlayItemRecieveMusic(PowerUpCollisionmedia,0); break;
              case 4: Player::shieldOn = true; game->player->setAndPlayItemRecieveMusic(ShieldUp,icon_counter); break;
              case 5: game->health->Increase(5);
                      game->player->setAndPlayItemRecieveMusic(QUrl("qrc:/Assets/HealthGet.mp3"),icon_counter);
                      Floating_Text *healthIncrease = new Floating_Text(QPixmap(":/Assets/misc/health(+5).png").scaled(30,25,Qt::IgnoreAspectRatio,Qt::SmoothTransformation),x(),y());
                      game->scene->addItem(healthIncrease);
                      break;
            }

            //Increase score according to the powerUp

            if(icon_counter == 1)
            {
                Floating_Text *hoveringScore = new Floating_Text(QPixmap(":/Assets/misc/score(+10).png").scaled(40,40,Qt::IgnoreAspectRatio,Qt::SmoothTransformation),x(),y());
                game->scene->addItem(hoveringScore);
            }
            else if(icon_counter == 2)
            {
                Floating_Text *hoveringScore = new Floating_Text(QPixmap(":/Assets/misc/score(+20).png").scaled(40,40,Qt::IgnoreAspectRatio,Qt::SmoothTransformation),x(),y());
                game->scene->addItem(hoveringScore);
            }
            else if(icon_counter == 3)
            {
                Floating_Text *hoveringScore = new Floating_Text(QPixmap(":/Assets/misc/score(+30).png").scaled(40,40,Qt::IgnoreAspectRatio,Qt::SmoothTransformation),x(),y());
                game->scene->addItem(hoveringScore);
            }

            game->scene->removeItem(this);
            delete this;

            return;
        }
    }
}

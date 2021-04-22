//This file is responsible for maintining the motion of the meteorites

#include "meteorites.h"

#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>

#include <stdlib.h> //rand() function

#include "_GM.h"


extern _GM * game;

//Meteorites Constructor ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Meteorites::Meteorites()
{
    //Initialize the myRotation counter(this is for limtiting the time a meteor rotates in one direction)

    myRotation = 0;

    //Initialize rotationCounter(this is for setting the angle of rotation of the meteor)

    rotationCounter = 0;

    //Draw the meteorites

    meteorCounter = 1+ rand()%4; //set the counter for setting the meteor sprites

    int ScreenLimit = game->scene->sceneRect().width() - 2*pixmap().width();

    // set the sprite

    if(meteorCounter == 1)
    {        
        setPixmap(QPixmap(":/Assets/Meteorites/Meteorite (3).png").scaled(68,68,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

        random_x = 600 + rand() % ScreenLimit;
    }
    else if(meteorCounter == 2)
    {
        setPixmap(QPixmap(":/Assets/Meteorites/Meteorite (2).png").scaled(68,68,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

        random_x = 400 + rand() % (ScreenLimit - 200);
    }
    else if(meteorCounter == 3)
    {
        setPixmap(QPixmap(":/Assets/Meteorites/Meteorite (1).png").scaled(68,68,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

        random_x = 200 + rand() % (ScreenLimit - 400);
    }
    else if(meteorCounter == 4)
    {
        setPixmap(QPixmap(":/Assets/Meteorites/Meteorite (4).png").scaled(68,68,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

        random_x =  rand() % (ScreenLimit - 600);
    }

    setPos(random_x,y()); // Setting the position of the meteor

    // allocating memory for the meteor move timer and Initializing it

    MeteorMoveTimer = new QTimer();
    connect(MeteorMoveTimer,SIGNAL(timeout()),this,SLOT(Move()));
    MeteorMoveTimer->start(10);

    // allocating memory for Rotate animation timer and Initializing it

    rotateAnimTimer = new QTimer();
    connect( rotateAnimTimer,SIGNAL(timeout()),this,SLOT(playRotateAnimation()) );
    rotateAnimTimer->start(3);
}

// This function is for making the meteorites move++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Meteorites::Move()
{

    // delete off-scene meteors

    if( pos().y() > scene()->height() + scene()->sceneRect().y() + pixmap().height())
        {
            delete MeteorMoveTimer;

            delete rotateAnimTimer;

            scene()->removeItem(this);
            delete this;
            return;
        }

    //move the meteors

    if( x() > 0)
    {
        setPos(x() - 3, y() + 1);
    }

    if(x() < scene()->width())
    {
        setPos(x() + 3 , y() + 1);
    }

}

//This function is for making the metrorites rotate++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Meteorites :: playRotateAnimation()
{

    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0 ; i < colliding_items.size() ; i++)
    {
        if( typeid(*(colliding_items[i])) == typeid(Meteorites) || typeid(*(colliding_items[i])) == typeid(PowerUP))
        {
            if(rotationCounter < 250)
            {
                rotationCounter++;
                myRotation--;
                this->setRotation(myRotation);

            }
            else if(rotationCounter > 250)
            {
                rotationCounter++;
                myRotation++;
                this->setRotation(myRotation);
                if(rotationCounter == 500)
                    rotationCounter = 0;
            }

            return;
        }
    }

  if(rotationCounter < 250)
  {
      if( x() > 0 && x() < scene()->width())
      {
          rotationCounter++;
          myRotation++;
          this->setRotation(myRotation);
      }
      else
      {
          rotationCounter++;
          myRotation--;
          this->setRotation(myRotation);
          if(rotationCounter == 500)
          rotationCounter = 0;
      }
  }
  else if(rotationCounter > 250)
  {
      if( x() > 0 && x() < scene()->width())
      {
          rotationCounter++;
          myRotation--;
          this->setRotation(myRotation);
          if(rotationCounter == 500)
          rotationCounter = 0;
      }
      else
      {
          rotationCounter++;
          myRotation++;
          this->setRotation(myRotation);
      }
  }
}


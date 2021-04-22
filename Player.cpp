//This file defies defines the player behaviour

#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>

#include "enemy.h"
#include "health.h"
#include "_GM.h"

#include "floating_text.h"

#include <stdlib.h>

#include <QDebug>

#include "game_over.h"
#include "plane_explosion.h"

extern _GM *game;

//Player static member definition +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

bool Player::shieldOn = false;
bool Player::Bull_Tag = false;
bool Player::player_Left_Tag = false;
bool Player::player_Right_Tag = false;

//Player Constructor definition +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Player::Player(qreal widthValue):sWidth(widthValue)
{
    this->installEventFilter(this);

    // Set Graphics

    setPixmap(QPixmap(":/Assets/blue_shipv3/Ship (1).png").scaled(84,84,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    //player_collision_media declaration and initialization

    player_collision_media = new QMediaPlayer();
    player_collision_media->setMedia(QUrl("qrc:/Assets/blue_shipv3/ouch.mp3"));

    anim_number = 1; //initialize animation counter

    //memory Allocation for poweer up player

    powerUpMedia = new QMediaPlayer();

    //playermove animation timer

    moveAnimTimer = new QTimer();
    connect( moveAnimTimer,SIGNAL(timeout()),this,SLOT(playAnimation()) );
    moveAnimTimer->start(50);


//+++++++++++++++++++++++++++++++++++++++++++++++++Media Stuffs+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    //Declare and Initialize enemy destruction music

    enemy_destroy_media = new QMediaPlayer();

    //bullet_fire_media declaration and initialization

    bullet_fire_media = new QMediaPlayer();
    bullet_fire_media->setMedia(BulletFire);

//+++++++++++++++++++++++++++++++++++++Left and Right Move Timer Mechanism+++++++++++++++++++++++++++++++++++++++++++++++++

    //Player Move Left Timer Tagger

    Player_Left_Move_Timer_Tagger = new QTimer();
    connect( Player_Left_Move_Timer_Tagger,SIGNAL(timeout()),this,SLOT(setPlayerLeftTag()) );
    Player_Left_Move_Timer_Tagger->start(3);

    //Player Move Left Timer

    Player_Left_Move_Timer = new QTimer();
    connect( Player_Left_Move_Timer,SIGNAL(timeout()),this,SLOT(Player_Left_Move_Mechanism()) );

    //Player Move Right Timer Tagger

    Player_Right_Move_Timer_Tagger = new QTimer();
    connect( Player_Right_Move_Timer_Tagger,SIGNAL(timeout()),this,SLOT(setPlayerRightTag()) );
    Player_Right_Move_Timer_Tagger->start(3);

    //Player Move Right Timer

    Player_Right_Move_Timer = new QTimer();
    connect( Player_Right_Move_Timer,SIGNAL(timeout()),this,SLOT(Player_Right_Move_Mechanism()) );

    //Bullet Shooter Timer Tagger

    Bullet_Shoot_Timer_Tagger = new QTimer();
    connect( Bullet_Shoot_Timer_Tagger,SIGNAL(timeout()),this,SLOT(setBulletTag()) );
    Bullet_Shoot_Timer_Tagger->start(5);

    //Bullet Shooter Timer

    Bullet_Shoot_Timer = new QTimer();
    connect( Bullet_Shoot_Timer,SIGNAL(timeout()),this,SLOT(BulletMechanism()) );

//++++++++++++++++++++++++++++++++++++++++++++Collision Detection Timers+++++++++++++++++++++++++++++++++++++++++++++++++++

    //PLayer Collision Timer

    QTimer *playerCollisionTimer = new QTimer();
    connect( playerCollisionTimer,SIGNAL(timeout()),this,SLOT(Player_Collision()) );
    playerCollisionTimer->start(75);

    //Enenmy destruction Music


    enemy_destroy_media->setMedia(QUrl("qrc:/Assets/misc/Music/nani.mp3 "));

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++Key Events+++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Player::keyPressEvent(QKeyEvent *event)
{
    eventFilter(event);
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    eventFilter(event);
}

bool Player::eventFilter(QEvent * event)
{

    if(event->type()==QEvent::KeyPress)
    {
        pressed_released_keys += ((QKeyEvent*)event)->key();

    if( pressed_released_keys.contains(Qt::Key_Left) && pressed_released_keys.contains(Qt::Key_Space) )//(pressed_released_keys.contains(Qt::Key_Left) && pressed_released_keys.contains(Qt::Key_Space) )
                {
                    if (player_Left_Tag == false)
                    {
                    player_Left_Tag = true;
                    player_Right_Tag = false;
                    }
                }

    if( pressed_released_keys.contains(Qt::Key_Right) && pressed_released_keys.contains(Qt::Key_Space) )//(pressed_released_keys.contains(Qt::Key_Right) && pressed_released_keys.contains(Qt::Key_Space) )
                {
                    if (player_Right_Tag == false)
                    {
                    player_Right_Tag = true;
                    player_Left_Tag = false;
                    }
                }

    if(pressed_released_keys.contains(Qt::Key_Left))
                {
                    if (player_Left_Tag == false)
                    {
                    player_Left_Tag = true;
                    player_Right_Tag = false;
                    }
                }

    if(pressed_released_keys.contains(Qt::Key_Right))
                {
                    if (player_Right_Tag == false)
                    {
                    player_Right_Tag = true;
                    player_Left_Tag = false;
                    }
                }
    if(pressed_released_keys.contains(Qt::Key_Space)) //(!pressed_released_keys.contains(Qt::Key_Left) && !pressed_released_keys.contains(Qt::Key_Right) &&
                {
                    if (Bull_Tag == false)
                    Bull_Tag = true;
                }
    }

    else if(event->type()==QEvent::KeyRelease)
    {
        pressed_released_keys -= ((QKeyEvent*)event)->key();

        if(!pressed_released_keys.contains(Qt::Key_Space))
        {
            Bull_Tag = false;
        }

        if(!pressed_released_keys.contains(Qt::Key_Right))
        {
            player_Right_Tag = false;
        }

        if(!pressed_released_keys.contains(Qt::Key_Left))
        {
            player_Left_Tag = false;
        }

        if(!pressed_released_keys.contains(Qt::Key_Right) && pressed_released_keys.contains(Qt::Key_Left))
        {
            player_Right_Tag = false;
        }

        if (!pressed_released_keys.contains(Qt::Key_Left) && pressed_released_keys.contains(Qt::Key_Right))
        {
            player_Left_Tag = false;
        }

    }


    return false;
}

//Player Left Move Mechanism ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Player::setPlayerLeftTag()
{
    if( player_Left_Tag == true && Player_Left_Move_Timer->isActive() == false )
    {
        Player_Left_Move_Timer->start(10);
    }
    else if(player_Left_Tag == false && Player_Left_Move_Timer->isActive() == true)
    {
        Player_Left_Move_Timer->stop();
    }
}

void Player::Player_Left_Move_Mechanism()
{
        if(x() > 20 - pixmap().width()/3)   // 10 because of edge correction
        setPos(x() - 7, y());
}

//Player Right Move Mechanism +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Player::setPlayerRightTag()
{
    if(Player_Right_Move_Timer->isActive() == false && player_Right_Tag == true)
    {
        Player_Right_Move_Timer->start(10);
    }
    else if(player_Right_Tag == false && Player_Right_Move_Timer->isActive() == true)
    {
        Player_Right_Move_Timer->stop();
    }
}

void Player::Player_Right_Move_Mechanism()
{
        if(x() < (sWidth - 2*(pixmap().width()/3)) - 20)   // 10 because of edge correction
        setPos(x() + 7, y());
}

//Bullet Move Mechanism +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Player::setBulletTag()
{
    if(Bullet_Shoot_Timer->isActive() == false && Bull_Tag == true)
    {
        Bullet_Shoot_Timer->start(50);
    }
    else if(Bull_Tag == false && Bullet_Shoot_Timer->isActive() == true)
    {
        Bullet_Shoot_Timer->stop();
    }
}

void Player::BulletMechanism()
{
        //This timer controls the bullet frequency

        Bullet_Shoot_Timer->setInterval(250);

        Bullet *bullet = new Bullet();             //new bullet is created and current x and y position of player is passed

        game->scene->addItem(bullet);                       //Bullet is added to the scene

        //Play Bullet Creation Music

        if(bullet_fire_media->state() == QMediaPlayer::PlayingState)
        {
            bullet_fire_media->setPosition(0);
            bullet_fire_media->play();
        }
        else bullet_fire_media->play();
}

//Player Shield animation sprites ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Player:: playAnimation()
{
    if(shieldOn == false)
    {
        switch(anim_number)
        {
            case 1 :setPixmap(Ship1); anim_number = 2; break;
            case 2 :setPixmap(Ship2); anim_number = 3; break;
            case 3 :setPixmap(Ship3); anim_number = 4; break;
            case 4 :setPixmap(Ship4); anim_number = 5; break;
            case 5 :setPixmap(Ship4); anim_number = 6; break;
            case 6 :setPixmap(Ship3); anim_number = 7; break;
            case 7 :setPixmap(Ship2); anim_number = 8; break;
            case 8 :setPixmap(Ship1); anim_number = 1; break;
        }
    }
    else if (shieldOn == true)
    {

        switch(anim_number)
        {
            case 1 :setPixmap(ShipShield1); anim_number = 2; break;
            case 2 :setPixmap(ShipShield2); anim_number = 3; break;
            case 3 :setPixmap(ShipShield3); anim_number = 4; break;
            case 4 :setPixmap(ShipShield4); anim_number = 5; break;
            case 5 :setPixmap(ShipShield4); anim_number = 6; break;
            case 6 :setPixmap(ShipShield3); anim_number = 7; break;
            case 7 :setPixmap(ShipShield2); anim_number = 8; break;
            case 8 :setPixmap(ShipShield1); anim_number = 1; break;
        }
    }
}

//Enemy spawning function +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Player::enemy_Spawn()
{
       // create and add items to the scene

       enemy *ENEMY = new enemy();
       scene()->addItem(ENEMY);
}

//Enemy Spawning function +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Player::meteoritesSpawn()
{
    Meteorites *meteor = new Meteorites();
    scene()->addItem(meteor);
}

//Power_ups and collectibles spawning functions +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Player::powerUP_Spawn()
{
       // create and add items to the scene

       PowerUP *powerUP_Item = new PowerUP();
       scene()->addItem(powerUP_Item);
}

//player collision checking function ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Player::Player_Collision()
{
    colliding_items = collidingItems();

    //If enemy collides Player then destroy both or reduce player health and destroy enemy

    for(int i = 0 ; i < colliding_items.size() ; i++)
    {
        if (typeid(*(colliding_items[i])) == typeid(enemy))
           {
                if(shieldOn == false)
                     {
                        game->health->Decrease(10);                   //Decrease Player Health

                        //create score animation text image

                        Floating_Text *hoveringscore = new Floating_Text(QPixmap(":/Assets/misc/health(-10).png").scaled(45,45,Qt::IgnoreAspectRatio,Qt::SmoothTransformation),x(),y());
                        game->scene->addItem(hoveringscore);
                     }

                //play player collision media

                if(player_collision_media->state() == QMediaPlayer::PlayingState && shieldOn == false)
                {
                    player_collision_media->setPosition(0);
                    player_collision_media->play();
                }

                //play item recieve music if shield is off

                if(shieldOn == true)
                {
                    shieldOn = false;
                    setAndPlayItemRecieveMusic(ShieldDown,0);
                }

                //play player collision media

                else player_collision_media->play();

                scene()->removeItem(colliding_items[i]);          //remove enemy
                delete colliding_items[i];                        //delete enemy

                if( game->health->getHealth() < 1)      //Player is dead if health is zero
                    {

                    //create and play plane explosion

                    Plane_Explosion *explode = new Plane_Explosion(x(),y());

                    scene()->removeItem(this);                //remove player if health is zero
                    delete this;

                    game->scene->addItem(explode);

                    //show Game over

                        Game_Over * gameOVER = new Game_Over();
                        game->scene->addItem(gameOVER);

                          //delete player
                        return;
                    }
          }

        //if player collides with meteorites  decrease health or destroy player

        else if(typeid(*(colliding_items[i])) == typeid(Meteorites))
            {
            if(shieldOn == false)
                 {
                    game->health->Decrease(5);                   //Decrease Player Health


                    //create score animation text image

                    Floating_Text *hoveringscore = new Floating_Text(QPixmap(":/Assets/misc/health(-5).png").scaled(45,45,Qt::IgnoreAspectRatio,Qt::SmoothTransformation),x(),y());
                    game->scene->addItem(hoveringscore);
                 }

            //play player collision media

            if(player_collision_media->state() == QMediaPlayer::PlayingState && shieldOn == false)
            {
                player_collision_media->setPosition(0);
                player_collision_media->play();
            }

            //play item recieve music

            if(shieldOn == true)
            {
                shieldOn = false;
                setAndPlayItemRecieveMusic(ShieldDown,4);
            }

            else player_collision_media->play();

            scene()->removeItem(colliding_items[i]);          //remove enemy
            delete colliding_items[i];                        //delete enemy

            if( game->health->getHealth() < 1)      //Player is dead if health is zero
                {

                Plane_Explosion *explode = new Plane_Explosion(x(),y());

                scene()->removeItem(this);                //remove player if health is zero
                delete this;                              //delete player


                game->scene->addItem(explode);

                //show Game over

                    Game_Over * gameOVER = new Game_Over();
                    game->scene->addItem(gameOVER);
                    return;
                }
            }
     }

}

// play enemy destruction music function ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Player::playEnemyDestructionMusic()
{
    //if

    if(enemy_destroy_media->state() == QMediaPlayer::PlayingState)
    {
        enemy_destroy_media->stop();
    }
        //Play enemy destruction music
        enemy_destroy_media->setPosition(500);
        enemy_destroy_media->setVolume(50);
        enemy_destroy_media->play();
}

//Music PLaying function (Plays music according to the passed arguments) ++++++++++++++++++++++++++++++++++++++++++++++++

void Player::setAndPlayItemRecieveMusic(QMediaContent music,int itemCounter)
{
    if(powerUpMedia->state() == QMediaPlayer::PlayingState)
    powerUpMedia->stop();

    powerUpMedia->setMedia(music);
    if(itemCounter == 4 )
        {
            powerUpMedia->setPosition(1300);
        }

    if (itemCounter == 5)
        {
           powerUpMedia->setPosition(45);
        }
    powerUpMedia->play();
}

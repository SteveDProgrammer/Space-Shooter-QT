#ifndef PLAYER_H
#define PLAYER_H

#include<QGraphicsPixmapItem>
#include<QObject>

#include <typeinfo>
#include <QList>

#include "bullet.h"
#include <QTimer>
#include <QMediaPlayer>

class Player : public QObject ,public QGraphicsPixmapItem
{   Q_OBJECT
private:


    //Animation and Music resources

    QPixmap Ship1 = QPixmap(":/Assets/blue_shipv3/Ship (1).png").scaled(84,84,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    QPixmap Ship2 = QPixmap(":/Assets/blue_shipv3/Ship (2).png").scaled(84,84,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    QPixmap Ship3 = QPixmap(":/Assets/blue_shipv3/Ship (3).png").scaled(84,84,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    QPixmap Ship4 = QPixmap(":/Assets/blue_shipv3/Ship (4).png").scaled(84,84,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    QPixmap ShipShield1 = QPixmap(":/Assets/blue_shipv3/Shield_mode/Shield (1).png").scaled(84,84,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    QPixmap ShipShield2 = QPixmap(":/Assets/blue_shipv3/Shield_mode/Shield (2).png").scaled(84,84,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    QPixmap ShipShield3 = QPixmap(":/Assets/blue_shipv3/Shield_mode/Shield (3).png").scaled(84,84,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    QPixmap ShipShield4 = QPixmap(":/Assets/blue_shipv3/Shield_mode/Shield (4).png").scaled(84,84,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    QImage BackGround1 = QImage(":/Assets/Background/Background (2).png");
    QImage BackGround2 = QImage(":/Assets/Background/Background (1).png");

    //Media Contents

    QMediaContent BulletFire = QUrl("qrc:/Assets/Bullets/pew-pew.mp3");
    QMediaContent PlayerCollisionMedia = QUrl("qrc:/Assets/misc/Music/crash.mp3");

    QMediaContent ShieldDown = QUrl("qrc:/Assets/misc/Music/Shield off.mp3");

    // Bullet Music, Enemy Destruction Music And Player Collision Music

    QMediaPlayer *bullet_fire_media;
    QMediaPlayer *enemy_destroy_media;
    QMediaPlayer *player_collision_media;
    QMediaPlayer *powerUpMedia;


    //.................................//

    int setBackGroundflag = 1;

    qreal sWidth;

    static bool Bull_Tag;
    static bool player_Left_Tag;
    static bool player_Right_Tag;


    //Player animation counter
    int anim_number;

    //player move animation timer
    QTimer *moveAnimTimer;

    //Player Left Move Timer
    QTimer *Player_Left_Move_Timer;
    //Player Left Move Timer Tagger
    QTimer *Player_Left_Move_Timer_Tagger;

    //Player Right Timer
    QTimer *Player_Right_Move_Timer;
    //Player Right Move Timer Tagger
    QTimer *Player_Right_Move_Timer_Tagger;

    //Bullet Shoot Timer
    QTimer *Bullet_Shoot_Timer;
    //Bullet Shooter Timer Tagger
    QTimer *Bullet_Shoot_Timer_Tagger;

    //Collision Items List
    QList<QGraphicsItem *> colliding_items;

    //Pressed and Realeased Keys list
    QSet<int> pressed_released_keys;

public:
    Player(qreal widthValue);

    static bool shieldOn;

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    bool eventFilter(QEvent * event);

public slots:

    void enemy_Spawn();
    void meteoritesSpawn();
    void powerUP_Spawn();

    void setPlayerLeftTag();
    void Player_Left_Move_Mechanism();

    void setPlayerRightTag();
    void Player_Right_Move_Mechanism();

    void setBulletTag();
    void BulletMechanism();

    void Player_Collision();
    void playAnimation();

//Enemy And Bullet Music
    void playEnemyDestructionMusic();
    void setAndPlayItemRecieveMusic(QMediaContent music,int itemCounter);
};

#endif

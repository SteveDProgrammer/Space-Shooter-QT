#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include "player.h"

#include "floating_text.h"

#include "enemy.h"
#include "meteorites.h"

class Bullet: public QObject, public QGraphicsPixmapItem
{   Q_OBJECT

    int anim_number_die;

    int explosionTimeLimit;

    //floating score animation

    Floating_Text *hoveringscore;

    int test;

    //enemy Explosion Timer

    QTimer *EnemyExplosionTimer;

    //meteor explosion Timer

    QTimer *MeteorExplosionTimer;

    //Move Timer

    QTimer *moveTimer;

public:
    Bullet();
    void Destroy();

    //PixMap Sprite Counter

    static int spriteCounter;

public slots:
    void Move();

    void dieExplosionAnimation();
};

#endif // BULLET_H


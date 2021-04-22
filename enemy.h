#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class enemy: public QObject, public QGraphicsPixmapItem
{   Q_OBJECT

    //Animation and Audio Resources

    //Dragon Fly Sprites

    QPixmap Dragon1 = QPixmap(":/Assets/Red_Dragon/Red_Dragon (1).png").scaled(128,128,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    QPixmap Dragon2 = QPixmap(":/Assets/Red_Dragon/Red_Dragon (2).png").scaled(128,128,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    QPixmap Dragon3 = QPixmap(":/Assets/Red_Dragon/Red_Dragon (3).png").scaled(128,128,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    QPixmap Dragon4 = QPixmap(":/Assets/Red_Dragon/Red_Dragon (4).png").scaled(128,128,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    //Enemy Move Timer
    QTimer * EnemyMoveTimer;

    //Enemy animation counter
    int anim_number_fly;

    //Enemy fly animation timer
    QTimer *flyAnimTimer;

public:
    enemy();


public slots:
    void Move();
    void playFlyAnimation();
};

#endif // ENEMY_H

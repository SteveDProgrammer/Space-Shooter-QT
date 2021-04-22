#ifndef POWERUP_H
#define POWERUP_H

#include <QObject>
#include <QTimer>

#include <QList>
#include <typeinfo>

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include <QMediaPlayer>

#include "_GM.h"

class PowerUP: public QObject,public QGraphicsPixmapItem
{Q_OBJECT

    QTimer *powerUP_MoveTimer;
    qreal x_axis;

    //shield stuffs

    QMediaContent ShieldUp = QUrl("qrc:/Assets/misc/Music/Shield on.mp3");

    //power Up Music

    QMediaContent PowerUpCollisionmedia = QUrl("qrc:/Assets/misc/Music/powerup.mp3");

    //Counter for setting Power_up Item Sprite

    int icon_counter;

public:
    PowerUP();

public slots:

    void powerUpMOve();

};

#endif // POWERUP_H

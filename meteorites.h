#ifndef METEORITES_H
#define METEORITES_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Meteorites: public QObject, public QGraphicsPixmapItem
{ Q_OBJECT

    int meteorCounter;
    int rotationCounter;

    qreal random_x;

    qreal myRotation;

    //Meteor Move Timer
    QTimer *MeteorMoveTimer;

    //Meteor fly animation timer
    QTimer *rotateAnimTimer;

public:
    Meteorites();

public slots:
    void Move();
    void playRotateAnimation();
};

#endif // METEORITES_H

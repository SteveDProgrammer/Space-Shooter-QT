#ifndef PLANE_EXPLOSION_H
#define PLANE_EXPLOSION_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMediaPlayer>

class Plane_Explosion:public QObject,public QGraphicsPixmapItem
{Q_OBJECT

public:

    Plane_Explosion(qreal x, qreal y);
    int counter ;

public slots:

    void Animate();

};

#endif // PLANE_EXPLOSION_H

#ifndef _GM_H
#define _GM_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>

#include "player.h"
#include "Score.h"
#include "health.h"
#include "powerup.h"

#include "meteorites.h"

#include "header_body.h"

class _GM: public QGraphicsView
{

public:
    _GM();

    void Pause(int);

    QMediaPlayer *MMusic;

    QGraphicsScene *scene;
    Player *player ;

    Score * score = new Score();
    Health * health = new Health();

    void ExplosionMusic();

public slots:

    void start();


};

#endif // _GM_H

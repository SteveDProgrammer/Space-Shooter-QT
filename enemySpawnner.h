#ifndef ENEMYSPAWNNER_H
#define ENEMYSPAWNNER_H

#include <QObject>
#include <QTimer>
#include "player.h"

class enemySpawnner: public QObject
{ Q_OBJECT
public:
    enemySpawnner(Player *, QTimer *&eTimer);

//public slots:
//    void spawn();
};

#endif // ENEMYSPAWNNER_H

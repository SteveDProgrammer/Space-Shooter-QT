#include <enemySpawnner.h>
#include "enemies.h"
#include <QGraphicsScene>

enemySpawnner::enemySpawnner(Player * player , QTimer * &eTimer )
{
    connect (eTimer,SIGNAL(timeout()),player,SLOT(spawn()) );
}

//void enemySpawnner::spawn()
//{
//       // create and add items to the scene

//       Enemies *enemy = new Enemies();
//       scene()->addItem(enemy);
//}

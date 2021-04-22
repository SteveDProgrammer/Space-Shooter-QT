#ifndef GAME_OVER_H
#define GAME_OVER_H

#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>


class Game_Over: public QObject, public QGraphicsPixmapItem
{Q_OBJECT

    int counter;

public:
    Game_Over();

public slots:
    void display();
};

#endif // GAME_OVER_H

#ifndef HEALTH_H
#define HEALTH_H

//#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>

class Health :  public QGraphicsPixmapItem
{
    int health;
public:
    Health();//QGraphicsTextItem *Parent = 0);

    void Decrease(int);
    int getHealth();

    void Increase(int increase_Factor);
};

#endif // HEALTH_H

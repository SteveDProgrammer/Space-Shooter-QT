#ifndef ENEMIES_H
#define ENEMIES_H

#include <QGraphicsRectItem>
#include <QObject>

class Enemies: public QObject, public QGraphicsRectItem
{  Q_OBJECT

public:
    Enemies();
public slots:
    void Move();
};

#endif // ENEMIES_H

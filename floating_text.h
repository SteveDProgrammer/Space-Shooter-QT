#ifndef FLOATING_TEXT_H
#define FLOATING_TEXT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

#include <QGraphicsScene>

class Floating_Text:public QObject, public QGraphicsPixmapItem
{Q_OBJECT
    //Timer to manipulate the up and down movement of the text image

    QTimer *moveTimer;

    //move animation required variables

    bool left_right_counter = true;
    float counter;

    //animation kill time left counter

    int deathCounter;

public:

   Floating_Text(QPixmap holder, qreal x, qreal y);

public slots:
    //Text Item Move Mechanism

    void moveAnimation();
};

#endif // FLOATING_TEXT_H

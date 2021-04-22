#ifndef MENUBUTTONS_H
#define MENUBUTTONS_H

#include <QGraphicsPixmapItem>
#include <QObject>

class menuButtons:public QObject, public QGraphicsPixmapItem
{Q_OBJECT

    int animation_counter;

public:

    //constructors

    menuButtons();

    //keyBoard events

    void keyPressEvent(QKeyEvent *event);

public slots:

    void animate();
};

#endif // MENUBUTTONS_H

//This file is for enemy initialization and enemy movement

#include "enemies.h"
#include <QGraphicsScene>
#include <stdlib.h> // For Random function... rand()

#include <QTimer>

Enemies::Enemies()
{
    int x_coordinate = rand() % 700;                           //set a Random x_coordinate
    setRect(0,0,100,100);                                      //initialize the newly created enemy object
    setPos(x_coordinate,scene()->height()+rect().height());    //set random position w.r.t x-coordinate

    //Timer for moving Enemy

    QTimer *enemyTimer = new QTimer();                             //create an enemy Timer
    connect(enemyTimer,SIGNAL(timeout()),this,SLOT(Move()) );              //call to connect funtion and use of signal and slot
    enemyTimer->start(50);                                          //call to start function of enemyTimer
}

void Enemies::Move()
{
    setPos(x(),y()+5);
}

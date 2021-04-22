//This program defines the score achievement and health deduction animation

#include "floating_text.h"
#include "_GM.h"

extern _GM * game;

// takes a pixmap item and the enmey or player position as an argument

Floating_Text::Floating_Text(QPixmap holder , qreal x , qreal y)
{
    //setPosition

    setPos(x,y);

    //set graphics that has been passed to the constructor

    setPixmap(holder);

    //Move sprite Timer

    moveTimer = new QTimer();
    connect( moveTimer , SIGNAL(timeout()) , this , SLOT(moveAnimation()) );
    moveTimer->start(10);

    //animation left right direction changing counter

    counter = 5;

    deathCounter = 0;
}



void Floating_Text::moveAnimation()
{
    deathCounter++;

    if(deathCounter > 50)
    {
        moveTimer->stop();

        game->scene->removeItem(this);

        delete this;

        return;
    }

    if(left_right_counter == true)
    {
        setPos( x() + 2 , y() - 2 );

        counter++;

        if(counter == 10)
        left_right_counter = false;
    }
    else if (left_right_counter == false)
    {
        setPos( x() - 2 , y() - 2 );

        counter--;

        if(counter == 0)
        left_right_counter = true;
    }
}

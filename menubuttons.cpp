//This function is for the display text in the menu

#include "menubuttons.h"
#include "_GM.h"

extern _GM *game;

//menu Buttons Constructor ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

menuButtons::menuButtons()
{
    //set the animation counter

    animation_counter = 1;

    //set the linked image

    setPixmap(QPixmap(":/Assets/Menu/Start.png").scaled(400,50,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    //set Pimap Position

    setPos( 400-pixmap().width()/2 , 600-pixmap().height()/2 + 55 );

    //Initialize and start timer

    QTimer *animationTimer = new QTimer();
    connect( animationTimer,SIGNAL(timeout()),this,SLOT(animate()) );
    animationTimer->start(18);
}

//game start button press event++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void menuButtons::keyPressEvent(QKeyEvent * event)
{
    if(event->type() == QEvent::KeyPress && event->key() == Qt::Key_Space)
        {
           game->start();
        }
}

//Button animation sprites+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void menuButtons::animate()
{
    this->setFocus();
    switch(animation_counter)
    {
        case 1:setPixmap(QPixmap(":/Assets/Menu/Start.png").scaled(601,71,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));setPos( 400-pixmap().width()/2 -1, 600-pixmap().height()/2 + 55 +1); animation_counter = 2; break;
        case 2:setPixmap(QPixmap(":/Assets/Menu/Start.png").scaled(603,73,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));setPos( 400-pixmap().width()/2 -2, 600-pixmap().height()/2 + 55 +2); animation_counter = 3; break;
        case 3:setPixmap(QPixmap(":/Assets/Menu/Start.png").scaled(605,75,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));setPos( 400-pixmap().width()/2 -3, 600-pixmap().height()/2 + 55 +3); animation_counter = 4; break;
        case 4:setPixmap(QPixmap(":/Assets/Menu/Start.png").scaled(607,77,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));setPos( 400-pixmap().width()/2 -4, 600-pixmap().height()/2 + 55 +4); animation_counter = 5; break;
        case 5:setPixmap(QPixmap(":/Assets/Menu/Start.png").scaled(609,79,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));setPos( 400-pixmap().width()/2 -5, 600-pixmap().height()/2 + 55 +5); animation_counter = 6; break;
        case 6:setPixmap(QPixmap(":/Assets/Menu/Start.png").scaled(611,81,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));setPos( 400-pixmap().width()/2 -6, 600-pixmap().height()/2 + 55 +6); animation_counter = 7; break;
        case 7:setPixmap(QPixmap(":/Assets/Menu/Start.png").scaled(613,83,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));setPos( 400-pixmap().width()/2 -7, 600-pixmap().height()/2 + 55 +7); animation_counter = 8; break;
        case 8:setPixmap(QPixmap(":/Assets/Menu/Start.png").scaled(615,85,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));setPos( 400-pixmap().width()/2 -8, 600-pixmap().height()/2 + 55 +8); animation_counter = 9; break;
        case 9:setPixmap(QPixmap(":/Assets/Menu/Start.png").scaled(615,85,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));setPos( 400-pixmap().width()/2 -8, 600-pixmap().height()/2 + 55 +8); animation_counter = 10; break;
        case 10:setPixmap(QPixmap(":/Assets/Menu/Start.png").scaled(614,83,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));setPos( 400-pixmap().width()/2 -7, 600-pixmap().height()/2 + 55 +7); animation_counter = 11; break;
        case 11:setPixmap(QPixmap(":/Assets/Menu/Start.png").scaled(613,81,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));setPos( 400-pixmap().width()/2 -6, 600-pixmap().height()/2 + 55 +6); animation_counter = 12; break;
        case 12:setPixmap(QPixmap(":/Assets/Menu/Start.png").scaled(611,79,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));setPos( 400-pixmap().width()/2 -5, 600-pixmap().height()/2 + 55 +5); animation_counter = 13; break;
        case 13:setPixmap(QPixmap(":/Assets/Menu/Start.png").scaled(609,77,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));setPos( 400-pixmap().width()/2 -4, 600-pixmap().height()/2 + 55 +4); animation_counter = 14; break;
        case 14:setPixmap(QPixmap(":/Assets/Menu/Start.png").scaled(607,75,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));setPos( 400-pixmap().width()/2 -3, 600-pixmap().height()/2 + 55 +3); animation_counter = 15; break;
        case 15:setPixmap(QPixmap(":/Assets/Menu/Start.png").scaled(605,73,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));setPos( 400-pixmap().width()/2 -2, 600-pixmap().height()/2 + 55 +2); animation_counter = 16; break;
        case 16:setPixmap(QPixmap(":/Assets/Menu/Start.png").scaled(603,71,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));setPos( 400-pixmap().width()/2 -1, 600-pixmap().height()/2 + 55 +1); animation_counter = 1; break;
    }
}

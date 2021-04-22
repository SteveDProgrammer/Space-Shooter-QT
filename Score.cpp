//This file is responsible for maintaining the scores

#include "Score.h"
#include <QFont>

//Score Constructor +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Score::Score(QGraphicsTextItem *parent):QGraphicsTextItem(parent)
{
    // initialize the score

    score = 0;

    //draw the text

    setPlainText(QString::number(score)); //set score = 0
    setDefaultTextColor(Qt::green);
    setFont(QFont("courier",13));
}

//setScore Function +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void Score::setScore(int scoreOffset)
{
    score += scoreOffset;
    setPlainText(QString::number(score) ); //set Updated score
}

//getScore Function +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int Score::getscore()
{
    return score;
}


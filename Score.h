#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score:public QGraphicsTextItem
{
public:
    Score(QGraphicsTextItem *parent = 0);

    int getscore();
    void setScore(int scoreOffset);

private:

    int score;
};

#endif // SCORE_H

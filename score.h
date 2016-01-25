#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem
{
    Q_OBJECT
public:
    explicit Score(QGraphicsItem *parent = 0);

    int getScore();

public slots:
    void increase();

private:
    int score;
};

#endif // SCORE_H

#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>

Enemy::Enemy()
{
    int randomNum = rand()%700;
    setRect(randomNum, 0, 100, 100);
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(100);
}

void Enemy::move()
{
    setPos(x(), y() + 10);
    if(y() > scene()->height())
    {
        qDebug() << "Enemy removed ";
        scene()->removeItem(this);
        delete this;
    }
}

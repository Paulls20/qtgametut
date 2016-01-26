#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>

Enemy::Enemy()
{
    setPixmap(QPixmap(":/images/enemy.png"));
    int randomNum = rand()%700;
    //setRect(randomNum, 0, 100, 100);
    setPos(randomNum, 0);
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
        emit reduceHealth();
        scene()->removeItem(this);
        delete this;
    }
}

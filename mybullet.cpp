#include "mybullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <typeinfo>
#include "enemy.h"

MyBullet::MyBullet() : QObject(), QGraphicsPixmapItem()
{
    //setRect(0, 0, 10, 50);
    setPos(0,0);
    setPixmap(QPixmap(":/images/bullet.png"));


    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void MyBullet::move()
{
    setPos(x(), y() - 10);

    QList<QGraphicsItem*> enemies = collidingItems();
    foreach(QGraphicsItem* enemy, enemies)
    {
        if(typeid(*enemy) == typeid(Enemy)) {
            scene()->removeItem(enemy);
            scene()->removeItem(this);
            emit changeScore(this);
            delete enemy;
            return;
        }
    }

    if(y() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}


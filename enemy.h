#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>


class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Enemy();

signals:
    void reduceHealth();

public slots:
    void move();
};

#endif // ENEMY_H

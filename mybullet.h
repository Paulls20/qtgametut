#ifndef MYBULLET_H
#define MYBULLET_H

#include <QObject>
#include <QGraphicsRectItem>

class MyBullet : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    MyBullet();
signals:
    void changeScore(MyBullet*);

public slots:
    void move();
};

#endif // MYBULLET_H

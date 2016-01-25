#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
#include "mybullet.h"

class MyRect: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    MyRect();
    void keyPressEvent(QKeyEvent *event);

signals:
    void setScore();
public slots:
    void scoreChange(MyBullet *bullet);

};

#endif // MYRECT_H

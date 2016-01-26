#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
#include "mybullet.h"
#include <QMediaPlayer>

class MyRect: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    MyRect();
    void keyPressEvent(QKeyEvent *event);

signals:
    void setScore();
public slots:
    void scoreChange(MyBullet *bullet);

private:
    QMediaPlayer* mediaPlayer;

};

#endif // MYRECT_H

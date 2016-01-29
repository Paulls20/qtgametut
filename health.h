#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QLabel>

class Health : public QGraphicsTextItem
{
    Q_OBJECT
public:
    Health();

public:
    int getHealth();

signals:
    void gameOver();

public slots:
    void decrease();


private:
    int _health;
};

#endif // HEALTH_H

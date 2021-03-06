#include "health.h"
#include <QFont>

Health::Health() : _health(3)
{
    setPos(x(), y()+25);
    setPlainText("Health: 3");
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

int Health::getHealth()
{

    return _health;
}

void Health::decrease()
{
    if(_health > 1)
      --_health;
    else
      emit gameOver();


    setPlainText(QString("Health: ") + QString::number(_health));

}


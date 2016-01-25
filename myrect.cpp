#include "myrect.h"
#include <QGraphicsScene>
#include <QDebug>


MyRect::MyRect()
{

}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Left:
           if(x() > 0)
            setPos(x()-10, y());
           break;
        case Qt::Key_Right:
           if(x() < 700)
            setPos(x()+10, y());
           break;
//         case Qt::Key_Up:
//           setPos(x(), y()-10);
//           break;
//         case Qt::Key_Down:
//            setPos(x(), y()+10);
//            break;
         case Qt::Key_Space:
            MyBullet *bullet = new MyBullet();
            QObject::connect(bullet, SIGNAL(changeScore(MyBullet*)),this, SLOT(scoreChange(MyBullet*)));
            bullet->setPos(this->x() + 50,this->y());
            scene()->addItem(bullet);
            break;
    }
}

void MyRect::scoreChange(MyBullet* bullet)
{
    qDebug() << "change score";
    delete bullet;
    emit setScore();
}


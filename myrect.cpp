#include "myrect.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QMediaPlaylist>


MyRect::MyRect()
{
    setPixmap(QPixmap(":/images/player.png"));
    mediaPlayer = new QMediaPlayer();
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/music/bullet.mp3"));
    mediaPlayer->setPlaylist(playlist);

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
            if(mediaPlayer->state() == QMediaPlayer::PlayingState)
            {
                qDebug() << "stopped";
                mediaPlayer->setPosition(0);
                mediaPlayer->stop();

                //mediaPlayer->
            }
            if(mediaPlayer->state() == QMediaPlayer::StoppedState) {
                qDebug() << "started";
                mediaPlayer->play();

            }

            QObject::connect(bullet, SIGNAL(changeScore(MyBullet*)),this, SLOT(scoreChange(MyBullet*)));
            qDebug() << "X -> " << x() + 50 << "Y -> " << this->y();
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


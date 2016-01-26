#include "widget.h"
#include "ui_widget.h"

#include <QTimer>
#include "enemy.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);

    rect = new MyRect();
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(rect);
    rect->setFocus();

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/images/background.jpg")));
    ui->graphicsView->setScene(scene);
    rect->setPos(ui->graphicsView->width()/2 - 50, ui->graphicsView->height() - 128);

    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(createEnemy()));
    timer->start(2000);

    score = new Score();
    scene->addItem(score);
    QObject::connect(rect, SIGNAL(setScore()), score, SLOT(increase()));

    health = new Health();
    scene->addItem(health);

    QMediaPlayer* bgMusic = new QMediaPlayer();

    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    playlist->addMedia(QUrl("qrc:/music/bgmusic.mp3"));
    bgMusic->setPlaylist(playlist);
    bgMusic->play();

}

void Widget::createEnemy()
{
    Enemy *enemy =  new Enemy();
    QObject::connect(enemy, SIGNAL(reduceHealth()), health, SLOT(decrease()));
    scene->addItem(enemy);
}

Widget::~Widget()
{
    delete ui;
}

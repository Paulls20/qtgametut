#include "widget.h"
#include "ui_widget.h"

#include <QTimer>
#include "enemy.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);

    rect = new MyRect();
    rect->setRect(0, 0,100,100);
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(rect);
    rect->setFocus();

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(scene);
    rect->setPos(ui->graphicsView->width()/2 - 50, ui->graphicsView->height() - rect->rect().height());

    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(createEnemy()));
    timer->start(2000);

    score = new Score();
    scene->addItem(score);
    QObject::connect(rect, SIGNAL(setScore()), score, SLOT(increase()));
}

void Widget::createEnemy()
{
    Enemy *enemy =  new Enemy();
    scene->addItem(enemy);
}

Widget::~Widget()
{
    delete ui;
}

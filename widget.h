#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include "myrect.h"
#include "score.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    Score* getScore();

private slots:
    void createEnemy();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    MyRect *rect;
    Score *score;

};

#endif // WIDGET_H

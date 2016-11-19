#include "bullet.h"
#include "constants.h"
#include <QTimer>
#include <QGraphicsScene>
#include "enemy.h"
#include "score.h"
#include "game.h"

extern Game *game;

Bullet::Bullet(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/bullet.png"));

    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(BULLET_MOVE_PAUSE);
}

void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            game->score->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    setPos(x(),y() - BULLET_MOVE_POINTS);
    if((pos().y() + this->pixmap().height()) < 0){
        scene()->removeItem(this);
        delete this;
    }
}

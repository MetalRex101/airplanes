#include "enemy.h"
#include "constants.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include "game.h"

extern Game *game;

Enemy::Enemy(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem()
{
    int random_number = rand() % (SCENE_WIDTH - ENEMY_WIDTH*2) + ENEMY_WIDTH;
    setPos(random_number, 0);

    setPixmap(QPixmap(":/images/enemy.png"));

    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(ENEMY_MOVE_PAUSE);
}

void Enemy::move()
{
    setPos(x(),y() + ENEMY_MOVE_POINTS);
    if(pos().y() > SCENE_HEIGHT){
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}

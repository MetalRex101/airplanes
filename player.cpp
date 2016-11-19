#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"
#include "constants.h"
#include "enemy.h"

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0){
            setPos(x() - PLAYER_MOVE_POINTS, y());
        }
    }
    else if(event->key() == Qt::Key_Right){
        if((pos().x() + PLAYER_WIDTH) < SCENE_WIDTH){
            setPos(x() + PLAYER_MOVE_POINTS, y());
        }

    }
    else if(event->key() == Qt::Key_Space){
        Bullet *bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
//        if(bulletSound->state() == QMediaPlayer.PlayingState){
//            bulletSound->setPosition(0);
//        }
//        else if(bulletSound->state() == QMediaPlayer.StoppedState){
//            //bulletSound->play();
//        }

    }
}

Player::Player(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    bulletSound = new QMediaPlayer();
    //bulletSound->setMedia(QUrl("qrc:/sounds/bulletsound.wmv"));

    setPixmap(QPixmap(":/images/player.png"));
    setTransformOriginPoint(50,50);
    setRotation(180);

}

void Player::spawn()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}

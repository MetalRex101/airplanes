#include "game.h"
#include <QGraphicsScene>
#include "player.h"
#include "constants.h"
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include <QImage>

Game::Game(QWidget *parent)
{
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,SCENE_WIDTH, SCENE_HEIGHT);

    scene->setBackgroundBrush(QBrush(QImage(":/images/bg.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(SCENE_WIDTH, SCENE_HEIGHT);

    Player *player = new Player();
    player->setPos((rect().width( ) / 2) - (player->pixmap().width() / 2), rect().height( ) - player->pixmap().height());
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x(),health->y() + 25);
    scene->addItem(health);

    enemySpawnTimer = new QTimer();
    QObject::connect(enemySpawnTimer,SIGNAL(timeout()),player,SLOT(spawn()));
    enemySpawnTimer->start(2000);

    QMediaPlayer *bgSound = new QMediaPlayer();
    bgSound->setMedia(QUrl("qrc:/sounds/bgsound.mp3"));
    bgSound->setVolume(50);
    bgSound->play();
}

void Game::lose()
{
    enemySpawntimer->stop();
    //TODO Loose event
}

#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <Qtimer>
#include "player.h"
#include "score.h"
#include "health.h"

class Game : public QGraphicsView
{
public:
    Game(QWidget *parent = 0);
    void lose();
    void nextLevel();
    void replay();

    QGraphicsScene *scene;
    Player * player;
    Score *score;
    Health *health;
    QTimer *enemySpawntimer;
};

#endif // GAME_H

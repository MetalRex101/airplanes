#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);
    Player(QGraphicsItem *parent = 0);
public slots:
    void spawn();
private:
    QMediaPlayer *bulletSound;
};

#endif // MYRECT_H

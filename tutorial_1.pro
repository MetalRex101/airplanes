#-------------------------------------------------
#
# Project created by QtCreator 2016-11-18T20:28:32
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tutorial_1
TEMPLATE = app


SOURCES += main.cpp \
    bullet.cpp \
    enemy.cpp \
    game.cpp \
    player.cpp \
    score.cpp \
    health.cpp

HEADERS  += \
    bullet.h \
    constants.h \
    enemy.h \
    game.h \
    player.h \
    score.h \
    health.h

FORMS    +=

RESOURCES += \
    res.qrc

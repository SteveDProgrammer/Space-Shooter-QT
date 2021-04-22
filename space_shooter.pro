#-------------------------------------------------
#
# Project created by QtCreator 2018-12-27T23:49:33
#
#-------------------------------------------------

QT += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = space_shooter
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    _GM.cpp \
    bullet.cpp \
    createplayer.cpp \
    enemies.cpp \
    enemy.cpp \
    enemyspawnner.cpp \
    floating_text.cpp \
    game_over.cpp \
    header_body.cpp \
    health.cpp \
    menubuttons.cpp \
    meteorites.cpp \
    plane_explosion.cpp \
    Player.cpp \
    powerup.cpp \
    Score.cpp \
    SpawnEnemiesInMain.cpp

HEADERS  += mainwindow.h \
    _GM.h \
    bullet.h \
    createplayer.h \
    enemies.h \
    enemy.h \
    enemyspawnner.h \
    floating_text.h \
    game_over.h \
    header_body.h \
    health.h \
    menubuttons.h \
    meteorites.h \
    plane_explosion.h \
    powerup.h \
    Score.h \
    SpawnEnemiesInMain.h \
    player.h

FORMS    += mainwindow.ui

DISTFILES += \
    Red_Dragon/Red_Dragon (1).png \
    Red_Dragon/Red_Dragon (2).png \
    Red_Dragon/Red_Dragon (3).png \
    Red_Dragon/Red_Dragon (4).png \
    space_shooter.pro.user

RESOURCES += \
    resource.qrc

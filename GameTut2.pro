#-------------------------------------------------
#
# Project created by QtCreator 2016-01-20T18:41:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameTut2
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    myrect.cpp \
    mybullet.cpp \
    enemy.cpp \
    score.cpp

HEADERS  += widget.h \
    myrect.h \
    mybullet.h \
    enemy.h \
    score.h

FORMS    += widget.ui

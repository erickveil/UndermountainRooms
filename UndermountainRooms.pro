#-------------------------------------------------
#
# Project created by QtCreator 2017-11-19T07:58:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UndermountainRooms
TEMPLATE = app

CONFIG += c++14


SOURCES += main.cpp\
        mainwindow.cpp \
    tableentry.cpp \
    randomtable.cpp \
    monsterentry.cpp \
    monstertable.cpp \
    hexcrawltables.cpp \
    complextrap.cpp \
    randomchambers.cpp \
    randomdungeons.cpp \
    dice.cpp \
    npctables.cpp \
    adventuretables.cpp \
    loottables.cpp \
    traptables.cpp \
    encountertables.cpp \
    dungeontables.cpp \
    treasuremaps.cpp \
    dungeon/dungeon.cpp \
    dungeon/level.cpp \
    dungeon/room.cpp \
    dungeon/roomexit.cpp \
    dungeon/hall.cpp

HEADERS  += mainwindow.h \
    tableentry.h \
    randomtable.h \
    monsterentry.h \
    monstertable.h \
    hexcrawltables.h \
    complextrap.h \
    randomchambers.h \
    randomdungeons.h \
    dice.h \
    npctables.h \
    adventuretables.h \
    loottables.h \
    traptables.h \
    encountertables.h \
    dungeontables.h \
    treasuremaps.h \
    dungeon/dungeon.h \
    dungeon/level.h \
    dungeon/room.h \
    dungeon/roomexit.h \
    dungeon/hall.h

FORMS    += mainwindow.ui

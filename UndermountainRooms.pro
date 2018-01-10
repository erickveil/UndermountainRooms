#-------------------------------------------------
#
# Project created by QtCreator 2017-11-19T07:58:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UndermountainRooms
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tableentry.cpp \
    randomtable.cpp \
    alltables.cpp \
    monsterentry.cpp \
    monstertable.cpp \
    hexcrawltables.cpp \
    complextrap.cpp

HEADERS  += mainwindow.h \
    tableentry.h \
    randomtable.h \
    alltables.h \
    monsterentry.h \
    monstertable.h \
    hexcrawltables.h \
    complextrap.h

FORMS    += mainwindow.ui

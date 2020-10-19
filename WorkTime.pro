#-------------------------------------------------
#
# Project created by QtCreator 2020-10-18T16:41:04
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WorkTime
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    database.cpp

HEADERS  += mainwindow.h \
    database.h

FORMS    += mainwindow.ui

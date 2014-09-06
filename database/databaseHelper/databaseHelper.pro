#-------------------------------------------------
#
# Project created by QtCreator 2014-09-06T13:45:43
#
#-------------------------------------------------

QT       -= core gui

TARGET = databaseHelper
TEMPLATE = lib
CONFIG += staticlib

SOURCES += databasehelper.cpp

HEADERS += databasehelper.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

#-------------------------------------------------
#
# Project created by QtCreator 2014-09-06T13:45:43
#
#-------------------------------------------------

QT       -= core gui

TARGET = databaseHelper
TEMPLATE = lib
CONFIG += staticlib

SOURCES += databasehelper.cpp \
    src/GolfCourse.cpp \
    src/GolfObject.cpp \
    src/Hole.cpp \
    src/PlayedHole.cpp \
    src/Player.cpp \
    src/Round.cpp \
    src/Shot.cpp \
    src/sqlite3.c

INCLUDEPATH += $$PWD/include

HEADERS += databasehelper.h \
    include/GolfCourse.h \
    include/GolfObject.h \
    include/Hole.h \
    include/LinkedList.h \
    include/PlayedHole.h \
    include/Player.h \
    include/Round.h \
    include/Shot.h \
    include/sqlite3.h \
    include/sqlite3ext.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

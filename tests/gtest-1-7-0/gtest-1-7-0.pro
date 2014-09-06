#-------------------------------------------------
#
# Project created by QtCreator 2014-09-06T14:28:54
#
#-------------------------------------------------

QT       -= core gui

TARGET = gtest-1-7-0
TEMPLATE = lib

DEFINES += GTEST170_LIBRARY

SOURCES += gtest170.cpp

HEADERS += gtest170.h\
        gtest-1-7-0_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

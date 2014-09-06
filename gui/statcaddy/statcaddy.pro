#-------------------------------------------------
#
# Project created by QtCreator 2014-09-06T13:10:05
#
#-------------------------------------------------

QT       += core

QT       += gui

TARGET = statcaddy
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    src/addcourse.cpp \
    src/addplayer.cpp \
    src/addround.cpp \
    src/databasedialog.cpp \
    src/filter.cpp \
    src/mainwindow.cpp \
    src/piechart.cpp \
    src/plotter.cpp \
    src/PlotterSettings.cpp

INCLUDEPATH +=$$PWD/../../database/databaseHelper \
    $$PWD/../../database/databaseHelper/include

HEADERS += \
    include/addcourse.h \
    include/addplayer.h \
    include/addround.h \
    include/databasedialog.h \
    include/filter.h \
    include/mainwindow.h \
    include/piechart.h \
    include/plotter.h \
    include/PlotterSettings.h \
    interface/ui_addcourse.h \
    interface/ui_addplayer.h \
    interface/ui_addround.h \
    interface/ui_databasedialog.h \
    interface/ui_filter.h \
    interface/ui_mainwindow.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../database/build-databaseHelper-Desktop-Release/release/ -ldatabaseHelper
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../database/build-databaseHelper-Desktop-Release/debug/ -ldatabaseHelper
else:unix: LIBS += -L$$PWD/../../database/build-databaseHelper-Desktop-Release/ -ldatabaseHelper

INCLUDEPATH += $$PWD/../../database/build-databaseHelper-Desktop-Release
DEPENDPATH += $$PWD/../../database/build-databaseHelper-Desktop-Release

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../database/build-databaseHelper-Desktop-Release/release/libdatabaseHelper.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../database/build-databaseHelper-Desktop-Release/debug/libdatabaseHelper.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../database/build-databaseHelper-Desktop-Release/release/databaseHelper.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../database/build-databaseHelper-Desktop-Release/debug/databaseHelper.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../database/build-databaseHelper-Desktop-Release/libdatabaseHelper.a

#-------------------------------------------------
#
# Project created by QtCreator 2017-12-18T12:30:50
#
#-------------------------------------------------

QT       += core gui network script

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WADDownloader
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    app/main.cpp \
    app/mainwindow.cpp \
    app/wad.cpp \
    resources/uis/wadlistwidget.cpp \
    resources/uis/settingswindow.cpp

HEADERS += \
    app/mainwindow.h \
    app/wad.h \
    resources/uis/wadlistwidget.h \
    resources/uis/settingswindow.h

FORMS += \
    resources/uis/mainwindow.ui \
    resources/uis/wadlistwidget.ui \
    resources/uis/settingswindow.ui

SUBDIRS += \
    WADDownloader.pro

DISTFILES += \
    README.md \

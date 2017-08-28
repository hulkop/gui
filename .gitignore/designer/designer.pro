#-------------------------------------------------
#
# Project created by QtCreator 2017-07-17T12:36:08
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = designer
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    savechanges.cpp

HEADERS  += \
    mainwindow.h \
    savechanges.h

FORMS    += mainwindow.ui \
    savechanges.ui

#-------------------------------------------------
#
# Project created by QtCreator 2014-06-04T18:34:53
#
#-------------------------------------------------

QT       += core
QT       += webkit
QT       += widgets
QT       += webkitwidgets
QT       += gui
QT       += network
QT       += xml
QT       += sql

TARGET = SvenUtils
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    src/qcookie.cpp \
    src/qttimeutils.cpp \
    src/qregexutils.cpp

HEADERS += \
    src/qcookie.h \
    src/qttimeutils.h \
    src/qregexutils.h

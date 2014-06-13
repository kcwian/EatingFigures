#-------------------------------------------------
#
# Project created by QtCreator 2014-04-17T17:39:25
#
#-------------------------------------------------

QT       += core gui opengl network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS +=
TARGET = QGLFigury
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
figura.cpp\
    poziomy.cpp \
    odcinek.cpp \
kwadrat.cpp \
kolo.cpp \
trojkat.cpp

HEADERS  += mainwindow.h \
figura.h\
    poziomy.h \
    odcinek.h \
kwadrat.h \
kolo.h \
trojkat.h

FORMS    += mainwindow.ui

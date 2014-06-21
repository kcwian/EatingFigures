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
    myglwidget.cpp\
figura.cpp\
trojkat.cpp \
kolo.cpp\
kwadrat.cpp\
    odcinek.cpp \
    dialog.cpp \
    dialog2.cpp

HEADERS  += mainwindow.h \
myglwidget.h\
figura.h\
kolo.h\
kwadrat.h\
trojkat.h \
    odcinek.h \
    dialog.h \
    dialog2.h

FORMS    += mainwindow.ui \
    dialog.ui \
    dialog2.ui

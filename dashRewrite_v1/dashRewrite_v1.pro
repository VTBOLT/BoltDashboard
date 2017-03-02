#-------------------------------------------------
#
# Project created by QtCreator 2017-02-28T12:49:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dashRewrite_v1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    race_view.cpp \
    debug_view.cpp \
    can/canrecieve.cpp \
    can/cansend.cpp \
    interfacecan.cpp

HEADERS  += mainwindow.h \
    race_view.h \
    debug_view.h \
    can/can.h \
    can/cancomm.h \
    can/canframelen.h \
    can/error.h \
    can/gw.h \
    can/isotp.h \
    can/lib.h \
    can/netlink.h \
    can/raw.h \
    can/terminal.h \
    interfacecan.h

FORMS    += mainwindow.ui

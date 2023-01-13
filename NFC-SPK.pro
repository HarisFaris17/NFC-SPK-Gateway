#-------------------------------------------------
#
# Project created by QtCreator 2022-12-05T16:54:55
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NFC-SPK
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcpserver.cpp \
    tcp.cpp \
    tcpserver2.cpp \
    processor.cpp

HEADERS  += mainwindow.h \
    tcpserver.h \
    tcp.h \
    tcpserver2.h \
    processor.h

FORMS    += mainwindow.ui

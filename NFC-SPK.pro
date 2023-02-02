#-------------------------------------------------
#
# Project created by QtCreator 2022-12-05T16:54:55
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NFC-SPK
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcpserver.cpp \
    tcp.cpp \
    tcpserver2.cpp \
    processor.cpp \
    database.cpp \
    file.cpp \
    locationcalculatorprocess.cpp \
    common.cpp

HEADERS  += mainwindow.h \
    tcpserver.h \
    tcp.h \
    tcpserver2.h \
    processor.h \
    database.h \
    file.h \
    constants.h \
    locationcalculatorprocess.h \
    common.h

FORMS    += mainwindow.ui

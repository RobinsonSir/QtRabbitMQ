#-------------------------------------------------
#
# Project created by QtCreator 2017-06-01T15:14:10
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RabbitClient
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    qrabbitmq.cpp

HEADERS  += mainwindow.h \
    qrabbitmq.h

FORMS    += mainwindow.ui

INCLUDEPATH += ./QAMQP

LIBS += -L../bin -lqamqp

UI_DIR = ../form
DESTDIR = ../bin
RCC_DIR = ../qrc
MOC_DIR = ../moc
OBJECTS_DIR = ../obj

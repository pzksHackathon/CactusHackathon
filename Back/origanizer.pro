QT += core
QT -= gui

CONFIG += c++11

TARGET = origanizer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    step.cpp \
    goal.cpp \
    organizer.cpp

HEADERS += \
    organizer.h \
    goal.h \
    timer.h \
    calendar.h \
    notificationmanager.h \
    step.h


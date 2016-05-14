QT += core
QT -= gui

TARGET = OrganizemMe
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    organizer.h \
    goal.h \
    timer.h \
    calendar.h \
    notificationmanager.h


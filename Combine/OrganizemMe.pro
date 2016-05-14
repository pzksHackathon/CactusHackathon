QT += core
QT -= gui
QT += widgets
QMAKE_CXXFLAGS += -std=c++11

TARGET = OrganizemMe
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app

SOURCES += main.cpp \
    goal.cpp \
    organizer.cpp \
    step.cpp \
    newgoalui.cpp \
    newpostui.cpp \
    organizerui.cpp

HEADERS += \
    organizer.h \
    goal.h \
    timer.h \
    calendar.h \
    notificationmanager.h \
    step.h \
    diary.h \
    post.h \
    day.h \
    month.h \
    newgoalui.h \
    newpostui.h \
    organizerui.h

SUBDIRS += \
    origanizer.pro

FORMS += \
    newgoalui.ui \
    newpostui.ui \
    organizerui.ui

DISTFILES += \
    Cactus.pro.user \
    OrganizemMe.pro.user \
    OrganizemMe.pro.user.0a386e9 \
    origanizer.pro.user





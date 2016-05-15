QT += core
QT -= gui
QT += widgets
QT += printsupport
CONFIG += c++11

TARGET = origanizer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    step.cpp \
    goal.cpp \
    organizer.cpp \
    organizerui.cpp \
    newpostui.cpp \
    newgoalui.cpp \
    steptime.cpp \
    qcustomplot.cpp \
    productivitychart.cpp

FORMS += organizerui.ui \
    newpostui.ui \
    newgoalui.ui

HEADERS += organizer.h \
    goal.h \
    timer.h \
    calendar.h \
    notificationmanager.h \
    step.h \
    organizerui.h \
    newpostui.h \
    newgoalui.h \
    steptime.h \
    day.h \
    month.h \
    qcustomplot.h \
    productivitychart.h \
    diary.h \
    post.h

RESOURCES += \
    src.qrc


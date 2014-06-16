#-------------------------------------------------
#
# Project created by QtCreator 2014-04-18T14:47:22
#
#-------------------------------------------------

QT       += core sql gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lib
TEMPLATE = app

QT+= sql

SOURCES += main.cpp\
        mainwindow.cpp \
    logdialog.cpp \
    insert.cpp \
    querywindow.cpp \
    borrow.cpp \
    card.cpp \
    database.cpp \
    globalvariables.cpp \
    addcard.cpp \
    addmanager.cpp \
    courses.cpp \
    grades.cpp \
    main1.cpp \
    students.cpp

HEADERS  += mainwindow.h \
    logdialog.h \
    insert.h \
    querywindow.h \
    borrow.h \
    card.h \
    database.h \
    globalvariables.h \
    addcard.h \
    addmanager.h \
    courses.h \
    grades.h \
    head.h \
    students.h

FORMS    += mainwindow.ui \
    logdialog.ui \
    insert.ui \
    querywindow.ui \
    borrow.ui \
    card.ui \
    addcard.ui \
    addmanager.ui

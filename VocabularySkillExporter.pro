#-------------------------------------------------
#
# Project created by QtCreator 2014-11-22T19:11:42
#
#-------------------------------------------------

QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VocabularySkillExporter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialogaddvocabulary.cpp \
    dialogconverttxt.cpp \
    xmlhandler.cpp

HEADERS  += mainwindow.h \
    dialogaddvocabulary.h \
    dialogconverttxt.h \
    xmlhandler.h

FORMS    += mainwindow.ui \
    dialogaddvocabulary.ui \
    dialogconverttxt.ui

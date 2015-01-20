#-------------------------------------------------
#
# Project created by QtCreator 2014-12-23T11:34:35
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = test_all_qt
TEMPLATE = app

DLLDESTDIR += ../bin

SOURCES += main.cpp\
        mainwindow.cpp \
    zgraphicsscene.cpp \
    ztestpublic.cpp \
    ztest.cpp \
    ztextedit.cpp \
    zgraphicstextitem.cpp \
    cgraphicsstateitem.cpp \
    msgfilechatitem.cpp

HEADERS  += mainwindow.h \
    zgraphicsscene.h \
    ztestpublic.h \
    ztest.h \
    ztextedit.h \
    ztest_global.h \
    zgraphicstextitem.h \
    cgraphicsstateitem.h \
    msgfilechatitem.h

FORMS    += mainwindow.ui \
    msgfilewidget.ui

RESOURCES += \
    source.qrc

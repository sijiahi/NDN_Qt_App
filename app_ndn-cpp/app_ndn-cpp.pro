#-------------------------------------------------
#
# Project created by QtCreator 2020-09-24T02:15:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app
CONFIG += c++14
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        ndn_app.cpp \
    chatbuf.pb.cc \
    chat_demo.cpp \
    chat_setter.cpp \
    chat_core.cpp \
    data_sender.cpp

HEADERS += \
    ndn_app.h \
    chatbuf.pb.h \
    common.h \
    chat_demo.h \
    chat_setter.h \
    chat_core.h \
    data_sender.h

FORMS += \
        ndn_app.ui \
    chat_demo.ui \
    chat_setter.ui

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += libndn-cpp


SUBDIRS += \
    app.pro \


unix: LIBS += -L$$PWD/../../../../usr/local/lib/ -lndn-cpp

INCLUDEPATH += $$PWD/../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../usr/local/include


unix{
LIBS += -lprotobuf
LIBS += -L/usr/lib/x86_64-linux-gnu
LIBS += -lboost_system
LIBS += -L/usr/lib
LIBS += -llog4cxx
LIBS += -lpthread
LIBS += -lz
}



DISTFILES += \
    chatbuf.proto \
    qrc_doge_theme.o

unix:!macx: LIBS += -lndn-cpp

RESOURCES += \
    doge_theme.qrc

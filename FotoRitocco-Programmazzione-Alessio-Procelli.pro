#-------------------------------------------------
#
# Project created by QtCreator 2019-05-28T18:22:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FotoRitocco-Programmazzione-Alessio-Procelli
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        baseeffect.cpp \
        brush.cpp \
        controller.cpp \
        graphicsview.cpp \
        line.cpp \
        main.cpp \
        model.cpp \
        rectangle.cpp \
        triangle.cpp \
        view.cpp

HEADERS += \
        baseeffect.h \
        brush.h \
        controller.h \
        directions.h \
        effectsinterface.h \
        graphicsview.h \
        line.h \
        model.h \
        observer.h \
        rectangle.h \
        shape.h \
        subject.h \
        triangle.h \
        view.h \
        viewinterface.h

FORMS += \
        view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icone.qrc

DISTFILES +=

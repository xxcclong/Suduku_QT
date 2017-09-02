#-------------------------------------------------
#
# Project created by QtCreator 2017-08-28T15:14:49
#
#-------------------------------------------------

QT       += core gui
QT+=multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Suduku
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sudukuclass.cpp \
    choosedia.cpp \
    dialogchoo.cpp

HEADERS  += mainwindow.h \
    sudukuclass.h \
    choosedia.h \
    dialogchoo.h

FORMS    += mainwindow.ui \
    dialogchoo.ui

DISTFILES += \
    4d84438b4710b91267cfabd8c2fdfc039245221b.png \
    numbers/9.png \
    numbers/8.png \
    numbers/7.png \
    numbers/6.png \
    numbers/5.png \
    numbers/4.png \
    numbers/3.png \
    numbers/2.png \
    numbers/1.png \
    numbers/_-_.wav

RESOURCES += \
    numbers/numbers.qrc

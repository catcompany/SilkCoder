QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

QMAKE_CFLAGS += "-Wunused-parameter -Wnounused-variable"
QMAKE_CXXFLAGS += "-Wunused-parameter -Wnounused-variable"

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    coder.cpp \
    decoder.c \
    decodewindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    coder.h \
    decoder.h \
    decodewindow.h \
    mainwindow.h

FORMS += \
    decodewindow.ui \
    mainwindow.ui

# For Linux
unix:!macx: LIBS += -L$$PWD/libs/ -lSKP_SILK_SDK

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

unix:!macx: PRE_TARGETDEPS += $$PWD/libs/libSKP_SILK_SDK.a

#For Windows
win32: LIBS += -L$$PWD/libs/ -lSKP_SILK_SDK_win

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/libs/SKP_SILK_SDK_win.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/libs/libSKP_SILK_SDK_win.a

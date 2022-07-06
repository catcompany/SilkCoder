QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

QMAKE_CFLAGS += "-w"
QMAKE_CXXFLAGS += "-w"

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    coder.cpp \
    decodewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    mp3encoder.cpp

HEADERS += \
    coder.h \
    decodewindow.h \
    mainwindow.h \
    mp3encoder.h

FORMS += \
    decodewindow.ui \
    mainwindow.ui

# For Linux
unix:!macx: LIBS += -L$$PWD/libs/ -lSKP_SILK_SDK_linux \
                                  -lmp3lame_linux

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

unix:!macx: PRE_TARGETDEPS += $$PWD/libs/libSKP_SILK_SDK_linux.a \
                              $$PWD/libs/libmp3lame_linux.a

#For Windows
win32: LIBS += -L$$PWD/libs/ -lSKP_SILK_SDK_win

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/libs/SKP_SILK_SDK_win.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/libs/libSKP_SILK_SDK_win.a


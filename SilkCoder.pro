QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

QMAKE_CFLAGS += "-w -std=c17"
QMAKE_CXXFLAGS += "-w -std=c++17"

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    coder.cpp \
    main.cpp \
    mainwindow.cpp \
    mp3encoder.cpp

HEADERS += \
    coder.h \
    mainwindow.h \
    mp3encoder.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

# For Windows
win32: LIBS += -L$$PWD/libs/win/ -lSKP_SILK_SDK -lmp3lame
win32:!win32-g++: PRE_TARGETDEPS += $$PWD/libs/win/SKP_SILK_SDK.lib $$PWD/libs/win/mp3lame.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/libs/win/libSKP_SILK_SDK.a $$PWD/libs/win/libmp3lame.a

unix:!macx{
    if(contains(ANDROID_TARGET_ARCH,arm64-v8a)) {
        # For Android
        message("arm64-v8a")
        LIBS += $$PWD/libs/android/libSKP_SILK_SDK.a $$PWD/libs/android/libmp3lame.a
    }else{
        # For Linux
        message("using linux")
        LIBS += -L$$PWD/libs/linux/ -lSKP_SILK_SDK -lmp3lame
        PRE_TARGETDEPS += $$PWD/libs/linux/libSKP_SILK_SDK.a \
                          $$PWD/libs/linux/libmp3lame.a
    }
}

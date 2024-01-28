QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arrow.cpp \
    dyno.cpp \
    global.cpp \
    main.cpp \
    mainwindow.cpp \
    mix.cpp \
    mytriangle.cpp \
    pipe.cpp \
    pump.cpp \
    servicepump.cpp \
    servicevalve.cpp \
    tvertne.cpp \
    valve.cpp \
    widgetdata.cpp \
    widgetdiagramelement.cpp \
    widgetservice.cpp

HEADERS += \
    arrow.h \
    dyno.h \
    global.h \
    mainwindow.h \
    mix.h \
    mytriangle.h \
    pipe.h \
    pump.h \
    servicepump.h \
    servicevalve.h \
    tvertne.h \
    valve.h \
    widgetdata.h \
    widgetdiagramelement.h \
    widgetservice.h

FORMS += \
    mainwindow.ui \
    servicepump.ui \
    servicevalve.ui \
    widgetservice.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resource.qrc

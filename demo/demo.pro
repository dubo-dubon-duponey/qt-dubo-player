TEMPLATE = subdirs
## Basic consumer variables
#include(../vars.pri)

## Requires
#QT = core gui webkit

## Build a lib
#TEMPLATE = app
##QT += opengl webkit

##DEFINES += LIBROXEEPLAYER_LIBRARY

## Basic stuff (version and build/path magic)
#include(../conf/confbase.pri)

## Third-party stuff
#exists(../third-party/bootstrap.pri){
#    include(../third-party/bootstrap.pri)
#}

## Windows specific configuration
#win32{
#    message( -> Targetting windows)
#    include(../conf/confwin.pri)
#}

## Mac specific configuration
#mac{
#    message( -> Targetting osx)
#    include(../conf/confmacx.pri)
#}

## Unix specific configuration
#unix:!mac {
#    message( -> Targetting *nux)
#    include(../conf/confunix.pri)
#}

#INCLUDEPATH += $$PWD

#target.path = $$DESTDIR
#INSTALLS += target

##HEADERS +=

#SOURCES +=  main.cpp \
#    testvideo.cpp



## http://forum.videolan.org/viewtopic.php?f=32&t=61157
#DEPNAME = roxeeplayer

##isEmpty(ROXEE_DESTDIR){
##    INCLUDEPATH +=  $$PWD/../src/include
##    LIBS += -L$$PWD/../buildd/$${PLT}/$${QMAKE_CC}/$${ROXEE_LINK_TYPE}-$${ROXEE_BUILD_TYPE}/lib
##}

##LIBS +=         -lroxeeplayer

##mac{
##    contains(ROXEE_LINK_TYPE, static){
##        LIBS += -lvlc
##    }
##}

##    stupidvlc.cpp
##    stupidvlc.h
##include <qtvlcwidget.h>

##/*
##// Dig about VLC
##// http://developer.qt.nokia.com/doc/qt-4.8/qapplication.html
##// setGraphicsSystem();

##VLC

##Native Widgets vs Alien Widgets
##Introduced in Qt 4.4, alien widgets are widgets unknown to the windowing system. They do not have a native window handle associated with them. This feature significantly speeds up widget painting, resizing, and removes flicker.
##Should you require the old behavior with native windows, you can choose one of the following options:
##Use the QT_USE_NATIVE_WINDOWS=1 in your environment.
##Set the Qt::AA_NativeWindows attribute on your application. All widgets will be native widgets.
##Set the Qt::WA_NativeWindow attribute on widgets: The widget itself and all of its ancestors will become native (unless Qt::WA_DontCreateNativeAncestors is set).
##Call QWidget::winId to enforce a native window (this implies 3).
##Set the Qt::WA_PaintOnScreen attribute to enforce a native window (this implies 3).

##*/

#HEADERS += \
#    testvideo.h

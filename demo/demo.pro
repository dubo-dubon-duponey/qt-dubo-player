TEMPLATE = app

## Basic consumer variables
QT = core gui


#HEADERS += $$PWD/testvideo.h

SOURCES +=  $$PWD/main.cpp
#    $$PWD/testvideo.cpp

INCLUDEPATH += $$PWD
target.path = $$DESTDIR/../lib
INSTALLS += target


# You don't "need" any "magic" of the following - just link against the produced library if you are doing it your own way
include($$PWD/../vars.pri)
include($$PWD/../conf/confbase.pri)

INCLUDEPATH +=  $$PWD/../src/include/libroxeeplayer
LIBS +=         -L$$DESTDIR/../lib
LIBS +=         -lroxeeplayer

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




#DEPNAME = roxeeplayer

##isEmpty(ROXEE_DESTDIR){
##    INCLUDEPATH +=  $$PWD/../src/include
##    LIBS += -L$$PWD/../buildd/$${PLT}/$${QMAKE_CC}/$${ROXEE_LINK_TYPE}-$${ROXEE_BUILD_TYPE}/lib
##}

##mac{
##    contains(ROXEE_LINK_TYPE, static){
##        LIBS += -lvlc
##    }
##}

##    stupidvlc.cpp
##    stupidvlc.h
##include <qtvlcwidget.h>

## http://forum.videolan.org/viewtopic.php?f=32&t=61157
## http://developer.qt.nokia.com/doc/qt-4.8/qapplication.html


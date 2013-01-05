TEMPLATE = lib
QT = core gui

!lessThan(QT_VERSION, 5.0.0) {
    QT += widgets
}

include($$PWD/../vars.pri)
include($$PWD/../conf/confbase.pri)

# Windows specific configuration
win32{
    message( -> Targetting windows)
    include($$PWD/../conf/confwin.pri)
}

# Mac specific configuration
mac{
    message( -> Targetting osx)
    include($$PWD/../conf/confmacx.pri)
}

# Unix specific configuration
unix:!mac {
    message( -> Targetting *nux)
    include($$PWD/../conf/confunix.pri)
}

DEFINES += LIBROXEEPLAYER_LIBRARY

contains(ROXEE_LINK_TYPE, static){
    DEFINES += LIBROXEEPLAYER_USE_STATIC
}

INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/include
target.path = $$DESTDIR
INSTALLS += target

HEADERS += \
    $$PWD/include/libroxeeplayer/libroxeeplayer_global.h \
    $$PWD/include/libroxeeplayer/core.h \
    $$PWD/include/libroxeeplayer/root.h \
    $$PWD/include/libroxeeplayer/simpleplayer.h \
    $$PWD/include/libroxeeplayer/stackedplayer.h \
    $$PWD/include/libroxeeplayer/mediaplayer.h \
    $$PWD/coreinstance.h

SOURCES +=  $$PWD/root.cpp \
    $$PWD/core.cpp \
    $$PWD/coreinstance.cpp \
    $$PWD/mediaplayer.cpp \
    $$PWD/simpleplayer.cpp \
    $$PWD/stackedplayer.cpp

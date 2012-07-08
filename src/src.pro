# Basic consumer variables
include(../vars.pri)

# Requires
QT = core gui

# Build a lib
TEMPLATE = lib
DEFINES += LIBROXEEPLAYER_LIBRARY

# Basic stuff (version and build/path magic)
include(../conf/confbase.pri)

# Third-party stuff
exists(../third-party/bootstrap.pri){
    include(../third-party/bootstrap.pri)
}

# Windows specific configuration
win32{
    message( -> Targetting windows)
    include(../conf/confwin.pri)
}

# Mac specific configuration
mac{
    message( -> Targetting osx)
    include(../conf/confmacx.pri)
}

# Unix specific configuration
unix:!mac {
    message( -> Targetting *nux)
    include(../conf/confunix.pri)
}

INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/include/libroxeeplayer
target.path = $$DESTDIR
INSTALLS += target

HEADERS += \
    include/libroxeeplayer/libroxeeplayer_global.h \
    include/libroxeeplayer/core.h \
    include/libroxeeplayer/root.h \
    include/libroxeeplayer/simpleplayer.h \
    include/libroxeeplayer/stackedplayer.h \
    include/libroxeeplayer/mediaplayer.h \
    coreinstance.h

SOURCES +=  root.cpp \
    core.cpp \
    coreinstance.cpp \
    mediaplayer.cpp \
    simpleplayer.cpp \
    stackedplayer.cpp

# Basic consumer variables
include(../vars.pri)

# This is a library (to be ovveridden by eg MSVC specific config)
TEMPLATE = lib

# Requires
QT = core gui

# And be boring
CONFIG +=   QT_NO_CAST_FROM_ASCII \
            QT_NO_CAST_TO_ASCII \
            QT_STRICT_ITERATORS \
            QT_USE_FAST_CONCATENATION QT_USE_FAST_OPERATOR_PLUS

# Yes, this will build a lib
DEFINES += LIBROXEEPLAYER_LIBRARY

# Basic stuff (version and build/path magic)
include(../conf/confbase.pri)

# Windows specific configuration
win32{
    message( -> Targetting windows)
    include(../conf/confwin.pri)
}

# Mac specific configuration
macx{
    message( -> Targetting osx)
    include(../conf/confmacx.pri)
}

# Unix specific configuration
unix:!macx {
    message( -> Targetting linux)
    include(../conf/confunix.pri)
}

INCLUDEPATH += $$PWD
target.path = $$DESTDIR
INSTALLS += target


CONFIG += absolute_library_soname


#qtvlc.h\
HEADERS += \
    libroxeeplayer_global.h \
#    qtvlcwidget.h \
    core.h \
    coreinstance.h \
    mediaplayer.h \
    root.h \
    simpleplayer.h \
    stackedplayer.h
#    qtvlcerrorhandling.h \
#    qtvlclogging.h \
#    qtvlcasynchronousevents.h \
#    vlc_on_qt.h
#    qtvlcaudiocontrols.h \
#    qtvlcvideocontrols.h \
#    LibVLCpp/GenericRenderer.h \
#    LibVLCpp/RenderWidget.h \
#    LibVLCpp/VLCInstance.h \
#    LibVLCpp/VLCMedia.h \
#    LibVLCpp/VLCMediaPlayer.h \
#    LibVLCpp/VLCpp.hpp

#macx{
#    OBJECTIVE_SOURCES += qtvlcwidget.mm
#}



#qtvlc.cpp \
SOURCES += \
#    qtvlcerrorhandling.cpp \
#    qtvlclogging.cpp \
#    qtvlcasynchronousevents.cpp \
    core.cpp \
    coreinstance.cpp \
    mediaplayer.cpp \
    root.cpp \
    simpleplayer.cpp \
    stackedplayer.cpp
#    qtvlcaudiocontrols.cpp \
#    qtvlcvideocontrols.cpp \
#    LibVLCpp/GenericRenderer.cpp \
#    LibVLCpp/VLCInstance.cpp \
#    LibVLCpp/VLCMedia.cpp \
#    LibVLCpp/VLCMediaPlayer.cpp

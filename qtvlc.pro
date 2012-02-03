QT += core gui

TARGET = qtvlc
TEMPLATE = lib

DEFINES += QTVLC_LIBRARY

INCLUDEPATH += $$PWD

mac:CONFIG += absolute_library_soname
win32|mac:!wince*:!win32-msvc:!macx-xcode:CONFIG += debug_and_release build_all
DESTDIR = $$PWD/lib
#win32 {
#    DLLDESTDIR = $$[QT_INSTALL_BINS]
#    QMAKE_DISTCLEAN += $$[QT_INSTALL_BINS]\\$${QTSINGLEAPPLICATION_LIBNAME}.dll
#}
target.path = $$DESTDIR
INSTALLS += target



#qtvlc.h\
HEADERS += qtvlc_global.h \
    qtvlccore.h \
    qtvlcmediaplayer.h \
    qtvlcerrorhandling.h \
    qtvlclogging.h \
    qtvlcasynchronousevents.h \
    qtvlcwidget.h \
    qtvlc2.h
#    vlc_on_qt.h
#    qtvlcaudiocontrols.h \
#    qtvlcvideocontrols.h \
#    LibVLCpp/GenericRenderer.h \
#    LibVLCpp/RenderWidget.h \
#    LibVLCpp/VLCInstance.h \
#    LibVLCpp/VLCMedia.h \
#    LibVLCpp/VLCMediaPlayer.h \
#    LibVLCpp/VLCpp.hpp

macx{
    INCLUDEPATH +=  /Users/dmp/buildd/deploy.webitup.org/client/Darwin/include
#/Users/dmp/buildd/webitup/deploy/monades/include \
#    INCLUDEPATH +=  /Users/dmp/Applications/media/VLC.app/Contents/MacOS/include
    LIBS += -L/Users/dmp/buildd/deploy.webitup.org/client/Darwin/lib
#-L/Users/dmp/buildd/webitup/deploy/monades/lib \
#    LIBS += -L/Users/dmp/Applications/media/VLC.app/Contents/MacOS/lib
    LIBS += -lvlc
    LIBS += -framework Cocoa
    OBJECTIVE_SOURCES += qtvlcwidget.mm
#    OBJECTIVE_SOURCES += vlc_on_qt.mm

#    OBJECTIVE_SOURCES += LibVLCpp/RenderWidget.mm
}

#qtvlc.cpp \
SOURCES += qtvlccore.cpp \
    qtvlcmediaplayer.cpp \
    qtvlcerrorhandling.cpp \
    qtvlclogging.cpp \
    qtvlcasynchronousevents.cpp \
    qtvlc2.cpp
#    qtvlcaudiocontrols.cpp \
#    qtvlcvideocontrols.cpp \
#    LibVLCpp/GenericRenderer.cpp \
#    LibVLCpp/VLCInstance.cpp \
#    LibVLCpp/VLCMedia.cpp \
#    LibVLCpp/VLCMediaPlayer.cpp

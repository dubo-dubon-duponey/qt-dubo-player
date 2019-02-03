TEMPLATE = lib
QT = core widgets opengl

PROJECT_ROOT = $$PWD/..
include($$PROJECT_ROOT/config/qmakeitup.pri)

INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/lib$${TARGET}/global.h \
    $$PWD/lib$${TARGET}/core.h \
    $$PWD/lib$${TARGET}/root.h \
    $$PWD/lib$${TARGET}/simpleplayer.h \
    $$PWD/lib$${TARGET}/mediaplayer.h \
    $$PWD/lib$${TARGET}/audiocontrol.h \
    $$PWD/lib$${TARGET}/videocontrol.h \
    $$PWD/lib$${TARGET}/vlc3.h

SOURCES += \
    $$PWD/root.cpp \
    $$PWD/core.cpp \
    $$PWD/mediaplayer.cpp \
    $$PWD/simpleplayer.cpp \
    $$PWD/audiocontrol.cpp \
    $$PWD/videocontrol.cpp \
    $$PWD/vlc3.cpp

contains(DUBO_LINK_TYPE, dynamic){
    win32{
        copyToDestdir($$DUBO_EXTERNAL/lib/libvlc.dll, $$DESTDIR)
        copyToDestdir($$DUBO_EXTERNAL/lib/libvlccore.dll, $$DESTDIR)
        warning(You need to manually copy the vlc plugins folder over to $$DESTDIR in order for this to work!)
    }
}

# See https://trac.videolan.org/vlc/ticket/11681 for some fucked-up history
# Prior to the 2.2 release of VLC, plugins would be resolved relative to libvlc, in a ../plugins directory
# Due to changes in darwin/dirs.c, if your application binary is not named with something that starts with "VLC", the "global install" resolution is used
# In that case, the path for plugins is expected to be (relative to libvlc) in a vlc/plugins directory
# And obviously, this breaks atrociously because of the way plugins are linked to libvlc, so the symlink gymnastic
# XXX moving on to vlc3 then

!isEmpty(DUBO_INTERNAL){
    contains(DUBO_LINK_TYPE, dynamic){
        mac{
            system(rm -Rf $${DESTDIR}/$${TARGET}.app/Contents/MacOS/lib)
            system(mkdir -p $${DESTDIR}/$${TARGET}.app/Contents/MacOS/lib/vlc)
            # XXX this is creating copies of the symlinked, unversioned libs
            system(cp "$${DUBO_EXTERNAL}/lib/libvl*.dylib" "$$DESTDIR/$${TARGET}.app/Contents/MacOS/lib")
            system(cp -R "$${DUBO_EXTERNAL}/plugins" "$${DESTDIR}/$${TARGET}.app/Contents/MacOS/lib/vlc")
            QMAKE_LFLAGS += -Wl,-rpath,@executable_path/lib
        }
    }
}

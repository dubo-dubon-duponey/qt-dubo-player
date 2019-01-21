TEMPLATE = lib
QT = core widgets opengl

PROJECT_ROOT = $$PWD/..
include($$PROJECT_ROOT/config/qmakeitup.pri)

INCLUDEPATH += $$PWD

DEFINES += LIBDUBOPLAYER_LIBRARY
contains(DUBO_LINK_TYPE, static){
    DEFINES += LIBDUBOPLAYER_USE_STATIC
}

copyToDestdir($$PWD/lib$${TARGET}/*.h, $$DESTDIR/../include/lib$${TARGET})
copyToDestdir($$PWD/../res/redist/*, $$DESTDIR/../share/lib$${TARGET})

HEADERS += \
    $$PWD/lib$${TARGET}/global.h \
    $$PWD/lib$${TARGET}/core.h \
    $$PWD/lib$${TARGET}/root.h \
    $$PWD/lib$${TARGET}/simpleplayer.h \
    $$PWD/lib$${TARGET}/mediaplayer.h \
    $$PWD/lib$${TARGET}/audiocontrol.h \
    $$PWD/lib$${TARGET}/videocontrol.h \
    $$PWD/lib$${TARGET}/vlc2.h

SOURCES +=  $$PWD/root.cpp \
    $$PWD/core.cpp \
    $$PWD/mediaplayer.cpp \
    $$PWD/simpleplayer.cpp \
    $$PWD/audiocontrol.cpp \
    $$PWD/videocontrol.cpp \
    $$PWD/vlc2.cpp

contains(DUBO_LINK_TYPE, dynamic){
    win32{
        copyToDestdir($$DUBO_EXTERNAL/lib/libvlc.dll, $$DESTDIR)
        copyToDestdir($$DUBO_EXTERNAL/lib/libvlccore.dll, $$DESTDIR)
        warning(You need to manually copy the vlc plugins folder over to $$DESTDIR in order for this to work!)
# XXX find a way to copy over a folder with winblows
    #    copyToDestdir($$DUBO_EXTERNAL/lib/plugins/*, $$DESTDIR/plugins)
#        DDIR1 = $$DUBO_EXTERNAL/lib/plugins
#        DDIR2 = $$DESTDIR/plugins/
#        DDIR1 ~= s,/,\\,g
#        DDIR2 ~= s,/,\\,g

#            QMAKE_POST_LINK += cmd.exe /C xcopy $$quote($$DDIR1) $$quote($$DDIR2) $$escape_expand(\\n\\t)
#        system(xcopy $$quote($$DDIR1) $$quote($$DDIR2) $$escape_expand(\\n\\t))
    }
}

# See https://trac.videolan.org/vlc/ticket/11681 for some fucked-up history
# Prior to the 2.2 release of VLC, plugins would be resolved relative to libvlc, in a ../plugins directory
# Due to changes in darwin/dirs.c, if your application binary is not named with something that starts with "VLC", the "global install" resolution is used
# In that case, the path for plugins is expected to be (relative to libvlc) in a vlc/plugins directory
# And obviously, this breaks atrociously because of the way plugins are linked to libvlc, so the symlink gymnastic

!isEmpty(DUBO_INTERNAL){
    contains(DUBO_LINK_TYPE, dynamic){
        mac{
            system(rm -Rf $${DESTDIR}/lib)
            system(mkdir -p $${DESTDIR}/lib)
            # Pre 2.2
            # system(rm -Rf $${DESTDIR}/plugins)
            # Post 2.2
            system(mkdir -p $${DESTDIR}/lib/vlc)
            system(cp "$$DUBO_EXTERNAL/lib/libvl*.dylib" "$$DESTDIR/lib")
            # Pre 2.2
            system(cp -R "$$DUBO_EXTERNAL/plugins" "$${DESTDIR}")
            # Post 2.2
            system(ln -s "../../plugins" "$${DESTDIR}/lib/vlc")
        }
    }
}

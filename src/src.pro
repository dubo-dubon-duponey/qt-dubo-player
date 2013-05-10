TEMPLATE = lib
QT = core widgets webkit webkitwidgets

DEFINES += LIBROXEEPLAYER_LIBRARY

HEADERS += \
    $$PWD/include/libroxeeplayer/libroxeeplayer_global.h \
    $$PWD/include/libroxeeplayer/core.h \
    $$PWD/include/libroxeeplayer/root.h \
    $$PWD/include/libroxeeplayer/simpleplayer.h \
    $$PWD/include/libroxeeplayer/mediaplayer.h \
    $$PWD/include/libroxeeplayer/audiocontrol.h \
    $$PWD/include/libroxeeplayer/videocontrol.h \
    $$PWD/include/libroxeeplayer/webpluginfactory.h \
    $$PWD/include/libroxeeplayer/vlc2.h

SOURCES +=  $$PWD/root.cpp \
    $$PWD/core.cpp \
    $$PWD/mediaplayer.cpp \
    $$PWD/simpleplayer.cpp \
    $$PWD/audiocontrol.cpp \
    $$PWD/videocontrol.cpp \
    $$PWD/vlc2.cpp \
    $$PWD/webpluginfactory.cpp

include($$PWD/../config/common.pri)

contains(ROXEE_LINK_TYPE, static){
    DEFINES += LIBROXEEPLAYER_USE_STATIC
}

INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/include
target.path = $$DESTDIR
INSTALLS += target

copyToDestdir($$PWD/include/libroxeeplayer/*, $$DESTDIR/../include/libroxeeplayer)
copyToDestdir($$PWD/../res/redist/*, $$DESTDIR/../share/libroxeeplayer)

contains(ROXEE_LINK_TYPE, dynamic){
    win32{
        copyToDestdir($$ROXEE_EXTERNAL/lib/libvlc.dll, $$DESTDIR)
        copyToDestdir($$ROXEE_EXTERNAL/lib/libvlccore.dll, $$DESTDIR)
        warning(You need to manually copy the vlc plugins folder over to $$DESTDIR in order for this to work!)
# XXX find a way to copy over a folder with winblows
    #    copyToDestdir($$ROXEE_EXTERNAL/lib/plugins/*, $$DESTDIR/plugins)
#        DDIR1 = $$ROXEE_EXTERNAL/lib/plugins
#        DDIR2 = $$DESTDIR/plugins/
#        DDIR1 ~= s,/,\\,g
#        DDIR2 ~= s,/,\\,g

#            QMAKE_POST_LINK += cmd.exe /C xcopy $$quote($$DDIR1) $$quote($$DDIR2) $$escape_expand(\\n\\t)
#        system(xcopy $$quote($$DDIR1) $$quote($$DDIR2) $$escape_expand(\\n\\t))
    }
}

!isEmpty(ROXEE_INTERNAL){
    contains(ROXEE_LINK_TYPE, dynamic){
        mac{
            system(rm -Rf $${DESTDIR}/lib)
            system(rm -Rf $${DESTDIR}/plugins)
            system(mkdir -p $${DESTDIR}/lib)
            system(cp "$$ROXEE_EXTERNAL/lib/libvlccore.5.dylib" "$$DESTDIR/lib")
            system(cp "$$ROXEE_EXTERNAL/lib/libvlc.5.dylib" "$$DESTDIR/lib")
            system(cp -R "$$ROXEE_EXTERNAL/plugins" "$${DESTDIR}")
        }
    }
}

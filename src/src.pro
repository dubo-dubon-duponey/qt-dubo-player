TEMPLATE = lib
QT = core widgets webkit webkitwidgets

include($$PWD/../config/common.pri)

DEFINES += LIBROXEEPLAYER_LIBRARY

contains(ROXEE_LINK_TYPE, static){
    DEFINES += LIBROXEEPLAYER_USE_STATIC
}

INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/include
target.path = $$DESTDIR
INSTALLS += target

copyToDestdir($$PWD/include/libroxeeplayer/*, $$DESTDIR/../include/libroxeeplayer)
copyToDestdir($$PWD/../res/redist/*, $$DESTDIR/../share/libroxeeplayer)

!isEmpty(ROXEE_INTERNAL){
    contains(ROXEE_LINK_TYPE, dynamic){
        win32{
            copyToDestdir($$ROXEE_EXTERNAL/lib/libvlc.dll, $$DESTDIR)
            copyToDestdir($$ROXEE_EXTERNAL/lib/libvlccore.dll, $$DESTDIR)
        #    copyToDestdir($$ROXEE_EXTERNAL/lib/plugins/*, $$DESTDIR/plugins)
        }
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
#    stupidwidget.h

SOURCES +=  $$PWD/root.cpp \
    $$PWD/core.cpp \
    $$PWD/mediaplayer.cpp \
    $$PWD/simpleplayer.cpp \
    $$PWD/audiocontrol.cpp \
    $$PWD/videocontrol.cpp \
    $$PWD/vlc2.cpp \
    $$PWD/webpluginfactory.cpp
#    stupidwidget.cpp

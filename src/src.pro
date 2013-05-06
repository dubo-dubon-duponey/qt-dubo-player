TEMPLATE = lib
QT = core widgets webkit webkitwidgets

include($$PWD/../conf/conf.pri)

DEFINES += LIBROXEEPLAYER_LIBRARY

contains(ROXEE_LINK_TYPE, static){
    DEFINES += LIBROXEEPLAYER_USE_STATIC
}

INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/include
target.path = $$DESTDIR
INSTALLS += target


defineTest(copyToDestdir) {
    files = $$1
    dest = $$2

    for(FILE, files) {
        DDIR = $$dest

        # Replace slashes in paths with backslashes for Windows
        win32:FILE ~= s,/,\\,g
        win32:DDIR ~= s,/,\\,g

        win32{
            system(mkdir $$quote($$DDIR))
        }else{
            system(mkdir -p $$quote($$DDIR))
        }
        message(********************************************)
        message($$QMAKE_COPY $$quote($$FILE) $$quote($$DDIR) $$escape_expand(\\n\\t))
        message(********************************************)

        QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$FILE) $$quote($$DDIR) $$escape_expand(\\n\\t)
    }

    export(QMAKE_POST_LINK)
}

copyToDestdir($$PWD/include/libroxeeplayer/*, $$DESTDIR/../include/libroxeeplayer)
copyToDestdir($$PWD/../res/redist/*, $$DESTDIR/../share/libroxeeplayer)

# XXX careful with that - if both directories are the same
win32{
    contains(ROXEE_LINK_TYPE, dynamic){
        copyToDestdir($$ROXEE_EXTERNAL/lib/libvlc.dll, $$DESTDIR)
        copyToDestdir($$ROXEE_EXTERNAL/lib/libvlccore.dll, $$DESTDIR)
    #    copyToDestdir($$ROXEE_EXTERNAL/lib/plugins/*, $$DESTDIR/plugins)
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

TEMPLATE = app
QT = core widgets

PROJECT_ROOT = $$PWD/..
include($$PROJECT_ROOT/config/qmakeitup.pri)

renv=$$(DUBO_WITH_WEBKIT)
!isEmpty(renv){
    DUBO_WITH_WEBKIT = $$renv
}
isEqual(DUBO_WITH_WEBKIT, true) {
    QT += webkit webkitwidgets
    DEFINES += DUBO_WITH_WEBKIT=true
}

INCLUDEPATH += $$PWD

LIBS += -l$${DUBO_LINK_NAME}

contains(DUBO_LINK_TYPE, static){
    # Define that if you want to use it statically (msvc at least)
    DEFINES += LIBDUBOPLAYER_USE_STATIC
    win32{
        copyToDestdir($$DUBO_EXTERNAL/lib/libvlc.dll, $$DESTDIR)
        copyToDestdir($$DUBO_EXTERNAL/lib/libvlccore.dll, $$DESTDIR)
        warning(You need to manually copy the vlc plugins folder over to $$DESTDIR in order for this to work!)
    #    copyToDestdir($$DUBO_EXTERNAL/lib/plugins/*, $$DESTDIR/plugins)
    }

    !isEmpty(DUBO_INTERNAL){
        mac{
            system(rm -Rf $${DESTDIR}/$${TARGET}.app/Contents/MacOS/lib)
            system(rm -Rf $${DESTDIR}/$${TARGET}.app/Contents/MacOS/plugins)
            system(mkdir -p $${DESTDIR}/$${TARGET}.app/Contents/MacOS/lib/vlc)
            system(cp "$${DUBO_EXTERNAL}/lib/libvl*.dylib" "$$DESTDIR/$${TARGET}.app/Contents/MacOS/lib")
            # Pre 2.2
            system(cp -R "$${DUBO_EXTERNAL}/plugins" "$${DESTDIR}/$${TARGET}.app/Contents/MacOS")
            # Post 2.2
            system(ln -s "../../plugins" "$${DESTDIR}/$${TARGET}.app/Contents/MacOS/lib/vlc")
        }
    }
}

SOURCES +=  $$PWD/main.cpp

OTHER_FILES += video.html
OTHER_FILES += hack.js
RESOURCES += video.qrc

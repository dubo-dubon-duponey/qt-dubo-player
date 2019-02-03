TEMPLATE = app
QT = core widgets webengine webenginewidgets webchannel

PROJECT_ROOT = $$PWD/..
include($$PROJECT_ROOT/config/qmakeitup.pri)

INCLUDEPATH += $$PWD
LIBS        += -l$${DUBO_LINK_NAME}
SOURCES     += $$PWD/main.cpp
RESOURCES   += $$PWD/demo.qrc

mac{
    # Add plist, and a nice icon
    OTHER_FILES         += $$PWD/Info.plist \
                           $$PWD/demo.icns

    QMAKE_INFO_PLIST    = $${PWD}/Info.plist
    ICON                = $${PWD}/demo.icns
}







contains(DUBO_LINK_TYPE, static){
    win32{
        copyToDestdir($$DUBO_EXTERNAL/lib/libvlc.dll, $$DESTDIR)
        copyToDestdir($$DUBO_EXTERNAL/lib/libvlccore.dll, $$DESTDIR)
        warning(You need to manually copy the vlc plugins folder over to $$DESTDIR in order for this to work!)
    #    copyToDestdir($$DUBO_EXTERNAL/lib/plugins/*, $$DESTDIR/plugins)
    }

    !isEmpty(DUBO_INTERNAL){
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

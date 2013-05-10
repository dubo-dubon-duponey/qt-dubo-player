TEMPLATE = app
QT = core widgets webkit webkitwidgets

SOURCES +=  $$PWD/main.cpp

OTHER_FILES += video.html
OTHER_FILES += hack.js
RESOURCES += video.qrc

# Below are just funky helpers - just link to the lib and you should be fine
include($$PWD/../config/common.pri)

LIBS += -l$${ROXEE_LINK_NAME}

INCLUDEPATH += $$PWD
target.path = $$DESTDIR
INSTALLS += target

contains(ROXEE_LINK_TYPE, static){
    # Define that if you want to use it statically (msvc at least)
    DEFINES += LIBROXEEPLAYER_USE_STATIC
    win32{
        copyToDestdir($$ROXEE_EXTERNAL/lib/libvlc.dll, $$DESTDIR)
        copyToDestdir($$ROXEE_EXTERNAL/lib/libvlccore.dll, $$DESTDIR)
        warning(You need to manually copy the vlc plugins folder over to $$DESTDIR in order for this to work!)
    #    copyToDestdir($$ROXEE_EXTERNAL/lib/plugins/*, $$DESTDIR/plugins)
    }
    !isEmpty(ROXEE_INTERNAL){
        mac{
            system(rm -Rf $${DESTDIR}/$${TARGET}.app/Contents/MacOS/lib)
            system(rm -Rf $${DESTDIR}/$${TARGET}.app/Contents/MacOS/plugins)
            system(mkdir -p $${DESTDIR}/$${TARGET}.app/Contents/MacOS/lib)
            system(cp "$${ROXEE_EXTERNAL}/lib/libvlccore.5.dylib" "$$DESTDIR/$${TARGET}.app/Contents/MacOS/lib")
            system(cp "$${ROXEE_EXTERNAL}/lib/libvlc.5.dylib" "$$DESTDIR/$${TARGET}.app/Contents/MacOS/lib")
            system(cp -R "$${ROXEE_EXTERNAL}/plugins" "$${DESTDIR}/$${TARGET}.app/Contents/MacOS")
        }
    }
}

TEMPLATE = app
QT = core widgets webkit webkitwidgets

SOURCES +=  $$PWD/main.cpp

include($$PWD/../config/common.pri)

LIBS += -l$${ROXEE_LINK_NAME}

INCLUDEPATH += $$PWD
target.path = $$DESTDIR
INSTALLS += target

OTHER_FILES = video.html
RESOURCES += video.qrc


contains(ROXEE_LINK_TYPE, static){
    DEFINES += LIBROXEEPLAYER_USE_STATIC
    win32{
        copyToDestdir($$ROXEE_EXTERNAL/lib/libvlc.dll, $$DESTDIR)
        copyToDestdir($$ROXEE_EXTERNAL/lib/libvlccore.dll, $$DESTDIR)
    #    copyToDestdir($$ROXEE_EXTERNAL/lib/plugins/*, $$DESTDIR/plugins)
    }
    !isEmpty(ROXEE_INTERNAL){
        mac{
            system(rm -Rf $${DESTDIR}/roxeeplayer.app/Contents/MacOS/lib)
            system(rm -Rf $${DESTDIR}/roxeeplayer.app/Contents/MacOS/plugins)
            system(mkdir -p $${DESTDIR}/roxeeplayer.app/Contents/MacOS/lib)
            system(cp "$$ROXEE_EXTERNAL/lib/libvlccore.5.dylib" "$$DESTDIR/roxeeplayer.app/Contents/MacOS/lib")
            system(cp "$$ROXEE_EXTERNAL/lib/libvlc.5.dylib" "$$DESTDIR/roxeeplayer.app/Contents/MacOS/lib")
            system(cp -R "$$ROXEE_EXTERNAL/plugins" "$${DESTDIR}/roxeeplayer.app/Contents/MacOS")
        }
    }
}

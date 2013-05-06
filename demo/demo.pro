TEMPLATE = app

## Basic consumer variables
QT = core widgets webkit webkitwidgets

SOURCES +=  $$PWD/main.cpp

# You don't "need" any "magic" of the following - just link against the produced library if you are doing it your own way
include($$PWD/../conf/conf.pri)

INCLUDEPATH += $$PWD
target.path = $$DESTDIR
INSTALLS += target

OTHER_FILES = video.html
RESOURCES += video.qrc

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

win32{
    contains(ROXEE_LINK_TYPE, static){
        DEFINES += LIBROXEEPLAYER_USE_STATIC
        copyToDestdir($$ROXEE_EXTERNAL/lib/libvlc.dll, $$DESTDIR)
        copyToDestdir($$ROXEE_EXTERNAL/lib/libvlccore.dll, $$DESTDIR)
    #    copyToDestdir($$ROXEE_EXTERNAL/lib/plugins/*, $$DESTDIR/plugins)
    }
}

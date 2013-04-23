contains(TEMPLATE, app){
    INCLUDEPATH +=  $$DESTDIR/../include
    LIBS += -L$$DESTDIR/../lib
    LIBS += -l$${TARGET}
}

#contains(TEMPLATE, lib){
#    win32{
#        #CONFIG += staticlib
#        # ROXEE_EXTERNAL should point to that ../../vlc-2.0.1/sdk
#        #    LIBS += libvlc.dll.a libvlccore.dll.a
#        win32-g++ {
#        }

#        win32-msvc{
#        }
#    }

#    # Mac specific configuration
#    mac{
#        # Only if static
#        #LIBS += -lvlccore
#    }

#    # Unix specific configuration
#    unix:!mac {
#        # Only if static
#        #LIBS += -lvlccore
#    }
#}


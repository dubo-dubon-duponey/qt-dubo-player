TEMPLATE = lib
QT = core widgets

include($$PWD/../conf/conf.pri)

DEFINES += LIBROXEEPLAYER_LIBRARY

contains(ROXEE_LINK_TYPE, static){
    DEFINES += LIBROXEEPLAYER_USE_STATIC
}

INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/include
target.path = $$DESTDIR
INSTALLS += target

# Copy headers to destination
system(rm -Rf "$$DESTDIR/../include/libroxeeplayer")
system(mkdir -p "$$DESTDIR/../include")
system(cp -R "$$PWD/include/libroxeeplayer" "$$DESTDIR/../include")
system(rm -Rf "$$DESTDIR/../share/libroxeeplayer")
system(mkdir -p "$$DESTDIR/../share/libroxeeplayer")
system(cp "$$PWD/../res/redist/*" "$$DESTDIR/../share/libroxeeplayer")


# XXX private stuff - to be removed

#renvlt=$$(ROXEE_LINK_TYPE)
#isEmpty(renvlt){
#    renvlt=$$ROXEE_LINK_TYPE
#}

#isEmpty(ROXEE_EXTERNAL){
#    CONFIG(debug, debug|release){
#        mac{
#            ROXEE_EXTERNAL = /Users/dmp/buildd/deploy.webitup.org/client/Darwin/debug/$${renvlt}
#        }
#    }else{
#        mac{
#            ROXEE_EXTERNAL = /Users/dmp/buildd/deploy.webitup.org/client/Darwin/release/$${renvlt}
#        }
#    }
#}


HEADERS += \
    $$PWD/include/libroxeeplayer/libroxeeplayer_global.h \
    $$PWD/include/libroxeeplayer/core.h \
    $$PWD/include/libroxeeplayer/root.h \
    $$PWD/include/libroxeeplayer/simpleplayer.h \
#    $$PWD/include/libroxeeplayer/stackedplayer.h \
    $$PWD/include/libroxeeplayer/mediaplayer.h \
    $$PWD/include/libroxeeplayer/audiocontrol.h \
    $$PWD/include/libroxeeplayer/videocontrol.h \
    $$PWD/include/libroxeeplayer/vlc2.h
#    $$PWD/coreinstance.h

SOURCES +=  $$PWD/root.cpp \
    $$PWD/core.cpp \
#    $$PWD/coreinstance.cpp \
    $$PWD/mediaplayer.cpp \
    $$PWD/simpleplayer.cpp \
#    $$PWD/stackedplayer.cpp \
    $$PWD/audiocontrol.cpp \
    $$PWD/videocontrol.cpp \
    $$PWD/vlc2.cpp

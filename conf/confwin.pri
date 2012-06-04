#Debug
CONFIG(debug, debug|release): CONFIG += console

win32-g++ {
  include(confwin-mingw.pri)
}
else {
  include(confwin-msvc.pri)
}

#CONFIG += staticlib
CONFIG += dll

INCLUDEPATH += ../../../src/vlc-2.0.1/sdk/include/
LIBS += -L../../../src/vlc-2.0.1/sdk/lib/
#    LIBS += libvlc.dll.a libvlccore.dll.a
LIBS += -llibvlc -llibvlccore

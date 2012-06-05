#Debug
#CONFIG(debug, debug|release): CONFIG += console

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


DEFINES += UNICODE
DEFINES += WIN32
DEFINES += WIN32_LEAN_AND_MEAN
DEFINES += _CRT_SECURE_NO_DEPRECATE
DEFINES += _FILE_OFFSET_BITS=64
DEFINES += _SCL_SECURE_NO_DEPRECATE
DEFINES += _UNICODE
DEFINES += _WIN32
DEFINES += _WIN32_WINNT=0x0500
DEFINES += _WIN32_IE=0x0500
DEFINES += __USE_W32_SOCKETS

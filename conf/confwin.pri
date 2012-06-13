win32-g++ {
  include(confwin-mingw.pri)
}
else {
  include(confwin-msvc.pri)
}

#CONFIG += staticlib
CONFIG += dll

INCLUDEPATH += ../../vlc-2.0.1/sdk/include/
LIBS += -L../../vlc-2.0.1/sdk/lib/
#    LIBS += libvlc.dll.a libvlccore.dll.a
LIBS += -llibvlc -llibvlccore


# Windows stuff
DEFINES += UNICODE
DEFINES += WIN32
DEFINES += WIN32_LEAN_AND_MEAN
DEFINES += _FILE_OFFSET_BITS=64
DEFINES += _UNICODE
DEFINES += _WIN32
DEFINES += _WIN32_WINNT=0x0500
DEFINES += __USE_W32_SOCKETS
DEFINES += _CRT_SECURE_NO_DEPRECATE
DEFINES += _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES
DEFINES += _CRT_NONSTDC_NO_DEPRECATE

#QMAKE_CFLAGS_RELEASE += -Zi

# THIS CRAP IS THE ONLY WAY to not have my crappy shitty singleton crash on me
QMAKE_LFLAGS_RELEASE += /DEBUG

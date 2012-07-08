win32-g++ {
  include(confwin-mingw.pri)
}
else {
  include(confwin-msvc.pri)
}

#CONFIG += staticlib
INCLUDEPATH += ../../vlc-2.0.1/sdk/include/
LIBS += -L../../vlc-2.0.1/sdk/lib/
#    LIBS += libvlc.dll.a libvlccore.dll.a
LIBS += -llibvlc -llibvlccore

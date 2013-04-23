TEMPLATE = app

## Basic consumer variables
QT = core widgets

SOURCES +=  $$PWD/main.cpp

# You don't "need" any "magic" of the following - just link against the produced library if you are doing it your own way
include($$PWD/../conf/conf.pri)

INCLUDEPATH += $$PWD
target.path = $$DESTDIR
INSTALLS += target

# Include library
#INCLUDEPATH +=  $$DESTDIR/../include
#LIBS += -L$$DESTDIR/../lib
#LIBS += -l$${TARGET}

## http://forum.videolan.org/viewtopic.php?f=32&t=61157
## http://developer.qt.nokia.com/doc/qt-4.8/qapplication.html


QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.6

# Linking dynamically on OSX
CONFIG += absolute_library_soname

# Pointing to include and lib dirs
INCLUDEPATH += $${DEPDIR}/include
LIBS += -L$${DEPDIR}/lib
LIBS += -lvlc
LIBS += -framework Cocoa

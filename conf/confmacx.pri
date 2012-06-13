QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.6

# Pointing to include and lib dirs
LIBS += -lvlc
# Only if static
LIBS += -lvlccore
LIBS += -framework Cocoa

ROXEE_PROJECT_NAME = RoxeePlayer
ROXEE_VENDOR_NAME = WebItUp
ROXEE_PROJECT_VERSION_MAJOR = 0
ROXEE_PROJECT_VERSION_MINOR = 8
ROXEE_PROJECT_VERSION_BUGFIX = 0
ROXEE_MINIMUM_QT = 4.6
ROXEE_MIN_OSX = 10.6

# Name of the target
TARGET = roxeeplayer

# Any of the following may also be specified using environment variables

# Wether to build static, plugin or shared library
#ROXEE_LINK_TYPE = static
ROXEE_LINK_TYPE = dynamic

# If you want to use the provided mechanism to fetch and link third-party dependencies, specify which version you want here
# Otherwise, you must specify ROXEE_EXTERNAL (below)
ROXEE_INTERNAL_VERSION = 2.0.7-x86_64-20130430-0318
ROXEE_INTERNAL_PATH = VLC.app/Contents/MacOS

# Where to find additional dependencies (include and libs)
# Note this will be used BEFORE any other manually specified source, so, careful with that
win32{
    ROXEE_EXTERNAL = C:\roxeelove\buildd-deploy\gcc\release\static
}

mac{
    ROXEE_EXTERNAL =
}

# Where to output the final build (will default to buildd/platform/compiler-qtmajorversion-linktype-debug)
ROXEE_DESTDIR =

ROXEE_WIN_LIBS = -llibvlc -llibvlccore
ROXEE_NUX_LIBS = -lvlc
ROXEE_OSX_LIBS = -lvlc

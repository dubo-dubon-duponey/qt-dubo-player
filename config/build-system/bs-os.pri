# Generic QT/OS settings
mac{
    QMAKE_MACOSX_DEPLOYMENT_TARGET = $$ROXEE_MIN_OSX
}

win32{
    # Exclude cruft from the SDK
    DEFINES += WIN32_LEAN_AND_MEAN

    # Windows XP
    DEFINES += _WIN32_WINNT=0x0501
    DEFINES += _WIN32_IE=0x0501

    # http://stackoverflow.com/questions/662084/whats-the-difference-between-the-win32-and-win32-defines-in-c
    DEFINES += WIN32
    DEFINES += _WIN32

    # Large support
    DEFINES += _FILE_OFFSET_BITS=64

    DEFINES += UNICODE
    DEFINES += _UNICODE

    # Cygwin requires that stuff when using boost ASIO - but we don't support cygwin
    DEFINES += __USE_W32_SOCKETS
}


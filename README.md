# DuboPlayer

> "Dubo Components" are lightweight, targeted c++ libraries meant for QT applications.
> They aim at providing *simple to use* interfaces for a range of functionality
(notification, crash reporting, zero conf, application update, torrent, etc).
> Fully scriptable, they are primarily meant for javascript (from a QWebEngine) - thought they are usable as well in plain QT.
> Put together, these components should provide a comprehensive foundation for these building a "WebRunner", similarly to Electron.

DuboPlayer is a thin layer library on top of libvlc that exposes a QT-ified (scriptable) API for it.

It is meant:
- to be cross-platform (specifically sports OSX, unlike other libraries)
- to be usable either as a simple QWidget, or as a WebView plugin for HTML oriented webrunners
- primarily to serve as part of the Dubo webrunner application, though other people might find interest in it
- depend solely on libvlc, and QWidget (no QML crap)
- provide a get-go-ready solution, leaving the implementor only to bother about the player controls

It currently supports:
- most of vlc API, including events (through slots)
- multiple simultaneous players
- works from QT 4.8 and libvlc 2.0 (the WebPlugin requires QT5)

There exist at least two other implementations with a somewhat similar purpose (save scriptability, strict libvlc isolation and OSX support):
- https://bitbucket.org/trollixx/qtvlc/
- https://github.com/ntadej/vlc-qt/tree/master/src/core

## License

LGPL (same as libvlc).

## TL;DR

qmake
make

Run.

By default, this build against a network fetched vlc (OSX), the system installed one (linux), or the third-party embedded one (windows).
If you want to build against a specific vlc version, edit src/config/$PLATFORM.pri (win, mac, other) and point the DUBO_EXTERNAL
variable to where your vlc sdk folder lives.

## Doesn't work?

Failure to start your application, or vlc complaining about "plugins", usually means it can't find either libvlc, or the plugins folder.
You need to ensure both are in the library output folder.

## Build details

Inside src/config/$PLATFORM.pri, you may additionally pick an output build folder (DUBO_DESTDIR),

You can also decide to build a dynamic or static library.

By default, the project builds a shared library on OSX and Other, and a static one on Windows.

Note that any of these variables (DUBO_*) may be overriden from the environment.
eg: DUBO_LINK_TYPE=static qmake CONFIG+=debug

## How to create your own application

Check your build dir ("buildd", by default).
You will find a lib and include folder.
Link and include against these, then link against the "duboplayer" library.

Don't forget to put libvlc, libvlccore and the vlc plugins folder near the binary (if statically compiled),
or near the dubo library (if dynamically compiled).

Look into the demo subproject for inspiration, and read the headers (or the doxygen doc).

There are two ways to use it, mainly:
- use the SimplePlayer class, which is a QWidget
- use the WebPlugin factory if you want an html-usable plugin.

## About that "third-party" folder

On OSX, ./bootstrap.sh is called and does fetch VLC *binary* release to be linked by the project.

BE AWARE that no verification of any sort is performed on the retrieved binary, and that it is fetched over
unencrypted http. You really shouldn't *release* anything using that method if you give a fuck.

## Caveats and compatibility.

On windows, for the WebPlugin:
- QT 5.0.2: the WebPlugin will crash if your object tag has a dynamic size. Sounds like a QtWebKit bug...
Only solution is to throttle resizes on the node in javascript (just add hack.js to your view, and you are safe).
On OSX, it would "simply" complain about QPainterDevice.
- QT 5.0.2: obtaining mouse move events from the plugin is tricky (again handled by hack.js)
- QT 5.0.2, msvc dynamic builds: crash if DEBUG (can still use them in RELEASE)
Conversely, msvc static builds crash if RELEASE (can still use them in DEBUG).
Mixing mingw-vlc and msvc is a kinky idea anyhow...
But maybe investigate QMAKE_LFLAGS_RELEASE += /DEBUG

## API

Doxygen documentation should be generated as part of the build if you have the doxygen binary, though the doc effort is slick right now...

## TODO

Urgent:

Check every platform (windows done).
Implement vlm functions.

Medium:

Have a flag to build w/o WebPluginFactory (and be smart about minimum OSX version in that - QtWebKit in QT5 is no longer 10.6 compatible).
Find a way to copy plugins over on windows.
Fix third-party (OSX) version / fetch (need 2.0.7 and a better system for nightly builds).
Automatic network fetch on windows? Msys based, if present?
Integrate a platform dependent "app packager" for demo in order to ease testing.

Low priority:

Have a way to turn on / off debug messages
Write better documentation (especially a javascript API) - and fix existing one.
Express dependency on libvlc version.
Migrate to libvlc 2.1.
Verify windows behavior on key and clicks events.
Finish up and test remaining missing bits (aspectRatio comes to mind).
Better lib versioning (specially on windows?).
Investigate the reason msvc crash with shared libs in somes cases.
Switch license to GPL.
Package as a QT plugin.
Have bug tests (regression testing on libvlc).
Enhance build system to detect more efficiently if the system is working.
Better website for the project.
# http://forum.videolan.org/viewtopic.php?f=32&t=61157

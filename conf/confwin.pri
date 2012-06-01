#Debug
CONFIG(debug, debug|release): CONFIG += console

win32-g++ {
  include(confwin-mingw.pri)
}
else {
  include(confwin-msvc.pri)
}

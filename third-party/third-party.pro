TEMPLATE = subdirs

OTHER_FILES +=  $$PWD/README \
                $$PWD/bootstrap.sh

PROJECT_ROOT = $$PWD/..
include($$PROJECT_ROOT/config/qmakeitup.pri)

# Only mac has deps for now
mac{
    !isEmpty(DUBO_INTERNAL){
        message( -> Using internal third-party $${DUBO_INTERNAL_VERSION})
        system($$PWD/bootstrap.sh $${DUBO_INTERNAL_VERSION})
    }
}

#!mac:!win32{
#    warning( -> Nothing is done on linux: you need to install libvlcdev by your own means and possibly point DUBO_EXTERNAL manually to it)
#}

#win32{
#    warning( -> Nothing is done on windows: you need to point DUBO_EXTERNAL manually to your libVLC root path)
#}

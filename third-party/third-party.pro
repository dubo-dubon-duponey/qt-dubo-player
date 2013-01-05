TEMPLATE = subdirs

OTHER_FILES +=  $$PWD/README \
                $$PWD/bootstrap.sh

include($$PWD/../vars.pri)
include($$PWD/../conf/confbase.pri)

# Only mac has deps for now
mac{
    !isEmpty(ROXEE_INTERNAL_VERSION){
        message( -> Using internal third-party $${ROXEE_INTERNAL_VERSION})
        system(./bootstrap.sh $${ROXEE_INTERNAL_VERSION})
        system(rm -f $${DESTDIR}/lib/lib)
        system(ln -s `pwd`/VLC.app/Contents/MacOS/lib $${DESTDIR}/lib)
    }
}

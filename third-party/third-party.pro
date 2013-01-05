TEMPLATE = subdirs

OTHER_FILES +=  $$PWD/README \
                $$PWD/bootstrap.sh

include($$PWD/../conf/conf.pri)

message(************************* Building Third-Party *************************)

# Only mac has deps for now
mac{
    !isEmpty(ROXEE_INTERNAL_VERSION){
        message( -> Using internal third-party $${ROXEE_INTERNAL_VERSION})
        system(./bootstrap.sh $${ROXEE_INTERNAL_VERSION})

#        contains(TEMPLATE, app){
        contains(ROXEE_LINK_TYPE, static){
            LINKIN = $${DESTDIR}/bin/$${TARGET}.app/Contents/MacOS/
            system(rm -f "$$LINKIN/lib")
            system(ln -s "`pwd`/VLC.app/Contents/MacOS/lib" "$$LINKIN")
            message(ln -s "`pwd`/VLC.app/Contents/MacOS/lib" "$$LINKIN")
        }
#        }
#        contains(TEMPLATE, lib){
            contains(ROXEE_LINK_TYPE, dynamic){
                system(rm -f "$${DESTDIR}/lib/lib")
                system(mkdir -p "$${DESTDIR}/lib")
                system(ln -s "`pwd`/VLC.app/Contents/MacOS/lib" "$${DESTDIR}/lib")
            }
#        }


    }
}

!mac:!win32{
    warning( -> Nothing is done on linux: you need to install libvlcdev by your own means and possibly point ROXEE_EXTERNAL manually to it)
}

win32{
    warning( -> Nothing is done on windows: you need to point ROXEE_EXTERNAL manually to your libVLC root path)
}

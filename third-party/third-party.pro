TEMPLATE = subdirs

OTHER_FILES +=  $$PWD/README \
                $$PWD/bootstrap.sh

include($$PWD/../config/common.pri)

message(************************* Building Third-Party *************************)

# Only mac has deps for now
mac{
    !isEmpty(ROXEE_INTERNAL){
        message( -> Using internal third-party $${ROXEE_INTERNAL_VERSION})
        system(./bootstrap.sh $${ROXEE_INTERNAL_VERSION})

##        contains(TEMPLATE, app){
#        contains(ROXEE_LINK_TYPE, static){
#            LINKIN = $${DESTDIR}/bin/$${TARGET}.app/Contents/MacOS/
##            system(rm -f "$$LINKIN/lib/")
#        }
##        }
##        contains(TEMPLATE, lib){
#        contains(ROXEE_LINK_TYPE, dynamic){
#            LINKIN = $${DESTDIR}/lib/
#        }

#        system(rm -Rf "$$LINKIN/lib")
#        system(mkdir -p "$$LINKIN")
#        system(ln -s "`pwd`/$${ROXEE_INTERNAL_PATH}/lib" "$$LINKIN")
    }
}

#!mac:!win32{
#    warning( -> Nothing is done on linux: you need to install libvlcdev by your own means and possibly point ROXEE_EXTERNAL manually to it)
#}

#win32{
#    warning( -> Nothing is done on windows: you need to point ROXEE_EXTERNAL manually to your libVLC root path)
#}

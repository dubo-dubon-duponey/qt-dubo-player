TEMPLATE = subdirs
OTHER_FILES +=  $$PWD/doc.sh \
                $$PWD/Doxyfile

message(************************* Building Doc *************************)
!win32{
    system(./doc.sh)
}

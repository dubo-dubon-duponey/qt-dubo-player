TEMPLATE = subdirs
OTHER_FILES +=  $$PWD/doc.sh \
                $$PWD/doxygen.tpl

message(************************* Building Doc *************************)
!win32{
    system(./doc.sh)
}

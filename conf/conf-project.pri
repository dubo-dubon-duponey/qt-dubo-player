contains(TEMPLATE, app){
    INCLUDEPATH +=  $$DESTDIR/../include
    LIBS += -L$$DESTDIR/../lib
    win32{
        contains(ROXEE_LINK_TYPE, static){
            LIBS += -l$${TARGET}
        }else{
            LIBS += -l$${TARGET}0
        }
    }else{
        LIBS += -l$${TARGET}
    }
}

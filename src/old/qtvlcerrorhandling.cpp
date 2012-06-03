#include "qtvlcerrorhandling.h"
#include <vlc/vlc.h>

using namespace QtVlc;

ErrorHandling::ErrorHandling(QObject *parent) :
    QObject(parent)
{
}

ErrorHandling::~ErrorHandling()
{
}

QString ErrorHandling::errMsg()
{
    QString m = libvlc_errmsg();
    this->clearErr();
    return m;
}

void ErrorHandling::clearErr()
{
    libvlc_clearerr();
}

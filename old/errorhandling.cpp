#include "errorhandling.h"
#include <vlc/vlc.h>


namespace RoxeePlayer{

ErrorHandling::ErrorHandling(QObject *parent) :
    QObject(parent)
{
}

ErrorHandling::~ErrorHandling()
{
}

QString ErrorHandling::getErrMsg()
{
    return QString::fromUtf8(libvlc_errmsg());
}

void ErrorHandling::clearErr()
{
    libvlc_clearerr();
}

}

#ifndef QTVLC_GLOBAL_H
#define QTVLC_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QTVLC_LIBRARY)
#  define QTVLCSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTVLCSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QTVLC_GLOBAL_H

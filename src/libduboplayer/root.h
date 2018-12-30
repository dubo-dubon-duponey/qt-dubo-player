/*****************************************************************************
 * Copyright (c) 2019, Dubo Dubon Duponey <dubodubonduponey+github@pm.me>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifndef DUBOPLAYER_ROOT_H
#define DUBOPLAYER_ROOT_H

#include "global.h"

#include <QObject>

/*!
\mainpage
This library is primarily meant to be used by the Dubo Webrunner.
Its purpose is to provide a clean, QT-ified, scriptable API that introduces as little extra complexity as possible over
the underyling video player library, and ideally, be API independent from that library.
Right now though, it only supports (and is meant for) libvlc (http://www.videolan.org/vlc/libvlc.html).

To compile:
- build or install libvlc (http://wiki.videolan.org/LibVLC) (if you are on OSX, VLC is automatically fetched - see third-party)
- edit the config/$PLATFORM.pri file so that it matches your mileage:
- qmake, then make
- possibly copy over the libvlc plugins folder, and run

To use it, just create a DuboPlayer::SimplePlayer object.
This is specifically meant to be exposed for a QWebPluginFactory.


This code is distributed under the terms of the LGPL license.
*/

/*! \namespace DuboPlayer
\brief The library namespace.
*/

namespace DuboPlayer
{

/*! \brief Library root object. Don't instanciate. Query root on a SimplePlayer instead. */
class LIBDUBOPLAYERSHARED_EXPORT Root: public QObject {
    Q_OBJECT
public:
    /*! \brief The name of the library.*/
    Q_PROPERTY(const QString NAME READ getName CONSTANT)
    /*! \brief The name of the vendor.*/
    Q_PROPERTY(const QString VENDOR READ getVendor CONSTANT)
    /*! \brief The version of the library.*/
    Q_PROPERTY(const QString VERSION READ getVersion CONSTANT)
    /*! \brief The (git) revision of the library.*/
    Q_PROPERTY(const QString REVISION READ getRevision CONSTANT)
    /*! \brief The (git) changeset of the library.*/
    Q_PROPERTY(const QString CHANGESET READ getChangeset CONSTANT)

    /*! \brief The build type (release / debug of the library).*/
    Q_PROPERTY(const QString BUILD READ getBuildType CONSTANT)
    /*! \brief The type of the library (static / dynamic).*/
    Q_PROPERTY(const QString LINK READ getLinkType CONSTANT)
    /*! \brief QT Version used to build.*/
    Q_PROPERTY(const QString QT READ getQt CONSTANT)

    /*! \brief The nameof the underlying player library.*/
    Q_PROPERTY(const QString PLUGIN_NAME READ getLibName CONSTANT)
    /*! \brief The version of the underlying player library.*/
    Q_PROPERTY(const QString PLUGIN_VERSION READ getLibVersion CONSTANT)
    /*! \brief The revision of the underlying player library.*/
    Q_PROPERTY(const QString PLUGIN_REVISION READ getLibRevision CONSTANT)

    /*! \cond */
    const QString getName();
    const QString getVendor();
    const QString getVersion();
    const QString getRevision();
    const QString getChangeset();

    const QString getBuildType();
    const QString getLinkType();
    const QString getQt();

    const QString getLibName(){ return QString::fromLatin1("libvlc");}
    const QString getLibVersion();
    const QString getLibRevision();
    /*! \endcond */
};
}

#endif // DUBOPLAYER_ROOT_H

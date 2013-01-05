/*****************************************************************************
 * Copyright (c) 2012, WebItUp <contact@webitup.fr>
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

#ifndef ROXEEPLAYER_ROOT_H
#define ROXEEPLAYER_ROOT_H

#include "libroxeeplayer_global.h"
#include <QtCore/qobject.h>

/*!
\mainpage
This library is primarily meant to be used by the Roxee Webrunner.
Its purpose is to provide a clean, QT-ified, scriptable API that introduces as little extra complexity as possible over
the underyling video player library, and ideally, be API independent from that library.
Right now though, it only supports (and is meant for) libvlc (http://www.videolan.org/vlc/libvlc.html).

To compile:
- build or install libvlc (http://wiki.videolan.org/LibVLC)
- edit the vars.pri file at the root of the project so that it matches your mileage:
 - DEPDIR=# should point to wherever your lib and include folders reside (under which libtorrent can be found)
 - DESTDIR=# should point to wherever you want the library to be compiled
- qmake, then make

To use it, just create a RoxeePlayer::SimplePlayer object.
This is specifically meant to be exposed for a QWebPluginFactory.

If you want to have a QT Widget that will switch over a regular widget, use StackedPlayer.

Big fat warning: this pile of code may or may not work for you. If it does, you may send a thank you note :).
If it doesn't, you can probably:
- live with it
- ask me for help

... though neither of these is guaranteed to have any result - of course you may also fix it and possibly ask for a pull request :)


This code is distributed under the terms of the LGPL license.
*/

/*! \namespace RoxeePlayer
\brief The library namespace.
*/

namespace RoxeePlayer
{

    /*! \brief Library root object. */
    class LIBROXEEPLAYERSHARED_EXPORT Root: public QObject {
        Q_OBJECT
    public:
        /*! \brief The name of the library.*/
        Q_PROPERTY(const QString ROXEE_NAME READ getName)
        /*! \brief The name of the vendor.*/
        Q_PROPERTY(const QString ROXEE_VENDOR READ getVendor)
        /*! \brief The version of the library.*/
        Q_PROPERTY(const QString ROXEE_VERSION READ getVersion)
        /*! \brief The (git) revision of the library.*/
        Q_PROPERTY(const QString ROXEE_REVISION READ getRevision)
        /*! \brief The (git) changeset of the library.*/
        Q_PROPERTY(const QString ROXEE_CHANGESET READ getChangeset)

        /*! \brief The build type (release / debug of the library).*/
        Q_PROPERTY(const QString ROXEE_BUILD READ getBuildType)
        /*! \brief The type of the library (static / dynamic).*/
        Q_PROPERTY(const QString ROXEE_LINK READ getLinkType)
        /*! \brief QT Version used to build.*/
        Q_PROPERTY(const QString ROXEE_QT READ getQt)

        /*! \brief The nameof the underlying player library.*/
        Q_PROPERTY(const QString PLUGIN_NAME READ getLibName)
        /*! \brief The version of the underlying player library.*/
        Q_PROPERTY(const QString PLUGIN_VERSION READ getLibVersion)
        /*! \brief The revision of the underlying player library.*/
        Q_PROPERTY(const QString PLUGIN_REVISION READ getLibRevision)

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

#endif // ROXEEPLAYER_ROOT_H

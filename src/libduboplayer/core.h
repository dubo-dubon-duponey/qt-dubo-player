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

#ifndef DUBOPLAYER_CORE_H
#define DUBOPLAYER_CORE_H

#include "global.h"
#include "vlc2.h"

#include <QObject>
#include <QStringList>

namespace DuboPlayer{

/*! \brief A core object with a couple of random infos / helpers. Don't instanciate directly. Use SimplePlayer instead. */
class LIBDUBOPLAYERSHARED_EXPORT Core : public QObject
{
    Q_OBJECT
public:
    /*! \brief Should be created by passing a reference to the shadowed libvlc object. */
    explicit Core(DuboVLC * rvlc, QObject * parent = nullptr);

    /*! \brief Allows to control the UA string that will be set for http streams retrieval. */
    Q_INVOKABLE void setUserAgent(const QString &appName, const QString &appVersion);

    /*! \brief Gets the compiler used to build the underlying library */
    Q_PROPERTY(const QString compiler READ getCompiler)

    /*! \brief Gets the audio filters list*/
    Q_PROPERTY(const QStringList audioFilterList READ getAudioFilterList)
    /*! \brief Gets the video filters list*/
    Q_PROPERTY(const QStringList videoFilterList READ getVideoFilterList)

    /*! \cond */
    QString getCompiler();
    QStringList getAudioFilterList();
    QStringList getVideoFilterList();
    /*! \endcond */

signals:

public slots:

private:
    DuboVLC * vlc;

};
}

#endif // DUBOPLAYER_CORE_H

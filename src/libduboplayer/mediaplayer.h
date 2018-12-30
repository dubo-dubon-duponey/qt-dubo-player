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

#ifndef DUBOPLAYER_MEDIAPLAYER_H
#define DUBOPLAYER_MEDIAPLAYER_H

#include "global.h"

#include <QObject>
#include <QStringList>

#include "vlc2.h"

namespace DuboPlayer
{
/*! \brief A media player class, exposed through the top-level SimplePlayer. */
class LIBDUBOPLAYERSHARED_EXPORT MediaPlayer : public QObject
{
    Q_OBJECT
public:
    /*! \cond */
    explicit MediaPlayer(DuboVLC * rvlc, QObject * parent = nullptr);
    /*! \endcond */

    /*! \brief Retrieve and set the media */
    Q_PROPERTY(QString media READ media WRITE setMedia)
    /*! \brief Whether playing or not */
    Q_PROPERTY(bool isPlaying READ isPlaying)
    /*! \brief Read length */
    Q_PROPERTY(int length READ length)
    /*! \brief Retrieve and set playback time */
    Q_PROPERTY(int time READ time WRITE setTime)
    /*! \brief Retrieve and set playbakc position */
    Q_PROPERTY(float position READ position WRITE setPosition)
    /*! \brief Retrieve and set chapter */
    Q_PROPERTY(int chapter READ chapter WRITE setChapter)
    /*! \brief Read chapter count */
    Q_PROPERTY(int chapterCount READ chapterCount)

    /*! \brief Play */
    Q_INVOKABLE void play();
    /*! \brief Stop */
    Q_INVOKABLE void stop();
    /*! \brief Pause */
    Q_INVOKABLE void pause();
    /*! \brief Preliminary broadcast support */
    Q_INVOKABLE void experimental(const QString & broadcastName, const QString &path, const QString & args);

    /*! \cond */
    QString media();
    void setMedia(const QString & path);
    bool isPlaying();
    int length();
    int time();
    void setTime(const int & time);
    float position();
    void setPosition(const float & pos);
    int chapter();
    void setChapter(const int & chap);
    int chapterCount();
    /*! \endcond */



signals:

public slots:
private:
    DuboVLC * vlc;
};
}

#endif // DUBOPLAYER_MEDIAPLAYER_H

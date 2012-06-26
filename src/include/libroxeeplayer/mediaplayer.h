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

#ifndef ROXEEPLAYER_MEDIAPLAYER_H
#define ROXEEPLAYER_MEDIAPLAYER_H

#include "libroxeeplayer_global.h"

#include <QtCore/qobject.h>
#include <QtCore/qstringlist.h>

namespace RoxeePlayer
{
    /*! \brief A media player class, exposed through the top-level classes. */
    class LIBROXEEPLAYERSHARED_EXPORT MediaPlayer : public QObject
    {
        Q_OBJECT
    public:
        /*! \cond */
        explicit MediaPlayer(void * id, QObject *parent = 0);
        ~MediaPlayer();
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

//        friend class VideoControls;
//        friend class AudioControls;

        // Video controls

        /*! \brief Toggles fullscreen */
        Q_INVOKABLE void toggleFullscreen();

        /*! \brief Retrieve and set fullscreen */
        Q_PROPERTY(bool fullscreen READ fullscreen WRITE setFullscreen)

        /*! \brief Toggles key input */
        Q_INVOKABLE void setKeyInput(const bool on );
        /*! \brief Toggles mouse input */
        Q_INVOKABLE void setMouseInput(const bool on);
        /*getSize()*/
        /*! \brief Retrieves height */
        Q_PROPERTY(uint height READ height)
        /*! \brief Retrieves width */
        Q_PROPERTY(uint width READ width)

        /*cursor()*/
        /*! \brief Retrieves and sets scale */
        Q_PROPERTY(float scale READ scale WRITE setScale)

        /*! \brief Retrieves and set aspectRatio */
        Q_PROPERTY(QString aspectRatio READ aspectRatio WRITE setAspectRatio)

        /*! \brief Retrieves and set spu */
        Q_PROPERTY(int spu READ spu WRITE setSpu)
        /*! \brief Read spu count */
        Q_PROPERTY(int spuCount READ spuCount)

        /*! \brief Read spu description */
        Q_PROPERTY(QStringList spuTrackDescription READ spuTrackDescription)

        /*! \brief Set spu file */
        Q_INVOKABLE void setSubtitleFile(const QString &path);

/*        Q_PROPERTY(int spuDelay READ spuDelay WRITE setSpuDelay)
        int spuDelay();
        void setSpuDelay(const int & i);*/

//        Q_PROPERTY(QStringList titleDescription READ titleDescription)
        // QStringList* titleDescription();

        // XXX unexposed
        // QStringList* chapterDescription(int i);

        /*! \brief Retrieves and set cropping geometry */
        Q_PROPERTY(QString cropGeometry READ cropGeometry WRITE setCropGeometry)

        /*! \brief Retrieves and set teletext */
        Q_PROPERTY(int teletext READ teletext WRITE setTeletext)
//        Q_INVOKABLE void toggleTeletext();
        /*! \brief Read video track count */
        Q_PROPERTY(int videoTrackCount READ videoTrackCount)
        /*! \brief Read video tracks description */
        Q_PROPERTY(QStringList videoTrackDescription READ videoTrackDescription)
        /*! \brief Retrieve and set video track */
        Q_PROPERTY(int videoTrack READ videoTrack WRITE setVideoTrack)

        /*! \brief Take snapshot */
        Q_INVOKABLE void takeSnapshot();
        /*! \brief Toggle deinterlace mode */
        Q_INVOKABLE void setDeinterlace(const bool on);

        /*! \cond */
        void setFullscreen(const bool on);
        bool fullscreen();
        uint height();
        uint width();
        float scale();
        void setScale(const float factor);
        QString aspectRatio();
        void setAspectRatio(const QString &ar);
        int spu();
        void setSpu(uint i);
        int spuCount();
        QStringList spuTrackDescription();
        QString cropGeometry();
        void setCropGeometry(const QString &crop);
        int teletext();
        void setTeletext(const int & i);
        int videoTrackCount();
        QStringList videoTrackDescription();
        int videoTrack();
        void setVideoTrack(const int i);
        /*! \endcond */


        // AUDIO ***********************************

        /*! \brief Toggle mute */
        Q_INVOKABLE void toggleMute();
        /*! \brief Retrieve and set mute */
        Q_PROPERTY(bool mute READ mute WRITE setMute)
        /*! \brief Retrieve and set volume */
        Q_PROPERTY(int volume READ volume WRITE setVolume)
        /*! \brief Read audio tracks count */
        Q_PROPERTY(int audioTrackCount READ audioTrackCount)
        /*! \brief Retrieve and set audio track */
        Q_PROPERTY(int audioTrack READ audioTrack WRITE setAudioTrack)
        /*! \brief Retrieve audio tracks description */
        Q_PROPERTY(QStringList audioTrackDescription READ audioTrackDescription)

        /*! \cond */
        bool mute();
        void setMute(const bool status);
        int volume();
        void setVolume(const int vol);
        int audioTrackCount();
        int audioTrack();
        void setAudioTrack(const int i);
        QStringList audioTrackDescription();
        /*! \endcond */
    signals:

    public slots:

    private:

    };
}

#endif // ROXEEPLAYER_MEDIAPLAYER_H

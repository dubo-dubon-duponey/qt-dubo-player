/*****************************************************************************
 * Copyright (c) 2012, WebItUp
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

#include <QtCore/QObject>
#include <QtCore/QStringList>

namespace RoxeePlayer
{
    class LIBROXEEPLAYERSHARED_EXPORT MediaPlayer : public QObject
    {
        Q_OBJECT
    public:
        explicit MediaPlayer(void * id, QObject *parent = 0);
        ~MediaPlayer();

        Q_PROPERTY(QString media READ media WRITE setMedia)
        Q_PROPERTY(bool isPlaying READ isPlaying)
        Q_PROPERTY(int length READ length)
        Q_PROPERTY(int time READ time WRITE setTime)
        Q_PROPERTY(float position READ position WRITE setPosition)
        Q_PROPERTY(int chapter READ chapter WRITE setChapter)
        Q_PROPERTY(int chapterCount READ chapterCount)

        Q_INVOKABLE void play();
        Q_INVOKABLE void stop();
        Q_INVOKABLE void pause();


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

//        friend class VideoControls;
//        friend class AudioControls;

        // Video controls

        Q_INVOKABLE void toggleFullscreen();

        Q_PROPERTY(bool fullscreen READ fullscreen WRITE setFullscreen)
        void setFullscreen(const bool on);
        bool fullscreen();

        Q_INVOKABLE void setKeyInput(const bool on );
        Q_INVOKABLE void setMouseInput(const bool on);
        /*getSize()*/
        Q_PROPERTY(uint height READ height)
        Q_PROPERTY(uint width READ width)
        uint height();
        uint width();

        /*cursor()*/
        Q_PROPERTY(float scale READ scale WRITE setScale)
        float scale();
        void setScale(const float factor);

        Q_PROPERTY(QString aspectRatio READ aspectRatio WRITE setAspectRatio)
        QString aspectRatio();
        void setAspectRatio(const QString &ar);

        Q_PROPERTY(int spu READ spu WRITE setSpu)
        Q_PROPERTY(int spuCount READ spuCount)
        int spu();
        void setSpu(uint i);
        int spuCount();

        Q_PROPERTY(QStringList spuTrackDescription READ spuTrackDescription)
        QStringList spuTrackDescription();

        Q_INVOKABLE void setSubtitleFile(const QString &path);

/*        Q_PROPERTY(int spuDelay READ spuDelay WRITE setSpuDelay)
        int spuDelay();
        void setSpuDelay(const int & i);*/

//        Q_PROPERTY(QStringList titleDescription READ titleDescription)
        // QStringList* titleDescription();

        // XXX unexposed
        // QStringList* chapterDescription(int i);

        Q_PROPERTY(QString cropGeometry READ cropGeometry WRITE setCropGeometry)
        QString cropGeometry();
        void setCropGeometry(const QString &crop);

        Q_PROPERTY(int teletext READ teletext WRITE setTeletext)
        int teletext();
        void setTeletext(const int & i);

//        Q_INVOKABLE void toggleTeletext();

        Q_PROPERTY(int videoTrackCount READ videoTrackCount)
        int videoTrackCount();

        Q_PROPERTY(QStringList videoTrackDescription READ videoTrackDescription)
        QStringList videoTrackDescription();

        Q_PROPERTY(int videoTrack READ videoTrack WRITE setVideoTrack)
        int videoTrack();
        void setVideoTrack(const int i);
        Q_INVOKABLE void takeSnapshot();
        Q_INVOKABLE void setDeinterlace(const bool on);



        // AUDIO ***********************************

        Q_INVOKABLE void toggleMute();

        Q_PROPERTY(bool mute READ mute WRITE setMute)
        bool mute();
        void setMute(const bool status);
        Q_PROPERTY(int volume READ volume WRITE setVolume)
        int volume();
        void setVolume(const int vol);

        Q_PROPERTY(int audioTrackCount READ audioTrackCount)
        int audioTrackCount();
        Q_PROPERTY(int audioTrack READ audioTrack WRITE setAudioTrack)
        int audioTrack();
        void setAudioTrack(const int i);

        Q_PROPERTY(QStringList audioTrackDescription READ audioTrackDescription)
        QStringList audioTrackDescription();

    signals:

    public slots:

    private:

    };
}

#endif // ROXEEPLAYER_MEDIAPLAYER_H

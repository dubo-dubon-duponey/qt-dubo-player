/*****************************************************************************
 * Copyright (c) 2018, Dubo Dubon Duponey <dubodubonduponey@gmail.com>
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

#ifndef DUBOPLAYER_AUDIOCONTROLS_H
#define DUBOPLAYER_AUDIOCONTROLS_H

#include "libduboplayer_global.h"

#include <QObject>
#include <QStringList>

#include "libduboplayer/vlc2.h"

namespace DuboPlayer
{
/*! \brief Audio controllers, exposed through the top-level SimplePlayer */
class LIBDUBOPLAYERSHARED_EXPORT AudioControls : public QObject
{
    Q_OBJECT
public:
    /*! \cond */
    explicit AudioControls(DuboVLC * rvlc, QObject *parent = 0);
    /*! \endcond */

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


    /*! \brief Retrieve output list */
    Q_INVOKABLE QStringList outputList()
    {
        return vlc->audio_output_list_get();
    }

    /*! \brief Retrieve output devices list */
    Q_INVOKABLE QStringList outputDeviceList(const QString & outd)
    {
        return vlc->audio_output_device_list_get(outd);
    }

    /*! \brief Allow to set output */
    Q_INVOKABLE void setOutput(const QString & outd)
    {
        vlc->audio_output_set(outd);
    }

    /*! \brief Allow to set output device */
    Q_INVOKABLE void setOutputDevice(const QString & outd)
    {
        vlc->audio_output_set(outd);
    }

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
    DuboVLC * vlc;
};
}


#endif // DUBOPLAYER_AUDIOCONTROLS_H

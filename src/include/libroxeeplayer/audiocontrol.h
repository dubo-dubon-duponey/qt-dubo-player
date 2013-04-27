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

#ifndef ROXEEPLAYER_AUDIOCONTROLS_H
#define ROXEEPLAYER_AUDIOCONTROLS_H

#include "libroxeeplayer_global.h"

#include <QObject>
#include <QStringList>

#include "vlc2.h"

namespace RoxeePlayer
{
    /*! \brief Audio controllers, exposed through the top-level classes */
    class LIBROXEEPLAYERSHARED_EXPORT AudioControls : public QObject
    {
        Q_OBJECT
    public:
        /*! \cond */
        explicit AudioControls(RoxeeVLC * rvlc, QObject *parent = 0);
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
        RoxeeVLC * vlc;
    };
}

#endif // ROXEEPLAYER_AUDIOCONTROLS_H

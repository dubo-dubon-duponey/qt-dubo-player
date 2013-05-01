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

#include "libroxeeplayer/audiocontrol.h"

/*! \cond */

using namespace RoxeePlayer;

namespace RoxeePlayer{

AudioControls::AudioControls(RoxeeVLC * rvlc, QObject *parent) :
    QObject(parent)
{
    this->vlc = rvlc;
}

void AudioControls::toggleMute()
{
    vlc->audio_toggle_mute();
}

bool AudioControls::mute()
{
    return vlc->audio_get_mute();
}

void AudioControls::setMute(const bool status)
{
    vlc->audio_set_mute(status);
}

int AudioControls::volume()
{
    return vlc->audio_get_volume();
}

void AudioControls::setVolume(const int vol)
{
    vlc->audio_set_volume(vol);
}

int AudioControls::audioTrackCount()
{
    return vlc->audio_get_track_count();
}

QStringList AudioControls::audioTrackDescription()
{
    return vlc->audio_get_track_description();
}

int AudioControls::audioTrack()
{
    return vlc->audio_get_track();
}

void AudioControls::setAudioTrack(const int i)
{
    vlc->audio_set_track(i);
}

}

/*! \endcond */

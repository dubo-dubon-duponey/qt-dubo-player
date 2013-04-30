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

#include "libroxeeplayer/mediaplayer.h"
#include <QtCore/qdebug.h>

/*! \cond */

using namespace RoxeePlayer;

namespace RoxeePlayer{
MediaPlayer::MediaPlayer(RoxeeVLC * rvlc, QObject *parent) :
    QObject(parent)
{
    this->vlc = rvlc;
}

MediaPlayer::~MediaPlayer()
{
    qDebug() << "**** DESTRUCTION *** MediaPlayer";
}

/*
    // XXX
    // https://bugreports.qt.nokia.com//browse/QTBUG-16274


//void MediaPlayer::setEventHandler(const QString &path)
//{-> SHOULD EMIT / CONNECT
//    libvlc_event_manager_t * p_event_manager = libvlc_media_player_event_manager(LRPCoreInstance::instance()->getPlayer());

//    int libvlc_event_attach( p_event_manager, libvlc_event_type_t i_event_type, libvlc_callback_t f_callback, void * user_data);
//}
*/


void MediaPlayer::setMedia(const QString &path)
{
    QUrl * u = new QUrl(path);
    if(u->scheme() == "file")
        u->setScheme("");
    qDebug() << "Setting new url";
    qDebug() << u->toString();
    vlc->media_player_set_media(u->toString());
}

QString MediaPlayer::media()
{
    return vlc->media_player_get_media();
}

void MediaPlayer::play()
{
    vlc->media_player_play();
}

void MediaPlayer::stop()
{
    vlc->media_player_stop();
}

void MediaPlayer::pause()
{
    vlc->media_player_pause();
}

bool MediaPlayer::isPlaying()
{
    return vlc->media_player_is_playing();
}

int MediaPlayer::length()
{
    return vlc->media_player_get_length();
}

int MediaPlayer::time()
{
    return vlc->media_player_get_time();
}

void MediaPlayer::setTime(const int & time)
{
    vlc->media_player_set_time(time);
}

float MediaPlayer::position()
{
    return vlc->media_player_get_position();
}

void MediaPlayer::setPosition(const float & pos)
{
    vlc->media_player_set_position(pos);
}

int MediaPlayer::chapter()
{
    return vlc->media_player_get_chapter();
}

int MediaPlayer::chapterCount()
{
    return vlc->media_player_get_chapter_count();
}

void MediaPlayer::setChapter(const int & chap)
{
    vlc->media_player_set_chapter(chap);
}

/*
QtVlcAudioControls * MediaPlayer::getAudioControls()
{
}

QtVlcVideoControls * MediaPlayer::getVideoControls()
{

}
*/

}

/*! \endcond */

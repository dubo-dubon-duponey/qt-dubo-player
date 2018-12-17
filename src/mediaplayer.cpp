/*****************************************************************************
 * Copyright (c) 2018, Dubo Dubon Duponey <dubodubonduponey+github@pm.me>
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

#include "libduboplayer/mediaplayer.h"
#include <QUrl>

/*! \cond */

using namespace DuboPlayer;
// XXX
// https://bugreports.qt.nokia.com//browse/QTBUG-16274

namespace DuboPlayer{
MediaPlayer::MediaPlayer(DuboVLC * rvlc, QObject *parent) :
    QObject(parent)
{
    this->vlc = rvlc;
}

// XXX experimental
void MediaPlayer::experimental(const QString & broadcastName, const QString &path, const QString & args)
{
    vlc->vlm_add_broadcast(broadcastName, path, args);
    vlc->vlm_play_media(broadcastName);
}

void MediaPlayer::setMedia(const QString &path)
{
//    QUrl * u = new QUrl(path);
// XXX likely to be changed with vlc 2.1
//    if(u->scheme() == "file")
//        u->setScheme("");
//    vlc->media_player_set_media(u->toString());
    vlc->media_player_set_media(path);
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


}

/*! \endcond */

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

#include "libroxeeplayer/videocontrol.h"
#include "libroxeeplayer/vlc2.h"

#include <qDebug>

/*! \cond */

using namespace RoxeePlayer;

namespace RoxeePlayer{

VideoControls::VideoControls(RoxeeVLC * rvlc, QObject *parent) :
    QObject(parent)
{
    vlc = rvlc;
}



void VideoControls::toggleFullscreen()
{
    vlc->toggle_fullscreen();
}


void VideoControls::setFullscreen(const bool on)
{
    vlc->set_fullscreen(on);
}

bool VideoControls::fullscreen()
{
    return vlc->get_fullscreen();
}

void VideoControls::setKeyInput(const bool on )
{
    return vlc->video_set_key_input(on);
}

void VideoControls::setMouseInput(const bool on)
{
    return vlc->video_set_mouse_input(on);
}

uint VideoControls::height()
{
    int t = vlc->video_get_track();
    // Otherwise will crash
    if(t == -1)
        return 0;
    return vlc->video_get_height(t);
}

uint VideoControls::width()
{
    int t = vlc->video_get_track();
    // Otherwise will crash
    if(t == -1)
        return 0;
    return vlc->video_get_width(t);
}

float VideoControls::scale()
{
    return vlc->video_get_scale();
}

void VideoControls::setScale(const float factor)
{
    vlc->video_set_scale(factor);
}


QString VideoControls::aspectRatio()
{
    return vlc->video_get_aspect_ratio();
}

void VideoControls::setAspectRatio(const QString &ar)
{
    vlc->video_set_aspect_ratio(ar);
}

int VideoControls::spu()
{
    return vlc->video_get_spu();
}

int VideoControls::spuCount()
{
    return vlc->video_get_spu_count();
}

QStringList VideoControls::spuTrackDescription()
{
    return vlc->video_get_spu_description();
}


void VideoControls::setSpu(uint i)
{
    vlc->video_set_spu(i);
}

void VideoControls::setSubtitleFile(const QString &path)
{
    vlc->video_set_subtitle_file(path);
}
/*
int VideoControls::spuDelay()
{
    return libvlc_video_get_spu_delay(LRPCoreInstance::instance()->getPlayer());
}

void VideoControls::setSpuDelay(const int & i)
{
    libvlc_video_set_spu_delay(LRPCoreInstance::instance()->getPlayer(), i);
}
*/

/*
QStringList* VideoControls::titleDescription()
{
    return new QStringList();
//LIBVLC_API
//libvlc_track_description_t * 	libvlc_video_get_title_description (libvlc_media_player_t *LRPCoreInstance::instance()->getPlayer())
//        Get the description of available titles.
//    libvlc_track_description_t * t = libvlc_video_get_description(LRPCoreInstance::instance()->getPlayer());
}

QStringList* VideoControls::chapterDescription(int i)
{
//LIBVLC_API
//libvlc_track_description_t * 	libvlc_video_get_chapter_description (libvlc_media_player_t *LRPCoreInstance::instance()->getPlayer(), int i_title)
//        Get the description of available chapters for specific title.
    libvlc_track_description_t * t = libvlc_video_get_chapter_description (LRPCoreInstance::instance()->getPlayer(), i);
    return new QStringList();
}
*/

QString VideoControls::cropGeometry()
{
    return vlc->video_get_crop_geometry();
}

void VideoControls::setCropGeometry(const QString &crop)
{
    vlc->video_set_crop_geometry(crop);
}

int VideoControls::teletext()
{
    return vlc->video_get_teletext();
}

void VideoControls::setTeletext(const int & i)
{
    vlc->video_set_teletext(i);
}

void VideoControls::toggleTeletext()
{
    vlc->toggle_teletext();
}

int VideoControls::videoTrackCount()
{
    return vlc->video_get_track_count();
}

QStringList VideoControls::videoTrackDescription()
{
    return vlc->video_get_track_description();
}


int VideoControls::videoTrack()
{
    return vlc->video_get_track();
}

void VideoControls::setVideoTrack(const int i)
{
    vlc->video_set_track(i);
}

void VideoControls::takeSnapshot(const int i, const QString & id)
{
    QDir wl = QDir(QStandardPaths::writableLocation(QStandardPaths::CacheLocation));
    wl.cd(QString::fromLatin1("snapshots"));
    // XXX check other uses of toLocal8bit
//    const char *psz_filepath = (wl.absoluteFilePath(QString::fromLatin1("shot.png"))).toStdString().c_str();

    vlc->video_take_snapshot(i, wl.absoluteFilePath(QString(id).append(QString::fromLatin1("-shot.png"))));
    //    const char *psz_filepath =

}

void VideoControls::setDeinterlace(const bool on)
{
    qDebug() << "Setting deinterlace to";
    qDebug() << on;
}

}

/*! \endcond */

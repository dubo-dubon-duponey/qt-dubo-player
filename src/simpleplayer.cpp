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

#include "libduboplayer/simpleplayer.h"
#include <QStackedLayout>
/*! \cond */

namespace DuboPlayer{

SimplePlayer::SimplePlayer(QWidget *parent) :
    QWidget(parent), ooWidget(nullptr)
{
    QStackedLayout * sl = new QStackedLayout();
    this->setLayout(sl);

    DuboVLC * rvlc = new DuboVLC(this);
    rvlc->media_player_new();

    this->setAccessibleName("video player");

    QWidget * container = new QWidget(this);
    this->layout()->addWidget(container);
    rvlc->media_player_set_window((void *) container->winId());

    connect(rvlc, SIGNAL(notify(QString)), this, SLOT(slotNotify(QString)));

    _rp_core = new DuboPlayer::Core(rvlc, this);
    _rp_mediaplayer = new DuboPlayer::MediaPlayer(rvlc, this);
    _rp_audio = new DuboPlayer::AudioControls(rvlc, this);
    _rp_video = new DuboPlayer::VideoControls(rvlc, this);
}

void SimplePlayer::slotNotify(const QString & seg)
{
    emit notify(seg);
}

DuboPlayer::Root * SimplePlayer::root()
{
    if(!_rp_root){
        _rp_root = new DuboPlayer::Root();
    }
    return _rp_root;
}

DuboPlayer::Core * SimplePlayer::core()
{
    return _rp_core;
}

DuboPlayer::MediaPlayer * SimplePlayer::mediaPlayer()
{
    return _rp_mediaplayer;
}

DuboPlayer::VideoControls * SimplePlayer::videoControls()
{
    return _rp_video;
}

DuboPlayer::AudioControls * SimplePlayer::audioControls()
{
    return _rp_audio;
}

}
/*! \endcond */

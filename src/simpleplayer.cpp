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

#include "libroxeeplayer/simpleplayer.h"

#include <QBoxLayout>
#include <QDebug>

/*! \cond */

namespace RoxeePlayer{

SimplePlayer::SimplePlayer(QWidget *parent) :
    QWidget(parent)
{
    qDebug() << "     +++ [Lib] {Player}: single player constructor";
    setAttribute(Qt::WA_NativeWindow, true);

    QWidget * videoWidget = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(videoWidget);
    this->setLayout(layout);

    RoxeeVLC * rvlc = new RoxeeVLC(this);
    rvlc->media_player_new();
    rvlc->media_player_set_window((void *) videoWidget->winId());

    connect(rvlc, SIGNAL(notify(QString)), this, SLOT(slotNotify(QString)));

    _rp_core = new RoxeePlayer::Core(rvlc, this);
    _rp_mediaplayer = new RoxeePlayer::MediaPlayer(rvlc, this);
    _rp_audio = new RoxeePlayer::AudioControls(rvlc, this);
    _rp_video = new RoxeePlayer::VideoControls(rvlc, this);
}

SimplePlayer::~SimplePlayer()
{
    qDebug() << "************************************ DESTRUCTION *****************************";
}


void SimplePlayer::slotNotify(const QString & seg)
{
    emit notify(seg);
}

RoxeePlayer::Root * SimplePlayer::root()
{
    if(!_rp_root){
        _rp_root = new RoxeePlayer::Root();
    }
    return _rp_root;
}

RoxeePlayer::Core * SimplePlayer::core()
{
    return _rp_core;
}

RoxeePlayer::MediaPlayer * SimplePlayer::mediaPlayer()
{
    return _rp_mediaplayer;
}

//RoxeePlayer::Aud * SimplePlayer::mediaPlayer()
//{
//    return _rp_mediaplayer;
//}


//RoxeePlayer::MediaPlayer * SimplePlayer::mediaPlayer()
//{
//    return _rp_mediaplayer;
//}



}
/*! \endcond */

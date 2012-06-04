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

#include "simpleplayer.h"

#include <QtGui/QVBoxLayout>
#include <QtGui/QStackedLayout>
#include <QtCore/QDebug>

/*! \cond */

namespace RoxeePlayer{

SimplePlayer::SimplePlayer(QWidget *parent) :
    QWidget(parent)
{
    setAttribute(Qt::WA_NativeWindow, true);

    QWidget * videoWidget = new QWidget;
        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(videoWidget);
        this->setLayout(layout);

        _rp_mediaplayer = new RoxeePlayer::MediaPlayer((void *) videoWidget->winId());

//    _vp = new RoxeePlayer::MediaPlayer((void *) this->winId());


    //    videoWidget->setAutoFillBackground( true );
//    QPalette plt = palette();
//    plt.setColor( QPalette::Window, Qt::black );
//    videoWidget->setPalette( plt );

//    QVBoxLayout *layout2 = new QVBoxLayout;





    // (void *) static_cast< QtVlcWidget* >(this)->id(), this);

}

SimplePlayer::~SimplePlayer()
{
    qDebug() << " [M] VLC: destructor";
//    QObject::~QObject();
}

RoxeePlayer::Root * SimplePlayer::root()
{
    qDebug() << " [M] VLC: root getter";
    if(!_rp_root){
        _rp_root = new RoxeePlayer::Root();
    }
    return _rp_root;
}

RoxeePlayer::Core * SimplePlayer::core()
{
    qDebug() << " [M] VLC: core getter";
    return RoxeePlayer::Core::instance();
}

RoxeePlayer::MediaPlayer * SimplePlayer::mediaPlayer()
{
    qDebug() << " [M] VLC: media player getter";
    return _rp_mediaplayer;
}

}
/*! \endcond */

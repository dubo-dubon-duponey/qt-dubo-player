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

#ifndef ROXEEPLAYER_SIMPLEPLAYER_H
#define ROXEEPLAYER_SIMPLEPLAYER_H

#include "libroxeeplayer_global.h"

#include <QtCore/QObject>
#include <QtGui/QWidget>

#include "root.h"
#include "core.h"
#include "mediaplayer.h"

//using namespace RoxeePlayer;

namespace RoxeePlayer{

/*! \brief. One of the top-level user classes.

Provides with a simple QWidget player.
Useful as-is for a QWebPlugin.
*/

class LIBROXEEPLAYERSHARED_EXPORT SimplePlayer : public QWidget
{
    Q_OBJECT
public:
    /*! \brief Constructor */
    explicit SimplePlayer(QWidget *parent = 0);// const QString & appPath,
    /*! \cond */
    ~SimplePlayer();
    /*! \endcond */

    /*! \brief Get a reference to the library Root object. */
    RoxeePlayer::Root * root();
    /*! \brief Get a reference to the player Core object. */
    RoxeePlayer::Core * core();
    /*! \brief Get a reference to the media player itself. */
    RoxeePlayer::MediaPlayer * mediaPlayer();

signals:

public slots:

private:
    RoxeePlayer::Root * _rp_root;
    RoxeePlayer::MediaPlayer * _rp_mediaplayer;

};

}

#endif // ROXEEPLAYER_SIMPLEPLAYER_H

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

#ifndef ROXEEPLAYER_STACKEDPLAYER_H
#define ROXEEPLAYER_STACKEDPLAYER_H

#include "libroxeeplayer_global.h"

#include <QObject>
#include <QStackedLayout>

#include "root.h"
#include "core.h"
#include "mediaplayer.h"

namespace RoxeePlayer{

    /*! \brief. One of the top-level user classes.

    Provides with a controller that will overlay/hide a player widget inside a stacked layout.
    */
    class LIBROXEEPLAYERSHARED_EXPORT StackedPlayer : public QObject
    {
        Q_OBJECT
    public:
        /*! \brief Constructor.

        Pass a stacked layout and a parent QObject. */
        explicit StackedPlayer(QStackedLayout * layout, QObject *parent = 0);

        /*! \cond */
        ~StackedPlayer();
        /*! \endcond */

        /*! \brief Start playing a file located at path. */
        Q_INVOKABLE void start(const QString & path);
        /*! \brief Stop playing, and remove the widget. */
        Q_INVOKABLE void stop();
        /*! \brief Sets the size and position of the widget */
        Q_INVOKABLE void setGeometry(const int & x, const int & y, const int & w, const int & h);

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

        QWidget * _video_widget;
        QStackedLayout * _outer_layout;
        QWidget * _shifted_widget;
    };
}

#endif // ROXEEPLAYER_STACKEDPLAYER_H

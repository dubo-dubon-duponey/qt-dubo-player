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

#ifndef ROXEEPLAYER_SIMPLEPLAYER_H
#define ROXEEPLAYER_SIMPLEPLAYER_H

#include "libroxeeplayer_global.h"

#include <QWidget>
#include <QApplication>

#include "root.h"
#include "core.h"
#include "mediaplayer.h"
#include "audiocontrol.h"
#include "videocontrol.h"

namespace RoxeePlayer{

/*! \brief. The top-level class.

Provides with a simple QWidget player.
Used as-is inside the QWebPluginFactory.
*/

class LIBROXEEPLAYERSHARED_EXPORT SimplePlayer : public QWidget
{
    Q_OBJECT
public:
    /*! \brief Constructor */
    explicit SimplePlayer(QWidget *parent = 0);

    /*! \brief Access the media controller of this player */
    Q_PROPERTY(QVariant media READ getMediaPlayer)
    /*! \brief Access the audio controller of this player */
    Q_PROPERTY(QVariant audio READ getAudio)
    /*! \brief Access the video controller of this player */
    Q_PROPERTY(QVariant video READ getVideo)
    /*! \brief Access the core property of the library through this player */
    Q_PROPERTY(QVariant core READ getCore)
    /*! \brief Access the root property of the library through this player */
    Q_PROPERTY(QVariant root READ getRoot)

    /*! \cond */
    Q_PROPERTY(bool crashing READ crashing)
    Q_PROPERTY(QStringList underTheInfluence READ underTheInfluence)

    QVariant getMediaPlayer()
    {
        QVariant var = QVariant::fromValue((QObject*) _rp_mediaplayer);
        return var;
    }

    QVariant getAudio()
    {
        QVariant var = QVariant::fromValue((QObject*) _rp_audio);
        return var;
    }

    QVariant getVideo()
    {
        QVariant var = QVariant::fromValue((QObject*) _rp_video);
        return var;
    }

    QVariant getCore()
    {
        QVariant var = QVariant::fromValue((QObject*) _rp_core);
        return var;
    }

    QVariant getRoot()
    {
        QVariant var = QVariant::fromValue((QObject*) this->root());
        return var;
    }

    bool crashing()
    {
        // Windows...
        #if defined(Q_OS_WIN)
            return true;
        #else
            return false;
        #endif
    }

    QStringList underTheInfluence()
    {
        QStringList l = QStringList();
        QPoint pos = QCursor::pos();
        QWidget * under = qApp->widgetAt(pos);
        if(under && under->accessibleName() == "video player"){
            l.append(QString::number(pos.x()));
            l.append(QString::number(pos.y()));
        }
        return l;
    }
    /*! \endcond */

    /*! \brief Get a reference to the library Root object. */
    RoxeePlayer::Root * root();
    /*! \brief Get a reference to the player Core object. */
    RoxeePlayer::Core * core();
    /*! \brief Get a reference to the media player itself. */
    RoxeePlayer::MediaPlayer * mediaPlayer();
    /*! \brief Get a reference to the video controls. */
    RoxeePlayer::VideoControls * videoControls();
    /*! \brief Get a reference to the audio controls. */
    RoxeePlayer::AudioControls * audioControls();

signals:
    /*! \brief lbvlc events are piped through this. */
    void notify(const QString & seg);

public slots:
    void slotNotify(const QString & seg);

private:
    RoxeePlayer::Root * _rp_root;
    RoxeePlayer::Core * _rp_core;
    RoxeePlayer::MediaPlayer * _rp_mediaplayer;
    RoxeePlayer::AudioControls * _rp_audio;
    RoxeePlayer::VideoControls * _rp_video;


};

}

#endif // ROXEEPLAYER_SIMPLEPLAYER_H

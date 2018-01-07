/*****************************************************************************
 * Copyright (c) 2018, Dubo Dubon Duponey <dubodubonduponey@gmail.com>
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

#ifndef DUBOPLAYER_SIMPLEPLAYER_H
#define DUBOPLAYER_SIMPLEPLAYER_H

#include "libduboplayer_global.h"

#include <QWidget>
#include <QLayout>
#include <QStackedLayout>
#include <QApplication>
#include <QMoveEvent>

#include "root.h"
#include "core.h"
#include "mediaplayer.h"
#include "audiocontrol.h"
#include "videocontrol.h"

namespace DuboPlayer{

/*! \brief. The top-level class.

Provides with a simple QWidget player.
Used as-is inside the QWebPluginFactory.
*/

class LIBDUBOPLAYERSHARED_EXPORT SimplePlayer : public QWidget
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
    DuboPlayer::Root * root();
    /*! \brief Get a reference to the player Core object. */
    DuboPlayer::Core * core();
    /*! \brief Get a reference to the media player itself. */
    DuboPlayer::MediaPlayer * mediaPlayer();
    /*! \brief Get a reference to the video controls. */
    DuboPlayer::VideoControls * videoControls();
    /*! \brief Get a reference to the audio controls. */
    DuboPlayer::AudioControls * audioControls();


    /*! \cond */
    void setOverlayWidget(QWidget *widget)
    {
        ooWidget = widget;
        ((QStackedLayout *) this->layout())->insertWidget(0, ooWidget);
        ooWidget->show();
    }
    /*! \endcond */


signals:
    /*! \brief lbvlc events are piped through this. */
    void notify(const QString & seg);

public slots:
    /*! \brief public slot for notifications */
    void slotNotify(const QString & seg);

private:
    DuboPlayer::Root * _rp_root;
    DuboPlayer::Core * _rp_core;
    DuboPlayer::MediaPlayer * _rp_mediaplayer;
    DuboPlayer::AudioControls * _rp_audio;
    DuboPlayer::VideoControls * _rp_video;

    QWidget * ooWidget;


protected:
    /*! \cond */
    void moveEvent(QMoveEvent *event)
    {
//        if (ooWidget)
//            ooWidget->move(this->window()->pos());
        if (ooWidget)
            ooWidget->move(event->pos());
    }

    void resizeEvent(QResizeEvent *event)
    {
        if (ooWidget)
            ooWidget->resize(event->size());
    }

    void hideEvent(QHideEvent *)
    {
        if (ooWidget)
            ooWidget->hide();
    }

    void showEvent(QShowEvent *)
    {
        if (ooWidget)
            ooWidget->show();
    }

    void closeEvent(QCloseEvent *)
    {
        if (ooWidget)
            ooWidget->close();
    }
    /*! \endcond */

};

}

#endif // DUBOPLAYER_SIMPLEPLAYER_H

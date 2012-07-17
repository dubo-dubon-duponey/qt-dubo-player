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

#include "stackedplayer.h"

#include <QtCore/qdebug.h>
#include <QtCore/qrect.h>
#include <QtGui/qwidget.h>

/*! \cond */

namespace RoxeePlayer{

StackedPlayer::StackedPlayer(QStackedLayout * layout, QObject *parent) :
    QObject(parent), _rp_root(0)
{
    qDebug() << "     +++ [Lib] {Player}: stacked player constructor";
    _outer_layout = layout;
    _shifted_widget = 0;
    _video_widget = new QWidget;
    QWidget * videoWidget = new QWidget;
    QHBoxLayout * inlayout = new QHBoxLayout;
    inlayout->addWidget(videoWidget);
    _video_widget->setLayout(inlayout);
    // Enable mouse tracking in case the parent widget wants to do something with the mouse
    videoWidget->setMouseTracking(true);
    _video_widget->setMouseTracking(true);

    _rp_mediaplayer = new RoxeePlayer::MediaPlayer((void *) videoWidget->winId());
}

StackedPlayer::~StackedPlayer()
{
    qDebug() << "     --- [Lib] {Player}: stacked player destructor";
}

RoxeePlayer::Root * StackedPlayer::root()
{
    if(!_rp_root){
        _rp_root = new RoxeePlayer::Root();
    }
    return _rp_root;
}

RoxeePlayer::Core * StackedPlayer::core()
{
    return RoxeePlayer::Core::instance();
}

RoxeePlayer::MediaPlayer * StackedPlayer::mediaPlayer()
{
    return _rp_mediaplayer;
}

void StackedPlayer::start(const QString & path)
{
    qDebug() << "     *** [Lib] {Player}: stacked player start" << path;
    //    _mp->stop();
    //    _video_widget->show();

    if(_shifted_widget)
        return;
    _outer_layout->addWidget( _video_widget );
    _rp_mediaplayer->setMedia(path);
    _rp_mediaplayer->play();
    _shifted_widget = _outer_layout->currentWidget();
    _outer_layout->setCurrentWidget(_video_widget);
}

void StackedPlayer::stop()
{
    qDebug() << "     *** [Lib] {Player}: stacked player stop";
    if(!_shifted_widget)
        return;
    _rp_mediaplayer->stop();
    _outer_layout->removeWidget( _video_widget );
    if(_shifted_widget){
        _outer_layout->setCurrentWidget(_shifted_widget);
        _shifted_widget = 0;
    }
}

void StackedPlayer::setGeometry(const int & x, const int & y, const int & w, const int & h)
{
    qDebug() << "     *** [Lib] {Player}: stacked player set geometry";
    _video_widget->setGeometry(x, y, w, h);
}

}
/*! \endcond */

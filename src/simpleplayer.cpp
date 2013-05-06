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
#include <QStackedLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDebug>

#include <QGraphicsWidget>
//#include <stupidwidget.h>

/*! \cond */

namespace RoxeePlayer{

SimplePlayer::SimplePlayer(QWidget *parent) :
    QWidget(parent)// , trailh(0), trailw(0)
{
    RoxeeVLC * rvlc = new RoxeeVLC(this);
    rvlc->media_player_new();





    qDebug() << " [RoxeeLibVLC] {Player}: single player constructor";

//    QWidget * videoWrapperWidget = new QWidget(this);
//    videoWidget = new QWidget(videoWrapperWidget);
//    videoWrapperWidget->setFixedHeight(100);
//    videoWrapperWidget->setFixedWidth(100);

//    videoWrapperWidget->setLayout(new QVBoxLayout());
////    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
//    videoWrapperWidget->layout()->setSpacing(0);
//    videoWrapperWidget->layout()->setContentsMargins(0, 0, 0, 0);
//    videoWrapperWidget->layout()->addWidget(videoWidget);

//    this->setLayout(new QVBoxLayout());
////    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
//    this->layout()->setSpacing(0);
//    this->layout()->setContentsMargins(0, 0, 0, 0);
//    this->layout()->addWidget(videoWrapperWidget);


//    rvlc->media_player_set_window((void *) videoWidget->winId());
////    rvlc->media_player_set_window((void *) this->winId());





//    QWidget * videoWidget = new QWidget(this);

//    this->setLayout(new QVBoxLayout());
//    this->layout()->setSpacing(0);
//    this->layout()->setContentsMargins(0, 0, 0, 0);
//    this->layout()->addWidget(videoWidget);

//    rvlc->media_player_set_window((void *) videoWidget->winId());
    rvlc->media_player_set_window((void *) this->winId());

    connect(rvlc, SIGNAL(notify(QString)), this, SLOT(slotNotify(QString)));

    _rp_core = new RoxeePlayer::Core(rvlc, this);
    _rp_mediaplayer = new RoxeePlayer::MediaPlayer(rvlc, this);
    _rp_audio = new RoxeePlayer::AudioControls(rvlc, this);
    _rp_video = new RoxeePlayer::VideoControls(rvlc, this);

    //    setAttribute(Qt::WA_PaintOnScreen, true);
//    setAttribute(Qt::WA_NativeWindow, true);
//    setAttribute(Qt::WA_DontCreateNativeAncestors, true);

//    videoWidget->setUpdatesEnabled(false);

//    inVideoWidget->layout()->addWidget(videoWidget);

//    inVideoWidget->setAttribute(Qt::WA_PaintOnScreen, true);
//    inVideoWidget->setAttribute(Qt::WA_NativeWindow, true);
//    inVideoWidget->setAttribute(Qt::WA_DontCreateNativeAncestors, true);


//    QGridLayout  *layout = new QGridLayout(parent);

//    videoWidget->installEventFilter(this);
////    inVideoWidget->installEventFilter(this);
//    installEventFilter(this);


//    videoWidget->setLayout(new QVBoxLayout());
//    videoWidget->layout()->setSpacing(0);
//    videoWidget->layout()->setContentsMargins(0, 0, 0, 0);
//    videoWidget->layout()->addWidget(inVideoWidget);

}

//SimplePlayer::~SimplePlayer()
//{
//    qDebug() << "************************************ DESTRUCTION *****************************";
//}



//void SimplePlayer::hackSize(int w, int h)
//{
//    this->setFixedHeight(h);
//    this->setFixedWidth(w);
//    this->repaint();
//    this->update();
//    videoWidget->repaint();
//    videoWidget->update();
//}


void SimplePlayer::slotNotify(const QString & seg)
{
//    int h = _rp_video->height();
//    int w = _rp_video->width();
//    if((h != 0) && (videoWidget->height() != trailh)){
//        qDebug() << "Container" << trailh << trailw;
//        qDebug() << "Current video" << videoWidget->height() << videoWidget->width();
//        qDebug() << "VLC video" << h << w;

//        int ref = trailh;
//        if(!ref)
//            ref = h;
//        videoWidget->setFixedHeight(ref);
//        videoWidget->setFixedWidth(w / h * ref);
////        qDebug() << "Setting size to " << h << w << ref << (w / h * ref) << videoWidget->height() << videoWidget->width();
//    }
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

//void SimplePlayer::resizeEvent(QResizeEvent * event)
//{
//    qDebug() << "RESIZE HAPPENED" << this->height() << this->width();
////    trailh = this->height();
////    trailw = this->width();
//    event->accept();
////        event->ignore();
//}


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

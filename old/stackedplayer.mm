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
#include <QEvent>
#include <QStackedLayout>

#include <AppKit/NSApplication.h>
#include <AppKit/NSWindow.h>
#include <videowidget.h>
/*! \cond */

namespace RoxeePlayer{

StackedPlayer::StackedPlayer(QStackedLayout * layout, QObject *parent) :
    QObject(parent), _rp_root(0), timer(0)
{
    qDebug() << "     +++ [Lib] {Player}: stacked player constructor";
    _outer_layout = layout;
    _shifted_widget = 0;
    _video_widget = new QWidget;
    _inner_video_widget = new VideoWidget;
//    QHBoxLayout * inlayout = new QHBoxLayout;
    QStackedLayout * inlayout = new QStackedLayout;

//    VideoWidget * toto = new VideoWidget();
//    toto->setAttribute(Qt::WA_NativeWindow, true);
//    toto->setStyleSheet(QString::fromAscii("background-color: transparent !important;border: 10px solid blue;"));
//    toto->setAttribute(Qt::WA_NoSystemBackground, true);
//    toto->setAttribute(Qt::WA_TranslucentBackground, true);
//    toto->setAttribute(Qt::WA_NoBackground, true);
//    toto->show();

    inlayout->addWidget(_inner_video_widget);
//    inlayout->addWidget(toto);
    _video_widget->setLayout(inlayout);
    // Enable mouse tracking in case the parent widget wants to do something with the mouse
    _inner_video_widget->setMouseTracking(true);
    _video_widget->setMouseTracking(true);
    hack = (void *) _inner_video_widget->winId();
    _rp_mediaplayer = new RoxeePlayer::MediaPlayer(0);// (void *) _inner_video_widget->winId());

//    _video_widget->installEventFilter(this);
    _inner_video_widget->installEventFilter(this);
    _inner_video_widget->setStyleSheet("border: 10px solid red");
//    _inner_video_widget->grabKeyboard();

    // SHIT SHIT SHIT
//    _video_widget->setAttribute(Qt::WA_Disabled, true);
//    videoWidget->setAttribute(Qt::WA_Disabled, true);

//    _rp_mediaplayer = new RoxeePlayer::MediaPlayer((void *) videoWidget->winId());
//    _outer_layout->addWidget( _video_widget );

//    _outer_layout->addWidget( _video_widget );

//    QWidget * maskTheShit = new QWidget();
//    maskTheShit->setAttribute(Qt::WA_NativeWindow, true);
////    maskTheShit->setAttribute(Qt::WA_NoSystemBackground, true);
//    maskTheShit->setAttribute(Qt::WA_TranslucentBackground, true);
//    maskTheShit->setStyleSheet("border: 10px solid red");
////    maskTheShit->installEventFilter(this);
//    inlayout->addWidget(maskTheShit);
//    maskTheShit->show();
//    inlayout->setCurrentWidget(maskTheShit);


    qDebug() << "HIDING SHIT UNDERNEATH *************";
//    _video_widget->hide();
    _outer_layout->addWidget( _video_widget );
    _video_widget->hide();


//    qDebug() << "GOING TO TIME THES HIT";
//    timer = new QTimer(this);
//    timer->setInterval(10000);
//    connect(timer,SIGNAL(timeout()),this,SLOT(monSlot()));

//    timer->start();

}

void StackedPlayer::monSlot()
{
//    qDebug() << "IN THE SLOOOOOOOOOOOT";
//    this->stop();
}

bool StackedPlayer::eventFilter(QObject *object, QEvent *event)
{
    switch(event->type()){
    default:
        qDebug() << "Do preventing shitfor " << object;
        qDebug() << "Event type" << event->type();
        return true;
        break;
    case QEvent::Paint:
    case QEvent::MouseMove:
    case QEvent::Resize:
        break;
    }
    return false;
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
    _rp_mediaplayer->bind(hack);
    qDebug() << "     *** [Lib] {Player}: stacked player start" << path;
//    _mp->stop();
    _video_widget->show();

//    _video_widget->show();
    _rp_mediaplayer->setMedia(path);
    _rp_mediaplayer->play();
    _shifted_widget = _outer_layout->currentWidget();
//    _outer_layout->setCurrentWidget(_video_widget);
}

void StackedPlayer::stop()
{
    qDebug() << "     *** [Lib] {Player}: stacked player stop";
    _rp_mediaplayer->stop();
    _rp_mediaplayer->release();
//    NSView * maview = (NSView *) _inner_video_widget->winId();
//    _video_widget->hide();
//    _outer_layout->removeWidget( _video_widget );
    if(_shifted_widget){
        // XXX particularly unsafe
        _video_widget->layout()->removeWidget(_inner_video_widget);
        _inner_video_widget->deleteLater();
        _inner_video_widget = 0;
        _video_widget->deleteLater();
        _video_widget = 0;
        qDebug() << "RELEASING ALL SHIT TO " << _shifted_widget;
//        _shifted_widget->focusWidget();
//        _outer_layout->setCurrentWidget(_shifted_widget);
//        _shifted_widget->grabKeyboard();
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

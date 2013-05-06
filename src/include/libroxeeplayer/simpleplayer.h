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

#include <QtCore/qobject.h>

#include <QWidget>
#include <QGraphicsWidget>

#include <QDebug>
#include <QPainter>
#include <QPen>
#include <QColor>

#include "root.h"
#include "core.h"
#include "mediaplayer.h"
#include "audiocontrol.h"
#include "videocontrol.h"

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
    SimplePlayer(QWidget *parent = 0);// const QString & appPath,
//    ~SimplePlayer();

    Q_PROPERTY(QVariant media READ getMediaPlayer)
    Q_PROPERTY(QVariant audio READ getAudio)
    Q_PROPERTY(QVariant video READ getVideo)
    Q_PROPERTY(QVariant core READ getCore)
    Q_PROPERTY(QVariant root READ getRoot)

    Q_PROPERTY(bool crashing READ crashing)

    QVariant getMediaPlayer()
    {
        QVariant var = QVariant::fromValue((QObject*) _rp_mediaplayer);
        return var;
    }

    Q_INVOKABLE QVariant getAudio()
    {
        QVariant var = QVariant::fromValue((QObject*) _rp_audio);
        return var;
    }

    Q_INVOKABLE QVariant getVideo()
    {
        QVariant var = QVariant::fromValue((QObject*) _rp_video);
        return var;
    }

    Q_INVOKABLE QVariant getCore()
    {
        QVariant var = QVariant::fromValue((QObject*) _rp_core);
        return var;
    }

    Q_INVOKABLE QVariant getRoot()
    {
        QVariant var = QVariant::fromValue((QObject*) this->root());
        return var;
    }
//    Q_INVOKABLE void hackSize(int w, int h);

    bool crashing()
    {
        #if defined(Q_OS_WIN)
            return true;
        #else
            return false:
        #endif
    }

    /*! \brief Get a reference to the library Root object. */
    RoxeePlayer::Root * root();
    /*! \brief Get a reference to the player Core object. */
    RoxeePlayer::Core * core();
    /*! \brief Get a reference to the media player itself. */
    RoxeePlayer::MediaPlayer * mediaPlayer();


signals:
    void notify(const QString & seg);

public slots:
    void slotNotify(const QString & seg);


private:
    RoxeePlayer::Root * _rp_root;
    RoxeePlayer::Core * _rp_core;
    RoxeePlayer::MediaPlayer * _rp_mediaplayer;
    RoxeePlayer::AudioControls * _rp_audio;
    RoxeePlayer::VideoControls * _rp_video;

//    int trailh;
//    int trailw;

//    inline void update(int x, int y, int w, int h)
//    {

//    }

//    void update(const QRect&)
//    {

//    }

//    void update(const QRegion&)
//    {

//    }

//    void repaint(int x, int y, int w, int h)
//    {

//    }

//    void repaint(const QRect &)
//    {

//    }

//    void repaint(const QRegion &)
//    {

//    }



//    void update()
//    {

//    }

//    void repaint()
//    {

//    }


protected:
//    void paintEvent(QPaintEvent * event)
//    {
////        QPainter paint(this);

////        QColor color(Qt::blue);
////        QPen pen(color);
////        pen.setWidth(12);
////        paint.setPen(pen);
////        paint.drawLine(10,10,70,70);

////        qDebug() << "SHIT HAPPENED";
//////        event->accept();
//        event->accept();
////        event->ignore();
//    }

//    void resizeEvent(QResizeEvent * event);

};

}

#endif // ROXEEPLAYER_SIMPLEPLAYER_H


//    bool nativeEvent(const QByteArray & eventType, void * message, long * result)
//    {
//        if(((MSG*) message)->message == 5){
//            result = 0;
//            qDebug() << "SHIT 5 IGNORED";
//            return true;
//        }
//        if(((MSG*) message)->message == 133){
//            result = 0;
//            qDebug() << "SHIT 133 IGNORED";
//            return true;
//        }
//        if(((MSG*) message)->message == 71){
//            result = 0;
//            qDebug() << "SHIT 71 IGNORED";
//            return true;
//        }
//        if(((MSG*) message)->message == 20){
//            result = 0;
//            qDebug() << "SHIT 20 IGNORED";
//            return true;
//        }
//        if(((MSG*) message)->message == 131){
//            result = 0;
//            qDebug() << "SHIT 20 IGNORED";
//            return true;
//        }
//        if(((MSG*) message)->message == 70){
//            result = 0;
//            qDebug() << "SHIT 70 IGNORED";
//            return true;
//        }
////        if(((MSG*) message)->message == 15){
////            result = 0;
////            qDebug() << "SHIT 15 IGNORED";
////            return true;
////        }
//        qDebug() << "******";
////        qDebug() << eventType;
//        // qDebug() << (* message);// 0x22b064
////        qDebug() << (message);// 0x22b064
////        qDebug() << (& message);// 0x22b064
//        qDebug() << ((MSG*) message)->message;// 5
//        qDebug() << ((MSG*) message)->hwnd;
////        qDebug() << ((MSG*) message)->time;
//        return false;
//    }



//    bool eventFilter(QObject *object, QEvent *event)
//    {
//        if(event->type() == QEvent::Resize){

//            qDebug() << "Prevented inner resize";
//            event->accept();
//            return true;
//        }
//        if(event->type() == QEvent::Move){

//            qDebug() << "Prevented inner move";
//            event->accept();
//            return true;
//        }
//        if(event->type() == QEvent::Paint){

//            qDebug() << "Prevented inner repaint";
//            event->accept();
//            return true;
//        }
//        if(event->type() == QEvent::UpdateLater){

//            qDebug() << "Prevented later update";
//            event->accept();
//            return true;
//        }

//        if(event->type() == QEvent::PolishRequest){

//            qDebug() << "Prevented later update";
//            event->accept();
//            return true;
//        }

//        if(event->type() == QEvent::LayoutRequest){

//            qDebug() << "Prevented later update";
//            event->accept();
//            return true;
//        }

//        if(event->type() != QEvent::MetaCall){
//                qDebug() << "Filterer";
//                qDebug() << event->type();
//        }

//        return false;
////        if((event->type() != QEvent::MetaCall)
////            && (event->type() != QEvent::DeferredDelete)
////            && (event->type() != QEvent::Paint)
////            && (event->type() != QEvent::Timer)
////            && (event->type() != 185)
////            && (event->type() != QEvent::ChildRemoved)
////            && (event->type() != QEvent::ChildAdded)
////            && (event->type() != QEvent::DynamicPropertyChange)
////            && (event->type() != QEvent::ZOrderChange)
////            && (event->type() != QEvent::ActivationChange)
////        )
////        {
////            switch(event->type()){
////                case QEvent::ApplicationDeactivate:
////                    qDebug("ApplicationDeactivate");
////                break;
////                case QEvent::ApplicationActivate:
////                    qDebug("ApplicationActivate");
////                break;
////                case QEvent::WindowActivate:
////                    qDebug("WindowActivate");
////                break;
////                case QEvent::WindowDeactivate:
////                    qDebug("WindowDeactivate");
////                break;
////                case QEvent::FocusOut:
////                    qDebug("FocusOut");
////                break;
////                case QEvent::FocusIn:
////                    qDebug("FocusIn");
////                break;
////                default:
////                //    qDebug() << QString(object->dumpObjectInfo());
////                    qDebug() << event->type();
////                break;
////            }

////        }
//    }


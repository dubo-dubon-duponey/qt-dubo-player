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

#ifndef WIDGET_H
#define WIDGET_H

#include "libroxeeplayer_global.h"

#include <QtGui/QVBoxLayout>
#include <QtGui/QStackedLayout>

#include "mediaplayer.h"

// Hack stuff horror
#if defined( Q_WS_MAC )
    #include <QMacCocoaViewContainer>

    #ifdef __OBJC__
    #define ADD_COCOA_NATIVE_REF(CocoaClass) \
        @class CocoaClass; \
        typedef CocoaClass *Native##CocoaClass##Ref
    #else
    #define ADD_COCOA_NATIVE_REF(CocoaClass) typedef void *Native##CocoaClass##Ref
    #endif

    ADD_COCOA_NATIVE_REF(NSView);

#endif


using namespace RoxeePlayer;

class LIBROXEEPLAYERSHARED_EXPORT QtVlcWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QtVlcWidget(QWidget *parent = 0);
    ~QtVlcWidget();
    // MediaPlayer * start(const QString & path);

    MediaPlayer * mediaPlayer();
    QVBoxLayout *_layout;
//    QStackedLayout *_layout;


#if defined( Q_WS_MAC )
    NativeNSViewRef id() const;
    void release();
//    QMacCocoaViewContainer* getInnerStuff();

private:
    NativeNSViewRef          m_video;

#else
    WId id() const { return winId(); }
private:
#endif
//    MediaPlayer * _vp;

signals:

public slots:


};

#endif // WIDGET_H


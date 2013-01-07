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

// Don't remember where the inspiration came from: likely stackoverflow and/or videolan wiki and/or forums
// If you feel this contains parts of your code, write me a note

#include "qtvlcwidget.h"
#include <QtGui/QVBoxLayout>
#include <QtCore/QDebug>

#import <Cocoa/Cocoa.h>
#import <QuartzCore/QuartzCore.h>
#import <AppKit/NSView.h>


@interface VLCNSView : NSView
BOOL stretchesVideo;
- ( void ) setStretchesVideo : ( BOOL ) value;
- ( BOOL ) stretchesVideo;
- ( void ) addVoutSubview:( NSView * ) aView;
- ( void ) removeVoutSubview:( NSView * ) aView;
@end

@implementation VLCNSView
- ( id ) initWithFrame:( NSRect ) frameRect
{
    if ((self = [super initWithFrame:frameRect]) == nil){ return nil; }
    return self;
}
- ( void ) dealloc
{
    [super dealloc];
}
- ( void ) setStretchesVideo : ( BOOL ) value
{
    stretchesVideo = value;
}
- ( BOOL ) stretchesVideo
{
    return stretchesVideo;
}
- ( void ) addVoutSubview:( NSView * ) aView
{
    [aView setFrame:[self bounds]];
    [self addSubview:aView];
    [aView setAutoresizingMask:NSViewHeightSizable | NSViewWidthSizable];
}
- (void) removeVoutSubview:(NSView *)aView {}
@end

QtVlcWidget::QtVlcWidget( QWidget *parent ) :
//  QGLWidget( parent )
  QWidget( parent )
{
    setAttribute(Qt::WA_NativeWindow, true);

    _layout = new QVBoxLayout(parent);
    _layout->setContentsMargins(0, 0, 0, 0);
//    _layout = new QStackedLayout();
//    _layout->setStackingMode(QStackedLayout::StackAll);
    setLayout(_layout);

//    NSView *video = [[NSView alloc] init];
//    setCocoaView(video);
//    [video release];

    CoreInstance::instance();

    m_video = [[VLCNSView alloc] init];

    QMacCocoaViewContainer*  container = new QMacCocoaViewContainer( m_video, this );
    // m_container->setAutoFillBackground( true );
    container->setCocoaView(m_video);

//    QPalette videoPalette = m_container->palette();
//    videoPalette.setColor( QPalette::Window, QColor( Qt::red) );
//    m_container->setPalette( videoPalette );



    _layout->addWidget( container );

}


/*
m_video = [[VLCNSView alloc] init];
m_container = new QMacCocoaViewContainer( m_video, this );
m_container->setAutoFillBackground( true );

QPalette videoPalette = m_container->palette();
videoPalette.setColor( QPalette::Window, QColor( Qt::black ) );
m_container->setPalette( videoPalette );

QVBoxLayout* layout = new QVBoxLayout;
layout->addWidget( m_container );
setLayout( layout );
*/



//QMacCocoaViewContainer* QtVlcWidget::getInnerStuff()
//{
//    return m_container;
//}



/*
_videoWidget = new QMacCocoaViewContainer(0);
    layout->addWidget(_videoWidget);

    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

    VLCVideoView *videoView = [[VLCVideoView alloc] init];
    _videoWidget->setCocoaView(videoView);

    libvlc_media_player_set_nsobject(_mp, videoView);
    [videoView release];

    [pool release];
*/


QtVlcWidget::~QtVlcWidget()
{
}
/*
RoxeePlayer::MediaPlayer * QtVlcWidget::start(const QString & path)
{
    // Works, in a way
    // VENISE TRY

    if(!_vp){
        _vp = new RoxeePlayer::MediaPlayer((void *) static_cast< QtVlcWidget* >(this)->id(), this);
    }else{
        _vp->stop();
    }
    _vp->setMedia(path);
    _vp->play();
    return _vp;
//    _vp = new RoxeePlayer::MediaPlayer(path, m_container->cocoaView(), this);

    // _vp = new RoxeePlayer::MediaPlayer(path, (void * ) m_container->winId(), this);// this->id()
    // m_container->show();


    //    _vp = new RoxeePlayer::MediaPlayer(path, (void *) m_container->winId(), this);

    // QMacCocoaViewContainer
}
*/

//RoxeePlayer::MediaPlayer * QtVlcWidget::mediaPlayer()
//{
//    if(!_vp){
//        _vp = new RoxeePlayer::MediaPlayer((void *) static_cast< QtVlcWidget* >(this)->id(), this);
//    }
//    return _vp;
//}

/* winId returns a pointer to the NSView */
NativeNSViewRef
QtVlcWidget::id() const
{
    return m_video;
}

void
QtVlcWidget::release()
{
    [m_video release];
}

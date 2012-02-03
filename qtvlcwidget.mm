#include "qtvlcwidget.h"
#include <QPalette>
#include <QColor>
#include <QVBoxLayout>
#include <QDebug>

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

QtVlcWidget::QtVlcWidget( const QString & appPath, QWidget *parent ) :
//  QGLWidget( parent )
  QWidget( parent )
{
    _vp = 0;
    setAttribute(Qt::WA_NativeWindow, true);
    qDebug() << "Going in";
    // setAutoBufferSwap(false);


    _layout = new QVBoxLayout(parent);
    _layout->setContentsMargins(0, 0, 0, 0);

//    _layout = new QStackedLayout();
//    _layout->setStackingMode(QStackedLayout::StackAll);

    setLayout(_layout);

//    NSView *video = [[NSView alloc] init];
//    setCocoaView(video);
//    [video release];

    QtVlc::Core::instance();

    m_video = [[VLCNSView alloc] init];

    m_container = new QMacCocoaViewContainer( m_video, this );
    // m_container->setAutoFillBackground( true );
    m_container->setCocoaView(m_video);

//    QPalette videoPalette = m_container->palette();
//    videoPalette.setColor( QPalette::Window, QColor( Qt::red) );
//    m_container->setPalette( videoPalette );



    _layout->addWidget( m_container );

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



QMacCocoaViewContainer* QtVlcWidget::getInnerStuff()
{
    return m_container;
}



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
QtVlc::MediaPlayer * QtVlcWidget::start(const QString & path)
{
    // Works, in a way
    // VENISE TRY

    if(!_vp){
        _vp = new QtVlc::MediaPlayer((void *) static_cast< QtVlcWidget* >(this)->id(), this);
    }else{
        _vp->stop();
    }
    _vp->setMedia(path);
    _vp->play();
    return _vp;
//    _vp = new QtVlc::MediaPlayer(path, m_container->cocoaView(), this);

    // _vp = new QtVlc::MediaPlayer(path, (void * ) m_container->winId(), this);// this->id()
    // m_container->show();


    //    _vp = new QtVlc::MediaPlayer(path, (void *) m_container->winId(), this);

    // QMacCocoaViewContainer
}
*/

QtVlc::MediaPlayer * QtVlcWidget::mediaPlayer()
{
    if(!_vp){
        _vp = new QtVlc::MediaPlayer((void *) static_cast< QtVlcWidget* >(this)->id(), this);
    }
    return _vp;
}


/* winId should return pointer to the NSView, m_video */
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

// #include "qtvlcwidget.moc"

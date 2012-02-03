#ifndef QTVLCWIDGET_H
#define QTVLCWIDGET_H

#include "qtvlcmediaplayer.h"
#include "qtvlc_global.h"
#include <QVBoxLayout>
#include <QStackedLayout>


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


using namespace QtVlc;

class QTVLCSHARED_EXPORT QtVlcWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QtVlcWidget(const QString & appPath, QWidget *parent = 0);
    ~QtVlcWidget();
    // MediaPlayer * start(const QString & path);

    MediaPlayer * mediaPlayer();
    QVBoxLayout *_layout;
//    QStackedLayout *_layout;


#if defined( Q_WS_MAC )
    NativeNSViewRef id() const;
    void release();
    QMacCocoaViewContainer* getInnerStuff();

private:
    NativeNSViewRef          m_video;
    QMacCocoaViewContainer*  m_container;

#else
    WId id() const { return winId(); }
private:
#endif
    MediaPlayer * _vp;

signals:

public slots:


};

#endif // QTVLCWIDGET_H


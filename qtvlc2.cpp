#include "qtvlc2.h"

qtvlc2::qtvlc2(const QString & appPath, QWidget *parent) :
    QWidget(parent)
{
    QtVlc::Core::instance();
    setAttribute(Qt::WA_NativeWindow, true);

    QWidget * videoWidget = new QWidget;
//    videoWidget->setAutoFillBackground( true );
//    QPalette plt = palette();
//    plt.setColor( QPalette::Window, Qt::black );
//    videoWidget->setPalette( plt );

//    QVBoxLayout *layout2 = new QVBoxLayout;

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(videoWidget);
    this->setLayout(layout);
    _vp = new QtVlc::MediaPlayer((void *) videoWidget->winId());



    // (void *) static_cast< QtVlcWidget* >(this)->id(), this);

}

qtvlc2::~qtvlc2()
{

}

QtVlc::MediaPlayer * qtvlc2::mediaPlayer()
{
    return _vp;
}



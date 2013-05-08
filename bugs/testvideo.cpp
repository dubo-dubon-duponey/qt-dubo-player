#include "testvideo.h"
#include <QLayout>
#include <QDebug>

TestVideo::TestVideo(QWidget *parent) :
    QWidget(parent)
{
    QString path = QString::fromAscii("file:///Volumes/UltraFat/Ted_Bundy.avi");
    const char * const vlcArgs[] = {
        "--intf", "macosx"
    };

//    qDebug() << this->winId();
    ins = libvlc_new(sizeof(vlcArgs) / sizeof(*vlcArgs), vlcArgs);
    mp = libvlc_media_player_new(ins);
    libvlc_media_player_set_nsobject( mp, (void *) this->winId());
    libvlc_media_player_set_media(mp, libvlc_media_new_path(ins, path.toLocal8Bit()));
    libvlc_media_player_play(mp);

    // Kill the stuff in 5 seconds
    timer = new QTimer(this);
    timer->setInterval(10000);
    connect(timer,SIGNAL(timeout()),this,SLOT(scrapit()));
    timer->start();
}

void TestVideo::scrapit()
{
//    qDebug() << "Cleaning everything";
    libvlc_media_player_stop(mp);
    libvlc_media_player_set_nsobject(mp, NULL);
    libvlc_media_player_release(mp);
    mp = 0;
    libvlc_release(ins);
    ins = 0;
    this->parentWidget()->layout()->removeWidget(this);
    this->destroy(true, true);
}

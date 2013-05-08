#ifndef TESTVIDEO_H
#define TESTVIDEO_H

#include <QWidget>
#include <QTimer>
#include <vlc/vlc.h>

class TestVideo : public QWidget
{
    Q_OBJECT
public:
    explicit TestVideo(QWidget *parent = 0);

signals:
    
public slots:
    void scrapit();

private:
    libvlc_instance_t * ins;
    libvlc_media_player_t * mp;
    QTimer * timer;
};

#endif // TESTVIDEO_H

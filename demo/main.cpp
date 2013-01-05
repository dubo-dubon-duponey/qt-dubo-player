#include <QApplication>
#include <QMainWindow>
#include <QHBoxLayout>

#include <libroxeeplayer/simpleplayer.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    RoxeePlayer::SimplePlayer * player;
    player = new RoxeePlayer::SimplePlayer();
    player->show();
    player->mediaPlayer()->setMedia(QString("file:///Volumes/MacGrosse/MyTrailer.mov"));
    player->mediaPlayer()->play();

    return app.exec();
}

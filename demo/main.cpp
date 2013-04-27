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

//    player->core()->setUserAgent(QString("application name"), QString("13234"));
    // Returns "clang: warning: argument unused during compilation: '-mmacosx-version-min=10.5'"
//    qDebug() << player->core()->getCompiler();
//    qDebug() << player->core()->getAudioFilterList();
//    qDebug() << player->core()->getVideoFilterList();

    qDebug() << player->mediaPlayer()->isPlaying();

//    qDebug() << player->mediaPlayer()->media();
    qDebug() << "************";
    player->mediaPlayer()->setMedia(QString::fromUtf8("/Volumes/MacGrosse/Home/Movies/MyTraileréüß♥.mov"));
    qDebug() << "************";
//    qDebug() << player->mediaPlayer()->media();
    qDebug() << "************";
    qDebug() << player->mediaPlayer()->isPlaying();
    player->mediaPlayer()->play();
    qDebug() << player->mediaPlayer()->isPlaying();


//    RoxeePlayer::SimplePlayer * player2;
//    player2 = new RoxeePlayer::SimplePlayer();
//    player2->show();
//    player2->mediaPlayer()->setMedia(QString("file:///Volumes/MacGrosse/Nip Tuck Season 4 - 01 - Cindy Plumb.avi"));
//    player2->mediaPlayer()->play();

//    player = 0;
//    player2 = 0;

    int a = app.exec();
//    player->~SimplePlayer();
//    player2->~SimplePlayer();
    return a;
}

#include <QApplication>
#include <QWebView>
#include <QGraphicsWebView>
#include <QWebInspector>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <libroxeeplayer/simpleplayer.h>
#include <libroxeeplayer/webpluginfactory.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Simple QWidget
    RoxeePlayer::SimplePlayer * player;
    player = new RoxeePlayer::SimplePlayer();
    player->show();

    player->mediaPlayer()->setMedia("http://download.blender.org/peach/bigbuckbunny_movies/BigBuckBunny_320x180.mp4");
    player->mediaPlayer()->play();

    //
    // As a plugin inside HTML
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);


//    QGraphicsScene * scene = new QGraphicsScene();
//    QGraphicsView * vv = new QGraphicsView(scene);
//    QGraphicsWebView *view = new QGraphicsWebView();

    QWebView *view = new QWebView();
    new QWebInspector( view );

    RoxeePlayer::WebPluginFactory * factory = new RoxeePlayer::WebPluginFactory( view );
    view->page()->setPluginFactory(factory);
    view->page()->setProperty("_q_webInspectorServerPort", 12345);
    view->load(QUrl("qrc:/video.html"));

    view->show();
  //    scene->addItem(view);
//    vv->show();

    int a = app.exec();
    return a;
}

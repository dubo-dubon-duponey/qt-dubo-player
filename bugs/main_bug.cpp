#include <QApplication>

#include <QMainWindow>
#include <QHBoxLayout>
#include <QtWebKit/QWebView>

#include <vlc/vlc.h>
#include "testvideo.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget mainWin;

    mainWin.show();
    QHBoxLayout * ll = new QHBoxLayout();
    mainWin.setLayout(ll);
    mainWin.setGeometry(0, 0, 1600, 800);

    TestVideo * video = new TestVideo(& mainWin);
    ll->addWidget(video);
    video->show();

    QWebView * view = new QWebView(& mainWin);
    ll->addWidget(view);
    view->show();
    view->load(QString::fromAscii("http://www.google.fr/"));
    return app.exec();
}

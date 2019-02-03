/*****************************************************************************
 * Copyright (c) 2019, Dubo Dubon Duponey <dubodubonduponey+github@pm.me>
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

#include <QApplication>
#include <QtWebEngine>
#include <QWebEngineView>
#include <QWebChannel>
#include <QDebug>

#include "libduboplayer/simpleplayer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Simple QWidget
    DuboPlayer::SimplePlayer * player;
    player = new DuboPlayer::SimplePlayer();
    DuboPlayer::Root * root = new DuboPlayer::Root();

    // player->setAutoFillBackground(true);
    // player->setMouseTracking(true);

    // player->setWindowFlags(Qt::FramelessWindowHint);
    // player->setWindowFlags(Qt::CoverWindow);

    /*
    Widget = 0x00000000,
    Window = 0x00000001,
    Dialog = 0x00000002 | Window,
    Sheet = 0x00000004 | Window,
    Drawer = Sheet | Dialog,
    Popup = 0x00000008 | Window,
    Tool = Popup | Dialog,
    ToolTip = Popup | Sheet,
    SplashScreen = ToolTip | Dialog,
    Desktop = 0x00000010 | Window,
    SubWindow = 0x00000012,
    ForeignWindow = 0x00000020 | Window,
    CoverWindow = 0x00000040 | Window,
    */

    /*
    player->setAttribute(Qt::WA_TranslucentBackground, true);
    player->setAttribute(Qt::WA_NoSystemBackground, true);
    player->setAttribute(Qt::WA_OpaquePaintEvent, false);
    player->setAttribute(Qt::WA_PaintOnScreen, true);
    player->setStyleSheet(QString::fromLatin1("background-color: red;"));
    player->setWindowOpacity(0.5);
    */

    player->mediaPlayer()->setMedia(QString::fromLatin1("http://download.blender.org/peach/bigbuckbunny_movies/BigBuckBunny_320x180.mp4"));
    player->mediaPlayer()->play();
    player->show();

    /*
    qDebug() << player->root()->getName();
    qDebug() << player->root()->getBuildType();
    qDebug() << player->root()->getLinkType();
    qDebug() << player->root()->getQt();
    qDebug() << player->root()->getVendor();
    qDebug() << player->root()->getVersion();
    qDebug() << player->root()->getRevision();
    qDebug() << player->root()->getChangeset();

    qDebug() << player->root()->getLibName();
    qDebug() << player->root()->getLibVersion();
    qDebug() << player->root()->getLibRevision();

    qDebug() << player->core()->getCompiler();
    qDebug() << player->core()->getAudioFilterList();
    qDebug() << player->core()->getVideoFilterList();
*/

    // As a plugin inside HTML
/*    QWebEngineView *view = new QWebEngineView();
    view->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
    view->settings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);*/

    // Display the webview
    QFileInfo jsFileInfo(QDir::currentPath() + QString::fromUtf8("/qwebchannel.js"));

    if (!jsFileInfo.exists())
        QFile::copy(QString::fromUtf8(":/qtwebchannel/qwebchannel.js"), jsFileInfo.absoluteFilePath());

    QtWebEngine::initialize();
    QWebEngineView * view = new QWebEngineView();

    QWebChannel * channel = new QWebChannel(view->page());
    view->page()->setWebChannel(channel);
    view->load(QUrl(QString::fromUtf8("qrc:/demo.html")));

    view->show();
    // player->setOverlayWidget(view);

    channel->registerObject(QString::fromUtf8("Root"), root);
    channel->registerObject(QString::fromUtf8("Player"), player);

    int a = app.exec();
    return a;
}

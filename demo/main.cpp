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
#include <QDebug>

#include "libduboplayer/simpleplayer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Simple QWidget
    DuboPlayer::SimplePlayer * player;
    player = new DuboPlayer::SimplePlayer();
    player->show();

    player->mediaPlayer()->setMedia(QString::fromLatin1("http://download.blender.org/peach/bigbuckbunny_movies/BigBuckBunny_320x180.mp4"));
    player->mediaPlayer()->play();

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


    // As a plugin inside HTML
/*    QWebEngineView *view = new QWebEngineView();
    view->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
    view->settings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);*/

    int a = app.exec();
    return a;
}

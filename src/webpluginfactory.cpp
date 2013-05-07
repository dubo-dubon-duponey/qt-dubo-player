/*
 * Copyright 2012 WebItUp <contact@webitup.fr>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301  USA
 */

#include "libroxeeplayer/webpluginfactory.h"

#include "libroxeeplayer/simpleplayer.h"

#include <QtCore/qdebug.h>

using namespace RoxeePlayer;

namespace RoxeePlayer{

// XXX FAIL
// http://qt-project.org/forums/viewthread/8054
// http://code.google.com/p/socialwebmediacenter/source/browse/src/QTproject/qmlPlugins/KDeadMouseUtils/vlcplayer.cpp

WebPluginFactory::WebPluginFactory(QObject *parent) :
    QWebPluginFactory(parent)
{
    qDebug() << " [RoxeeLibVLC] PluginFactory: constructor";
}

//RoxeeWebPluginFactory::~RoxeeWebPluginFactory()
//{
//    qDebug() << " [RoxeeLibVLC] PluginFactory: destructor";
//}

QList<QWebPluginFactory::Plugin> WebPluginFactory::plugins () const
{
    qDebug() << " [M] PluginFactory: get plugins";
    QWebPluginFactory::MimeType mimeType;
    mimeType.name = QString::fromLatin1("video/x-roxee");
    mimeType.description = QString::fromLatin1("Roxee");
    mimeType.fileExtensions = QStringList() << QString::fromLatin1("mp4");
    mimeType.fileExtensions << QString::fromLatin1("mkv");
    mimeType.fileExtensions << QString::fromLatin1("avi");
    mimeType.fileExtensions << QString::fromLatin1("ogm");
    mimeType.fileExtensions << QString::fromLatin1("ts");

    QWebPluginFactory::Plugin plugin;
    plugin.name = QString::fromLatin1("Roxee");
    plugin.description = QString::fromLatin1("Roxee rocks");
    plugin.mimeTypes = QList<MimeType>() << mimeType;
    return QList<QWebPluginFactory::Plugin>() << plugin;
}

void WebPluginFactory::refreshPlugins ()
{
    qDebug() << " [RoxeeLibVLC]  PluginFactory: refresh plugins";
}

QObject * WebPluginFactory::create ( const QString & mimeType, const QUrl & url, const QStringList & /*argumentNames*/, const QStringList & /*argumentValues*/ ) const
{
    qDebug() << " [RoxeeLibVLC]  PluginFactory: create plugin for mimetype";

    if(mimeType != QString::fromLatin1("video/x-roxee")){
        return 0;
    }

    RoxeePlayer::SimplePlayer * inner  = new RoxeePlayer::SimplePlayer();// QString::fromLatin1("whatever")
//    player->stop();
    inner->mediaPlayer()->setMedia(url.toString());
//    player->setMedia(QString::fromLatin1("http://sn.ackitup.net:5000/mkv/test.multi.mkv"));

    // This is necessary so that mousevents are correctly forwarded afterwards to the webview (after deactivate + click on plugin)
    inner->setMouseTracking(true);

//    inner->mediaPlayer()->play();

//    inner->autoFillBackground();
//    inner->createWinId();
//    inner->setGeometry(0,0,300,300);
//    inner->setAttribute(Qt::WA_DontCreateNativeAncestors, true);
//    inner->setAttribute(Qt::WA_NativeWindow, true);

    // Crash on window if we don't use fixed dimensions for the widget
//    inner->setFixedHeight(100);
//    inner->setFixedWidth(100);
    return inner;
}

}

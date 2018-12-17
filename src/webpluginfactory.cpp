/*****************************************************************************
 * Copyright (c) 2018, Dubon Dubon Duponey <dubodubonduponey+github@pm.me>
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


#include "libduboplayer/webpluginfactory.h"

#include "libduboplayer/simpleplayer.h"

//#include <QDebug>
#include <QStackedLayout>
#include <QWebView>
#include <QGraphicsWebView>
#include <QGraphicsView>
#include <QGLWidget>
#include <QStyle>

/*! \cond */

using namespace DuboPlayer;

namespace DuboPlayer{

// XXX FAIL
// http://qt-project.org/forums/viewthread/8054
// http://code.google.com/p/socialwebmediacenter/source/browse/src/QTproject/qmlPlugins/KDeadMouseUtils/vlcplayer.cpp

WebPluginFactory::WebPluginFactory(QObject *parent) :
    QWebPluginFactory(parent)
{
//    qDebug() << " [DuboLibVLC] PluginFactory: constructor";
}

QList<QWebPluginFactory::Plugin> WebPluginFactory::plugins () const
{
//    qDebug() << " [DuboLibVLC] PluginFactory: get plugins";
    QWebPluginFactory::MimeType mimeType;
    mimeType.name = QString::fromLatin1("video/x-dubo");
    mimeType.description = QString::fromLatin1("Dubo");
    mimeType.fileExtensions = QStringList() << QString::fromLatin1("mp4");
    mimeType.fileExtensions << QString::fromLatin1("mkv");
    mimeType.fileExtensions << QString::fromLatin1("avi");
    mimeType.fileExtensions << QString::fromLatin1("ogm");
    mimeType.fileExtensions << QString::fromLatin1("ts");

    QWebPluginFactory::Plugin plugin;
    plugin.name = QString::fromLatin1("Dubo");
    plugin.description = QString::fromLatin1("Dubo rocks");
    plugin.mimeTypes = QList<MimeType>() << mimeType;
    return QList<QWebPluginFactory::Plugin>() << plugin;
}

void WebPluginFactory::refreshPlugins ()
{
//    qDebug() << " [DuboLibVLC]  PluginFactory: refresh plugins";
}

 QObject * WebPluginFactory::create ( const QString & mimeType, const QUrl & url, const QStringList & argumentNames, const QStringList & /* argumentValues */ ) const
 {
 //    qDebug() << " [DuboLibVLC]  PluginFactory: create plugin for mimetype";

     if(mimeType != QString::fromLatin1("video/x-dubo"))
         return 0;

     DuboPlayer::SimplePlayer * inner  = new DuboPlayer::SimplePlayer();// QString::fromLatin1("whatever")
 //    QPalette palette = view->page()->palette();
 //    palette.setBrush(QPalette::Base, Qt::transparent);
 //    view->setPalette(palette);
     // view->page()->setPalette(palette);
 //    inner->setAttribute(Qt::WA_OpaquePaintEvent, false);
 //    inner->setWindowFlags(Qt::FramelessWindowHint);

     inner->mediaPlayer()->setMedia(url.toString());

     if(argumentNames.contains("autofill")){
         inner->setAutoFillBackground(true);
     }
     inner->setMouseTracking(true);
     return inner;


//     QWidget *pTestWidget = new QWidget;
//     pTestWidget->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
//     pTestWidget->setAttribute(Qt::WA_TranslucentBackground, true);
//     pTestWidget->setAttribute(Qt::WA_NoSystemBackground, true);
//     pTestWidget->setAttribute(Qt::WA_OpaquePaintEvent, false);
//     pTestWidget->setAttribute( Qt::WA_PaintOnScreen, true);

// //        QGraphicsWebView *container= new QGraphicsWebView();//

//         QWebView *container= new QWebView();

// //        container->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
//         container->setWindowFlags(Qt::FramelessWindowHint);
// //        container->setParent(0); // Create TopLevel-Widget
//         container->setAttribute(Qt::WA_NoSystemBackground, true);
//         container->setAttribute(Qt::WA_TranslucentBackground, true);
//         container->setHtml("<body><div style=\"background-color: rgba(255, 255, 0, 0.5); border: 1px solid black; color:#FFFFFF;font-size:36px;\">Holy macaroni</div></body>");

//         QPalette palette = container->palette();
//         palette.setBrush(QPalette::Base, Qt::transparent);
//         container->page()->setPalette(palette);
//         container->setAttribute(Qt::WA_OpaquePaintEvent, false);


//         container->setStyleSheet("background-color: red;");

// //        container->setWindowOpacity(0.5);


//         inner->setOverlayWidget(container);
// //        container->show();

 }


//QObject * WebPluginFactory::create ( const QString & mimeType, const QUrl & url, const QStringList & argumentNames, const QStringList & /* argumentValues */ ) const
//{
////    qDebug() << " [DuboLibVLC]  PluginFactory: create plugin for mimetype";

//   if(mimeType != QString::fromLatin1("video/x-dubo"))
//       return 0;

//   DuboPlayer::SimplePlayer * inner  = new DuboPlayer::SimplePlayer();// QString::fromLatin1("whatever")

////    QWidget *pTestWidget = new QWidget;
////    pTestWidget->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
////    pTestWidget->setAttribute(Qt::WA_TranslucentBackground, true);
////    pTestWidget->setAttribute(Qt::WA_NoSystemBackground, true);
////    pTestWidget->setAttribute(Qt::WA_OpaquePaintEvent, false);
////    pTestWidget->setAttribute( Qt::WA_PaintOnScreen, true);

//   //    pTestWidget->show();


//   QWebSettings::globalSettings()->setAttribute(QWebSettings::AcceleratedCompositingEnabled, true);
//   QGLWidget * gwi = new QGLWidget();
////    gwi->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);


//   QGraphicsView * gview = new QGraphicsView();
//   gview->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
//   gview->setViewport(gwi);
//   gview->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
////    gview->setAttribute(Qt::WA_TranslucentBackground, true);
////    gview->setAttribute(Qt::WA_NoSystemBackground, true);
////    gview->setAttribute(Qt::WA_OpaquePaintEvent, false);
////    gview->setAttribute( Qt::WA_PaintOnScreen, true);
//   gview->setStyleSheet("background-color: transparent");

//   QGraphicsScene * scene = new QGraphicsScene(gview);
//   QGraphicsWebView * container = new QGraphicsWebView();
//   scene->addItem(container);
//   gview->setScene(scene);

//   container->setHtml("<body><div style=\"background-color: rgba(255, 255, 0, 0.5); border: 1px solid black; color:#FFFFFF;font-size:36px;\">Holy macaroni</div></body>");

//   gview->show();
//   //   ((QWidget *) inner)->window()->layout()->addWidget(gview);

//   inner->mediaPlayer()->setMedia(url.toString());

////    if(argumentNames.contains("autofill")){
////        inner->setAutoFillBackground(true);
////    }
//   inner->setMouseTracking(true);

//   return inner;

////    container->setScsetScene(scene);

//   //    setCentralWidget(gview);

////    QGraphicsWebView *container= new QGraphicsWebView();//

//   //    QWebView *view = new QWebView();

////    container->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
////    container->setWindowFlags(Qt::FramelessWindowHint);
////    container->setParent(0); // Create TopLevel-Widget
////    container->setAttribute(Qt::WA_NoSystemBackground, true);
////    container->setAttribute(Qt::WA_TranslucentBackground, true);

////    QPalette palette = container->palette();
////    palette.setBrush(QPalette::Base, Qt::transparent);
////    container->page()->setPalette(palette);
////    container->setAttribute(Qt::WA_OpaquePaintEvent, false);


////    container->setStyleSheet("background-color: transparent");

//   //    container->show();
////    container->setWindowOpacity(0.5);


////    inner->setOverlayWidget(container);
////    inner->setOverlayWidget(pTestWidget);

////    inner->setAutoFillBackground(true);
////    w.show();


////    container->setWindowOpacity(.0);
////    container->setAttribute(Qt::WA_PaintOnScreen); // as pointed by Caveman (thanks!)



////    QPalette palette = view->page()->palette();
////    palette.setBrush(QPalette::Base, Qt::transparent);
////    view->setPalette(palette);
//   // view->page()->setPalette(palette);
//   container->setAttribute(Qt::WA_OpaquePaintEvent, false);
//   container->setWindowFlags(Qt::FramelessWindowHint);

////    QPalette pa = view->palette();
////    pa.setBrush(QPalette::Base, Qt::transparent);
////    view->setPalette(pa);


//   //    container->setAttribute( Qt::WA_PaintOnScreen, true);
////    container->setStyleSheet("background-color: transparent");
////    container->setAttribute(Qt::WA_TranslucentBackground, true);
////    container->setAttribute(Qt::WA_NoSystemBackground, true);
////    container->setWindowOpacity(0.5);



////    container->setLayout(new QStackedLayout());
////    container->layout()->addWidget(view);
////    inner->layout()->addWidget(view);

////    inner->setOverlayWidget(container);

//   inner->mediaPlayer()->setMedia(url.toString());

//   if(argumentNames.contains("autofill")){
//       inner->setAutoFillBackground(true);
//   }
//   inner->setMouseTracking(true);

//   return inner;
//}


}


/*! \endcond */

/*****************************************************************************
 * Copyright (c) 2018, Dubo Dubon Duponey <dubodubonduponey@gmail.com>
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

#ifndef DUBOPLAYER_WEBPLUGINFACTORY_H
#define DUBOPLAYER_WEBPLUGINFACTORY_H

#include "libduboplayer_global.h"

#include <QWebPluginFactory>
#include <QList>
#include <QStringList>
#include <QUrl>

namespace DuboPlayer
{
/*! \brief. An example QWebPluginFactory to use for your webview. */

class LIBDUBOPLAYERSHARED_EXPORT WebPluginFactory : public QWebPluginFactory
{
    Q_OBJECT
public:
    /*! \brief. See QWebPluginFactory. */
    explicit WebPluginFactory(QObject *parent = 0);

    /*! \cond */
    virtual QList<QWebPluginFactory::Plugin> plugins() const;
    virtual void refreshPlugins();
    virtual QObject *create(const QString& mimeType,
                            const QUrl&,
                            const QStringList& argumentNames,
                            const QStringList& argumentValues) const;
    /*! \endcond */

signals:

public slots:

};
}

#endif // DUBOPLAYER_WEBPLUGINFACTORY_H







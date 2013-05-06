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

#ifndef ROXEEPLAYER_WEBPLUGINFACTORY_H
#define ROXEEPLAYER_WEBPLUGINFACTORY_H

#include "libroxeeplayer_global.h"

#include <QWebPluginFactory>
#include <QList>
#include <QStringList>

namespace RoxeePlayer
{

class LIBROXEEPLAYERSHARED_EXPORT WebPluginFactory : public QWebPluginFactory
{
    Q_OBJECT
public:
    explicit WebPluginFactory(QObject *parent = 0);
//    ~RoxeeWebPluginFactory();
    virtual QList<QWebPluginFactory::Plugin> plugins() const;
    virtual void refreshPlugins();
    virtual QObject *create(const QString& mimeType,
                            const QUrl&,
                            const QStringList& argumentNames,
                            const QStringList& argumentValues) const;

signals:

public slots:

};
}

#endif // ROXEEPLAYER_WEBPLUGINFACTORY_H







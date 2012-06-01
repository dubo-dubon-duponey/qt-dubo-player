/*****************************************************************************
 * Copyright (c) 2012, WebItUp
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

#ifndef ROXEEPLAYER_ROOT_H
#define ROXEEPLAYER_ROOT_H

#include "libroxeeplayer_global.h"
#include <QtCore/QObject>

namespace RoxeePlayer
{

    class LIBROXEEPLAYERSHARED_EXPORT Root: public QObject {
        Q_OBJECT
    public:
        explicit Root(){}

        Q_PROPERTY(const QString name READ getName)
        Q_PROPERTY(const QString ROXEE_VERSION READ getVersion)
        Q_PROPERTY(const QString ROXEE_REVISION READ getRevision)
        Q_PROPERTY(const QString ROXEE_CHANGESET READ getChangeset)

        Q_PROPERTY(const QString PLUGIN_VERSION READ getLibVersion)
        Q_PROPERTY(const QString PLUGIN_REVISION READ getLibRevision)

        const QString getName();
        const QString getVersion();
        const QString getRevision();
        const QString getChangeset();

        const QString getLibVersion();
        const QString getLibRevision();
    };
}

#endif // ROXEEPLAYER_ROOT_H

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

#include "libduboplayer/root.h"

#include "libduboplayer/vlc3.h"

/*! \cond */

namespace DuboPlayer{
const QString Root::getName(){
    return QString::fromUtf8(PROJECT_NAME);
}

const QString Root::getVendor(){
    return QString::fromUtf8(PROJECT_VENDOR);
}

const QString Root::getVersion(){
    return QString::fromUtf8(VERSION_FULL);
}

const QString Root::getBuildType(){
    return QString::fromUtf8(PROJECT_BUILDTYPE);
}

const QString Root::getLinkType(){
    return QString::fromUtf8(PROJECT_LINKTYPE);
}

const QString Root::getQt(){
    return QString::fromUtf8(QT_VERSION_STR);
}

const QString Root::getRevision(){
    return QString::fromUtf8(VERSION_GIT);
}

const QString Root::getChangeset(){
    return QString::fromUtf8(VERSION_CHANGE);
}

const QString Root::getLibVersion(){
    return DuboVLC::get_version();
}

const QString Root::getLibRevision(){
    return DuboVLC::get_changeset();
}

}

/*! \endcond */

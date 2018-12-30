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

#include "libduboplayer/core.h"

/*! \cond */

namespace DuboPlayer{

Core::Core(DuboVLC * rvlc, QObject *parent):
    QObject(parent)
{
    vlc = rvlc;
}

void Core::setUserAgent(const QString &appName, const QString &appVersion)
{
    QString applicationOutput = appName + " " + appVersion;
    QString httpOutput = appName + "/" + appVersion + " " + PROJECT_NAME + "/" + VERSION_FULL + "(" + vlc->get_version() + " " + vlc->get_compiler() +")";
    vlc->set_user_agent(applicationOutput, httpOutput);
}

QString Core::getCompiler()
{
    return vlc->get_compiler();
}

QStringList Core::getAudioFilterList()
{
    return vlc->audio_filter_list_get();
}

QStringList Core::getVideoFilterList()
{
    return vlc->video_filter_list_get();
}

}

/*! \endcond */

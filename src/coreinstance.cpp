/*****************************************************************************
 * Copyright (c) 2012, WebItUp <contact@webitup.fr>
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

#include "coreinstance.h"

#include <QtCore/qdebug.h>

/*! \cond */

LRPCoreInstance* LRPCoreInstance::m_Instance = 0;

LRPCoreInstance::LRPCoreInstance()
{
    const char * const vlcArgs[] = {
        "-I", "dummy", /* Don't use any interface */
        "--ignore-config", /* Don't use VLC's config */
        "--no-osd" };

//    "--extraintf=logger", /* Log everything */
//    "--verbose=2", /* Be much more verbose then normal for debugging purpose */

    if((_vlc = libvlc_new(sizeof(vlcArgs) / sizeof(*vlcArgs), vlcArgs)) == NULL) {
        qDebug() << QString::fromLatin1("Could not init libVLC");
    }
}


LRPCoreInstance* LRPCoreInstance::instance()
{
    static QMutex mutex;
    if (!m_Instance){
        mutex.lock();
        if (!m_Instance)
            m_Instance = new LRPCoreInstance;
        mutex.unlock();
    }
    return m_Instance;
}

LRPCoreInstance::~LRPCoreInstance()
{
    libvlc_release(_vlc);
    _vlc = 0;

    static QMutex mutex;
    mutex.lock();
    delete m_Instance;
    m_Instance = 0;
    mutex.unlock();
}

/*! \endcond */

// 1.1
//    // Convert arguments
//    std::string stdStrings[args.size()];
//    const char *vlcArgs[args.size()];
//    for(int i = 0; i < args.size(); i++) {
//            stdStrings[i] = args[i].toStdString();
//            vlcArgs[i] = stdStrings[i].c_str();
//    }

//    // libvlc_instance_t * 	libvlc_new (int argc, const char *const *argv)
//    // Create and initialize a libvlc instance.
//    _vlc = libvlc_new(sizeof(vlcArgs) / sizeof(*vlcArgs), vlcArgs);

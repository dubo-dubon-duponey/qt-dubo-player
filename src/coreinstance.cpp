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

#include "coreinstance.h"

/*! \cond */

LRPCoreInstance* LRPCoreInstance::m_Instance = 0;

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

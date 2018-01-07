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

#ifndef DUBOPLAYER_LIBDUBOPLAYER_GLOBAL_H
#define DUBOPLAYER_LIBDUBOPLAYER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBDUBOPLAYER_USE_STATIC)
#  define LIBDUBOPLAYERSHARED_EXPORT
#elif defined(LIBDUBOPLAYER_LIBRARY)
#  define LIBDUBOPLAYERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIBDUBOPLAYERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DUBOPLAYER_LIBDUBOPLAYER_GLOBAL_H

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

#ifndef ROXEEPLAYER_LIBROXEEPLAYER_GLOBAL_H
#define ROXEEPLAYER_LIBROXEEPLAYER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBROXEEPLAYER_LIBRARY)
#  define LIBROXEEPLAYERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIBROXEEPLAYERSHARED_EXPORT Q_DECL_IMPORT
// To have it static:
//#  define LIBROXEEPLAYERSHARED_EXPORT
#endif

#endif // ROXEEPLAYER_LIBROXEEPLAYER_GLOBAL_H

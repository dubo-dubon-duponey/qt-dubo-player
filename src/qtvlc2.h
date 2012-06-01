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

#ifndef ROXEEPLAYER_QTVLC2_H
#define ROXEEPLAYER_QTVLC2_H

#include "libroxeeplayer_global.h"

#include <QtCore/QObject>
#include <QtGui/QWidget>

#include "mediaplayer.h"

//using namespace RoxeePlayer;

namespace RoxeePlayer{

class LIBROXEEPLAYERSHARED_EXPORT qtvlc2 : public QWidget
{
    Q_OBJECT
public:
    explicit qtvlc2(QWidget *parent = 0);// const QString & appPath,
    ~qtvlc2();
    MediaPlayer * mediaPlayer();

signals:

public slots:

private:
    MediaPlayer * _vp;

};

}

#endif // ROXEEPLAYER_QTVLC2_H

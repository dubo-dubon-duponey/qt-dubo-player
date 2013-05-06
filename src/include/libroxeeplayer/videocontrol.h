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

#ifndef ROXEEPLAYER_VIDEOCONTROLS_H
#define ROXEEPLAYER_VIDEOCONTROLS_H

#include "libroxeeplayer_global.h"

#include <QObject>
#include <QStringList>

#include "libroxeeplayer/vlc2.h"

namespace RoxeePlayer
{
    /*! \brief Video controllers, exposed through the top-level classes */
    class LIBROXEEPLAYERSHARED_EXPORT VideoControls : public QObject
    {
        Q_OBJECT
    public:
        /*! \cond */
        explicit VideoControls(RoxeeVLC * rvlc, QObject *parent = 0);
        /*! \endcond */

        // Video controls

        /*! \brief Toggles fullscreen */
        Q_INVOKABLE void toggleFullscreen();

        /*! \brief Retrieve and set fullscreen */
        Q_PROPERTY(bool fullscreen READ fullscreen WRITE setFullscreen)

        /*! \brief Toggles key input */
        Q_INVOKABLE void setKeyInput(const bool on );
        /*! \brief Toggles mouse input */
        Q_INVOKABLE void setMouseInput(const bool on);
        /*getSize()*/
        /*! \brief Retrieves height */
        Q_PROPERTY(uint height READ height)
        /*! \brief Retrieves width */
        Q_PROPERTY(uint width READ width)

        /*cursor()*/
        /*! \brief Retrieves and sets scale */
        Q_PROPERTY(float scale READ scale WRITE setScale)

        /*! \brief Retrieves and set aspectRatio */
        Q_PROPERTY(QString aspectRatio READ aspectRatio WRITE setAspectRatio)

        /*! \brief Retrieves and set spu */
        Q_PROPERTY(int spu READ spu WRITE setSpu)
        /*! \brief Read spu count */
        Q_PROPERTY(int spuCount READ spuCount)

        /*! \brief Read spu description */
        Q_PROPERTY(QStringList spuTrackDescription READ spuTrackDescription)

        /*! \brief Set spu file */
        Q_INVOKABLE void setSubtitleFile(const QString &path);

/*        Q_PROPERTY(int spuDelay READ spuDelay WRITE setSpuDelay)
        int spuDelay();
        void setSpuDelay(const int & i);*/

//        Q_PROPERTY(QStringList titleDescription READ titleDescription)
        // QStringList* titleDescription();

        // XXX unexposed
        // QStringList* chapterDescription(int i);

        /*! \brief Retrieves and set cropping geometry */
        Q_PROPERTY(QString cropGeometry READ cropGeometry WRITE setCropGeometry)

        /*! \brief Retrieves and set teletext */
        Q_PROPERTY(int teletext READ teletext WRITE setTeletext)
//        Q_INVOKABLE void toggleTeletext();
        /*! \brief Read video track count */
        Q_PROPERTY(int videoTrackCount READ videoTrackCount)
        /*! \brief Read video tracks description */
        Q_PROPERTY(QStringList videoTrackDescription READ videoTrackDescription)
        /*! \brief Retrieve and set video track */
        Q_PROPERTY(int videoTrack READ videoTrack WRITE setVideoTrack)

        /*! \brief Take snapshot */
        Q_INVOKABLE void takeSnapshot(const int i, const QString & id);
//        void VideoControls::takeSnapshot(const int i)

        /*! \brief Toggle deinterlace mode */
        Q_INVOKABLE void setDeinterlace(const bool on);

        /*! \cond */
        void setFullscreen(const bool on);
        bool fullscreen();
        uint height();
        uint width();
        float scale();
        void setScale(const float factor);
        QString aspectRatio();
        void setAspectRatio(const QString &ar);
        int spu();
        void setSpu(uint i);
        int spuCount();
        QStringList spuTrackDescription();
        QString cropGeometry();
        void setCropGeometry(const QString &crop);
        int teletext();
        void setTeletext(const int & i);
        void toggleTeletext();
        int videoTrackCount();
        QStringList videoTrackDescription();
        int videoTrack();
        void setVideoTrack(const int i);
        /*! \endcond */

    signals:

    public slots:
    private:
        RoxeeVLC * vlc;
    };
}

#endif // ROXEEPLAYER_VIDEOCONTROLS_H

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

#ifndef ROXEEPLAYER_CORE_H
#define ROXEEPLAYER_CORE_H

#include "libroxeeplayer_global.h"

#include <QtCore/QMutex>
#include <QtCore/QObject>
#include <QtCore/QStringList>

namespace RoxeePlayer{

/*! \brief A core object with a couple of random infos / helpers (this is a singleton) */
class LIBROXEEPLAYERSHARED_EXPORT Core : public QObject
{
    Q_OBJECT
public:
    /*! \brief Instance (singleton pattern) */
    static Core* instance()
    {
        static QMutex mutex;
        if (!m_Instance){
            mutex.lock();
            if (!m_Instance)
                m_Instance = new Core;
            mutex.unlock();
        }
        return m_Instance;
    }

    /*! \brief Destructor */
    ~Core()
    {
        static QMutex mutex;
        mutex.lock();
        delete m_Instance;
        m_Instance = 0;
        mutex.unlock();
    }

    /*! \brief Allows to control the UA string that will be set for http streams retrieval. */
    Q_INVOKABLE void setUserAgent(const QString &appName, const QString &appVersion);
    /*! \brief Gets the underlying library version */
    Q_PROPERTY(const QString version READ getVersion)
    /*! \brief Gets the underlying library changeset */
    Q_PROPERTY(const QString changeset READ getChangeset)
    /*! \brief Gets the compiler used to build the underlying library */
    Q_PROPERTY(const QString compiler READ getCompiler)

    /*! \cond */
    QString getVersion();
    QString getChangeset();
    QString getCompiler();

    QStringList audioFilterList();
    QStringList videoFilterList();
    /*! \endcond */

signals:

public slots:

private:
    explicit Core(){}

    static Core* m_Instance;

    Core(const Core &);
    Core& operator=(const Core &);

};
}

#endif // ROXEEPLAYER_CORE_H

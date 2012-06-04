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

#include "core.h"
#include <QtCore/QDebug>
#include <QtCore/QMutex>

#include "coreinstance.h"

/*! \cond */

namespace RoxeePlayer{
Core* Core::m_Instance = 0;

Core* Core::instance()
{
    qDebug() << " [M] VLC: Getting core instance";
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
Core::~Core()
{
//    qDebug() << " [M] VLC: Destructing core instance";
//    static QMutex mutex;
//    mutex.lock();
//    delete m_Instance;
//    m_Instance = 0;
//    mutex.unlock();
}


void Core::setUserAgent(const QString &appName, const QString &appVersion)
{
//    void 	libvlc_set_user_agent (libvlc_instance_t *p_instance, const char *name, const char *http)
//            Sets the application name.
    QString applicationOutput = appName + " " + appVersion;
    QString httpOutput = appName + "/" + appVersion + " qt-libvlc/" + (this->getVersion()) + "("+ this->getCompiler() +")";
    libvlc_set_user_agent(LRPCoreInstance::instance()->getSession(), applicationOutput.toAscii().data(), httpOutput.toAscii().data());
}

QString Core::getVersion()
{
//    const char * 	libvlc_get_version (void)
//            Retrieve libvlc version.
    return QString(libvlc_get_version());
}

QString Core::getChangeset()
{
//    const char * 	libvlc_get_changeset (void)
//            Retrieve libvlc changeset.
    return QString(libvlc_get_changeset());
}

QString Core::getCompiler()
{
//    const char * 	libvlc_get_compiler (void)
//            Retrieve libvlc compiler version.
    return QString(libvlc_get_compiler());
}


/*

Data Structures

struct  	libvlc_module_description_t
    Description of a module. More...
Modules

    LibVLC error handling
    LibVLC asynchronous events

LibVLC emits asynchronous events.


    LibVLC logging

libvlc_log_* functions provide access to the LibVLC messages log.


Typedefs

typedef struct
libvlc_module_description_t 	libvlc_module_description_t
    Description of a module.
Functions

void 	libvlc_retain (libvlc_instance_t *p_instance)
    Increments the reference count of a libvlc instance.
int 	libvlc_add_intf (libvlc_instance_t *p_instance, const char *name)
    Try to start a user interface for the libvlc instance.
void 	libvlc_set_exit_handler (libvlc_instance_t *p_instance, void(*cb)(void *), void *opaque)
    Registers a callback for the LibVLC exit event.
void 	libvlc_wait (libvlc_instance_t *p_instance)
    Waits until an interface causes the instance to exit.
void 	libvlc_free (void *ptr)
    Frees an heap allocation returned by a LibVLC function.


typedef struct libvlc_instance_t 	libvlc_instance_t
    This structure is opaque.
typedef int64_t 	libvlc_time_t

*/



QStringList Core::audioFilterList()
{
    QStringList l = QStringList();
    libvlc_module_description_t * md = libvlc_audio_filter_list_get(LRPCoreInstance::instance()->getSession());
    do{
        l.append(QString().fromLocal8Bit(md->psz_name));
        l.append(QString().fromLocal8Bit(md->psz_shortname));
        l.append(QString().fromLocal8Bit(md->psz_longname));
        l.append(QString().fromLocal8Bit(md->psz_help));
    }while(md->p_next);
    libvlc_module_description_list_release(md);
    return l;
}

QStringList Core::videoFilterList()
{
    QStringList l = QStringList();
    libvlc_module_description_t * md = libvlc_video_filter_list_get(LRPCoreInstance::instance()->getSession());
    do{
        l.append(QString().fromLocal8Bit(md->psz_name));
        l.append(QString().fromLocal8Bit(md->psz_shortname));
        l.append(QString().fromLocal8Bit(md->psz_longname));
        l.append(QString().fromLocal8Bit(md->psz_help));
    }while(md->p_next);
    libvlc_module_description_list_release(md);
    return l;
}

}

/*! \endcond */

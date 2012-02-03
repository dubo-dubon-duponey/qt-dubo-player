#include "qtvlccore.h"
#include <QDebug>

using namespace QtVlc;

Core* Core::m_Instance = 0;

Core::Core(QObject *parent) :
    QObject(parent)
{
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

    // Create and initialize a libvlc instance.
    if((_vlc = libvlc_new(0,NULL)) == NULL) {
        qDebug() << "Could not init libVLC";
    }
}


Core::~Core()
{
    // void 	libvlc_release (libvlc_instance_t *p_instance)
    // Decrement the reference count of a libvlc instance, and destroy it if it reaches zero.
    libvlc_release(_vlc);

    // Free singleton
    static QMutex mutex;
    mutex.lock();
    delete m_Instance;
    m_Instance = 0;
    mutex.unlock();
}


Core* Core::instance()
{
//    QStringList args;
//    args << "--intf=dummy"
//             << "--no-media-library"
//             << "--reset-plugins-cache"
//             << "-I"
//             << "-dummy"
//             << "--no-stats"
//             << "--ignore-config"      // Don't use VLC's config

//             << "--verbose=-1"
//             << "--quiet"
//          #ifdef Q_WS_MAC
////             << "--vout=caca"
////             << "--vout=minimal_macosx"
////             << "--opengl-provider=minimal_macosx"
//          #endif
//             << "--no-osd"
//             <<  ("--plugin-path=" + appPath);

//    qDebug() << "Received plugin path:";
//    qDebug() << appPath;
    static QMutex mutex;
    if (!m_Instance){
        mutex.lock();
        if (!m_Instance)
            m_Instance = new Core();
        mutex.unlock();
    }
    return m_Instance;
}

void Core::setUserAgent(const QString &appName, const QString &appVersion)
{
//    void 	libvlc_set_user_agent (libvlc_instance_t *p_instance, const char *name, const char *http)
//            Sets the application name.
    QString applicationOutput = appName + " " + appVersion;
    QString httpOutput = appName + "/" + appVersion + " qt-libvlc/" + (this->getVersion()) + "("+ this->getCompiler() +")";
    libvlc_set_user_agent(_vlc, applicationOutput.toAscii().data(), httpOutput.toAscii().data());
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
    libvlc_module_description_t * md = libvlc_audio_filter_list_get(_vlc);
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
    libvlc_module_description_t * md = libvlc_video_filter_list_get(_vlc);
    do{
        l.append(QString().fromLocal8Bit(md->psz_name));
        l.append(QString().fromLocal8Bit(md->psz_shortname));
        l.append(QString().fromLocal8Bit(md->psz_longname));
        l.append(QString().fromLocal8Bit(md->psz_help));
    }while(md->p_next);
    libvlc_module_description_list_release(md);
    return l;
}

#ifndef ROXEEPLAYER_COREINSTANCE_H
#define ROXEEPLAYER_COREINSTANCE_H

#include "libroxeeplayer_global.h"

#include <QtCore/qobject.h>
#include <QtCore/qmutex.h>
#include <QtCore/qstringlist.h>

#include <vlc/vlc.h>

// XXX allow more than one vlc instance instead of this crap

/*! \cond */
struct libvlc_instance_t;
struct libvlc_media_player_t;

class LRPCoreInstance : public QObject
{
    Q_OBJECT
public:
    static LRPCoreInstance* instance();
    ~LRPCoreInstance();

//    void setSession (libvlc_instance_t* val) { _vlc = val; }
    libvlc_instance_t* getSession () { return _vlc; }

    void setPlayer (libvlc_media_player_t * val) { _vlcmp = val; }
    libvlc_media_player_t* getPlayer () { return _vlcmp; }

private:
    libvlc_instance_t* _vlc;
    libvlc_media_player_t * _vlcmp;

    LRPCoreInstance();
    LRPCoreInstance(const LRPCoreInstance &); // hide copy constructor
    LRPCoreInstance& operator=(const LRPCoreInstance &); // hide assign op

    static LRPCoreInstance* m_Instance;

};

/*! \endcond */

#endif // ROXEEPLAYER_COREINSTANCE_H

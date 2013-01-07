#include "events.h"

#include <vlc/vlc.h>

namespace RoxeePlayer{

Events::Events(QObject *parent) :
    QObject(parent)
{
}

Events::~Events()
{
}




//libvlc_event_type_t vlcEvents[] =
//{
//    libvlc_MediaPlayerMediaChanged,
//    libvlc_MediaPlayerNothingSpecial,
//    libvlc_MediaPlayerOpening,
//    libvlc_MediaPlayerBuffering,
//    libvlc_MediaPlayerPlaying,
//    libvlc_MediaPlayerPaused,
//    libvlc_MediaPlayerStopped,
//    libvlc_MediaPlayerForward,
//    libvlc_MediaPlayerBackward,
//    libvlc_MediaPlayerEndReached,
//    libvlc_MediaPlayerEncounteredError,
//    libvlc_MediaPlayerTimeChanged,
//    libvlc_MediaPlayerPositionChanged,
//    libvlc_MediaPlayerSeekableChanged,
//    libvlc_MediaPlayerPausableChanged,
//    libvlc_MediaPlayerTitleChanged,
//    libvlc_MediaPlayerSnapshotTaken,
//    libvlc_MediaPlayerLengthChanged
//};

//const int eventCount = sizeof(vlcEvents) / sizeof(vlcEvents[0]);

//libvlc_event_manager_t *vlcEventManager = libvlc_media_player_event_manager(m_vlcPlayer);

//for (int i = 0; i < eventCount; ++i) {
//    libvlc_event_attach(vlcEventManager, vlcEvents[i], reinterpret_cast<libvlc_callback_t>(vlcEventCallback), this);
//}





//typedef void( * libvlc_callback_t)(const struct libvlc_event_t *, void *)
//static void Events::Callback(const libvlc_event_t *event,
//                            void *data);
//void Events::Callback(const struct libvlc_event_t * event, void * data)
//{
//    switch(event->type)
//    {
//    case libvlc_MediaPlayerMediaChanged:
//    case libvlc_MediaPlayerNothingSpecial:
//    case libvlc_MediaPlayerOpening:
//    case libvlc_MediaPlayerBuffering:
//    case libvlc_MediaPlayerPlaying:
//    case libvlc_MediaPlayerPaused:
//    case libvlc_MediaPlayerStopped:
//    case libvlc_MediaPlayerForward:
//    case libvlc_MediaPlayerBackward:
//    case libvlc_MediaPlayerEndReached:
//    case libvlc_MediaPlayerEncounteredError:
//    case libvlc_MediaPlayerTimeChanged:
//    case libvlc_MediaPlayerPositionChanged:
//    case libvlc_MediaPlayerSeekableChanged:
//    case libvlc_MediaPlayerPausableChanged:
//    case libvlc_MediaPlayerTitleChanged:
//    case libvlc_MediaPlayerSnapshotTaken:
//    case libvlc_MediaPlayerLengthChanged:


//        libvlc_MediaMetaChanged
//        libvlc_MediaSubItemAdded
//        libvlc_MediaDurationChanged
//        libvlc_MediaParsedChanged
//        libvlc_MediaFreed
//        libvlc_MediaStateChanged
//        libvlc_MediaPlayerMediaChanged
//        libvlc_MediaPlayerNothingSpecial
//        libvlc_MediaPlayerOpening
//        libvlc_MediaPlayerBuffering
//        libvlc_MediaPlayerPlaying
//        libvlc_MediaPlayerPaused
//        libvlc_MediaPlayerStopped
//        libvlc_MediaPlayerForward
//        libvlc_MediaPlayerBackward
//        libvlc_MediaPlayerEndReached
//        libvlc_MediaPlayerEncounteredError
//        libvlc_MediaPlayerTimeChanged
//        libvlc_MediaPlayerPositionChanged
//        libvlc_MediaPlayerSeekableChanged
//        libvlc_MediaPlayerPausableChanged
//        libvlc_MediaPlayerTitleChanged
//        libvlc_MediaPlayerSnapshotTaken
//        libvlc_MediaPlayerLengthChanged
//        libvlc_MediaPlayerVout
//        libvlc_MediaListItemAdded
//        libvlc_MediaListWillAddItem
//        libvlc_MediaListItemDeleted
//        libvlc_MediaListWillDeleteItem
//        libvlc_MediaListViewItemAdded
//        libvlc_MediaListViewWillAddItem
//        libvlc_MediaListViewItemDeleted
//        libvlc_MediaListViewWillDeleteItem
//        libvlc_MediaListPlayerPlayed
//        libvlc_MediaListPlayerNextItemSet
//        libvlc_MediaListPlayerStopped
//        libvlc_MediaDiscovererStarted
//        libvlc_MediaDiscovererEnded
//        libvlc_VlmMediaAdded
//        libvlc_VlmMediaRemoved
//        libvlc_VlmMediaChanged
//        libvlc_VlmMediaInstanceStarted
//        libvlc_VlmMediaInstanceStopped
//        libvlc_VlmMediaInstanceStatusInit
//        libvlc_VlmMediaInstanceStatusOpening
//        libvlc_VlmMediaInstanceStatusPlaying
//        libvlc_VlmMediaInstanceStatusPause
//        libvlc_VlmMediaInstanceStatusEnd
//        libvlc_VlmMediaInstanceStatusError

//        break;
//    case libvlc_MediaPlayerVout:
//        emit core->vout();
//        break;
//    default:
//        break;
//    }
//}

}


/*

Typedefs

typedef struct
libvlc_event_manager_t 	libvlc_event_manager_t
        Event manager that belongs to a libvlc object, and from whom events can be received.
typedef int 	libvlc_event_type_t
        Type of a LibVLC event.
typedef void(* 	libvlc_callback_t )(const struct libvlc_event_t *, void *)
        Callback function notification.
Functions

int 	libvlc_event_attach (libvlc_event_manager_t *p_event_manager, libvlc_event_type_t i_event_type, libvlc_callback_t f_callback, void *user_data)
        Register for an event notification.
void 	libvlc_event_detach (libvlc_event_manager_t *p_event_manager, libvlc_event_type_t i_event_type, libvlc_callback_t f_callback, void *p_user_data)
        Unregister an event notification.
const char * 	libvlc_event_type_name (libvlc_event_type_t event_type)
        Get an event's type name.



enum  	libvlc_event_e {
  libvlc_MediaMetaChanged = 0, libvlc_MediaSubItemAdded, libvlc_MediaDurationChanged, libvlc_MediaParsedChanged,
  libvlc_MediaFreed, libvlc_MediaStateChanged, libvlc_MediaPlayerMediaChanged = 0x100, libvlc_MediaPlayerNothingSpecial,
  libvlc_MediaPlayerOpening, libvlc_MediaPlayerBuffering, libvlc_MediaPlayerPlaying, libvlc_MediaPlayerPaused,
  libvlc_MediaPlayerStopped, libvlc_MediaPlayerForward, libvlc_MediaPlayerBackward, libvlc_MediaPlayerEndReached,
  libvlc_MediaPlayerEncounteredError, libvlc_MediaPlayerTimeChanged, libvlc_MediaPlayerPositionChanged, libvlc_MediaPlayerSeekableChanged,
  libvlc_MediaPlayerPausableChanged, libvlc_MediaPlayerTitleChanged, libvlc_MediaPlayerSnapshotTaken, libvlc_MediaPlayerLengthChanged,
  libvlc_MediaListItemAdded = 0x200, libvlc_MediaListWillAddItem, libvlc_MediaListItemDeleted, libvlc_MediaListWillDeleteItem,
  libvlc_MediaListViewItemAdded = 0x300, libvlc_MediaListViewWillAddItem, libvlc_MediaListViewItemDeleted, libvlc_MediaListViewWillDeleteItem,
  libvlc_MediaListPlayerPlayed = 0x400, libvlc_MediaListPlayerNextItemSet, libvlc_MediaListPlayerStopped, libvlc_MediaDiscovererStarted = 0x500,
  libvlc_MediaDiscovererEnded, libvlc_VlmMediaAdded = 0x600, libvlc_VlmMediaRemoved, libvlc_VlmMediaChanged,
  libvlc_VlmMediaInstanceStarted, libvlc_VlmMediaInstanceStopped, libvlc_VlmMediaInstanceStatusInit, libvlc_VlmMediaInstanceStatusOpening,
  libvlc_VlmMediaInstanceStatusPlaying, libvlc_VlmMediaInstanceStatusPause, libvlc_VlmMediaInstanceStatusEnd, libvlc_VlmMediaInstanceStatusError
}

Event types.

More...
typedef struct libvlc_event_t 	libvlc_event_t
        A LibVLC event.
  */

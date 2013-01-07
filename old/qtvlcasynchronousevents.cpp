#include "qtvlcasynchronousevents.h"

using namespace QtVlc;

AsynchronousEvents::AsynchronousEvents(QObject *parent) :
    QObject(parent)
{
}

AsynchronousEvents::~AsynchronousEvents()
{
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

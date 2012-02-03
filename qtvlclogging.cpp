#include "qtvlclogging.h"

using namespace QtVlc;

Logging::Logging(QObject *parent) :
    QObject(parent)
{
}

Logging::~Logging()
{
}

/*
Functions

unsigned 	libvlc_get_log_verbosity (const libvlc_instance_t *p_instance)
        Return the VLC messaging verbosity level.
void 	libvlc_set_log_verbosity (libvlc_instance_t *p_instance, unsigned level)
        Set the VLC messaging verbosity level.
libvlc_log_t * 	libvlc_log_open (libvlc_instance_t *p_instance)
        Open a VLC message log instance.
void 	libvlc_log_close (libvlc_log_t *p_log)
        Close a VLC message log instance.
unsigned 	libvlc_log_count (const libvlc_log_t *p_log)
        Returns the number of messages in a log instance.
void 	libvlc_log_clear (libvlc_log_t *p_log)
        Clear a log instance.
libvlc_log_iterator_t * 	libvlc_log_get_iterator (const libvlc_log_t *p_log)
        Allocate and returns a new iterator to messages in log.
void 	libvlc_log_iterator_free (libvlc_log_iterator_t *p_iter)
        Release a previoulsy allocated iterator.
int 	libvlc_log_iterator_has_next (const libvlc_log_iterator_t *p_iter)
        Return whether log iterator has more messages.
libvlc_log_message_t * 	libvlc_log_iterator_next (libvlc_log_iterator_t *p_iter, libvlc_log_message_t *p_buffer)
        Return the next log message.



typedef struct libvlc_log_t 	libvlc_log_t
        This structure is opaque.
typedef struct
libvlc_log_iterator_t 	libvlc_log_iterator_t
        This structure is opaque.
typedef struct libvlc_log_message_t 	libvlc_log_message_t
  */

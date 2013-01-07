#include "logging.h"

#include <vlc/vlc.h>
#include <vlc/libvlc.h>

namespace RoxeePlayer{

Logging::Logging(QObject *parent) :
    QObject(parent)
{
    libvlc_log_subscriber_t * sub;
    void * data;
    libvlc_log_subscribe(sub, this->LogCb, data);
//    void libvlc_log_subscribe	(	libvlc_log_subscriber_t * 	sub,
//    libvlc_log_cb 	cb,
//    void * 	data
//    )
//    Registers a logging callback to LibVLC.

//    This function is thread-safe.

//    Parameters:
//    sub 	uninitialized subscriber structure
//    cb 	callback function pointer
//    data 	opaque data pointer for the callback function
//    Note:
//    Some log messages (especially debug) are emitted by LibVLC while initializing, before any LibVLC instance even exists. Thus this function does not require a LibVLC instance parameter.
//    Warning:
//    As a consequence of not depending on a LibVLC instance, all logging callbacks are shared by all LibVLC instances within the process / address space. This also enables log messages to be emitted by LibVLC components that are not specific to any given LibVLC instance.
//    Do not call this function from within a logging callback. It would trigger a dead lock.

}

//typedef void(* libvlc_log_cb)(void *data, int level, const char *fmt, va_list args)

void Logging::LogCb(void * data, int level, const char *fmt, va_list args)
{
    qDebug() << "SHIT ***********************";
    qDebug() << level;
    qDebug() << fmt;
}



Logging::~Logging()
{
}

//uint Logging::getVerbosity()
//{
//    //    unsigned 	libvlc_get_log_verbosity (const libvlc_instance_t *p_instance)
//    //        Always returns minus one.
//    return libvlc_get_log_verbosity(LRPCoreInstance::instance()->getSession());

//}

//void Logging::setVerbosity(uint level)
//{
//    //    void 	libvlc_set_log_verbosity (libvlc_instance_t *p_instance, unsigned level)
//    //        This function does nothing.
//    return libvlc_set_log_verbosity(LRPCoreInstance::instance()->getSession(), level);
//}


}


/*

Data Structures

struct  	libvlc_log_subscriber
    Data structure for a LibVLC logging callbacks. More...
Typedefs

typedef void(* 	libvlc_log_cb )(void *data, int level, const char *fmt, va_list args)
    Callback prototype for LibVLC log message handler.
typedef struct
libvlc_log_subscriber 	libvlc_log_subscriber_t
    Data structure for a LibVLC logging callbacks.
Enumerations

Logging messages level.

More...
Functions

void 	libvlc_log_subscribe (libvlc_log_subscriber_t *sub, libvlc_log_cb cb, void *data)
    Registers a logging callback to LibVLC.
void 	libvlc_log_subscribe_file (libvlc_log_subscriber_t *sub, FILE *stream)
    Registers a logging callback to a file.
void 	libvlc_log_unsubscribe (libvlc_log_subscriber_t *sub)
    Deregisters a logging callback from LibVLC.
libvlc_log_t * 	libvlc_log_open (libvlc_instance_t *p_instance)
    This function does nothing useful.
void 	libvlc_log_close (libvlc_log_t *p_log)
    Frees memory allocated by libvlc_log_open().
unsigned 	libvlc_log_count (const libvlc_log_t *p_log)
    Always returns zero.
void 	libvlc_log_clear (libvlc_log_t *p_log)
    This function does nothing.
libvlc_log_iterator_t * 	libvlc_log_get_iterator (const libvlc_log_t *p_log)
    This function does nothing useful.
void 	libvlc_log_iterator_free (libvlc_log_iterator_t *p_iter)
    Frees memory allocated by libvlc_log_get_iterator().
int 	libvlc_log_iterator_has_next (const libvlc_log_iterator_t *p_iter)
    Always returns zero.
libvlc_log_message_t * 	libvlc_log_iterator_next (libvlc_log_iterator_t *p_iter, libvlc_log_message_t *p_buffer)
    Always returns NULL.



typedef struct libvlc_log_t 	libvlc_log_t
    This structure is opaque.
typedef struct
libvlc_log_iterator_t 	libvlc_log_iterator_t
    This structure is opaque.
typedef struct libvlc_log_message_t 	libvlc_log_message_t
  */

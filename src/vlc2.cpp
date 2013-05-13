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

#include <vlc/vlc.h>
#include "libroxeeplayer/vlc2.h"
//#include <QDebug>

/*! \cond */

namespace RoxeePlayer{

struct RoxeeVLC::CheshireCatInstance {
    libvlc_instance_t * instance;
    libvlc_media_player_t * player;

    static void libvlc_callback(const libvlc_event_t *p_event, void * p_user_data)
    {
        RoxeeVLC * p_rox = (RoxeeVLC *) p_user_data;
        emit p_rox->notify(libvlc_event_type_name(p_event->type));

        //        char * toto = p_event->type;
//        emit notify(p_event->type);
    //    static int i_first_time_media_player_time_changed = 0;
    //    static bool b_media_player_title_changed = false;

    //    VLCMediaObject *p_vlc_mediaObject = (VLCMediaObject *) p_user_data;
    }

};

RoxeeVLC::RoxeeVLC( QObject * parent)
    : QObject(parent), smile(new CheshireCatInstance()) {
//    qDebug() << " [RoxeeLibVLC] Cat layer: constructing";
    const char * const vlcArgs[] = {
        "-I", "dummy", /* Don't use any interface */
        "--ignore-config", /* Don't use VLC's config */
        //    "--extraintf=logger", /* Log everything */
        //    "--verbose=2", /* Be much more verbose then normal for debugging purpose */
        "--no-osd"
    };

    if((smile->instance = libvlc_new(sizeof(vlcArgs) / sizeof(*vlcArgs), vlcArgs)) == NULL) {
        // Do we ever reach here or do we simply throw?
//        qDebug() << QString::fromLatin1("Could not init libVLC");
    }
//    qDebug() << " [RoxeeLibVLC] Cat layer using VLC " << this->get_version();
}

RoxeeVLC::~RoxeeVLC(){
//    qDebug() << " [RoxeeLibVLC] Cat layer: destructing";
    if(smile->player){
        libvlc_media_player_release(smile->player);
        smile->player = 0;
    }
    if(smile->instance){
        libvlc_release(smile->instance);
        smile->instance = 0;
    }
    delete smile;
}

// XXX retain / release?
RoxeeVLC::RoxeeVLC(const RoxeeVLC& other)
    : QObject(), smile(new CheshireCatInstance(*(other.smile))) {
    // do nothing
//    qDebug() << " [RoxeeLibVLC] Cat layer: copy constructor";
}

RoxeeVLC& RoxeeVLC::operator=(const RoxeeVLC &other) {
//    qDebug() << " [RoxeeLibVLC] Cat layer: copy assignment";
    *smile = *(other.smile);
    return* this;
}

/**
 * Returns a new Cat instance, sharing the same vlc instance and possible media player (until new_player is called)
 * @brief RoxeeVLC::Carroll
 */
RoxeeVLC * RoxeeVLC::Carroll(){
    RoxeeVLC * cat;
//    qDebug() << " [RoxeeLibVLC] Cat layer: carroll";
    cat = this;
    libvlc_retain(smile->instance);
    if(smile->player)
        libvlc_media_player_retain(smile->player);
    return cat;
}

//libvlc_instance_t * 	libvlc_new (int argc, const char *const *argv)
// 	Create and initialize a libvlc instance.
//void 	libvlc_release (libvlc_instance_t *p_instance)
// 	Decrement the reference count of a libvlc instance, and destroy it if it reaches zero.
//void 	libvlc_retain (libvlc_instance_t *p_instance)
// 	Increments the reference count of a libvlc instance.
//int 	libvlc_add_intf (libvlc_instance_t *p_instance, const char *name)
// 	Try to start a user interface for the libvlc instance.
//void 	libvlc_set_exit_handler (libvlc_instance_t *p_instance, void(*cb)(void *), void *opaque)
// 	Registers a callback for the LibVLC exit event.
//void 	libvlc_wait (libvlc_instance_t *p_instance)
// 	Waits until an interface causes the instance to exit.
//void 	libvlc_set_user_agent (libvlc_instance_t *p_instance, const char *name, const char *http)
// 	Sets the application name.
void RoxeeVLC::set_user_agent(const QString &appOutput, const QString &httpOutput)
{
//    void 	libvlc_set_user_agent (libvlc_instance_t *p_instance, const char *name, const char *http)
    libvlc_set_user_agent(smile->instance, appOutput.toLocal8Bit(), httpOutput.toLocal8Bit());
}

//const char * 	libvlc_get_version (void)
// 	Retrieve libvlc version.
const QString RoxeeVLC::get_version()
{
    return QString(libvlc_get_version());
}

//const char * 	libvlc_get_compiler (void)
// 	Retrieve libvlc compiler version.
const QString RoxeeVLC::get_compiler()
{
//    const char * 	libvlc_get_compiler (void)
//            Retrieve libvlc compiler version.
    return QString(libvlc_get_compiler());
}

//const char * 	libvlc_get_changeset (void)
// 	Retrieve libvlc changeset.
const QString RoxeeVLC::get_changeset()
{
    return QString(libvlc_get_changeset());
}

//void 	libvlc_free (void *ptr)
// 	Frees an heap allocation returned by a LibVLC function.
//void 	libvlc_module_description_list_release (libvlc_module_description_t *p_list)
// 	Release a list of module descriptions.
//libvlc_module_description_t * 	libvlc_audio_filter_list_get (libvlc_instance_t *p_instance)
// 	Returns a list of audio filters that are available.
/**
 * Instance generic stuff
 */

QStringList RoxeeVLC::audio_filter_list_get()
{
//    void 	libvlc_module_description_list_release (libvlc_module_description_t *p_list)
//        Release a list of module descriptions.
//    libvlc_module_description_t * 	libvlc_audio_filter_list_get (libvlc_instance_t *p_instance)
//        Returns a list of audio filters that are available.
    QStringList l = QStringList();
    libvlc_module_description_t * md = libvlc_audio_filter_list_get(smile->instance);
    do{
        l.append(QString().fromLocal8Bit(md->psz_name));
        l.append(QString().fromLocal8Bit(md->psz_shortname));
        l.append(QString().fromLocal8Bit(md->psz_longname));
        l.append(QString().fromLocal8Bit(md->psz_help));
        md = md->p_next;
    }while(md);
    libvlc_module_description_list_release(md);
    return l;
}

//libvlc_module_description_t * 	libvlc_video_filter_list_get (libvlc_instance_t *p_instance)
// 	Returns a list of video filters that are available.
QStringList RoxeeVLC::video_filter_list_get()
{
//    void 	libvlc_module_description_list_release (libvlc_module_description_t *p_list)
//        Release a list of module descriptions.
//    libvlc_module_description_t * 	libvlc_video_filter_list_get (libvlc_instance_t *p_instance)
//        Returns a list of video filters that are available.
    QStringList l = QStringList();
    libvlc_module_description_t * md = libvlc_video_filter_list_get(smile->instance);
    do{
        l.append(QString().fromLocal8Bit(md->psz_name));
        l.append(QString().fromLocal8Bit(md->psz_shortname));
        l.append(QString().fromLocal8Bit(md->psz_longname));
        l.append(QString().fromLocal8Bit(md->psz_help));
        md = md->p_next;
    }while(md);
    libvlc_module_description_list_release(md);
    return l;
}

/**
 * Audio Controls
 */

//LIBVLC_API void 	libvlc_audio_toggle_mute (libvlc_media_player_t *p_mi)
// 	Toggle mute status.
void RoxeeVLC::audio_toggle_mute()
{
    libvlc_audio_toggle_mute(smile->player);
}

//LIBVLC_API int 	libvlc_audio_get_mute (libvlc_media_player_t *p_mi)
// 	Get current mute status.
bool RoxeeVLC::audio_get_mute()
{
    return libvlc_audio_get_mute (smile->player);
}

//LIBVLC_API void 	libvlc_audio_set_mute (libvlc_media_player_t *p_mi, int status)
// 	Set mute status.
void RoxeeVLC::audio_set_mute(const bool status)
{
    libvlc_audio_set_mute (smile->player, status);
}

//LIBVLC_API int 	libvlc_audio_get_volume (libvlc_media_player_t *p_mi)
// 	Get current software audio volume.
int RoxeeVLC::audio_get_volume()
{
    return libvlc_audio_get_volume(smile->player);
}

//LIBVLC_API int 	libvlc_audio_set_volume (libvlc_media_player_t *p_mi, int i_volume)
// 	Set current software audio volume.
void RoxeeVLC::audio_set_volume(const int vol)
{
    libvlc_audio_set_volume(smile->player, vol);
}

//LIBVLC_API int 	libvlc_audio_get_track_count (libvlc_media_player_t *p_mi)
// 	Get number of available audio tracks.
int RoxeeVLC::audio_get_track_count()
{
    return libvlc_audio_get_track_count (smile->player);
}

//LIBVLC_API
//libvlc_track_description_t * 	libvlc_audio_get_track_description (libvlc_media_player_t *p_mi)
// 	Get the description of available audio tracks.
QStringList RoxeeVLC::audio_get_track_description()
{
    QStringList l = QStringList();
    libvlc_track_description_t * td = libvlc_audio_get_track_description (smile->player);
    if(td){
        do{
            l.append(QString().fromLocal8Bit(td->psz_name));
            td = td->p_next;
        }while(td);
    }
    return l;
}

//LIBVLC_API int 	libvlc_audio_get_track (libvlc_media_player_t *p_mi)
// 	Get current audio track.
int RoxeeVLC::audio_get_track()
{
    return libvlc_audio_get_track ( smile->player );
}

//LIBVLC_API int 	libvlc_audio_set_track (libvlc_media_player_t *p_mi, int i_track)
// 	Set current audio track.
void RoxeeVLC::audio_set_track(const int i)
{
    libvlc_audio_set_track ( smile->player, i );
}

//LIBVLC_API libvlc_audio_output_t * 	libvlc_audio_output_list_get (libvlc_instance_t *p_instance)
// 	Gets the list of available audio outputs.
//LIBVLC_API void 	libvlc_audio_output_list_release (libvlc_audio_output_t *p_list)
// 	Frees the list of available audio outputs.
QStringList RoxeeVLC::audio_output_list_get()
{
    libvlc_audio_output_t * md = libvlc_audio_output_list_get ( smile->instance );
    QStringList l = QStringList();
    do{
        l.append(QString().fromLocal8Bit(md->psz_name));
        l.append(QString().fromLocal8Bit(md->psz_description));
        md = md->p_next;
    }while(md);
    libvlc_audio_output_list_release(md);
    return l;
}

//LIBVLC_API
//libvlc_audio_output_device_t * 	libvlc_audio_output_device_list_get (libvlc_instance_t *p_instance, const char *aout)
// 	Gets a list of audio output devices for a given audio output.
//LIBVLC_API void 	libvlc_audio_output_device_list_release (libvlc_audio_output_device_t *p_list)
// 	Frees a list of available audio output devices.
QStringList RoxeeVLC::audio_output_device_list_get(const QString & /*outd*/)
{
//    const char * out = outd.toLocal8Bit();
//    libvlc_audio_output_t * md = libvlc_audio_output_device_list_get ( smile->instance, out);
    QStringList l = QStringList();
//    do{
//        l.append(QString().fromLocal8Bit(md->psz_device));
//        l.append(QString().fromLocal8Bit(md->psz_description));
//        md = md->p_next;
//    }while(md);
//    libvlc_audio_output_device_list_release(md);
    return l;
}

//LIBVLC_API int 	libvlc_audio_output_set (libvlc_media_player_t *p_mi, const char *psz_name)
// 	Sets the audio output.
void RoxeeVLC::audio_output_set(const QString & outd)
{
    const char * out = outd.toLocal8Bit();
    libvlc_audio_output_set (smile->player, out);
}


//LIBVLC_API void 	libvlc_audio_output_device_set (libvlc_media_player_t *p_mi, const char *psz_audio_output, const char *psz_device_id)
// 	Configures an explicit audio output device for a given audio output plugin.
void RoxeeVLC::audio_output_device_set(const QString & /*outd*/)
{
//    const char * out = outd.toLocal8Bit();
//    libvlc_audio_output_device_set (smile->player, out);
}








//LIBVLC_API int 	libvlc_audio_get_channel (libvlc_media_player_t *p_mi)
// 	Get current audio channel.
//LIBVLC_API int 	libvlc_audio_set_channel (libvlc_media_player_t *p_mi, int channel)
// 	Set current audio channel.
//LIBVLC_API int64_t 	libvlc_audio_get_delay (libvlc_media_player_t *p_mi)
// 	Get current audio delay.
//LIBVLC_API int 	libvlc_audio_set_delay (libvlc_media_player_t *p_mi, int64_t i_delay)
// 	Set current audio delay.












/**
 * Video Controls
 */

//LIBVLC_API void 	libvlc_toggle_fullscreen (libvlc_media_player_t *p_mi)
// 	Toggle fullscreen status on non-embedded video outputs.
void RoxeeVLC::toggle_fullscreen()
{
    libvlc_toggle_fullscreen(smile->player);
}

//LIBVLC_API void 	libvlc_set_fullscreen (libvlc_media_player_t *p_mi, int b_fullscreen)
// 	Enable or disable fullscreen.
void RoxeeVLC::set_fullscreen(const bool on)
{
    libvlc_set_fullscreen(smile->player, on);
}

//LIBVLC_API int 	libvlc_get_fullscreen (libvlc_media_player_t *p_mi)
// 	Get current fullscreen status.
bool RoxeeVLC::get_fullscreen()
{
    return libvlc_get_fullscreen(smile->player);
}

//LIBVLC_API void 	libvlc_video_set_key_input (libvlc_media_player_t *p_mi, unsigned on)
// 	Enable or disable key press events handling, according to the LibVLC hotkeys configuration.
void RoxeeVLC::video_set_key_input(const bool on )
{
    libvlc_video_set_key_input (smile->player, on);
}

//LIBVLC_API void 	libvlc_video_set_mouse_input (libvlc_media_player_t *p_mi, unsigned on)
// 	Enable or disable mouse click events handling.
void RoxeeVLC::video_set_mouse_input(const bool on)
{
    libvlc_video_set_mouse_input (smile->player, on);
}

//LIBVLC_API int 	libvlc_video_get_size (libvlc_media_player_t *p_mi, unsigned num, unsigned *px, unsigned *py)
// 	Get the pixel dimensions of a video.
uint RoxeeVLC::video_get_width(int t)
{
    uint px = 0;
    uint py = 0;
    libvlc_video_get_size(smile->player, t, & px, & py);
    return px;
}

uint RoxeeVLC::video_get_height(int t)
{
    uint px = 0;
    uint py = 0;
    libvlc_video_get_size(smile->player, t, & px, & py);
    return py;
}

//LIBVLC_API int 	libvlc_video_get_cursor (libvlc_media_player_t *p_mi, unsigned num, int *px, int *py)
// 	Get the mouse pointer coordinates over a video.
//int RoxeeVLC::libvlc_video_get_cursor_x()
//{
//    return 0;
//}

//int RoxeeVLC::libvlc_video_get_cursor_y()
//{
//    return 0;
//}

//LIBVLC_API float 	libvlc_video_get_scale (libvlc_media_player_t *p_mi)
// 	Get the current video scaling factor.
float RoxeeVLC::video_get_scale()
{
    return libvlc_video_get_scale(smile->player);
}

//LIBVLC_API void 	libvlc_video_set_scale (libvlc_media_player_t *p_mi, float f_factor)
// 	Set the video scaling factor.
void RoxeeVLC::video_set_scale(const float factor)
{
    libvlc_video_set_scale(smile->player, factor);
}

//LIBVLC_API char * 	libvlc_video_get_aspect_ratio (libvlc_media_player_t *p_mi)
// 	Get current video aspect ratio.
QString RoxeeVLC::video_get_aspect_ratio()
{
    return QString(libvlc_video_get_aspect_ratio(smile->player));
}

//LIBVLC_API void 	libvlc_video_set_aspect_ratio (libvlc_media_player_t *p_mi, const char *psz_aspect)
// 	Set new video aspect ratio.
void RoxeeVLC::video_set_aspect_ratio(const QString &ar)
{
    libvlc_video_set_aspect_ratio (smile->player, ar.toLocal8Bit());
}

//LIBVLC_API int 	libvlc_video_get_spu (libvlc_media_player_t *p_mi)
// 	Get current video subtitle.
int RoxeeVLC::video_get_spu()
{
    return libvlc_video_get_spu(smile->player);
}

//LIBVLC_API int 	libvlc_video_get_spu_count (libvlc_media_player_t *p_mi)
// 	Get the number of available video subtitles.
int RoxeeVLC::video_get_spu_count()
{
    return libvlc_video_get_spu_count(smile->player);
}

//LIBVLC_API
//libvlc_track_description_t * 	libvlc_video_get_spu_description (libvlc_media_player_t *p_mi)
// 	Get the description of available video subtitles.
QStringList RoxeeVLC::video_get_spu_description()
{
    QStringList l = QStringList();
    libvlc_track_description_t * td = libvlc_video_get_spu_description (smile->player);
    if(td){
        do{
            l.append(QString().fromLocal8Bit(td->psz_name));
            td = td->p_next;
        }while(td->p_next);
    }
    return l;
}

//LIBVLC_API int 	libvlc_video_set_spu (libvlc_media_player_t *p_mi, unsigned i_spu)
// 	Set new video subtitle.
void RoxeeVLC::video_set_spu(uint i)
{
    libvlc_video_set_spu(smile->player, i);
}

//LIBVLC_API int 	libvlc_video_set_subtitle_file (libvlc_media_player_t *p_mi, const char *psz_subtitle)
// 	Set new video subtitle file.
void RoxeeVLC::video_set_subtitle_file(const QString &path)
{
    libvlc_video_set_subtitle_file(smile->player, path.toLocal8Bit());
}

//LIBVLC_API int64_t 	libvlc_video_get_spu_delay (libvlc_media_player_t *p_mi)
// 	Get the current subtitle delay.
int RoxeeVLC::video_get_spu_delay()
{
    return libvlc_video_get_spu_delay(smile->player);
}

//LIBVLC_API int 	libvlc_video_set_spu_delay (libvlc_media_player_t *p_mi, int64_t i_delay)
// 	Set the subtitle delay.
void RoxeeVLC::video_set_spu_delay(const int & i)
{
    libvlc_video_set_spu_delay(smile->player, i);
}

//LIBVLC_API
//libvlc_track_description_t * 	libvlc_video_get_title_description (libvlc_media_player_t *p_mi)
// 	Get the description of available titles.

//QStringList* RoxeeVLC::video_get_description()
//{
//    return new QStringList();
////        Get the description of available titles.
////    libvlc_track_description_t * t = libvlc_video_get_description(smile->player);
//}

//LIBVLC_API
//libvlc_track_description_t * 	libvlc_video_get_chapter_description (libvlc_media_player_t *p_mi, int i_title)
// 	Get the description of available chapters for specific title.
//QStringList* RoxeeVLC::video_get_chapter_description(int i)
//{
////        Get the description of available chapters for specific title.
//    libvlc_track_description_t * t = libvlc_video_get_chapter_description (smile->player, i);
//    return new QStringList();
//}

//LIBVLC_API char * 	libvlc_video_get_crop_geometry (libvlc_media_player_t *p_mi)
// 	Get current crop filter geometry.
QString RoxeeVLC::video_get_crop_geometry()
{
    return QString(libvlc_video_get_crop_geometry(smile->player));
}

//LIBVLC_API void 	libvlc_video_set_crop_geometry (libvlc_media_player_t *p_mi, const char *psz_geometry)
// 	Set new crop filter geometry.
void RoxeeVLC::video_set_crop_geometry(const QString &crop)
{
    libvlc_video_set_crop_geometry (smile->player, crop.toLocal8Bit());
}

//LIBVLC_API int 	libvlc_video_get_teletext (libvlc_media_player_t *p_mi)
// 	Get current teletext page requested.
int RoxeeVLC::video_get_teletext()
{
    return libvlc_video_get_teletext(smile->player);
}

//LIBVLC_API void 	libvlc_video_set_teletext (libvlc_media_player_t *p_mi, int i_page)
// 	Set new teletext page to retrieve.
void RoxeeVLC::video_set_teletext(const int & i)
{
    libvlc_video_set_teletext(smile->player, i);
}

//LIBVLC_API void 	libvlc_toggle_teletext (libvlc_media_player_t *p_mi)
// 	Toggle teletext transparent status on video output.
void RoxeeVLC::toggle_teletext()
{
//LIBVLC_API void 	libvlc_toggle_teletext (libvlc_media_player_t *smile->player)
//        Toggle teletext transparent status on video output.
     libvlc_toggle_teletext(smile->player);
}

//LIBVLC_API int 	libvlc_video_get_track_count (libvlc_media_player_t *p_mi)
// 	Get number of available video tracks.
int RoxeeVLC::video_get_track_count()
{
    return libvlc_video_get_track_count(smile->player);
}

//LIBVLC_API
//libvlc_track_description_t * 	libvlc_video_get_track_description (libvlc_media_player_t *p_mi)
// 	Get the description of available video tracks.
QStringList RoxeeVLC::video_get_track_description()
{
    QStringList l = QStringList();
    libvlc_track_description_t * td = libvlc_video_get_track_description(smile->player);
    if(td){
        do{
            l.append(QString().fromLocal8Bit(td->psz_name));
            td = td->p_next;
        }while(td);
    }
    return l;
}

//LIBVLC_API int 	libvlc_video_get_track (libvlc_media_player_t *p_mi)
// 	Get current video track.
int RoxeeVLC::video_get_track()
{
    return libvlc_video_get_track (smile->player);
}

//LIBVLC_API int 	libvlc_video_set_track (libvlc_media_player_t *p_mi, int i_track)
// 	Set video track.
void RoxeeVLC::video_set_track(const int i)
{
    libvlc_video_set_track (smile->player, i);
}


void RoxeeVLC::video_take_snapshot(const int i, const QString & path)
{
    const char * psz_filepath = path.toLocal8Bit();
    libvlc_video_take_snapshot(smile->player, i, psz_filepath, 0, 100);
}



//LIBVLC_API int
// 	Take a snapshot of the current video window.
//LIBVLC_API void 	libvlc_video_set_deinterlace (libvlc_media_player_t *p_mi, const char *psz_mode)
// 	Enable or disable deinterlace filter.
//LIBVLC_API int 	libvlc_video_get_marquee_int (libvlc_media_player_t *p_mi, unsigned option)
// 	Get an integer marquee option value.
//LIBVLC_API char * 	libvlc_video_get_marquee_string (libvlc_media_player_t *p_mi, unsigned option)
// 	Get a string marquee option value.
//LIBVLC_API void 	libvlc_video_set_marquee_int (libvlc_media_player_t *p_mi, unsigned option, int i_val)
// 	Enable, disable or set an integer marquee option.
//LIBVLC_API void 	libvlc_video_set_marquee_string (libvlc_media_player_t *p_mi, unsigned option, const char *psz_text)
// 	Set a marquee string option.
//LIBVLC_API int 	libvlc_video_get_logo_int (libvlc_media_player_t *p_mi, unsigned option)
// 	Get integer logo option.
//LIBVLC_API void 	libvlc_video_set_logo_int (libvlc_media_player_t *p_mi, unsigned option, int value)
// 	Set logo option as integer.
//LIBVLC_API void 	libvlc_video_set_logo_string (libvlc_media_player_t *p_mi, unsigned option, const char *psz_value)
// 	Set logo option as string.
//LIBVLC_API int 	libvlc_video_get_adjust_int (libvlc_media_player_t *p_mi, unsigned option)
// 	Get integer adjust option.
//LIBVLC_API void 	libvlc_video_set_adjust_int (libvlc_media_player_t *p_mi, unsigned option, int value)
// 	Set adjust option as integer.
//LIBVLC_API float 	libvlc_video_get_adjust_float (libvlc_media_player_t *p_mi, unsigned option)
// 	Get float adjust option.
//LIBVLC_API void 	libvlc_video_set_adjust_float (libvlc_media_player_t *p_mi, unsigned option, float value)
// 	Set adjust option as float.


/**
 * Media Player
 */

//LIBVLC_API libvlc_media_player_t * 	libvlc_media_player_new (libvlc_instance_t *p_libvlc_instance)
// 	Create an empty Media Player object.

void RoxeeVLC::media_player_new(){
//    qDebug() << " [RoxeeLibVLC] Cat layer: media_player_new";
    if(smile->player)
        libvlc_media_player_release(smile->player);
    smile->player = libvlc_media_player_new(smile->instance);

    libvlc_event_manager_t * p_event_manager = libvlc_media_player_event_manager(smile->player);

    libvlc_event_type_t eventsMediaPlayer[] = {
        libvlc_MediaPlayerPlaying,
        libvlc_MediaPlayerPaused,
        libvlc_MediaPlayerEndReached,
        libvlc_MediaPlayerStopped,
        libvlc_MediaPlayerEncounteredError,
        libvlc_MediaPlayerTimeChanged,
        libvlc_MediaPlayerTitleChanged,
        libvlc_MediaPlayerPositionChanged,
        libvlc_MediaPlayerSeekableChanged,
        libvlc_MediaPlayerPausableChanged,

        libvlc_MediaPlayerMediaChanged,
        libvlc_MediaPlayerNothingSpecial,
        libvlc_MediaPlayerOpening,
        libvlc_MediaPlayerBuffering,
        libvlc_MediaPlayerForward,
        libvlc_MediaPlayerBackward,
        libvlc_MediaPlayerSnapshotTaken,
        libvlc_MediaPlayerLengthChanged,
        libvlc_MediaPlayerVout
    };

//    libvlc_MediaMetaChanged,
//    libvlc_MediaSubItemAdded,
//    libvlc_MediaDurationChanged,
//    libvlc_MediaParsedChanged,
//    libvlc_MediaFreed,
//    libvlc_MediaStateChanged,
//    libvlc_MediaListItemAdded,
//    libvlc_MediaListWillAddItem,
//    libvlc_MediaListItemDeleted,
//    libvlc_MediaListWillDeleteItem,
//    libvlc_MediaListViewItemAdded,
//    libvlc_MediaListViewWillAddItem,
//    libvlc_MediaListViewItemDeleted,
//    libvlc_MediaListViewWillDeleteItem,
//    libvlc_MediaListPlayerPlayed,
//    libvlc_MediaListPlayerNextItemSet,
//    libvlc_MediaListPlayerStopped,
//    libvlc_MediaDiscovererStarted,
//    libvlc_MediaDiscovererEnded,
//    libvlc_VlmMediaAdded,
//    libvlc_VlmMediaRemoved,
//    libvlc_VlmMediaChanged,
//    libvlc_VlmMediaInstanceStarted,
//    libvlc_VlmMediaInstanceStopped,
//    libvlc_VlmMediaInstanceStatusInit,
//    libvlc_VlmMediaInstanceStatusOpening,
//    libvlc_VlmMediaInstanceStatusPlaying,
//    libvlc_VlmMediaInstanceStatusPause,
//    libvlc_VlmMediaInstanceStatusEnd,
//    libvlc_VlmMediaInstanceStatusError
//    };




////Media
//p_vlc_media_event_manager = libvlc_media_event_manager( p_vlc_media, p_vlc_exception );
//libvlc_event_type_t eventsMedia[] = {
//    libvlc_MediaMetaChanged,
//    libvlc_MediaSubItemAdded,
//    libvlc_MediaDurationChanged,
//    //FIXME libvlc does not know this event
//    //libvlc_MediaPreparsedChanged,
//    libvlc_MediaFreed,
//    libvlc_MediaStateChanged,
//};
//i_nbEvents = sizeof( eventsMedia ) / sizeof( *eventsMedia );
//for( int i = 0; i < i_nbEvents; i++ )
//{
//    libvlc_event_attach( p_vlc_media_event_manager, eventsMedia[i], libvlc_callback, this, p_vlc_exception );
//    checkException();
//}




//    libvlc_MediaMetaChanged = 0, libvlc_MediaSubItemAdded, libvlc_MediaDurationChanged, libvlc_MediaParsedChanged,
//    libvlc_MediaFreed, libvlc_MediaStateChanged, libvlc_MediaPlayerMediaChanged = 0x100, libvlc_MediaPlayerNothingSpecial,
//    libvlc_MediaPlayerOpening, libvlc_MediaPlayerBuffering, libvlc_MediaPlayerPlaying, libvlc_MediaPlayerPaused,
//    libvlc_MediaPlayerStopped, libvlc_MediaPlayerForward, libvlc_MediaPlayerBackward, libvlc_MediaPlayerEndReached,
//    libvlc_MediaPlayerEncounteredError, libvlc_MediaPlayerTimeChanged, libvlc_MediaPlayerPositionChanged, libvlc_MediaPlayerSeekableChanged,
//    libvlc_MediaPlayerPausableChanged, libvlc_MediaPlayerTitleChanged, libvlc_MediaPlayerSnapshotTaken, libvlc_MediaPlayerLengthChanged,
//    libvlc_MediaPlayerVout, libvlc_MediaListItemAdded = 0x200, libvlc_MediaListWillAddItem, libvlc_MediaListItemDeleted,
//    libvlc_MediaListWillDeleteItem, libvlc_MediaListViewItemAdded = 0x300, libvlc_MediaListViewWillAddItem, libvlc_MediaListViewItemDeleted,
//    libvlc_MediaListViewWillDeleteItem, libvlc_MediaListPlayerPlayed = 0x400, libvlc_MediaListPlayerNextItemSet, libvlc_MediaListPlayerStopped,
//    libvlc_MediaDiscovererStarted = 0x500, libvlc_MediaDiscovererEnded, libvlc_VlmMediaAdded = 0x600, libvlc_VlmMediaRemoved,
//    libvlc_VlmMediaChanged, libvlc_VlmMediaInstanceStarted, libvlc_VlmMediaInstanceStopped, libvlc_VlmMediaInstanceStatusInit,
//    libvlc_VlmMediaInstanceStatusOpening, libvlc_VlmMediaInstanceStatusPlaying, libvlc_VlmMediaInstanceStatusPause, libvlc_VlmMediaInstanceStatusEnd,
//    libvlc_VlmMediaInstanceStatusError

    int i_nbEvents = sizeof( eventsMediaPlayer ) / sizeof( *eventsMediaPlayer );
    for( int i = 0; i < i_nbEvents; i++ )
    {
        libvlc_event_attach( p_event_manager, eventsMediaPlayer[i],
                               smile->libvlc_callback, this );
//        checkException();
    }


    //Media
//    p_vlc_media_event_manager = libvlc_media_event_manager( p_vlc_media, p_vlc_exception );
//    libvlc_event_type_t eventsMedia[] = {
//        libvlc_MediaMetaChanged,
//        libvlc_MediaSubItemAdded,
//        libvlc_MediaDurationChanged,
//        //FIXME libvlc does not know this event
//        //libvlc_MediaPreparsedChanged,
//        libvlc_MediaFreed,
//        libvlc_MediaStateChanged,
//    };
//    i_nbEvents = sizeof( eventsMedia ) / sizeof( *eventsMedia );
//    for( int i = 0; i < i_nbEvents; i++ )
//    {
//        libvlc_event_attach( p_vlc_media_event_manager, eventsMedia[i], libvlc_callback, this, p_vlc_exception );
//        checkException();
//    }

    //    int libvlc_event_attach( p_event_manager, libvlc_event_type_t i_event_type, libvlc_callback_t f_callback, void * user_data);
}





//LIBVLC_API libvlc_media_player_t * 	libvlc_media_player_new_from_media (libvlc_media_t *p_md)
// 	Create a Media Player object from a Media.

//LIBVLC_API void 	libvlc_media_player_release (libvlc_media_player_t *p_mi)
// 	Release a media_player after use Decrement the reference count of a media player object.

//LIBVLC_API void 	libvlc_media_player_retain (libvlc_media_player_t *p_mi)
// 	Retain a reference to a media player object.

//LIBVLC_API void 	libvlc_media_player_set_media (libvlc_media_player_t *p_mi, libvlc_media_t *p_md)
// 	Set the media that will be used by the media_player.
void RoxeeVLC::media_player_set_media(const QString & path) {
//    qDebug() << " [RoxeeLibVLC] Cat layer: media_player_set_media " << path.toLocal8Bit();
    libvlc_media_player_set_media(smile->player, libvlc_media_new_path(smile->instance, path.toLocal8Bit()));
}

/**
 * Add a broadcast, with one input.
 *
 * \param p_instance the instance
 * \param psz_name the name of the new broadcast
 * \param psz_input the input MRL
 * \param psz_output the output MRL (the parameter to the "sout" variable)
 * \param i_options number of additional options
 * \param ppsz_options additional options
 * \param b_enabled boolean for enabling the new broadcast
 * \param b_loop Should this broadcast be played in loop ?
 * \return 0 on success, -1 on error
 */

bool RoxeeVLC::vlm_add_broadcast(const QString & broadcastName, const QString & path, const QString & args) {
    int err = libvlc_vlm_add_broadcast(
        smile->instance,
        broadcastName.toLocal8Bit(),
        path.toLocal8Bit(),
        // mp4a
        //
        // rtp{sdp=rtsp://:8080/}
//        "#transcode{vcodec=h264,vb=0,scale=0,acodec=mp4a,ab=56}:http{mux=ts,dst=:8080/}",
        args.toLocal8Bit(),
        0,
        NULL,
        1,
        0
    );
    if(err == -1)
        return false;
    return true;
}

/**
 * Play the named broadcast.
 *
 * \param p_instance the instance
 * \param psz_name the name of the broadcast
 * \return 0 on success, -1 on error
 */
bool RoxeeVLC::vlm_play_media(const QString & broadcastName) {
    int err = libvlc_vlm_play_media(smile->instance, broadcastName.toLocal8Bit());
    if(err == -1)
        return false;
    return true;
}

// http://www.videolan.org/doc/streaming-howto/en/ch04.html#id349864

    //    LIBVLC_API int libvlc_vlm_add_broadcast	(	libvlc_instance_t * 	p_instance,
    //    const char * 	psz_name,
    //    const char * 	psz_input,
    //    const char * 	psz_output,
    //    int 	i_options,
    //    const char *const * 	ppsz_options,
    //    int 	b_enabled,
    //    int 	b_loop
    //    )


//http://stackoverflow.com/questions/6449226/how-to-stream-from-vlc-linux-to-ipod-with-web-service-complete-process

    //#transcode{
//        vcodec=h264,venc=x264{
//            aud,profile=baseline,level=30,keyint=30,bframes=0,ref=1,nocabac
//        },
//        acodec=mp4a,ab=56,deinterlace
//    }:
//    duplicate{dst=std{access=file,mux=ts,dst=-}}

    // http://confluence.codewave.de/display/mytunesrss/Using+VLC+for+transcoding,+HTTP+live+streaming+and+remote+control

// "" -I rc dshow:// vdev="XSplitBroadcaster" adev="XSplitBroadcaster" size="1280x720"

//    --sout=#transcode{width=1280,height=720,fps=25,vcodec=h264,vb=256,venc=x264{aud,profile=baseline,level=30,keyint=30,ref=1},
//            acodec=mp3,ab=96,channels=2}:std{access=livehttp{seglen=10,delsegs=true,numsegs=5,index=C:\inetpub\wwwroot\stream\stream.m3u8,index-url=http://dennis/stream/stream-########.ts},
//            mux=ts{use-key-frames},dst=C:\inetpub\wwwroot\stream\stream-########.ts}


//    libvlc_vlm_add_broadcast(
//                smile->instance,
//                "raymon",
//                path.toLocal8Bit(),
//                // mp4a
//                //
//                // rtp{sdp=rtsp://:8080/}

//                "#transcode{vcodec=h264,vb=0,scale=0,acodec=mp4a,ab=56}:http{mux=ts,dst=:8080/}",
//                0,
//                NULL,
//                1,
//                0
//                );


    // WORKS WITH VLC    CLIENT
//        libvlc_vlm_add_broadcast(
//                    smile->instance,
//                    "raymon",
//                    path.toLocal8Bit(),
//                    // mp4a
//                    //
//                    // rtp{sdp=rtsp://:8080/}

// //                   "#transcode{vcodec=h264,vb=0,scale=0,acodec=aac,ab=128,channels=2,samplerate=44100}:http{mux=ts,dst=:8080/}",
//                    "#transcode{vcodec=h264,vb=0,scale=0,acodec=mp3,ab=128,channels=2,samplerate=44100}:http{mux=ts,dst=:8080/}",
//                    0,
//                    NULL,
//                    1,
//                    0
//                    );
//        libvlc_vlm_play_media(smile->instance, "raymon");

//LIBVLC_API libvlc_media_t * 	libvlc_media_player_get_media (libvlc_media_player_t *p_mi)
// 	Get the media used by the media_player.
QString RoxeeVLC::media_player_get_media()
{
//    qDebug() << " [RoxeeLibVLC] Cat layer: media_player_get_media";
    libvlc_media_t * m = libvlc_media_player_get_media(smile->player);
    if(m){
        return QString::fromUtf8(libvlc_media_get_mrl(m));
    }
    return QString::fromLatin1("");
}

//LIBVLC_API libvlc_event_manager_t * 	libvlc_media_player_event_manager (libvlc_media_player_t *p_mi)
// 	Get the Event Manager from which the media player send event.





//LIBVLC_API int 	libvlc_media_player_is_playing (libvlc_media_player_t *p_mi)
// 	is_playing
bool RoxeeVLC::media_player_is_playing()
{
//    qDebug() << " [RoxeeLibVLC] Cat layer: media_player_is_playing";
    return libvlc_media_player_is_playing(smile->player);
}

//LIBVLC_API int 	libvlc_media_player_play (libvlc_media_player_t *p_mi)
// 	Play.
void RoxeeVLC::media_player_play() {

    //    qDebug() << " [RoxeeLibVLC] Cat layer: media_player_play";
    libvlc_media_player_play(smile->player);
}

//LIBVLC_API void 	libvlc_media_player_set_pause (libvlc_media_player_t *mp, int do_pause)
// 	Pause or resume (no effect if there is no media).

//LIBVLC_API void 	libvlc_media_player_pause (libvlc_media_player_t *p_mi)
// 	Toggle pause (no effect if there is no media).
void RoxeeVLC::media_player_pause()
{
//    qDebug() << " [RoxeeLibVLC] Cat layer: media_player_pause";
    libvlc_media_player_pause(smile->player);
}

//LIBVLC_API void 	libvlc_media_player_stop (libvlc_media_player_t *p_mi)
// 	Stop (no effect if there is no media).
void RoxeeVLC::media_player_stop()
{
//    qDebug() << " [RoxeeLibVLC] Cat layer: media_player_stop";
    libvlc_media_player_stop(smile->player);
}


//LIBVLC_API void 	libvlc_video_set_callbacks (libvlc_media_player_t *mp, libvlc_video_lock_cb lock, libvlc_video_unlock_cb unlock, libvlc_video_display_cb display, void *opaque)
// 	Set callbacks and private data to render decoded video to a custom area in memory.
//LIBVLC_API void 	libvlc_video_set_format (libvlc_media_player_t *mp, const char *chroma, unsigned width, unsigned height, unsigned pitch)
// 	Set decoded video chroma and dimensions.
//LIBVLC_API void 	libvlc_video_set_format_callbacks (libvlc_media_player_t *mp, libvlc_video_format_cb setup, libvlc_video_cleanup_cb cleanup)
// 	Set decoded video chroma and dimensions.

//LIBVLC_API void 	libvlc_media_player_set_nsobject (libvlc_media_player_t *p_mi, void *drawable)
// 	Set the NSView handler where the media player should render its video output.
//LIBVLC_API void * 	libvlc_media_player_get_nsobject (libvlc_media_player_t *p_mi)
// 	Get the NSView handler previously set with libvlc_media_player_set_nsobject().
//LIBVLC_API void 	libvlc_media_player_set_agl (libvlc_media_player_t *p_mi, uint32_t drawable)
// 	Set the agl handler where the media player should render its video output.
//LIBVLC_API uint32_t 	libvlc_media_player_get_agl (libvlc_media_player_t *p_mi)
// 	Get the agl handler previously set with libvlc_media_player_set_agl().
//LIBVLC_API void 	libvlc_media_player_set_xwindow (libvlc_media_player_t *p_mi, uint32_t drawable)
// 	Set an X Window System drawable where the media player should render its video output.
//LIBVLC_API uint32_t 	libvlc_media_player_get_xwindow (libvlc_media_player_t *p_mi)
// 	Get the X Window System window identifier previously set with libvlc_media_player_set_xwindow().
//LIBVLC_API void 	libvlc_media_player_set_hwnd (libvlc_media_player_t *p_mi, void *drawable)
// 	Set a Win32/Win64 API window handle (HWND) where the media player should render its video output.
//LIBVLC_API void * 	libvlc_media_player_get_hwnd (libvlc_media_player_t *p_mi)
// 	Get the Windows API window handle (HWND) previously set with libvlc_media_player_set_hwnd().
void RoxeeVLC::media_player_set_window(void * id) {
//    qDebug() << " [RoxeeLibVLC] Cat layer: media_player_set_window";
#if defined ( Q_OS_MAC )
    libvlc_media_player_set_nsobject( smile->player, (void *) id );
#elif defined ( Q_OS_UNIX )
    libvlc_media_player_set_xwindow( smile->player, reinterpret_cast<intptr_t>( id ) );
#elif defined ( Q_OS_WIN )
    libvlc_media_player_set_hwnd( smile->player, id );
#endif
}

//LIBVLC_API void 	libvlc_audio_set_callbacks (libvlc_media_player_t *mp, libvlc_audio_play_cb play, libvlc_audio_pause_cb pause, libvlc_audio_resume_cb resume, libvlc_audio_flush_cb flush, libvlc_audio_drain_cb drain, void *opaque)
// 	Set callbacks and private data for decoded audio.
//LIBVLC_API void 	libvlc_audio_set_volume_callback (libvlc_media_player_t *mp, libvlc_audio_set_volume_cb set_volume)
// 	Set callbacks and private data for decoded audio.
//LIBVLC_API void 	libvlc_audio_set_format_callbacks (libvlc_media_player_t *mp, libvlc_audio_setup_cb setup, libvlc_audio_cleanup_cb cleanup)
// 	Set decoded audio format.
//LIBVLC_API void 	libvlc_audio_set_format (libvlc_media_player_t *mp, const char *format, unsigned rate, unsigned channels)
// 	Set decoded audio format.



//LIBVLC_API libvlc_time_t 	libvlc_media_player_get_length (libvlc_media_player_t *p_mi)
// 	Get the current movie length (in ms).
int RoxeeVLC::media_player_get_length()
{
//    qDebug() << " [RoxeeLibVLC] Cat layer: media_player_get_length";
    return libvlc_media_player_get_length(smile->player);
}

//LIBVLC_API libvlc_time_t 	libvlc_media_player_get_time (libvlc_media_player_t *p_mi)
// 	Get the current movie time (in ms).
int RoxeeVLC::media_player_get_time()
{
//    qDebug() << " [RoxeeLibVLC] Cat layer: media_player_get_time";
    return libvlc_media_player_get_time(smile->player);
}

//LIBVLC_API void 	libvlc_media_player_set_time (libvlc_media_player_t *p_mi, libvlc_time_t i_time)
// 	Set the movie time (in ms).
void RoxeeVLC::media_player_set_time(const int & time)
{
//    qDebug() << " [RoxeeLibVLC] Cat layer: media_player_set_time";
    libvlc_media_player_set_time(smile->player, time);
}

//LIBVLC_API float 	libvlc_media_player_get_position (libvlc_media_player_t *p_mi)
// 	Get movie position as percentage between 0.0 and 1.0.
float RoxeeVLC::media_player_get_position()
{
//    qDebug() << " [RoxeeLibVLC] Cat layer: media_player_get_position";
    return libvlc_media_player_get_position(smile->player);
}

//LIBVLC_API void 	libvlc_media_player_set_position (libvlc_media_player_t *p_mi, float f_pos)
// 	Set movie position as percentage between 0.0 and 1.0.
void RoxeeVLC::media_player_set_position(const float & pos)
{
//    qDebug() << " [RoxeeLibVLC] Cat layer: media_player_set_position";
    libvlc_media_player_set_position(smile->player, pos);
}

//LIBVLC_API void 	libvlc_media_player_set_chapter (libvlc_media_player_t *p_mi, int i_chapter)
// 	Set movie chapter (if applicable).
void RoxeeVLC::media_player_set_chapter(const int & chap)
{
//    qDebug() << " [RoxeeLibVLC] Cat layer: media_player_set_chapter";
    libvlc_media_player_set_chapter(smile->player, chap);
}

//LIBVLC_API int 	libvlc_media_player_get_chapter (libvlc_media_player_t *p_mi)
// 	Get movie chapter.
int RoxeeVLC::media_player_get_chapter()
{
//    qDebug() << " [RoxeeLibVLC] Cat layer: media_player_get_chapter";
    return libvlc_media_player_get_chapter(smile->player);
}

//LIBVLC_API int 	libvlc_media_player_get_chapter_count (libvlc_media_player_t *p_mi)
// 	Get movie chapter count.
int RoxeeVLC::media_player_get_chapter_count()
{
//    qDebug() << " [RoxeeLibVLC] Cat layer: media_player_get_chapter_count";
    return libvlc_media_player_get_chapter_count(smile->player);
}

//LIBVLC_API int 	libvlc_media_player_will_play (libvlc_media_player_t *p_mi)
// 	Is the player able to play.
//LIBVLC_API int 	libvlc_media_player_get_chapter_count_for_title (libvlc_media_player_t *p_mi, int i_title)
// 	Get title chapter count.
//LIBVLC_API void 	libvlc_media_player_set_title (libvlc_media_player_t *p_mi, int i_title)
// 	Set movie title.
//LIBVLC_API int 	libvlc_media_player_get_title (libvlc_media_player_t *p_mi)
// 	Get movie title.
//LIBVLC_API int 	libvlc_media_player_get_title_count (libvlc_media_player_t *p_mi)
// 	Get movie title count.
//LIBVLC_API void 	libvlc_media_player_previous_chapter (libvlc_media_player_t *p_mi)
// 	Set previous chapter (if applicable).
//LIBVLC_API void 	libvlc_media_player_next_chapter (libvlc_media_player_t *p_mi)
// 	Set next chapter (if applicable).
//LIBVLC_API float 	libvlc_media_player_get_rate (libvlc_media_player_t *p_mi)
// 	Get the requested movie play rate.
//LIBVLC_API int 	libvlc_media_player_set_rate (libvlc_media_player_t *p_mi, float rate)
// 	Set movie play rate.
//LIBVLC_API libvlc_state_t 	libvlc_media_player_get_state (libvlc_media_player_t *p_mi)
// 	Get current movie state.
//LIBVLC_API float 	libvlc_media_player_get_fps (libvlc_media_player_t *p_mi)
// 	Get movie fps rate.
//LIBVLC_API unsigned 	libvlc_media_player_has_vout (libvlc_media_player_t *p_mi)
// 	end bug
//LIBVLC_API int 	libvlc_media_player_is_seekable (libvlc_media_player_t *p_mi)
// 	Is this media player seekable?
//LIBVLC_API int 	libvlc_media_player_can_pause (libvlc_media_player_t *p_mi)
// 	Can this media player be paused?
//LIBVLC_API void 	libvlc_media_player_next_frame (libvlc_media_player_t *p_mi)
// 	Display the next frame (if supported).
//LIBVLC_API void 	libvlc_media_player_navigate (libvlc_media_player_t *p_mi, unsigned navigate)
// 	Navigate through DVD Menu.
//LIBVLC_API void 	libvlc_track_description_list_release (libvlc_track_description_t *p_track_description)
// 	Release (free) libvlc_track_description_t.


}


/*! \endcond */

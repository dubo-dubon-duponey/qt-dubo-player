#include "qtvlcmediaplayer.h"
#include <QDebug>

using namespace QtVlc;

MediaPlayer::MediaPlayer(void * id, QObject *parent) :
    QObject(parent)
{
    Core* m = Core::instance();
    _vlcmp = libvlc_media_player_new(m->_vlc);
#if defined ( Q_WS_MAC )
    libvlc_media_player_set_nsobject( _vlcmp, (void *) id );
#elif defined ( Q_OS_UNIX )
    libvlc_media_player_set_xwindow( _vlcmp, reinterpret_cast<intptr_t>( id ) );
#elif defined ( Q_OS_WIN )
    libvlc_media_player_set_hwnd( _vlcmp, id );
#endif
}

MediaPlayer::~MediaPlayer()
{
    libvlc_media_player_release(_vlcmp);
}

/*
    Core* m = Core::instance("/Users/dmp/buildd/webitup/build/monades/mac/vlc-1.1.12/vlc_install_dir");
    _vlcmp = libvlc_media_player_new_from_media(libvlc_media_new_path(m->_vlc, path.toAscii()));

    //    new QtVlcVideoControls(this);
    //    new QtVlcAudioControls(this);

//    (void *) static_cast< RenderWidget* >(renderWidget)->id()

//    qDebug() << id;

    qDebug() << "Trying to go";
    #if defined ( Q_WS_MAC )
        // XXX THIS WORKS WITH GLWIDGET
        libvlc_media_player_set_nsobject( _vlcmp, (void *) id );
        // Renders out of frame
        // libvlc_media_player_set_agl (_vlcmp, ((QWidget *) parent)->winId());
        // libvlc_media_player_set_agl (_vlcmp, reinterpret_cast<intptr_t>( id ));
    #elif defined ( Q_OS_UNIX )
        libvlc_media_player_set_xwindow( _vlcmp, reinterpret_cast<intptr_t>( id ) );
    #elif defined ( Q_OS_WIN )
        libvlc_media_player_set_hwnd( _vlcmp, id );
    #endif


    libvlc_media_player_play(_vlcmp);
}
*/

/*    qDebug() << "touj";
    qDebug() << id;
    qDebug() << libvlc_media_player_get_nsobject( _vlcmp );
    libvlc_media_player_set_nsobject( _vlcmp, id );
    qDebug() << libvlc_media_player_get_nsobject( _vlcmp );*/
    // XXX
    // https://bugreports.qt.nokia.com//browse/QTBUG-16274

void MediaPlayer::setMedia(const QString &path)
{
    Core* m = Core::instance();
    libvlc_media_player_set_media(_vlcmp, libvlc_media_new_path(m->_vlc, path.toAscii()));
}

QString MediaPlayer::media()
{
    // XXX not implemented
    throw "NOT_IMPLEMENTED";
    return "";//QString(libvlc_media_player_get_media(_vlcmp));
}

void MediaPlayer::play()
{
    libvlc_media_player_play(_vlcmp);
}

void MediaPlayer::stop()
{
    libvlc_media_player_stop(_vlcmp);
}

void MediaPlayer::pause()
{
    libvlc_media_player_pause(_vlcmp);
}

bool MediaPlayer::isPlaying()
{
    return libvlc_media_player_is_playing(_vlcmp);
}

int MediaPlayer::length()
{
    return libvlc_media_player_get_length(_vlcmp);
}

int MediaPlayer::time()
{
    return libvlc_media_player_get_time(_vlcmp);
}

void MediaPlayer::setTime(const int & time)
{
    libvlc_media_player_set_time(_vlcmp, time);
}

float MediaPlayer::position()
{
    return libvlc_media_player_get_position(_vlcmp);
}

void MediaPlayer::setPosition(const float & pos)
{
    libvlc_media_player_set_position(_vlcmp, pos);
}

int MediaPlayer::chapter()
{
    return libvlc_media_player_get_chapter(_vlcmp);
}

int MediaPlayer::chapterCount()
{
    return libvlc_media_player_get_chapter_count(_vlcmp);
}

void MediaPlayer::setChapter(const int & chap)
{
    libvlc_media_player_set_chapter(_vlcmp, chap);
}



/*
QtVlcAudioControls * MediaPlayer::getAudioControls()
{
}

QtVlcVideoControls * MediaPlayer::getVideoControls()
{

}
*/


/*
LIBVLC_API void 	libvlc_media_player_retain (libvlc_media_player_t *_vlcmp)
    Retain a reference to a media player object.

LIBVLC_API libvlc_event_manager_t * 	libvlc_media_player_event_manager (libvlc_media_player_t *_vlcmp)
    Get the Event Manager from which the media player send event.

LIBVLC_API void 	libvlc_media_player_set_pause (libvlc_media_player_t *mp, int do_pause)
    Pause or resume (no effect if there is no media).

LIBVLC_API void 	libvlc_video_set_callbacks (libvlc_media_player_t *mp, libvlc_video_lock_cb lock, libvlc_video_unlock_cb unlock, libvlc_video_display_cb display, void *opaque)
        Set callbacks and private data to render decoded video to a custom area in memory.

LIBVLC_API void 	libvlc_video_set_format (libvlc_media_player_t *mp, const char *chroma, unsigned width, unsigned height, unsigned pitch)
        Set decoded video chroma and dimensions.

LIBVLC_API void 	libvlc_video_set_format_callbacks (libvlc_media_player_t *mp, libvlc_video_format_cb setup, libvlc_video_cleanup_cb cleanup)
        Set decoded video chroma and dimensions.

LIBVLC_API void * 	libvlc_media_player_get_nsobject (libvlc_media_player_t *_vlcmp)
        Get the NSView handler previously set with libvlc_media_player_set_nsobject().

LIBVLC_API void 	libvlc_media_player_set_agl (libvlc_media_player_t *_vlcmp, uint32_t drawable)
        Set the agl handler where the media player should render its video output.

LIBVLC_API uint32_t 	libvlc_media_player_get_agl (libvlc_media_player_t *_vlcmp)
        Get the agl handler previously set with libvlc_media_player_set_agl().

LIBVLC_API uint32_t 	libvlc_media_player_get_xwindow (libvlc_media_player_t *_vlcmp)
        Get the X Window System window identifier previously set with libvlc_media_player_set_xwindow().

LIBVLC_API void * 	libvlc_media_player_get_hwnd (libvlc_media_player_t *_vlcmp)
        Get the Windows API window handle (HWND) previously set with libvlc_media_player_set_hwnd().

LIBVLC_API void 	libvlc_audio_set_callbacks (libvlc_media_player_t *mp, libvlc_audio_play_cb play, libvlc_audio_pause_cb pause, libvlc_audio_resume_cb resume, libvlc_audio_flush_cb flush, libvlc_audio_drain_cb drain, void *opaque)
        Set callbacks and private data for decoded audio.

LIBVLC_API void 	libvlc_audio_set_volume_callback (libvlc_media_player_t *mp, libvlc_audio_set_volume_cb set_volume)
        Set callbacks and private data for decoded audio.

LIBVLC_API void 	libvlc_audio_set_format_callbacks (libvlc_media_player_t *mp, libvlc_audio_setup_cb setup, libvlc_audio_cleanup_cb cleanup)
        Set decoded audio format.

LIBVLC_API void 	libvlc_audio_set_format (libvlc_media_player_t *mp, const char *format, unsigned rate, unsigned channels)
        Set decoded audio format.

LIBVLC_API int 	libvlc_media_player_will_play (libvlc_media_player_t *_vlcmp)
        Is the player able to play.

LIBVLC_API int 	libvlc_media_player_get_chapter_count_for_title (libvlc_media_player_t *_vlcmp, int i_title)
        Get title chapter count.

LIBVLC_API void 	libvlc_media_player_set_title (libvlc_media_player_t *_vlcmp, int i_title)
        Set movie title.

LIBVLC_API int 	libvlc_media_player_get_title (libvlc_media_player_t *_vlcmp)
        Get movie title.

LIBVLC_API int 	libvlc_media_player_get_title_count (libvlc_media_player_t *_vlcmp)
        Get movie title count.

LIBVLC_API void 	libvlc_media_player_previous_chapter (libvlc_media_player_t *_vlcmp)
        Set previous chapter (if applicable).

LIBVLC_API void 	libvlc_media_player_next_chapter (libvlc_media_player_t *_vlcmp)
        Set next chapter (if applicable).

LIBVLC_API float 	libvlc_media_player_get_rate (libvlc_media_player_t *_vlcmp)
        Get the requested movie play rate.

LIBVLC_API int 	libvlc_media_player_set_rate (libvlc_media_player_t *_vlcmp, float rate)
        Set movie play rate.

LIBVLC_API libvlc_state_t 	libvlc_media_player_get_state (libvlc_media_player_t *_vlcmp)
        Get current movie state.

LIBVLC_API float 	libvlc_media_player_get_fps (libvlc_media_player_t *_vlcmp)
        Get movie fps rate.

LIBVLC_API unsigned 	libvlc_media_player_has_vout (libvlc_media_player_t *_vlcmp)
        end bug

LIBVLC_API int 	libvlc_media_player_is_seekable (libvlc_media_player_t *_vlcmp)
        Is this media player seekable?

LIBVLC_API int 	libvlc_media_player_can_pause (libvlc_media_player_t *_vlcmp)
        Can this media player be paused?

LIBVLC_API void 	libvlc_media_player_next_frame (libvlc_media_player_t *_vlcmp)
        Display the next frame (if supported).

LIBVLC_API void 	libvlc_media_player_navigate (libvlc_media_player_t *_vlcmp, unsigned navigate)
        Navigate through DVD Menu.

LIBVLC_API void 	libvlc_track_description_release (libvlc_track_description_t *p_track_description)
        Release (free) libvlc_track_description_t.

  */
/*
Data Structures

struct  	libvlc_track_description_t
        Description for video, audio tracks and subtitles. More...
struct  	libvlc_audio_output_t
        Description for audio output. More...
struct  	libvlc_rectangle_t
        Rectangle type for video geometry. More...
Modules

        LibVLC video controls
        LibVLC audio controls
Typedefs

typedef struct
libvlc_media_player_t 	libvlc_media_player_t
typedef struct
libvlc_track_description_t 	libvlc_track_description_t
        Description for video, audio tracks and subtitles.
typedef struct
libvlc_audio_output_t 	libvlc_audio_output_t
        Description for audio output.
typedef struct libvlc_rectangle_t 	libvlc_rectangle_t
        Rectangle type for video geometry.

typedef enum
libvlc_video_marquee_option_t 	libvlc_video_marquee_option_t
        Marq options definition.
typedef enum libvlc_navigate_mode_t 	libvlc_navigate_mode_t
        Navigation mode.
typedef void *(* 	libvlc_video_lock_cb )(void *opaque, void **planes)
        Callback prototype to allocate and lock a picture buffer.
typedef void(* 	libvlc_video_unlock_cb )(void *opaque, void *picture, void *const *planes)
        Callback prototype to unlock a picture buffer.
typedef void(* 	libvlc_video_display_cb )(void *opaque, void *picture)
        Callback prototype to display a picture.
typedef unsigned(* 	libvlc_video_format_cb )(void **opaque, char *chroma, unsigned *width, unsigned *height, unsigned *pitches, unsigned *lines)
        Callback prototype to configure picture buffers format.
typedef void(* 	libvlc_video_cleanup_cb )(void *opaque)
        Callback prototype to configure picture buffers format.
typedef void(* 	libvlc_audio_play_cb )(void *data, const void *samples, unsigned count, int64_t pts)
        Callback prototype for audio playback.
typedef void(* 	libvlc_audio_pause_cb )(void *data, int64_t pts)
        Callback prototype for audio pause.
typedef void(* 	libvlc_audio_resume_cb )(void *data, int64_t pts)
        Callback prototype for audio resumption (i.e.
typedef void(* 	libvlc_audio_flush_cb )(void *data, int64_t pts)
        Callback prototype for audio buffer flush (i.e.
typedef void(* 	libvlc_audio_drain_cb )(void *data)
        Callback prototype for audio buffer drain (i.e.
typedef void(* 	libvlc_audio_set_volume_cb )(void *data, float volume, bool mute)
        Callback prototype for audio volume change.
typedef int(* 	libvlc_audio_setup_cb )(void **data, char *format, unsigned *rate, unsigned *channels)
        Callback prototype to setup the audio playback.
typedef void(* 	libvlc_audio_cleanup_cb )(void *data)
        Callback prototype for audio playback cleanup.

                                                   */


void MediaPlayer::toggleFullscreen()
{
//LIBVLC_API void 	libvlc_toggle_fullscreen (libvlc_media_player_t *_vlcmp)
//        Toggle fullscreen status on non-embedded video outputs.
    libvlc_toggle_fullscreen(_vlcmp);
}


void MediaPlayer::setFullscreen(const bool on)
{
// LIBVLC_API void 	libvlc_set_fullscreen (libvlc_media_player_t *_vlcmp, int b_fullscreen)
//        Enable or disable fullscreen.
    libvlc_set_fullscreen(_vlcmp, on);
}

bool MediaPlayer::fullscreen()
{
//LIBVLC_API int 	libvlc_get_fullscreen (libvlc_media_player_t *_vlcmp)
//        Get current fullscreen status.
    return libvlc_get_fullscreen(_vlcmp);
}

void MediaPlayer::setKeyInput(const bool on )
{
// LIBVLC_API void 	libvlc_video_set_key_input (libvlc_media_player_t *_vlcmp, unsigned on)
//        Enable or disable key press events handling, according to the LibVLC hotkeys configuration.
    libvlc_video_set_key_input (_vlcmp, on);
}

void MediaPlayer::setMouseInput(const bool on)
{
// LIBVLC_API void 	libvlc_video_set_mouse_input (libvlc_media_player_t *_vlcmp, unsigned on)
//        Enable or disable mouse click events handling.
    libvlc_video_set_mouse_input (_vlcmp, on);
}

/*VideoControls::getSize()
{
// LIBVLC_API int 	libvlc_video_get_size (libvlc_media_player_t *_vlcmp, unsigned num, unsigned *px, unsigned *py)
//        Get the pixel dimensions of a video.
}*/

int MediaPlayer::height()
{
// LIBVLC_DEPRECATED int 	libvlc_video_get_height (libvlc_media_player_t *_vlcmp)
//        Get current video height.
    return libvlc_video_get_height (_vlcmp);
}

int MediaPlayer::width()
{
//LIBVLC_DEPRECATED int 	libvlc_video_get_width (libvlc_media_player_t *_vlcmp)
//        Get current video width.
    return libvlc_video_get_width (_vlcmp);
}

/*MediaPlayer::cursor()
{
//LIBVLC_API int 	libvlc_video_get_cursor (libvlc_media_player_t *_vlcmp, unsigned num, int *px, int *py)
//        Get the mouse pointer coordinates over a video.
}*/

float MediaPlayer::scale()
{
//LIBVLC_API float 	libvlc_video_get_scale (libvlc_media_player_t *_vlcmp)
//        Get the current video scaling factor.
    return libvlc_video_get_scale(_vlcmp);
}

void MediaPlayer::setScale(const float factor)
{
//LIBVLC_API void 	libvlc_video_set_scale (libvlc_media_player_t *_vlcmp, float f_factor)
//        Set the video scaling factor.
    libvlc_video_set_scale(_vlcmp, factor);
}


QString MediaPlayer::aspectRatio()
{
//LIBVLC_API char * 	libvlc_video_get_aspect_ratio (libvlc_media_player_t *_vlcmp)
//        Get current video aspect ratio.
    return libvlc_video_get_aspect_ratio(_vlcmp);
}

void MediaPlayer::setAspectRatio(const QString &ar)
{
//LIBVLC_API void 	libvlc_video_set_aspect_ratio (libvlc_media_player_t *_vlcmp, const char *psz_aspect)
//        Set new video aspect ratio.
    libvlc_video_set_aspect_ratio (_vlcmp, ar.toLocal8Bit());
}

int MediaPlayer::spu()
{
//LIBVLC_API int 	libvlc_video_get_spu (libvlc_media_player_t *_vlcmp)
//        Get current video subtitle.
    return libvlc_video_get_spu(_vlcmp);
}

int MediaPlayer::spuCount()
{
//LIBVLC_API int 	libvlc_video_get_spu_count (libvlc_media_player_t *_vlcmp)
//        Get the number of available video subtitles.
    return libvlc_video_get_spu_count(_vlcmp);
}

QStringList MediaPlayer::spuTrackDescription()
{
    QStringList l = QStringList();
    libvlc_track_description_t * td = libvlc_video_get_spu_description (_vlcmp);
    if(td){
        l.append(QString().fromLocal8Bit(td->psz_name));
        while(td->p_next){
            td = td->p_next;
            l.append(QString().fromLocal8Bit(td->psz_name));
        }
    }
    return l;
}


void MediaPlayer::setSpu(uint i)
{
//LIBVLC_API int 	libvlc_video_set_spu (libvlc_media_player_t *_vlcmp, unsigned i_spu)
//        Set new video subtitle.
    libvlc_video_set_spu(_vlcmp, i);
}

void MediaPlayer::setSubtitleFile(const QString &path)
{
//LIBVLC_API int 	libvlc_video_set_subtitle_file (libvlc_media_player_t *_vlcmp, const char *psz_subtitle)
//        Set new video subtitle file.
    libvlc_video_set_subtitle_file(_vlcmp, path.toLocal8Bit());
}
/*
int MediaPlayer::spuDelay()
{
    return libvlc_video_get_spu_delay(_vlcmp);
}

void MediaPlayer::setSpuDelay(const int & i)
{
    libvlc_video_set_spu_delay(_vlcmp, i);
}
*/

/*
QStringList* MediaPlayer::titleDescription()
{
    return new QStringList();
//LIBVLC_API
//libvlc_track_description_t * 	libvlc_video_get_title_description (libvlc_media_player_t *_vlcmp)
//        Get the description of available titles.
//    libvlc_track_description_t * t = libvlc_video_get_description(_vlcmp);
}

QStringList* MediaPlayer::chapterDescription(int i)
{
//LIBVLC_API
//libvlc_track_description_t * 	libvlc_video_get_chapter_description (libvlc_media_player_t *_vlcmp, int i_title)
//        Get the description of available chapters for specific title.
    libvlc_track_description_t * t = libvlc_video_get_chapter_description (_vlcmp, i);
    return new QStringList();
}
*/

QString MediaPlayer::cropGeometry()
{
// LIBVLC_API char * 	libvlc_video_get_crop_geometry (libvlc_media_player_t *_vlcmp)
//        Get current crop filter geometry.
    return QString(libvlc_video_get_crop_geometry(_vlcmp));
}

void MediaPlayer::setCropGeometry(const QString &crop)
{
//LIBVLC_API void 	libvlc_video_set_crop_geometry (libvlc_media_player_t *_vlcmp, const char *psz_geometry)
//        Set new crop filter geometry.
    libvlc_video_set_crop_geometry (_vlcmp, crop.toLocal8Bit());
}

int MediaPlayer::teletext()
{
    return libvlc_video_get_teletext(_vlcmp);
//LIBVLC_API int 	libvlc_video_get_teletext (libvlc_media_player_t *_vlcmp)
//        Get current teletext page requested.
}

void MediaPlayer::setTeletext(const int & i)
{
//LIBVLC_API void 	libvlc_video_set_teletext (libvlc_media_player_t *_vlcmp, int i_page)
//        Set new teletext page to retrieve.
    libvlc_video_set_teletext(_vlcmp, i);
}

/*
void MediaPlayer::toggleTeletext()
{
//LIBVLC_API void 	libvlc_toggle_teletext (libvlc_media_player_t *_vlcmp)
//        Toggle teletext transparent status on video output.
    libvlc_video_toggle_teletext(_vlcmp);
}
*/

int MediaPlayer::videoTrackCount()
{
//LIBVLC_API int 	libvlc_video_get_track_count (libvlc_media_player_t *_vlcmp)
//        Get number of available video tracks.
    return libvlc_video_get_track_count(_vlcmp);
}

QStringList MediaPlayer::videoTrackDescription()
{
//LIBVLC_API
//libvlc_track_description_t * 	libvlc_video_get_track_description (libvlc_media_player_t *_vlcmp)
//        Get the description of available video tracks.
    QStringList l = QStringList();
    libvlc_track_description_t * td = libvlc_video_get_track_description (_vlcmp);
    if(td){
        l.append(QString().fromLocal8Bit(td->psz_name));
        while(td->p_next){
            td = td->p_next;
            l.append(QString().fromLocal8Bit(td->psz_name));
        }
    }
    return l;
}


int MediaPlayer::videoTrack()
{
//LIBVLC_API int 	libvlc_video_get_track (libvlc_media_player_t *_vlcmp)
//        Get current video track.
    return libvlc_video_get_track (_vlcmp);
}

void MediaPlayer::setVideoTrack(const int i)
{
//LIBVLC_API int 	libvlc_video_set_track (libvlc_media_player_t *_vlcmp, int i_track)
//        Set video track.
    libvlc_video_set_track (_vlcmp, i);
}

void MediaPlayer::takeSnapshot()
{
//LIBVLC_API int 	libvlc_video_take_snapshot (libvlc_media_player_t *_vlcmp, unsigned num, const char *psz_filepath, unsigned int i_width, unsigned int i_height)
//        Take a snapshot of the current video window.
}

void MediaPlayer::setDeinterlace(const bool on)
{
//LIBVLC_API void 	libvlc_video_set_deinterlace (libvlc_media_player_t *_vlcmp, const char *psz_mode)
//        Enable or disable deinterlace filter.
//    libvlc_video_set_deinterlace(_vlcmp, on);
}


/*
LIBVLC_API int 	libvlc_video_get_marquee_int (libvlc_media_player_t *_vlcmp, unsigned option)
    Get an integer marquee option value.

LIBVLC_API char * 	libvlc_video_get_marquee_string (libvlc_media_player_t *_vlcmp, unsigned option)
    Get a string marquee option value.
LIBVLC_API void 	libvlc_video_set_marquee_int (libvlc_media_player_t *_vlcmp, unsigned option, int i_val)
    Enable, disable or set an integer marquee option.
LIBVLC_API void 	libvlc_video_set_marquee_string (libvlc_media_player_t *_vlcmp, unsigned option, const char *psz_text)
    Set a marquee string option.
LIBVLC_API int 	libvlc_video_get_logo_int (libvlc_media_player_t *_vlcmp, unsigned option)
    Get integer logo option.
LIBVLC_API void 	libvlc_video_set_logo_int (libvlc_media_player_t *_vlcmp, unsigned option, int value)
    Set logo option as integer.
LIBVLC_API void 	libvlc_video_set_logo_string (libvlc_media_player_t *_vlcmp, unsigned option, const char *psz_value)
    Set logo option as string.
LIBVLC_API int 	libvlc_video_get_adjust_int (libvlc_media_player_t *_vlcmp, unsigned option)
    Get integer adjust option.
LIBVLC_API void 	libvlc_video_set_adjust_int (libvlc_media_player_t *_vlcmp, unsigned option, int value)
    Set adjust option as integer.
LIBVLC_API float 	libvlc_video_get_adjust_float (libvlc_media_player_t *_vlcmp, unsigned option)
    Get float adjust option.
LIBVLC_API void 	libvlc_video_set_adjust_float (libvlc_media_player_t *_vlcmp, unsigned option, float value)
    Set adjust option as float.
*/



/*

  AUDIO CONTROLS

  */


/*
LIBVLC_API libvlc_audio_output_t * 	libvlc_audio_output_list_get (libvlc_instance_t *p_instance)
    Get the list of available audio outputs.
LIBVLC_API void 	libvlc_audio_output_list_release (libvlc_audio_output_t *p_list)
    Free the list of available audio outputs.
LIBVLC_API int 	libvlc_audio_output_set (libvlc_media_player_t *_vlcmp, const char *psz_name)
    Set the audio output.
LIBVLC_API int 	libvlc_audio_output_device_count (libvlc_instance_t *p_instance, const char *psz_audio_output)
    Get count of devices for audio output, these devices are hardware oriented like analor or digital output of sound card.
LIBVLC_API char * 	libvlc_audio_output_device_longname (libvlc_instance_t *p_instance, const char *psz_audio_output, int i_device)
    Get long name of device, if not available short name given.
LIBVLC_API char * 	libvlc_audio_output_device_id (libvlc_instance_t *p_instance, const char *psz_audio_output, int i_device)
    Get id name of device.
LIBVLC_API void 	libvlc_audio_output_device_set (libvlc_media_player_t *_vlcmp, const char *psz_audio_output, const char *psz_device_id)
    Set audio output device.
LIBVLC_API int 	libvlc_audio_output_get_device_type (libvlc_media_player_t *_vlcmp)
    Get current audio device type.
LIBVLC_API void 	libvlc_audio_output_set_device_type (libvlc_media_player_t *_vlcmp, int device_type)
    Set current audio device type.


*/


void MediaPlayer::toggleMute()
{
//    LIBVLC_API void 	libvlc_audio_toggle_mute (libvlc_media_player_t *_vlcmp)
//            Toggle mute status.
    libvlc_audio_toggle_mute(_vlcmp);
}

bool MediaPlayer::mute()
{
//    LIBVLC_API int 	libvlc_audio_get_mute (libvlc_media_player_t *_vlcmp)
//            Get current mute status.
    return libvlc_audio_get_mute (_vlcmp);
}

void MediaPlayer::setMute(const bool status)
{
//    LIBVLC_API void 	libvlc_audio_set_mute (libvlc_media_player_t *_vlcmp, int status)
//            Set mute status.
    libvlc_audio_set_mute (_vlcmp, status);
}

int MediaPlayer::volume()
{
//    LIBVLC_API int 	libvlc_audio_get_volume (libvlc_media_player_t *_vlcmp)
//            Get current software audio volume.
    return libvlc_audio_get_volume(_vlcmp);
}

void MediaPlayer::setVolume(const int vol)
{
//    LIBVLC_API int 	libvlc_audio_set_volume (libvlc_media_player_t *_vlcmp, int i_volume)
//            Set current software audio volume.
    libvlc_audio_set_volume(_vlcmp, vol);
}

int MediaPlayer::audioTrackCount()
{
//    LIBVLC_API int 	libvlc_audio_get_track_count (libvlc_media_player_t *_vlcmp)
//            Get number of available audio tracks.
    return libvlc_audio_get_track_count (_vlcmp);
}

QStringList MediaPlayer::audioTrackDescription()
{
    QStringList l = QStringList();
    libvlc_track_description_t * td = libvlc_audio_get_track_description (_vlcmp);
    if(td){
        l.append(QString().fromLocal8Bit(td->psz_name));
        while(td->p_next){
            td = td->p_next;
            l.append(QString().fromLocal8Bit(td->psz_name));
        }
    }
    return l;
}

// Roxee.core.runner.video.controller.audioTrackDescription

int MediaPlayer::audioTrack()
{
// LIBVLC_API int 	libvlc_audio_get_track (libvlc_media_player_t *_vlcmp)
//        Get current audio track.
    return libvlc_audio_get_track (_vlcmp);
}

void MediaPlayer::setAudioTrack(const int i)
{
//LIBVLC_API int 	libvlc_audio_set_track (libvlc_media_player_t *_vlcmp, int i_track)
//        Set current audio track.
    libvlc_audio_set_track ( _vlcmp, i );
}

/*
LIBVLC_API int 	libvlc_audio_get_channel (libvlc_media_player_t *_vlcmp)
    Get current audio channel.
LIBVLC_API int 	libvlc_audio_set_channel (libvlc_media_player_t *_vlcmp, int channel)
    Set current audio channel.
LIBVLC_API int64_t 	libvlc_audio_get_delay (libvlc_media_player_t *_vlcmp)
    Get current audio delay.
LIBVLC_API int 	libvlc_audio_set_delay (libvlc_media_player_t *_vlcmp, int64_t i_delay)
    Set current audio delay.
*/








/*****************************************************************************
 * Copyright (c) 2018, Dubo Dubon Duponey <dubodubonduponey@gmail.com>
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

#ifndef DUBOPLAYER_VLC_HPP
#define DUBOPLAYER_VLC_HPP

#include <QObject>
#include <QStringList>

/*! \cond */
namespace DuboPlayer{

class DuboVLC: public QObject
{
   Q_OBJECT
private:
    struct CheshireCatInstance;                 // Not defined here
    CheshireCatInstance * smile;

signals:
    void notify(const QString & type);

public:
    explicit DuboVLC(QObject * parent = 0);                         // Constructor
    explicit DuboVLC(const DuboVLC&);            // Copy constructor
    DuboVLC& operator=(const DuboVLC&); // Copy assignment operator
    ~DuboVLC();                        // Destructor

    DuboVLC * Carroll();

    void set_user_agent(const QString &appOutput, const QString &httpOutput);
    static const QString get_version();
    static const QString get_changeset();
    static const QString get_compiler();
    QStringList audio_filter_list_get();
    QStringList video_filter_list_get();

    // Audio
    void audio_toggle_mute();
    bool audio_get_mute();
    void audio_set_mute(const bool status);
    int audio_get_volume();
    void audio_set_volume(const int vol);
    int audio_get_track_count();
    QStringList audio_get_track_description();
    int audio_get_track();
    void audio_set_track(const int i);
    QStringList audio_output_list_get();
    QStringList audio_output_device_list_get(const QString & outd);
    void audio_output_set(const QString & outd);
    void audio_output_device_set(const QString & outd);

    // Media Player
    void media_player_new();
    void media_player_set_media(const QString &);
    QString media_player_get_media();
    bool media_player_is_playing();
    void media_player_play();
    void media_player_pause();
    void media_player_stop();
    void media_player_set_window(void * id);
    int media_player_get_length();
    int media_player_get_time();
    void media_player_set_time(const int & time);
    float media_player_get_position();
    void media_player_set_position(const float & pos);
    void media_player_set_chapter(const int & chap);
    int media_player_get_chapter();
    int media_player_get_chapter_count();

    // Video
    void toggle_fullscreen();
    void set_fullscreen(const bool on);
    bool get_fullscreen();
    void video_set_key_input(const bool on );
    void video_set_mouse_input(const bool on);
    uint video_get_width(int t);
    uint video_get_height(int t);
    float video_get_scale();
    void video_set_scale(const float factor);
    QString video_get_aspect_ratio();
    void video_set_aspect_ratio(const QString &ar);
    int video_get_spu();
    int video_get_spu_count();
    QStringList video_get_spu_description();
    void video_set_spu(uint i);
    void video_set_subtitle_file(const QString &path);
    int video_get_spu_delay();
    void video_set_spu_delay(const int & i);
    QString video_get_crop_geometry();
    void video_set_crop_geometry(const QString &crop);
    int video_get_teletext();
    void video_set_teletext(const int & i);
    void toggle_teletext();
    int video_get_track_count();
    QStringList video_get_track_description();
    int video_get_track();
    void video_set_track(const int i);





    void video_take_snapshot(const int i, const QString & path);


    bool vlm_play_media(const QString & broadcastName);
    bool vlm_add_broadcast(const QString & broadcastName, const QString & path, const QString & args);


};

}
/*! \endcond */

#endif // DUBOPLAYER_VLC_HPP

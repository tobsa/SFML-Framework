////////////////////////////////////////////////////////////////////////////////
// Filename: MusicGroup.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef SFX_MUSIC_GROUP_HPP
#define SFX_MUSIC_GROUP_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Music.hpp"
#include "../Containers/Vector.hpp"
#include <memory>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
class MusicGroup
{
private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private typedefs
    ////////////////////////////////////////////////////////////////////////////////
    typedef std::shared_ptr<Music> MusicPtr;
    typedef Vector<MusicPtr>       MusicVector;

public:

    ////////////////////////////////////////////////////////////////////////////////
    // Public enums
    ////////////////////////////////////////////////////////////////////////////////
    enum Order { Linear,        // Plays next sound
                 LinearOnce,    // Plays all the sounds in the list once
                 LinearAuto,    // Automatically plays the next sound
                 Random,        // Plays a random sound in the list
                 RandomAuto     // Automaically keep choosing random sounds
    };

    ////////////////////////////////////////////////////////////////////////////////
    // Constructor
    ////////////////////////////////////////////////////////////////////////////////
    MusicGroup(Order order = Linear);

    ////////////////////////////////////////////////////////////////////////////////
    // Add new music to the group
    ////////////////////////////////////////////////////////////////////////////////
    void addMusic(MusicPtr music);

    ////////////////////////////////////////////////////////////////////////////////
    // Play, pause and stop music
    ////////////////////////////////////////////////////////////////////////////////
    void play();
    void pause();
    void stop();

    ////////////////////////////////////////////////////////////////////////////////
    // Check if the group is playing, paused or stopped
    ////////////////////////////////////////////////////////////////////////////////
    bool isPlaying() const;
    bool isPaused() const;
    bool isStopped() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Remove music from the list
    ////////////////////////////////////////////////////////////////////////////////
    void removeMusic(MusicPtr music);
    void removeMusic(const std::string& name);

    ////////////////////////////////////////////////////////////////////////////////
    // Update the group (LinearOnce, LinearAuto and RandomAuto requires this)
    ////////////////////////////////////////////////////////////////////////////////
    void onUpdate();

    ////////////////////////////////////////////////////////////////////////////////
    // Set order and volume
    ////////////////////////////////////////////////////////////////////////////////
    void setOrder(Order order);
    void setVolume(float volume);

    ////////////////////////////////////////////////////////////////////////////////
    // Get the order and volume
    ////////////////////////////////////////////////////////////////////////////////
    Order getOrder() const;
    float getVolume() const;

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private member data
    ////////////////////////////////////////////////////////////////////////////////
    MusicVector m_musics;
    Order       m_order;
    std::size_t m_currentIndex;
    std::size_t m_nextIndex;
    bool        m_playing;
    float       m_volume;
};

} // namespace sfx

#endif
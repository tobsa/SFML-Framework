////////////////////////////////////////////////////////////////////////////////
// Filename: Music.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef SFX_MUSIC_HPP
#define SFX_MUSIC_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include <SFML/Audio/Music.hpp>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// A simple sf::Music wrapper with an unique identifier
////////////////////////////////////////////////////////////////////////////////
class Music
{
public:
    
    ////////////////////////////////////////////////////////////////////////////////
    // Constructor
    ////////////////////////////////////////////////////////////////////////////////
    Music(const std::string& filename);

    ////////////////////////////////////////////////////////////////////////////////
    // Start to stream from a new music file
    ////////////////////////////////////////////////////////////////////////////////
    void setMusic(const std::string& filename);

    ////////////////////////////////////////////////////////////////////////////////
    // Play, pause and stop music
    ////////////////////////////////////////////////////////////////////////////////
    void play();
    void pause();
    void stop();

    ////////////////////////////////////////////////////////////////////////////////
    // Is the music playing, paused or stopped
    ////////////////////////////////////////////////////////////////////////////////
    bool isPlaying() const;
    bool isPaused() const;
    bool isStopped() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Set volume and loop
    ////////////////////////////////////////////////////////////////////////////////
    void setVolume(float volume);
    void setLoop(bool loop);

    ////////////////////////////////////////////////////////////////////////////////
    // Get volume and loop
    ////////////////////////////////////////////////////////////////////////////////
    float getVolume() const;
    bool getLoop() const;
    const std::string& getName() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Define == operator
    ////////////////////////////////////////////////////////////////////////////////
    bool operator==(const Music& music) const;

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private member data
    ////////////////////////////////////////////////////////////////////////////////
    std::string m_name;
    sf::Music   m_music;
};

} // namespace sfx

#endif
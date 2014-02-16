////////////////////////////////////////////////////////////////////////////////
// Filename: Sound.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef SFX_SOUND_HPP
#define SFX_SOUND_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "../Containers/Vector.hpp"
#include <SFML/Audio/Sound.hpp>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// A simple wrapper around sf::Sound with ability to have many channels
////////////////////////////////////////////////////////////////////////////////
class Sound
{
public:

    ////////////////////////////////////////////////////////////////////////////////
    // Constructor
    ////////////////////////////////////////////////////////////////////////////////
    Sound();
    Sound(const std::string& name, const sf::SoundBuffer& soundBuffer, std::size_t channels = 1);

    ////////////////////////////////////////////////////////////////////////////////
    // Set a new sound buffer (clear any previous sounds and always creates at least
    // one channel
    ////////////////////////////////////////////////////////////////////////////////
    void setSound(const std::string& name, const sf::SoundBuffer& soundBuffer, std::size_t channels = 1);

    ////////////////////////////////////////////////////////////////////////////////
    // Play, pause and stop a sound
    ////////////////////////////////////////////////////////////////////////////////
    void play();
    void pause();
    void stop();

    ////////////////////////////////////////////////////////////////////////////////
    // Check if the sound is playing, paused or stopped
    ////////////////////////////////////////////////////////////////////////////////
    bool isPlaying() const;
    bool isPaused() const;
    bool isStopped() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Set volume
    ////////////////////////////////////////////////////////////////////////////////
    void setVolume(float volume);

    ////////////////////////////////////////////////////////////////////////////////
    // Get the amount of channels this 
    ////////////////////////////////////////////////////////////////////////////////
    std::size_t getChannels() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Get the name of the sound
    ////////////////////////////////////////////////////////////////////////////////
    const std::string& getName() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Get the volume
    ////////////////////////////////////////////////////////////////////////////////
    float getVolume() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Define == operator
    ////////////////////////////////////////////////////////////////////////////////
    bool operator==(const Sound& sound) const;

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private typedef
    ////////////////////////////////////////////////////////////////////////////////
    typedef Vector<sf::Sound> SoundVector;

    ////////////////////////////////////////////////////////////////////////////////
    // Private
    ////////////////////////////////////////////////////////////////////////////////
    std::string m_name;
    SoundVector m_sounds;
};

} // namespace sfx

#endif
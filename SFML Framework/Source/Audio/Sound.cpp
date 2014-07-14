////////////////////////////////////////////////////////////////////////////////
// Filename: Sound.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Sound.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
Sound::Sound()
{
}

////////////////////////////////////////////////////////////////////////////////
Sound::Sound(const std::string& name, const sf::SoundBuffer& soundBuffer, std::size_t channels) :
    m_name   (name),
    m_sounds (sfx::clamp(channels, 1U, channels), sf::Sound(soundBuffer))
{
}

////////////////////////////////////////////////////////////////////////////////
void Sound::setSound(const std::string& name, const sf::SoundBuffer& soundBuffer, std::size_t channels)
{
    m_sounds.clear();

    m_name   = name;
    channels = sfx::clamp(channels, 1U, channels);

    for(std::size_t i = 0; i < channels; ++i)
        m_sounds.addBack(sf::Sound(soundBuffer));        
}

////////////////////////////////////////////////////////////////////////////////
void Sound::play()
{
    bool foundPaused = false;

    // Check for paused channels to play from first
    for(auto& sound : m_sounds)
    {
        if(sound.getStatus() == sf::Sound::Paused)
        {
            sound.play();
            foundPaused = true;
        }
    }

    // If there wasn't any paused channels then start playing from the first free channel
    if(!foundPaused)
    {
        for(auto& sound : m_sounds)
        {
            if(sound.getStatus() == sf::Sound::Stopped)
            {
                sound.play();
                break;
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
void Sound::pause()
{
    for(auto& sound : m_sounds)
    {
        if(sound.getStatus() == sf::Sound::Playing)
            sound.pause();
    }
}

////////////////////////////////////////////////////////////////////////////////
void Sound::stop()
{
     for(auto& sound : m_sounds)
        sound.stop();
}

////////////////////////////////////////////////////////////////////////////////
bool Sound::isPlaying() const
{
    // Check if a channel is still playing
    for(auto& sound : m_sounds)
    {
        if(sound.getStatus() == sf::Sound::Playing)
            return true;
    }

    return false;
}

////////////////////////////////////////////////////////////////////////////////
bool Sound::isPaused() const
{
    // Check if all channels is paused
    for(auto& sound : m_sounds)
    {
        if(sound.getStatus() != sf::Sound::Paused)
            return false;
    }

    return true;
}

////////////////////////////////////////////////////////////////////////////////
bool Sound::isStopped() const
{
     // Check if all channels is stopped
    for(auto& sound : m_sounds)
    {
        if(sound.getStatus() != sf::Sound::Stopped)
            return false;
    }

    return true;
}

////////////////////////////////////////////////////////////////////////////////
void Sound::setVolume(float volume)
{
    for(auto& sound : m_sounds)
        sound.setVolume(volume);
}

////////////////////////////////////////////////////////////////////////////////
std::size_t Sound::getChannels() const
{
    return m_sounds.getSize();
}

////////////////////////////////////////////////////////////////////////////////
const std::string& Sound::getName() const
{
    return m_name;
}

////////////////////////////////////////////////////////////////////////////////
float Sound::getVolume() const
{
    return m_sounds.front().getVolume();
}

////////////////////////////////////////////////////////////////////////////////
bool Sound::operator==(const Sound& sound) const
{
    return m_name == sound.m_name;
}

} // namespace sfx
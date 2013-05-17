////////////////////////////////////////////////////////////////////////////////
// Filename: Music.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Music.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
Music::Music(const std::string& filename)
{
    setMusic(filename);
}

////////////////////////////////////////////////////////////////////////////////
void Music::setMusic(const std::string& filename)
{
    m_name = filename;
    m_music.openFromFile(filename);
}

////////////////////////////////////////////////////////////////////////////////
void Music::play()
{
    m_music.play();
}

////////////////////////////////////////////////////////////////////////////////
void Music::pause()
{
    m_music.pause();
}

////////////////////////////////////////////////////////////////////////////////
void Music::stop()
{
    m_music.stop();
}

////////////////////////////////////////////////////////////////////////////////
bool Music::isPlaying() const
{
    return m_music.getStatus() == sf::Music::Playing;
}

////////////////////////////////////////////////////////////////////////////////
bool Music::isPaused() const
{
    return m_music.getStatus() == sf::Music::Paused;
}

////////////////////////////////////////////////////////////////////////////////
bool Music::isStopped() const
{
    return m_music.getStatus() == sf::Music::Stopped;
}

////////////////////////////////////////////////////////////////////////////////
void Music::setVolume(float volume)
{
    m_music.setVolume(volume);
}

////////////////////////////////////////////////////////////////////////////////
void Music::setLoop(bool loop)
{
    m_music.setLoop(loop);
}

////////////////////////////////////////////////////////////////////////////////
float Music::getVolume() const
{
    return m_music.getVolume();
}

////////////////////////////////////////////////////////////////////////////////
bool Music::getLoop() const
{
    return m_music.getLoop();
}

////////////////////////////////////////////////////////////////////////////////
const std::string& Music::getName() const
{
    return m_name;
}

////////////////////////////////////////////////////////////////////////////////
bool Music::operator==(const Music& music) const
{
    return m_name == music.m_name;
}

} // namespace sfx
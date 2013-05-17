////////////////////////////////////////////////////////////////////////////////
// Filename: SoundGroup.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "SoundGroup.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
SoundGroup::SoundGroup(Order order) :
    m_order        (order),
    m_currentIndex (0),
    m_nextIndex    (0),
    m_playing      (false),
    m_volume       (100.f)
{
}

////////////////////////////////////////////////////////////////////////////////
void SoundGroup::addSound(const Sound& sound)
{
    m_sounds.addBack(sound);
    m_sounds.back().setVolume(m_volume);
}

////////////////////////////////////////////////////////////////////////////////
void SoundGroup::play()
{
    if(m_sounds.isEmpty()) return;

    if(m_order == Linear)
    {
        // Make sure the current sound isn't playing before playing the next sound
        if(m_sounds[m_currentIndex].isStopped())
        {
            m_currentIndex = m_nextIndex;
            m_sounds[m_currentIndex].play();
            m_nextIndex = sfx::wrap(m_nextIndex + 1, 0U, m_sounds.getSize() - 1);
        }
    }
    else if(m_order == LinearSkip)
    {
        // Play the next sound
        m_currentIndex = m_nextIndex;
        m_sounds[m_currentIndex].play();
        m_nextIndex = sfx::wrap(m_nextIndex + 1, 0U, m_sounds.getSize() - 1);
    }
    else if(m_order == Random)
    {
        m_sounds[sfx::getRandom(0, m_sounds.getSize() - 1)].play();
    }

    m_playing = true;
}

////////////////////////////////////////////////////////////////////////////////
void SoundGroup::stop()
{
    for(auto& sound : m_sounds)
        sound.stop();

    m_currentIndex = 0;
    m_nextIndex    = 0;
    m_playing      = false;
}

////////////////////////////////////////////////////////////////////////////////
bool SoundGroup::isPlaying() const
{
    for(const auto& sound : m_sounds)
    {
        if(!sound.isPlaying())
            return false;
    }

    return true;
}

////////////////////////////////////////////////////////////////////////////////
bool SoundGroup::isStopped() const
{
    for(const auto& sound : m_sounds)
    {
        if(!sound.isStopped())
            return false;
    }

    return true;
}

////////////////////////////////////////////////////////////////////////////////
void SoundGroup::removeSound(const Sound& sound)
{
    for(std::size_t i = 0; i < m_sounds.getSize(); ++i)
    {
        if(m_sounds[i] == sound)
            i = m_sounds.remove(i);
    }
}

////////////////////////////////////////////////////////////////////////////////
void SoundGroup::removeSound(const std::string& key)
{
    for(std::size_t i = 0; i < m_sounds.getSize(); ++i)
    {
        if(m_sounds[i].getName() == key)
            i = m_sounds.remove(i);
    }
}

////////////////////////////////////////////////////////////////////////////////
void SoundGroup::onUpdate()
{
    if(!m_playing) return;

    if(m_order == LinearOnce)
    {
        // Make sure the current sound isn't playing
        if(m_sounds[m_currentIndex].isStopped())
        {
            // Stop if all the sounds have been played
            if(m_currentIndex == m_sounds.getSize() -1)
                stop();
            else 
            {
                // Play next sound
                m_currentIndex = m_nextIndex;
                m_sounds[m_currentIndex].play();
                m_nextIndex++;
            }

        }
    }
    else if(m_order == LinearAuto)
    {
        // Make sure the current sound isn't playing before playing the next sound
        if(m_sounds[m_currentIndex].isStopped())
        {
            m_currentIndex = m_nextIndex;
            m_sounds[m_currentIndex].play();
            m_nextIndex = sfx::wrap(m_nextIndex + 1, 0U, m_sounds.getSize() - 1);
        }
    }
    else if(m_order == RandomAuto)
    {
        // Make sure the current sound isn't playing before randomly playing a new sound
        if(m_sounds[m_currentIndex].isStopped())
        {
            m_currentIndex = m_nextIndex = sfx::getRandom(0, m_sounds.getSize() - 1);
            m_sounds[m_currentIndex].play();
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
void SoundGroup::setOrder(Order order)
{
    stop();
    m_order = order;
}

////////////////////////////////////////////////////////////////////////////////
void SoundGroup::setVolume(float volume)
{
    for(auto& sound : m_sounds)
        sound.setVolume(volume);

    m_volume = volume;
}

////////////////////////////////////////////////////////////////////////////////
SoundGroup::Order SoundGroup::getOrder() const
{
    return m_order;
}

float SoundGroup::getVolume() const
{
    return m_volume;
}

} // namespace sfx
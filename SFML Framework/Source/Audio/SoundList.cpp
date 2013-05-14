////////////////////////////////////////////////////////////////////////////////
// Filename: SoundList.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "SoundList.hpp"
#include "../Utility/Utility.hpp"
#include "../Utility/Log.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
SoundList::SoundList(Order order) :
    m_order     (order),
    m_index     (0),
    m_playing   (false)
{
}

////////////////////////////////////////////////////////////////////////////////
void SoundList::addSound(const sf::Sound& sound)
{
    m_sounds.push_back(sound);
}

////////////////////////////////////////////////////////////////////////////////
void SoundList::setSoundList(const Sounds& sounds)
{
    m_sounds = sounds;
}

////////////////////////////////////////////////////////////////////////////////
void SoundList::play()
{
    if(m_sounds.empty())
        sfx::Log::writeT("Error (SoundList::play()) : m_sounds is empty");

    m_playing = true;
}

////////////////////////////////////////////////////////////////////////////////
void SoundList::pause()
{
    if(m_sounds.empty())
        sfx::Log::writeT("Error (SoundList::pause()) : m_sounds is empty");

    m_sounds[m_index].pause();
    m_playing = false;
}

////////////////////////////////////////////////////////////////////////////////
void SoundList::stop()
{
    if(m_sounds.empty())
        sfx::Log::writeT("Error (SoundList::stop()) : m_sounds is empty");

    m_sounds[m_index].stop();
    m_index = 0;
    m_playing = false;
}

////////////////////////////////////////////////////////////////////////////////
void SoundList::onUpdate()
{
    if(!m_playing) return;

    if(m_sounds[m_index].getStatus() != sf::Sound::Playing)
    {
        if(m_order == Linear)
            m_index = sfx::wrap(m_index + 1U, 0U, m_sounds.size() - 1U);
        else
            m_index = sfx::getRandom(0, m_sounds.size() - 1);

        m_sounds[m_index].play();
    }
}

////////////////////////////////////////////////////////////////////////////////
void SoundList::setOrder(Order order)
{
    m_order = order;
}

} // namespace sfx
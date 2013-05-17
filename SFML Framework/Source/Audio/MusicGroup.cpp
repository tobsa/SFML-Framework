////////////////////////////////////////////////////////////////////////////////
// Filename: MusicGroup.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "MusicGroup.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
MusicGroup::MusicGroup(Order order) :
    m_order        (order),
    m_currentIndex (0),
    m_nextIndex    (0),
    m_playing      (false),
    m_volume       (100.f)
{
}

////////////////////////////////////////////////////////////////////////////////
void MusicGroup::addMusic(MusicPtr music)
{
    m_musics.addBack(music);
    m_musics.back()->setVolume(m_volume);
}

////////////////////////////////////////////////////////////////////////////////
void MusicGroup::play()
{
    if(m_musics.isEmpty()) return;

    if(m_order == Linear)
    {
        // Plays the next music in the list
        if(m_musics[m_currentIndex]->isStopped())
        {
            m_currentIndex = m_nextIndex;
            m_musics[m_currentIndex]->play();
            m_nextIndex = sfx::wrap(m_nextIndex + 1, 0U, m_musics.getSize() - 1);
        }
        else if(m_musics[m_currentIndex]->isPaused())
            m_musics[m_currentIndex]->play();
    }
    else if(m_order == Random)
    {
        // Plays a random music in the list
        if(m_musics[m_currentIndex]->isStopped())
        {
            m_currentIndex = m_nextIndex = sfx::getRandom(0, m_musics.getSize() - 1);
            m_musics[m_currentIndex]->play();
        }
    }
    else if(m_order == LinearOnce || m_order == LinearAuto || m_order == RandomAuto)
    {
        if(m_musics[m_currentIndex]->isPaused())
            m_musics[m_currentIndex]->play();
    }
    
    m_playing = true;    
}

////////////////////////////////////////////////////////////////////////////////
void MusicGroup::pause()
{
    if(m_musics.isEmpty()) return;

    m_musics[m_currentIndex]->pause();
}

////////////////////////////////////////////////////////////////////////////////
void MusicGroup::stop()
{
    for(auto& music : m_musics)
        music->stop();

    m_currentIndex = 0;
    m_nextIndex    = 0;
    m_playing      = false;
}

////////////////////////////////////////////////////////////////////////////////
bool MusicGroup::isPlaying() const
{
    if(m_musics.isEmpty()) return false;

    return m_musics[m_currentIndex]->isPlaying();
}

////////////////////////////////////////////////////////////////////////////////
bool MusicGroup::isPaused() const
{
    if(m_musics.isEmpty()) return false;

    return m_musics[m_currentIndex]->isPaused();
}

////////////////////////////////////////////////////////////////////////////////
bool MusicGroup::isStopped() const
{
    if(m_musics.isEmpty()) return false;

    return m_musics[m_currentIndex]->isStopped();
}

////////////////////////////////////////////////////////////////////////////////
void MusicGroup::removeMusic(MusicPtr music)
{
    for(std::size_t i = 0; i < m_musics.getSize(); ++i)
    {
        if(m_musics[i] == music)
            i = m_musics.remove(i);
    }

    stop();
}

////////////////////////////////////////////////////////////////////////////////
void MusicGroup::removeMusic(const std::string& name)
{
    for(std::size_t i = 0; i < m_musics.getSize(); ++i)
    {
        if(m_musics[i]->getName() == name)
            i = m_musics.remove(i);
    }

    stop();
}

////////////////////////////////////////////////////////////////////////////////
void MusicGroup::onUpdate()
{
    if(!m_playing) return;

    if(m_order == LinearOnce)
    {
        // Make sure the current music isn't playing
        if(m_musics[m_currentIndex]->isStopped())
        {
            // Stop if all the musics have been played
            if(m_currentIndex == m_musics.getSize() -1)
                stop();
            else 
            {
                // Play next music
                m_currentIndex = m_nextIndex;
                m_musics[m_currentIndex]->play();
                m_nextIndex++;
            }

        }
    }
    else if(m_order == LinearAuto)
    {
        // Make sure the current music isn't playing before playing the next music
        if(m_musics[m_currentIndex]->isStopped())
        {
            m_currentIndex = m_nextIndex;
            m_musics[m_currentIndex]->play();
            m_nextIndex = sfx::wrap(m_nextIndex + 1, 0U, m_musics.getSize() - 1);
        }
    }
    else if(m_order == RandomAuto)
    {
        // Make sure the current music isn't playing before playing a new random music
        if(m_musics[m_currentIndex]->isStopped())
        {
            m_currentIndex = m_nextIndex = sfx::getRandom(0, m_musics.getSize() - 1);
            m_musics[m_currentIndex]->play();
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
void MusicGroup::setOrder(Order order)
{
    stop();
    m_order = order;
}

////////////////////////////////////////////////////////////////////////////////
void MusicGroup::setVolume(float volume)
{
    for(auto& music : m_musics)
        music->setVolume(volume);

    m_volume = volume;
}

////////////////////////////////////////////////////////////////////////////////
MusicGroup::Order MusicGroup::getOrder() const
{
    return m_order;
}

float MusicGroup::getVolume() const
{
    return m_volume;
}

} // namespace sfx
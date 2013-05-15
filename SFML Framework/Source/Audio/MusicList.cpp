////////////////////////////////////////////////////////////////////////////////
// Filename: MusicList.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "MusicList.hpp"
#include "../Utility/Utility.hpp"
#include "../Utility/Log.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
MusicList::MusicList(Order order) :
    m_order   (order),
    m_index   (0),
    m_playing (false)
{
}

////////////////////////////////////////////////////////////////////////////////
void MusicList::addMusic(const std::string& filename)
{
    MusicPtr music = std::make_shared<sf::Music>();
    music->openFromFile(filename);

    m_musics.addBack(music);
}

////////////////////////////////////////////////////////////////////////////////
void MusicList::play()
{
    if(m_musics.isEmpty())
        sfx::Log::writeT("Error (MusicList::play()) : m_musics is empty");

    m_playing = true;
}

////////////////////////////////////////////////////////////////////////////////
void MusicList::pause()
{
    if(m_musics.isEmpty())
        sfx::Log::writeT("Error (MusicList::pause()) : m_musics is empty");

    m_musics[m_index]->pause();
    m_playing = false;
}

////////////////////////////////////////////////////////////////////////////////
void MusicList::stop()
{
    if(m_musics.isEmpty())
        sfx::Log::writeT("Error (MusicList::stop()) : m_musics is empty");

    m_musics[m_index]->stop();
    m_playing = false;
}

////////////////////////////////////////////////////////////////////////////////
void MusicList::onUpdate()
{
    if(!m_playing) return;

    if(m_musics[m_index]->getStatus() != sf::Music::Playing)
    {
        if(m_order == Linear)
            m_index = sfx::wrap(m_index + 1U, 0U, m_musics.getSize() - 1U);
        else
            m_index = sfx::getRandom(0, m_musics.getSize() - 1);

        m_musics[m_index]->play();
    }
}

////////////////////////////////////////////////////////////////////////////////
void MusicList::setOrder(Order order)
{
    m_order = order;
}

} // namespace sfx
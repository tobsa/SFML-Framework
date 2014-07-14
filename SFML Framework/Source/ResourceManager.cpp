////////////////////////////////////////////////////////////////////////////////
// Filename: ResourceManager.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "ResourceManager.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
sf::Texture& ResourceManager::getTexture(const std::string& filename)
{
    if(m_textures.find(filename) == m_textures.end())
    {
        m_textures[filename] = std::make_shared<sf::Texture>();
        m_textures[filename]->loadFromFile(filename);
    }

    return *m_textures[filename];
}

////////////////////////////////////////////////////////////////////////////////
sf::Font& ResourceManager::getFont(const std::string& filename)
{
    if(m_fonts.find(filename) == m_fonts.end())
    {
        m_fonts[filename] = std::make_shared<sf::Font>();
        m_fonts[filename]->loadFromFile(filename);
    }

    return *m_fonts[filename];
}

////////////////////////////////////////////////////////////////////////////////
sf::SoundBuffer& ResourceManager::getSoundBuffer(const std::string& filename)
{
    if(m_soundBuffers.find(filename) == m_soundBuffers.end())
    {
        m_soundBuffers[filename] = std::make_shared<sf::SoundBuffer>();
        m_soundBuffers[filename]->loadFromFile(filename);
    }

    return *m_soundBuffers[filename];
}


} // namespace sfx
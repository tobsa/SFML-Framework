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
        sf::Texture texture;
        texture.loadFromFile(filename);
        m_textures[filename] = texture;
    }

    return m_textures[filename];
}

////////////////////////////////////////////////////////////////////////////////
sf::Font& ResourceManager::getFont(const std::string& filename)
{
    if(m_fonts.find(filename) == m_fonts.end())
    {
        sf::Font font;
        font.loadFromFile(filename);
        m_fonts[filename] = font;
    }

    return m_fonts[filename];
}

////////////////////////////////////////////////////////////////////////////////
sf::SoundBuffer& ResourceManager::getSoundBuffer(const std::string& filename)
{
    if(m_soundBuffers.find(filename) == m_soundBuffers.end())
    {
        sf::SoundBuffer soundBuffer;
        soundBuffer.loadFromFile(filename);
        m_soundBuffers[filename] = soundBuffer;
    }

    return m_soundBuffers[filename];
}


} // namespace sfx
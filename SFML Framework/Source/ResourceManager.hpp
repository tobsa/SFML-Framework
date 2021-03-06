////////////////////////////////////////////////////////////////////////////////
// Filename: ResourceManager.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef SFX_RESOURCE_MANAGER_HPP
#define SFX_RESOURCE_MANAGER_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Containers/Map.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <memory>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// A resource manager class that can store and load textures, fonts and
// and sound buffers
////////////////////////////////////////////////////////////////////////////////
class ResourceManager
{
private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private typedefs
    ////////////////////////////////////////////////////////////////////////////////
    typedef std::shared_ptr<sf::Texture>     TexturePtr;
    typedef std::shared_ptr<sf::Font>        FontPtr;
    typedef std::shared_ptr<sf::SoundBuffer> SoundBufferPtr;
    typedef Map<std::string, TexturePtr>     TextureMap;
    typedef Map<std::string, FontPtr>        FontMap;
    typedef Map<std::string, SoundBufferPtr> SoundBufferMap;

public:

    ////////////////////////////////////////////////////////////////////////////////
    // Retriev texture, font or sound buffer
    ////////////////////////////////////////////////////////////////////////////////
    sf::Texture& getTexture(const std::string& filename);
    sf::Font& getFont(const std::string& filename);
    sf::SoundBuffer& getSoundBuffer(const std::string& filename);

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private member data
    ////////////////////////////////////////////////////////////////////////////////
    TextureMap     m_textures;
    FontMap        m_fonts;
    SoundBufferMap m_soundBuffers;
};

} // namespace sfx

#endif

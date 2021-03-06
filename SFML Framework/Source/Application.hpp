////////////////////////////////////////////////////////////////////////////////
// Filename: Application.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef SFX_APPLICATION_HPP
#define SFX_APPLICATION_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include <SFML/Graphics/RenderWindow.hpp>
#include "Audio/AudioManager.hpp"
#include "GameSettings.hpp"
#include "ResourceManager.hpp"
#include "StateManager.hpp"


namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// The main application class
////////////////////////////////////////////////////////////////////////////////
class Application : public ResourceManager, public sf::RenderWindow, public GameSettings, public StateManager, public AudioManager
{
public:

    ////////////////////////////////////////////////////////////////////////////////
    // Create an application
    ////////////////////////////////////////////////////////////////////////////////
    Application(sf::VideoMode videoMode, const std::string& name, sf::Uint32 style = sf::Style::Default, unsigned int antialiasing = 0);
    Application(unsigned int width, unsigned int height, const std::string& name, sf::Uint32 style = sf::Style::Default, unsigned int antialiasing = 0);

    ////////////////////////////////////////////////////////////////////////////////
    // Get the mouse position
    ////////////////////////////////////////////////////////////////////////////////
    sf::Vector2f Application::getMousePosition() const;
};

} // namespace sfx

#endif

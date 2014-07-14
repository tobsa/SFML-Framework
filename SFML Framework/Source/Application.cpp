////////////////////////////////////////////////////////////////////////////////
// Filename: Application.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Application.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Utility/Utility.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
Application::Application(sf::VideoMode videoMode, const std::string& name, sf::Uint32 style, unsigned int antialiasing) :
    sf::RenderWindow (videoMode, name, style, sf::ContextSettings(0U, 0U, antialiasing, 2U, 0U))
{
}

////////////////////////////////////////////////////////////////////////////////
Application::Application(unsigned int width, unsigned int height, const std::string& name, sf::Uint32 style, unsigned int antialiasing) :
    sf::RenderWindow(sf::VideoMode(width, height), name, style, sf::ContextSettings(0U, 0U, antialiasing, 2U, 0U))
{
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f Application::getMousePosition() const
{
    return static_cast<sf::Vector2f>(sf::Mouse::getPosition(*this));
}

} // namespace sfx

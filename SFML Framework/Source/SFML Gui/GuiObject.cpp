////////////////////////////////////////////////////////////////////////////////
// Filename: GuiObject.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "GuiObject.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
GuiObject::~GuiObject()
{
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f GuiObject::getMousePosition(const sf::Event& event) const
{
    return static_cast<sf::Vector2f>(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
}

} // namespace sfx
////////////////////////////////////////////////////////////////////////////////
// Filename: Picture.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Picture.hpp"
#include "../Application.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
Picture::Picture(Application& application) :
    GuiObject (application)
{
}

////////////////////////////////////////////////////////////////////////////////
void Picture::onEvent(const sf::Event& event)
{
    // No events for a picture
}

////////////////////////////////////////////////////////////////////////////////
void Picture::onUpdate()
{
    // No updates for a picture...
}

////////////////////////////////////////////////////////////////////////////////
void Picture::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_sprite, states);
}

////////////////////////////////////////////////////////////////////////////////
const sf::Vector2f& Picture::getPosition() const
{
    return m_sprite.getPosition();
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f Picture::getSize() const
{
    return sf::Vector2f(m_sprite.getLocalBounds().width, m_sprite.getLocalBounds().height);
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f Picture::getCenter() const
{
    return sf::Vector2f(getPosition().x + getSize().x / 2.f, getPosition().y + getSize().y / 2.f);
}

////////////////////////////////////////////////////////////////////////////////
sf::FloatRect Picture::getBoundingBox() const
{
    return sf::FloatRect(getPosition().x, getPosition().y, getSize().x, getSize().y);
}

////////////////////////////////////////////////////////////////////////////////
void Picture::setPosition(const sf::Vector2f& position)
{
    m_sprite.setPosition(position);
}

////////////////////////////////////////////////////////////////////////////////
void Picture::setPosition(float x, float y)
{
    m_sprite.setPosition(x, y);
}

////////////////////////////////////////////////////////////////////////////////
void Picture::setX(float x)
{
    m_sprite.setPosition(x, getPosition().y);
}

////////////////////////////////////////////////////////////////////////////////
void Picture::setY(float y)
{
    m_sprite.setPosition(getPosition().x, y);
}

////////////////////////////////////////////////////////////////////////////////
bool Picture::intersects(const GuiObject& object) const
{
    return intersects(object.getBoundingBox());
}

////////////////////////////////////////////////////////////////////////////////
bool Picture::intersects(const sf::FloatRect& boundingBox) const
{
    return boundingBox.intersects(getBoundingBox());
}

////////////////////////////////////////////////////////////////////////////////
bool Picture::contains(const sf::Vector2f& position) const
{
    return contains(position.x, position.y);
}

////////////////////////////////////////////////////////////////////////////////
bool Picture::contains(float x, float y) const
{
    return getBoundingBox().contains(x, y);
}

////////////////////////////////////////////////////////////////////////////////
const sf::Texture& Picture::getTexture() const
{
    return *m_sprite.getTexture();
}

////////////////////////////////////////////////////////////////////////////////
void Picture::setTexture(const std::string& filename)
{
    m_sprite.setTexture(m_application.getTexture(filename));
}

////////////////////////////////////////////////////////////////////////////////
void Picture::setTexture(const sf::Texture& texture)
{
    m_sprite.setTexture(texture);
}

} // namespace sfx

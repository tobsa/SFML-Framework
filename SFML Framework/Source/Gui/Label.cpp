////////////////////////////////////////////////////////////////////////////////
// Filename: Label.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Label.hpp"
#include "../Application.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
Label::Label(Application& application) :
    GuiObject (application)
{

}

////////////////////////////////////////////////////////////////////////////////
void Label::onEvent(const sf::Event& event)
{
    // No events for a label...
}

////////////////////////////////////////////////////////////////////////////////
void Label::onUpdate()
{
    // No updates for a label
}

////////////////////////////////////////////////////////////////////////////////
void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(!isEnabled()) return;

    target.draw(m_text, states);
}

////////////////////////////////////////////////////////////////////////////////
const sf::Vector2f& Label::getPosition() const
{
    return m_text.getPosition();
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f Label::getSize() const
{
    return sf::Vector2f(m_text.getLocalBounds().width, m_text.getLocalBounds().height);
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f Label::getCenter() const
{
    return sf::Vector2f(getPosition().x + getSize().x / 2.f, getPosition().y + getSize().y / 2.f);
}

////////////////////////////////////////////////////////////////////////////////
sf::FloatRect Label::getBoundingBox() const
{
    return sf::FloatRect(getPosition().x, getPosition().y, getSize().x, getSize().y);
}

////////////////////////////////////////////////////////////////////////////////
void Label::setPosition(const sf::Vector2f& position)
{
    m_text.setPosition(position);
}

////////////////////////////////////////////////////////////////////////////////
void Label::setPosition(float x, float y)
{
    m_text.setPosition(x, y);
}

////////////////////////////////////////////////////////////////////////////////
void Label::setX(float x)
{
    setPosition(x, getPosition().y);
}

////////////////////////////////////////////////////////////////////////////////
void Label::setY(float y)
{
    setPosition(getPosition().x, y);
}

////////////////////////////////////////////////////////////////////////////////
bool Label::intersects(const GuiObject& object) const
{
    return intersects(object.getBoundingBox());
}

////////////////////////////////////////////////////////////////////////////////
bool Label::intersects(const sf::FloatRect& boundingBox) const
{
    return boundingBox.intersects(getBoundingBox());
}

////////////////////////////////////////////////////////////////////////////////
bool Label::contains(const sf::Vector2f& position) const
{
    return contains(position.x, position.y);
}

////////////////////////////////////////////////////////////////////////////////
bool Label::contains(float x, float y) const
{
    return getBoundingBox().contains(x, y);
}

////////////////////////////////////////////////////////////////////////////////
const std::string Label::getText() const
{
    return m_text.getString();
}

////////////////////////////////////////////////////////////////////////////////
const sf::Font& Label::getFont() const
{
    return *m_text.getFont();
}

////////////////////////////////////////////////////////////////////////////////
unsigned int Label::getCharacterSize() const
{
    return m_text.getCharacterSize();
}

////////////////////////////////////////////////////////////////////////////////
const sf::Color& Label::getColor() const
{
    return m_text.getColor();
}

////////////////////////////////////////////////////////////////////////////////
sf::Uint32 Label::getStyle() const
{
    return m_text.getStyle();
}

////////////////////////////////////////////////////////////////////////////////
void Label::setText(const std::string& text)
{
    m_text.setString(text);
}

////////////////////////////////////////////////////////////////////////////////
void Label::setFont(const std::string& filename)
{
    m_text.setFont(m_application.getFont(filename));
}

////////////////////////////////////////////////////////////////////////////////
void Label::setFont(const sf::Font& font)
{
    m_text.setFont(font);
}

////////////////////////////////////////////////////////////////////////////////
void Label::setCharacterSize(unsigned int size)
{
    m_text.setCharacterSize(size);
}

////////////////////////////////////////////////////////////////////////////////
void Label::setColor(const sf::Color& color)
{
    m_text.setColor(color);
}

////////////////////////////////////////////////////////////////////////////////
void Label::setStyle(sf::Uint32 style)
{
    m_text.setStyle(style);
}

} // namespace sfx

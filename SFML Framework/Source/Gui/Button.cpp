////////////////////////////////////////////////////////////////////////////////
// Filename: Button.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Button.hpp"
#include "../Application.hpp"
#include "../Utility/Utility.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
Button::Button(Application& application) :
    GuiObject (application)
{
}

////////////////////////////////////////////////////////////////////////////////
void Button::onEvent(const sf::Event& event)
{
    if(isDisabled()) return;

    if(event.type == sf::Event::MouseButtonPressed)
    {
        setPressed(isHover());

        if(isHover() && m_callbackPressed)
            m_callbackPressed();
    }

    if(event.type == sf::Event::MouseButtonReleased || event.type == sf::Event::MouseLeft)
    {
        if(isPressed() && m_callbackReleased)
            m_callbackReleased();

        setPressed(false);
    }
}

////////////////////////////////////////////////////////////////////////////////
void Button::onUpdate()
{
    if(isDisabled()) return;

    bool hover = contains(m_application.mapPixelToCoords(static_cast<sf::Vector2i>(m_application.getMousePosition())));
    setHover(hover);

    if(hover && m_callbackHover)
        m_callbackHover();


    if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && !sf::Mouse::isButtonPressed(sf::Mouse::Right))
        setPressed(false);
}

////////////////////////////////////////////////////////////////////////////////
void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(isDisabled()) return;

    if(isPressed())
        target.draw(m_sprites[2], states);
    else if(isHover())
        target.draw(m_sprites[1], states);
    else
        target.draw(m_sprites[0], states);
}

////////////////////////////////////////////////////////////////////////////////
const sf::Vector2f& Button::getPosition() const
{
    return m_sprites[0].getPosition();
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f Button::getSize() const
{
    return sf::Vector2f(m_sprites[0].getLocalBounds().width, m_sprites[0].getLocalBounds().height);
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f Button::getCenter() const
{
    return sf::Vector2f(getPosition().x + getSize().x / 2.f, getPosition().y + getSize().y / 2.f);
}

////////////////////////////////////////////////////////////////////////////////
sf::FloatRect Button::getBoundingBox() const
{
    return sf::FloatRect(getPosition().x, getPosition().y, getSize().x, getSize().y);
}

////////////////////////////////////////////////////////////////////////////////
void Button::setPosition(const sf::Vector2f& position)
{
    for(auto& sprite : m_sprites)
        sprite.setPosition(position);
}

////////////////////////////////////////////////////////////////////////////////
void Button::setPosition(float x, float y)
{
    setPosition(sf::Vector2f(x, y));
}

////////////////////////////////////////////////////////////////////////////////
void Button::setX(float x)
{
    setPosition(x, getPosition().y);
}

////////////////////////////////////////////////////////////////////////////////
void Button::setY(float y)
{
    setPosition(getPosition().x, y);
}

////////////////////////////////////////////////////////////////////////////////
bool Button::intersects(const GuiObject& object) const
{
    return intersects(object.getBoundingBox());
}

////////////////////////////////////////////////////////////////////////////////
bool Button::intersects(const sf::FloatRect& boundingBox) const
{
    return boundingBox.intersects(getBoundingBox());
}

////////////////////////////////////////////////////////////////////////////////
bool Button::contains(const sf::Vector2f& position) const
{
    return contains(position.x, position.y);
}

////////////////////////////////////////////////////////////////////////////////
bool Button::contains(float x, float y) const
{
    return getBoundingBox().contains(x, y);
}

////////////////////////////////////////////////////////////////////////////////
const sf::Texture& Button::getTexture(std::size_t index) const
{
    return *m_sprites[sfx::clamp(index, 0U, 2U)].getTexture();
}

////////////////////////////////////////////////////////////////////////////////
void Button::setTexture(std::size_t index, const std::string& filename)
{
    m_sprites[sfx::clamp(index, 0U, 2U)].setTexture(m_application.getTexture(filename));
}

////////////////////////////////////////////////////////////////////////////////
void Button::setTexture(std::size_t index, const sf::Texture& texture)
{
    m_sprites[sfx::clamp(index, 0U, 2U)].setTexture(texture);
}

////////////////////////////////////////////////////////////////////////////////
void Button::setTexture(const std::string& filename)
{
    setTexture(0, filename + "/Normal.png");
    setTexture(1, filename + "/Hover.png");
    setTexture(2, filename + "/Pressed.png");
}

////////////////////////////////////////////////////////////////////////////////
void Button::callback(std::size_t index, const Function& callback)
{
    switch(index)
    {
        case 0: m_callbackHover    = callback; break;
        case 1: m_callbackPressed  = callback; break;
        case 2: m_callbackReleased = callback; break;
    }
}

} // namespace sfx


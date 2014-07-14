////////////////////////////////////////////////////////////////////////////////
// Filename: RadioButton.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "RadioButton.hpp"
#include "../Application.hpp"
#include "../Utility/Utility.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace sfx
{

RadioButton::RadioButtonVector RadioButton::m_radioButtons;

////////////////////////////////////////////////////////////////////////////////
RadioButton::RadioButton(Application& application) :
    GuiObject (application)
{
    m_radioButtons.addBack(this);
}

////////////////////////////////////////////////////////////////////////////////
void RadioButton::onEvent(const sf::Event& event)
{
    if(isDisabled()) return;

    if(event.type == sf::Event::MouseButtonPressed)
    {
        if(isHover() && !isPressed())
            press();
    }
}

////////////////////////////////////////////////////////////////////////////////
void RadioButton::onUpdate()
{
    if(isDisabled()) return;

    bool hover = contains(m_application.mapPixelToCoord(m_application.getMousePosition()));
    setHover(hover);

    if(hover && m_callbackHover)
        m_callbackHover();
}

////////////////////////////////////////////////////////////////////////////////
void RadioButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
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
const sf::Vector2f& RadioButton::getPosition() const
{
    return m_sprites[0].getPosition();
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f RadioButton::getSize() const
{
    return sf::Vector2f(m_sprites[0].getLocalBounds().width, m_sprites[0].getLocalBounds().height);
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f RadioButton::getCenter() const
{
    return sf::Vector2f(getPosition().x + getSize().x / 2.f, getPosition().y + getSize().y / 2.f);
}

////////////////////////////////////////////////////////////////////////////////
sf::FloatRect RadioButton::getBoundingBox() const
{
    return sf::FloatRect(getPosition().x, getPosition().y, getSize().x, getSize().y);
}

////////////////////////////////////////////////////////////////////////////////
void RadioButton::setPosition(const sf::Vector2f& position)
{
    for(auto& sprite : m_sprites)
        sprite.setPosition(position);
}

////////////////////////////////////////////////////////////////////////////////
void RadioButton::setPosition(float x, float y)
{
    setPosition(sf::Vector2f(x, y));
}

////////////////////////////////////////////////////////////////////////////////
void RadioButton::setX(float x)
{
    setPosition(x, getPosition().y);
}

////////////////////////////////////////////////////////////////////////////////
void RadioButton::setY(float y)
{
    setPosition(getPosition().x, y);
}

////////////////////////////////////////////////////////////////////////////////
bool RadioButton::intersects(const GuiObject& object) const
{
    return intersects(object.getBoundingBox());
}

////////////////////////////////////////////////////////////////////////////////
bool RadioButton::intersects(const sf::FloatRect& boundingBox) const
{
    return boundingBox.intersects(getBoundingBox());
}

////////////////////////////////////////////////////////////////////////////////
bool RadioButton::contains(const sf::Vector2f& position) const
{
    return contains(position.x, position.y);
}

////////////////////////////////////////////////////////////////////////////////
bool RadioButton::contains(float x, float y) const
{
    return getBoundingBox().contains(x, y);
}

////////////////////////////////////////////////////////////////////////////////
const sf::Texture& RadioButton::getTexture(std::size_t index) const
{
    return *m_sprites[sfx::clamp(index, 0U, 2U)].getTexture();
}

////////////////////////////////////////////////////////////////////////////////
void RadioButton::setTexture(std::size_t index, const std::string& filename)
{
    m_sprites[sfx::clamp(index, 0U, 2U)].setTexture(m_application.getTexture(filename));
}

////////////////////////////////////////////////////////////////////////////////
void RadioButton::setTexture(std::size_t index, const sf::Texture& texture)
{
    m_sprites[sfx::clamp(index, 0U, 2U)].setTexture(texture);
}

////////////////////////////////////////////////////////////////////////////////
void RadioButton::setTexture(const std::string& filename)
{
    setTexture(0, filename + "/Normal.png");
    setTexture(1, filename + "/Hover.png");
    setTexture(2, filename + "/Pressed.png");
}

////////////////////////////////////////////////////////////////////////////////
void RadioButton::setGroup(const std::string& group)
{
    m_group = group;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& RadioButton::getGroup() const
{
    return m_group;
}

////////////////////////////////////////////////////////////////////////////////
void RadioButton::callback(std::size_t index, const Function& callback)
{
    switch(index)
    {
        case 0: m_callbackHover    = callback; break;
        case 1: m_callbackPressed  = callback; break;
        case 2: m_callbackReleased = callback; break;
    }
}

////////////////////////////////////////////////////////////////////////////////
void RadioButton::press()
{
    setPressed(true);

    if(m_callbackPressed)
        m_callbackPressed();

    // Unpress all other buttons in the same group as this button
    for(auto& button : m_radioButtons)
    {
        if(button != this && button->m_group == m_group)
        {
            button->setPressed(false);
            
            if(m_callbackReleased)
                m_callbackReleased();
        }
    }
}

} // namespace sfx
////////////////////////////////////////////////////////////////////////////////
// Filename: CheckBox.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "CheckBox.hpp"
#include "../Application.hpp"
#include "../Utility.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
CheckBox::CheckBox(Application& application) :
    GuiObject (application)
{
}

////////////////////////////////////////////////////////////////////////////////
void CheckBox::onEvent(const sf::Event& event)
{
    if(event.type == sf::Event::MouseMoved)
    {
        setHover(contains(getMousePosition(event)));
    }

    if(event.type == sf::Event::MouseButtonPressed)
    {
        if(isHover())
            setPressed(!isPressed());
    }
}

////////////////////////////////////////////////////////////////////////////////
void CheckBox::onUpdate()
{
    if(!contains(m_application.getMousePosition()))
        setHover(false);
}

////////////////////////////////////////////////////////////////////////////////
void CheckBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(isPressed() && isHover())
        target.draw(m_sprites[3], states);
    else if(isPressed())
        target.draw(m_sprites[2], states);
    else if(isHover())
        target.draw(m_sprites[1], states);
    else
        target.draw(m_sprites[0], states);
}

////////////////////////////////////////////////////////////////////////////////
const sf::Vector2f& CheckBox::getPosition() const
{
    return m_sprites[0].getPosition();
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f CheckBox::getSize() const
{
    return sf::Vector2f(m_sprites[0].getLocalBounds().width, m_sprites[0].getLocalBounds().height);
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f CheckBox::getCenter() const
{
    return sf::Vector2f(getPosition().x + getSize().x / 2.f, getPosition().y + getSize().y / 2.f);
}

////////////////////////////////////////////////////////////////////////////////
sf::FloatRect CheckBox::getBoundingBox() const
{
    return sf::FloatRect(getPosition().x, getPosition().y, getSize().x, getSize().y);
}

////////////////////////////////////////////////////////////////////////////////
void CheckBox::setPosition(const sf::Vector2f& position)
{
    for(auto& sprite : m_sprites)
        sprite.setPosition(position);
}

////////////////////////////////////////////////////////////////////////////////
void CheckBox::setPosition(float x, float y)
{
    setPosition(sf::Vector2f(x, y));
}

////////////////////////////////////////////////////////////////////////////////
void CheckBox::setX(float x)
{
    setPosition(x, getPosition().y);
}

////////////////////////////////////////////////////////////////////////////////
void CheckBox::setY(float y)
{
    setPosition(getPosition().x, y);
}

////////////////////////////////////////////////////////////////////////////////
bool CheckBox::intersects(const GuiObject& object) const
{
    return intersects(object.getBoundingBox());
}

////////////////////////////////////////////////////////////////////////////////
bool CheckBox::intersects(const sf::FloatRect& boundingBox) const
{
    return boundingBox.intersects(getBoundingBox());
}

////////////////////////////////////////////////////////////////////////////////
bool CheckBox::contains(const sf::Vector2f& position) const
{
    return contains(position.x, position.y);
}

////////////////////////////////////////////////////////////////////////////////
bool CheckBox::contains(float x, float y) const
{
    return getBoundingBox().contains(x, y);
}

////////////////////////////////////////////////////////////////////////////////
const sf::Texture& CheckBox::getTexture(std::size_t index) const
{
    return *m_sprites[sfx::clamp(index, 0U, 3U)].getTexture();
}

////////////////////////////////////////////////////////////////////////////////
void CheckBox::setTexture(std::size_t index, const std::string& filename)
{
    m_sprites[sfx::clamp(index, 0U, 3U)].setTexture(m_application.getTexture(filename));
}

////////////////////////////////////////////////////////////////////////////////
void CheckBox::setTexture(std::size_t index, const sf::Texture& texture)
{
    m_sprites[sfx::clamp(index, 0U, 3U)].setTexture(texture);
}

////////////////////////////////////////////////////////////////////////////////
void CheckBox::setTexture(const std::string& filename)
{
    setTexture(0, filename + "/Normal.png");
    setTexture(1, filename + "/Hover.png");
    setTexture(2, filename + "/Checked.png");
    setTexture(3, filename + "/HoverChecked.png");
}

////////////////////////////////////////////////////////////////////////////////
bool CheckBox::isChecked() const
{
    return isPressed();
}

////////////////////////////////////////////////////////////////////////////////
void CheckBox::setChecked(bool checked)
{
    setPressed(checked);
}

} // namespace sfx
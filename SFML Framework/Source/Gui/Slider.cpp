////////////////////////////////////////////////////////////////////////////////
// Filename: Slider.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Slider.hpp"
#include "../Application.hpp"
#include "../Utility/Utility.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
Slider::Slider(Application& application) :
    GuiObject (application),
    m_minimum (0.f),
    m_maximum (100.f)
{
}

////////////////////////////////////////////////////////////////////////////////
void Slider::onEvent(const sf::Event& event)
{
    if(!isEnabled()) return;

    if(event.type == sf::Event::MouseMoved)
    {
        const sf::Vector2f mouse = getMousePosition(event);

        setHover(contains(mouse) || sfx::getBoundingBox(m_sprites[1]).contains(mouse));

        if(isPressed())
        {
            // For easier access
            float x0 = m_sprites[0].getPosition().x;
            float x1 = m_sprites[1].getPosition().x;
            float w0 = m_sprites[0].getLocalBounds().width;
            float w1 = m_sprites[1].getLocalBounds().width;

            //Set the position of the slider
            m_sprites[1].setPosition(sfx::clamp(mouse.x, x0, x0 + w0) - w1 / 2.f, m_sprites[1].getPosition().y);

            // Calculate the current value
            m_value = (m_maximum - m_minimum) * ((x1 + w1 / 2.f) - x0) / (x0 + w0 - x0) + m_minimum;

            // Perform moved callback
            for(const auto& callback : m_movedCallbacks)
                callback();
        }
    }

    if(event.type == sf::Event::MouseButtonPressed)
    {
        if(isHover())
        {
            // Perform pressed callbacks
            for(const auto& callback : m_pressedCallbacks)
                callback();
        }

        setPressed(isHover());
    }

    if(event.type == sf::Event::MouseButtonReleased)
    {
        if(isPressed())
        {
            // Perform released callbacks
            for(const auto& callback : m_releasedCallbacks)
                callback();
        }

        setPressed(false);
    }
}

////////////////////////////////////////////////////////////////////////////////
void Slider::onUpdate()
{
    if(!isEnabled()) return;

    if(!contains(m_application.getMousePosition()) && !sfx::getBoundingBox(m_sprites[1]).contains(m_application.getMousePosition()))
        setHover(false);
    if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && !sf::Mouse::isButtonPressed(sf::Mouse::Right))
        setPressed(false);
}

////////////////////////////////////////////////////////////////////////////////
void Slider::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(!isEnabled()) return;

    for(const auto& sprite : m_sprites)
        target.draw(sprite, states);
}

////////////////////////////////////////////////////////////////////////////////
const sf::Vector2f& Slider::getPosition() const
{
    return m_sprites[0].getPosition();
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f Slider::getSize() const
{
    return sf::Vector2f(m_sprites[0].getLocalBounds().width, m_sprites[0].getLocalBounds().height);
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f Slider::getCenter() const
{
    return sf::Vector2f(getPosition().x + getSize().x / 2.f, getPosition().y + getSize().y / 2.f);
}

////////////////////////////////////////////////////////////////////////////////
sf::FloatRect Slider::getBoundingBox() const
{
    return sf::FloatRect(getPosition().x, getPosition().y, getSize().x, getSize().y);
}

////////////////////////////////////////////////////////////////////////////////
void Slider::setPosition(const sf::Vector2f& position)
{
    m_sprites[0].setPosition(position);
    m_sprites[1].setPosition(position.x, position.y + getSize().y / 2.f - m_sprites[1].getLocalBounds().height / 2.f);

    // Update value position
    setValue(getValue());
}

////////////////////////////////////////////////////////////////////////////////
void Slider::setPosition(float x, float y)
{
    setPosition(sf::Vector2f(x, y));
}

////////////////////////////////////////////////////////////////////////////////
void Slider::setX(float x)
{
    setPosition(x, getPosition().y);
}

////////////////////////////////////////////////////////////////////////////////
void Slider::setY(float y)
{
    setPosition(getPosition().x, y);
}

////////////////////////////////////////////////////////////////////////////////
bool Slider::intersects(const GuiObject& object) const
{
    return intersects(object.getBoundingBox());
}

////////////////////////////////////////////////////////////////////////////////
bool Slider::intersects(const sf::FloatRect& boundingBox) const
{
    return boundingBox.intersects(getBoundingBox());
}

////////////////////////////////////////////////////////////////////////////////
bool Slider::contains(const sf::Vector2f& position) const
{
    return contains(position.x, position.y);
}

////////////////////////////////////////////////////////////////////////////////
bool Slider::contains(float x, float y) const
{
    return getBoundingBox().contains(x, y);
}

////////////////////////////////////////////////////////////////////////////////
const sf::Texture& Slider::getTexture(std::size_t index) const
{
    return *m_sprites[sfx::clamp(index, 0U, 1U)].getTexture();
}

////////////////////////////////////////////////////////////////////////////////
void Slider::setTexture(std::size_t index, const std::string& filename)
{
    m_sprites[sfx::clamp(index, 0U, 1U)].setTexture(m_application.getTexture(filename));
    setPosition(getPosition());
}

////////////////////////////////////////////////////////////////////////////////
void Slider::setTexture(std::size_t index, const sf::Texture& texture)
{
    m_sprites[sfx::clamp(index, 0U, 1U)].setTexture(texture);
    setPosition(getPosition());
}

////////////////////////////////////////////////////////////////////////////////
void Slider::setTexture(const std::string& filename)
{
    setTexture(0, filename + "/Bar.png");
    setTexture(1, filename + "/Slider.png");
}

////////////////////////////////////////////////////////////////////////////////
float Slider::getMinimum() const
{
    return m_minimum;
}

////////////////////////////////////////////////////////////////////////////////
float Slider::getMaximum() const
{
    return m_maximum;
}

////////////////////////////////////////////////////////////////////////////////
float Slider::getValue() const
{
    return m_value;
}

////////////////////////////////////////////////////////////////////////////////
void Slider::setMinimum(float min)
{
    m_minimum = sfx::clamp(min, min, m_maximum);
}

////////////////////////////////////////////////////////////////////////////////
void Slider::setMaximum(float max)
{
    m_maximum = sfx::clamp(max, m_minimum, max);
}

////////////////////////////////////////////////////////////////////////////////
void Slider::setValue(float value)
{
    // Make sure we stay within the min and max values
    m_value = sfx::clamp(value, m_minimum, m_maximum);

    // Calculate the position of the slider
    float percentage = (m_value - m_minimum) / (m_maximum - m_minimum);
    float position   = m_sprites[0].getPosition().x + m_sprites[0].getLocalBounds().width * percentage;

    // Set the slider position
    m_sprites[1].setPosition(position - m_sprites[1].getLocalBounds().width / 2.f, m_sprites[1].getPosition().y);
}

////////////////////////////////////////////////////////////////////////////////
void Slider::addPressedCallback(const std::function<void()>& callback)
{
    m_pressedCallbacks.push_back(callback);
}

////////////////////////////////////////////////////////////////////////////////
void Slider::addMovedCallback(const std::function<void()>& callback)
{
    m_movedCallbacks.push_back(callback);
}

////////////////////////////////////////////////////////////////////////////////
void Slider::addReleasedCallback(const std::function<void()>& callback)
{
    m_releasedCallbacks.push_back(callback);
}

} // namespace sfx
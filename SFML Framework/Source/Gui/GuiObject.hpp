////////////////////////////////////////////////////////////////////////////////
// Filename: GuiObject.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef GUI_OBJECT_HPP
#define GUI_OBJECT_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include <SFML/Graphics/Drawable.hpp>

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////
namespace sfx { class Application; }
namespace sf  { class Event;       }

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// Represent a base gui object. All gui object should inherit from this
////////////////////////////////////////////////////////////////////////////////
class GuiObject : public sf::Drawable
{
public:

    ////////////////////////////////////////////////////////////////////////////////
    // Default constructor
    ////////////////////////////////////////////////////////////////////////////////
    GuiObject(Application& application);

    ////////////////////////////////////////////////////////////////////////////////
    // Destroy the gui object
    ////////////////////////////////////////////////////////////////////////////////
    virtual ~GuiObject();

    ////////////////////////////////////////////////////////////////////////////////
    // Process events
    ////////////////////////////////////////////////////////////////////////////////
    virtual void onEvent(const sf::Event& event) = 0;

    ////////////////////////////////////////////////////////////////////////////////
    // Update the gui object
    ////////////////////////////////////////////////////////////////////////////////
    virtual void onUpdate() = 0;

    ////////////////////////////////////////////////////////////////////////////////
    // Draw the gui object
    ////////////////////////////////////////////////////////////////////////////////
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

    ////////////////////////////////////////////////////////////////////////////////
    // Get the position, size, center and bounding box of the object
    ////////////////////////////////////////////////////////////////////////////////
    virtual const sf::Vector2f& getPosition() const = 0;
    virtual sf::Vector2f getSize() const = 0;
    virtual sf::Vector2f getCenter() const = 0;
    virtual sf::FloatRect getBoundingBox() const = 0;

    ////////////////////////////////////////////////////////////////////////////////
    // Set a new position for the gui object
    ////////////////////////////////////////////////////////////////////////////////
    virtual void setPosition(const sf::Vector2f& position) = 0;
    virtual void setPosition(float x, float y) = 0;
    virtual void setX(float x) = 0;
    virtual void setY(float y) = 0;

    ////////////////////////////////////////////////////////////////////////////////
    // Check if another gui object or bounding box intersects 
    ////////////////////////////////////////////////////////////////////////////////
    virtual bool intersects(const GuiObject& object) const = 0;
    virtual bool intersects(const sf::FloatRect& boundingBox) const = 0;

    ////////////////////////////////////////////////////////////////////////////////
    // Check if a single point is inside the gui object
    ////////////////////////////////////////////////////////////////////////////////
    virtual bool contains(const sf::Vector2f& position) const = 0;
    virtual bool contains(float x, float y) const = 0;

    ////////////////////////////////////////////////////////////////////////////////
    // Enable/disable a gui object
    ////////////////////////////////////////////////////////////////////////////////
    void enable();
    void disable();
    bool isEnabled() const;
    bool isDisabled() const;

protected:

    ////////////////////////////////////////////////////////////////////////////////
    // Check if hovering or pressed
    ////////////////////////////////////////////////////////////////////////////////
    bool isHover() const;
    bool isPressed() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Set hover or pressed status
    ////////////////////////////////////////////////////////////////////////////////
    void setHover(bool hover);
    void setPressed(bool pressed);

protected:

    ////////////////////////////////////////////////////////////////////////////////
    // Protected member data
    ////////////////////////////////////////////////////////////////////////////////
    Application& m_application;

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private member dat
    ////////////////////////////////////////////////////////////////////////////////
    bool m_hover;
    bool m_pressed;
    bool m_enabled;
};

} // namespace sfx

#endif
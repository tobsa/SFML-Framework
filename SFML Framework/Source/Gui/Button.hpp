////////////////////////////////////////////////////////////////////////////////
// Filename: Button.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef SFX_BUTTON_HPP
#define SFX_BUTTON_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "GuiObject.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <functional>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// A basic gui push button
////////////////////////////////////////////////////////////////////////////////
class Button : public GuiObject
{
private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private typedefs
    ////////////////////////////////////////////////////////////////////////////////
    typedef std::function<void()> Function;

public:

    ////////////////////////////////////////////////////////////////////////////////
    // Create a button
    ////////////////////////////////////////////////////////////////////////////////
    Button(Application& application);

    ////////////////////////////////////////////////////////////////////////////////
    // Process events
    ////////////////////////////////////////////////////////////////////////////////
    virtual void onEvent(const sf::Event& event);

    ////////////////////////////////////////////////////////////////////////////////
    // Update the gui object
    ////////////////////////////////////////////////////////////////////////////////
    virtual void onUpdate();

    ////////////////////////////////////////////////////////////////////////////////
    // Draw the gui object
    ////////////////////////////////////////////////////////////////////////////////
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    ////////////////////////////////////////////////////////////////////////////////
    // Get the position, size, center and bounding box of the object
    ////////////////////////////////////////////////////////////////////////////////
    virtual const sf::Vector2f& getPosition() const;
    virtual sf::Vector2f getSize() const;
    virtual sf::Vector2f getCenter() const;
    virtual sf::FloatRect getBoundingBox() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Set a new position for the gui object
    ////////////////////////////////////////////////////////////////////////////////
    virtual void setPosition(const sf::Vector2f& position);
    virtual void setPosition(float x, float y);
    virtual void setX(float x);
    virtual void setY(float y);

    ////////////////////////////////////////////////////////////////////////////////
    // Check if another gui object or bounding box intersects 
    ////////////////////////////////////////////////////////////////////////////////
    virtual bool intersects(const GuiObject& object) const;
    virtual bool intersects(const sf::FloatRect& boundingBox) const;

    ////////////////////////////////////////////////////////////////////////////////
    // Check if a single point is inside the gui object
    ////////////////////////////////////////////////////////////////////////////////
    virtual bool contains(const sf::Vector2f& position) const;
    virtual bool contains(float x, float y) const;

    ////////////////////////////////////////////////////////////////////////////////
    // Get the texture specified by an index
    // 0 = Normal texture
    // 1 = Hover texture
    // 2 = Pressed texture
    ////////////////////////////////////////////////////////////////////////////////
    const sf::Texture& getTexture(std::size_t index) const;

    ////////////////////////////////////////////////////////////////////////////////
    // Set the texture. See getTexture() for correct indices
    ////////////////////////////////////////////////////////////////////////////////
    void setTexture(std::size_t index, const std::string& filename);
    void setTexture(std::size_t index, const sf::Texture& texture);

    ////////////////////////////////////////////////////////////////////////////////
    // This method will attempt to load three images located in the filename.
    // Example: If filename is "Data/Images/Button" 
    // This method will try and load three images named Normal.png, Hover.png and
    // Pressed.png in a folder named Button in the path Data/Images.
    ////////////////////////////////////////////////////////////////////////////////
    void setTexture(const std::string& filename);

    ////////////////////////////////////////////////////////////////////////////////
    // Set callback function
    // Index 0 : On hover
    // Index 1 : On pressed
    // Index 2 : On released
    ////////////////////////////////////////////////////////////////////////////////
    void callback(std::size_t index, const Function& callback);

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private member data
    ////////////////////////////////////////////////////////////////////////////////
    sf::Sprite     m_sprites[3];
    Function       m_callbackHover;
    Function       m_callbackPressed;
    Function       m_callbackReleased;
};

} // namespace sfx

#endif
////////////////////////////////////////////////////////////////////////////////
// Filename: Label.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef SFX_LABEL_HPP
#define SFX_LABEL_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "GuiObject.hpp"
#include <SFML/Graphics/Text.hpp>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// A simple way to create a label
////////////////////////////////////////////////////////////////////////////////
class Label : public GuiObject 
{
public:

    ////////////////////////////////////////////////////////////////////////////////
    // Create a label
    ////////////////////////////////////////////////////////////////////////////////
    Label(Application& application);

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
    // Get the labels text, font, size, color and style
    ////////////////////////////////////////////////////////////////////////////////
    const std::string getText() const;
    const sf::Font& getFont() const;
    unsigned int getCharacterSize() const;
    const sf::Color& getColor() const;
    sf::Uint32 getStyle() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Set the labels text, font, size, color or style
    ////////////////////////////////////////////////////////////////////////////////
    void setText(const std::string& text);
    void setFont(const std::string& filename);
    void setFont(const sf::Font& font);
    void setCharacterSize(unsigned int size);
    void setColor(const sf::Color& color);
    void setStyle(sf::Uint32 style);

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private member data
    ////////////////////////////////////////////////////////////////////////////////
    sf::Text m_text;
};

} // namespace sfx

#endif
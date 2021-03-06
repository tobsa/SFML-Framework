////////////////////////////////////////////////////////////////////////////////
// Filename: TextEditBox.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef SFX_TEXT_EDIT_BOX_HPP
#define SFX_TEXT_EDIT_BOX_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "GuiObject.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <functional>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// A simple box with some basic text editing capabilities
////////////////////////////////////////////////////////////////////////////////
class TextEditBox : public GuiObject
{
private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private typedefs
    ////////////////////////////////////////////////////////////////////////////////
    typedef std::function<void()> Function;

public:

    ////////////////////////////////////////////////////////////////////////////////
    // Create a text edit box
    ////////////////////////////////////////////////////////////////////////////////
    TextEditBox(Application& application);

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
    // Example: If filename = "Data/Images/TextEditBox" 
    // This method will try and load three images named Normal.png, Hover.png and
    // Pressed.png in a folder named TextEditBox in the path Data/Images.
    ////////////////////////////////////////////////////////////////////////////////
    void setTexture(const std::string& filename);

    ////////////////////////////////////////////////////////////////////////////////
    // Get the current text, font, character size, or style
    ////////////////////////////////////////////////////////////////////////////////
    std::string getText() const;
    const sf::Font& getFont() const;
    unsigned int getCharacterSize() const;
    const sf::Color& getColor() const;
    sf::Uint32 getStyle() const;
    
    ////////////////////////////////////////////////////////////////////////////////
    // Set the text, font, chararcter size, color or style
    ////////////////////////////////////////////////////////////////////////////////
    void setText(const std::string& text);
    void setFont(const std::string& filename);
    void setFont(const sf::Font& font);
    void setCharacterSize(unsigned int size);
    void setColor(const sf::Color& color);
    void setStyle(sf::Uint32 style);

    ////////////////////////////////////////////////////////////////////////////////
    // Get the text position and caret size
    ////////////////////////////////////////////////////////////////////////////////
    const sf::Vector2f& getTextPosition() const;
    std::size_t getCaretSize() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Get the max amount of characters that can be typed into the edit box
    ////////////////////////////////////////////////////////////////////////////////
    std::size_t getMaxCharacters() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Set the text position and caret size
    ////////////////////////////////////////////////////////////////////////////////
    void setTextPosition(const sf::Vector2f& position);
    void setTextPosition(float x, float y);
    void setCaretSize(std::size_t size);

    ////////////////////////////////////////////////////////////////////////////////
    // Set the max amount of characters that can be typed into the text box
    ////////////////////////////////////////////////////////////////////////////////
    void setMaxCharacters(std::size_t maxCharacters);

    ////////////////////////////////////////////////////////////////////////////////
    // Add a callback to the text edit box
    // Index 0: On hover
    // Index 1: On pressed
    // Index 2: On released
    // Index 3: On text entered
    ////////////////////////////////////////////////////////////////////////////////
    void callback(std::size_t index, const Function& callback);

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Update the text and caret
    ////////////////////////////////////////////////////////////////////////////////
    void updateText();
    void updateCaret();

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private member data
    ////////////////////////////////////////////////////////////////////////////////
    sf::Sprite         m_sprites[3];
    sf::Text           m_text;
    std::size_t        m_maxCharacters;
    sf::RectangleShape m_caret;
    Function           m_callbackHover;
    Function           m_callbackPressed;
    Function           m_callbackReleased;
    Function           m_callbackTextEntered;
};

}

#endif
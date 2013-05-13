////////////////////////////////////////////////////////////////////////////////
// Filename: CheckBox.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef CHECK_BOX_HPP
#define CHECK_BOX_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "GuiObject.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <functional>
#include <vector>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// A check box object
////////////////////////////////////////////////////////////////////////////////
class CheckBox : public GuiObject
{
public:

    ////////////////////////////////////////////////////////////////////////////////
    // Create a check box
    ////////////////////////////////////////////////////////////////////////////////
    CheckBox(Application& application);

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
    // 2 = Checked texture
    // 3 = Checked and hover texture
    ////////////////////////////////////////////////////////////////////////////////
    const sf::Texture& getTexture(std::size_t index) const;

    ////////////////////////////////////////////////////////////////////////////////
    // Set the texture. See getTexture() for correct indices
    ////////////////////////////////////////////////////////////////////////////////
    void setTexture(std::size_t index, const std::string& filename);
    void setTexture(std::size_t index, const sf::Texture& texture);

    ////////////////////////////////////////////////////////////////////////////////
    // This method will attempt to load four images located in the filename.
    // Example: If filename is "Data/Images/CheckBox" 
    // This method will try and load four images named Normal.png, Hover.png, 
    // Checked.png and HoverChecked.png in a folder named CheckBox in the path 
    // Data/Images.
    ////////////////////////////////////////////////////////////////////////////////
    void setTexture(const std::string& filename);

    ////////////////////////////////////////////////////////////////////////////////
    // Get checked status
    ////////////////////////////////////////////////////////////////////////////////
    bool isChecked() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Set checked status
    ////////////////////////////////////////////////////////////////////////////////
    void setChecked(bool checked);

    ////////////////////////////////////////////////////////////////////////////////
    // Add a callback function to the check box
    ////////////////////////////////////////////////////////////////////////////////
    void addIsCheckedCallback(const std::function<void()>& callback);
    void addNoCheckedCallback(const std::function<void()>& callback);

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private typedefs
    ////////////////////////////////////////////////////////////////////////////////
    typedef std::vector<std::function<void()>> Callbacks;

    ////////////////////////////////////////////////////////////////////////////////
    // Private member data
    ////////////////////////////////////////////////////////////////////////////////
    sf::Sprite m_sprites[4];
    Callbacks  m_isCheckedCallbacks;
    Callbacks  m_noCheckedCallbacks;
};

} // namespace sfx

#endif
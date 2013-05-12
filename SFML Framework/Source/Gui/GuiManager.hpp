////////////////////////////////////////////////////////////////////////////////
// Filename: GuiManager.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef GUI_MANAGER_HPP
#define GUI_MANAGER_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "GuiObject.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <memory>
#include <map>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////
class Application;

////////////////////////////////////////////////////////////////////////////////
// A gui manager that can create, load and store gui objects
////////////////////////////////////////////////////////////////////////////////
class GuiManager : public sf::Drawable
{
private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private typedefs
    ////////////////////////////////////////////////////////////////////////////////
    typedef std::shared_ptr<GuiObject>          GuiObjectPtr;
    typedef std::map<std::string, GuiObjectPtr> GuiObjectMap;

public:

    ////////////////////////////////////////////////////////////////////////////////
    // Create a gui manager
    ////////////////////////////////////////////////////////////////////////////////
    GuiManager(Application& application);
    
    ////////////////////////////////////////////////////////////////////////////////
    // Add a gui object to the manager. If the key already exist the previous value
    // will be overwritten.
    ////////////////////////////////////////////////////////////////////////////////
    template<typename T> T& create(const std::string& key);

    ////////////////////////////////////////////////////////////////////////////////
    // Get a gui object specified by a key. If the key doesn't exist then an error
    // is thrown.
    ////////////////////////////////////////////////////////////////////////////////
    template<typename T> T& get(const std::string& key);

    ////////////////////////////////////////////////////////////////////////////////
    // Remove a gui object from the manager. Any references to the object will be
    // invalidated.
    ////////////////////////////////////////////////////////////////////////////////
    void remove(const std::string& key);

    ////////////////////////////////////////////////////////////////////////////////
    // Handle events
    ////////////////////////////////////////////////////////////////////////////////
    void onEvent(const sf::Event& event);

    ////////////////////////////////////////////////////////////////////////////////
    // Update all gui objects
    ////////////////////////////////////////////////////////////////////////////////
    void onUpdate();

    ////////////////////////////////////////////////////////////////////////////////
    // Draw all the gui objects in the manager
    ////////////////////////////////////////////////////////////////////////////////
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private member data
    ////////////////////////////////////////////////////////////////////////////////
    Application& m_application;
    GuiObjectMap m_objects;
};

} // namespace sfx

////////////////////////////////////////////////////////////////////////////////
// Inline files
////////////////////////////////////////////////////////////////////////////////
#include "GuiManager.inl"

#endif
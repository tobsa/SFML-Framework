////////////////////////////////////////////////////////////////////////////////
// Filename: State.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef STATE_HPP
#define STATE_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include <string>

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////
namespace sf { class RenderWindow; }

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////
class ResourceManager;
class GameSettings;
class StateManager;

////////////////////////////////////////////////////////////////////////////////
// A base state class. All game states should inherit from this.
////////////////////////////////////////////////////////////////////////////////
class State
{
public:

    ////////////////////////////////////////////////////////////////////////////////
    // Create a base state
    ////////////////////////////////////////////////////////////////////////////////
    State(sf::RenderWindow& renderWindow, sfx::ResourceManager& rm, sfx::GameSettings& gs, StateManager& sm, const std::string& name);

    ////////////////////////////////////////////////////////////////////////////////
    // Destroy the state
    ////////////////////////////////////////////////////////////////////////////////
    virtual ~State();

    ////////////////////////////////////////////////////////////////////////////////
    // Execute the state
    ////////////////////////////////////////////////////////////////////////////////
    virtual bool onExecute() = 0;

    ////////////////////////////////////////////////////////////////////////////////
    // Get the name of the state
    ////////////////////////////////////////////////////////////////////////////////
    const std::string& getName() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Process events
    ////////////////////////////////////////////////////////////////////////////////
    virtual void onEvent() = 0;

    ////////////////////////////////////////////////////////////////////////////////
    // Update the state
    ////////////////////////////////////////////////////////////////////////////////
    virtual void onUpdate() = 0;

    ////////////////////////////////////////////////////////////////////////////////
    // Render state content
    ////////////////////////////////////////////////////////////////////////////////
    virtual void onRender() = 0;

    ////////////////////////////////////////////////////////////////////////////////
    // When the state is paused
    ////////////////////////////////////////////////////////////////////////////////
    virtual void onPause() = 0;

    ////////////////////////////////////////////////////////////////////////////////
    // When the state is resumed
    ////////////////////////////////////////////////////////////////////////////////
    virtual void onResume() = 0;

protected: 

    ////////////////////////////////////////////////////////////////////////////////
    // Protected member data
    ////////////////////////////////////////////////////////////////////////////////
    sf::RenderWindow& m_renderWindow;
    ResourceManager&  m_resourceManager;
    GameSettings&     m_gameSettings;
    StateManager&     m_stateManager;
    std::string       m_name;
};

}

#endif
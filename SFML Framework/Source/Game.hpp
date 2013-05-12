////////////////////////////////////////////////////////////////////////////////
// Filename: Game.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_HPP
#define GAME_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "State.hpp"

////////////////////////////////////////////////////////////////////////////////
// Contains the game
////////////////////////////////////////////////////////////////////////////////
class Game : public sfx::State
{
public:

    ////////////////////////////////////////////////////////////////////////////////
    // Create a game state
    ////////////////////////////////////////////////////////////////////////////////
    Game(sf::RenderWindow& renderWindow, sfx::ResourceManager& rm, sfx::GameSettings& gs, sfx::StateManager& sm);

    ////////////////////////////////////////////////////////////////////////////////
    // Execute the state
    ////////////////////////////////////////////////////////////////////////////////
    virtual bool onExecute();

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Process events
    ////////////////////////////////////////////////////////////////////////////////
    virtual void onEvent();

    ////////////////////////////////////////////////////////////////////////////////
    // Update the state
    ////////////////////////////////////////////////////////////////////////////////
    virtual void onUpdate();

    ////////////////////////////////////////////////////////////////////////////////
    // Render state content
    ////////////////////////////////////////////////////////////////////////////////
    virtual void onRender();

    ////////////////////////////////////////////////////////////////////////////////
    // When the state is paused
    ////////////////////////////////////////////////////////////////////////////////
    virtual void onPause();

    ////////////////////////////////////////////////////////////////////////////////
    // When the state is resumed
    ////////////////////////////////////////////////////////////////////////////////
    virtual void onResume();

    ////////////////////////////////////////////////////////////////////////////////
    // Restart the state
    ////////////////////////////////////////////////////////////////////////////////
    virtual void onRestart();
};

#endif
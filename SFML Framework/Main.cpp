////////////////////////////////////////////////////////////////////////////////
// Filename: Main.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include "Source/Sfx.hpp"

////////////////////////////////////////////////////////////////////////////////
// Entry point of application
////////////////////////////////////////////////////////////////////////////////
int main()
{
    // Create a rendering window
    sf::RenderWindow renderWindow(sf::VideoMode(1024, 768), "SFML Framework");

    // Create resource manager and game settings
    sfx::ResourceManager rm;
    sfx::GameSettings gs;
    
    // Create state manager
    sfx::StateManager stateManager;

    // Add states to the game
    stateManager.add("MainMenu", std::make_shared<MainMenu>(renderWindow, rm, gs, stateManager));
    stateManager.add("Game",     std::make_shared<Game>    (renderWindow, rm, gs, stateManager));
    
    // Set starting state
    stateManager.setState("MainMenu");

    // Run the application
    while(stateManager.getState()->onExecute());

    return 0;
}
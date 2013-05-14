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
#include <iostream>
#include <memory>
#include "Source/MainMenu.hpp"
#include "Source/Game.hpp"
#include <SFML/Audio.hpp>

void useRegular();
void useState();

////////////////////////////////////////////////////////////////////////////////
// Entry point of application
////////////////////////////////////////////////////////////////////////////////
int main()
{
    //useRegular();
    useState();

    return 0;
}

void useRegular()
{
    sfx::Application application(1024, 768, "SFML Framework");
   
    while(application.isOpen())
    {
        sf::Event event;
        while(application.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                application.close();

            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape)
                    application.close();
            }
        }

        application.clear();
        application.display();
    }
}

void useState()
{
    sfx::Application application(1024, 768, "SFML Framework");

    // Add states to the game
    application.addState("MainMenu", std::make_shared<MainMenu>(application));
    application.addState("Game",     std::make_shared<Game>    (application));
    
    // Set starting state
    application.setState("MainMenu");

    // Run the application
    while(application.getState()->onExecute());
}
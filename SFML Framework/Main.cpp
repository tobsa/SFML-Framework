////////////////////////////////////////////////////////////////////////////////
// Filename: Main.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Source/Sfx.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <memory>

////////////////////////////////////////////////////////////////////////////////
// Entry point of application
////////////////////////////////////////////////////////////////////////////////
int main()
{
    sfx::Application application(1024, 768, "SFML Framework");

    while (application.isOpen())
    {
        sf::Event event;
        while (application.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                application.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                    application.close();
            }
        }

        application.clear();
        application.display();
    }

    return 0;
}
////////////////////////////////////////////////////////////////////////////////
// Filename: Application.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef APPLICATION_HPP
#define APPLICATION_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include <SFML/Graphics/RenderWindow.hpp>
#include "ResourceManager.hpp"
#include "GameSettings.hpp"
#include "StateManager.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// The main application class
////////////////////////////////////////////////////////////////////////////////
class Application 
{
private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private typedefs
    ////////////////////////////////////////////////////////////////////////////////
    typedef std::shared_ptr<State>          StatePtr;
    typedef std::map<std::string, StatePtr> StateMap;

public:

    ////////////////////////////////////////////////////////////////////////////////
    // Create an application
    ////////////////////////////////////////////////////////////////////////////////
    Application(sf::VideoMode videoMode, const std::string& name, sf::Uint32 style = sf::Style::Default);
    Application(unsigned int width, unsigned int height, const std::string& name, sf::Uint32 style = sf::Style::Default);

    ////////////////////////////////////////////////////////////////////////////////
    // Methods from sf::RenderWindow
    ////////////////////////////////////////////////////////////////////////////////
    sf::Image capture() const;
    sf::Vector2f getSize() const;
    sf::Vector2f getPosition() const;
    sf::Vector2f getMousePosition() const;
    bool isOpen() const;
    bool pollEvent(sf::Event& event);
    void create(sf::VideoMode videoMode, const std::string& name, sf::Uint32 style = sf::Style::Default);
    void create(unsigned int width, unsigned int height, const std::string& name, sf::Uint32 style = sf::Style::Default);
    void close();
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    void setTitle(const std::string& title);
    void setVisible(bool visible);
    void setVerticalSyncEnabled(bool enabled);
    void setMouseCursorVisible(bool visible);
    void setKeyRepeatEnabled(bool enabled);
    void setFramerateLimit(unsigned int limit);
    void setActive(bool active);
    void display();
    void clear(const sf::Color& color = sf::Color(0, 0, 0, 255));
    void draw(const sf::Drawable& drawable, const sf::RenderStates& states = sf::RenderStates::Default);
    void draw(const sf::Vertex *vertices, unsigned int vertexCount, sf::PrimitiveType type, const sf::RenderStates& states = sf::RenderStates::Default);
    void setMousePosition(const sf::Vector2f& position);
    void setMousePosition(float x, float y);

    ////////////////////////////////////////////////////////////////////////////////
    // Methods from sfx::ResourceManager
    ////////////////////////////////////////////////////////////////////////////////
    sf::Texture& getTexture(const std::string& filename);
    sf::Font& getFont(const std::string& filename);
    sf::SoundBuffer& getSoundBuffer(const std::string& filename);

    ////////////////////////////////////////////////////////////////////////////////
    // Methods from sfx::GameSettings
    ////////////////////////////////////////////////////////////////////////////////
    template<class T> T& getValue(const std::string& key);
    template<class T> void setValue(const std::string& key, const T& value);
    std::string getValueType(const std::string& key);
    void removeValue(const std::string& key);

    ////////////////////////////////////////////////////////////////////////////////
    // Methods from sfx::StateManager
    ////////////////////////////////////////////////////////////////////////////////
    void addState(const std::string& key, StatePtr state);
    StatePtr getState() const;
    StatePtr getState(const std::string& key);
    void setState(const std::string& key);

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private member data
    ////////////////////////////////////////////////////////////////////////////////
    sf::RenderWindow m_renderWindow;
    ResourceManager  m_resourceManager;
    GameSettings     m_gameSettings;
    StateManager     m_stateManager;
};

} // namespace sfx

////////////////////////////////////////////////////////////////////////////////
// Inline files
////////////////////////////////////////////////////////////////////////////////
#include "Application.inl"

#endif
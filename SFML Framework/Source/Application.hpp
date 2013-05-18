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
#include "EventManager.hpp"
#include "Audio/AudioManager.hpp"

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
    Application(sf::VideoMode videoMode, const std::string& name, sf::Uint32 style = sf::Style::Default, unsigned int antialiasing = 0);
    Application(unsigned int width, unsigned int height, const std::string& name, sf::Uint32 style = sf::Style::Default, unsigned int antialiasing = 0);

    ////////////////////////////////////////////////////////////////////////////////
    // Methods from sf::RenderWindow
    ////////////////////////////////////////////////////////////////////////////////
    sf::Image capture() const;
    sf::Vector2f getSize() const;
    sf::Vector2f getPosition() const;
    sf::Vector2f getMousePosition() const;
    bool isOpen() const;
    bool pollEvent(sf::Event& event);
    void create(sf::VideoMode videoMode, const std::string& name, sf::Uint32 style = sf::Style::Default, unsigned int antialiasing = 0);
    void create(unsigned int width, unsigned int height, const std::string& name, sf::Uint32 style = sf::Style::Default, unsigned int antialiasing = 0);
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
    void setView(const sf::View& view);
    const sf::View& getView() const;
    const sf::View& getDefaultView() const;
    sf::Vector2f mapPixelToCoord(const sf::Vector2f& position) const;
    sf::Vector2f mapPixelToCoord(const sf::Vector2f& position, const sf::View& view) const;

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

    ////////////////////////////////////////////////////////////////////////////////
    // Methods from sfx::EventManager
    ////////////////////////////////////////////////////////////////////////////////
    void addEvent(const Event& event);
    std::size_t getEventSize() const;
    const Event& getEvent(const std::string& name);
    const Event& getEvent(std::size_t index);
    sfx::Vector<Event>& getEvents();
    void removeEvent(const std::string& name);
    void removeEvent(std::size_t index);
    void removeLastEvent();
    bool findEvent(const std::string& name);

    ////////////////////////////////////////////////////////////////////////////////
    // Methods from sfx::AudioManager
    ////////////////////////////////////////////////////////////////////////////////
    void setSound(const std::string& key, const std::string& filename, std::size_t channels = 1);
    void setMusic(const std::string& key, const std::string& filename);
    void playSound(const std::string& key);
    void pauseSound(const std::string& key);
    void stopSound(const std::string& key);
    void playMusic(const std::string& key);
    void pauseMusic(const std::string& key);
    void stopMusic(const std::string& key);
    bool isSoundPlaying(const std::string& key) const;
    bool isSoundPaused(const std::string& key) const;
    bool isSoundStopped(const std::string& key) const;
    bool isMusicPlaying(const std::string& key) const;
    bool isMusicPaused(const std::string& key) const;
    bool isMusicStopped(const std::string& key) const;
    void setSoundVolume(const std::string& key, float volume);
    float getSoundVolume(const std::string& key) const;
    void setMusicVolume(const std::string& key, float volume);
    float getMusicVolume(const std::string& key) const;
    void removeSound(const std::string& key);
    void removeMusic(const std::string& key);
    void createSoundGroup(const std::string& group);
    void createMusicGroup(const std::string& group);
    void addSoundToGroup(const std::string& group, const std::string& key);
    void addMusicToGroup(const std::string& group, const std::string& key);
    void playSoundGroup(const std::string& group);
    void stopSoundGroup(const std::string& group);
    void playMusicGroup(const std::string& group);
    void pauseMusicGroup(const std::string& group);
    void stopMusicGroup(const std::string& group);
    bool isSoundGroupPlaying(const std::string& group) const;
    bool isSoundGroupStopped(const std::string& group) const;
    bool isMusicGroupPlaying(const std::string& group) const;
    bool isMusicGroupPaused(const std::string& group) const;
    bool isMusicGroupStopped(const std::string& group) const;
    void removeSoundFromGroup(const std::string& group, const std::string& key);
    void removeSoundGroup(const std::string& group);
    void removeMusicFromGroup(const std::string& group, const std::string& key);
    void removeMusicGroup(const std::string& group);
    void setSoundGroupVolume(const std::string& group, float volume);
    void setSoundGroupOrder(const std::string& group, SoundGroup::Order order);
    void setMusicGroupVolume(const std::string& group, float volume);
    void setMusicGroupOrder(const std::string& group, MusicGroup::Order order);
    float getSoundGroupVolume(const std::string& group) const;
    SoundGroup::Order getSoundGroupOrder(const std::string& group) const;
    float getMusicGroupVolume(const std::string& group) const;
    MusicGroup::Order getMusicGroupOrder(const std::string& group) const;
    void onUpdate();

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private member data
    ////////////////////////////////////////////////////////////////////////////////
    sf::RenderWindow m_renderWindow;
    ResourceManager  m_resourceManager;
    GameSettings     m_gameSettings;
    StateManager     m_stateManager;
    EventManager     m_eventManager;
    AudioManager     m_audioManager;
};

} // namespace sfx

////////////////////////////////////////////////////////////////////////////////
// Inline files
////////////////////////////////////////////////////////////////////////////////
#include "Application.inl"

#endif
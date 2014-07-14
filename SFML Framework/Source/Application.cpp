////////////////////////////////////////////////////////////////////////////////
// Filename: Application.cpp
// Author: Tobias Savinainen
// Year: 2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Application.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Utility/Utility.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
Application::Application(sf::VideoMode videoMode, const std::string& name, sf::Uint32 style, unsigned int antialiasing) :
    m_renderWindow (videoMode, name, style, sf::ContextSettings(0U, 0U, antialiasing, 2U, 0U))
{
}

////////////////////////////////////////////////////////////////////////////////
Application::Application(unsigned int width, unsigned int height, const std::string& name, sf::Uint32 style, unsigned int antialiasing) :
    m_renderWindow (sf::VideoMode(width, height), name, style, sf::ContextSettings(0U, 0U, antialiasing, 2U, 0U))
{
}

////////////////////////////////////////////////////////////////////////////////
sf::Image Application::capture() const
{
    return m_renderWindow.capture();
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f Application::getSize() const
{
    return static_cast<sf::Vector2f>(m_renderWindow.getSize());
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f Application::getPosition() const
{
    return static_cast<sf::Vector2f>(m_renderWindow.getPosition());
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f Application::getMousePosition() const
{
    return static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_renderWindow));
}

////////////////////////////////////////////////////////////////////////////////
bool Application::isOpen() const
{
    return m_renderWindow.isOpen();
}

////////////////////////////////////////////////////////////////////////////////
bool Application::pollEvent(sf::Event& event)
{
    return m_renderWindow.pollEvent(event);
}

////////////////////////////////////////////////////////////////////////////////
void Application::create(sf::VideoMode videoMode, const std::string& name, sf::Uint32 style, unsigned int antialiasing)
{
    m_renderWindow.create(videoMode, name, style, sf::ContextSettings(0U, 0U, antialiasing, 2U, 0U));
}

////////////////////////////////////////////////////////////////////////////////
void Application::create(unsigned int width, unsigned int height, const std::string& name, sf::Uint32 style, unsigned int antialiasing)
{
    m_renderWindow.create(sf::VideoMode(width, height), name, style, sf::ContextSettings(0U, 0U, antialiasing, 2U, 0U));
}

////////////////////////////////////////////////////////////////////////////////
void Application::close()
{
    m_renderWindow.close();
}

////////////////////////////////////////////////////////////////////////////////
void Application::setPosition(const sf::Vector2f& position)
{
    m_renderWindow.setPosition(static_cast<sf::Vector2i>(position));
}

////////////////////////////////////////////////////////////////////////////////
void Application::setPosition(float x, float y)
{
    setPosition(sf::Vector2f(x, y));
}

////////////////////////////////////////////////////////////////////////////////
void Application::setTitle(const std::string& title)
{
    m_renderWindow.setTitle(title);
}

////////////////////////////////////////////////////////////////////////////////
void Application::setVisible(bool visible)
{
    m_renderWindow.setVisible(visible);
}

////////////////////////////////////////////////////////////////////////////////
void Application::setVerticalSyncEnabled(bool enabled)
{
    m_renderWindow.setVerticalSyncEnabled(enabled);
}

////////////////////////////////////////////////////////////////////////////////
void Application::setMouseCursorVisible(bool visible)
{
    m_renderWindow.setMouseCursorVisible(visible);
}

////////////////////////////////////////////////////////////////////////////////
void Application::setKeyRepeatEnabled(bool enabled)
{
    m_renderWindow.setKeyRepeatEnabled(enabled);
}

////////////////////////////////////////////////////////////////////////////////
void Application::setFramerateLimit(unsigned int limit)
{
    m_renderWindow.setFramerateLimit(limit);
}

////////////////////////////////////////////////////////////////////////////////
void Application::setActive(bool active)
{
    m_renderWindow.setActive(active);
}


////////////////////////////////////////////////////////////////////////////////
void Application::display()
{
    m_renderWindow.display();
}

////////////////////////////////////////////////////////////////////////////////
void Application::clear(const sf::Color& color)
{
    m_renderWindow.clear();
}

////////////////////////////////////////////////////////////////////////////////
void Application::draw(const sf::Drawable& drawable, const sf::RenderStates& states)
{
    m_renderWindow.draw(drawable, states);
}

////////////////////////////////////////////////////////////////////////////////
void Application::draw(const sf::Vertex *vertices, unsigned int vertexCount, sf::PrimitiveType type, const sf::RenderStates& states)
{
    m_renderWindow.draw(vertices, vertexCount, type, states);
}

////////////////////////////////////////////////////////////////////////////////
void Application::setMousePosition(const sf::Vector2f& position)
{
    sf::Mouse::setPosition(static_cast<sf::Vector2i>(position), m_renderWindow);
}

////////////////////////////////////////////////////////////////////////////////
void Application::setMousePosition(float x, float y)
{
    setMousePosition(sf::Vector2f(x, y));
}

////////////////////////////////////////////////////////////////////////////////
void Application::setView(const sf::View& view)
{
    m_renderWindow.setView(view);
}

////////////////////////////////////////////////////////////////////////////////
const sf::View& Application::getView() const
{
    return m_renderWindow.getView();
}

////////////////////////////////////////////////////////////////////////////////
const sf::View& Application::getDefaultView() const
{
    return m_renderWindow.getDefaultView();
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f Application::mapPixelToCoord(const sf::Vector2f& position) const
{
    return m_renderWindow.mapPixelToCoords(static_cast<sf::Vector2i>(position));
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f Application::mapPixelToCoord(const sf::Vector2f& position, const sf::View& view) const
{
    return m_renderWindow.mapPixelToCoords(static_cast<sf::Vector2i>(position), view);
}

////////////////////////////////////////////////////////////////////////////////
sf::Vector2f Application::getMousePixelToCoord() const
{
    return mapPixelToCoord(getMousePosition());
}

////////////////////////////////////////////////////////////////////////////////
void Application::setDefaultView()
{
    setView(getDefaultView());
}

////////////////////////////////////////////////////////////////////////////////
sf::Texture& Application::getTexture(const std::string& filename)
{
    return m_resourceManager.getTexture(filename);
}

////////////////////////////////////////////////////////////////////////////////
sf::Font& Application::getFont(const std::string& filename)
{
    return m_resourceManager.getFont(filename);
}

////////////////////////////////////////////////////////////////////////////////
sf::SoundBuffer& Application::getSoundBuffer(const std::string& filename)
{
    return m_resourceManager.getSoundBuffer(filename);
}

////////////////////////////////////////////////////////////////////////////////
std::string Application::getValueType(const std::string& key)
{
    return m_gameSettings.getType(key);
}

////////////////////////////////////////////////////////////////////////////////
void Application::removeValue(const std::string& key)
{
    m_gameSettings.remove(key);
}

////////////////////////////////////////////////////////////////////////////////
void Application::addState(const std::string& key, StatePtr state)
{
    m_stateManager.addState(key, state);
}

////////////////////////////////////////////////////////////////////////////////
Application::StatePtr Application::getState() const
{
    return m_stateManager.getState();
}

////////////////////////////////////////////////////////////////////////////////
Application::StatePtr Application::getState(const std::string& key)
{
    return m_stateManager.getState(key);
}

////////////////////////////////////////////////////////////////////////////////
void Application::setState(const std::string& key)
{
    return m_stateManager.setState(key);
}

////////////////////////////////////////////////////////////////////////////////
void Application::setSound(const std::string& key, const std::string& filename, std::size_t channels)
{
    m_audioManager.setSound(key, getSoundBuffer(filename), channels);
}

////////////////////////////////////////////////////////////////////////////////
void Application::setMusic(const std::string& key, const std::string& filename)
{
    m_audioManager.setMusic(key, filename);
}

////////////////////////////////////////////////////////////////////////////////
void Application::playSound(const std::string& key)
{
    m_audioManager.playSound(key);
}

////////////////////////////////////////////////////////////////////////////////
void Application::pauseSound(const std::string& key)
{
    m_audioManager.pauseSound(key);
}

////////////////////////////////////////////////////////////////////////////////
void Application::stopSound(const std::string& key)
{
    m_audioManager.stopSound(key);
}

////////////////////////////////////////////////////////////////////////////////
void Application::playMusic(const std::string& key)
{
    m_audioManager.playMusic(key);
}

////////////////////////////////////////////////////////////////////////////////
void Application::pauseMusic(const std::string& key)
{
    m_audioManager.pauseMusic(key);
}

////////////////////////////////////////////////////////////////////////////////
void Application::stopMusic(const std::string& key)
{
    m_audioManager.stopMusic(key);
}

////////////////////////////////////////////////////////////////////////////////
bool Application::isSoundPlaying(const std::string& key) const
{
    return m_audioManager.isSoundPlaying(key);
}

////////////////////////////////////////////////////////////////////////////////
bool Application::isSoundPaused(const std::string& key) const
{
    return m_audioManager.isSoundPaused(key);
}

////////////////////////////////////////////////////////////////////////////////
bool Application::isSoundStopped(const std::string& key) const
{
    return m_audioManager.isSoundStopped(key);
}

////////////////////////////////////////////////////////////////////////////////
bool Application::isMusicPlaying(const std::string& key) const
{
    return m_audioManager.isMusicPlaying(key);
}

////////////////////////////////////////////////////////////////////////////////
bool Application::isMusicPaused(const std::string& key) const
{
    return m_audioManager.isMusicPaused(key);
}

////////////////////////////////////////////////////////////////////////////////
bool Application::isMusicStopped(const std::string& key) const
{
    return m_audioManager.isMusicStopped(key);
}

////////////////////////////////////////////////////////////////////////////////
void Application::setSoundVolume(const std::string& key, float volume)
{
    m_audioManager.setSoundVolume(key, volume);
}

////////////////////////////////////////////////////////////////////////////////
float Application::getSoundVolume(const std::string& key) const
{
    return m_audioManager.getSoundVolume(key);
}

////////////////////////////////////////////////////////////////////////////////
void Application::setMusicVolume(const std::string& key, float volume)
{
    m_audioManager.setMusicVolume(key, volume);
}

////////////////////////////////////////////////////////////////////////////////
float Application::getMusicVolume(const std::string& key) const
{
    return m_audioManager.getMusicVolume(key);
}

////////////////////////////////////////////////////////////////////////////////
void Application::removeSound(const std::string& key)
{
    m_audioManager.removeSound(key);
}

////////////////////////////////////////////////////////////////////////////////
void Application::removeMusic(const std::string& key)
{
    m_audioManager.removeMusic(key);
}

////////////////////////////////////////////////////////////////////////////////
void Application::createSoundGroup(const std::string& group)
{
    m_audioManager.createSoundGroup(group);
}

////////////////////////////////////////////////////////////////////////////////
void Application::createMusicGroup(const std::string& group)
{
    m_audioManager.createMusicGroup(group);
}

////////////////////////////////////////////////////////////////////////////////
void Application::addSoundToGroup(const std::string& group, const std::string& key)
{
    m_audioManager.addSoundToGroup(group, key);
}

////////////////////////////////////////////////////////////////////////////////
void Application::addMusicToGroup(const std::string& group, const std::string& key)
{
    m_audioManager.addMusicToGroup(group, key);
}

////////////////////////////////////////////////////////////////////////////////
void Application::playSoundGroup(const std::string& group)
{
    m_audioManager.playSoundGroup(group);
}

////////////////////////////////////////////////////////////////////////////////
void Application::stopSoundGroup(const std::string& group)
{
    m_audioManager.stopSoundGroup(group);
}

////////////////////////////////////////////////////////////////////////////////
void Application::playMusicGroup(const std::string& group)
{
    m_audioManager.playMusicGroup(group);
}

////////////////////////////////////////////////////////////////////////////////
void Application::pauseMusicGroup(const std::string& group)
{
    m_audioManager.pauseMusicGroup(group);
}

////////////////////////////////////////////////////////////////////////////////
void Application::stopMusicGroup(const std::string& group)
{
    m_audioManager.stopMusicGroup(group);
}

////////////////////////////////////////////////////////////////////////////////
bool Application::isSoundGroupPlaying(const std::string& group) const
{
    return m_audioManager.isSoundGroupPlaying(group);
}

////////////////////////////////////////////////////////////////////////////////
bool Application::isSoundGroupStopped(const std::string& group) const
{
    return m_audioManager.isSoundGroupStopped(group);
}

////////////////////////////////////////////////////////////////////////////////
bool Application::isMusicGroupPlaying(const std::string& group) const
{
    return m_audioManager.isMusicGroupPlaying(group);
}

////////////////////////////////////////////////////////////////////////////////
bool Application::isMusicGroupPaused(const std::string& group) const
{
    return m_audioManager.isMusicGroupPaused(group);
}

////////////////////////////////////////////////////////////////////////////////
bool Application::isMusicGroupStopped(const std::string& group) const
{
    return m_audioManager.isMusicGroupStopped(group);
}

////////////////////////////////////////////////////////////////////////////////
void Application::removeSoundFromGroup(const std::string& group, const std::string& key)
{
    m_audioManager.removeSoundFromGroup(group, key);
}

////////////////////////////////////////////////////////////////////////////////
void Application::removeSoundGroup(const std::string& group)
{
    m_audioManager.removeSoundGroup(group);
}

////////////////////////////////////////////////////////////////////////////////
void Application::removeMusicFromGroup(const std::string& group, const std::string& key)
{
    m_audioManager.removeMusicFromGroup(group, key);
}

////////////////////////////////////////////////////////////////////////////////
void Application::removeMusicGroup(const std::string& group)
{
    m_audioManager.removeMusicGroup(group);
}

////////////////////////////////////////////////////////////////////////////////
void Application::setSoundGroupVolume(const std::string& group, float volume)
{
    m_audioManager.setSoundGroupVolume(group, volume);
}

////////////////////////////////////////////////////////////////////////////////
void Application::setSoundGroupOrder(const std::string& group, SoundGroup::Order order)
{
    m_audioManager.setSoundGroupOrder(group, order);
}

////////////////////////////////////////////////////////////////////////////////
void Application::setMusicGroupVolume(const std::string& group, float volume)
{
    m_audioManager.setMusicGroupVolume(group, volume);
}

////////////////////////////////////////////////////////////////////////////////
void Application::setMusicGroupOrder(const std::string& group, MusicGroup::Order order)
{
    m_audioManager.setMusicGroupOrder(group, order);
}

////////////////////////////////////////////////////////////////////////////////
float Application::getSoundGroupVolume(const std::string& group) const
{
    return m_audioManager.getSoundGroupVolume(group);
}

////////////////////////////////////////////////////////////////////////////////
SoundGroup::Order Application::getSoundGroupOrder(const std::string& group) const
{
    return m_audioManager.getSoundGroupOrder(group);
}

////////////////////////////////////////////////////////////////////////////////
float Application::getMusicGroupVolume(const std::string& group) const
{
    return m_audioManager.getMusicGroupVolume(group);
}

////////////////////////////////////////////////////////////////////////////////
MusicGroup::Order Application::getMusicGroupOrder(const std::string& group) const
{
    return m_audioManager.getMusicGroupOrder(group);
}

////////////////////////////////////////////////////////////////////////////////
void Application::onUpdate()
{
    m_audioManager.onUpdate();
}

} // namespace sfx

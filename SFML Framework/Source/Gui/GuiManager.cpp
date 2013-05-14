////////////////////////////////////////////////////////////////////////////////
// Filename: GuiManager.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "GuiManager.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
GuiManager::GuiManager(Application& application) :
    m_application (application)
{
}
    
////////////////////////////////////////////////////////////////////////////////
void GuiManager::remove(const std::string& key)
{
    auto result = m_objects.find(key);
    if(result != m_objects.end())
    {
        auto it = std::find(m_objectsList.begin(), m_objectsList.end(), result->second);
        m_objectsList.erase(it);
        m_objects.erase(key);
    }    
}

////////////////////////////////////////////////////////////////////////////////
void GuiManager::onEvent(const sf::Event& event)
{
    for(const auto& object : m_objectsList)
        object->onEvent(event);
}

////////////////////////////////////////////////////////////////////////////////
void GuiManager::onUpdate()
{
    for(const auto& object : m_objectsList)
        object->onUpdate();
}

////////////////////////////////////////////////////////////////////////////////
void GuiManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(const auto& object : m_objectsList)
        target.draw(*object);
}

////////////////////////////////////////////////////////////////////////////////
void GuiManager::enable(const std::string& group)
{
    auto result = m_objectGroup.find(group);
    if(result == m_objectGroup.end())
        sfx::Log::writeT("Error (GuiManager::enable()): " + group + " doesn't exist");

    for(auto& object : result->second)
        object.second->enable();
}

////////////////////////////////////////////////////////////////////////////////
void GuiManager::disable(const std::string& group)
{
    auto result = m_objectGroup.find(group);
    if(result == m_objectGroup.end())
        sfx::Log::writeT("Error (GuiManager::disable()): " + group + " doesn't exist");

    for(auto& object : result->second)
        object.second->disable();
}

} // namespace sfx


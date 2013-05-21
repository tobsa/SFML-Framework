////////////////////////////////////////////////////////////////////////////////
// Filename: BaseEntityManager.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "BaseEntityManager.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
BaseEntityManager::BaseEntityManager(Application& application) :
    m_application (application)
{
}

////////////////////////////////////////////////////////////////////////////////
BaseEntityManager::~BaseEntityManager()
{
}

////////////////////////////////////////////////////////////////////////////////
void BaseEntityManager::onUpdate(float dt)
{
    for(const auto& entity : m_entities)
        entity->onUpdate(dt);
}

////////////////////////////////////////////////////////////////////////////////
void BaseEntityManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(const auto& entity : m_entities)
        target.draw(*entity);    
}

} // namespace sfx
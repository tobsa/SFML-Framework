////////////////////////////////////////////////////////////////////////////////
// Filename: Component.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Component.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
Component::Component(Application& application, Entity& entity) :
    m_application (application),
    m_entity      (entity)
{
}

////////////////////////////////////////////////////////////////////////////////
Component::~Component()
{
}

////////////////////////////////////////////////////////////////////////////////
Entity& Component::getEntity() const
{
    return m_entity;
}

} // namespace sfx
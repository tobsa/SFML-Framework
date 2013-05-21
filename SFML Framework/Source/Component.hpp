////////////////////////////////////////////////////////////////////////////////
// Filename: Component.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef COMPONENT_HPP
#define COMPONENT_HPP

////////////////////////////////////////////////////////////////////////////////
// Forward declarations
////////////////////////////////////////////////////////////////////////////////
namespace sfx { class Application; }
namespace sfx { class Entity;      }

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// A base component class
////////////////////////////////////////////////////////////////////////////////
class Component
{
public:

    ////////////////////////////////////////////////////////////////////////////////
    // Constructor
    ////////////////////////////////////////////////////////////////////////////////
    Component(Application& application, Entity& entity);

    ////////////////////////////////////////////////////////////////////////////////
    // Destructor
    ////////////////////////////////////////////////////////////////////////////////
    virtual ~Component();

    ////////////////////////////////////////////////////////////////////////////////
    // Update the component
    ////////////////////////////////////////////////////////////////////////////////
    virtual void onUpdate(float dt);

    ////////////////////////////////////////////////////////////////////////////////
    // Get the entity
    ////////////////////////////////////////////////////////////////////////////////
    Entity& getEntity() const;

protected:

    ////////////////////////////////////////////////////////////////////////////////
    // Protected member data
    ////////////////////////////////////////////////////////////////////////////////
    Application& m_application;
    Entity&      m_entity;
};

} // namespace sfx

#endif
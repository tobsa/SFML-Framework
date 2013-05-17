////////////////////////////////////////////////////////////////////////////////
// Filename: EventManager.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Event.hpp"
#include "Containers/Vector.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// An event manager. Can add, remove and accessing events
////////////////////////////////////////////////////////////////////////////////
class EventManager 
{
private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private typedefs
    ////////////////////////////////////////////////////////////////////////////////
    typedef Vector<Event> Events;

public:

    ////////////////////////////////////////////////////////////////////////////////
    // Add an event to the manager
    ////////////////////////////////////////////////////////////////////////////////
    void addEvent(const Event& event);
    
    ////////////////////////////////////////////////////////////////////////////////
    // Get the amount of events in the manager
    ////////////////////////////////////////////////////////////////////////////////
    std::size_t getSize() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Get an event. If the event doesn't exist an error is thrown
    ////////////////////////////////////////////////////////////////////////////////
    const Event& getEvent(const std::string& name);
    const Event& getEvent(std::size_t index);

    ////////////////////////////////////////////////////////////////////////////////
    // Get the whole events vector
    ////////////////////////////////////////////////////////////////////////////////
    Events& getEvents();

    ////////////////////////////////////////////////////////////////////////////////
    // Remove an event from the manager
    ////////////////////////////////////////////////////////////////////////////////
    void remove(const std::string& name);
    void remove(std::size_t index);
    void removeLast();

    ////////////////////////////////////////////////////////////////////////////////
    // Check if an event exist
    ////////////////////////////////////////////////////////////////////////////////
    bool findEvent(const std::string& name);

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private member data
    ////////////////////////////////////////////////////////////////////////////////
    Events m_events;
};

} // namespace sfx

#endif
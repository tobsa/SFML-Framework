////////////////////////////////////////////////////////////////////////////////
// Filename: EventManager.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "EventManager.hpp"
#include "Log.hpp"
#include "Utility.hpp"
#include <algorithm>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
void EventManager::addEvent(const Event& event)
{
    m_events.push_back(event);
}
    
////////////////////////////////////////////////////////////////////////////////
std::size_t EventManager::getSize() const
{
    return m_events.size();
}

////////////////////////////////////////////////////////////////////////////////
const Event& EventManager::getEvent(const std::string& name)
{
    auto result = std::find(m_events.begin(), m_events.end(), Event(name));
    
    if(result == m_events.end())
        sfx::Log::writeT("Error (EventManager::getEvent()): " + name + " doesn't exist");

    return *result;
}

////////////////////////////////////////////////////////////////////////////////
const Event& EventManager::getEvent(std::size_t index)
{
    return m_events[sfx::clamp(index, static_cast<std::size_t>(0), m_events.size() - 1)];
}

////////////////////////////////////////////////////////////////////////////////
void EventManager::remove(const std::string& name)
{
    for(auto it = m_events.begin(); it != m_events.end();)
    {
        if(it->getName() == name)
            it = m_events.erase(it);
        else 
            ++it;
    }
}

////////////////////////////////////////////////////////////////////////////////
void EventManager::remove(std::size_t index)
{
    auto it = m_events.begin();
    std::advance(it, index);

    m_events.erase(it);
}

////////////////////////////////////////////////////////////////////////////////
void EventManager::removeLast()
{
    m_events.pop_back();
}

} // namespace sfx
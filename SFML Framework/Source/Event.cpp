////////////////////////////////////////////////////////////////////////////////
// Filename: Event.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Event.hpp"
#include "Log.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
Event::Event(const std::string& name, const std::string& key, const std::string& message) :
    m_name (name)
{
    if(!key.empty() && !message.empty())
        addMessage(key, message);
}

////////////////////////////////////////////////////////////////////////////////
const std::string& Event::getName() const
{
    return m_name;
}

////////////////////////////////////////////////////////////////////////////////
void Event::setName(const std::string& name)
{
    m_name = name;
}

////////////////////////////////////////////////////////////////////////////////
void Event::addMessage(const std::string& key, const std::string& message)
{
    m_messages[key] = message;
}
    
////////////////////////////////////////////////////////////////////////////////
const std::string& Event::getMessage(const std::string& key) const
{
    auto result = m_messages.find(key);
    if(result == m_messages.end())
        sfx::Log::writeT("Error (Event::getMessage(): " + key + " doesn't exist");

    return result->second;
}

////////////////////////////////////////////////////////////////////////////////
void Event::removeMessage(const std::string& key)
{
    m_messages.erase(key);
}

////////////////////////////////////////////////////////////////////////////////
bool Event::operator == (const Event& event)
{
    return m_name == event.getName();
}

} // namespace sfx

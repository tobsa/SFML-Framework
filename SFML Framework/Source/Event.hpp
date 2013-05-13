////////////////////////////////////////////////////////////////////////////////
// Filename: Event.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef EVENT_HPP
#define EVENT_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <map>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// A simple event that can associate multiple messages with a single key
////////////////////////////////////////////////////////////////////////////////
class Event 
{
public:

    ////////////////////////////////////////////////////////////////////////////////
    // Create the event
    ////////////////////////////////////////////////////////////////////////////////
    Event(const std::string& name);

    ////////////////////////////////////////////////////////////////////////////////
    // Get the name of the event
    ////////////////////////////////////////////////////////////////////////////////
    const std::string& getName() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Set new name for the event
    ////////////////////////////////////////////////////////////////////////////////
    void setName(const std::string& name);

    ////////////////////////////////////////////////////////////////////////////////
    // Add a message to the event
    ////////////////////////////////////////////////////////////////////////////////
    void addMessage(const std::string& key, const std::string& message);
    
    ////////////////////////////////////////////////////////////////////////////////
    // Get a message specified by a key. If the key doesn't exist an error is 
    // thrown
    ////////////////////////////////////////////////////////////////////////////////
    const std::string& getMessage(const std::string& key) const;

    ////////////////////////////////////////////////////////////////////////////////
    // Remove a message from the event
    ////////////////////////////////////////////////////////////////////////////////
    void removeMessage(const std::string& key);

    bool operator == (const sfx::Event& rhs) const
    {
        return m_name == rhs.getName();
    }

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private typedefs
    ////////////////////////////////////////////////////////////////////////////////
    typedef std::map<std::string, std::string> Messages;

    ////////////////////////////////////////////////////////////////////////////////
    // Private member data
    ////////////////////////////////////////////////////////////////////////////////
    Messages    m_messages;
    std::string m_name;
};



} // namespace sfx



#endif
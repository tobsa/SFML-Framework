////////////////////////////////////////////////////////////////////////////////
// Filename: GuiManager.inl
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "GuiManager.hpp"
#include "../Log.hpp"

namespace sfx
{

 ////////////////////////////////////////////////////////////////////////////////
template<typename T> T& GuiManager::create(const std::string& key, const std::string& group)
{
    // If the key already exist then erase the previous value
    if(m_objects.find(key) != m_objects.end())
        remove(key);     

    // Create the object
    std::shared_ptr<T> object = std::make_shared<T>(m_application);

    // Add it to the manager
    m_objects[key] = object;
    m_objectsList.push_back(object);

    m_objectGroup[group][key] = object;

    return *object.get();
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> T& GuiManager::get(const std::string& key)
{
    // Check if the object exist
    auto it = m_objects.find(key);
    if(it == m_objects.end())
        sfx::Log::writeT("Error (GuiManager::get()): " + key + " doesn't exist");

    return *static_cast<T*>(it->second.get());
}

} // namespace sfx
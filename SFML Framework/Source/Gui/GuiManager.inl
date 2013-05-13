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
template<typename T> T& GuiManager::create(const std::string& key)
{
    auto it = m_objects.find(key);

    // If the key already exist then erase the previous value
    if(it != m_objects.end())
        remove(key);     

    // Create the object
    std::shared_ptr<T> object = std::make_shared<T>(m_application);

    // Add it to the manager
    m_objects[key] = object;

    // Add it to the list
    m_objectsList.push_back(object);

    return *object.get();
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> T& GuiManager::get(const std::string& key)
{
    // Check if the object exist
    auto it = m_objects.find(key);
    if(it == m_objects.end())
    {
        std::string error = "Error (GuiManager::get()): " + key + " doesn't exist";
        sfx::Log::write(error);
        throw error;
    }

    return *static_cast<T*>(it->second.get());
}

} // namespace sfx
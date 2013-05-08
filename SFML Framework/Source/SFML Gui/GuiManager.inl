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
template<typename T> T& GuiManager::create(const std::string& key, GuiObjectPtr object)
{
    auto it = m_objects.find(key);

    // If the key already exist 
    if(it != m_objects.end())
        m_objects.erase(key);

    m_objects[key] = object;

    return static_cast<T&>(*object.get());
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
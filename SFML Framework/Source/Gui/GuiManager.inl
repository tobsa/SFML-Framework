////////////////////////////////////////////////////////////////////////////////
// Filename: GuiManager.inl
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "GuiManager.hpp"

namespace sfx
{

 ////////////////////////////////////////////////////////////////////////////////
template<typename T> T& GuiManager::create(const std::string& key)
{
    // If the key already exist then erase the previous value
    if(m_objects.find(key) != m_objects.end())
        remove(key);     

    // Create the object
    std::shared_ptr<T> object = std::make_shared<T>(m_application);

    // Add it to the manager
    m_objects[key] = object;
    m_objectsList.push_back(object);

    return *object.get();
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> T& GuiManager::get(const std::string& key)
{
    const auto& result = m_objects.findWithErrorCheck(key, "Error (GuiManager::get()): " + key + " doesn't exist");

    return *static_cast<T*>(result->second.get());
}

} // namespace sfx
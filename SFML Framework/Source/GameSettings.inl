////////////////////////////////////////////////////////////////////////////////
// Filename: GameSettings.inl
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "GameSettings.hpp"
#include "Property.hpp"
#include "Log.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
template<class T> T& GameSettings::get(const std::string& key)
{
    auto it = m_properties.find(key);
    if(it == m_properties.end())
    {
        std::string error = "Error (GameSettings::get()): " + key + " doesn't exist";
        sfx::Log::write(error);
        throw error;
    }

    return const_cast<T&>(static_cast<Property<T>*>(it->second.get())->getValue());
}

////////////////////////////////////////////////////////////////////////////////
template<class T> void GameSettings::set(const std::string& key, const T& value)
{
    auto it = m_properties.find(key);

    // If the key already exist then erase the previous value
    if(it != m_properties.end())
        m_properties.erase(key);
   
    m_properties[key] = std::make_shared<Property<T>>(value);
    m_properties[key]->setType(typeid(T).name());
}

} // namespace sfx

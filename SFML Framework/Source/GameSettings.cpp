////////////////////////////////////////////////////////////////////////////////
// Filename: GameSettings.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "GameSettings.hpp"
#include "Log.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
std::string GameSettings::getType(const std::string& key)
{
    auto it = m_properties.find(key);
    if(it == m_properties.end())
    {
        std::string error = "Error (GameSettings::getType()): " + key + " doesn't exist";
        sfx::Log::write(error);
        throw error;
    }

    return it->second->getType();
}

////////////////////////////////////////////////////////////////////////////////
void GameSettings::remove(const std::string& key)
{
    if(m_properties.find(key) == m_properties.end())
    {
        std::string error = "Error (GameSettings::remove()): " + key + " doesn't exist";
        sfx::Log::write(error);
        throw error;
    }

    m_properties.erase(key);
}

} // namespace sfx
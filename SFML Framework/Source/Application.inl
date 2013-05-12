////////////////////////////////////////////////////////////////////////////////
// Filename: Application.inl
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Application.hpp"

namespace sfx
{

template<class T> T& Application::getValue(const std::string& key)
{
    return m_gameSettings.get<T>(key);
}

template<class T> void Application::setValue(const std::string& key, const T& value)
{
    m_gameSettings.set(key, value);
}

} // namespace sfx
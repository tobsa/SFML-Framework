////////////////////////////////////////////////////////////////////////////////
// Filename: Map.inl
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Map.hpp"
#include "../Utility/Log.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
template<typename Type, typename Value> void Map<Type, Value>::insert(const Type& type, const Value& value)
{
    m_map[type] = value;
}

////////////////////////////////////////////////////////////////////////////////
template<typename Type, typename Value> Value& Map<Type, Value>::get(const Type& key)
{
    return m_map[key];    
}

////////////////////////////////////////////////////////////////////////////////
template<typename Type, typename Value> const Value& Map<Type, Value>::get(const Type& key) const
{
    return m_map[key];   
}

////////////////////////////////////////////////////////////////////////////////
template<typename Type, typename Value>  Value& Map<Type, Value>::operator [] (const Type& key)
{
    return m_map[key];     
}

////////////////////////////////////////////////////////////////////////////////
template<typename Type, typename Value> const Value& Map<Type, Value>::operator [] (const Type& key) const
{
    return m_map[key];     
}

////////////////////////////////////////////////////////////////////////////////
template<typename Type, typename Value> std::size_t Map<Type, Value>::getSize() const
{
	return m_map.size();
}


////////////////////////////////////////////////////////////////////////////////
template<typename Type, typename Value> typename Map<Type, Value>::iterator Map<Type, Value>::begin()
{
	return m_map.begin();
}

////////////////////////////////////////////////////////////////////////////////
template<typename Type, typename Value> typename Map<Type, Value>::const_iterator Map<Type, Value>::begin() const
{
	return m_map.begin();
}

////////////////////////////////////////////////////////////////////////////////
template<typename Type, typename Value> typename Map<Type, Value>::iterator Map<Type, Value>::end()
{
	return m_map.end();
}

////////////////////////////////////////////////////////////////////////////////
template<typename Type, typename Value> typename Map<Type, Value>::const_iterator Map<Type, Value>::end() const
{
	return m_map.end();
}

////////////////////////////////////////////////////////////////////////////////
template<typename Type, typename Value> bool Map<Type, Value>::isEmpty() const
{
	return m_map.empty();
}

////////////////////////////////////////////////////////////////////////////////
template<typename Type, typename Value> bool Map<Type, Value>::hasValue() const
{
	return !m_map.empty();
}

////////////////////////////////////////////////////////////////////////////////
template<typename Type, typename Value> void Map<Type, Value>::clear()
{
	m_map.clear();
}

////////////////////////////////////////////////////////////////////////////////
template<typename Type, typename Value> void Map<Type, Value>::remove(const Type& type)
{
	m_map.erase(type);
}

////////////////////////////////////////////////////////////////////////////////
template<typename Type, typename Value> typename Map<Type, Value>::iterator Map<Type, Value>::find(const Type& type)
{
	return m_map.find(type);
}

////////////////////////////////////////////////////////////////////////////////
template<typename Type, typename Value> typename Map<Type, Value>::const_iterator Map<Type, Value>::find(const Type& type) const
{
	return m_map.find(type);
}

////////////////////////////////////////////////////////////////////////////////
template<typename Type, typename Value> typename Map<Type, Value>::iterator Map<Type, Value>::findWithErrorCheck(const Type& type, const std::string& errorMessage)
{
    const auto& result = m_map.find(type);
    if(result == m_map.end())
        sfx::Log::writeT(errorMessage);

    return result;
}

////////////////////////////////////////////////////////////////////////////////
template<typename Type, typename Value> typename Map<Type, Value>::const_iterator Map<Type, Value>::findWithErrorCheck(const Type& type, const std::string& errorMessage) const
{
    const auto& result = m_map.find(type);
    if(result == m_map.end())
        sfx::Log::writeT(errorMessage);

    return result;
}

} // namespace sfx
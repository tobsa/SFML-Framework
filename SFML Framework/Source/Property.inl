////////////////////////////////////////////////////////////////////////////////
// Filename: Property.inl
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Property.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
template<class T> Property<T>::Property(const T& value) :
    m_value (value)
{
}

////////////////////////////////////////////////////////////////////////////////
template<class T> const T& Property<T>::getValue() const
{
    return m_value;
}

////////////////////////////////////////////////////////////////////////////////
template<class T> void Property<T>::setValue(const T& value)
{
    m_value = value;
}

} // namespace sfx
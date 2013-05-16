////////////////////////////////////////////////////////////////////////////////
// Filename: Vector.inl
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "Vector.hpp"
#include "../Utility/Log.hpp"
#include "../Utility/Utility.hpp"
#include <algorithm>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
template<typename T> Vector<T>::Vector()
{
}

template<typename T> Vector<T>::Vector(std::size_t size, const T& element)
{
    for(std::size_t i = 0; i < size; ++i)
        m_vector.push_back(element);
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> void Vector<T>::addBack(const T& element)
{
    m_vector.push_back(element);
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> T& Vector<T>::get(std::size_t index)
{
    return m_vector[index];
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> const T& Vector<T>::get(std::size_t index) const
{
    return m_vector[index];
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> T& Vector<T>::operator [] (std::size_t index)
{
    return m_vector[index];
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> const T& Vector<T>::operator [] (std::size_t index) const
{
    return m_vector[index];
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> std::size_t Vector<T>::getSize() const
{
    return m_vector.size();
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> const T& Vector<T>::front() const
{
    return m_vector.front();
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> const T& Vector<T>::back() const
{
    return m_vector.back();
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> typename Vector<T>::iterator Vector<T>::begin()
{
    return m_vector.begin();
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> typename Vector<T>::const_iterator Vector<T>::begin() const
{
    return m_vector.begin();
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> typename Vector<T>::iterator Vector<T>::end()
{
    return m_vector.end();
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> typename Vector<T>::const_iterator Vector<T>::end() const
{
    return m_vector.end();
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> bool Vector<T>::isEmpty() const
{
    return m_vector.empty();
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> bool Vector<T>::hasValue() const
{
    return !m_vector.empty();
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> void Vector<T>::clear()
{
    return m_vector.clear();
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> size_t Vector<T>::remove(std::size_t index)
{
    if(index < 0 || index >= getSize())
        sfx::Log::writeT("Error (Vector::remove()): Index " + sfx::convert(index) + " is out of bounds");

    auto it = begin();
    std::advance(it, index);

    m_vector.erase(it);

    return index - 1;
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> void Vector<T>::removeValue(const T& element)
{
    m_vector.erase(std::remove(begin(), end(), element), end());
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> void Vector<T>::removeBack()
{
    m_vector.pop_back();
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> void Vector<T>::insert(std::size_t index, const T& element)
{
    if(index < 0 || index >= getSize())
        sfx::Log::writeT("Error (Vector::insert()): Index " + sfx::convert(index) + " is out of bounds");

    auto it = begin();
    std::advance(it, index);

    m_vector.insert(it, element);
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> void Vector<T>::replace(const T& value, const T& element)
{
    for(std::size_t i = 0; i < getSize(); ++i)
    {
        if(m_vector[i] == value)
            m_vector[i] = element;
    }
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> std::size_t Vector<T>::find(const T& element) const
{
    for(std::size_t i = 0; i < getSize(); ++i)
    {
        if(m_vector[i] == element)
            return i;
    }

    return -1;
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> void Vector<T>::resize(std::size_t size)
{
    m_vector.resize(size);
}

} // namespace sfx
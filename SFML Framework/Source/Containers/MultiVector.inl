////////////////////////////////////////////////////////////////////////////////
// Filename: MultiVector.inl
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "MultiVector.hpp"
#include "../Utility/Log.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
template<typename T> MultiVector<T>::MultiVector(std::size_t pageSize) :
    m_pageSize            (pageSize),
    m_internalCurrentPage (0),
    m_externalCurrentPage (0)
{
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> void MultiVector<T>::addBack(const T& element)
{
    m_elements.addBack(element);

    if(m_multiVector.isEmpty())
        m_multiVector.addBack(m_elements);
    else 
    {
        // Check if a new page needs to be added
        if(m_multiVector[m_internalCurrentPage].getSize() >= m_pageSize)
        {
            m_internalCurrentPage++;
            m_multiVector.addBack(Vector<T>(1, element));
        }
        else
        {
            m_multiVector[m_internalCurrentPage].addBack(element);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> Vector<T>& MultiVector<T>::getCurrentPage()
{
    if(m_multiVector.isEmpty())
        Log::writeT("Error (MultiVector<T>::getCurrentPage()) : m_multiVector is empty");

    return m_multiVector[m_externalCurrentPage];
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> const Vector<T>& MultiVector<T>::getCurrentPage() const
{
    if(m_multiVector.isEmpty())
        Log::writeT("Error (MultiVector<T>::getCurrentPage() const) : m_multiVector is empty");

    return m_multiVector[m_externalCurrentPage];    
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> Vector<T>& MultiVector<T>::getPage(std::size_t index)
{
    if(index < 0 || index >= m_multiVector.getSize())
        Log::writeT("Error (MultiVector<T>::getPage()) Index: " + convert(index) + " is out of bounds");

    return m_multiVector[index];
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> const Vector<T>& MultiVector<T>::getPage(std::size_t index) const
{
    if(index < 0 || index >= m_multiVector.getSize())
        Log::writeT("Error (MultiVector<T>::getPage() const) Index: " + convert(index) + " is out of bounds");

    return m_multiVector[index];    
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> void MultiVector<T>::setPage(std::size_t page)
{
    m_externalCurrentPage = clamp(page, 0U, m_multiVector.getSize() - 1);
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> void MultiVector<T>::setPageSize(std::size_t pageSize)
{
    m_multiVector.clear();

    m_pageSize            = pageSize;
    m_internalCurrentPage = 0;
    m_externalCurrentPage = 0;

    for(const auto& element : m_elements)
    {
        if(m_multiVector.isEmpty())
            m_multiVector.addBack(Vector<T>(1, element));
        else 
        {
            // Check if a new page needs to be added
            if(m_multiVector[m_internalCurrentPage].getSize() >= m_pageSize)
            {
                m_internalCurrentPage++;
                m_multiVector.addBack(Vector<T>(1, element));
            }
            else
            {
                m_multiVector[m_internalCurrentPage].addBack(element);
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> void MultiVector<T>::remove(const T& element)
{
    // Remove all element values from the multivector
    for(auto& vector : m_multiVector)
    {
        for(std::size_t i = 0; i < vector.getSize(); ++i)
        {
            if(vector[i] == element)
                i = vector.remove(i);
        }
    }

    m_elements.removeValue(element);

    // And build the multivector from the beginning
    setPageSize(m_pageSize);
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> std::size_t MultiVector<T>::getCurrentPageIndex() const
{
    return m_externalCurrentPage;
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> std::size_t MultiVector<T>::getPageSize() const
{
    return m_pageSize;
}

////////////////////////////////////////////////////////////////////////////////
template<typename T> std::size_t MultiVector<T>::getNbPages() const
{
    return m_multiVector.getSize();
}

} // namespace sfx
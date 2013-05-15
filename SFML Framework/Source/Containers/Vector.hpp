////////////////////////////////////////////////////////////////////////////////
// Filename: Vector.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef VECTOR_HPP
#define VECTOR_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include <vector>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// A wrapper around std::vector
////////////////////////////////////////////////////////////////////////////////
template<typename T> class Vector 
{
public:

    ////////////////////////////////////////////////////////////////////////////////
    // Add an element to the back of the vector
    ////////////////////////////////////////////////////////////////////////////////
    void addBack(const T& element);

    ////////////////////////////////////////////////////////////////////////////////
    // Get an element specified by an index
    ////////////////////////////////////////////////////////////////////////////////
    T& get(std::size_t index);
    T& get(std::size_t index) const;
    T& operator [] (std::size_t index);
    T& operator [] (std::size_t index) const;

    ////////////////////////////////////////////////////////////////////////////////
    // Get the size of the vector
    ////////////////////////////////////////////////////////////////////////////////
    std::size_t getSize() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Get the front and back element element of the vector
    ////////////////////////////////////////////////////////////////////////////////
    const T& front() const;
    const T& back() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Get iterator from the underlying vector
    ////////////////////////////////////////////////////////////////////////////////
    typename std::vector<T>::iterator begin();
    typename std::vector<T>::iterator begin() const;
    typename std::vector<T>::iterator end();
    typename std::vector<T>::iterator end() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Check if there's elements in the vector
    ////////////////////////////////////////////////////////////////////////////////
    bool isEmpty() const;
    bool hasValue() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Clear all elements
    ////////////////////////////////////////////////////////////////////////////////
    void clear();

    ////////////////////////////////////////////////////////////////////////////////
    /// Remove values from the vector
    ////////////////////////////////////////////////////////////////////////////////
    std::size_t remove(std::size_t index);
    void removeValue(const T& element);
    void removeBack();
    
    ////////////////////////////////////////////////////////////////////////////////
    // Insert and replace values
    ////////////////////////////////////////////////////////////////////////////////
    void insert(std::size_t index, const T& element);
    void replace(const T& value, const T& element);

    ////////////////////////////////////////////////////////////////////////////////
    // Find an element. If the element exist it's index position is returned.
    // If the element doesn't exist -1 is returned
    ////////////////////////////////////////////////////////////////////////////////
    std::size_t find(const T& element) const;

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private typedefs
    ////////////////////////////////////////////////////////////////////////////////
    typedef std::vector<T> VectorList;

    ////////////////////////////////////////////////////////////////////////////////
    // Private member data
    ////////////////////////////////////////////////////////////////////////////////
    VectorList m_vector;
};

} // namespace sfx

////////////////////////////////////////////////////////////////////////////////
// Inline files
////////////////////////////////////////////////////////////////////////////////
#include "Vector.inl"

#endif
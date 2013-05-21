////////////////////////////////////////////////////////////////////////////////
// Filename: Map.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef MAP_HPP
#define MAP_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include <map>
#include <string>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// A wrapper around std::map
////////////////////////////////////////////////////////////////////////////////
template<typename Type, typename Value> class Map
{
public:

    ////////////////////////////////////////////////////////////////////////////////
    // Public typedefs
    ////////////////////////////////////////////////////////////////////////////////
    typedef typename std::map<Type, Value>::iterator iterator;
    typedef typename std::map<Type, Value>::const_iterator const_iterator;

public:

    ////////////////////////////////////////////////////////////////////////////////
    // Insert a value into the map
    ////////////////////////////////////////////////////////////////////////////////
    void insert(const Type& type, const Value& value);

    ////////////////////////////////////////////////////////////////////////////////
    // Get an element specified by a key
    ////////////////////////////////////////////////////////////////////////////////
    Value& get(const Type& key);
    const Value& get(const Type& key) const;
    Value& operator[] (const Type& key);
    const Value& operator[] (const Type& key) const;

    ////////////////////////////////////////////////////////////////////////////////
    // Get the size of the map
    ////////////////////////////////////////////////////////////////////////////////
    std::size_t getSize() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Get iterator from the underlying map
    ////////////////////////////////////////////////////////////////////////////////
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Check if there's some value in the map
    ////////////////////////////////////////////////////////////////////////////////
    bool isEmpty() const;
    bool hasValue() const;

    ////////////////////////////////////////////////////////////////////////////////
    // Clear the map
    ////////////////////////////////////////////////////////////////////////////////
    void clear();

    ////////////////////////////////////////////////////////////////////////////////
    // Remove a value 
    ////////////////////////////////////////////////////////////////////////////////
    void remove(const Type& type);

    ////////////////////////////////////////////////////////////////////////////////
    // Find a value
    ////////////////////////////////////////////////////////////////////////////////
    iterator find(const Type& type);
    const_iterator find(const Type& type) const;
    iterator findWithErrorCheck(const Type& type, const std::string& errorMessage);
    const_iterator findWithErrorCheck(const Type& type, const std::string& errorMessage) const;

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private typedefs
    ////////////////////////////////////////////////////////////////////////////////
    typedef std::map<Type, Value> MapList;

    ////////////////////////////////////////////////////////////////////////////////
    // Private member data
    ////////////////////////////////////////////////////////////////////////////////
    MapList m_map;
};

} // namespace sfx

////////////////////////////////////////////////////////////////////////////////
// Inline files
////////////////////////////////////////////////////////////////////////////////
#include "Map.inl"

#endif
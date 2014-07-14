////////////////////////////////////////////////////////////////////////////////
// Filename: GameSettings.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef SFX_GAME_SETTINGS_HPP
#define SFX_GAME_SETTINGS_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "BaseProperty.hpp"
#include "Containers/Map.hpp"
#include <memory>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// A game settings class that can store any type of data
////////////////////////////////////////////////////////////////////////////////
class GameSettings
{
protected:

    ////////////////////////////////////////////////////////////////////////////////
    // Private typedefs
    ////////////////////////////////////////////////////////////////////////////////
    typedef std::shared_ptr<BaseProperty> PropertyPtr;
    typedef Map<std::string, PropertyPtr> PropertyMap;

public:

    ////////////////////////////////////////////////////////////////////////////////
    // Get a value associated with the specified key. If the key doesn't exist
    // an error is thrown.
    ////////////////////////////////////////////////////////////////////////////////
    template<class T> T& get(const std::string& key);

    ////////////////////////////////////////////////////////////////////////////////
    // Set a new value associated with a key. If the key already exist then the
    // previous value will be overwritten.
    ////////////////////////////////////////////////////////////////////////////////
    template<class T> void set(const std::string& key, const T& value);

    ////////////////////////////////////////////////////////////////////////////////
    // Get the type of the value associated with a key
    ////////////////////////////////////////////////////////////////////////////////
    std::string getType(const std::string& key);

    ////////////////////////////////////////////////////////////////////////////////
    // Remove a value from the game settings. If the key doesn't exist an error
    // is thrown.
    ////////////////////////////////////////////////////////////////////////////////
    void remove(const std::string& key);

protected:

    ////////////////////////////////////////////////////////////////////////////////
    // Private member data
    ////////////////////////////////////////////////////////////////////////////////
    PropertyMap m_properties;
};

} // namespace sfx

////////////////////////////////////////////////////////////////////////////////
// Inline files
////////////////////////////////////////////////////////////////////////////////
#include "GameSettings.inl"

#endif

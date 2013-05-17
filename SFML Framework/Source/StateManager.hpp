////////////////////////////////////////////////////////////////////////////////
// Filename: StateManager.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef STATE_MANAGER_HPP
#define STATE_MANAGER_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "State.hpp"
#include "Containers/Map.hpp"
#include <string>
#include <map>
#include <memory>

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// A state manager that holds all the game states and allows for switching 
// between them.
////////////////////////////////////////////////////////////////////////////////
class StateManager
{
private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private typedefs
    ////////////////////////////////////////////////////////////////////////////////
    typedef std::shared_ptr<State>     StatePtr;
    typedef Map<std::string, StatePtr> StateMap;

public:

    ////////////////////////////////////////////////////////////////////////////////
    // Create a state manager
    ////////////////////////////////////////////////////////////////////////////////
    StateManager();

    ////////////////////////////////////////////////////////////////////////////////
    // Add a state to the state manager
    ////////////////////////////////////////////////////////////////////////////////
    void add(const std::string& key, StatePtr state);

    ////////////////////////////////////////////////////////////////////////////////
    // Get the current state
    ////////////////////////////////////////////////////////////////////////////////
    StatePtr getState() const;
    StatePtr getState(const std::string& key);

    ////////////////////////////////////////////////////////////////////////////////
    // Set a new state
    ////////////////////////////////////////////////////////////////////////////////
    void setState(const std::string& key);

private:    

    ////////////////////////////////////////////////////////////////////////////////
    // Private member data
    ////////////////////////////////////////////////////////////////////////////////
    StateMap m_states;
    StatePtr m_currentState;
};

}

#endif
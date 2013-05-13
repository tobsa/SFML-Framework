////////////////////////////////////////////////////////////////////////////////
// Filename: StateManager.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "StateManager.hpp"
#include "Log.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
StateManager::StateManager() :
    m_currentState (nullptr)
{
}

////////////////////////////////////////////////////////////////////////////////
void StateManager::add(const std::string& key, StatePtr state)
{
    if(m_states.find(key) == m_states.end())
        m_states[key] = state;
}

////////////////////////////////////////////////////////////////////////////////
StateManager::StatePtr StateManager::getState() const
{
    if(!m_currentState)
    {
        std::string error = "Error (StateManager::getState()): m_currentState == nullptr (You must set a starting state)";
        sfx::Log::write(error);
        throw error;
    }

    return m_currentState;
}

////////////////////////////////////////////////////////////////////////////////
StateManager::StatePtr StateManager::getState(const std::string& key)
{
    auto result = m_states.find(key);
    if(result == m_states.end())
    {
        std::string error = "Error (StateManager::getState()): " + key + " doesn't exist";
        sfx::Log::write(error);
        throw error;
    }

    return result->second;
}

////////////////////////////////////////////////////////////////////////////////
void StateManager::setState(const std::string& key)
{
    auto it = m_states.find(key);
    if(it == m_states.end())
    {
        std::string error = "Error (StateManager::setState()): " + key + " doesn't exist";
        sfx::Log::write(error);
        throw error;
    }

    if(m_currentState)
        m_currentState->onPause();

    m_currentState = it->second;
    m_currentState->onResume();
}

}
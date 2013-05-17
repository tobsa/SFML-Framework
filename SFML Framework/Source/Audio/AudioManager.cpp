////////////////////////////////////////////////////////////////////////////////
// Filename: AudioManager.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "AudioManager.hpp"
#include "../Application.hpp"
#include "../Utility/Log.hpp"
#include "../Utility/Utility.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
AudioManager::AudioManager(Application& application) :
    m_application (application)
{
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::setSound(const std::string& key, const std::string& filename, std::size_t channels)
{
    m_sounds.insert(key, Sound(key, m_application.getSoundBuffer(filename), channels));
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::playSound(const std::string& key)
{
     m_sounds.findWithErrorCheck(key, "Error (AudioManager::playSound()): " + key + " doesn't exist")->second.play();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::pauseSound(const std::string& key)
{
     m_sounds.findWithErrorCheck(key, "Error (AudioManager::pauseSound()): " + key + " doesn't exist")->second.pause();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::stopSound(const std::string& key)
{
     m_sounds.findWithErrorCheck(key, "Error (AudioManager::stopSound()): " + key + " doesn't exist")->second.stop();
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::isSoundPlaying(const std::string& key) const
{
    return m_sounds.findWithErrorCheck(key, "Error (AudioManager::isPlaying()): " + key + " doesn't exist")->second.isPlaying();
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::isSoundPaused(const std::string& key) const
{
    return m_sounds.findWithErrorCheck(key, "Error (AudioManager::isPaused()): " + key + " doesn't exist")->second.isPaused();
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::isSoundStopped(const std::string& key) const
{
    return m_sounds.findWithErrorCheck(key, "Error (AudioManager::isStopped()): " + key + " doesn't exist")->second.isStopped();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::setSoundVolume(const std::string& key, float volume)
{
    m_sounds.findWithErrorCheck(key, "Error (AudioManager::setSoundVolume()): " + key + " doesn't exist")->second.setVolume(volume);
}

////////////////////////////////////////////////////////////////////////////////
float AudioManager::getSoundVolume(const std::string& key) const
{
    return m_sounds.findWithErrorCheck(key, "Error (AudioManager::getSoundVolume()): " + key + " doesn't exist")->second.getVolume();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::removeSound(const std::string& key)
{
    m_sounds.remove(key);
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::createGroup(const std::string& group)
{
    m_soundGroups.insert(group, SoundGroup());    
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::addSoundToGroup(const std::string& group, const std::string& key)
{
    const auto& groupCheck = m_soundGroups.findWithErrorCheck(group, "Error (AudioManager::addSoundToGroup()): " + group + " doesn't exist");
    const auto& keyCheck   = m_sounds.findWithErrorCheck(key,        "Error (AudioManager::addSoundToGroup()): " + key   + " doesn't exist");

    groupCheck->second.addSound(keyCheck->second);
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::playSoundGroup(const std::string& group)
{
    m_soundGroups.findWithErrorCheck(group, "Error (AudioManager::addSoundToGroup()): " + group + " doesn't exist")->second.play();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::stopSoundGroup(const std::string& group)
{
    m_soundGroups.findWithErrorCheck(group, "Error (AudioManager::stopSoundGroup()): " + group + " doesn't exist")->second.stop();
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::isSoundGroupPlaying(const std::string& group) const
{
    return m_soundGroups.findWithErrorCheck(group, "Error (AudioManager::isSoundGroupPlaying()): " + group + " doesn't exist")->second.isPlaying();
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::isSoundGroupStopped(const std::string& group) const
{
    return m_soundGroups.findWithErrorCheck(group, "Error (AudioManager::isSoundGroupStopped()): " + group + " doesn't exist")->second.isStopped();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::removeSoundFromGroup(const std::string& group, const std::string& key)
{
    const auto& groupCheck = m_soundGroups.findWithErrorCheck(group, "Error (AudioManager::removeSoundFromGroup()): " + group + " doesn't exist");
    const auto& keyCheck   = m_sounds.findWithErrorCheck(key,        "Error (AudioManager::removeSoundFromGroup()): " + key   + " doesn't exist");

    groupCheck->second.removeSound(keyCheck->second);
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::removeGroup(const std::string& group)
{
    m_soundGroups.remove(group);    
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::onUpdate()
{
    for(auto& soundGroup : m_soundGroups)
        soundGroup.second.onUpdate();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::setSoundGroupVolume(const std::string& group, float volume)
{
    m_soundGroups.findWithErrorCheck(group, "Error (AudioManager::setSoundGroupVolume()): " + group + " doesn't exist")->second.setVolume(volume);
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::setSoundGroupOrder(const std::string& group, SoundGroup::Order order)
{
    m_soundGroups.findWithErrorCheck(group, "Error (AudioManager::setSoundGroupOrder()): " + group + " doesn't exist")->second.setOrder(order);
}

////////////////////////////////////////////////////////////////////////////////
float AudioManager::getSoundGroupVolume(const std::string& group) const
{
    return m_soundGroups.findWithErrorCheck(group, "Error (AudioManager::getSoundGroupVolume()): " + group + " doesn't exist")->second.getVolume();
}

////////////////////////////////////////////////////////////////////////////////
SoundGroup::Order AudioManager::getSoundGroupOrder(const std::string& group) const
{
    return m_soundGroups.findWithErrorCheck(group, "Error (AudioManager::getSoundGroupOrder()): " + group + " doesn't exist")->second.getOrder();
}

} // namespace sfx
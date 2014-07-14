////////////////////////////////////////////////////////////////////////////////
// Filename: AudioManager.cpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "AudioManager.hpp"
#include "../Utility/Log.hpp"
#include "../Utility/Utility.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
AudioManager::AudioManager()
{
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::setSound(const std::string& key, const sf::SoundBuffer& buffer, std::size_t channels)
{
    m_sounds.insert(key, Sound(key, buffer, channels));
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::setMusic(const std::string& key, const std::string& filename)
{
    m_musics.insert(key, std::make_shared<Music>(filename));
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
void AudioManager::playMusic(const std::string& key)
{
     m_musics.findWithErrorCheck(key, "Error (AudioManager::playMusic()): " + key + " doesn't exist")->second->play();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::pauseMusic(const std::string& key)
{
     m_musics.findWithErrorCheck(key, "Error (AudioManager::pauseMusic()): " + key + " doesn't exist")->second->pause();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::stopMusic(const std::string& key)
{
     m_musics.findWithErrorCheck(key, "Error (AudioManager::stopMusic()): " + key + " doesn't exist")->second->stop();
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::isSoundPlaying(const std::string& key) const
{
    return m_sounds.findWithErrorCheck(key, "Error (AudioManager::isSoundPlaying()): " + key + " doesn't exist")->second.isPlaying();
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::isSoundPaused(const std::string& key) const
{
    return m_sounds.findWithErrorCheck(key, "Error (AudioManager::isSoundPaused()): " + key + " doesn't exist")->second.isPaused();
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::isSoundStopped(const std::string& key) const
{
    return m_sounds.findWithErrorCheck(key, "Error (AudioManager::isSoundStopped()): " + key + " doesn't exist")->second.isStopped();
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::isMusicPlaying(const std::string& key) const
{
    return m_musics.findWithErrorCheck(key, "Error (AudioManager::isMusicPlaying()): " + key + " doesn't exist")->second->isPlaying();
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::isMusicPaused(const std::string& key) const
{
    return m_musics.findWithErrorCheck(key, "Error (AudioManager::isMusicPaused()): " + key + " doesn't exist")->second->isPaused();
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::isMusicStopped(const std::string& key) const
{
    return m_musics.findWithErrorCheck(key, "Error (AudioManager::isMusicStopped()): " + key + " doesn't exist")->second->isStopped();
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
void AudioManager::setMusicVolume(const std::string& key, float volume)
{
    m_musics.findWithErrorCheck(key, "Error (AudioManager::setMusicVolume()): " + key + " doesn't exist")->second->setVolume(volume);
}

////////////////////////////////////////////////////////////////////////////////
float AudioManager::getMusicVolume(const std::string& key) const
{
    return m_musics.findWithErrorCheck(key, "Error (AudioManager::getMusicVolume()): " + key + " doesn't exist")->second->getVolume();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::removeSound(const std::string& key)
{
    m_sounds.remove(key);
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::removeMusic(const std::string& key)
{
    m_musics.remove(key);
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::createSoundGroup(const std::string& group)
{
    m_soundGroups.insert(group, SoundGroup());
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::createMusicGroup(const std::string& group)
{
    m_musicGroups.insert(group, MusicGroup());
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::addSoundToGroup(const std::string& group, const std::string& key)
{
    const auto& groupCheck = m_soundGroups.findWithErrorCheck(group, "Error (AudioManager::addSoundToGroup()): " + group + " doesn't exist");
    const auto& keyCheck   = m_sounds.findWithErrorCheck(key,        "Error (AudioManager::addSoundToGroup()): " + key   + " doesn't exist");

    groupCheck->second.addSound(keyCheck->second);
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::addMusicToGroup(const std::string& group, const std::string& key)
{
    const auto& groupCheck = m_musicGroups.findWithErrorCheck(group, "Error (AudioManager::addMusicToGroup()): " + group + " doesn't exist");
    const auto& keyCheck   = m_musics.findWithErrorCheck(key,        "Error (AudioManager::addMusicToGroup()): " + key   + " doesn't exist");

    groupCheck->second.addMusic(keyCheck->second);
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
void AudioManager::playMusicGroup(const std::string& group)
{
    m_musicGroups.findWithErrorCheck(group, "Error (AudioManager::playMusicGroup()): " + group + " doesn't exist")->second.play();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::pauseMusicGroup(const std::string& group)
{
    m_musicGroups.findWithErrorCheck(group, "Error (AudioManager::pauseMusicGroup()): " + group + " doesn't exist")->second.pause();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::stopMusicGroup(const std::string& group)
{
    m_musicGroups.findWithErrorCheck(group, "Error (AudioManager::stopMusicGroup()): " + group + " doesn't exist")->second.stop();
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
bool AudioManager::isMusicGroupPlaying(const std::string& group) const
{
    return m_musicGroups.findWithErrorCheck(group, "Error (AudioManager::isMusicGroupPlaying()): " + group + " doesn't exist")->second.isPlaying();
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::isMusicGroupPaused(const std::string& group) const
{
    return m_musicGroups.findWithErrorCheck(group, "Error (AudioManager::isMusicGroupPaused()): " + group + " doesn't exist")->second.isPaused();
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::isMusicGroupStopped(const std::string& group) const
{
    return m_musicGroups.findWithErrorCheck(group, "Error (AudioManager::isMusicGroupStopped()): " + group + " doesn't exist")->second.isStopped();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::removeSoundFromGroup(const std::string& group, const std::string& key)
{
    const auto& groupCheck = m_soundGroups.findWithErrorCheck(group, "Error (AudioManager::removeSoundFromGroup()): " + group + " doesn't exist");
    const auto& keyCheck   = m_sounds.findWithErrorCheck(key,        "Error (AudioManager::removeSoundFromGroup()): " + key   + " doesn't exist");

    groupCheck->second.removeSound(keyCheck->second);
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::removeSoundGroup(const std::string& group)
{
    m_soundGroups.remove(group);
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::removeMusicFromGroup(const std::string& group, const std::string& key)
{
    const auto& groupCheck = m_musicGroups.findWithErrorCheck(group, "Error (AudioManager::removeMusicFromGroup()): " + group + " doesn't exist");
    const auto& keyCheck   = m_musics.findWithErrorCheck(key,        "Error (AudioManager::removeMusicFromGroup()): " + key   + " doesn't exist");

    groupCheck->second.removeMusic(keyCheck->second);
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::removeMusicGroup(const std::string& group)
{
    m_musicGroups.remove(group);
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::onUpdate()
{
    for(auto& soundGroup : m_soundGroups)
        soundGroup.second.onUpdate();

    for(auto& musicGroup : m_musicGroups)
        musicGroup.second.onUpdate();
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
void AudioManager::setMusicGroupVolume(const std::string& group, float volume)
{
    m_musicGroups.findWithErrorCheck(group, "Error (AudioManager::setMusicGroupVolume()): " + group + " doesn't exist")->second.setVolume(volume);
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::setMusicGroupOrder(const std::string& group, MusicGroup::Order order)
{
    m_musicGroups.findWithErrorCheck(group, "Error (AudioManager::setMusicGroupOrder()): " + group + " doesn't exist")->second.setOrder(order);
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

////////////////////////////////////////////////////////////////////////////////
float AudioManager::getMusicGroupVolume(const std::string& group) const
{
    return m_musicGroups.findWithErrorCheck(group, "Error (AudioManager::getMusicGroupVolume()): " + group + " doesn't exist")->second.getVolume();
}

////////////////////////////////////////////////////////////////////////////////
MusicGroup::Order AudioManager::getMusicGroupOrder(const std::string& group) const
{
    return m_musicGroups.findWithErrorCheck(group, "Error (AudioManager::getMusicGroupOrder()): " + group + " doesn't exist")->second.getOrder();
}

} // namespace sfx

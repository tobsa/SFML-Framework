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
void AudioManager::addSound(const std::string& key, const std::string& filename, std::size_t nbChannels)
{
    // Create sounds depending on channel size
    std::vector<sf::Sound> sounds;
    for(std::size_t i = 0; i < nbChannels; ++i)
        sounds.push_back(sf::Sound(m_application.getSoundBuffer(filename)));

    // Add them to the list
    m_sounds[key] = sounds;
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::playSound(const std::string& key)
{
    // Make sure the key exist
    auto result = m_sounds.find(key);
    if(result == m_sounds.end())
        sfx::Log::writeT("Error (AudioManager::playSound()): " + key + " doesn't exist");

    // Play a sound from a free channel
    for(auto& sound : result->second)
    {
        if(sound.getStatus() != sf::Sound::Playing)
        {
            sound.play();
            break;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::pauseSound(const std::string& key)
{
    // Make sure the key exist
    auto result = m_sounds.find(key);
    if(result == m_sounds.end())
        sfx::Log::writeT("Error (AudioManager::pauseSound()): " + key + " doesn't exist");

    // Pause the sounds
    for(auto& sound : result->second)
        sound.pause();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::stopSound(const std::string& key)
{
    // Make sure the key exist
    auto result = m_sounds.find(key);
    if(result == m_sounds.end())
        sfx::Log::writeT("Error (AudioManager::stopSound()): " + key + " doesn't exist");

    // Stop the sounds
    for(auto& sound : result->second)
        sound.stop();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::setSoundVolume(const std::string& key, float volume)
{
    // Make sure the key exist
    auto result = m_sounds.find(key);
    if(result == m_sounds.end())
        sfx::Log::writeT("Error (AudioManager::setVolume()): " + key + " doesn't exist");

    volume = sfx::clamp(volume, 0.f, 100.f);

    // Set sound volume
    for(auto& sound : result->second)
        sound.setVolume(volume);
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::setSoundLoop(const std::string& key, bool loop)
{
    // Make sure the key exist
    auto result = m_sounds.find(key);
    if(result == m_sounds.end())
        sfx::Log::writeT("Error (AudioManager::setLoop()): " + key + " doesn't exist");

    // Set loop
    for(auto& sound : result->second)
        sound.setLoop(loop);
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::setSoundPitch(const std::string& key, float pitch)
{
    // Make sure the key exist
    auto result = m_sounds.find(key);
    if(result == m_sounds.end())
        sfx::Log::writeT("Error (AudioManager::setPitch()): " + key + " doesn't exist");

    // Set pitch
    for(auto& sound : result->second)
        sound.setPitch(pitch);
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::isSoundPlaying(const std::string& key) const
{
    // Make sure the key exist
    auto result = m_sounds.find(key);
    if(result == m_sounds.end())
        sfx::Log::writeT("Error (AudioManager::isPlaying()): " + key + " doesn't exist");

    // Check if all channels is playing
    for(auto& sound : result->second)
    {
        if(sound.getStatus() != sf::Sound::Playing)
            return false;
    }

    return true;
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::isSoundPaused(const std::string& key) const
{
    // Make sure the key exist
    auto result = m_sounds.find(key);
    if(result == m_sounds.end())
        sfx::Log::writeT("Error (AudioManager::isPaused()): " + key + " doesn't exist");

    // Check if all channels is paused
    for(auto& sound : result->second)
    {
        if(sound.getStatus() != sf::Sound::Paused)
            return false;
    }

    return true;
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::isSoundStopped(const std::string& key) const
{
    // Make sure the key exist
    auto result = m_sounds.find(key);
    if(result == m_sounds.end())
        sfx::Log::writeT("Error (AudioManager::isStopped()): " + key + " doesn't exist");

    // Check if all channels is stopped
    for(auto& sound : result->second)
    {
        if(sound.getStatus() != sf::Sound::Stopped)
            return false;
    }

    return true;
}

////////////////////////////////////////////////////////////////////////////////
float AudioManager::getSoundVolume(const std::string& key) const
{
    // Make sure the key exist
    auto result = m_sounds.find(key);
    if(result == m_sounds.end())
        sfx::Log::writeT("Error (AudioManager::getVolume()): " + key + " doesn't exist");

    return result->second[0].getVolume();
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::getSoundLoop(const std::string& key) const
{
    // Make sure the key exist
    auto result = m_sounds.find(key);
    if(result == m_sounds.end())
        sfx::Log::writeT("Error (AudioManager::getLoop()): " + key + " doesn't exist");

    return result->second[0].getLoop();
}

////////////////////////////////////////////////////////////////////////////////
float AudioManager::getSoundPitch(const std::string& key) const
{
    // Make sure the key exist
    auto result = m_sounds.find(key);
    if(result == m_sounds.end())
        sfx::Log::writeT("Error (AudioManager::getPitch()): " + key + " doesn't exist");

    return result->second[0].getPitch();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::addMusic(const std::string& key, const std::string& filename)
{
    auto object = std::make_shared<sf::Music>();
    object->openFromFile(filename);

    m_musics[key] = object;
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::playMusic(const std::string& key)
{
    // Make sure the key exist
    auto result = m_musics.find(key);
    if(result == m_musics.end())
        sfx::Log::writeT("Error (AudioManager::playMusic()): " + key + " doesn't exist");

    result->second->play();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::pauseMusic(const std::string& key)
{
    // Make sure the key exist
    auto result = m_musics.find(key);
    if(result == m_musics.end())
        sfx::Log::writeT("Error (AudioManager::pauseMusic()): " + key + " doesn't exist");

    result->second->pause();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::stopMusic(const std::string& key)
{
    // Make sure the key exist
    auto result = m_musics.find(key);
    if(result == m_musics.end())
        sfx::Log::writeT("Error (AudioManager::stopMusic()): " + key + " doesn't exist");

    result->second->stop();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::setMusicVolume(const std::string& key, float volume)
{
    // Make sure the key exist
    auto result = m_musics.find(key);
    if(result == m_musics.end())
        sfx::Log::writeT("Error (AudioManager::setMusicVolume()): " + key + " doesn't exist");

    volume = sfx::clamp(volume, 0.f, 100.f);

    result->second->setVolume(volume);
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::setMusicLoop(const std::string& key, bool loop)
{
    // Make sure the key exist
    auto result = m_musics.find(key);
    if(result == m_musics.end())
        sfx::Log::writeT("Error (AudioManager::setMusicLoop()): " + key + " doesn't exist");

    result->second->setLoop(loop);
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::setMusicPitch(const std::string& key, float pitch)
{
    // Make sure the key exist
    auto result = m_musics.find(key);
    if(result == m_musics.end())
        sfx::Log::writeT("Error (AudioManager::setMusicPitch()): " + key + " doesn't exist");

    result->second->setPitch(pitch);
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::isMusicPlaying(const std::string& key) const
{
    // Make sure the key exist
    auto result = m_musics.find(key);
    if(result == m_musics.end())
        sfx::Log::writeT("Error (AudioManager::isMusicPlaying()): " + key + " doesn't exist");

    return result->second->getStatus() == sf::Music::Playing;
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::isMusicPaused(const std::string& key) const
{
    // Make sure the key exist
    auto result = m_musics.find(key);
    if(result == m_musics.end())
        sfx::Log::writeT("Error (AudioManager::isMusicPaused()): " + key + " doesn't exist");

    return result->second->getStatus() == sf::Music::Paused;
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::isMusicStopped(const std::string& key) const
{
    // Make sure the key exist
    auto result = m_musics.find(key);
    if(result == m_musics.end())
        sfx::Log::writeT("Error (AudioManager::isMusicStopped()): " + key + " doesn't exist");

    return result->second->getStatus() == sf::Music::Stopped;
}

////////////////////////////////////////////////////////////////////////////////
float AudioManager::getMusicVolume(const std::string& key) const
{
    // Make sure the key exist
    auto result = m_musics.find(key);
    if(result == m_musics.end())
        sfx::Log::writeT("Error (AudioManager::getMusicVolume()): " + key + " doesn't exist");

    return result->second->getVolume();
}

////////////////////////////////////////////////////////////////////////////////
bool AudioManager::getMusicLoop(const std::string& key) const
{
    // Make sure the key exist
    auto result = m_musics.find(key);
    if(result == m_musics.end())
        sfx::Log::writeT("Error (AudioManager::getMusicLoop()): " + key + " doesn't exist");

    return result->second->getLoop();
}

////////////////////////////////////////////////////////////////////////////////
float AudioManager::getMusicPitch(const std::string& key) const
{
    // Make sure the key exist
    auto result = m_musics.find(key);
    if(result == m_musics.end())
        sfx::Log::writeT("Error (AudioManager::getMusicPitch()): " + key + " doesn't exist");

    return result->second->getPitch();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::addSoundToList(const std::string& soundList, const std::string& filename)
{
    if(m_soundList.find(soundList) == m_soundList.end())
    {
        m_soundList[soundList] = sfx::SoundList();
    }

    m_soundList[soundList].addSound(sf::Sound(m_application.getSoundBuffer(filename)));
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::playSoundList(const std::string& soundList)
{
    if(m_soundList.find(soundList) == m_soundList.end())
        sfx::Log::writeT("Error (AudioManager::playSoundList()): " + soundList + " doesn't exist");

    m_soundList[soundList].play();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::pauseSoundList(const std::string& soundList)
{
    if(m_soundList.find(soundList) == m_soundList.end())
        sfx::Log::writeT("Error (AudioManager::pauseSoundList()): " + soundList + " doesn't exist");

    m_soundList[soundList].pause();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::stopSoundList(const std::string& soundList)
{
    if(m_soundList.find(soundList) == m_soundList.end())
        sfx::Log::writeT("Error (AudioManager::stopSoundList()): " + soundList + " doesn't exist");

    m_soundList[soundList].stop();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::setSoundListOrder(const std::string& soundList, sfx::SoundList::Order order)
{
    if(m_soundList.find(soundList) == m_soundList.end())
        sfx::Log::writeT("Error (AudioManager::setSoundListOrder()): " + soundList + " doesn't exist");

    m_soundList[soundList].setOrder(order);
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::onUpdate()
{
    for(auto& soundList : m_soundList)
        soundList.second.onUpdate();

    for(auto& musicList : m_musicList)
        musicList.second.onUpdate();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::addMusicToList(const std::string& musicList, const std::string& filename)
{
    if(m_musicList.find(musicList) == m_musicList.end())
    {
        m_musicList[musicList] = sfx::MusicList();
    }

    m_musicList[musicList].addMusic(filename);
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::playMusicList(const std::string& musicList)
{
    if(m_musicList.find(musicList) == m_musicList.end())
        sfx::Log::writeT("Error (AudioManager::playMusicList()): " + musicList + " doesn't exist");

    m_musicList[musicList].play();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::pauseMusicList(const std::string& musicList)
{
    if(m_musicList.find(musicList) == m_musicList.end())
        sfx::Log::writeT("Error (AudioManager::pauseMusicList()): " + musicList + " doesn't exist");

    m_musicList[musicList].pause();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::stopMusicList(const std::string& musicList)
{
    if(m_musicList.find(musicList) == m_musicList.end())
        sfx::Log::writeT("Error (AudioManager::stopMusicList()): " + musicList + " doesn't exist");

    m_musicList[musicList].stop();
}

////////////////////////////////////////////////////////////////////////////////
void AudioManager::setMusicListOrder(const std::string& musicList, sfx::MusicList::Order order)
{
    if(m_musicList.find(musicList) == m_musicList.end())
        sfx::Log::writeT("Error (AudioManager::setMusicListOrder()): " + musicList + " doesn't exist");

    m_musicList[musicList].setOrder(order);
}

} // namespace sfx
////////////////////////////////////////////////////////////////////////////////
// Filename: AudioManager.hpp
// Author:   Tobias Savinainen
// Year:     2013
////////////////////////////////////////////////////////////////////////////////
#ifndef SFX_AUDIO_MANAGER_HPP
#define SFX_AUDIO_MANAGER_HPP

////////////////////////////////////////////////////////////////////////////////
// Header files
////////////////////////////////////////////////////////////////////////////////
#include "SoundGroup.hpp"
#include "MusicGroup.hpp"
#include "../Containers/Map.hpp"

namespace sfx
{

////////////////////////////////////////////////////////////////////////////////
// A basic audio player that can play music and sounds
////////////////////////////////////////////////////////////////////////////////
class AudioManager
{
private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private typedefs
    ////////////////////////////////////////////////////////////////////////////////
    typedef Map<std::string, Sound>        SoundMap;
    typedef Map<std::string, SoundGroup>   SoundGroupMap;
    typedef std::shared_ptr<Music>         MusicPtr;
    typedef Map<std::string, MusicPtr>     MusicMap;
    typedef Map<std::string, MusicGroup>   MusicGroupMap;

public:

    ////////////////////////////////////////////////////////////////////////////////
    // Create an audio manager
    ////////////////////////////////////////////////////////////////////////////////
    AudioManager();

    ////////////////////////////////////////////////////////////////////////////////
    // Add a sound/music to the manager. If the key already exist the previous value will
    // be overwritten.
    ////////////////////////////////////////////////////////////////////////////////
    void setSound(const std::string& key, const sf::SoundBuffer& buffer, std::size_t channels = 1);
    void setMusic(const std::string& key, const std::string& filename);

    ////////////////////////////////////////////////////////////////////////////////
    // Play, pause and stop sound/music
    ////////////////////////////////////////////////////////////////////////////////
    void playSound(const std::string& key);
    void pauseSound(const std::string& key);
    void stopSound(const std::string& key);
    void playMusic(const std::string& key);
    void pauseMusic(const std::string& key);
    void stopMusic(const std::string& key);

    ////////////////////////////////////////////////////////////////////////////////
    // Is the sound/music playing, paused or stopped?
    ////////////////////////////////////////////////////////////////////////////////
    bool isSoundPlaying(const std::string& key) const;
    bool isSoundPaused(const std::string& key) const;
    bool isSoundStopped(const std::string& key) const;
    bool isMusicPlaying(const std::string& key) const;
    bool isMusicPaused(const std::string& key) const;
    bool isMusicStopped(const std::string& key) const;

    ////////////////////////////////////////////////////////////////////////////////
    // Get and set volume
    ////////////////////////////////////////////////////////////////////////////////
    void setSoundVolume(const std::string& key, float volume);
    float getSoundVolume(const std::string& key) const;
    void setMusicVolume(const std::string& key, float volume);
    float getMusicVolume(const std::string& key) const;

    ////////////////////////////////////////////////////////////////////////////////
    // Remove a sound/music from the manager
    ////////////////////////////////////////////////////////////////////////////////
    void removeSound(const std::string& key);
    void removeMusic(const std::string& key);

    ////////////////////////////////////////////////////////////////////////////////
    // Create and add sound/music to a group
    ////////////////////////////////////////////////////////////////////////////////
    void createSoundGroup(const std::string& group);
    void createMusicGroup(const std::string& group);
    void addSoundToGroup(const std::string& group, const std::string& key);
    void addMusicToGroup(const std::string& group, const std::string& key);

    ////////////////////////////////////////////////////////////////////////////////
    // Play and stop a sound/music group
    ////////////////////////////////////////////////////////////////////////////////
    void playSoundGroup(const std::string& group);
    void stopSoundGroup(const std::string& group);
    void playMusicGroup(const std::string& group);
    void pauseMusicGroup(const std::string& group);
    void stopMusicGroup(const std::string& group);

    ////////////////////////////////////////////////////////////////////////////////
    // Is a sound/music group playing or stopped?
    ////////////////////////////////////////////////////////////////////////////////
    bool isSoundGroupPlaying(const std::string& group) const;
    bool isSoundGroupStopped(const std::string& group) const;
    bool isMusicGroupPlaying(const std::string& group) const;
    bool isMusicGroupPaused(const std::string& group) const;
    bool isMusicGroupStopped(const std::string& group) const;

    ////////////////////////////////////////////////////////////////////////////////
    // Remove sound/music from a group
    ////////////////////////////////////////////////////////////////////////////////
    void removeSoundFromGroup(const std::string& group, const std::string& key);
    void removeSoundGroup(const std::string& group);
    void removeMusicFromGroup(const std::string& group, const std::string& key);
    void removeMusicGroup(const std::string& group);

    ////////////////////////////////////////////////////////////////////////////////
    // Update audio manager
    ////////////////////////////////////////////////////////////////////////////////
    void onUpdate();

    ////////////////////////////////////////////////////////////////////////////////
    // Set sound/music group volume and order
    ////////////////////////////////////////////////////////////////////////////////
    void setSoundGroupVolume(const std::string& group, float volume);
    void setSoundGroupOrder(const std::string& group, SoundGroup::Order order);
    void setMusicGroupVolume(const std::string& group, float volume);
    void setMusicGroupOrder(const std::string& group, MusicGroup::Order order);

    ////////////////////////////////////////////////////////////////////////////////
    // Get sound/music group volume and order
    ////////////////////////////////////////////////////////////////////////////////
    float getSoundGroupVolume(const std::string& group) const;
    SoundGroup::Order getSoundGroupOrder(const std::string& group) const;
    float getMusicGroupVolume(const std::string& group) const;
    MusicGroup::Order getMusicGroupOrder(const std::string& group) const;

private:

    ////////////////////////////////////////////////////////////////////////////////
    // Private member data
    ////////////////////////////////////////////////////////////////////////////////
    SoundMap      m_sounds;
    SoundGroupMap m_soundGroups;
    MusicMap      m_musics;
    MusicGroupMap m_musicGroups;
};

} // namespace sfx

#endif

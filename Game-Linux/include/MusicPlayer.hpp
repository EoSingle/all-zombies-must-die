#pragma once

#include <SFML/Audio.hpp>

/// @brief MusicPlayer class
///
/// This class is responsible for the game musics.
class MusicPlayer
{
private:
    /// @brief Music Attributes
    sf::Music music;
    std::string filePath;
    float volume;

public:
    /// @brief Default Constructor
    ///
    /// Songs start at maximum volume (100%) and with no file path.
    MusicPlayer();

    /// @brief Destructor
    ~MusicPlayer();

    /// @brief Play the music
    void play();

    /// @brief Stop the music
    void stop();

    /// @brief Pause the music
    void pause();

    /// @brief Set the music volume
    /// @param volume The volume to set
    void setVolume(float volume);

    /// @brief Set the music loop (repeat)
    /// @param loop True to loop the music, false otherwise
    void setLoop(bool loop);

    /// @brief Set the music file path
    /// @param filePath The file path to set
    void setFilePath(std::string filePath);

    /// @brief Open the music from a file
    /// @param filePath The file path to open the music
    void openFromFile(std::string filePath);

    /// @brief Check if the music is playing
    /// @return True if the music is playing, false otherwise
    const bool isPlaying() const;

    /// @brief Get the music volume
    /// @return The music volume
    const float getVolume() const;

    /// @brief Get the music file path
    /// @return The music file path
    const std::string getFilePath() const;
};
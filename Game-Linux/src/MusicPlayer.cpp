#include "MusicPlayer.hpp"

MusicPlayer::MusicPlayer()
{
    this->volume = 100.f;
    this->filePath = "";
}

MusicPlayer::~MusicPlayer() {}

void MusicPlayer::play()
{
    this->music.play();
}

void MusicPlayer::stop()
{
    this->music.stop();
}

void MusicPlayer::pause()
{
    this->music.pause();
}

void MusicPlayer::setVolume(float volume)
{
    if (volume >= 0.f && volume <= 100.f)
    {
        this->volume = volume;
        this->music.setVolume(this->volume);
    }
}

void MusicPlayer::setLoop(bool loop)
{
    this->music.setLoop(loop);
}

void MusicPlayer::setFilePath(std::string filePath)
{
    this->filePath = filePath;
    this->music.openFromFile(this->filePath);
}

void MusicPlayer::openFromFile(std::string filePath)
{
    this->music.openFromFile(filePath);
}

const bool MusicPlayer::isPlaying() const
{
    return this->music.getStatus() == this->music.Playing;
}

const float MusicPlayer::getVolume() const
{
    return this->volume;
}

const std::string MusicPlayer::getFilePath() const
{
    return this->filePath;
}
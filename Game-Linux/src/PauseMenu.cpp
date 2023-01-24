#include "PauseMenu.hpp"

PauseMenu::PauseMenu(sf::RenderTarget& target ){
    this->pauseMenu.setSize(sf::Vector2f(target.getSize().x, target.getSize().y));
    this->pauseMenu.setFillColor(sf::Color(20, 20, 20, 100));

    //this->textPause.setFont(this->font);
    this->textPause.setCharacterSize(50);
    this->textPause.setFillColor(sf::Color::White);
    this->textPause.setPosition(sf::Vector2f(target.getSize().x / 2.f - 200.f, target.getSize().y / 2.f - 100.f));
    this->textPause.setString("Game Paused");

    //this->textContinue.setFont(this->font);
    this->textContinue.setCharacterSize(30);
    this->textContinue.setFillColor(sf::Color::White);
    this->textContinue.setPosition(sf::Vector2f(target.getSize().x / 2.f - 220.f, target.getSize().y / 2.f));
    this->textContinue.setString("Press TAB to continue");

    //this->textExit.setFont(this->font);
    this->textExit.setCharacterSize(30);
    this->textExit.setFillColor(sf::Color::White);
    this->textExit.setPosition(sf::Vector2f(target.getSize().x / 2.f - 320.f, target.getSize().y / 2.f + 80.f));
    this->textExit.setString("Press ESC to return to main menu");

    //this->textVolume.setFont(this->font);
    this->textVolume.setCharacterSize(15);
    this->textVolume.setFillColor(sf::Color::White);
    this->textVolume.setPosition(sf::Vector2f(50, target.getSize().y / 2.f + 200.f));
    this->textVolume.setString("Press UP ARROW to increase volume and DOWN ARROW to decrease volume");

    //this->textVolumeValue.setFont(this->font);
    this->textVolumeValue.setCharacterSize(15);
    this->textVolumeValue.setFillColor(sf::Color::White);
    this->textVolumeValue.setPosition(sf::Vector2f(50, target.getSize().y / 2.f + 230.f));
}

PauseMenu::~PauseMenu(){
}

void PauseMenu::setFont(sf::Font& font){
    this->textPause.setFont(font);
    this->textContinue.setFont(font);
    this->textExit.setFont(font);
    this->textVolume.setFont(font);
    this->textVolumeValue.setFont(font);
}

void PauseMenu::setVolume(int volume){
    this->textVolumeValue.setString("Volume " + std::to_string(volume));
}

void PauseMenu::render(sf::RenderTarget* target, int volume){
    target->draw(this->pauseMenu);
    target->draw(this->textPause);
    target->draw(this->textContinue);
    target->draw(this->textExit);
    target->draw(this->textVolume);
    setVolume(volume);
    target->draw(this->textVolumeValue);
}
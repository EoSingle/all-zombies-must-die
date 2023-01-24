#include "GameOver.hpp"

GameOver::GameOver(sf::RenderTarget& target){
    this->gameOverMenu.setSize(sf::Vector2f(target.getSize().x, target.getSize().y));
    this->gameOverMenu.setFillColor(sf::Color(20, 20, 20, 150));

    //this->textGameOver.setFont(this->font);
    this->textGameOver.setCharacterSize(50);
    this->textGameOver.setFillColor(sf::Color::Red);
    this->textGameOver.setPosition(sf::Vector2f(target.getSize().x / 2.f - 130.f, target.getSize().y / 2.f - 100.f));
    this->textGameOver.setString("You Died");

    //this->textGameOverExit.setFont(this->font);
    this->textGameOverExit.setCharacterSize(30);
    this->textGameOverExit.setFillColor(sf::Color::White);
    this->textGameOverExit.setPosition(sf::Vector2f(target.getSize().x / 2.f - 320.f, target.getSize().y / 2.f + 80.f));
    this->textGameOverExit.setString("Press ESC to return to main menu");

    //this->textGameOverScore.setFont(this->font);
    this->textGameOverScore.setCharacterSize(30);
    this->textGameOverScore.setFillColor(sf::Color::White);
    this->textGameOverScore.setPosition(sf::Vector2f(target.getSize().x / 2.f - 320.f, target.getSize().y / 2.f));
    //this->textGameOverScore.setString("Score " + std::to_string(this->points));
}

GameOver::~GameOver(){
}

void GameOver::setFont(sf::Font& font){
    this->textGameOver.setFont(font);
    this->textGameOverExit.setFont(font);
    this->textGameOverScore.setFont(font);
}

void GameOver::setPoints(int points){
    this->textGameOverScore.setString("Score " + std::to_string(points));
}

void GameOver::render(sf::RenderTarget* target){
    target->draw(this->gameOverMenu);
    target->draw(this->textGameOver);
    target->draw(this->textGameOverScore);
    target->draw(this->textGameOverExit);
}

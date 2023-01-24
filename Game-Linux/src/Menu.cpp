#include "Menu.hpp"

void Menu::loadFonts(){
    if(!this->mainMenuFont.loadFromFile("assets/Fonts/darkstar.ttf")){
        throw("ERROR::GAME::COULD NOT LOAD FONT DARKSTAR");
    }

    if(!this->titleFont.loadFromFile("assets/Fonts/titlefont.ttf")){
        throw("ERROR::GAME::COULD NOT LOAD FONT TITLEFONT");
    }
}

Menu::Menu(sf::RenderTarget& target){
    if(!this->mainMenuBackgroundTex.loadFromFile("assets/Textures/menu.png")){
        std::cout << "ERROR::GAME::COULD NOT LOAD MAIN MENU BACKGROUND" << "\n";
    }
    this->mainMenuBackground.setTexture(this->mainMenuBackgroundTex);
    this->mainMenuBackground.setScale(1.2f, 1.2f);

    this->loadFonts();

    this->mainMenuText.setFont(this->titleFont);
    this->mainMenuText.setCharacterSize(40);
    this->mainMenuText.setFillColor(sf::Color::White);
    this->mainMenuText.setPosition(sf::Vector2f(target.getSize().x / 2.f - 180.f, target.getSize().y / 2.f + 200.f));
    this->mainMenuText.setString("PRESS  ENTER  TO  START");

    this->mainMenuTitle.setFont(this->titleFont);
    this->mainMenuTitle.setCharacterSize(60);
    this->mainMenuTitle.setFillColor(sf::Color::White);
    this->mainMenuTitle.setPosition(sf::Vector2f(target.getSize().x / 2.f - 300.f, target.getSize().y / 2.f - 220.f));
    this->mainMenuTitle.setString("ALL  ZOMBIES \n     MUST  DIE");

    this->fontColor = 255;
    this->fontLoop = true;

    this->mainMenuMusic.setFilePath("assets/Music/track2.ogg");
    this->mainMenuMusic.openFromFile(this->mainMenuMusic.getFilePath());
    this->mainMenuMusic.setLoop(true);
    this->mainMenuMusic.setVolume(20.f);
    this->mainMenuMusic.play();

}

Menu::~Menu(){
}

void Menu::playMusic(){
    this->mainMenuMusic.play();
}

void Menu::stopMusic(){
    this->mainMenuMusic.stop();
}

void Menu::render(sf::RenderTarget* target){
    target->draw(this->mainMenuBackground);
    
    // Text Animation
    if(this->fontLoop){
        fontColor-=5;
        if(fontColor <= 0){
            fontColor = 0;
            this->fontLoop = false;
        }
    } else {
        fontColor+=5;
        if(fontColor >= 255){
            fontColor = 255;
            this->fontLoop = true;
        }
    }

    this->mainMenuText.setFillColor(sf::Color(255,255,255,fontColor));
    target->draw(this->mainMenuText);
    target->draw(this->mainMenuTitle);
}

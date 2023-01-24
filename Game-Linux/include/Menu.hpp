#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "MusicPlayer.hpp"

/// @brief Menu class
///
/// This class is responsible for the menu screen.
class Menu{
    private:
        /// @brief Menu Attributes
        sf::Texture mainMenuBackgroundTex;
        sf::Sprite mainMenuBackground;
        sf::Font mainMenuFont;
        sf::Text mainMenuText;
        sf::Font titleFont;
        sf::Text mainMenuTitle;
        int fontColor;
        bool fontLoop;
        MusicPlayer mainMenuMusic;

        /// @brief load the menu screen fonts
        void loadFonts();

    public:
        /// @brief Default Constructor
        /// @param target A reference to the window to set the menu screen attributes
        Menu(sf::RenderTarget& target);

        /// @brief Destructor
        ~Menu();

        /// @brief Play the menu screen music
        void playMusic();

        /// @brief Stop the menu screen music
        void stopMusic();

        /// @brief Render the menu screen
        /// @param target A pointer to the window to render the menu screen
        void render(sf::RenderTarget* target);

};
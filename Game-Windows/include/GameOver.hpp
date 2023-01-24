#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

/// @brief GameOver class
///
/// This class is responsible for the game over screen.
class GameOver{
    private:
        /// @brief GameOver Attributes
        sf::RectangleShape gameOverMenu;
        sf::Text textGameOver;
        sf::Text textGameOverScore;
        sf::Text textGameOverExit;

    public:
        /// @brief Default Constructor
        /// @param target The target to render the game over screen 
        GameOver(sf::RenderTarget& target);

        /// @brief Destructor
        ~GameOver();

        /// @brief Set the game over screen font
        /// @param font A reference to the font
        void setFont(sf::Font& font);

        /// @brief Set the game over screen score
        void setPoints(int points);

        /// @brief Render the game over screen
        /// @param target A reference to the window to render the game over screen
        void render(sf::RenderTarget* target);


};


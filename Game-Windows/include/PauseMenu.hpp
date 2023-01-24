#pragma once

#include "SFML/Graphics.hpp"

/// @brief PauseMenu class
///
/// This class is responsible for the pause menu screen.
class PauseMenu{
    private:
        /// @brief PauseMenu Attributes
        sf::RectangleShape pauseMenu;
        sf::Text textPause;
        sf::Text textContinue;
        sf::Text textVolume;
        sf::Text textVolumeValue;
        sf::Text textExit;

    public:
        /// @brief Default Constructor
        /// @param target A window reference to set the pause menu screen attributes
        PauseMenu(sf::RenderTarget& target);

        /// @brief Destructor
        ~PauseMenu();

        /// @brief Set the pause menu screen font
        /// @param font A reference to the font
        void setFont(sf::Font& font);

        /// @brief Set the pause menu music volume
        /// @param volume The volume to set
        void setVolume(int volume);

        /// @brief Render the pause menu screen
        /// @param target A pointer to the window to render the pause menu screen
        /// @param volume The current volume of the music
        void render(sf::RenderTarget* target, int volume);
};
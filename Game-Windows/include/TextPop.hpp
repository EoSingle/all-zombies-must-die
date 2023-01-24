#pragma once

#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>

/// @brief TextPop class
///
/// This class is responsible for the text pop ups.
class TextPop
{
private:
    /// @brief TextPop Attributes
    sf::Text text;
    sf::RenderWindow *window;
    float counter;
    float duration;
    bool done;

public:
    /// @brief Default Constructor
    /// @param font A reference to the font
    /// @param txt The text to display
    /// @param pos The position to display the text
    /// @param color The color of the text
    /// @param duration The duration of the text
    TextPop(sf::Font &font, std::string txt, sf::Vector2f pos, sf::Color color, float duration);
    
    /// @brief Destructor
    ~TextPop();

    /// @brief Get the pop up text
    /// @return The pop up text
    sf::Text getText();

    /// @brief Inform if the pop up is done
    /// @return True if the pop up is done, false otherwise
    bool isDone();

    /// @brief Update the pop up text
    void update();

    /// @brief Render the pop up text
    /// @param target A reference to the window to render the pop up text
    void render(sf::RenderTarget *target);
};
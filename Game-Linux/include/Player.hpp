#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include "Health.hpp"
#include "Gun.hpp"

/// @brief Player class
///
/// This class is responsible for the player.
class Player
{
private:

    /// Player Texture
    sf::Sprite sprite;
    sf::Texture texture;

    /// Player Attributes
    Health playerHP;
    Gun playerGun;
    float movementSpeed;

    /// Private Functions
    void initVariables();
    void initTextures();
    void initSprite();

public:
    /// @brief Constructor
    Player();

    /// @brief Destructor
    ~Player();

    /// @brief Inform the player's position
    /// @return The sprite position x and y in the window
    const sf::Vector2f &getPos() const;

    /// @brief Inform the player's bounds
    /// @return The sprite global bounds
    const sf::FloatRect getBounds() const;

    /// @brief Inform the player's health
    /// @return A reference to the player's health
    Health *getHealth();

    /// @brief Inform the player's gun
    /// @return A reference to the player's gun
    Gun *getGun();

    /// @brief Inform the player's damage
    /// @return A random number between the gun's damage and the gun's damage + range
    int getDamage();

    /// @brief Set the player's gun
    /// @param newGun A pointer to the new gun
    void setGun(Gun *newGun);

    /// @brief Set the player's position
    /// @param pos The new position
    void setPosition(const sf::Vector2f pos);

    /// @brief Set the player's position
    /// @param x The new position x
    /// @param y The new position y
    void setPosition(const float x, const float y);

    /// @brief Move the player
    /// @param dirX The x direction to move
    /// @param dirY The y direction to move
    void move(const float dirX, const float dirY);

    /// @brief Inform if the player can attack
    /// @return True if the player can shoot, false otherwise
    const bool canAttack();

    /// @brief Attack
    /// @return True if the player has shot, false otherwise
    bool attack();

    /// @brief Update the player
    void update();

    /// @brief Render the player
    /// @param target A reference to the window to render the player
    void render(sf::RenderTarget &target);
};

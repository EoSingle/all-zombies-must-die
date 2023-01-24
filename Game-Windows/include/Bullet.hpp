#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include <cmath>

/// @brief Bullet class
///
/// This class is responsible for the bullets.
class Bullet
{
private:
    /// @brief Bullet Texture
    sf::Sprite shape;
    sf::Texture *texture;

    /// @brief Bullet Attributes
    sf::Vector2f direction;
    int damage;
    float movementSpeed;

public:
    /// @brief Default Constructor
    /// @param texture A pointer to the texture
    /// @param initialPos The initial position of the bullet
    /// @param dir The direction of the bullet
    /// @param dmg The damage of the bullet
    /// @param moveSpeed The movement speed of the bullet
    Bullet(sf::Texture *texture, sf::Vector2f initialPos, sf::Vector2f dir, int dmg, float moveSpeed);
    
    /// @brief Destructor
    ~Bullet();

    /// @brief Inform the bullet's bounds
    /// @return The global bounds of the bullet
    const sf::FloatRect getBounds() const;

    /// @brief Inform the bullet's damage
    /// @return The damage of the bullet
    int getDamage();

    /// @brief Set the bullet's damage to half
    void wallBang();

    /// @brief Update the bullet's movement
    void update();

    /// @brief Render the bullet
    /// @param target The target to render the bullet
    void render(sf::RenderTarget *target);
};

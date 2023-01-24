#pragma once

#include <SFML\Graphics.hpp>
#include <cmath>
#include "Player.hpp"
#include "Health.hpp"

/// @brief Enemy class
///
/// This class is responsible for the enemies.
class Enemy
{
private:
    /// @brief Enemy Texture
    sf::Sprite sprite;
    sf::Texture texture;

    /// @brief Enemy Attributes
    Health enemyHP;
    int damage;
    int points;

    /// @brief A pointer to the player
    Player *playerRef;

    /// @brief Follow type attribute
    bool follows;

    /// @brief The enemy's movement speed and movement direction
    sf::Vector2f direction;
    float movementSpeed;

    /// @brief Private Functions
    void initVariables(int hp, int dmg, int pts);
    void initTextures();
    void initSprite();

public:
    /// @brief Default Constructor
    ///
    /// Creates an enemy with the information passed as parameters
    ///
    /// @param player A reference to the player
    /// @param moveSpeed The enemy's movement speed
    /// @param hp The enemy's health
    /// @param dmg The enemy's damage
    /// @param pts The enemy's points
    Enemy(Player &player, float moveSpeed, int hp, int dmg, int pts);

    /// @brief Copy constructor
    Enemy(const Enemy &e);

    /// @brief Destructor
    ~Enemy();

    /// @brief Inform the enemy's position
    /// @return The sprite position x and y in the window
    const sf::Vector2f &getPos() const;

    /// @brief Set the enemy's position
    /// @param newPos The new position
    void setPos(sf::Vector2f newPos);

    /// @brief Inform the enemy's bounds
    /// @return The sprite global bounds
    const sf::FloatRect getBounds() const;

    /// @brief Inform the enemy's health
    /// @return A reference to the enemy's health
    Health *getHealth();

    /// @brief Inform the enemy's health (const)
    /// @return A const reference to the enemy's health
    const Health *getHealthConst() const;

    /// @brief Inform the enemy's damage
    /// @return The enemy's damage
    const int &getDamage() const;

    /// @brief Inform the enemy's points
    /// @return The enemy's points
    int getPoints() const;

    /// @brief Update the enemy
    void update();

    /// @brief Render the enemy
    /// @param target A window reference to render the enemy
    void render(sf::RenderTarget *target);
};
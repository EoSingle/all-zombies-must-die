#pragma once

#include <list>
#include <iostream>
#include "Player.hpp"
#include "Enemy.hpp"

/// @brief Spawner class
///
/// This class is responsible for the enemy spawner.
class Spawner
{
private:
    /// @brief Spawner Attributes
    int waveCount;
    float stopwatch;
    std::vector<Enemy> enemyTypes;
    int waveAmount;

    sf::Window *window;
    Player *player;
    std::vector<Enemy *> *enemyVector;

    sf::Vector2f GetSpawnLocation();
    Enemy *GetRandomEnemy();

public:
    /// @brief Spawner Constructor
    /// @param window A reference to the game window
    /// @param player A reference to the player
    /// @param enemies A reference to the enemies vector
    Spawner(sf::Window &window, Player &player, std::vector<Enemy *> &enemies);
    
    /// @brief Spawner Destructor
    ~Spawner();

    /// @brief Get the wave number
    /// @return The wave number
    int waveNumber();

    /// @brief Spawn a random enemy
    void SpawnRandom();

    /// @brief Spawn a wave of enemies
    void SpawnWave();

    /// @brief Update the spawner
    void update();
};
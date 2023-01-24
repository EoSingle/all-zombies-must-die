#pragma once

/// @brief Health class
///
/// This class is responsible for the health.
class Health
{
private:
    /// @brief Health Attributes
    int hp;
    int hpMax;
    bool alive;

public:
    /// @brief Default Constructor
    ///
    /// This constructor creates a health with the default value of 100
    Health();

    /// @brief Constructor
    /// @param max The maximum health
    Health(int max);

    /// @brief Set the health
    /// @param value The health value
    void setHp(const int value);

    /// @brief Lose health
    /// @param value The health value to be lost
    void loseHp(const int value);

    /// @brief Turn alive to false
    void kill();

    /// @brief Get the health
    /// @return The health
    int getHp();

    /// @brief Get the maximum health
    /// @return The maximum health
    const int &getHpMax() const;

    /// @brief Check if the entity is alive
    /// @return True if the entity is alive, false otherwise
    bool isAlive();
};
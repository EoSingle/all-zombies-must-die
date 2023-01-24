#pragma once

#include <iostream>
#include <string>

/// @brief Game class
///
/// This class is responsible for the gun objects.
class Gun
{
private:
    /// @brief Gun type
    std::string name;

    /// @brief Gun ammo atributes
    int currentAmmo;
    int maxAmmo;

    /// @brief Gun damage atributes
    int baseDamage;
    int damageRange;
    float criticalChance;

    /// @brief Gun fire rate atributes
    float cooldown;
    float fireRate;
    float bulletSpeed;

    /// @brief Gun reload atributes
    bool reloading;
    float reloadProgress;
    float reloadTime;

public:
    /// @brief Default constructor
    Gun();

    /// @brief Constructor
    /// @param name The type of the gun
    /// @param maxAmmo The maximum ammo of the gun
    /// @param baseDamage The base damage of the gun
    /// @param damageRange The damage range of the gun
    /// @param criticalChance The critical chance of the gun
    /// @param fireRate The fire rate of the gun
    /// @param bulletSpeed The bullet speed of the gun
    /// @param reloadTime The reload time of the gun
    Gun(std::string name, int maxAmmo, int baseDamage, int damageRange, float critialChance, float fireRate, float bulletSpeed, float reloadTime);
    
    /// @brief Copy constructor
    /// @param g A reference to the gun to be copied
    Gun(const Gun &g);

    /// @brief Destructor
    ~Gun();

    /// @brief Inform the gun's name
    /// @return The gun's name
    std::string getName();

    /// @brief Inform the gun's current ammo
    /// @return The gun's current ammo
    int getAmmo();

    /// @brief Inform the gun's maximum ammo
    /// @return The gun's maximum ammo
    int getMaxAmmo();

    /// @brief Inform the gun's base damage
    /// @return The gun's base damage
    int getDamage();

    /// @brief Inform the gun's damage range
    /// @return The gun's damage range
    int getRange();

    /// @brief Inform the gun's critical chance
    /// @return The gun's critical chance
    float getCritChance();

    /// @brief Inform the gun's bullet speed
    /// @return The gun's bullet speed
    float getBulletSpeed();

    /// @brief Inform the gun's reload time
    /// @return The gun's reload time
    float getReloadTime();

    /// @brief Inform if the gun can shoot
    /// @return True if the gun can shoot, false otherwise
    bool canShoot();

    /// @brief Inform if the gun is reloading
    /// @return True if the gun is reloading, false otherwise
    bool isReloading();

    /// @brief Inform if the current shot is a critical hit
    /// @return True if the current shot is a critical hit, false otherwise
    bool critCheck();

    /// @brief Shoot!
    void shoot();

    /// @brief Reload!
    void reload();

    /// @brief Update the gun
    void update();
};
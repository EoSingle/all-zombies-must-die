#include "Gun.hpp"

Gun::Gun() : Gun("Pistol", 12, 4, 2, 0.1f, 2.f, 5.f, 5.f)
{
    currentAmmo = maxAmmo;
}

Gun::Gun(std::string name, int maxAmmo, int baseDamage, int damageRange, float criticalChance, float fireRate, float bulletSpeed, float reloadTime) : name(name), maxAmmo(maxAmmo), baseDamage(baseDamage), damageRange(damageRange), criticalChance(criticalChance), fireRate(fireRate), bulletSpeed(bulletSpeed), reloadTime(reloadTime)
{
    currentAmmo = maxAmmo;
    cooldown = 0.f;
}

Gun::Gun(const Gun &g)
{
    this->name = g.name;
    this->maxAmmo = g.maxAmmo;
    this->currentAmmo = g.currentAmmo;
    this->baseDamage = g.baseDamage;
    this->damageRange = g.damageRange;
    this->criticalChance = g.criticalChance;
    this->fireRate = g.fireRate;
    this->bulletSpeed = g.bulletSpeed;
    this->reloadTime = g.reloadTime;
}

Gun::~Gun() {}

std::string Gun::getName() { return name; }

int Gun::getAmmo() { return currentAmmo; }

int Gun::getMaxAmmo() { return maxAmmo; }

int Gun::getDamage() { return baseDamage; }

int Gun::getRange() { return damageRange; }

float Gun::getCritChance() { return criticalChance; }

float Gun::getBulletSpeed() { return bulletSpeed; }

float Gun::getReloadTime()
{
    return reloadTime;
}

bool Gun::canShoot()
{
    if (this->cooldown >= this->fireRate && currentAmmo > 0 && !reloading){
        return true;
    }
    return false;
}

bool Gun::isReloading()
{
    return reloading;
}

bool Gun::critCheck()
{
    if (rand() % 101 <= this->criticalChance * 100.f)
    {
        return true;
    }
    return false;
}

void Gun::shoot()
{
    this->currentAmmo--;
    this->cooldown = 0.f;
}

void Gun::reload()
{
    if (!reloading)
    {
        this->reloading = true;
        this->reloadProgress = 0.f;
    }
}

void Gun::update()
{
    if (this->cooldown < this->fireRate)
        this->cooldown += 0.1f;

    if (reloading)
    {
        this->reloadProgress += 0.1f;

        if (reloadProgress >= reloadTime)
        {
            this->currentAmmo = this->maxAmmo;
            reloading = false;
        }
    }
}
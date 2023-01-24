#include "Player.hpp"

// Private functions
void Player::initVariables()
{
    this->movementSpeed = 5.f;

    this->playerGun = Gun("Pistol", 12, 4, 2, 0.1f, 2.f, 5.f, 5.f);
    this->playerHP = Health(20);
}

void Player::initTextures()
{
    // Load texture from file
    if (!this->texture.loadFromFile("assets/Textures/player.png"))
        throw("ERROR::PLAYER::INITTEXTURES::Could not load texture file");
}

void Player::initSprite()
{
    // Set texture to sprite
    this->sprite.setTexture(this->texture);

    // Resize sprite
    this->sprite.scale(2.f, 2.f);

    // Set origin to center
    this->sprite.setPosition(400.f, 300.f);
}

// Constructor / Destructor
Player::Player()
{
    this->initVariables();
    this->initTextures();
    this->initSprite();
}

Player::~Player()
{
}

// Acessors
const sf::Vector2f &Player::getPos() const
{
    return this->sprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
    return this->sprite.getGlobalBounds();
}

Health *Player::getHealth()
{
    return &playerHP;
}

Gun *Player::getGun()
{
    return &playerGun;
}

int Player::getDamage()
{
    int dealtDMG = this->playerGun.getDamage() + (rand() % this->playerGun.getRange());

    if (this->playerGun.critCheck())
    {
        dealtDMG *= 3.f;
    }

    return dealtDMG;
}

// Modifiers
void Player::setGun(Gun *newGun)
{
    this->playerGun = *newGun;
}

void Player::setPosition(const sf::Vector2f pos)
{
    this->sprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
    this->sprite.setPosition(x, y);
}

// Functions
void Player::move(const float dirX, const float dirY)
{
    // Move the sprite
    this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

// Currently just calls canShoot() but will be expanded
const bool Player::canAttack()
{
    if (this->playerGun.canShoot())
    {
        return true;
    }
    return false;
}

bool Player::attack()
{
    if (this->canAttack())
    {
        this->playerGun.shoot();
        return true;
    }

    return false;
}

void Player::update()
{
    this->playerGun.update();
}

void Player::render(sf::RenderTarget &target)
{
    target.draw(this->sprite);
}
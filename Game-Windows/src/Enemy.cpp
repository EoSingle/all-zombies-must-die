#include "Enemy.hpp"

// Private Functions
void Enemy::initTextures()
{
    // Load texture from file
    if (!this->texture.loadFromFile("assets/Textures/Zombie.png"))
        throw("ERROR::ENEMY::INITTEXTURES::Could not load texture file");
}

void Enemy::initSprite()
{
    // Set texture to sprite
    this->sprite.setTexture(this->texture);

    // Resize sprite
    this->sprite.scale(2.f, 2.f);

    // Set origin to center
    this->sprite.setPosition(400.f, 300.f);
}

void Enemy::initVariables(int hp, int dmg, int pts)
{
    this->enemyHP = Health(hp);
    this->damage = dmg + rand() % 2;
    this->points = pts;
}

// Constructors / Destructors

// Follower enemy
Enemy::Enemy(Player &player, float moveSpeed, int hp, int dmg, int pts)
{
    this->initTextures();
    this->initSprite();
    this->initVariables(hp, dmg, pts);

    this->movementSpeed = moveSpeed + (rand() % 10 * 0.1f);

    playerRef = &player;
    follows = true;
}

Enemy::Enemy(const Enemy &e)
{
    this->initTextures();
    this->initSprite();
    this->initVariables(e.getHealthConst()->getHpMax(), e.getDamage(), e.getPoints());

    this->movementSpeed = e.movementSpeed;

    if (e.follows)
    {
        this->playerRef = e.playerRef;
        this->follows = true;
    }
    else
    {
        this->direction = e.direction;
        this->follows = false;
    }
}

// Destructor
Enemy::~Enemy() {}

// Accessors
const sf::Vector2f &Enemy::getPos() const
{
    return this->sprite.getPosition();
}

void Enemy::setPos(sf::Vector2f newPos)
{
    this->sprite.setPosition(newPos);
}

const sf::FloatRect Enemy::getBounds() const
{
    return this->sprite.getGlobalBounds();
}

Health *Enemy::getHealth()
{
    return &enemyHP;
}

const Health *Enemy::getHealthConst() const
{
    return &enemyHP;
}

const int &Enemy::getDamage() const
{
    return this->damage;
}

int Enemy::getPoints() const
{
    return this->points + rand() % 3;
}

// Functions

void Enemy::update()
{
    if (follows)
    {
        sf::Vector2f dir = playerRef->getPos() - this->getPos();
        float norma = sqrt(dir.x * dir.x + dir.y * dir.y);
        direction.x = dir.x / norma;
        direction.y = dir.y / norma;

        this->sprite.move(direction * movementSpeed);
    }
    else
    {
        this->sprite.move(direction * movementSpeed);
    }
}

void Enemy::render(sf::RenderTarget *target)
{
    target->draw(this->sprite);
}
#include "Bullet.hpp"

// Constructors / Destructors
Bullet::Bullet(sf::Texture *texture, sf::Vector2f initialPos, sf::Vector2f dir, int dmg, float moveSpeed)
{

    this->shape.setTexture(*texture);
    this->shape.setScale(1.5f, 1.5f);

    this->shape.setPosition(initialPos);
    this->damage = dmg;
    this->movementSpeed = moveSpeed;

    // Normalizando o vetor dir e aplicando em direção
    float norma = sqrt(dir.x * dir.x + dir.y * dir.y);
    direction.x = dir.x / norma;
    direction.y = dir.y / norma;
}

Bullet::~Bullet()
{
}

// Acessors
const sf::FloatRect Bullet::getBounds() const
{
    return this->shape.getGlobalBounds();
}

int Bullet::getDamage()
{
    return damage;
}

// Functions
void Bullet::wallBang()
{
    this->damage /= 1.5f;
}

void Bullet::update()
{
    // Movement
    this->shape.move(direction * movementSpeed);
}

void Bullet::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}
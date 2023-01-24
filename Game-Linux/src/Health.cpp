#include "Health.hpp"

Health::Health() : Health(100) { alive = true; }

Health::Health(int max) : hpMax(max)
{
    this->hp = hpMax;
    alive = true;
}

void Health::setHp(const int value)
{
    if (value > this->hpMax)
        this->hp = hpMax;
    else
        this->hp = value;

    if (this->hp <= 0)
        this->kill();
}

void Health::loseHp(const int value)
{
    if (value <= 0)
        return;

    this->hp -= value;

    if (this->hp <= 0)
        this->kill();
}

void Health::kill()
{
    this->alive = false;
}

int Health::getHp() { return hp; }

const int &Health::getHpMax() const { return hpMax; }

bool Health::isAlive() { return alive; }
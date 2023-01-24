#include <Spawner.hpp>

sf::Vector2f Spawner::GetSpawnLocation()
{
    sf::Vector2f resultado;

    bool axis = (rand() > (RAND_MAX / 2)); // Locked axis: 1 = horizontal / 0 = vertical
    bool side = (rand() > (RAND_MAX / 2)); // Side: 1 = top/left / 0 = bottom/right

    if (axis)
    {
        if (side)
        {
            resultado.x = rand() % this->window->getSize().x;
            resultado.y = 0.f;
        }
        else
        {
            resultado.x = rand() % this->window->getSize().x;
            resultado.y = this->window->getSize().y;
        }
    }
    else
    {
        if (side)
        {
            resultado.x = 0.f;
            resultado.y = rand() % this->window->getSize().y;
        }
        else
        {
            resultado.x = this->window->getSize().x;
            resultado.y = rand() % this->window->getSize().y;
        }
    }

    return resultado;
}

Enemy *Spawner::GetRandomEnemy()
{
    int randomIndex = rand() % this->enemyTypes.size();
    Enemy *resultado = new Enemy(enemyTypes[randomIndex]);
    return resultado;
}

Spawner::Spawner(sf::Window &window, Player &player, std::vector<Enemy *> &enemies)
{
    this->window = &window;
    this->player = &player;
    this->enemyVector = &enemies;

    this->waveAmount = 3;
    this->waveCount = 1;
    this->stopwatch = 10.0f;

    enemyTypes.push_back(Enemy(*this->player, 3.f, 12, 1, 5)); // Follower
}

Spawner::~Spawner() {}

int Spawner::waveNumber() { return waveCount; }

void Spawner::SpawnRandom()
{
    Enemy *newSpawn = GetRandomEnemy();
    enemyVector->push_back(newSpawn);
    newSpawn->setPos(GetSpawnLocation());

    waveCount++;
    float timeOffset = std::min((waveCount * 0.1f), 5.f);
    stopwatch = 10.0f - timeOffset;
}

void Spawner::SpawnWave()
{
    for (int i = 0; i < waveAmount; i++)
    {
        Enemy *newSpawn = GetRandomEnemy();
        enemyVector->push_back(newSpawn);
        newSpawn->setPos(GetSpawnLocation());
    }

    waveCount++;
    float timeOffset = std::min((waveCount * 0.3f), 15.f);
    stopwatch = 30.0f - timeOffset;
}

void Spawner::update()
{
    stopwatch -= 0.1f;

    if (stopwatch <= 0.f)
    {
        if (waveCount % 10 == 0)
        {
            SpawnWave();
        }
        else
        {
            SpawnRandom();
        }
    }
}
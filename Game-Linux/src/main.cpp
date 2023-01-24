#include "Game.hpp"
#include "Player.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"

#include <time.h>

int main()
{
    srand(time(static_cast<unsigned>(0)));

    // Init game engine
    Game game;

    // Run game engine
    game.run();

    // End of application
    return 0;
}
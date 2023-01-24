#include "doctest.h"
#include "Game.hpp"

TEST_CASE("Teste Game Init")
{
    Game game;
    CHECK(game.isStart());
    CHECK_FALSE(game.isGameOver());
}

TEST_CASE("Teste Start Game")
{
    Game game;
    game.startGame();
    CHECK(game.isStart());
}
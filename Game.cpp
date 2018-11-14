#include "Game.h"

Game::~Game()
{
}

void Game::addStone(Stone *stone)
{
    this->stoneHisto.push_back(stone);
}

#include "Game.h"
#include "Coordinate.h"
#include <iostream>

using namespace std;

Game::~Game()
{
}

void Game::addStone(Stone* stone)
{
    this->stoneHisto.push_back(stone);
    this->stoneBoard[stone->coordinate] = stone->color;
}

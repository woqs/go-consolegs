#ifndef GAME_H
#define GAME_H

#include "Stone.h"
#include "Coordinate.h"
#include <iostream>
#include <vector>
#include <map>

class Game
{
public:
    int size;
    std::vector<Stone> stoneHisto;
    std::map<Coordinate, bool> stoneBoard;
    void addStone(Stone stone);
    Game(int size): size(size) {};
    ~Game();
private:
};

#endif // GAME_H

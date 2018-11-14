#ifndef GAME_H
#define GAME_H

#include "Stone.h"
#include <iostream>
#include <vector>

class Game
{
public:
    int size;
    std::vector<Stone*> stoneHisto;
    void addStone(Stone *stone);
    Game(int size): size(size) {};
    ~Game();
private:
};

#endif // GAME_H

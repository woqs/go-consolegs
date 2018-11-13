#ifndef STONE_H
#define STONE_H

#include "Coordinate.h"

class Stone
{
public:
    char color;
    Coordinate coordinate;
    Stone(char color, Coordinate coordinate): color(color), coordinate(coordinate) {};
    ~Stone();
};

#endif // STONE_H

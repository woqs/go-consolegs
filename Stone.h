#ifndef STONE_H
#define STONE_H

#include "Coordinate.h"

class Stone
{
public:
    bool color;
    Coordinate coordinate;
    Stone(bool color, Coordinate* coordinate): color(color), coordinate(*coordinate) {};
    ~Stone();
    bool operator == (const Stone &s2);
};

#endif // STONE_H

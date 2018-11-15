#include "Stone.h"
#include "Coordinate.h"

Stone::~Stone()
{
}

bool Stone::operator == (const Stone &s2)
{
    if(this->coordinate == s2.coordinate)
        return true;
    return false;
}

#include "Coordinate.h"

Coordinate::Coordinate(char letter, int line)
{
    this->letter = letter;
    this->line = line;
}

Coordinate::~Coordinate()
{
}

bool Coordinate::operator == (const Coordinate& c2)
{
    if(this->letter == c2.letter && this->line == c2.line)
        return true;
    return false;
}

bool Coordinate::operator< (const Coordinate& c2)const
{
    if(c2.line < this->line || (int)c2.letter < (int)this->letter)
        return true;
    return false;
}

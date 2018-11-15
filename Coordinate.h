#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate
{
public:
    char letter;
    int line;
    Coordinate(char letter, int line);
    ~Coordinate();
    bool operator == (const Coordinate &c2);
    bool operator< (const Coordinate &c2)const;
};

#endif // COORDINATE_H

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Coordinate.h"
#include "Game.h"
#include <map>
#include <vector>

class Board
{
public:
    Board(Game game): game(game) {
        this->size = game.size;
        this->stars = this->starsCoordinates[game.size];
    };
    ~Board();
    void showGame();
    const bool COLOR_BLACK = 0;
    const bool COLOR_WHITE = 1;
private:
    void printGoban();
    void printFirstLine();
    void printFirstLinePart(int line);
    void printSecondLinePart(int line);
    void printThirdLinePart(int line);
    Game game;
    int size;
    std::vector<Coordinate> stars;
    char letters[19] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'O', 'N', 'P', 'Q', 'R', 'S'};
    std::map<int, std::vector<Coordinate>> starsCoordinates {
        {9,  {
            Coordinate('C', 3),
            Coordinate('C', 5),
            Coordinate('C', 7),
            Coordinate('E', 3),
            Coordinate('E', 5),
            Coordinate('E', 7),
            Coordinate('G', 3),
            Coordinate('G', 5),
            Coordinate('G', 7)
            }
        },
        {13, {
            Coordinate('D', 4),
            Coordinate('D', 7),
            Coordinate('D', 10),
            Coordinate('G', 4),
            Coordinate('G', 7),
            Coordinate('G', 10),
            Coordinate('J', 4),
            Coordinate('J', 7),
            Coordinate('J', 10)
            }
        },
        {19, {
            Coordinate('D', 4),
            Coordinate('D', 10),
            Coordinate('D', 16),
            Coordinate('J', 4),
            Coordinate('J', 10),
            Coordinate('J', 16),
            Coordinate('P', 4),
            Coordinate('P', 10),
            Coordinate('P', 16)
            }
        }
    };
    bool found = false;
    bool color = false;
};

#endif // BOARD_H

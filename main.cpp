#include "Board.h"
#include "Game.h"

int main(int argc, char *argv[])
{
    Game game(9);
    game.addStone(Stone(0, Coordinate('A', 1)));
    game.addStone(Stone(1, Coordinate('A', 2)));
    game.addStone(Stone(0, Coordinate('E', 4)));
    game.addStone(Stone(1, Coordinate('A', 3)));
    game.addStone(Stone(0, Coordinate('E', 6)));
    Board board(game);
    board.showGame();

    return 0;
}

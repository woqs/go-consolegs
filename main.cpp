#include "Board.h"
#include "Game.h"

int main(int argc, char *argv[])
{
    Game game(9);
    game.addStone(new Stone(0, new Coordinate('A', 1)));
    game.addStone(new Stone(1, new Coordinate('A', 2)));
    Board board(game);
    board.showGame();

    return 0;
}

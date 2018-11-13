#include "Board.h"
#include "Game.h"

int main(int argc, char *argv[])
{
    Game game;
    Board board(13);
    board.setupGame(game);

    return 0;
}

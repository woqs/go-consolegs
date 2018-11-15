#include "Board.h"
#include "Coordinate.h"
#include "Game.h"
#include <iostream>
#include <algorithm>

using namespace std;

Board::~Board()
{
}

void Board::showGame()
{
    printFirstLine();
    printGoban();
}

void Board::printFirstLine()
{
    cout << "     ";
    for(int i=0; i<this->size; ++i) {
        cout << "  " << this->letters[i] << "  ";
    }
    cout << "\n";
}

void Board::printGoban()
{
    string preC;
    string postC;
    for(int line=1; line<=this->size; ++line) {
        cout << "     ";
        for(int column=0; column<this->size; ++column) {
            if (find_if(
                    this->game.stoneHisto.begin(), this->game.stoneHisto.end(), [this, column, line](Stone* s) {
                        return s->coordinate.letter == this->letters[column] && s->coordinate.line == line;
                    }
                ) != this->game.stoneHisto.end()
            ) {
                cout << "-BBB-";
            } else if(line > 1) {
                cout << "  |  ";
            }        
        }
        cout << endl;

        preC = (line<10)? "  ":" ";
        cout << preC << line << "  ";
        for(int column=0; column<this->size; ++column) {
            if (find(stars.begin(), stars.end(), Coordinate(this->letters[column], line)) != stars.end()) {
                cout << "--" << "\033[1;37mO\033[0m" << "--";
            } else {
                preC = (column==0)? "  ":"--";
                postC = (column==this->size-1)? "  ":"--";
                cout << preC << "+" << postC;
            }
        }
        cout << endl;

        cout << "     ";
        for(int column=0; column<this->size; ++column) {
            if(line < this->size) {
                cout << "  |  ";
            }
        }
        cout << endl;
    }
}

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
    string printedStone;
    bool found = false;
    bool color = false;
    // a goban line is 3 lines tall, and 5 characters wide
    for(int line=1; line<=this->size; ++line) {
        //first part
        cout << "     ";
        for(int column=0; column<this->size; ++column) {
            for(auto stone : this->game.stoneBoard) {
                if(stone.first.line == line && stone.first.letter == this->letters[column]) {
                    color = stone.second;
                    found = true;
                }
            }
            if(found) {
                printedStone = (color==this->COLOR_BLACK)? " \e[41m   \e[0m " : " \e[47m   \e[0m ";
                cout << printedStone;
            } else if(line > 1) {
                cout << "  |  ";
            }
            found = false;
        }
        cout << endl;

        //second part
        preC = (line<10)? "  ":" ";
        cout << preC << line << "  ";
        for(int column=0; column<this->size; ++column) {
            for(auto stone : this->game.stoneBoard) {
                if(stone.first.line == line && stone.first.letter == this->letters[column]) {
                    color = stone.second;
                    found = true;
                }
            }
            if(found) {
                printedStone = (color==this->COLOR_BLACK)? "\e[41m     \e[0m" : "\e[47m     \e[0m";
                cout << printedStone;
            } else if (find(stars.begin(), stars.end(), Coordinate(this->letters[column], line)) != stars.end()) {
                cout << "--" << "\033[0;37mO\033[0m" << "--";
            } else {
                preC = (column==0)? "  ":"--";
                postC = (column==this->size-1)? "  ":"--";
                cout << preC << "+" << postC;
            }
            found = false;
        }
        cout << endl;

        //thrid part
        cout << "     ";
        for(int column=0; column<this->size; ++column) {
            for(auto stone : this->game.stoneBoard) {
                if(stone.first.line == line && stone.first.letter == this->letters[column]) {
                    color = stone.second;
                    found = true;
                }
            }
            if(found) {
                printedStone = (color==this->COLOR_BLACK)? " \e[41m   \e[0m " : " \e[47m   \e[0m ";
                cout << printedStone;
            } else if(line < this->size) {
                cout << "  |  ";
            }
            found = false;
        }
        cout << endl;
    }
}

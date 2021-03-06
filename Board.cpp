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
    // a goban line is 3 lines tall, and 5 characters wide
    for(int line=1; line<=this->size; ++line) {
        printFirstLinePart(line);
        printSecondLinePart(line);
        printThirdLinePart(line);
    }
}

void Board::printFirstLinePart(int line)
{
    string printedStone;
    
    cout << "     ";
    for(int column=0; column<this->size; ++column) {
        for(auto stone : this->game.stoneBoard) {
            if(stone.first.line == line && stone.first.letter == this->letters[column]) {
                this->color = stone.second;
                this->found = true;
                break;
            }
        }
        if(this->found) {
            printedStone = (this->color==this->COLOR_BLACK)? " \e[41m   \e[0m " : " \e[47m   \e[0m ";
            cout << printedStone;
        } else if(line > 1) {
            cout << "  |  ";
        }
        this->found = false;
    }
    cout << endl;
}

void Board::printSecondLinePart(int line)
{
    string printedStone;
    string preC;
    string postC;

    preC = (line<10)? "  ":" ";
    cout << preC << line << "  ";
    for(int column=0; column<this->size; ++column) {
        for(auto stone : this->game.stoneBoard) {
            if(stone.first.line == line && stone.first.letter == this->letters[column]) {
                this->color = stone.second;
                this->found = true;
                break;
            }
        }
        if(this->found) {
            printedStone = (this->color==this->COLOR_BLACK)? "\e[41m     \e[0m" : "\e[47m     \e[0m";
            cout << printedStone;
        } else if (find(stars.begin(), stars.end(), Coordinate(this->letters[column], line)) != stars.end()) {
            cout << "--" << "\033[0;37mO\033[0m" << "--";
        } else {
            preC = (column==0)? "  ":"--";
            postC = (column==this->size-1)? "  ":"--";
            cout << preC << "+" << postC;
        }
        this->found = false;
    }
    cout << endl;
    
}

void Board::printThirdLinePart(int line)
{
    string printedStone;

    cout << "     ";
    for(int column=0; column<this->size; ++column) {
        for(auto stone : this->game.stoneBoard) {
            if(stone.first.line == line && stone.first.letter == this->letters[column]) {
                this->color = stone.second;
                this->found = true;
            }
        }
        if(this->found) {
            printedStone = (this->color==this->COLOR_BLACK)? " \e[41m   \e[0m " : " \e[47m   \e[0m ";
            cout << printedStone;
        } else if(line < this->size) {
            cout << "  |  ";
        }
        this->found = false;
    }
    cout << endl;
}

#pragma once
#include <string>
#include <conio.h>
#include <iostream>
#include "Pos.h"
using namespace std;

class Player
{
private:
    string _name;
    char _icon;
    int _score;
    Pos _pointer;
public:
    Player(char, string, Pos);
    Pos pointer();
    char icon();
    int move(int);
};

Player::Player(char icon = '.', string name = "Uknown", Pos pointer = { 0, 0 })
{
    _icon = icon;
    _name = name;
    _pointer = pointer;
}

Pos Player::pointer() 
{
    return _pointer;
}

char Player::icon() 
{
    return _icon;
}

int Player::move(int size) {
    cout << _pointer.row << _pointer.col << "\n";
    char key = getch();
    switch (key) {
        case 's':
            _pointer.row = min(_pointer.row + 1, size - 1);
            return 0;
        case 'w':
            _pointer.row = max(_pointer.row - 1, 0);
            return 0;
        case 'a':
            _pointer.col = max(_pointer.col - 1, 0);
            return 0;
        case 'd':
            _pointer.col = min(_pointer.col + 1, size - 1);
            return 0;
        case ' ':
            return 1;
        default: 
            return 0;
    }
}
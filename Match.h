#pragma once
#include "Pos.h"
#include "Player.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Match
{
private:
    int _size;
    vector<vector<char>> _board;
    vector<Player> _players;
    int _currPlayer;
    Player* _winner;
public:
    Match(int = 10);
    void drawBoard();
    void tick();
    Player* getWinner();
    void switchPlayer();
    void play();
};

Match::Match(int size)
{
    _size = size;
    vector<char> t(size, '.');
    for (int i = 0; i < size; i++)
        _board.push_back(t);
    _currPlayer = 0;
    _winner = NULL;
    _players.push_back(Player('O'));
    _players.push_back(Player('X'));
}

void Match::drawBoard()
{
    Pos pointer = _players[_currPlayer].pointer();
    for (int i = 0; i < _size; i++)
    {
        for (int j = 0; j < _size; j++)
        {   
            cout << _board[i][j];
            if (i == pointer.row && (j == pointer.col - 1 || j == pointer.col))
                cout << "-";
            else    
                cout << " ";
        }
        cout << "\n";
    }
}

void Match::tick() 
{
    Pos pos = _players[_currPlayer].pointer();
    if (_board[pos.row][pos.col] == '.') 
    {
        _board[pos.row][pos.col] = _players[_currPlayer].icon();
    }
}

void Match::switchPlayer() 
{
    _currPlayer = (_currPlayer + 1) % _players.size();
}

Player* Match::getWinner() 
{
    Pos pos = _players[_currPlayer].pointer();
    if (_board[pos.row][pos.col] == _players[_currPlayer].icon())
    {
        char icon = _board[pos.row][pos.col];
        int match[4] = { 0 };

        int r = pos.row;
        int c = pos.col;
        while (r > 0 && _board[--r][c] == icon)
            match[0]++;
        r = pos.row;
        while (r < _size - 1 &&_board[++r][c] == icon)
            match[0]++;

        r = pos.row;
        while (c > 0 && _board[r][--c] == icon)
            match[1]++;
        c = pos.col;
        while(c < _size - 1 && _board[r][++c] == icon)
            match[1]++;

        c = pos.col;
        while (r < _size - 1 && c > 0 && _board[++r][--c] == icon)
            match[2]++;
        r = pos.row;
        c = pos.col;
        while(r < _size - 1 && c < _size - 1 && _board[++r][++c] == icon)
            match[2]++;

        r = pos.row;
        c = pos.col;
        while (r > 0 && c < _size - 1 && _board[--r][++c] == icon)
            match[3]++;
        r = pos.row;
        c = pos.col;
        while(r < _size - 1 && c > 0 && _board[++r][--c] == icon)
            match[3]++;

        if (match[0] >= 4 || match[1] >= 4 || match[2] >= 4 || match[3] >= 4)
            return new Player(_players[_currPlayer]);
    }
    return NULL;
}

void Match::play() {
    drawBoard();
    while (!_winner)
    {
        int moved = _players[_currPlayer].move(_size);
        cout << moved << "\n"; 
        if (moved)
        {
            tick();
            _winner = getWinner();
            switchPlayer();
        }
        system("cls");
        drawBoard();
    }
    cout << _winner->icon() << "\n";
    system("cls");
}
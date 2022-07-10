#pragma once

class Pos
{
public:
    int row;
    int col;
    Pos(int = 0, int = 0);
};

Pos::Pos(int _row, int _col) {
    row = _row;
    col = _col;
}
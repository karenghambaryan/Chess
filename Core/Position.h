#ifndef POSITION_H
#define POSITION_H

struct Position
{
    int row;
    int col;

    bool isValid() const
    {
        if(row >= 0 && row < 8 && col >= 0 && col < 8)
        {
            return true;
        }
        return false;
    }
    bool operator==(const Position& other) const
    {
        if(row == other.row && col == other.col)
        {
            return true;
        }
        return false;
    }
    bool operator!=(const Position& other) const
    {
        if (*this == other)
        {
            return false;
        }
        return true;
    }
};
#endif
#ifndef QUEEN_H
#define QUEEN_H

#include "Pieces.h"

class Queen : public Pieces
{
public:
    Queen(Color color) : Pieces(color) {}

    char getSymbol() const override;

    std::vector<Position> getMoves(const Position& from,const Board& board) const override;
};

#endif
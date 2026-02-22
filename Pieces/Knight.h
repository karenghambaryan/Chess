#ifndef KNIGHT_H
#define KNIGHT_H

#include "Pieces.h"

class Knight : public Pieces
{
public:
    Knight(Color color) : Pieces(color) {}

    char getSymbol() const override;

    std::vector<Position> getMoves(const Position& from,const Board& board) const override;
};

#endif
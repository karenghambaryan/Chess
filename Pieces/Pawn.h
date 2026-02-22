#ifndef PAWN_H
#define PAWN_H

#include "Pieces.h"

class Pawn : public Pieces
{
public:
    Pawn(Color color) : Pieces(color) {}

    char getSymbol() const override;

    std::vector<Position> getMoves(const Position& from,const Board& board) const override;
};

#endif
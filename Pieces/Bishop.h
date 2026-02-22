#ifndef BISHOP_H
#define BISHOP_H

#include "Pieces.h"

class Bishop : public Pieces
{
public:
    Bishop(Color color) : Pieces(color) {}

    char getSymbol() const override;

    std::vector<Position> getMoves(const Position& from,const Board& board) const override;
};

#endif
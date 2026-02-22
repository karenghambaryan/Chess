#ifndef ROOK_H
#define ROOK_H

#include "Pieces.h"

class Rook : public Pieces
{
public:
    Rook(Color color) : Pieces(color) {}
    ~Rook() override = default;
    char getSymbol() const override;

    std::vector<Position> getMoves(const Position& from,const Board& board) const override;
};

#endif
#ifndef KING_H
#define KING_H

#include "Pieces.h"

class King : public Pieces
{

public:
    King(Color color) : Pieces(color) {}
    ~King() override = default;
    char getSymbol() const override;
    std::vector<Position> getMoves(const Position& from, const Board& board) const override;
};

#endif



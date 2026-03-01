#ifndef MOVE_GENERATOR_H
#define MOVE_GENERATOR_H

#include <vector>
#include "Core/Board.h"

class MoveGenerator
{
public:
    static std::vector<std::pair<Position,Position>> generateAllMoves(Board& board, Color color);
};

#endif
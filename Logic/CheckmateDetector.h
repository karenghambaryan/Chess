#ifndef CHECKMATE_DETECTOR_H
#define CHECKMATE_DETECTOR_H

#include "Core/Board.h"
#include "Core/Color.h"

class CheckmateDetector
{
public:
    static bool isCheckmate(Board& board, Color color);
};

#endif
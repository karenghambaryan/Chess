#ifndef CHECK_DETECTOR_H
#define CHECK_DETECTOR_H

#include "Core/Board.h"

class CheckDetector
{
public:
    static bool isCheck(const Board& board, Color color);
};

#endif
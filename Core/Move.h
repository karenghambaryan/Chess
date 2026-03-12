#ifndef MOVE_H
#define MOVE_H

#include "Position.h"

class Pieces; 

struct Move
{
    Position m_from;
    Position m_to;
    Pieces* piece;
    bool isPromotion = false;
    Move(Position from, Position to) : m_from(from) , m_to(to) , piece(nullptr) {}
};

#endif
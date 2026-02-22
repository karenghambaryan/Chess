#ifndef MOVE_H
#define MOVE_H

#include "Position.h"

class Piece;

struct Move
{
    Position m_from;
    Position m_to;
    Piece* Tex;//որ եթե քայլը valid չէ հետ բերենք
    Move(Position from, Position to) : m_from(from) , m_to(to) ,Tex(nullptr){}
};

#endif
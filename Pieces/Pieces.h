#ifdef PIECES_H
#define PIECES_H

#include <vector>
#include "Chess/Core/Color.h"
#include "Chess/Core/Position.h"

class Board;

class Pieces
{
protected:
    Color m_color;
public:
    Pieces(Color color) : m_color(color);
    virtual ~Pieces() = default;
    Color getColor() const
    {
        return m_color;
    }
    virtual char getSymbol() const = 0;
    
    virtual std::vector<Position> getMoves(const Position& from, const Board& board) const = 0;
};
#endif;

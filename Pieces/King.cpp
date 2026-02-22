#include "King.h"
#include "Chess/Core/Board.h"

char King::getSymbol() const
{
    if (m_color == Color::White)
        return 'K';
    else
        return 'k';
}

std::vector<Position> King::getMoves(const Position& from, const Board& board) const
{
    std::vector<Position> moves;

    const int directions[8][2] = 
    {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1},
        {1,1},
        {1,-1},
        {-1,1},
        {-1,-1}
    };
    for(int i = 0; i < 8; i++)
    {
        if(to.isValid)
        {
            Piece* target = board.getPiece(to);
            if(!target || target->getColor() != m_color)
            {
                moves.push_back(to);
            }
        }
    }
    return moves;
}
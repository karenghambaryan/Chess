#include "Knight.h"
#include "Chess/Core/Board.h"

char Knight::getSymbol() const
{
    if (m_color == Color::White)
        return 'N';
    else
        return 'n';
}

std::vector<Position> Knight::getMoves(const Position& from,const Board& board) const
{
    std::vector<Position> moves;

    const int offsets[8][2] =
    {
        {2,1}, 
        {2,-1},
        {-2,1}, 
        {-2,-1},
        {1,2},
        {1,-2},
        {-1,2}, 
        {-1,-2}
    };

    for (int i = 0; i < 8; i++)
    {
        Position to;
        to.row = from.row + offsets[i][0];
        to.col = from.col + offsets[i][1];

        if (!to.isValid())
        {
            continue;
        }

        Pieces* target = board.getPiece(to);

        if (!target || target->getColor() != m_color)
        {
            moves.push_back(to);
        }
    }

    return moves;
}
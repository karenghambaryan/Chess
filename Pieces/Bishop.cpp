#include "Bishop.h"
#include "Core/Board.h"

char Bishop::getSymbol() const
{
    if (m_color == Color::White)
        return 'B';
    else
        return 'b';
}

std::vector<Position> Bishop::getMoves(const Position& from,const Board& board) const
{
    std::vector<Position> moves;

    const int directions[4][2] =
    {
        {1,1},    
        {1,-1},   
        {-1,1},   
        {-1,-1}   
    };
    for(int i = 0; i < 4; i++)
    {
        int row = from.row;
        int col = from.col;

        while(true)
        {
            row += directions[i][0];
            col += directions[i][1];

            Position to { row, col };

            if(!to.isValid())
            {
                break;
            }
            Pieces* target = board.getPiece(to);
            if(!target)
            {
                moves.push_back(to);
            }
            else
            {
                if(target->getColor() != m_color)
                {
                    moves.push_back(to);

                }
                break;
            }
        }
    }
    return moves;
}

#include "Queen.h"
#include "Chess/Core/Board.h"

char Queen::getSymbol() const
{
    if (m_color == Color::White)
        return 'Q';
    else
        return 'q';
}

std::vector<Position> Queen::getMoves(const Position& from,const Board& board) const
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

    for (int i = 0; i < 8; i++)
    {
        int row = from.row;
        int col = from.col;

        while (true)
        {
            row += directions[i][0];
            col += directions[i][1];

            Position to{ row, col };

            if (!to.isValid())
                break;

            Pieces* target = board.getPiece(to);

            if (!target)
            {
                moves.push_back(to);
            }
            else
            {
                if (target->getColor() != m_color)
                {
                    moves.push_back(to);
                }

                break;  
            }
        }
    }

    return moves;
}

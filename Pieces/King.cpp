#include "King.h"
#include "Core/Board.h"
#include "Core/Color.h"

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
    Position opponentKingPos = board.findKing(opposite(m_color));
    for(int i = 0; i < 8; i++)
    {
        Position to;
        to.row = from.row + directions[i][0];
        to.col = from.col + directions[i][1];

        if(to.isValid())
        {
            if(to.row == opponentKingPos.row && to.col == opponentKingPos.col)
            {
                continue;
            }

            Pieces* target = board.getPiece(to);
            if(!target || target->getColor() != m_color)
            {
                bool adjacentToOpponentKing = false;
                for(int j = 0; j < 8; j++)
                {
                    Position checkPos;
                    checkPos.row = opponentKingPos.row + directions[j][0];
                    checkPos.col = opponentKingPos.col + directions[j][1];
                    
                    if(checkPos.isValid() && checkPos.row == to.row && checkPos.col == to.col)
                    {
                        adjacentToOpponentKing = true;
                        break;
                    }
                }
                
                if(!adjacentToOpponentKing)
                {
                    moves.push_back(to);
                }
            }
        }
    }
    return moves;
}
#include "Pawn.h"
#include "Chess/Core/Board.h"

char Pawn::getSymbol() const
{
    if (m_color == Color::White)
        return 'P';
    else
        return 'p';
}

std::vector<Position> Pawn::getMoves(const Position& from,const Board& board) const
{
    std::vector<Position> moves;
    int direction;
    if(m_color == Color::White)
    {
        direction = -1;
    }
    else
    {
        direction = 1;
    }
    Position oneStep;
    oneStep.row = from.row + direction;
    oneStep.col = from.col;
    if (oneStep.isValid() && board.getPiece(oneStep) == nullptr)
        {
            moves.push_back(oneStep);

            bool isFirstMove =(m_color == Color::White && from.row == 6) || (m_color == Color::Black && from.row == 1);

            Position twoStep{
            from.row + 2 * direction,
            from.col
            };

            if (isFirstMove &&
                board.getPiece(twoStep) == nullptr)
            {
                moves.push_back(twoStep);
            }
        }
        int captureCols[2] = { -1, 1 };

        for (int i = 0; i < 2; i++)
        {
            Position capture;
            capture.row = from.row + direction;
            capture.col = from.col + captureCols[i]

        if (!capture.isValid())
        {
            continue;
        }
        Piece* target = board.getPiece(capture);

        if (target && target->getColor() != m_color)
        {
            moves.push_back(capture);
        }
    }

    return moves;
}
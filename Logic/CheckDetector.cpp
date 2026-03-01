#include "CheckDetector.h"

bool CheckDetector::isCheck(const Board& board, Color color)
{
    Position kingPos = board.findKing(color);

    if (!kingPos.isValid())
    {
        return false;
    }
    Color enemyColor = opposite(color);
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            Pieces* piece = board.getPiece({row, col});
            if (!piece)
            {
                continue;
            }
            if (piece->getColor() != enemyColor)
            {
                continue;
            }
            Position from{row, col};
            auto moves = piece->getMoves(from, board);
            for (const auto& move : moves)
            {
                if (move == kingPos)
                    return true;
            }
        }
    }
    return false;
}
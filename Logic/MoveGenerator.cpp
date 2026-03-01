#include "MoveGenerator.h"

std::vector<std::pair<Position,Position>> MoveGenerator::generateAllMoves(Board& board, Color color)
{
    std::vector<std::pair<Position,Position>> moves;

    for(int r=0;r<8;r++)
    {
        for(int c=0;c<8;c++)
        {
            Pieces* piece = board.getPiece({r,c});
            if(!piece || piece->getColor()!=color)
            {
                continue;
            }
            Position from{r,c};
            auto pieceMoves = piece->getMoves(from,board);

            for(const auto& to : pieceMoves)
            {
                moves.push_back({from,to});
            }
        }
    }

    return moves;
}
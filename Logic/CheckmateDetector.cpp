#include "CheckmateDetector.h"
#include "CheckDetector.h"
#include "MoveGenerator.h"

bool CheckmateDetector::isCheckmate(Board& board, Color color)
{
    if(!CheckDetector::isCheck(board,color))
    {
        return false;
    }
    auto moves = MoveGenerator::generateAllMoves(board,color);

    for(const auto& move : moves)
    {
        Position from = move.first;
        Position to   = move.second;

        auto captured = std::move(board.m_board[to.row][to.col]);
        auto moving = std::move(board.m_board[from.row][from.col]);
        board.m_board[to.row][to.col] = std::move(moving);
        bool stillCheck = CheckDetector::isCheck(board,color);
        moving = std::move(board.m_board[to.row][to.col]);
        board.m_board[from.row][from.col] = std::move(moving);
        board.m_board[to.row][to.col] = std::move(captured);
        if(!stillCheck)
        {
            return false;
        }
    }

    return true;
}

bool CheckmateDetector::isCheckmateInOneMove(Board& board, Color color)
{
    auto moves = MoveGenerator::generateAllMoves(board, color);

    for (const auto& move : moves)
    {
        Position from = move.first;
        Position to = move.second;

        auto captured = std::move(board.m_board[to.row][to.col]);
        auto moving = std::move(board.m_board[from.row][from.col]);
        board.m_board[to.row][to.col] = std::move(moving);
        board.m_board[from.row][from.col] = nullptr;

        if (!CheckDetector::isCheck(board, color))
        {
            Color opponent = opposite(color);
            if (isCheckmate(board, opponent))
            {
                moving = std::move(board.m_board[to.row][to.col]);
                board.m_board[from.row][from.col] = std::move(moving);
                board.m_board[to.row][to.col] = std::move(captured);
                return true;
            }
        }

        moving = std::move(board.m_board[to.row][to.col]);
        board.m_board[from.row][from.col] = std::move(moving);
        board.m_board[to.row][to.col] = std::move(captured);
    }

    return false;
}
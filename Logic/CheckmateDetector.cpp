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
        
        board.handlePawnPromotion(to);
        
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
        
        board.handlePawnPromotion(to);

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

bool CheckmateDetector::isCheckmateInTwoMoves(Board& board, Color color)
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
        
        board.handlePawnPromotion(to);

        Color opponent = opposite(color);
        if (isCheckmate(board, opponent))
        {
            moving = std::move(board.m_board[to.row][to.col]);
            board.m_board[from.row][from.col] = std::move(moving);
            board.m_board[to.row][to.col] = std::move(captured);
            continue;
        }

        bool canAvoid = false;
        auto opponentMoves = MoveGenerator::generateAllMoves(board, opponent);

        for (const auto& oppMove : opponentMoves)
        {
            Position oppFrom = oppMove.first;
            Position oppTo = oppMove.second;

            auto oppCaptured = std::move(board.m_board[oppTo.row][oppTo.col]);
            auto oppMoving = std::move(board.m_board[oppFrom.row][oppFrom.col]);
            board.m_board[oppTo.row][oppTo.col] = std::move(oppMoving);
            board.m_board[oppFrom.row][oppFrom.col] = nullptr;
            
            board.handlePawnPromotion(oppTo);

            if (CheckDetector::isCheck(board, opponent))
            {
                oppMoving = std::move(board.m_board[oppTo.row][oppTo.col]);
                board.m_board[oppFrom.row][oppFrom.col] = std::move(oppMoving);
                board.m_board[oppTo.row][oppTo.col] = std::move(oppCaptured);
                continue;
            }

            if (!isCheckmateInOneMove(board, color))
            {
                canAvoid = true;
            }

            oppMoving = std::move(board.m_board[oppTo.row][oppTo.col]);
            board.m_board[oppFrom.row][oppFrom.col] = std::move(oppMoving);
            board.m_board[oppTo.row][oppTo.col] = std::move(oppCaptured);

            if (canAvoid)
                break;
        }

        moving = std::move(board.m_board[to.row][to.col]);
        board.m_board[from.row][from.col] = std::move(moving);
        board.m_board[to.row][to.col] = std::move(captured);

        if (!canAvoid)
        {
            return true;
        }
    }

    return false;
}